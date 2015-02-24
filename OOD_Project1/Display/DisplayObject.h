#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <sstream>
#include <map>

class DisplayObject
{
public:
	using file = std::string;
	using path = std::string;
	using multimapStore = std::multimap < file, path >;
	using multimapStoreIterator = std::multimap< file, path>::iterator;

	file file_;
	path path_;
	multimapStore map_;

	unsigned numOfFiles;
	unsigned numOfDirectories;

	std::string showFileAndPaths()
	{
		std::ostringstream temp;
		temp << "\n File = ";
		temp << file_;
		temp << "\n Path = \n";
		for (multimapStoreIterator pathRefItr = map_.begin(); pathRefItr != map_.end(); ++pathRefItr)
		{
			temp << "       ";
			temp << pathRefItr->second;
			temp << "\n";
		}
		return temp.str();
	}

	std::string showPath(){
		std::ostringstream temp;
		temp << "\n ";
		temp << path_;
		return temp.str();
	}

	std::string showFiles()
	{
		std::ostringstream temp;
		temp << "\n";
		temp << file_;
		return temp.str();
	}

	std::string NumberOfFilesAndDirectories()
	{
		std::ostringstream temp;
		temp << "";
		temp << numOfFiles;
		temp << " files find in ";
		temp << numOfDirectories;
		temp << " directories";
		return temp.str();
	}

};
#endif