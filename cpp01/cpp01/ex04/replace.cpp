#include "replace.hpp"

Replace::Replace(std::string filename) : _inFile(filename) {
	this->_outFile = filename + ".replace";
}

Replace::~Replace() {
}

void	Replace::replace(std::string to_replace, std::string replace_with) {
	std::ifstream ifs(this->_inFile.c_str());
	if (ifs.is_open()) {
		std::string contents;
		if (std::getline(ifs, contents, '\0')) {
			std::ofstream ofs(this->_outFile.c_str());
			size_t pos = contents.find(to_replace);
			while (pos != std::string::npos) {
				contents.erase(pos, to_replace.length());
				contents.insert(pos, replace_with);
				pos = contents.find(to_replace);
			}
			ofs << contents;
			ofs.close();
		} else {
			std::cerr << "Empty file, Please try again!" << std::endl;
		}
		ifs.close();
	} else {
		std::cerr << "Unable to open file, Please try again!" << std::endl;
		exit(1);
	}
}