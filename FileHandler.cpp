#include "FileHandler.h"

FileHandler::FileHandler()
{
}

FileHandler::FileHandler(const char* dictionary_file_path, const char* input_file_path, const char* log_file_path)
{
	spelling_checker = new SpellingChecker();
	dictionary_file.open(dictionary_file_path);
	input_file.open(input_file_path);
	log_file.open(log_file_path);

	check_open(&dictionary_file, dictionary_file_path);
	check_open(&input_file, input_file_path);
}

void FileHandler::check_open(std::ifstream* file, const char* path)
{
	if (!file->is_open())
	{
		std::cout << "No se pudo abrir el archivo " << path << std::endl;
		throw -1;
	}
}

Trie* FileHandler::extract_dictionary_file_words()
{
	std::string line;
	while(!dictionary_file.eof())
	{
		std::getline(dictionary_file, line);
		//std::cout << line << std::endl;
		if (line[0] == '%')
		{
			continue;
		}
		spelling_checker->add_word(line);
	}
	return spelling_checker->get_dictionary();
}

void FileHandler::write_log_file()
{
	// TODO:
	// 1 - Escribir en el log nombre del alumno, nombre del archivo que se reviso y
	// diccionario utilizado para la revisi ́on (URL en la cuál está disponible
	// para descarga).
	// 2 - Parsear el archivo input_file y escribir en el log el retorno del método
	// check_spelling evaluado en cada palabra extraida de dicho archivo.
	// 3 - Escribir en el log un resumen de estadísticas de la revisión que
	// incluya: número total de palabras que contiene el diccionario, número de
	// palabras escritas correctamente y número de palabras con error. Cada una
	// en una línea.
}
