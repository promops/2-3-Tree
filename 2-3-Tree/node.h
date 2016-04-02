#pragma once

#include <iostream>

class Node
{
  private:
    Node *left_child_;
    Node *middle_child_;
    Node *right_child_;

    double middle_key_; // minimal value from middle node
    double right_key_;  // minimal value from right node

    double leaf_value_; 

  public:
    Node(double value);

    double getLeafValue() const;
    void   setLeafValue(double value);

    bool is_node() const;
    bool is_leaf() const;
};
