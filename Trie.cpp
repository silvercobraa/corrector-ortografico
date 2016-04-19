#include "Trie.h"

Trie::Trie()
{
	root = new TrieNode(NULL);
}

void print_node(TrieNode* t, std::string s)
{
	if (t == NULL)
	{
		std::cout << s << std::endl;
		return;
	}
	for (int i = 0; i < 26; i++)
	{
		print_node(t->child_nodes->at(i), s.append(1, 'a' + i));
	}
}
void Trie::print_trie()
{
	print_node(root, "");
}
