//#pragma once
#ifndef _NODE_H
#define _NODE_H

#include <string>

using namespace std;

class Node {

  friend class Tree;

private:
  string small;
  string large;
  int numData;

  Node* parent;
  Node* left;
  Node* middle;
  Node* right;

public:
  Node();

  explicit Node(const string& key);


};

#endif