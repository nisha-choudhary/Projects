#ifndef CATALOGER_H
#define CATALOGER_H
/////////////////////////////////////////////////////////////////////
//																   //
//  Cataloger.h    Calls FileMgr and DataStore				 	   //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Source:		   Dr Jim Fawcett                                  //
//  Author:		   Nisha Choudhary, nchoudha@syr.edu               //
//																   //
/////////////////////////////////////////////////////////////////////

/*
Module Operations:
==================
This module defines a class that can build catalogue datastore.

Public Interface:
=================
using vecofObjects = std::vector <DisplayObject>;//creating vector to connect to SpecificProjectDisplay class
vecofObjects searchInputText(vectorStore& patterns_, std::string searchText);//Printing the map in datastore
vecofObjects numberofFilesandDirectories();//printing number of files and directories
vecofObjects FindingDuplicateFiles();//printing duplicate files and directories
displayVec textSearch();//searching for text specified
vecofObjects textSearch();// accepting and searching for text from user in files and paths

Build Process:
==============
Required files
FileSystem.h, FileSystem.cpp , FileMgr.h, FileMgr.cpp, DisplayObject.h
Build commands
- devenv FileMgr.vcxproj
Maintenance History:
===================
- first release
*/

#include "../DataStore/DataStore.h"
#include "../FileSystem/FileSystem.h"
#include "../FileMgr/FileMgr.h"
#include "../DataStore/DisplayObject.h"
#include <iostream>
#include <vector>

class Cataloger
{
public:

	using path = std::string;
	using iterator = std::vector<std::string>::iterator;
	using setIterator = std::set<std::string>::iterator;
	using pathItr = std::set <std::string > ::iterator;
	using pathList = std::list < pathItr >;
	using pathListIterator = std::list < pathItr >::iterator;
	using pathIterator = std::set<path>::iterator;
	using pathRef = std::list < pathIterator >;
	using pathRefIterator = std::list<pathIterator>::iterator;
	using listIterator = std::list<setIterator>;
	using file = std::string;
	using patterns = std::vector<std::string>;
	using vectorStore = std::vector < std::string >;
	using vecofObjects = std::vector <DisplayObject>;

	Cataloger(FileMgr& fm);
	
	
	bool isFileExisting(const std::string& filename);
	bool FileSearch(vectorStore& patterns_);
	bool filePreExists(std::string filename, std::string pattern);

	
	vecofObjects searchInputText(vectorStore& patterns_, std::string searchText);
	vecofObjects numberofFilesandDirectories();
	vecofObjects FindingDuplicateFiles();
	vecofObjects textSearch();


private:
	FileMgr& fileMgr_;
	std::map <std::string, std::string> files_;
	setIterator getReference(const std::string& path);
	std::vector<std::string> store1;
	std::set<std::string> pathStore;
	std::map<std::string, std::list<setIterator>> store;
	bool textSearch(const std::string& filename, const std::string& filePath, const std::string searchtext);
};

#endif
