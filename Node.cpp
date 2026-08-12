#include "Node.h"

Node::Node()
  : 
    small(""),
    large(""),
    numData(1),
    parent(nullptr),
    left(nullptr),
    middle(nullptr),
    right(nullptr)
{
}

//------------------------------------------------------------------------

Node::Node(const string& word )
  : small(word),
    large(""),
    numData(1),
    parent(nullptr),
    left(nullptr),
    middle(nullptr),
    right(nullptr)
{
}
