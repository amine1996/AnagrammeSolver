#include "AnagrammeSolver.h"


void main()
{
	AnagrammeSolver as("wordsEn.txt");
	
	std::string word = "HelloWorld";
	while (std::regex_match(word, std::regex("[a-zA-Z]*")))
	{
		std::cout << "\nEntrez des lettres : ";
		std::cin >> word;
		std::cout << as.solveWithDictionnary(word);
	}
}