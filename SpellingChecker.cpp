#include <fstream>
#include <algorithm>
#include "SpellingChecker.h"

SpellingChecker::SpellingChecker()
{
	this->dictionary = new Trie();
	this->total_checked_words = 0;
	this->total_mispelled_words = 0;
}

Trie* SpellingChecker::get_dictionary()
{
	return this->dictionary;
}

int SpellingChecker::get_total_checked_words()
{
	return total_checked_words;
}
int SpellingChecker::get_total_mispelled_words()
{
	return total_mispelled_words;
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
	int length_difference = std::abs((signed)s1.size()-(signed)s2.size());
	//std::cout << "length difference: " << length_difference << std::endl;
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
	//if (mismatches + length_difference <= 2)
	if (mismatches <= 2 && length_difference <= 2)
	{
		return true;
	}
	return false;
}

void SpellingChecker::add_suggestions_1(vector<std::string>* suggestions, TrieNode* t, std::string word)
{
	TrieNode* aux = t;
	for (unsigned int i = 0; i < word.size(); i++)
	{
		if (aux == NULL)
		{
			return;
		}
		aux = aux->get_child(word[i]);
	}
	if (aux == NULL)
	{
		return;
	}
	for (char c1 = 'a'; c1 <= 'z'; c1++)
	{
		if (aux->get_child(c1) == NULL)
		{
			continue;
		}
		for (char c2 = 'a'; c2 <= 'z'; c2++)
		{
			if (aux->get_child(c1)->get_child(c2) == NULL)
			{
				continue;
			}
			if (aux->get_child(c1)->get_child(c2)->is_valid())
			{
				suggestions->push_back((word + c1) + c2);
			}
		}
	}
}

void SpellingChecker::add_suggestions_2(vector<std::string>* suggestions, std::string word)
{
	TrieNode* t = dictionary->get_root();
	std::string s = "";
	for (unsigned int i = 0; t != NULL && i < word.size(); i++)
	{
		t = t->get_child(word[i]);
		s += word[i];
		if (t != NULL && t->is_valid() && validate_length(s, word))
		{
			suggestions->push_back(s);
		}
	}
}

void SpellingChecker::add_suggestions_3(vector<std::string>* suggestions, TrieNode* t, std::string s, std::string word, int current_position, int mismatches)
{
	if (t == NULL || mismatches > 2)
	{
		return;
	}
	if (t->is_valid() && differs_at_most_by_2_characters(s, word))
	{
		suggestions->push_back(s);
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		if (word[current_position] == c)
		{
			add_suggestions_3(suggestions, t->get_child(c), s + c, word, current_position+1, mismatches);
		}
		else
		{
			add_suggestions_3(suggestions, t->get_child(c), s + c, word, current_position+1, mismatches+1);
		}
	}

}

vector<std::string> SpellingChecker::check_spelling(std::string word)
{
	vector<std::string> suggestions;
	std::cout << word << std::endl;
	if (!dictionary->contains(word))
	{
		add_suggestions_1(&suggestions, dictionary->get_root(), word);
		add_suggestions_2(&suggestions, word);
		add_suggestions_3(&suggestions, dictionary->get_root(), "", word, 0, 0);

		std::sort(suggestions.begin(), suggestions.end());
		suggestions.erase(std::unique(suggestions.begin(), suggestions.end()), suggestions.end());

		total_mispelled_words++;
	}
	else
	{
		suggestions.push_back(word);
	}
	total_checked_words++;
	return suggestions;
}
