/////////////////////////////////////////////////////////////////////
//																   //
//  Executive.cpp  Calls FileMgr, Cataloger & Display			   //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Source:		   Dr Jim Fawcett                                  //
//  Author:		   Nisha Choudhary, nchoudha@syr.edu               //
//																   //
/////////////////////////////////////////////////////////////////////


#include "../FileMgr/FileMgr.h"
#include "../Display/Display.h"
#include "../Cataloger/Cataloger.h"
#include "../DataStore/DisplayObject.h"
#include <algorithm>

#ifdef TEST_EXECUTIVE
int main(int argc, char *argv [])
{
	try{

		std::cout << "\n Testing Executive Package::";
		std::cout << "\n" << std::string(75, '*');
		std::cout << "\n";

		std::cout << "\nParsing Command line arguments: " << std::endl;
		//----< Parsing the command line >--------------------
		//int argc = 7;
		//char *argv[] = { "C:\\jimFawcett", "*.cpp", "*.h", "*.txt", "/s", "/d", "/f<main>" };
		FileMgr fm;
		fm.parseCmdLine(argc, argv);

		//----< Searching for files and directories >--------------------
		fm.search();
		//int argc = 7;

		Cataloger Ctg(fm);
		using vecofObjects = std::vector <DisplayObject>;
		Display disp;
		std::string condition;
		
		
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