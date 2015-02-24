#ifndef FILEMGR_H
#define FILEMGR_H

/////////////////////////////////////////////////////////////////////
//																   //
//  FileMgr.h      Calls DataStore and FileSystem	   			   //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Source:		   Dr Jim Fawcett                                  //
//  Author:		   Nisha Choudhary, nchoudha@syr.edu               //
//																   //
/////////////////////////////////////////////////////////////////////

/*
Module Operations:
==================
This module defines a class that can search files and paths and send to store in DataStore.

Public Interface:
=================
void parsingCommands(int argCount, char* argValues[]); //parsing commands from command line
void search(); //Search begins here
void find(const std::string& path); 
void searchFiles(std::string path, std::string pattern, bool listRecursively); // searches recursively if required
bool func_numberofFilesandDirectories(); // printing number of files in number of directories
bool func_hasDuplicates(); //printing duplicate files
bool func_textSearch(); //searches for the text givven as an input by the user
bool parseUserCommand(std::string parseSearchText); //parses the command line

Build Process:
==============
Required files
- FileSystem.h,FileSystem.cpp, DataStore.h, DataStore.cpp, SpecificProjectDisplay.h
Build commands
- devenv FileMgr.vcxproj
Maintenance History:
===================
- first release
*/

#include "../FileSystem/FileSystem.h"
#include "../DataStore/DataStore.h"
#include "../DataStore/DisplayObject.h"
#include <iostream>
#include <vector>
class FileMgr
{
public:

	FileMgr();
	using iterator = DataStore::iterator;
	using patterns = std::vector<std::string>;
	using vectorStore = std::vector < std::string >;
	using vecofObjects = std::vector <DisplayObject>;
	using patterns = std::vector <std::string>;

	vecofObjects DisplayStore();
	void addPattern(const std::string& patt);
	void search();
	void find(const std::string& path);
	void parseCmdLine(int argc, char* argv[]);
	void defaultCondition(bool fdpresent);
	void userInputCommand(std::string parseSearchText, int last);
	std::string getUserInputString();
	

	bool func_numberofFilesandDirectories();
	bool func_isSearchRecursively();
	bool func_hasDuplicates();
	bool func_textSearch();
	bool parseUserCommand(std::string parseSearchText);
	   
	vectorStore getPatterns();
	std::string getSearchtext();
	int dataStoreSize();
	DataStore& getDSRef();

private:

	bool bShowFuncSizeComplexity;
	bool isSearchRecursively;
	bool hasDuplicates;
	bool textSearch;
	bool numberofFilesandDirectories;
	void searchFiles(std::string path, std::string pattern, bool listRecursively);
	std::string path_;
	std::string inputforTextSearch;
	std::string searchforText;
	DataStore store_;
	patterns patterns_;

};
#endif
