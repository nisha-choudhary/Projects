/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  AppDelegate.m    DragMetoHell                                              //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS/CSE 651                                               //
//  Assignment No.:  hw3                                                       //
//  Author:          Nisha Choudhary, SUID: 327414511                          //
//                   nchoudha@syr.edu                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


#import "DMTHAppDelegate.h"
#import "DMTHViewController.h"

@implementation DMTHAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    self.viewController = [[DMTHViewController alloc] initWithNibName:@"DMTHViewController" bundle:nil];
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    return YES;
}

@end
