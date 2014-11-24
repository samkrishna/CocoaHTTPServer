#import <Foundation/Foundation.h>
#import "HTTPResponse.h"

@class HTTPConnection;


@interface HTTPFileResponse : NSObject <HTTPResponse>

- (instancetype)initWithFilePath: (NSString *)filePath
				   forConnection: (HTTPConnection *)connection;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *filePath;

@end
