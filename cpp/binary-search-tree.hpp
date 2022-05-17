#ifndef _SNIPPETS_BINARY_SEARCH_TREE_HPP
#define _SNIPPETS_BINARY_SEARCH_TREE_HPP

// reference: https://www.programiz.com/dsa/breadth-first-search-tree

#include <vector>

namespace snip {

class TreeNode {
public:
    int data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int data) : data(data) {}
};

class BST {
    TreeNode* root = nullptr;

    TreeNode* insert(TreeNode* rootSubTree, int data) {
        if (rootSubTree == nullptr) {
            return new TreeNode(data);
        }
        if (data <= rootSubTree->data) {
            rootSubTree->left = insert(rootSubTree->left, data);
        } else {
            rootSubTree->right = insert(rootSubTree->right, data);
        }
        return rootSubTree;
    }

public:
    BST(const std::vector<int>& input) {
        for (auto element : input) {
            root = insert(root, element);
        }
    }

    TreeNode* getRoot() {
        return root;
    }

    static bool isValid(TreeNode* root) {
        // TODO this is wrong
        if (!root) {
            return true;
        }
        if (root->left && root->left->data > root->data) {
            return false;
        }
        if (root->right && root->right->data <= root->data) {
            return false;
        }
        return isValid(root->left) && isValid(root->right);
    }
};

// see https://github.com/whoan/snip
// snip("cpp/std-input.hpp")

BST createBinarySearchTreeFromInput(std::size_t size) {
    return BST(snip::createCollectionFromStdInput<int>(size));
}

} // snip namespace

#endif
