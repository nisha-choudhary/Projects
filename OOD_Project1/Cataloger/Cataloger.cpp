/////////////////////////////////////////////////////////////////////
//																   //
//  Cataloger.cpp  Calls FileMgr and DataStore				 	   //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Source:		   Dr Jim Fawcett                                  //
//  Author:		   Nisha Choudhary, nchoudha@syr.edu               //
//																   //
/////////////////////////////////////////////////////////////////////

#include "Cataloger.h"
#include <iostream>
#include <fstream>
#include <string>


//----< Calls the default constructor >-----------
Cataloger::Cataloger(FileMgr& fm) : fileMgr_(fm){
}

//----< Creates reference for set interators >-----------
Cataloger::setIterator Cataloger::getReference(const std::string& path){

	std::set<std::string>::iterator setItr;
	for (setItr = pathStore.begin(); setItr != pathStore.end(); ++setItr){
		if (*setItr == path){
			return setItr;
		}
	}
	return setItr;
}
//----< Checks if a file is existing or not >-----------
bool Cataloger :: isFileExisting (const std::string& filename)
{
	std::map<std::string, std::list<setIterator>>::iterator mapIt;
	for (mapIt = store.begin(); mapIt != store.end(); ++mapIt){
		if (mapIt->first == filename){
			return true;
		}
	}
	return false;
}

//----< Calculates the total number of files and directories found >-----------
Cataloger::vecofObjects Cataloger :: numberofFilesandDirectories(){
	
	int numberofFiles = 0;
	int numberofDirectories = 0;
	Cataloger::vecofObjects vector1;
	DisplayObject obj;
	std::string vecString="";
	std::string vecString1 = "";
	std::map<std::string, std::list<setIterator>>::iterator mapItr;
	for (mapItr = fileMgr_.getDSRef().begin(); mapItr != fileMgr_.getDSRef().end(); ++mapItr)
	{
		std::list<setIterator> tempRef = mapItr->second;
		std::list<setIterator>::iterator listItr;
		for (listItr = tempRef.begin(); listItr != tempRef.end(); ++listItr){
			numberofFiles++;
		}
	}
	std::set<std::string>::iterator setit;
	for (pathItr pathItr = fileMgr_.getDSRef().beginPath(); pathItr != fileMgr_.getDSRef().endPath(); ++pathItr)
	{
		numberofDirectories++;
	}

	obj.numOfFiles = numberofFiles;
	obj.numOfDirectories = numberofDirectories;
	vector1.push_back(obj);
	return vector1;
}

//------< Searches for duplicate files >----------------------------
Cataloger :: vecofObjects Cataloger :: FindingDuplicateFiles()
{
	int count = 0;
	Cataloger::vecofObjects vector1;
	DisplayObject obj;
	bool duplicate;
	std::string vecString = "";
	std::string vecString1 = "";
	std::map<std::string, std::list<setIterator>>::iterator mapItr;
		for ( mapItr = fileMgr_.getDSRef().begin(); mapItr != fileMgr_.getDSRef().end(); ++mapItr){
			int count = 0;
			duplicate = false;
			std::string filename = mapItr->first;
			pathList list = mapItr->second;
			for (pathListIterator pathlistItr = list.begin(); pathlistItr != list.end(); ++pathlistItr){
				if (count >=1){
					duplicate = true;
					break;
				}
				count++;
			}
			if (duplicate){
				
				vecString = "\n" + filename;

				for (pathListIterator pathlistItr = list.begin(); pathlistItr != list.end(); ++pathlistItr){
					std::string path = *(*pathlistItr);
					vecString1 = vecString1 +" \n "+ path;
				}
				vecString = vecString + " \n " + vecString1;
				obj.duplicateFileandPaths = vecString;
				vector1.push_back(obj);
			}
			vecString = "";
			vecString1 = "";
		}
		
		return vector1;
	
}

//----< Checks if searched files are already present >-----------
bool Cataloger :: FileSearch(vectorStore& patterns_){
	bool isPresent = false;
	for (auto patt : patterns_){
		int number = patt.find("*.*");
		if (number != std::string::npos){
			isPresent = true;
		}
	}
	return isPresent;
}

//----< Checks if a file pre exits >-----------
bool Cataloger :: filePreExists(std::string filename, std::string pattern){
	for (auto mapItr : files_){
		if (mapItr.first == filename && mapItr.second == pattern){
			return true;
		}
	}
	return false;
}

