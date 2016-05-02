#include <fstream>
#include "SpellingChecker.h"

SpellingChecker::SpellingChecker()
{
	this->dictionary = new Trie();
}

void SpellingChecker::set_dictionary(const char* path)
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

Trie* SpellingChecker::get_dicctionary()
{
	return this->dictionary;
}

void SpellingChecker::check_spelling(const char* path)
{
	std::cout << "No implementado aún." << std::endl;
}

bool validate_length(std::string s1, std::string s2)
{
	if (s1.size() - s2.size() <= 2 || s2.size() - s1.size() <= 2)
	{
		return true;
	}
	return false;
}

bool is_prefix(std::string s1, std::string s2)
{
	// Si s1 es más larga no puede ser un prefijo de s.
	if (s1.size() > s2.size())
	{
		return false;
	}
	for (unsigned int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			return false;
		}
	}
	return true;
}

std::string shortest(std::string s1, std::string s2)
{
	if (s1.size() < s2.size())
	{
		return s2;
	}
	else
	{
		return s1;
	}
}

bool differs_at_most_by_2_characters(std::string s1, std::string s2)
{
	if (s1.size() <= 3 || s2.size() <= 3)
	{
		return false;
	}
	int mismatches = 0;
	string aux = shortest(s1, s2);
	for (unsigned int i = 0; i < aux.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			mismatches++;
		}
	}
	if (mismatches < 2)
	{
		return true;
	}
	return false;
}
