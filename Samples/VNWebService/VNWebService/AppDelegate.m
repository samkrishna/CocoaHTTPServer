//
//  AppDelegate.m
//  VNWebService
//
//  Created by Lei on 14/10/24.
//  Copyright (c) 2014年 Lei. All rights reserved.
//

#import "AppDelegate.h"
#import <VNWebService/VNWebService.h>

@interface AppDelegate ()

@property (nonatomic, strong) VNHTTPServer *httpServer;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    // Create server using our custom MyHTTPServer class
    _httpServer = [[VNHTTPServer alloc] init];
    
    // Tell the server to broadcast its presence via Bonjour.
    // This allows browsers such as Safari to automatically discover our service.
    [_httpServer setType:@"_http._tcp."];
    
    // Normally there's no need to run our server on any specific port.
    // Technologies like Bonjour allow clients to dynamically discover the server's port at runtime.
    // However, for easy testing you may want force a certain port so you can just hit the refresh button.
    [_httpServer setPort:12345];
    
    // Serve files from our embedded Web folder
    NSString *webPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"Web"];
    NSLog(@"Setting document root: %@", webPath);
    
    [_httpServer setDocumentRoot:webPath];
    
    // Start the server (and check for problems)
    
    NSError *error;
    if([_httpServer start:&error])
    {
        NSLog(@"Started HTTP Server on port %hu", [_httpServer listeningPort]);
    }
    else
    {
        NSLog(@"Error starting HTTP Server: %@", error);
    }
    
    return YES;
}

@end
