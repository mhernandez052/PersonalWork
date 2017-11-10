/*
 * Name        : sl_node.cpp
 * Author      : Martin Hernandez
 * Description : cpp for sl_node.h
 *               
 */
#include "sl_node.h"

SLNode::SLNode() {
    next_node_ = NULL;
    contents_ = 0;
  }
SLNode::SLNode(int overloaded) {
    contents_ = overloaded;
    next_node_ = NULL;
}

SLNode::~SLNode() {
}

void SLNode::set_contents(int contents) {
    contents_ = contents;
}
int SLNode::contents() const {
    return contents_;
}
void SLNode::set_next_node(SLNode* next_node) {
    next_node_ = next_node;
}

SLNode* SLNode:: next_node() const {
    return next_node_;
}
