#include "node.h"

Node::Node()
{
  left_child_ = NULL;
  middle_child_ = NULL;
  right_child_ = NULL;
}

Node::Node(int value)
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

// Leaf methods
bool Node::is_leaf() const      { return left_child_ == NULL; }
int  Node::getLeafValue() const { return leaf_value_; }

int Node::setLeafValue(int value)
{
  double old_value = leaf_value_;
  leaf_value_ = value;
  return old_value;
}

// Middle key methods
void Node::removeMiddleKey()       { middle_key_ = LONG_MIN; }
int  Node::getMiddleKey() const    { return middle_key_; }
bool Node::hasMiddleKey() const    { return middle_key_ != LONG_MIN; }
void Node::setMiddleKey(int value) { middle_key_ = value; }

// Right key methods
void Node::removeRightKey()       { right_key_ = LONG_MIN; }
int  Node::getRightKey() const    { return right_key_; }
bool Node::hasRightKey() const    { return right_key_ != LONG_MIN; }
void Node::setRightKey(int value) { right_key_ = value; }

// Left child methods
void  Node::removeLeftChild()         { left_child_ = NULL; }
Node* Node::getLeftChild() const      { return left_child_; }
void  Node::setLeftChild(Node *value) { left_child_ = value; }
bool  Node::hasLeftChild() const      { return left_child_ != NULL; }

// Middle child methods
Node* Node::getMiddleChild() const      { return middle_child_; }
void  Node::setMiddleChild(Node *value) { middle_child_ = value; }
bool  Node::hasMiddleChild() const      { return middle_child_ != NULL; }

void  Node::removeMiddleChild()
{ 
  left_child_ = NULL; 
  removeMiddleKey();
}

// Right child methods
Node* Node::getRightChild() const      { return right_child_; }
void  Node::setRightChild(Node *value) { right_child_ = value; }
bool  Node::hasRightChild() const      { return right_child_ != NULL; }

void  Node::removeRightChild()
{
  right_child_ = NULL;
  removeRightKey();
}