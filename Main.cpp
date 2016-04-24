#include <iostream>
#include <fstream>
#include <cstdio>
#include "SpellChecker.h"


int main(int argc, char const **argv)
{
	SpellChecker* sp = new SpellChecker();
	sp->set_dictionary(argv[1]);
	Trie* t = sp->get_dicctionary();
	t->print_trie();
	std::cout << "Contiene 'comentario': " << t->contains("comentario") << std::endl;
	while (true)
	{

	}
	return 0;
}
