// .opencode/plugins/learning-opportunity.ts
//
// learning-opportunities-auto — opencode plugin (tool.execute.after hook).
//
// After every Bash tool result, checks whether the command was a `git commit`
// and, if so, appends a one-way nudge to the tool output reminding the agent
// to consider offering a brief learning-opportunities exercise. This is the
// in-opencode equivalent of the git `post-commit` hook, which only fires for
// commits made OUTSIDE opencode (it guards on `[ -t 0 ]`). Without this
// plugin, commits made inside an opencode session never trigger an offer.
//
// Rate limiting: max 5 offers per session. Uses the same /tmp state-file
// scheme as .opencode/scripts/post-tool-use.sh (`lo_auto_<sessionID>.state`)
// so the two mechanisms share a single per-session budget.
//
// Dependency-free: only Bun/Node built-ins are imported, so the plugin loads
// in any clone without needing .opencode/package.json (which is git-ignored).

import { readFileSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

const MAX_OFFERS_PER_SESSION = 5;

function stateFile(sessionID: string): string {
  const safe = sessionID.replace(/[^a-zA-Z0-9_-]/g, "_");
  return join(tmpdir(), `lo_auto_${safe}.state`);
}

function offersUsed(sessionID: string): number {
  try {
    return Number(readFileSync(stateFile(sessionID), "utf8")) || 0;
  } catch {
    return 0;
  }
}

function recordOffer(sessionID: string): void {
  try {
    writeFileSync(stateFile(sessionID), String(offersUsed(sessionID) + 1));
  } catch {
    // State file unwritable: still surface the nudge once.
  }
}

export const LearningOpportunityAuto = async () => ({
  "tool.execute.after": async (input: {
    tool: string;
    sessionID: string;
    callID: string;
    args: Record<string, unknown>;
  }, output: { output: string }) => {
    if (input.tool !== "bash") return;
    const command =
      typeof input.args?.command === "string" ? input.args.command : "";
    if (!/\bgit\b[\s\S]*\bcommit\b/i.test(command)) return;
    if (offersUsed(input.sessionID) >= MAX_OFFERS_PER_SESSION) return;

    recordOffer(input.sessionID);

    output.output += [
      "",
      "[learning-opportunities-auto] The user just committed code.",
      "Per the learning-opportunities skill, consider whether this is a good",
      "moment to offer a brief 10-15 minute exercise on the work just",
      "committed (new files, a refactor, or a design decision are the best",
      "candidates). If it qualifies, ask ONE short question with the",
      "interactive question tool whether they would like the exercise. Do not",
      "start it until they confirm; if they decline, do not offer again this",
      "session.",
    ].join("\n");
  },
});
