#import <Foundation/Foundation.h>
#import "HTTPResponse.h"


@interface VNHTTPDataResponse : NSObject <VNHTTPResponse>
{
	NSUInteger offset;
	NSData *data;
}

- (instancetype)initWithData:(NSData *)data;

@end
