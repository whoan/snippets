#ifndef _SNIPPETS_DFS_HPP
#define _SNIPPETS_DFS_HPP

#include <iostream>
#include <stack>

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
  auto getOneSide(TreeNode node) {
    return direction == LeftToRight ? node->left : node->right;
  }

  template <typename TreeNode>
  auto getOtherSide(TreeNode node) {
    return direction == RightToLeft ? node->left : node->right;
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

  template <typename TreeNode>
  void traverseIterative(TreeNode root) {
    if (method == PostOrder) {
      throw std::runtime_error("Not implemented yet");
    }

    std::stack<TreeNode> nodes;
    auto node = root;
    nodes.push(root);
    if (method == Method::PreOrder) {
      visit(node);
    }

    while (node) {
      // process the left diagonal
      while (getOneSide(node)) {
        nodes.push(getOneSide(node));
        node = getOneSide(node);
        if (method == Method::PreOrder) {
          visit(node);
        }
      }
      // remove the leftmost node as it is processed now
      nodes.pop();
      if (method == Method::InOrder) {
        visit(node);
      }

      // find the deepest node with right node
      while (!getOtherSide(node) && nodes.size()) {
        node = nodes.top();
        nodes.pop();
        if (method == Method::InOrder) {
          visit(node);
        }
      }

      // having processed the left subtree, if there is no right subtree, we are done
      if (!getOtherSide(node)) {
        break;
      }

      // process the right subtree
      nodes.push(getOtherSide(node));
      node = getOtherSide(node);
      if (method == Method::PreOrder) {
        visit(node);
      }
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
