#include <fstream>
#include <algorithm>
#include "SpellingChecker.h"

SpellingChecker::SpellingChecker()
{
	this->dictionary = new Trie();
	this->file_handler = NULL;
	this->total_checked_words = 0;
	this->total_mispelled_words = 0;
}

SpellingChecker::SpellingChecker(FileHandler* f)
{
	this->dictionary = new Trie();
	this->file_handler = f;
	this->total_checked_words = 0;
	this->total_mispelled_words = 0;
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

bool SpellingChecker::is_suggestion(std::string M, std::string C)
{
	if (!validate_length(M, C))
	{
		return false;
	}
	if (!is_prefix(M, C) && !is_prefix(C, M))
	{
		return false;
	}
	if (differs_at_most_by_2_characters(M, C) && M.size() > 3 && C.size() > 3)
	{
		return true;
	}
	return false;
}

void SpellingChecker::magic(std::string word)
{
	for (char c1 = 'a'; c1 <= 'z'; c1++)
	{
		for (char c2 = 'a'; c2 <= 'z'; c2++)
		{
			if (dictionary->contains((word + c1) + c2))
			{
				suggestions.push_back((word + c1) + c2);
			}
		}
	}
}

void SpellingChecker::print_suggestions_1(TrieNode* t, std::string s, std::string word, int differences)
{
	if (t == NULL || differences > 2)
	{
		return;
	}
	TrieNode* aux = t;
	for (unsigned int i = 0; i < word.size() && aux != NULL; i++)
	{
		aux = aux->get_child(word[i]);
	}
	if (aux != NULL && aux->is_valid())
	{
		suggestions.push_back(s + word);
		return;
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		print_suggestions_1(t->get_child(c), s + c, word, differences+1);
	}
}

void SpellingChecker::check_spelling(std::string word)
{
	if (!dictionary->contains(word))
	{
		file_handler->write_to_log(word + ":");
		print_suggestions_1(dictionary->get_root(), "", word, 0);
		magic(word);
		// sort vector
		std::sort(suggestions.begin(), suggestions.end());
		std::reverse(suggestions.begin(), suggestions.end());
		while (!suggestions.empty())
		{
			file_handler->write_to_log(" " + suggestions.back());
			suggestions.pop_back();
		}
		file_handler->write_to_log("\n");
		total_mispelled_words++;
	}
	total_checked_words++;
}

int SpellingChecker::get_total_checked_words()
{
	return total_checked_words;
}
int SpellingChecker::get_total_mispelled_words()
{
	return total_mispelled_words;
}
