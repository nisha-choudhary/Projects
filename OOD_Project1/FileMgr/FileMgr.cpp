/////////////////////////////////////////////////////////////////////
//																   //
//  FileMgr.cpp    Calls DataStore and FileSystem				   //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Source:		   Dr Jim Fawcett                                  //
//  Author:		   Nisha Choudhary, nchoudha@syr.edu               //
//																   //
/////////////////////////////////////////////////////////////////////

#include "FileMgr.h"
#include <iostream>
#include <sstream>

//----< File Manager Default Constructor >---------------------------------//
FileMgr::FileMgr()
{
	isSearchRecursively = false;
	hasDuplicates = false;
	textSearch = false;
	patterns_.push_back("*.*");
}

//----< Finding all patterns and adding to vector >---------------------------------//
void FileMgr::addPattern(const std::string& patt){
	if (patterns_.size() == 1 && patterns_[0] == "*.*"){
		patterns_.pop_back();
		patterns_.push_back(patt);
	}
	else
	{
		patterns_.push_back(patt);
	}
}

//----< Finds for all files >---------------------------------//
void FileMgr::find(const std::string& path){
	for (auto patt : patterns_){
		searchFiles(path, patt, isSearchRecursively);
	}
}

//----< Finds file based on path >---------------------------------//
void FileMgr::search(){
	find(path_);
}


// ----< Parses User command line arguments>--------------------------
bool FileMgr :: parseUserCommand(std::string parseSearchText){
	inputforTextSearch = parseSearchText;
	hasDuplicates = false;
	numberofFilesandDirectories = false;
	textSearch = false;
	patterns_.clear();
	searchforText = "";
	bool getfirst = true;
	if (parseSearchText[0] != '\"'){
		return false;
	}
	std::size_t found = parseSearchText.find_first_of("\"");
	if (found == std::string::npos){
		return false;
	}
	std::size_t first = parseSearchText.find("\"");
	std::size_t last = parseSearchText.find_last_of("\"");
	if (last == std::string::npos || (first == 0 && last == 0)){
		return false;
	}
	searchforText = parseSearchText.substr(first + 1, last - (first + 1));
	if (searchforText.size() == 0){
		return false;
	}
	textSearch = true;
	last++;
	patterns_.push_back("*.*");
	userInputCommand(parseSearchText, last);
	return true;
}

// ----< user Input Command stoing pattern >------------------------------------------
void FileMgr::userInputCommand(std::string parseSearchText, int last){
	while (parseSearchText[last] != '\0'){
		std::string tmpWord = "";
		while (parseSearchText[last] != ' ' && parseSearchText[last] != '\0'){
			tmpWord += parseSearchText[last];
			last++;
		}
		if (tmpWord != ""){
			if (patterns_.size() == 1 && patterns_[0] == "*.*"){
				patterns_.pop_back();
				patterns_.push_back(tmpWord);
			}
			else{
				patterns_.push_back(tmpWord);
			}
		}
		last++;
	}
}

// ----< Return Command Input >---------------------------------------------------
std::string FileMgr :: getUserInputString(){
	return inputforTextSearch;
}


//----< Parses command line arguments>--------------------------------
void FileMgr::parseCmdLine(int argc, char* argv[])
{
	inputforTextSearch = "";
	bool fdpresent = true;

	for (int i = 1; i < argc; i++){
		std::string checkArg = argv[i];
		inputforTextSearch += checkArg;
		inputforTextSearch += " ";
		std::size_t found = checkArg.find("/f");

		if (checkArg == "/s" || checkArg == "/S"){
			isSearchRecursively = true;
		}
		else if (checkArg == "/d" || checkArg == "/D"){
			fdpresent = false;
			hasDuplicates = true;
		}
		else if (found != std::string::npos){
			textSearch = true;
			fdpresent = false;
			int start = checkArg.find_first_of("\"");
			int end = checkArg.find_last_of("\"");
			searchforText = checkArg.substr(start + 3, end - (start + 1));
			continue;
		}
		else if (path_.empty()){
			path_ = FileSystem::Path::getFullFileSpec(argv[i]);
		}
		else{
			addPattern(checkArg);
		}
	}

	defaultCondition(fdpresent);
}

//----< Checks for default conditions>--------------------------------
void FileMgr :: defaultCondition(bool fdpresent)
{
	if (patterns_.empty()){
		patterns_.push_back("*.*"); // default pattern
	}
	if (path_.empty()){
		path_ = FileSystem::Path::getFullFileSpec(".");  // default path
	}
	if (fdpresent){
		numberofFilesandDirectories = true;
	}
}

