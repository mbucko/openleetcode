#ifndef PRINTER_H
#define PRINTER_H

#include <algorithm>

#include <type_traits>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>

#include "singletreenode.h"
#include "treenode.h"
#include "typetraits.h"

struct Printer {
    template <typename T>
    static std::string toString(const T& value) {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }

    static std::string toString(const std::string& value) {
        return value;
    }

    template <typename T>
    static std::string toString(const std::vector<T>& value) {
        std::stringstream ss;
        ss << "[";
        for (size_t i = 0; i < value.size(); ++i) {
            if (i  != 0) {
                ss << ", ";
            }
            ss << Printer::toString(value[i]);
        }
        ss << "]";
        return ss.str();
    }

    static std::string toString(const SingleTreeNode* value) {
        if (value == nullptr) {
            return "null";
        }
        return Printer::toString(value->val);
    }

    static std::string toString(const TreeNode* value) {
        const std::vector<const SingleTreeNode*> nodes = toVector(value);
        if (nodes.empty()) {
            return "[null]";
        }

        return Printer::toString(nodes);
    }

  private:
    static std::vector<const SingleTreeNode*> toVector(const TreeNode* value) {
        std::vector<const SingleTreeNode*> nodes;
        if (value == nullptr) {
            return nodes;
        }

        std::queue<const TreeNode*> queue;
        std::unordered_set<const TreeNode*> visited;
        queue.push(value);

        while (!queue.empty()) {
            const TreeNode* current = queue.front();
            queue.pop();

            if (visited.count(current) > 0) {
                throw std::runtime_error("Circular dependency detected");
            }
            visited.insert(current);

            if (current != nullptr) {
                nodes.push_back(static_cast<const SingleTreeNode*>(current));
                queue.push(current->left);
                queue.push(current->right);
            } else {
                nodes.push_back(nullptr);
            }
        }

        nodes.erase(std::find(nodes.rbegin(), nodes.rend(), nullptr).base(),
                    nodes.end());

        return nodes;
    }
};

#endif // PRINTER_H