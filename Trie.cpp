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
	if (t->is_leaf)
	{
		std::cout << s << std::endl;
		return;
	}
	for (int i = 0; i < 26; i++)
	{
		// print_node(t->child_nodes->at(i), s + 'a' + i));
		char aux = 'a' + i;
		print_node(t->child_nodes->at(i), s + aux);
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
		if (aux->child_nodes->at(s[i] - 'a') == NULL)
		{
			aux->child_nodes->at(s[i] - 'a') = new TrieNode(aux);
		}
		aux = aux->child_nodes->at(s[i] - 'a');
	}
	if (aux != root)
	{
		aux->is_leaf = true;
	}
}