//----< Checks if recursive search is required >--------------------------------
bool FileMgr::func_isSearchRecursively()
{
	return isSearchRecursively;
}

//----< Checks if finding duplicates is required >--------------------------------
bool FileMgr::func_hasDuplicates()
{
	return hasDuplicates;
}

//----< Checks if Searching for a text is required >--------------------------------
bool FileMgr::func_textSearch()
{
	//textSearch = true;
	return textSearch;
}

FileMgr::vectorStore FileMgr::getPatterns(){
	return patterns_;
}

std::string FileMgr::getSearchtext(){
	return searchforText;
}
//----< Lists the file recursively, if listRecursively is true >--------------------------------
void FileMgr :: searchFiles(std::string path, std::string pattern, bool listRecursively)
{
	std::vector<std::string> tmpFiles = FileSystem::Directory::getFiles(path, pattern);
	for (auto tmpFile : tmpFiles){
		std::string filePath = FileSystem::Path::fileSpec(path, tmpFile);
		std::string fullPathwithFile = FileSystem::Path::getFullFileSpec(filePath);
		std::string fullPath = FileSystem::Path::getPath(fullPathwithFile);
		store_.DataStoreExecution(tmpFile, fullPath);
	}

	if (listRecursively){
		std::vector<std::string> dirs = FileSystem::Directory::getDirectories(path);
		for (auto dir : dirs){
			if (dir == "." || dir == ".."){
				continue;
			}
			std::string dirPath = FileSystem::Path::fileSpec(path, dir);
			searchFiles(dirPath, pattern, listRecursively);
		}
	}

}

FileMgr::vecofObjects FileMgr::DisplayStore()
{
	return store_.Display();
}


bool FileMgr::func_numberofFilesandDirectories()
{
	return numberofFilesandDirectories;
}

//-----< Returns DataStore Reference >-----------------------------
DataStore& FileMgr::getDSRef(){
	return store_;
}

int  FileMgr::dataStoreSize(){
	return store_.DataStoreSize();
}


#ifdef TEST_FILEMGR
//----< Calling FileMgr Main >----------------------------------------------------------------
int main(int argc, char* argv[]){

	try{
		
		FileMgr fm;
		std::cout << "\n\nShowing Default Case:: ";
		std::cout << "\n****************************************** ";
		std::string path = ".";
		bool isSearchRecursively = false;
		std::vector< std::string> patterns_;
		patterns_.push_back("*.*");
		std::cout << "\n Searching for files and building Datastore:" << std::endl;
		fm.search();
		std::cout << "Showing FileStore with respected PathsRefernce in DataStoreMAP \n";
		std::vector< DisplayObject> dataStoreVec = fm.DisplayStore();
		for (auto dataStoreVecItr : dataStoreVec){
			std::cout << "\n" << dataStoreVecItr.DisplayAllFilesandPaths();
		}

		std::cout << "\nShowing Default And Recursive Case:: ";
		std::cout << "\n****************************************** ";
		path = ".";
		isSearchRecursively = true;
		patterns_.clear();
		patterns_.push_back("*.*");
		std::cout << "\nSearching for files and building Datastore:" << std::endl;
		fm.search();
		std::cout << "Showing FileStore with respected PathsRefernce in DataStoreMAP \n";
		dataStoreVec = fm.DisplayStore();
		for (auto dataStoreVecItr : dataStoreVec){
			std::cout << "\n" << dataStoreVecItr.DisplayAllFilesandPaths();
		}

		std::cout << "\nShowing All Cases:: ";
		std::cout << "\n****************************************** ";
		path = "D:/test";
		isSearchRecursively = true;
		patterns_.clear();
		patterns_.push_back("*.h");
		patterns_.push_back("*.txt");
		patterns_.push_back("*.cpp");
		std::cout << "\nSearching for files and building Datastore:" << std::endl;
		fm.search();
		std::cout << "Showing FileStore with respected PathsRefernce in DataStoreMAP \n";
		dataStoreVec = fm.DisplayStore();
		for (auto dataStoreVecItr : dataStoreVec){
			std::cout << "\n" << dataStoreVecItr.DisplayAllFilesandPaths();
		}
		
	}
	catch (std::exception& ex){
		std::cout << "\n\n    " << ex.what() << "\n\n";
	}
	return 0;

}
#endif