//#pragma once

#ifndef _TREE_H
#define _TREE_H

#include "Node.h"

using namespace std;

class Tree {
private:
  Node* root;

public:
  Tree();
  ~Tree();
  Tree(const Tree&) = delete;
  Tree& operator=(const Tree&) = delete;

  void insert( const string & word);
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  void remove( const string & word);
  Node* search( const string & word);
//bool search (const string &) const;

private:

  bool noChildren(Node* curr) const;
  void insert(Node* curr, const string& word);
  void addData(Node* addHere, const string& word);
  void preOrder(const Node* curr) const;
  void inOrder(const Node* curr) const;
  void postOrder(const Node* curr) const;
  //void fix(Node* emptyNode);
  bool hasTwoChildSibling(Node* sibling) const;
  Node* search(Node* curr, const string& word);
};

#endif