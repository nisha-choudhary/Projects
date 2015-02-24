#ifndef DISPLAYOBJECT_H
#define DISPLAYOBJECT_H

/////////////////////////////////////////////////////////////////////
//																   //
//  DisplayObject.h Helps in creating vectors for output display   //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Source:		   Dr Jim Fawcett                                  //
//  Author:		   Nisha Choudhary, nchoudha@syr.edu               //
//																   //
/////////////////////////////////////////////////////////////////////

#include <string>
#include <sstream>
#include <map>

class DisplayObject
{
public:
	using file = std::string;
	using path = std::string;
	file file_;
	path path_;
	int numOfFiles;
	int numOfDirectories;
	using map = std::multimap < file, path >;
	using mapItr = std::multimap< file, path>::iterator;
	map map_;

	std :: string duplicateFileandPaths;
	std::string filesandpaths_;

	std::string DisplayAllFilesandPaths()
	{
		std::ostringstream temp;
		temp << filesandpaths_;
		return temp.str();
	}

	std::string showduplicateFileandPaths()
	{

		std::ostringstream temp;
		temp << duplicateFileandPaths;
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
		temp << "N= ";
		temp << numOfFiles;
		temp << " Number of files found in M= ";
		temp << numOfDirectories;
		temp << " directories";
		return temp.str();
	}

};
#endif