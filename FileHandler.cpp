#include "FileHandler.h"

FileHandler::FileHandler()
{
}

FileHandler::FileHandler(const char* dictionary_file_path, const char* input_file_path, const char* log_file_path)
{
	palabras_revisadas = 0;
	palabras_mal_escritas = 0;
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

void FileHandler::magic(TrieNode* t, std::string s, std::string word)
{
	if (t == NULL)
	{
		return;
	}
	if (t->is_valid())
	{
		if (spelling_checker->is_suggestion(word, s))
		{
			write_to_log(" " + s);
		}
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		magic(t->get_child(c), s + c, word);
	}
}
void FileHandler::write_suggestions()
{
	std::string word = "";
	std::string lowercase = "";
	while(true)
	{
		input_file >> word;
		if (input_file.eof())
		{
			break;
		}
		std::cout << "word: " << word << std::endl;
		for (unsigned int i = 0; i < word.size(); i++)
		{
			if ('A' <= word[i] && word[i] <= 'Z')
			{
				lowercase += (word[i]-'A'+'a');
			}
			else if ('a' <= word[i] && word[i] <= 'z')
			{
				lowercase += (word[i]);
			}
		}
		std::cout << "lowercase: " << lowercase << std::endl;
		if (!spelling_checker->get_dictionary()->contains(lowercase))
		{
			write_to_log(lowercase + ":");
			magic(spelling_checker->get_dictionary()->get_root(), "", lowercase);
			write_to_log("\n");
			palabras_mal_escritas++;
		}
		palabras_revisadas++;
		//write_to_log(spelling_checker->check_spelling(lowercase));

		lowercase.clear();
	}
}

void FileHandler::write_to_log(std::string s)
{
	log_file << s;
}

void FileHandler::write_statistics()
{
	log_file << "cantidad de palabras del diccionario: " << spelling_checker->get_dictionary()->get_total_words() << std::endl;
	//log_file << "palabras bien escritas: " << spelling_checker->get_total_checked_words()-spelling_checker->get_total_mispelled_words() << std::endl;
	log_file << "palabras bien escritas: " << palabras_revisadas-palabras_mal_escritas << std::endl;
	log_file << "palabras mal escritas: " << palabras_mal_escritas << std::endl;
}

void FileHandler::close_all()
{
	dictionary_file.close();
	input_file.close();
	log_file.close();
}
