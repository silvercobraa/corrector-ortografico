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
	// AQUI SE DEBERIA ITERAR EL TRIE Y LLAMAR AL METODO IS SUGGESTION POR CADA
	// PALABRA, PARA LUEGO CONCATENARLA A RETURN VALUE. ESTA FUNCION (check_spelling)
	// DEBERIA SER LLAMADA POR EL FILE HANDLER, QUE ESCRIBIRIA EL RETORNO EN EL
	// ARCHIVO LOG.
	if (!dictionary->contains(word))
	{
		return_value += word + ":";

	}
	return return_value;
}

bool SpellingChecker::is_suggestion(std::string M, std::string C)
{
	if (!validate_length(M, C))
	{
		return false;
	}
	if (is_prefix(M, C) || is_prefix(C, M))
	{
		return true;
	}
	if (differs_at_most_by_2_characters(M, C) && M.size() > 3 && C.size() > 3)
	{
		return true;
	}
	return false;
}
