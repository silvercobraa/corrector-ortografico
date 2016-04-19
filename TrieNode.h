#include <vector>

using namespace std;
#ifndef _TRIENODE_H_
#define _TRIENODE_H_

class TrieNode
{
//private:
	/**
	 * Este vector contiene un puntero a un TrieNode por cada letra del alfabeto.
	 */
public:
	TrieNode* parent_node;
	bool is_leaf;
	vector<TrieNode*>* child_nodes;
	TrieNode();
	TrieNode(TrieNode* tn);
};

#endif /* end of include guard: _TRIENODE_H_ */
