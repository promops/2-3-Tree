#pragma once

#include <iostream>

class Node
{
  private:
    Node *left_child_   = NULL;
    Node *middle_child_ = NULL;
    Node *right_child_  = NULL;

    int middle_key_ = LONG_MIN;  // minimal value from middle node
    int right_key_  = LONG_MIN;  // minimal value from right node

    int leaf_value_ = LONG_MIN;

  public:
    Node();
    Node(int value);
    Node(Node *left_child, Node *middle_child);

    //bool hasLeafValue() const;
    int  getLeafValue() const;
    int  setLeafValue(int value); // Возвращает старое значение

    void removeMiddleKey();
    int  getMiddleKey() const;
    bool hasMiddleKey() const;
    void setMiddleKey(int value);
    
    void removeRightKey();
    int  getRightKey() const;
    bool hasRightKey() const;
    void setRightKey(int value);

    bool  hasLeftChild() const;
    Node* getLeftChild() const;
    void  setLeftChild(Node* child);
    void  removeLeftChild();

    bool  hasMiddleChild() const;
    Node* getMiddleChild() const;
    void  setMiddleChild(Node* child);
    void  removeMiddleChild();

    bool  hasRightChild() const;
    Node* getRightChild() const;
    void  setRightChild(Node* child);
    void  removeRightChild();

    bool is_node() const;
    bool is_leaf() const;
};
