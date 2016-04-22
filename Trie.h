#include <iostream>
#include "TrieNode.h"

#ifndef _TRIE_H_
#define _TRIE_H_


class Trie
{
private:
	/**
	 * Nodo raíz de este trie. Nunca es nulo y su campo leaf siempre es falso.
	 */
	TrieNode* root;
public:

	Trie();

	/**
	 * Imprime este trie en orden lexicográfico.
	 */
	void print_trie();

	/**
	 * Agrega una palabra a este trie.
	 */
	void add_word(std::string s);

	/**
	 * Retorna true si este diccionario contiene la palabra 's'.
	 */
	bool contains(std::string s);
};


#endif
