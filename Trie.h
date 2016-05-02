#include <iostream>
#include "TrieNode.h"

#ifndef _TRIE_H_
#define _TRIE_H_


class Trie
{
private:
	/**
	 * Nodo raíz de este trie. Nunca es nulo y su campo valid siempre es falso.
	 */
	TrieNode* root;

	/**
	 * Cantidad de palabras que contiene este Trie.
	 */
	int total_words;
public:

	Trie();

	/**
	 * Imprime este trie en orden lexicográfico.
	 */
	void print_trie();

	/**
	 * Agrega una palabra a este trie. Retorna 1 si la palabra es nueva y retorna
	 * 0 si la palabra ya estaba contenida.
	 */
	int add_word(std::string s);

	/**
	 * Retorna true si este diccionario contiene la palabra 's'.
	 */
	bool contains(std::string s);

	/**
	 * Retona la cantidad de palabras que contiene este Trie.
	 */
	int get_total_words();
};


#endif
