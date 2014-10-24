#import <UIKit/UIKit.h>

@class iPhoneHTTPServerViewController;
@class VNHTTPServer;

@interface iPhoneHTTPServerAppDelegate : NSObject <UIApplicationDelegate>
{
	VNHTTPServer *httpServer;
	
	UIWindow *window;
	iPhoneHTTPServerViewController *viewController;
}

@property (nonatomic) IBOutlet UIWindow *window;
@property (nonatomic) IBOutlet iPhoneHTTPServerViewController *viewController;

@end