//--------< Searching for input text in file and path provided  >-----------
bool Cataloger::textSearch(const std::string& filename, const std::string& filePath, const std::string searchtext)
{
	std::string line;
	std::string fileSpecification = FileSystem::Path::fileSpec(filePath, filename);
	std::ifstream file1(fileSpecification);
	if (file1.is_open())
	{
		while (getline(file1, line))
		{
			if (std::string::npos != line.find(searchtext) )
				return true;
		}
	}
	return false;
}

//--------< Execution of text search starts here and calls all respective functions  >-----------
Cataloger::vecofObjects Cataloger::searchInputText(vectorStore& patterns_, std::string searchText)
{
	vecofObjects vector1;
	int store_Size = fileMgr_.dataStoreSize();
	int store_Count = 0;
	files_.clear();
	bool isPresent = FileSearch(patterns_);
	std::map<std::string, std::list<setIterator>>::iterator mapItr;
	
	for (mapItr = fileMgr_.getDSRef().begin(); mapItr != fileMgr_.getDSRef().end(); ++mapItr)
	{
		DisplayObject obj;
		std::string filename = mapItr->first;
		bool fileFound = false;
		std::string fe = FileSystem::Path::getExt(filename);

		for (std::vector<std::string>::iterator itr = patterns_.begin(); itr != patterns_.end(); itr++)
		{
			if (isPresent == true || (*itr).find(fe) != std::string::npos)
			{
				if (filePreExists(filename, *itr))
				{
					continue;
				}

				pathRef pathr = mapItr->second;
				pathRefIterator pathRefItr = pathr.begin();
				std::string path = *(*pathRefItr);
				bool fileFound = textSearch(filename, path, searchText);
				if (fileFound){
					obj.file_ = filename;
					vector1.push_back(obj);
					files_.emplace(filename, *itr);
				}
			}
		}
		if ((store_Count < store_Size)){
			store_Count++;
			mapItr = fileMgr_.getDSRef().begin();
		}
	}
	return vector1;
}


#ifdef TEST_CATALOGER

#include "../FileMgr/FileMgr.h"
#include "../Display/Display.h"
#include "../Cataloger/Cataloger.h"
#include "../DataStore/DisplayObject.h"
#include <algorithm>


int main(int argc, char *argv[])
{
	try{

		std::cout << "\n Testing Executive Package::";
		std::cout << "\n" << std::string(75, '*');
		std::cout << "\n";

		std::cout << "\nParsing Command line arguments: " << std::endl;
		int argc = 7;
		char *argv[] = { "C:\\jimFawcett", "*.cpp", "*.h", "*.txt", "/s", "/d", "/f<main>" };
		FileMgr fm;
		Cataloger Ctg(fm);
		using vecofObjects = std::vector <DisplayObject>;
		Display disp;
		std::string condition;

		//----< Parsing the command line >--------------------
		fm.parseCmdLine(argc, argv);

		//----< Searching for files and directories >--------------------
		fm.search();
		vecofObjects obj = fm.DisplayStore();
		disp.DisplayAllFilesandPaths(obj);

		if (fm.func_numberofFilesandDirectories())
		{
			vecofObjects obj1 = Ctg.numberofFilesandDirectories();
			disp.numberofFilesandDirectories(obj1);
		}
		if (fm.func_hasDuplicates())
		{
			vecofObjects obj = Ctg.FindingDuplicateFiles();
			disp.findingDuplicates(obj);
		}
		bool textSearch = false;
		std::string inputforTextSearch;
		if (fm.func_textSearch()){
			textSearch = true;
		}
		do
		{
			std::cout << "\n\n -----< Demonstration of Requirement 8 >----------------" << std::endl;
			std::getline(std::cin, inputforTextSearch);
			bool textSearch = false;
			inputforTextSearch += " ";
			condition = inputforTextSearch;
			if ((condition != " ") && !fm.parseUserCommand(inputforTextSearch)){
				std::cout << "\nInvalid Input!:";
				std::cout << "\nPlease enter in this format: \"INPUTTEXT\"patterns" << std::endl;
			}
			if (fm.func_textSearch())
			{
				vecofObjects obj = Ctg.searchInputText(fm.getPatterns(), fm.getSearchtext());
				disp.displayTextSearchFiles(obj);
			}
		} while (inputforTextSearch != " ");

	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << "\n\n";
	}
}

#endif