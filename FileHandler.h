#ifndef _FILE_HANDLER_H_
#define _FILE_HANDLER_H_

#include <fstream>
#include "SpellingChecker.h"

class FileHandler
{
private:

	/**
	 * Corrector ortográfico que utilizará este manejador de archivos.
	 */
	SpellingChecker* spelling_checker;

	/**
	 * Archivo que contiene las palabras que se consideran bien escritas.
	 */
	std::ifstream dictionary_file;

	/**
	 * Archivo cuya ortografía se quiere revisar.
	 */
	std::ifstream input_file;

	/**
	 * Archivo donde se escribe la salida de la correción ortográfica, es decir,
	 * las palabras mal escritas y sus sugerencias.
	 */
	std::ofstream log_file;

	/**
	 * Lanza una excepción si el archivo 'file' no pudo abrirse.
	 */
	void check_open(std::ifstream* file, const char* path);


public:

	FileHandler();

	FileHandler (const char* dictionary_file_path, const char* input_file_path, const char* log_file_path);

	/**
	 * Retorna un trie con todas las palabras contenidas en el archivo
	 * dictionary_file. Se asume una palabra por línea, es decir, se ignoran todas
	 * las palabras excepto las primeras de cada fila. Además, se ignoran las
	 * líneas que comiencen con un signo porcentaje ('%').
	 */
	Trie* extract_dictionary_file_words();

	/**
	 * Llena el archivo log_file con las palabras mal escritas, sus sugerencias
	 * y el resumen de estadísticas.
	 */
	void write_log_file();

};


#endif
