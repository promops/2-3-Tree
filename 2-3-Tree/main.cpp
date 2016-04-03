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
  //tree->insertValue(4);

  tree->printTree();

  scanf_s(" ");
}