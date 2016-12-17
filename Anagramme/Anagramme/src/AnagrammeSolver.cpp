#include "AnagrammeSolver.h"

AnagrammeSolver::AnagrammeSolver(std::string pFileName)
{
	fileName = pFileName;
	fillMap();
}

void AnagrammeSolver::fillMap()
{
	std::cout << "Generating dictionnary..." << std::endl;

	std::ifstream file(fileName);
	assert(file.is_open());

	std::string word;
	while (std::getline(file, word))
	{
		std::string sortedWord = word;
		std::sort(sortedWord.begin(), sortedWord.end());
		dictionnary.insert({ sortedWord, word });
	}
	file.close();
}

std::vector<std::string> AnagrammeSolver::solveWithDictionnary(std::string pWord)
{
	std::string word = pWord;
	assert(std::regex_match(word, std::regex("[a-zA-Z]*")));

	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	std::sort(word.begin(), word.end());

	auto range = dictionnary.equal_range(word);
	std::unordered_multimap<std::string, std::string>::iterator it;

	std::vector<std::string> res;

	for (it = range.first; it != range.second; it++)
		res.push_back(it->second);

	return res;
}

std::vector<std::string> AnagrammeSolver::solveWithoutDictionnary(std::string pWord)
{
	std::string word = pWord;
	assert(std::regex_match(word, std::regex("[a-zA-Z]*")));

	std::vector<std::string> wordVec;

	std::sort(word.begin(), word.end());
	wordVec.push_back(word);
	
	while (std::next_permutation(word.begin(), word.end()))
	{
		wordVec.push_back(word);
	} 

		
	return wordVec;
}