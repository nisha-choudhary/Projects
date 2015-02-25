/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  grid.m-     MineSweeper                                                    //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS/ CSE 651                                              //
//  MAP Project                                                                //
//  Author:          Nisha Choudhary, nchoudha@syr.edu                         //
//                   SUID: 327414511                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#import "grid.h"

//------------------------------------------------------------------------------
// grid implementation
//------------------------------------------------------------------------------

@implementation grid

@synthesize mineNumbers,mine,rowValue,colValue,opened,flag,visited;

//------------------------------------------------------------------------------
// grid init
//------------------------------------------------------------------------------
-(id) init
{
    self = [super init];
    mineNumbers = 0;
    mine = false;
    opened = false;
    flag = false;
    visited =false;
    return self;
}

@end
