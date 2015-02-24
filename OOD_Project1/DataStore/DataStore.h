#ifndef DATASTORE_H
#define DATASTORE_H

/////////////////////////////////////////////////////////////////////
//																   //
//  DataStore.h   Stores Catalog Data in map and set			   //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Source:		   Dr Jim Fawcett                                  //
//  Author:		   Nisha Choudhary, nchoudha@syr.edu               //
//																   //
/////////////////////////////////////////////////////////////////////

/*
Module Operations:
==================
This module connects to the Catalog class and stores data in map and set.

Public Interface:
=================
void insertNewPath(const std::string& filename, const std::string& path); //saving file and path ref in map Store
//Start and end the store for path
iterator begin(){ return store.begin(); }
iterator end(){ return store.end(); }
//Start and end the mapstore
setIterator beginPath(){ return pathStore.begin(); }
setIterator endPath(){ return pathStore.end(); }
using vecofObjects = std::vector < DisplayObject >; //vector of SpecificProjectDisplay class
vecofObjects Display();//display datastore by vector of SpecificProjectDisplay class

Build Process:
==============
Required files
- DataStore.h, DataStore.cpp ,SpecificProjectDisplay.h
Build commands
- devenv DataStore.vcxproj

Maintenance History:
====================
ver 1.0 : 9 Feb 2015
- first release
*/
#include<vector>
#include<map>
#include<list>
#include<set>
#include<iostream>
#include <string>
#include "DisplayObject.h"

class DataStore{
public:
	using setIterator = std::set<std::string>::iterator;
	using iterator = std::map<std::string, std::list<setIterator>>::iterator;
	using listIterator = std::list<setIterator>;
	using file = std::string;
	using patterns = std::vector<std::string>;
	using vecofObjects = std::vector < DisplayObject > ;
	
	vecofObjects Display();

	bool isPathExisting(const std::string& path);
	bool isFileExisting(const std::string& filename);
	void insertNewPath(const std::string& filename, const std::string& path);
	void insertFileName(const std::string& filename, const std::string& path);
	void DataStoreExecution(const std::string& filename, const std::string& path);
	void FindingDuplicateFiles();
	void callSearchForText( std::string word);
	void searchForText(std::string path, std::string word);
	void numberofFilesandDirectories();
	int DataStore::DataStoreSize();

	iterator begin(){ return store.begin(); }
	iterator end(){ return store.end(); }
	setIterator beginPath(){ return pathStore.begin(); }
	setIterator endPath(){ return pathStore.end(); }
private:
	setIterator DataStore::getReference(const std::string& path);
	std::set<std::string> pathStore;
	std::map<std::string, std::list<setIterator>> store;
};
#endif