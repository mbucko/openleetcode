# Simplify Path

You are given an absolute Unix-style file path ``path`` (it starts with ``'/'``). Return its simplified canonical form:

* ``"."`` means the current directory and can be dropped.
* ``".."`` means the parent directory. At the root, it stays at the root.
* Several slashes in a row act as one.
* Any other name, including ones like ``"..."``, is a normal directory name.

The canonical path starts with a single ``'/'``, separates directories with single slashes, and has no trailing slash (unless it is just ``"/"``).
\
\
\
**Example 1:**

>**Input:** path = "/usr//local/./bin/"\
>**Output:** "/usr/local/bin"

**Example 2:**

>**Input:** path = "/a/b/../../c"\
>**Output:** "/c"\
>**Explanation:** Each ".." goes up one level.

**Example 3:**

>**Input:** path = "/../"\
>**Output:** "/"\
>**Explanation:** You can't go above the root.

**Constraints:**

* ``1 <= path.length <= 3000``
* ``path`` contains English letters, digits, ``'.'``, ``'/'`` and ``'_'``.
* ``path`` is a valid absolute Unix path.
