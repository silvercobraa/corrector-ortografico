#include <vector>

using namespace std;
#ifndef _TRIENODE_H_
#define _TRIENODE_H_

/**
 * Clase que representa el nodo de un Trie con 26 hijos: uno por cada letra
 * minúscula.
 */
class TrieNode
{
private:

	/**
	* Este vector contiene un puntero a un TrieNode por cada letra del alfabeto.
	* La posición cero coresponde a la 'a' y la posición 25 corresponde a la 'z'.
	*/
	vector<TrieNode*>* child_nodes;

	/**
	 * Este boleano indica que la palabra que se forma desde la raíz hasta este
	 * nodo se considera como válida.
	 */
	bool valid;

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
	 * Retorna true si este nodo contiene es considerado válido. Retorna false
	 * si no lo es (duh).
	 */
	bool is_valid();

	/**
	 * Setea el estado de este nodo. Retorna 0 si el nodo se mantiene true o false,
	 * 1 si el nodo pasa de false a true y -1 si pasa de true a false;
	 */
	int set_valid(bool new_state);

	TrieNode* get_parent();
};

#endif
