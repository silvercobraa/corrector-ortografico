#include <vector>
#include "Trie.h"
#include "FileHandler.h"

#ifndef _SPELLING_CHECKER_H_
#define _SPELLING_CHECKER_H_

class FileHandler;

class SpellingChecker
{
private:

	FileHandler* file_handler;
	vector<std::string> suggestions;
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
	SpellingChecker(FileHandler* f);

	void print_suggestions_1(TrieNode* t, std::string s, std::string word, int differences);
	void print_suggestions_2(TrieNode* t, std::string s, std::string word, int differences);

	/**
	 * Llena el diccionario de este corrector ortográfico con todas las palabras
	 * del archivo cuya ruta es 'path'. Se asume una palabra por línea.
	 */
	void set_dictionary(Trie* dictionary);

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
	void check_spelling(std::string word);

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

	/**
	 * Retorna la cantidad de palabras revisadas.
	 */
	int get_total_checked_words();

	/**
	 * Retorna la cantidad de palabras evisadas que están mal escritas, según el
	 * diccionario de este corrector ortográfico.
	 */
	int get_total_mispelled_words();

	void magic(std::string word);
};


#endif
