#include <iostream>
#include <fstream>
#include <cstdio>
#include "TrieNode.h"
#include "Trie.h"

int main(int argc, char const **argv)
{
	std::ifstream archivo_diccionario;
	archivo_diccionario.open(argv[1]);
	if (!archivo_diccionario.is_open())
	{
		std::cout << "no se pudo abrir el archivo " << argv[1] << std::endl;
		return -1;
	}
	string linea;
	Trie* t = new Trie();
	while(!archivo_diccionario.eof())
	{
		std::getline(archivo_diccionario, linea);
		if (linea[0] == '%')
		{
			continue;
		}
		t->add_word(linea);
		//std::cout << linea << std::endl;
	}
	t->print_trie();
	std::cout << "Contiene 'comentario': " << t->contains("comentario") << std::endl;
	while (true)
	{

	}
	return 0;
}
