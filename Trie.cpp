#include "Trie.h"

Trie::Trie()
{
	root = new TrieNode();
	total_words = 0;
}

void print_node(TrieNode* t, std::string s)
{
	if (t == NULL)
	{
		return;
	}
	if (t->is_valid())
	{
		std::cout << s << std::endl;
		//return; // No debe retonar cuando sea una hoja puede podrian haber mas palabras con el mismo prefijo
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		print_node(t->get_child(c), s + c);
	}
}
void Trie::print_trie()
{
	print_node(root, "");
}

int Trie::add_word(std::string s)
{
	TrieNode* aux = root;
	int return_value;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		//std::cout << "s[i] - 'a': " << s[i] - 'a' << std::endl;
		// si el nodo no existe, es creado
		if (aux->get_child(s[i]) == NULL)
		{
			aux->set_child(s[i], new TrieNode(aux));
		}
		aux = aux->get_child(s[i]);
	}
	if (aux != root)
	{
		return_value = aux->set_valid(true);
		total_words += return_value;
	}
	return return_value;
}

bool Trie::contains(std::string s)
{
	TrieNode* t = root;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (t == NULL)
		{
			return false;
		}
		t = t->get_child(s[i]);
	}
	return t->is_valid();
}


int Trie::get_total_words()
{
	return total_words;
}

Trie::KeyIterator* Trie::get_key_iterator()
{
	return new KeyIterator();
}

Trie::KeyIterator::KeyIterator()
{
	// TODO: Implementar constructor.
}

bool Trie::KeyIterator::has_next()
{
	// TODO: Implementar este método.
	return false;
}

std::string Trie::KeyIterator::get_next()
{
	// TODO: Implementar este método.
	return NULL;
}
