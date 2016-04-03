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
  if (!root_) // ≈сли дерево пустое
  {
    root_ = new Node(value);
    return;
  }

  if (root_->is_leaf()) // ≈сли у дерева один узел (корень)
  {
    if (value < root_->getLeafValue())
      root_ = new Node(new Node(value), root_);
    else 
      if (value > root_->getLeafValue())
        root_ = new Node(root_, new Node(value));

    return;
  }

  // ≈сли дичь

  Node *node = insert(root_, value);

  //создание нового корн€
  if (node != NULL) 
    root_ = new Node(root_, node);
}

Node* Tree::insert(Node *current_node, double value)
{
  int child = 0;
  Node *w;

  // ≈сли текущий узел - лист
  if (current_node->is_leaf()) 
    if (value > current_node->getLeafValue())
    { 
      return new Node(value);
    }
    else if (value < current_node->getLeafValue())
    {
      return new Node(current_node->setLeafValue(value));
    }
    else
      return NULL;

    
    // ≈сли внутренний узел
    if (value < current_node->getMiddleKey())
    { 
      child = 1;
      w = current_node->getLeftChild();
    }
    else if (!current_node->getRightChild() || value < current_node->getMiddleKey()) // х во втором поддереве
    {
      child = 2;
      w = current_node->getMiddleChild();
    }
    else { // х в третьем поддереве 
      child = 3;
      w = current_node->getRightChild();
    }

    
    Node *node = insert(w, value);

    if (node != NULL)
      // node имеет двух сыновей
      if (current_node->getRightChild() == NULL) 
        if (child - 2)
        {
          current_node->setRightChild(node);
        }
        else { // child = 1 
          current_node->setRightChild(current_node->getMiddleChild());
          current_node->setMiddleChild(node);
        }
      // node имеет трех сыновей
      else {

        if (child == 3) // pback и 3 - й сын станов€тс€ сыновь€ми нового узла
        {
          new Node(current_node->getRightChild(), node);
          //low: = current_node.lowofthird;
          current_node->setRightChild(NULL);
        }
        else { // child < 2; перемещение 3 - го сына node к pnew
          new Node(current_node->getRightChild(), node);
          //pnewt.secondchild: = current_node.thirdchild;
          //pnew\.lowofsecond: = current_node.lowofthird;
          //pnewt.thirdchild: = nil;
          current_node->setRightChild(NULL);
        }

        if (child == 2) //pback становитс€ 1 - м сыном pnew
        {
          //pnewf.firstchild: = pback;
          //low: = lowback
        }

        if (child == 1) // 2 - й сын node перемещаетс€ к pnew, pback становитс€ 2 - м сыном node
        {
          //pnewt.firstchild: = current_node.secondchild;
          //low: = nodet - lowofsecond;
          //current_node.secondcnild: = pback;
          //current_node.lowofsecond: = lowback
        }
     }
      return NULL;
}

void Tree::print(Node *tree, int lv)
{
    int i;
    if (!tree)
      return;

    print(tree->getLeftChild(), lv + 1);

    for (i = 0; i < lv; i++)
      printf("          ");

    if (tree->is_leaf())
      printf("%.0f\n", tree->getLeafValue());
    else
      printf("(%.0f, %.0f)\n", tree->getMiddleKey(), tree->getRightKey());

    print(tree->getMiddleChild(), lv + 1);

    print(tree->getRightChild(), lv + 1);
}

void Tree::printTree() 
{
  print(root_, 0);
}