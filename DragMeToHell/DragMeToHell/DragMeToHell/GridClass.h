/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GridClass.h      DragMetoHell                                              //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS/CSE 651                                               //
//  Assignment No.:  hw3                                                       //
//  Author:          Nisha Choudhary, SUID: 327414511                          //
//                   nchoudha@syr.edu                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


#import <Foundation/Foundation.h>
//------------------------------------------------------------------------------
// Defining interface grid which holds value for per cell of minesweeper
//------------------------------------------------------------------------------
@interface GridClas : NSObject

@property (nonatomic,readwrite) int rowValue; // store row Value
@property (nonatomic,readwrite) int colValue; // store col Value
@property (nonatomic,readwrite) int angel_count; // store angelcount
@property (nonatomic,readwrite) int kValue; // to get index of an array
@property (nonatomic,readwrite) int numberofTries; //
@property (nonatomic,readwrite) bool opened; // to check cell is open or not
@property (nonatomic,readwrite) bool angel; // to check if angel is present or not
@property (nonatomic,readwrite) bool visited; // to check grid has been visited
@property (nonatomic,readwrite) bool flag; // to check flag is set or not
-(id) init;

@end
