#pragma once

#include <iostream>

class Node
{
  private:
    Node *left_child_ = NULL;
    Node *middle_child_ = NULL;
    Node *right_child_ = NULL;

    double middle_key_ = 0; // minimal value from middle node
    double right_key_ = 0;  // minimal value from right node

    double leaf_value_ = 0; 

  public:
    Node();
    Node(double value);
    Node(Node *left_child, Node *middle_child);

    double getLeafValue() const;
    double setLeafValue(double value); // Возвращает старое значение

    double getMiddleKey() const;
    void   setMiddleKey(double value);

    double getRightKey() const;
    void   setRightKey(double value);

    Node* getLeftChild() const;
    void  setLeftChild(Node* child);

    Node* getMiddleChild() const;
    void  setMiddleChild(Node* child);

    Node* getRightChild() const;
    void  setRightChild(Node* child);

    bool is_node() const;
    bool is_leaf() const;
};
