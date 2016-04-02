#pragma once

#include "node.h"
#include <iostream>

class Tree
{

private:
  Node *root_;

public:
  Tree();

  void addValue(double value);
  Node searchNode(double value);

  void printTree();
};