/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ViewController.m-     MineSweeper                                          //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS/ CSE 651                                              //
//  MAP Project                                                                //
//  Author:          Nisha Choudhary, nchoudha@syr.edu                         //
//                   SUID: 327414511                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#import "ViewController.h"
#import "MineSweeperMainView.h"
#import "grid.h"

@interface ViewController ()
@property (strong,nonatomic) IBOutlet MineSweeperMainView *mainView;
@end

//------------------------------------------------------------------------------
// View Controller implenetation
//------------------------------------------------------------------------------
@implementation ViewController
@synthesize mainView;

//------------------------------------------------------------------------------
// view Did load call
//------------------------------------------------------------------------------
- (void)viewDidLoad
{
    [super viewDidLoad];
    //setting backgroundcolor
    [self.mainView setBackgroundColor: [UIColor grayColor]];
    // calling to inisiate objects and do initialization for that
    [mainView addNewInstance];
    
}

//------------------------------------------------------------------------------
// Dispose of any resources that can be recreated.
//------------------------------------------------------------------------------
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

@end
