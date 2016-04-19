#include <vector>

using namespace std;
#ifndef _TRIENODE_H_
#define _TRIENODE_H_

class TrieNode
{
private:
	/**
	* Este vector contiene un puntero a un TrieNode por cada letra del alfabeto.
	*/
	vector<TrieNode*>* child_nodes;

	/**
	 * Este boleano indica que la palabra que se forma desde la raíz hasta este nodo está en el diccionario.
	 */
	bool leaf;

	/**
	 * Puntero al nodo padre. No estoy seguro si será necesario pero lo dejo por si acaso
	 */
	TrieNode* parent_node;

public:
	TrieNode();
	TrieNode(TrieNode* tn);
	TrieNode* get_child(char c);
	void set_child(char character, TrieNode* tn);
	bool is_leaf();
	void set_leaf(bool b);
};

#endif
