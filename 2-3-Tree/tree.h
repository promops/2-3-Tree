#pragma once

#include "node.h"
#include <iostream>

class Tree
{

private:
  Node *root_;

  void  print(Node *tree, int lv);
  Node* insert(Node *current_node, double value);
public:
  Tree();

  void insertValue(double value);
  Node searchNode(double value);

  void printTree();
};