#include <iostream>
#include "TrieNode.h"

#ifndef _TRIE_H_
#define _TRIE_H_


class Trie
{
//private:
public:
	TrieNode* root;
	Trie ();
	void print_trie();
	void add_word(std::string s);
};


#endif /* end of include guard: _TRIE_H_ */
