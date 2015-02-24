/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  MyView.m         DragMetoHell                                              //
//  Language:        Objective-C 2.0                                           //
//  Platform:        Mac OS X                                                  //
//  Course No.:      CIS/CSE 651                                               //
//  Assignment No.:  hw3                                                       //
//  Author:          Nisha Choudhary, SUID: 327414511                          //
//                   nchoudha@syr.edu                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


#import "MyView.h"
#import "DMTHViewController.h"

@interface MyView ()

@end

@implementation MyView

@synthesize dw, dh, row, col, x, y, x1, y1, x2, y2, inMotion, flag, s,myArray,numberOfTriess, count;

- (id)initWithFrame:(CGRect)frame {
    return self = [super initWithFrame:frame];

}

-(void) addNewInstance
{
    NSLog(@" i am here  addnewInsatnce ");

    numberOfTriess = 0;
    myArray=[[NSMutableArray alloc]init];
    GridClas *gridPointer;
    int k=0;
    for(int i=0;i<10 ;i++){
        for( int j =0 ; j < 10 ; j++){
            gridPointer = [[GridClas alloc]init];
            gridPointer.rowValue = i;
            gridPointer.colValue = j;
            gridPointer.kValue = k;
            [myArray addObject:gridPointer];
            k++;
        }
    }
    [self spotAngels];
}


- (void)drawRect:(CGRect)rect 
{
    
    // NSLog( @"drawRect:" );
    
    CGContextRef context = UIGraphicsGetCurrentContext();  // obtain graphics context
    // CGContextScaleCTM( context, 0.5, 0.5 );  // shrink into upper left quadrant
    CGRect bounds = [self bounds];          // get view's location and size
    CGFloat w = CGRectGetWidth( bounds );   // w = width of view (in points)
    CGFloat h = CGRectGetHeight ( bounds ); // h = height of view (in points)
    dw = w/10.0f;                           // dw = width of cell (in points)
    dh = h/10.0f;                           // d`h = height of cell (in points)
    
   // NSLog( @"view (width,height) = (%g,%g)", w, h );
   // NSLog( @"cell (width,height) = (%g,%g)", dw, dh );
    
    // dr/Users/nishachoudhary/Downloads/DragMeToHell/DragMeToHell/main.maw lines to form a 10x10 cell grid
    CGContextBeginPath( context );               // begin collecting drawing operations
    for ( int i = 1;  i < 10;  ++i ) 
    {
        // draw horizontal grid line
        CGContextMoveToPoint( context, 0, i*dh );
        CGContextAddLineToPoint( context, w, i*dh );
    }
    for ( int i = 1;  i < 10;  ++i )
    {
        // draw vertical grid line
        CGContextMoveToPoint( context, i*dw, 0);
        CGContextAddLineToPoint( context, i*dw, h);
    }
    [[UIColor grayColor] setStroke];             // use gray as stroke color
    CGContextDrawPath( context, kCGPathStroke ); // execute collected drawing ops
    
    x1=100; y1=100; x2=200; y2=200;
    // establish bounding box for image
    CGPoint tl = self.inMotion ? CGPointMake( x, y ): CGPointMake( row*dw, col*dh );
    
    
    //CGPoint t3 = self.inMotion ? CGPointMake( x2, y2 ): CGPointMake( row*dw, col*dh );
    
    
    CGRect imageRect ;
    UIImage *img ;
    GridClas *gridPointer;
    if(numberOfTriess == 1){
        imageRect = CGRectMake(tl.x, tl.y, dw/2, dh/2);
    }else if(numberOfTriess == 2){
       imageRect = CGRectMake(tl.x, tl.y, dw/4, dh/4);

    }else if(numberOfTriess == 3){
        
        imageRect = CGRectMake(tl.x, tl.y, dw/8, dh/8);

    }else{
       imageRect = CGRectMake(tl.x, tl.y, dw, dh);
    }
    
    if ( self.row == 9  &&  self.col == 9 ){
        imageRect = CGRectMake(tl.x, tl.y, dw, dh);
        img = [UIImage imageNamed:@"devil"];
         UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Congratulations!!" message:@"You Win!!" delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"New Game",nil];
        [alert show];
    }else{
        
        img = [UIImage imageNamed:@"angel2"];
        }
    [img drawInRect:imageRect];

    [self insertAngel];
}

