#include "Tree.h"
#include <iostream>
#include <string>

using namespace std;

/* 

static const string& midStr( const string& s1, const string& s2, const string& s3 ) {
  if (( s1 < s2 && s1 > s3 ) ||( s1 < s3 && s1 > s2 ) ) 
    return s1;
  else if (( s2 < s1 && s2 > s3 ) ||( s2 < s3 && s2 > s1 ) ) 
    return s2;
  else 
    return s3;
}

static const string& minStr( const string& s1, const string& s2, const string& s3 ) {
  if ( s1 < s2 && s1 < s3 ) 
    return s1;
  else if ( s2 < s1 && s2 < s3 ) 
    return s2;
  else
    return s3;
}

static const string& maxStr( const string& s1, const string& s2, const string& s3 ) {
  if ( s1 > s2 && s1 > s3 ) 
    return s1;
  else if ( s2 > s1 && s2 > s3 ) 
    return s2;
  else
    return s3;
}
*/

Tree::Tree() {
  root = NULL;
}

Tree::~Tree() {

  postOrder(root);
  root = nullptr;
}


bool Tree::noChildren( Node* node ) const {
  if (!node->left && !node->middle && !node->right)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Tree::insert( const string& word ) {
  if ( root == nullptr ) {
    root = new Node( word );
  } else {
    insert( root, word );
  }
}


void Tree::insert( Node* curr, const string& word )
{
  if (curr->numData == 1)
  {
    addData(curr, word);
  }
  else if (curr->numData == 2)
  {
    if (curr->small > word)
    {
      if (curr->left == nullptr)
      {
        curr->left = new Node (word);
      }
      else
      {
        insert(curr->left, word);
      }
      
    }
    else if (curr->large < word)
    {
      if (curr->right == nullptr)
      {
        curr->right = new Node (word);
      }
      else
      {
        insert(curr->right, word);
      }
      
    }
    else
    {
      if (curr->middle == nullptr)
      {
        curr->middle = new Node (word);
      }
      else
      {
        insert(curr->middle, word);
      }
    }
  }
}


/*void Tree::addData( Node* addHere, const string& word ) {
  addHere->data += word;
}*/

void Tree::preOrder() const {
  preOrder( root );
  cout << endl;
}

void Tree::preOrder( const Node* curr ) const {
  if (curr)
  {
    cout << curr->small << " ";
    preOrder(curr->left);
    preOrder(curr->middle);
    cout << curr->large << ", ";
    preOrder(curr->right);
  }
  
}

void Tree::inOrder() const {
  inOrder( root );
  cout << endl;
}

void Tree::inOrder(const Node* curr) const {
  if (curr)
  {
    inOrder(curr->left);
    cout << curr->small << " ";
    inOrder(curr->middle);
    cout << curr->large << ", ";
    inOrder(curr->right);
  }
}

void Tree::postOrder() const {
  postOrder( root );
  cout << endl;
}

void Tree::postOrder(const Node* curr) const {
  if (curr)
  {
    postOrder(curr->left);
    postOrder(curr->middle);
    cout << curr->small << " ";
    postOrder(curr->right);
    cout << curr->large << ", ";
    //delete curr;
  }
}

void Tree::addData(Node* addHere, const string& word)
{
  if (word < addHere->small)
  {
    addHere->large = addHere->small;
    addHere->small = word;
  }
  else
  {
    addHere->large = word;
  }
  ++addHere->numData;
}

void Tree::remove(const string &word) {
    Node *nodeToRemove = search(root, word);
    if (nodeToRemove) {
        if (nodeToRemove->numData == 1) {
            if (nodeToRemove == root && noChildren(root)) {
                delete root;
                root = nullptr;
                return;
            }
            if (nodeToRemove->left || nodeToRemove->middle || nodeToRemove->right) {
                // Internal node with children
                Node *replacementNode = nullptr;
                if (nodeToRemove->left) {
                    replacementNode = nodeToRemove->left;
                    while (replacementNode->right) {
                        replacementNode = replacementNode->right;
                    }
                } else if (nodeToRemove->middle) {
                    replacementNode = nodeToRemove->middle;
                    while (replacementNode->right) {
                        replacementNode = replacementNode->right;
                    }
                } else if (nodeToRemove->right) {
                    replacementNode = nodeToRemove->right;
                    while (replacementNode->left) {
                        replacementNode = replacementNode->left;
                    }
                }
                nodeToRemove->small = replacementNode->small;
                remove(replacementNode->small);
            } else {
                // Leaf node
                if (nodeToRemove->parent) {
                    Node *parent = nodeToRemove->parent;
                    if (parent->left == nodeToRemove) {
                        parent->left = nullptr;
                    } else if (parent->middle == nodeToRemove) {
                        parent->middle = nullptr;
                    } else if (parent->right == nodeToRemove) {
                        parent->right = nullptr;
                    }
                    delete nodeToRemove;
                    if (parent->numData == 2) {
                        parent->numData--;
                        if (parent->large == word) {
                            parent->large = "";
                        }
                    }
                }
            }
        } else if (nodeToRemove->numData == 2) {
            if (nodeToRemove->small == word) {
                nodeToRemove->small = nodeToRemove->large;
            }
            nodeToRemove->large = "";
            nodeToRemove->numData--;
        }
    }
}


bool Tree::hasTwoChildSibling(Node* sib) const {
  return sib->left && sib->right;
}

// This is NOT const because we want the node* so we can
// do a remove
Node* Tree::search(const string& word) {
  return search(root, word);
}

Node* Tree::search( Node* curr, const string& word )
{
  if (curr == nullptr)
  {
    return nullptr;
  }
  if (curr->small == word || (curr->numData == 2 && curr->large == word))
  {
    return curr;
  }
  else if (word < curr->small)
  {
    return search(curr->left, word);
  }
  else if (curr->numData == 2 && word > curr->large)
  {
    return search(curr->right, word);
  }
  else
  {
    return search(curr->middle, word);
  }
}