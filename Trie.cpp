#include "Trie.h"

Trie::Trie()
{
	root = new TrieNode();
}

void print_node(TrieNode* t, std::string s)
{
	if (t == NULL)
	{
		return;
	}
	if (t->is_valid())
	{
		std::cout << s << std::endl;
		//return; // No debe retonar cuando sea una hoja puede podrian haber mas palabras con el mismo prefijo
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		print_node(t->get_child(c), s + c);
	}
}
void Trie::print_trie()
{
	print_node(root, "");
}

void Trie::add_word(std::string s)
{
	TrieNode* aux = root;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		//std::cout << "s[i] - 'a': " << s[i] - 'a' << std::endl;
		// si el nodo no existe, es creado
		if (aux->get_child(s[i]) == NULL)
		{
			aux->set_child(s[i], new TrieNode(aux));
		}
		aux = aux->get_child(s[i]);
	}
	if (aux != root)
	{
		aux->set_valid(true);
	}
}

bool Trie::contains(std::string s)
{
	TrieNode* t = root;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (t == NULL)
		{
			return false;
		}
		t = t->get_child(s[i]);
	}
	return t->is_valid();
}
