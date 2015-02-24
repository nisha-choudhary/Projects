#ifndef DISPLAY_H
#define DISPLAY_H
/////////////////////////////////////////////////////////////////////
//																   //
//  Display.h	   Displays final output						   //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Source:		   Dr Jim Fawcett                                  //
//  Author:		   Nisha Choudhary, nchoudha@syr.edu               //
//																   //
/////////////////////////////////////////////////////////////////////

/*
Module Operations:
==================
This modules is required to display results.

Public Interface:
=================
using vecofObjects = std::vector <DisplayObject>; //creating vector to access SpecificProjectDisplay Class
void void findingDuplicates(vecofObjects obj);//printing duplicate files 
void numberofFilesandDirectories(vecofObjects obj);// printing number of files and directories
void displayTextSearchFiles(vecofObjects obj); //printing the files found during text search
void printFilesFoundOutput(DisplayObject fileDisplay); //printing all files found

Build Process:
==============
Required files
- DataStore.h, DataStore.cpp ,SpecificProjectDisplay.h
Build commands
- devenv DataStore.vcxproj

Maintenance History:
====================
ver 1.0 : 8 Feb 2015
- first release
*/
#include<vector>
#include<iostream>
#include "../DataStore/DisplayObject.h"

class Display{
public:
	using vecofObjects = std::vector <DisplayObject>;
	
	void numberofFilesandDirectories(vecofObjects obj);
	void findingDuplicates(vecofObjects obj);
	void DisplayAllFilesandPaths(vecofObjects obj);
	void displayTextSearchFiles(vecofObjects obj);
	void printFilesFoundOutput(DisplayObject fileDisplay);
		
};
#endif
