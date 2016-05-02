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
	 * Setea el archivo cuya ruta es 'path' como el archivo de salida de la
	 * correción ortográfica. Si no existe, es creado.
	 */
	void set_log_file(const char* path);

	/**
	 * Vacía el archivo log.
	 */
	void empty_log_file();

	/**
	 * Revisa la ortografía del archivo cuya ruta es 'path'.
	 */
	void check_spelling(const char* path);

};


#endif
