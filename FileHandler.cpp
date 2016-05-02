#include "FileHandler.h"

FileHandler::FileHandler()
{
}

FileHandler::FileHandler(const char* dictionary_file_path, const char* input_file_path, const char* log_file_path)
{
	spelling_checker = new SpellingChecker();
	// FALTA CHECKEAR LOS OPEN!!
	dictionary_file.open(dictionary_file_path);
	input_file.open(input_file_path);
	log_file.open(log_file_path);

	check_open_files(dictionary_file_path, input_file_path, log_file_path);
}

void FileHandler::check_open_files(const char* dictionary_file_path, const char* input_file_path, const char* log_file_path)
{
	if (!dictionary_file.is_open())
	{
		std::cout << "No se pudo abrir el archivo " << dictionary_file_path << std::endl;
		throw -1;
	}
	if (!input_file.is_open())
	{
		std::cout << "No se pudo abrir el archivo " << input_file_path << std::endl;
		throw -1;
	}
	if (!log_file.is_open())
	{
		std::cout << "No se pudo abrir el archivo " << log_file_path << std::endl;
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
