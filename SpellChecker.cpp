#include <fstream>
#include "SpellChecker.h"

SpellChecker::SpellChecker()
{
	this->dictionary = new Trie();
}

void SpellChecker::set_dictionary(const char* path)
{
	std::ifstream dictionary_file;
	dictionary_file.open(path);
	if (!dictionary_file.is_open())
	{
		std::cout << "No se pudo abrir el archivo " << path << std::endl;
		return;
	}
	std::string line;
	while(!dictionary_file.eof())
	{
		std::getline(dictionary_file, line);
		if (line[0] == '%')
		{
			continue;
		}
		dictionary->add_word(line);
	}
}

Trie* SpellChecker::get_dicctionary()
{
	return this->dictionary;
}

void SpellChecker::check_spelling(const char* path)
{
	std::cout << "No implementado aún." << std::endl;
}
