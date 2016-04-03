#include "tree.h"

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  Tree *tree = new Tree();

  tree->insertValue(1);
  tree->insertValue(2);
  tree->insertValue(3);

  tree->printTree();

  cout << "\n\n\n";

  tree->insertValue(4);
  tree->insertValue(5);
  tree->insertValue(6);
  tree->insertValue(7);
  tree->insertValue(8);

  tree->printTree();

  scanf_s(" ");
}