//------------------------------------------------------------------------------
// Display state of game
//------------------------------------------------------------------------------
-(void) insertAngel
{
    int k =0;
    GridClas *gridPointer;
    for(int i=0;i<10 ;i++){
        for( int j=0 ; j< 10 ; j++){
            
            gridPointer= [ myArray objectAtIndex:k];
            NSString *pathToResource;
            UIImage *img;
            if( gridPointer.angel)
            {
                CGPoint xy = { (gridPointer.colValue)*dw, gridPointer.rowValue*dh };
                CGRect mineImage = CGRectMake(xy.x,xy.y,dw,dh);
                
                if(i==0){
                pathToResource = [[NSBundle mainBundle] pathForResource:@"angel2" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                    
                }
                
                else if(i==1){
                
                pathToResource = [[NSBundle mainBundle] pathForResource:@"angel3" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                else if(i==2){
                
                pathToResource = [[NSBundle mainBundle] pathForResource:@"angel4" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    
                    [img drawInRect:mineImage];
                }
                
                else if(i==3){
                pathToResource = [[NSBundle mainBundle] pathForResource:@"angel5" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                else if(i==4){
                pathToResource = [[NSBundle mainBundle] pathForResource:@"angel6" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                else if(i==5){
                pathToResource = [[NSBundle mainBundle] pathForResource:@"angel7" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                else if(i==6){
                pathToResource = [[NSBundle mainBundle] pathForResource:@"angel8" ofType:@"png"];
                   img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                else if(i==7){
                pathToResource = [[NSBundle mainBundle] pathForResource:@"angel9" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                else{
                  pathToResource = [[NSBundle mainBundle] pathForResource:@"angel10" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                gridPointer.angel_count=1;
            }
            
            if(gridPointer.visited == true )
            {
                
                CGPoint xy = { (gridPointer.colValue)*dw, gridPointer.rowValue*dh };
                CGRect mineImage = CGRectMake(xy.x,xy.y,dw*2,dh*2);
                UIImage *img;
                
                if(i==0){
                    pathToResource = [[NSBundle mainBundle] pathForResource:@"angel2" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                    
                }
                
                else if(i==1){
                    
                    pathToResource = [[NSBundle mainBundle] pathForResource:@"angel3" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                else if(i==2){
                    
                    pathToResource = [[NSBundle mainBundle] pathForResource:@"angel4" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    
                    [img drawInRect:mineImage];
                }
                
                else if(i==3){
                    pathToResource = [[NSBundle mainBundle] pathForResource:@"angel5" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                else if(i==4){
                    pathToResource = [[NSBundle mainBundle] pathForResource:@"angel6" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                else if(i==5){
                    pathToResource = [[NSBundle mainBundle] pathForResource:@"angel7" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                else if(i==6){
                    pathToResource = [[NSBundle mainBundle] pathForResource:@"angel8" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                
                else if(i==7){
                    pathToResource = [[NSBundle mainBundle] pathForResource:@"angel9" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
                else{
                    pathToResource = [[NSBundle mainBundle] pathForResource:@"angel10" ofType:@"png"];
                    img = [UIImage imageNamed:pathToResource];
                    [img drawInRect:mineImage];
                }
               
                 [img drawInRect:mineImage];
            }
             k++;
        }
    }
}


//------------------------------------------------------------------------------
// Place Angels into the grids
//------------------------------------------------------------------------------
-(void) spotAngels
{
     GridClas *gridPointer;
    int bombsCounter = 27;
    while(bombsCounter > 0){
        int randomNumber = arc4random_uniform((10 * 10) - 1);
        int rowCount = (randomNumber / 10);
        int columnCount = randomNumber % 10;
        int k=0, count=0;
       
        for(int i=0;i<10 ;i++){
            for( int j =0 ; j < 10 ; j++){
                gridPointer = [ myArray objectAtIndex:k];
                if(gridPointer.rowValue == rowCount && gridPointer.colValue == columnCount)
                {
                    if(gridPointer.rowValue !=0 && gridPointer.colValue !=0)
                    {
                        if(gridPointer.rowValue !=9 && gridPointer.colValue !=9)
                        {
                            gridPointer.angel = true;
                        }
                    }
                }

                k++;
            }
        }
        bombsCounter--;
    }
}


//------------------------------------------------------------------------------
// reseting game values for new game
//------------------------------------------------------------------------------
- (void)resetGame
{
    
    int k =0;
    GridClas *gridPointer;
    for(int i=0;i< 10 ;i++){
        for( int j =0 ; j < 10 ; j++){
            gridPointer= [ myArray objectAtIndex:k];
            gridPointer.angel = FALSE;
            gridPointer.opened = false;
            gridPointer.flag = FALSE;
            gridPointer.visited =false;
            k++;
        }
    }
    numberOfTriess = 0;
    self.row=0;
    self.col=0;
    self.x=0;
    self.y=0;
    [self setBackgroundColor:[UIColor cyanColor]];
    
    CGPoint tl = self.inMotion ? CGPointMake( x, y ): CGPointMake( row*dw, col*dh );
    CGRect imageRect ;
    // imageRect = CGRectMake(tl.x, tl.y, dw, dh)
    UIImage *img ;
    
    if ( self.row == 9 && self.col == 9 ){
        img = [UIImage imageNamed:@"devil"];
        
    }else{
        img = [UIImage imageNamed:@"angel1"];
    }
    [img drawInRect:imageRect];
    
    
    [self spotAngels];
    
}


//------------------------------------------------------------------------------
// Calling after button is clicked
//------------------------------------------------------------------------------
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if(buttonIndex == 1){
        // resetting game
        [self resetGame];
        [self setNeedsDisplay];
    }else{
        // shutting down game
        exit(0);
    }
}


//------------------------------------------------------------------------------
// Handles all touches that begin right at mouse click
//------------------------------------------------------------------------------

-(void) touchesBegan: (NSSet *) touches withEvent: (UIEvent *) event
{
    int touchRow, touchCol;
    CGPoint xy;
    
    NSLog( @"touchesBegan:withEvent:" );
    [super touchesBegan: touches withEvent: event];
    for ( id t in touches )
    {
        xy = [t locationInView: self];
        self.x = xy.x;  self.y = xy.y;
        touchRow = self.x / self.dw;  touchCol = self.y / self.dh;
        self.inMotion = (self.row == touchRow  &&  self.col == touchCol);
        NSLog( @"touch point (x,y) = (%g,%g)", self.x, self.y );
        NSLog( @"  falls in cell (row,col) = (%d,%d)", touchRow, touchCol );
    }
}

//------------------------------------------------------------------------------
// Handles all touches that happens when the angel is moved
//------------------------------------------------------------------------------

-(void) touchesMoved: (NSSet *) touches withEvent: (UIEvent *) event
{    
    int touchRow, touchCol;
    CGPoint xy;

    NSLog( @"touchesMoved:withEvent:" );
    [super touchesMoved: touches withEvent: event];
    
    for ( id t in touches )
    {
        xy = [t locationInView: self];
        self.x = xy.x;  self.y = xy.y;
        touchCol = self.x / self.dw;  touchRow = self.y / self.dh;
        GridClas *gridPointer;
        NSLog(@"Self row,col %d, %d ", touchRow, touchCol);
        NSLog(@"GridPointer row,col %d, %d ", gridPointer.rowValue, gridPointer.colValue);
        int k=0;
        for(int i=0;i<10 ;i++){
            for( int j =0 ; j < 10 ; j++){
                gridPointer = [ myArray objectAtIndex:k];
                
                if(gridPointer.rowValue == touchRow && gridPointer.colValue == touchCol)
                {   if(!gridPointer.flag){
                    if(gridPointer.angel)
                    {
                        numberOfTriess++;

                        NSLog(@"Tries= %d", numberOfTriess);
                        if( numberOfTriess>3)
                        {
                            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Game Over!!" message:@"You Lose!!" delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"New Game",nil];
                            [alert show];
                        }
                    
                        gridPointer.visited=true;
                        gridPointer.flag = true;
                        
                    }
                    }
                }else{
                    gridPointer.visited=false;
                }
                k++;
            }
        }
        
    }
    
    if ( self.inMotion )
    {
        [self setNeedsDisplay];
    }
}

//------------------------------------------------------------------------------
// Handles all touches that happens after the mouse key is released
//------------------------------------------------------------------------------

-(void) touchesEnded: (NSSet *) touches withEvent: (UIEvent *) event
{
    GridClas *gridPointer;
    NSLog( @"touchesEnded:withEvent:" );
    [super touchesEnded: touches withEvent: event];
    if ( self.inMotion )
    {
        int touchRow = 0, touchCol = 0;
        CGPoint xy ;
        
        for ( id t in touches )
        {
            xy = [t locationInView: self];
            self.x = xy.x;  self.y = xy.y;
            touchRow = self.x / self.dw;  touchCol = self.y / self.dh;
            NSLog( @"touch point (x,y) = (%g,%g)", x, y );
            NSLog( @"  falls in cell (row,col) = (%d,%d)", touchRow, touchCol );
            
        }
        self.inMotion = NO;
        self.row = touchRow;  self.col = touchCol;
        if ( self.row == 9  &&  self.col == 9 )
            [self setBackgroundColor: [UIColor redColor]];
        else
        {
            [self setBackgroundColor: [UIColor cyanColor]];
        }
        [self setNeedsDisplay];
    }
}


-(void) touchesCancelled: (NSSet *) touches withEvent: (UIEvent *) event
{
    NSLog( @"touchesCancelled:withEvent:" );
    [super touchesCancelled: touches withEvent: event];    
}

@end
