/////////////////////////////////////////////////////////////////////
//																   //
//  Display.h	   Displays final output						   //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Source:		   Dr Jim Fawcett                                  //
//  Author:		   Nisha Choudhary, nchoudha@syr.edu               //
//																   //
/////////////////////////////////////////////////////////////////////



#include "Display.h"
#include <iomanip>

//------< Prints all numbers of files and directories >--------------------
void Display :: numberofFilesandDirectories(vecofObjects obj){
	std::cout <<"\n\n ------< Printing Numbers of Files and Directories: >------ \n";
	if (!obj.size()){
		std::cout << "\n No Files Found! " << std::endl;
	}
	for (auto displayItr : obj){

		std::cout << "\n" << displayItr.NumberOfFilesAndDirectories();
	}
	std::cout << "\n\n";
}

//------< Prints all the duplicate files found  >--------------------
void Display :: findingDuplicates(vecofObjects obj)
{
	std::cout << "\n\n ------< Printing Duplicate Filenames and Path names: >------";
	if (!obj.size()){
		std::cout << "\n No Duplicate Filenames Found!  " << std::endl;
	}
	for (auto displayItr : obj){
		std::cout << "\n" << displayItr.showduplicateFileandPaths();
	}
	std::cout << "\n\n";
}

//------< Prints all the files and their paths  >--------------------
void Display :: DisplayAllFilesandPaths(vecofObjects obj)
{
	std::cout<< "\n\n------< Displaying Map containing All File names and Path : >-------- \n";
	if (!obj.size()){
		std::cout << "\n No Files Found!  " << std::endl;
	}
	for (auto displayItr : obj){

		std::cout << "\n" << displayItr.DisplayAllFilesandPaths();
	}
	std::cout << "\n\n";

}

//------< Prints all files with the text searched  >--------------------
void Display::displayTextSearchFiles(vecofObjects obj)
{
	std::cout << "\n\n------< Displaying All Files with the Searched Text : >-------- \n";
	if (!obj.size()){
		std::cout << "\n Text Not Found!  " << std::endl;
	}
	for (auto fileDisplay : obj){
		printFilesFoundOutput(fileDisplay);
	}
}

//------< Prints all file names  >--------------------
void Display::printFilesFoundOutput(DisplayObject fileDisplay)
{
	std::cout <<"\n"<< fileDisplay.showFiles();
}

#ifdef TEST_DISPLAY
#include "../FileMgr/FileMgr.h"
#include "../Display/Display.h"
#include "../Cataloger/Cataloger.h"
#include "../DataStore/DisplayObject.h"

int main(int argc, char *argv [])
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
		vecofObjects obj= fm.DisplayStore();
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
				std::cout<<"\nPlease enter in this format: \"INPUTTEXT\"patterns" << std::endl;
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
		std::cout << ex.what()<<"\n\n";
	}
}
#endif