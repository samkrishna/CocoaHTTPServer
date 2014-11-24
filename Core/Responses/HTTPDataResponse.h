#import <Foundation/Foundation.h>
#import "HTTPResponse.h"


@interface VNHTTPDataResponse : NSObject <VNHTTPResponse>

- (instancetype)initWithData:(NSData *)data;

@end
