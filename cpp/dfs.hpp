#ifndef _SNIPPETS_DFS_HPP
#define _SNIPPETS_DFS_HPP

#include <iostream>

// reference: https://www.programiz.com/dsa/tree-traversal

namespace snip {

class DFS {
  enum Method {
    PreOrder, InOrder, PostOrder
  } method;

  enum Direction {
    LeftToRight, RightToLeft
  } direction;

  template <typename TreeNode>
  DFS(TreeNode root, Method method, Direction direction=LeftToRight)
  : method(method), direction(direction)
  {
    traverse(root);
  }

  template <typename TreeNode>
  void visit(TreeNode node) {
    std::cerr << node->data << " ";
  }

  template <typename TreeNode>
  void traverse(TreeNode node) {
    if (!node) {
      return;
    }

    if (method == Method::PreOrder) {
      visit(node);
    }
    traverse(direction == LeftToRight ? node->left : node->right);
    if (method == Method::InOrder) {
      visit(node);
    }
    traverse(direction == LeftToRight ? node->right : node->left);
    if (method == Method::PostOrder) {
      visit(node);
    }
  }

public:
  template <typename TreeNode>
  static void preOrder(TreeNode root) {
    DFS dfs(root, DFS::PreOrder);
  }

  template <typename TreeNode>
  static void inOrder(TreeNode root) {
    DFS dfs(root, DFS::InOrder);
  }

  template <typename TreeNode>
  static void postOrder(TreeNode root) {
    DFS dfs(root, DFS::PostOrder);
  }

  template <typename TreeNode>
  static void preOrderReverse(TreeNode root) {
    DFS dfs(root, DFS::PreOrder, DFS::RightToLeft);
  }

  template <typename TreeNode>
  static void inOrderReverse(TreeNode root) {
    DFS dfs(root, DFS::InOrder, DFS::RightToLeft);
  }

  template <typename TreeNode>
  static void postOrderReverse(TreeNode root) {
    DFS dfs(root, DFS::PostOrder, DFS::RightToLeft);
  }
};

} // snip namespace

#endif
