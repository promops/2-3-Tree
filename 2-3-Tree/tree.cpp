#include "tree.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

Tree::Tree()
{
  root_ = NULL;
}

void Tree::insertValue(double value)
{
  // ≈сли дерево пустое
  if (!root_)
  {
    root_ = new Node(value);
    return;
  }

  double i;
  Node *node = insert(root_, value, &i);

  //создание нового корн€
  if (node != NULL)
  {
    root_ = new Node(root_, node);
    root_->setMiddleKey(i);
  }
}

Node* Tree::insert(Node *current_node, double value, double* low)
{
  int child = 0;
  Node *w;

  // ≈сли лист
  if (current_node->is_leaf())    
    if (value > current_node->getLeafValue())
    {
      *low = value;
      return new Node(value);
    }
    else if (value < current_node->getLeafValue())
    {
      *low = current_node->getLeafValue();
      return new Node(current_node->setLeafValue(value));
    }
    else
      return NULL;
  
  // ≈сли узел, выбираем ветку
  if (value < current_node->getMiddleKey())
  { 
    child = 1;
    w = current_node->getLeftChild();
  }
  else if (!current_node->hasRightChild())
  {
    child = 2;
    w = current_node->getMiddleChild();
  }
  else {
    child = 3;
    w = current_node->getRightChild();
  }

  double lowback = 0;
  Node *pback = insert(w, value, &lowback);

  if (pback == NULL)
    return NULL;

  // current_node имеет двух сыновей
  if (!current_node->hasRightChild())
  {
    if (child == 2)
    {
      current_node->setRightChild(pback);
      current_node->setRightKey(lowback);
    }
    else {
      current_node->setRightChild(current_node->getMiddleChild());
      current_node->setRightKey(current_node->getMiddleKey());
      current_node->setMiddleChild(pback);
      current_node->setMiddleKey(lowback);
    }
  }


  // node имеет трех сыновей
  else {
    Node *pnew = new Node();

    if (child == 3) // pback и 3 - й сын станов€тс€ сыновь€ми нового узла
    {
      pnew->setLeftChild(current_node->getRightChild());
      pnew->setMiddleChild(pback);
      pnew->setMiddleKey(lowback);

      *low = current_node->getRightKey();
      current_node->setRightChild(NULL);
      current_node->setRightKey(0);
    }
    else {
      pnew->setMiddleChild(current_node->getRightChild());
      pnew->setMiddleKey(current_node->getRightKey());
      current_node->setRightChild(NULL);
      current_node->setRightKey(0);
    }

    if (child == 2)
    {
      pnew->setLeftChild(pback);
      *low = lowback;
    }

    if (child == 1) 
    {
      pnew->setLeftChild(current_node->getMiddleChild());
      *low = current_node->getMiddleKey();

      current_node->setMiddleChild(pback);
      current_node->setMiddleKey(lowback);
    }

    return pnew;
  }

  return NULL;
}

void Tree::removeValue(double value)
{
}

void Tree::print(Node *tree, int lv)
{
    int i;
    if (!tree)
      return;

    if (tree->is_leaf())
      printf("%d ", tree->getLeafValue());
    else {
      if (lv) 
        printf("\n");

      for (i = 0; i < lv; i++)
        printf("    ");

      if (!tree->hasRightChild())
        printf("[%d, -]: ", tree->getMiddleKey());
      else
        printf("[%d, %d]: ", tree->getMiddleKey(), tree->getRightKey());
        
    }

    print(tree->getLeftChild(), lv + 1);
    print(tree->getMiddleChild(), lv + 1);
    print(tree->getRightChild(), lv + 1);
}

void Tree::printTree() 
{
  print(root_, 0);
}