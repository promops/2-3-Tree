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
  // Если дерево пустое
  if (!root_)
  {
    root_ = new Node(value);
    return;
  }

  // Если у дерева один узел (корень)
  if (root_->is_leaf()) 
  {
    if (value < root_->getLeafValue())
      root_ = new Node(new Node(value), root_);
    else 
      if (value > root_->getLeafValue())
        root_ = new Node(root_, new Node(value));

    return;
  }

  
  // Если дичь
  double i;
  Node *node = insert(root_, value, &i);

  //создание нового корня
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

  // Если лист
  if (current_node->is_leaf())
  {
    if (current_node->getLeafValue() != value)
      if (current_node->getLeafValue() < value)
      {
      *low = value;
      return new Node(value);
      }
      else {
        Node *pnew = new Node(current_node->getLeafValue());
        current_node->setLeafValue(value);
        *low = current_node->getLeafValue();

        return pnew;
      }

      return NULL;
  }
  
    // Если узел
    if (value < current_node->getMiddleKey())
    { 
      cout << "child: 1\n";
      child = 1;
      w = current_node->getLeftChild();
    }
    else if (!current_node->getRightChild() || value < current_node->getMiddleKey()) // х во втором поддереве
    {
      cout << "child: 2\n";
      child = 2;
      w = current_node->getMiddleChild();
    }
    else { // х в третьем поддереве 
      cout << "child: 3\n";
      child = 3;
      w = current_node->getRightChild();
    }

    double lowback = 0;
    Node *pback = insert(w, value, &lowback);



    if (pback != NULL)
      // node имеет двух сыновей
      if (current_node->getRightChild() == NULL) 


        if (child == 2)
        {
          cout << "== 2\n";
          current_node->setRightChild(pback);
          current_node->setRightKey(lowback);
        }
        else { // child = 1 
          cout << "== 1\n";
          current_node->setRightChild(current_node->getMiddleChild());
          current_node->setRightKey(current_node->getMiddleKey());
          current_node->setMiddleChild(pback);
          current_node->setMiddleKey(lowback);
        }



      // node имеет трех сыновей
      else {
        Node *pnew = new Node();

        if (child == 3) // pback и 3 - й сын становятся сыновьями нового узла
        {
          cout << "== 3\n";

          pnew->setLeftChild(current_node->getRightChild());
          pnew->setMiddleChild(pback);
          pnew->setMiddleKey(lowback);

          *low = current_node->getRightKey();
          current_node->setRightChild(NULL);
        }
        else {
          pnew->setMiddleChild(current_node->getRightChild());
          pnew->setMiddleKey(current_node->getRightKey());
          current_node->setRightChild(NULL);
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

void Tree::print(Node *tree, int lv)
{
    int i;
    if (!tree)
      return;

    if (tree->is_leaf())
      printf("%.0f ", tree->getLeafValue());
    else {
      if (lv) 
        printf("\n");

      for (i = 0; i < lv; i++)
        printf("    ");

      printf("[%.0f, %.0f]: ", tree->getMiddleKey(), tree->getRightKey());
    }

    print(tree->getLeftChild(), lv + 1);
    print(tree->getMiddleChild(), lv + 1);
    print(tree->getRightChild(), lv + 1);
}

void Tree::printTree() 
{
  print(root_, 0);
}