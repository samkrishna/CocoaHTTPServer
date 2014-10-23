#import <Foundation/Foundation.h>
#import "HTTPResponse.h"


@interface VNHTTPRedirectResponse : NSObject <VNHTTPResponse>

- (instancetype)initWithPath:(NSString *)redirectPath;

@end
