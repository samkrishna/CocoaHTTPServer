#import <Foundation/Foundation.h>
#import "HTTPResponse.h"


@interface HTTPRedirectResponse : NSObject <HTTPResponse>

- (instancetype)initWithPath:(NSString *)redirectPath;

@end
