#import <Foundation/Foundation.h>
#import "HTTPResponse.h"


@interface HTTPDataResponse : NSObject <HTTPResponse>

- (instancetype)initWithData:(NSData *)data;

@end
