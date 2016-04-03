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
  void removeValue(double);

  void printTree();
};