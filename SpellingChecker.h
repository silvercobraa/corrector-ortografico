// TODO: RENOMBRAR MÉTODOS

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

	/**
	 * Vector donde se guardan las palabras que se consideren como sugenencias
	 * válidas al revisar la ortografía de una palabra.
	 */
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
	 * Retorna true si s1  s2 difieren a los más en 2 caracteres y el largo de
	 * ambas es mayor a 3.
	 */
	bool differs_at_most_by_2_characters(std::string s1, std::string s2);


public:
	SpellingChecker();
	SpellingChecker(FileHandler* f);

	/**
	 * Retorna un trie que representa al diccionario.
	 */
	Trie* get_dictionary();

	/**
	 * Agrega la palabra 's' al conjunto de palabras válidas.
	 */
	void add_word(std::string s);


	void check_spelling(std::string word);

	/**
	 * Retorna la cantidad de palabras revisadas.
	 */
	int get_total_checked_words();

	/**
	 * Retorna la cantidad de palabras evisadas que están mal escritas, según el
	 * diccionario de este corrector ortográfico.
	 */
	int get_total_mispelled_words();

	/**
	* Este metodo busca palabras en el diccionario que tengan como prefijo a word
	* y las agrega al vector de sugerencias.
	*/
	void add_suggestions_1(TrieNode* t, std::string word);

	/**
	 * Este metodo busca palabras en el diccionario que sean prefijos de word.
	 */
	void add_suggestions_2(std::string word);

	/**
	 * Este metodo busca palabras difieran a lo más en dos caracteres de word
	 * y las agrega al vector de sugerencias, siempre y cuando la word y s sean
	 * de largo mayor que 3.
	 */
	void add_suggestions_3(TrieNode* t, std::string s, std::string word, int current_position, int mismatches);

};


#endif
