/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  grid.h-     MineSweeper                                                    //
//              Source file containing Grid Interface.                         //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS-651                                                   //
//  Assignment No.:  hw3,part2                                                 //
//  Author:          Ankur Pandey, SUID: 408067486 , Syracuse University       //
//                   (315)572-2879, apandey@syr.edu                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


#import <Foundation/Foundation.h>
//------------------------------------------------------------------------------
// Defining interface grid which holds value for per cell of minesweeper
//------------------------------------------------------------------------------
@interface Grid : NSObject

@property (nonatomic,readwrite) int rowValue; // store row Value
@property (nonatomic,readwrite) int colValue; // store col Value
@property (nonatomic,readwrite) int kValue; // to get index of an array
@property (nonatomic,readwrite) bool opened; // to check cell is open or not
@property (nonatomic,readwrite) bool mine; // to check mine is present or not
@property (nonatomic,readwrite) bool visited; // to check grid has been visited
@property (nonatomic,readwrite) int mineNumbers; //counting surrounding minenumber
@property (nonatomic,readwrite) bool flag; // to check flag is set or not
-(id) init;

@end
