#include "Trie.h"

#ifndef _SPELL_CHECKER_
#define _SPELL_CHECKER_


class SpellChecker
{
private:

	Trie* dictionary;

public:
	SpellChecker();

	/**
	 * Llena el diccionario de este corrector ortográfico con todas las palabras
	 * del archivo cuya ruta es 'path'. Se asume una palabra por línea.
	 */
	void set_dictionary(const char* path);

	/**
	 * Retorna el trie que representa al diccionario.
	 */
	Trie* get_dicctionary();

	/**
	 * Revisa la ortografía del archivo cuya ruta es 'path'.
	 */
	void check_spelling(const char* path);

};


#endif
