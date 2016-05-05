#include <iostream>
#include <fstream>
#include <cstdio>
#include "SpellingChecker.h"
#include "FileHandler.h"

int main(int argc, char const **argv)
{
	std::string NOMBRE_ALUMNOS = "Cesar Bolivar, David Vidal";
	std::string NOMBRE_ARCHIVO_REVISADO = argv[2];
	std::string URL_DICCIONARIO = "http://www.winedt.org/dict.html";

	FileHandler* file_handler = new FileHandler(argv[1], argv[2], argv[3]);
	/*Trie* t = */file_handler->extract_dictionary_file_words();

	//t->print_trie();
	file_handler->write_to_log("Alumnos: " + NOMBRE_ALUMNOS + "\n");
	file_handler->write_to_log("Nombre archivo revisado: " + NOMBRE_ARCHIVO_REVISADO + "\n");
	file_handler->write_to_log("URL diccionario usado: " + URL_DICCIONARIO + "\n");
	file_handler->write_suggestions();
	file_handler->write_statistics();
	file_handler->close_all();
	return 0;
}
