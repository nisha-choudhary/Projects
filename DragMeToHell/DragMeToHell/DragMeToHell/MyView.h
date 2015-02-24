/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  MyView.h         DragMetoHell                                              //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS/CSE 651                                               //
//  Assignment No.:  hw3                                                       //
//  Author:          Nisha Choudhary, SUID: 327414511                          //
//                   nchoudha@syr.edu                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#import <UIKit/UIKit.h>
#import "GridClass.h"

@interface MyView : UIView
@property (strong,nonatomic) NSMutableArray *myArray; // NSArray to store grid objec
@property (strong,nonatomic) NSMutableArray *myArray1;
@property (nonatomic, assign) CGFloat dw, dh;  // width and height of cell
@property (nonatomic, assign) CGFloat x, y, x1, y1, x2, y2;    // touch point coordinates
@property (nonatomic, assign) int row, col;    // selected cell in cell grid
@property (nonatomic, assign) BOOL inMotion;   // YES iff in process of dragging
@property (nonatomic, assign) BOOL flag;   // YES iff in process of dragging
@property (nonatomic, strong) NSString *s;     // item to drag around grid
@property (nonatomic,assign) int numberOfTriess;
@property (nonatomic,assign) int count;


-(void) addNewInstance;
-(void) insertAngel;

@end
