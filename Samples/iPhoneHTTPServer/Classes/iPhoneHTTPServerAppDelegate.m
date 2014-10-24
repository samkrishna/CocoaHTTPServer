#import "iPhoneHTTPServerAppDelegate.h"
#import "iPhoneHTTPServerViewController.h"
#import "VNHTTPServer.h"


@implementation iPhoneHTTPServerAppDelegate

@synthesize window;
@synthesize viewController;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	// Create server using our custom MyHTTPServer class
	httpServer = [[VNHTTPServer alloc] init];
	
	// Tell the server to broadcast its presence via Bonjour.
	// This allows browsers such as Safari to automatically discover our service.
	[httpServer setType:@"_http._tcp."];
	
	// Normally there's no need to run our server on any specific port.
	// Technologies like Bonjour allow clients to dynamically discover the server's port at runtime.
	// However, for easy testing you may want force a certain port so you can just hit the refresh button.
	[httpServer setPort:12345];
	
	// Serve files from our embedded Web folder
	NSString *webPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"Web"];
	NSLog(@"Setting document root: %@", webPath);
	
	[httpServer setDocumentRoot:webPath];
	
	// Start the server (and check for problems)
	
	NSError *error;
	if([httpServer start:&error])
	{
		NSLog(@"Started HTTP Server on port %hu", [httpServer listeningPort]);
	}
	else
	{
		NSLog(@"Error starting HTTP Server: %@", error);
	}
	
    // Add the view controller's view to the window and display.
    [window addSubview:viewController.view];
    [window makeKeyAndVisible];

    return YES;
}



@end
