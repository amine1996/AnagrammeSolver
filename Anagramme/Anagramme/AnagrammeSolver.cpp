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
}

std::string AnagrammeSolver::solveWithDictionnary(std::string word)
{
	assert(std::regex_match(word, std::regex("[a-zA-Z]*")));

	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	std::sort(word.begin(), word.end());

	auto range = dictionnary.equal_range(word);
	std::unordered_multimap<std::string, std::string>::iterator it;

	std::string res = "";
	for (it = range.first; it != range.second; it++)
	{
		res += it->second + "\n";
	}
	return res;
}