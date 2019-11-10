#ifndef _SNIPPETS_DFS_HPP
#define _SNIPPETS_DFS_HPP

#include <iostream>

// reference: https://www.programiz.com/dsa/tree-traversal

using snip::TreeNode;

namespace snip {

class DFS {
public:
  static void preOrder(TreeNode* node) {
    if (!node) {
      return;
    }
    std::cerr << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
  }

  static void inOrder(TreeNode* node) {
    if (!node) {
      return;
    }
    inOrder(node->left);
    std::cerr << node->data << " ";
    inOrder(node->right);
  }

  static void postOrder(TreeNode* node) {
    if (!node) {
      return;
    }
    postOrder(node->left);
    postOrder(node->right);
    std::cerr << node->data << " ";
  }

  static void reverseInOrder(TreeNode* node) {
    if (!node) {
      return;
    }
    reverseInOrder(node->right);
    std::cerr << node->data << " ";
    reverseInOrder(node->left);
  }
};

} // snip namespace

#endif
