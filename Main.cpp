#include <iostream>
#include <fstream>
#include <cstdio>
#include "SpellingChecker.h"
#include "FileHandler.h"

int main(int argc, char const **argv)
{
	FileHandler* file_handler = new FileHandler(argv[1], argv[2], argv[3]);
	Trie* t = file_handler->extract_dictionary_file_words();
	//SpellingChecker* sp = new SpellingChecker();
	//sp->set_dictionary(argv[1]);
	//Trie* t = sp->get_dictionary();
	//t->print_trie();
	std::cout << "total words: " << t->get_total_words() << std::endl;
	SpellingChecker* sc = new SpellingChecker();
	std::cout << sc->is_suggestion("HOL", "HOLAS") << std::endl;
	while (true)
	{

	}
	return 0;
}
