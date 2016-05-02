#include <iostream>
#include <fstream>
#include <cstdio>
#include "SpellingChecker.h"


int main(int argc, char const **argv)
{
	SpellingChecker* sp = new SpellingChecker();
	sp->set_dictionary(argv[1]);
	Trie* t = sp->get_dicctionary();
	t->print_trie();
	std::cout << "Contiene 'comentario': " << t->contains("comentario") << std::endl;
	while (true)
	{

	}
	return 0;
}
