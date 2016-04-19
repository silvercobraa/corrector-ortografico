#include <iostream>
#include "TrieNode.h"
#include "Trie.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Trie* t = new Trie();
	string s = "hola";
	t->add_word(s);
	t->add_word("wena");
	t->add_word("gooby");
	t->add_word("pls");
	t->print_trie();
	return 0;
}
