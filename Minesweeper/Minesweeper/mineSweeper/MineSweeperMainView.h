/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
// MineSweeperMainView.m-     MineSweeper                                      //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS/ CSE 651                                              //
//  MAP Project                                                                //
//  Author:          Nisha Choudhary, nchoudha@syr.edu                         //
//                   SUID: 327414511                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#import <UIKit/UIKit.h>
#import "grid.h"

//------------------------------------------------------------------------------
// macro for number of mines
//------------------------------------------------------------------------------
#define NUMBEROFMINES 44

//------------------------------------------------------------------------------
// Defining Mine Sweeper UIView interface
//------------------------------------------------------------------------------
@interface MineSweeperMainView : UIView
{
@private
   int row, col;
    CGFloat dw, dh; // width and height of cell
    bool gameOver;  // to check game over
    int placedMineCount; // to count number of mine placed
    int totalScoretobecounted; // to check total score to be counted
}
@property (nonatomic, assign) CGFloat x, y; // touch point coordinates
@property (strong,nonatomic) NSMutableArray *myArray; // NSArray to store grid object
@property (nonatomic, assign) int row; // selected cell in cell grid
@property (nonatomic, assign) int col;
@property (nonatomic, assign) CGFloat dw;
@property (nonatomic, assign) CGFloat dh;
-(void)resetGame; // starts a new game, resets score
-(void) placeMines;
-(void) mineNumbersCount;
-(void) addNewInstance;
-(void) recursivelyOpen:(grid *) gridPoint;

@end
