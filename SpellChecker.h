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

	Trie* get_dicctionary();

};


#endif
