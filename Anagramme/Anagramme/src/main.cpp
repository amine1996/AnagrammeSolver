#include "AnagrammeSolver.h"


void printVector(std::vector<std::string> vec)
{
	for (int i = 0; i < vec.size(); i++)
		std::cout << "\t\t" << vec.at(i) << std::endl;
}

void main()
{
	AnagrammeSolver as("wordsEn.txt");
	
	std::string word = "HelloWorld";
	while (std::regex_match(word, std::regex("[a-zA-Z]*")))
	{
		std::cout << "\nEnter random letters : ";
		std::cin >> word;
		std::cout << "From dictionnary : " << std::endl;
		printVector(as.solveWithDictionnary(word));
		std::cout << "All permutations : " << std::endl;
		printVector(as.solveWithoutDictionnary(word));
	}
}

