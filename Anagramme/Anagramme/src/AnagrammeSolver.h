#include <stdio.h>
#include <unordered_map>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <regex>
#include <vector>

class AnagrammeSolver
{
	private:
		std::string fileName;
		std::unordered_multimap<std::string, std::string> dictionnary;
		void fillMap();

	public:
		AnagrammeSolver(std::string pFileName);
		std::vector<std::string> solveWithDictionnary(std::string pWord);
		std::vector<std::string> solveWithoutDictionnary(std::string pWord);
};

