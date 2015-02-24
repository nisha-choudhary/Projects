#ifndef FILEMGR_H
#define FILEMGR_H

#include <vector>

class FileManager{
public:
	using patterns = std::vector < std::string > ;

	void parsingCommands(int argCount, char* argValues[]);
	void search();
	void FileManager::find(std::string path, std::string pattern, bool isRecursive);

private:

	bool isRecursive;
	bool isDuplicatefile;
	bool isNofFilesinMdirDisplay;
	std::string searchText;
	std::string path_;
	patterns pattern_;


};
#endif