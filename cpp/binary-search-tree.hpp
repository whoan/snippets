#ifndef _SNIPPETS_BINARY_SEARCH_TREE_HPP
#define _SNIPPETS_BINARY_SEARCH_TREE_HPP

#include <vector>

namespace snip {

class TreeNode {
public:
    int data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int data) : data(data) {}
};

class BFS {
    TreeNode* root = nullptr;

    TreeNode* insert(TreeNode* rootSubTree, int data) {
        if (rootSubTree == nullptr) {
            return new TreeNode(data);
        }

        TreeNode* cur;
        if (data <= rootSubTree->data) {
            cur = insert(rootSubTree->left, data);
            rootSubTree->left = cur;
        } else {
            cur = insert(rootSubTree->right, data);
            rootSubTree->right = cur;
        }
        return rootSubTree;
    }

public:
    BFS(const std::vector<int>& input) {
        for (auto element : input) {
            root = insert(root, element);
        }
    }

    TreeNode* getRoot() {
        return root;
    }
};

// see https://github.com/whoan/snip
// snip("std-input.hpp")

BFS createBinarySearchTreeFromInput(std::size_t size) {
    return BFS(snip::createCollectionFromStdInput<int>(size));
}

} // snip namespace


#endif
