#include "node.h"

Node::Node(double value)
{
  left_child_ = NULL;
  middle_child_ = NULL;
  right_child_ = NULL;

  leaf_value_ = value;
}

bool Node::is_node() const 
{ 
  return left_child_; 
}

bool Node::is_leaf() const 
{ 
  return (!left_child_ && !middle_child_ && !right_child_); 
}

double Node::getLeafValue() const  
{ 
  return leaf_value_;
}

void Node::setLeafValue(double value)
{
  leaf_value_ = value;
}