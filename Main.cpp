#include <iostream>
#include "TrieNode.h"
#include "Trie.h"

using namespace std;

int main(int argc, char const *argv[])
{
	TrieNode* tn = new TrieNode();
	cout << tn->child_nodes->size() << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << tn->child_nodes->at(i) << endl;
	}
	Trie* t = new Trie();
	t->print_trie();
	return 0;
}
