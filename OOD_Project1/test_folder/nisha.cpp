
/////////////////////////////////////////////////////////////////////
//  Executive.cpp - Makes call to the FileManager, Cataloger and   //
//					Display	classes								   //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2013                                 //
//  Platform:      Dell, Windows 8.1                               //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Author:		   Nupur Bhonge                                    //
/////////////////////////////////////////////////////////////////////

#include "FileManager.h"
#include "../FileSystem/FileSystem.h"
#include <iostream>


void FileManager::search(){
	for (auto patt : pattern_){
		find(path_, patt, isRecursive);
	}
}

void FileManager::find(std::string path, std::string pattern, bool isRecursive){

	std::vector < std::string > filesSearched = FileSystem::Directory::getFiles(path, pattern);
	
	if (isRecursive){
		std::vector < std::string > dirSearched = FileSystem::Directory::getDirectories(path);
		for (auto dir : dirSearched){
			if (dir == "." || dir == ".."){
				continue;
			}
			std::string dirPath = FileSystem::Path::fileSpec(path, dir);
			find(dirPath, pattern, isRecursive);
		}
	}

	for (auto tempFile : filesSearched){
		//std::string filePath = FileSystem::Path::fileSpec(path, tempFile);
		//std::string fullPathwithFile = FileSystem::Path::getFullFileSpec(filePath);
		//std::string fullPath = FileSystem::Path::getPath(fullPathwithFile);
		std::cout << "/nPath   " << path << std::endl;
		std::cout << "/ntmpFile  " << tempFile << std::endl;
		//Datastore_.savingData(tmpFile, fullPath);
	}
}

void FileManager::parsingCommands(int argCount, char* argValues[]){

	bool isNfilesMdirDisplay = false;
	for (int i = 0; i < argCount; i++)
	{
		std::string tempStr = argValues[i];
		std::size_t found = tempStr.find("/f");
		if (found != std::string::npos){
			isNfilesMdirDisplay = true;
			unsigned first = tempStr.find("<");
			unsigned last = tempStr.find(">");
			searchText = tempStr.substr(first + 1, last - (first + 1));
			continue;
		}

		if (tempStr == "/s")
		{
			isRecursive = true;
		}
		else if (tempStr == "/d")
		{
			isNfilesMdirDisplay = true;
			isDuplicatefile = true;
		}
		else if (path_.empty())
		{
			path_ = FileSystem::Path::getFullFileSpec(tempStr);
		}
		else
		{
			pattern_.push_back(tempStr);
		}
	}

	if (isNfilesMdirDisplay){
		isNofFilesinMdirDisplay = true;
	}

	if (path_.empty())
	{
		path_ = FileSystem::Path::getFullFileSpec(".");
	}

	if (pattern_.empty())
	{
		pattern_.push_back("*.*");
	}
}


#ifdef TEST_FILEMGR
int main()
{



}
#endif