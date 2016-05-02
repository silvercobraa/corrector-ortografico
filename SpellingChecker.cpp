#include <fstream>
#include "SpellingChecker.h"

SpellingChecker::SpellingChecker()
{
	this->dictionary = new Trie();
}

void SpellingChecker::set_dictionary(Trie* dictionary)
{
	this->dictionary = dictionary;
}

Trie* SpellingChecker::get_dictionary()
{
	return this->dictionary;
}

void SpellingChecker::add_word(std::string s)
{
	dictionary->add_word(s);
}

void SpellingChecker::check_spelling(const char* path)
{
	std::cout << "No implementado aún." << std::endl;
}

bool SpellingChecker::validate_length(std::string s1, std::string s2)
{
	if (s1.size() - s2.size() <= 2 || s2.size() - s1.size() <= 2)
	{
		return true;
	}
	return false;
}

bool SpellingChecker::is_prefix(std::string s1, std::string s2)
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

bool SpellingChecker::differs_at_most_by_2_characters(std::string s1, std::string s2)
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

std::string SpellingChecker::check_spelling(std::string word)
{
	std::string return_value = "";
	if (!dictionary->contains(word))
	{
		return_value += word + ":";

	}
	return return_value;
}

bool is_suggestion(std::string M, std::string C)
{
	return (is_prefix(M, C) || is_prefix(C, M)) && validate_length(M, C) && differs_at_most_by_2_characters(M, C);
}
