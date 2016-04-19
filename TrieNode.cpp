#include "TrieNode.h"

TrieNode::TrieNode()
{
	child_nodes = new vector<TrieNode*>(26);
}

TrieNode::TrieNode(TrieNode* tn)
{
	child_nodes = new vector<TrieNode*>(26);
	parent_node = tn;
}
