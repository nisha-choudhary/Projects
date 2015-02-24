/////////////////////////////////////////////////////////////////////
//																   //
//  DataStore.cpp  Stores Catalog Data in map and set			   //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Source:		   Dr Jim Fawcett                                  //
//  Author:		   Nisha Choudhary, nchoudha@syr.edu               //
//																   //
/////////////////////////////////////////////////////////////////////

#include "DataStore.h"
#include <iostream>
#include <fstream>
using namespace std;

//------< Checks if a path is existing or not >--------------------
bool DataStore :: isPathExisting(const std::string& path)
{
	std::set<std::string>::iterator setit;
	for (setit = pathStore.begin(); setit != pathStore.end(); ++setit){
		if (*setit == path){
			return true;
		}
	}
	return false;
}

//------< Checks if a file  is existing or not >--------------------
bool DataStore :: isFileExisting(const std::string& filename)
{
	std::map<std::string, std::list<setIterator>>::iterator mapIt;
	for (mapIt = store.begin(); mapIt != store.end(); ++mapIt){
		if (mapIt->first == filename){
			return true;
		}
	}
	return false;
}

DataStore::setIterator DataStore :: getReference(const std::string& path){

	std::set<std::string>::iterator setItr;
	for (setItr = pathStore.begin(); setItr != pathStore.end(); ++setItr){
		if (*setItr == path){
			return setItr;
		}
	}
	return setItr;
}

void DataStore :: DataStoreExecution(const std::string& filename, const std::string& path)
{
	if (!isPathExisting(path)){
		pathStore.insert(path);
	}
	insertNewPath(filename, path);
	insertFileName(filename, path);
}

//------< Insertion of path into the DataStore >----------------------------------------

void DataStore :: insertNewPath(const std::string& filename, const std::string& path)
{
	// ----< if a new path is encountered >-----------------------
	if (!isPathExisting(path))
	{
		std::set<std::string>::iterator setit;
		for (setit = pathStore.begin(); setit != pathStore.end(); ++setit){
			if (*setit == path){
				std::list<setIterator> tempRef;
				tempRef.push_back(setit);
				store.insert(std::pair<file, std::list<setIterator>>(filename, tempRef));
			}
		}
	}
}

//------< Insertion of FileNames into the DataStore >----------------------------------------

void DataStore :: insertFileName(const std::string& filename, const std::string& path)
{
	//------< If a new file is encountered >------------------------------------------

	if (!isFileExisting(filename))
	{

		setIterator pathRef = getReference(path); //returns pointer
		std::list<setIterator> tmpList;
		tmpList.push_back(pathRef);
		store.emplace(filename, tmpList);
	}

	//------< If a pre existing file is encountered >------------------------------------
	else
	{
		setIterator pathRef = getReference(path); //returns pointer
		std::map<std::string, std::list<setIterator>>::iterator mapItr;

		for (mapItr = store.begin(); mapItr != store.end(); ++mapItr){
			if (mapItr->first == filename){
				std::list<setIterator> tempRef;
				tempRef = mapItr->second;
				store.erase(filename);
				tempRef.push_front(pathRef);
				store.emplace(filename, tempRef);
				break;
			}
		}
	}
}

DataStore::vecofObjects DataStore :: Display()
{
	std::map<std::string, std::list<setIterator>>::iterator mapItr;
	std::string filesandpaths_ = "";
	std::string paths="";
	DataStore::vecofObjects vector1;
	DisplayObject obj;
	for (mapItr = store.begin(); mapItr != store.end(); ++mapItr)
	{
		std::string fileName = mapItr->first;
		filesandpaths_ = "\n Filename: ";
		filesandpaths_ = filesandpaths_ + mapItr->first;

		//----< Printing list of references >-----
		std::list<setIterator> tempRef = mapItr->second;
		std::list<setIterator>::iterator listItr;
		filesandpaths_ = filesandpaths_ + "\n Is Located at:";
		for (listItr = tempRef.begin(); listItr != tempRef.end(); ++listItr){
			filesandpaths_ = filesandpaths_ + "\n Path: " + *(*listItr);
		}
		obj.filesandpaths_ = filesandpaths_;
		vector1.push_back(obj);
		filesandpaths_ = "";
	}
	return vector1;
}

int DataStore::DataStoreSize(){
	return store.size();
}


#ifdef TEST_DATASTORE

int main(){
	std::cout << "\n Testing Datastore";
	std::cout << "\n";

	DataStore ds;
	std::cout << "\nSaving File one.txt in C:/TextDir ";
	std::cout << "\nSaving File one.txt in E:/CppFiles ";
	std::cout << "\nSaving File two.h in D:/HeaderFileDir/HeaderFiles ";
	std::cout << "\nSaving File three.cppt in E:/CppFiles ";
	std::cout << "\nSaving File two.h in C:/TextDir ";
	std::cout << "\nSaving File two.h in E:/CppFiles \n";

	ds.insertNewPath("one.txt", "C:/TextDir");
	ds.insertNewPath("one.txt", "E:/CppFiles");
	ds.insertNewPath("two.h", "D:/HeaderFileDir/HeaderFiles");
	ds.insertNewPath("three.cpp", "E:/CppFiles");
	ds.insertNewPath("two.h", "C:/TextDir");
	ds.insertNewPath("two.h", "E:/CppFiles");


	
}
#endif