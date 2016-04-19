#include "Trie.h"

Trie::Trie()
{
	root = new TrieNode(NULL);
}

void print_node(TrieNode* t, std::string s)
{
	if (t == NULL)
	{
		// std::cout << s << std::endl;
		return;
	}
	if (t->is_leaf())
	{
		std::cout << s << std::endl;
		return;
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		// print_node(t->child_nodes->at(i), s + 'a' + i));
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
		std::cout << "s[i] - 'a': " << s[i] - 'a' << std::endl;
		if (aux->get_child(s[i]) == NULL)
		{
			aux->set_child(s[i], new TrieNode(aux));
		}
		aux = aux->get_child(s[i]);
	}
	if (aux != root)
	{
		aux->set_leaf(true);
	}
}
