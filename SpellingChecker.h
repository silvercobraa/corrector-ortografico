#include "Trie.h"

#ifndef _SPELL_CHECKER_
#define _SPELL_CHECKER_


class SpellingChecker
{
private:

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
	 * Retorna el trie que representa al diccionario.
	 */
	Trie* get_dicctionary();

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
