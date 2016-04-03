#include "node.h"

Node::Node()
{
  left_child_ = NULL;
  middle_child_ = NULL;
  right_child_ = NULL;
}

Node::Node(double value)
{
  left_child_ = NULL;
  middle_child_ = NULL;
  right_child_ = NULL;

  leaf_value_ = value;
}

Node::Node(Node *left_child, Node *middle_child)
{
  left_child_ = left_child;
  middle_child_ = middle_child;
  right_child_ = NULL;

  //if (middle_child->is_leaf())
    //middle_key_ = middle_child->getLeafValue();
}

bool Node::is_node() const 
{ 
  return left_child_ != NULL; 
}

bool Node::is_leaf() const 
{ 
  return left_child_ == NULL; 
}

double Node::getLeafValue() const  
{ 
  return leaf_value_;
}

double Node::setLeafValue(double value)
{
  double old_value = leaf_value_;
  leaf_value_ = value;
  return old_value;
}

double Node::getMiddleKey() const
{
  return middle_key_;
}

void Node::setMiddleKey(double value)
{
  middle_key_ = value;
}

double Node::getRightKey() const
{
  return right_key_;
}

void Node::setRightKey(double value)
{
  right_key_ = value;
}

Node* Node::getLeftChild() const
{
  return left_child_;
}

void Node::setLeftChild(Node *value)
{
  left_child_ = value;
}

Node* Node::getMiddleChild() const
{
  return middle_child_;
}

void Node::setMiddleChild(Node *value)
{
  middle_child_ = value;
}

Node* Node::getRightChild() const
{
  return right_child_;
}

void Node::setRightChild(Node *value)
{
  right_child_ = value;
}