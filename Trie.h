#include <iostream>
#include "TrieNode.h"

#ifndef _TRIE_H_
#define _TRIE_H_


class Trie
{
private:
	TrieNode* root;
public:
	Trie ();
	void print_trie();
};


#endif /* end of include guard: _TRIE_H_ */
