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
	 * Este boleano indica que la palabra que se forma desde la raíz hasta este
	 * nodo está en el diccionario.
	 */
	bool leaf;

	/**
	 * Puntero al nodo padre. No estoy seguro si será necesario pero lo dejo por
	 * si acaso...
	 */
	TrieNode* parent_node;


public:
	/**
	 * Constructor por defecto. Setea su nodo padre y cada nodo hijo en NULL.
	 */
	TrieNode();

	/**
	 * Setea su nodo padre en tn y cada nodo hijo a NULL.
	 */
	TrieNode(TrieNode* tn);

	/**
	 * Retorna el nodo hijo asiciado al caracter recibido. No se toman
	 * precauciones si el caracter no es una letra minúscula.
	 */
	TrieNode* get_child(char c);

	/**
	 * Setea el nodo hijo asociado al caracter c a tn.
	 */
	void set_child(char c, TrieNode* tn);

	/**
	 * Retorna true si este nodo contiene es considerado válido. Retorna false si no lo es (duh).
	 */
	bool is_valid();

	/**
	 * Setea el estado de este nodo.
	 */
	void set_valid(bool b);

	TrieNode* get_parent();
};

#endif
