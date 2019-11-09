#ifndef _SNIPPETS_BINARY_SEARCH_TREE_HPP
#define _SNIPPETS_BINARY_SEARCH_TREE_HPP

#include <vector>

namespace snip {

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BFS {
    Node* root = nullptr;

public:
    BFS(const std::vector<int>& input) {
        for (auto element : input) {
            root = insert(root, element);
        }
    }

    Node* insert(Node* rootSubTree, int data) {
        if(rootSubTree == nullptr) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= rootSubTree->data) {
                cur = insert(rootSubTree->left, data);
                rootSubTree->left = cur;
            } else {
                cur = insert(rootSubTree->right, data);
                rootSubTree->right = cur;
           }

           return rootSubTree;
       }
    }

    auto getRoot() {
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
