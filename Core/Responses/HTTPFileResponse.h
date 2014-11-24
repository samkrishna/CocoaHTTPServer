#import <Foundation/Foundation.h>
#import "HTTPResponse.h"

@class VNHTTPConnection;


@interface VNHTTPFileResponse : NSObject <VNHTTPResponse>

- (instancetype)initWithFilePath: (NSString *)filePath
				   forConnection: (VNHTTPConnection *)connection;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *filePath;

@end
