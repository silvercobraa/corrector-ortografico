#include <iostream>
#include "TrieNode.h"

TrieNode::TrieNode()
{
	child_nodes = new vector<TrieNode*>(26);
	parent_node = NULL;
	valid = false;
}

TrieNode::TrieNode(TrieNode* tn)
{
	child_nodes = new vector<TrieNode*>(26);
	parent_node = tn;
	valid = false;
}

TrieNode* TrieNode::get_child(char c)
{
	return child_nodes->at(c - 'a');
}

void TrieNode::set_child(char c, TrieNode* tn)
{
	child_nodes->at(c - 'a') = tn;
}

bool TrieNode::is_valid()
{
	return valid;
}

int TrieNode::set_valid(bool new_state)
{
	bool previous_state = valid;
	valid = new_state;
	return (int)new_state-(int)previous_state;
}

TrieNode* TrieNode::get_parent()
{
	return parent_node;
}
