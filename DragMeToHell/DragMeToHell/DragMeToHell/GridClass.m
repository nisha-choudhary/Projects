/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GridClass.m      DragMetoHell                                              //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS/CSE 651                                               //
//  Assignment No.:  hw3                                                       //
//  Author:          Nisha Choudhary, SUID: 327414511                          //
//                   nchoudha@syr.edu                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#import "GridClass.h"

//------------------------------------------------------------------------------
// grid implementation
//------------------------------------------------------------------------------

@implementation GridClas

@synthesize angel,rowValue,colValue,opened,flag,visited, numberofTries, angel_count;

//------------------------------------------------------------------------------
// grid init
//------------------------------------------------------------------------------
-(id) init
{
    self = [super init];
    numberofTries=0;
    angel_count=0;
    angel = false;
    opened = false;
    flag = false;
    visited =false;
    return self;
}

@end
