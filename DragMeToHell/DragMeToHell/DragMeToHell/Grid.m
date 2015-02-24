
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  grid.m-     MineSweeper                                                    //
//              Source file containing Grid Implementation.                    //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS-651                                                   //
//  Assignment No.:  hw3,part2                                                 //
//  Author:          Ankur Pandey, SUID: 408067486 , Syracuse University       //
//                   (315)572-2879, apandey@syr.edu                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#import "Grid.h"

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
