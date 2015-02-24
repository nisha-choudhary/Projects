/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ViewController.m DragMetoHell                                              //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS/CSE 651                                               //
//  Assignment No.:  hw3                                                       //
//  Author:          Nisha Choudhary, SUID: 327414511                          //
//                   nchoudha@syr.edu                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#import "DMTHViewController.h"
#import "MyView.h"
#import "GridClass.h"


@interface DMTHViewController ()
@property (strong,nonatomic) IBOutlet MyView *myView;
@end

@implementation DMTHViewController
@synthesize myView;
- (void)viewDidLoad
{
    NSLog( @"viewDidLoad" );
    [super viewDidLoad];
    NSLog( @"viewDidLoad 3 " );

    [self.view setBackgroundColor: [UIColor cyanColor]];
    NSLog( @"viewDidLoad 4 " );

    [myView addNewInstance];
    NSLog( @"viewDidLoad" );


}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

@end
