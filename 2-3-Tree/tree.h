#pragma once

#include "node.h"
#include <iostream>

class Tree
{

private:
  Node *root_;

  void  print(Node*, int);
  Node* insert(Node*, double, double*);
public:
  Tree();

  void insertValue(double);
  Node searchNode(double);

  void printTree();
};