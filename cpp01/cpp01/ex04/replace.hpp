#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class Replace {
	private:
		std::string _inFile;
		std::string _outFile;
	public:
		Replace(std::string filename);
		~Replace();

		void	replace(std::string s1, std::string s2); 
};

#endif