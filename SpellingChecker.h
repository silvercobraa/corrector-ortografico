#include "Trie.h"

#ifndef _SPELLING_CHECKER_H_
#define _SPELLING_CHECKER_H_


class SpellingChecker
{
private:

	/**
	 * Cantidad de palabras revisadas.
	 */
	int total_checked_words;

	/**
	 * Cantidad de palabras que están mal escritas.
	 */
	int total_mispelled_words;

	/**
	 * Trie con las palabras consideradas válidas por este corrector ortográfico.
	 */
	Trie* dictionary;

	/**
	* Retorna true si la longitud de s1 difiere a los mas en 2 unidades de la
	* longitud de s2.
	*/
	bool validate_length(std::string s1, std::string s2);

	/**
	 * Retorna true si s1 es un prefijo de s2. Retorna false en otro caso.
	 */
	bool is_prefix(std::string s1, std::string s2);

	/**
	 * Retorna true si s1  s2 difieren a los más en 2 caracteres y el largo de
	 * ambas es mayor a 3.
	 */
	bool differs_at_most_by_2_characters(std::string s1, std::string s2);

	/**
	 * Retorna true si s1 es una sugerencia válida para s2, según los siguientes
	 * criterios:
	 * - Si las longitudes de M y C difieren en más de dos, entonces C no se
	 *   sugiere.
	 * - Si M es un prefijo de C, o si C es un prefijo de M , entonces se sugiere
	 *   C.
	 * - Se comparan, uno a uno desde el comienzo, los caracteres de M y C hasta
	 *   terminar uno o ambos strings (lo que ocurra primero). Si hay a lo más
	 *   dos diferencias, y ambos M y C son de largo mayor a tres, entonces
	 *   se sugiere C.
	 */
	bool is_suggestion(std::string M, std::string C);

public:
	SpellingChecker();

	/**
	 * Llena el diccionario de este corrector ortográfico con todas las palabras
	 * del archivo cuya ruta es 'path'. Se asume una palabra por línea.
	 */
	void set_dictionary(const char* path);

	/**
	 * Retorna un trie que representa al diccionario.
	 */
	Trie* get_dictionary();

	/**
	 * Agrega la palabra 's' al conjunto de palabras válidas.
	 */
	void add_word(std::string s);

	/**
	 * Revisa la ortografía de la palabra word. Si la palabra no está contenida en el
	 * diccionario, se retorna un string de la forma:
	 * word: sugerencia_1 sugerencia_2 sugerencia_3 ...
	 * Si la palabra está bien escrita, se retorna un string vacío.
	 */
	std::string check_spelling(std::string word);

};


#endif
