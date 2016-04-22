#include <iostream>
#include "TrieNode.h"

TrieNode::TrieNode()
{
	child_nodes = new vector<TrieNode*>(26);
	parent_node = NULL;
	leaf = false;
}

TrieNode::TrieNode(TrieNode* tn)
{
	child_nodes = new vector<TrieNode*>(26);
	parent_node = tn;
	leaf = false;
}

TrieNode* TrieNode::get_child(char c)
{
	return child_nodes->at(c - 'a');
}

void TrieNode::set_child(char c, TrieNode* tn)
{
	child_nodes->at(c - 'a') = tn;
}

bool TrieNode::is_leaf()
{
	return leaf;
}

void TrieNode::set_leaf(bool b)
{
	leaf = b;
}

TrieNode* TrieNode::get_parent()
{
	return parent_node;
}
