#import "VNHTTPRedirectResponse.h"
#import "HTTPLogging.h"

@interface VNHTTPRedirectResponse ()

@property (nonatomic, copy) NSString *redirectPath;

@end

@implementation VNHTTPRedirectResponse

- (instancetype)initWithPath:(NSString *)path
{
	if ((self = [super init]))
	{
		HTTPLogTrace();
		[self setRedirectPath: path];
	}
	return self;
}

- (UInt64)contentLength
{
	return 0;
}

- (UInt64)offset
{
	return 0;
}

- (void)setOffset:(UInt64)offset
{
	// Nothing to do
}

- (NSData *)readDataOfLength:(NSUInteger)length
{
	HTTPLogTrace();
	
	return nil;
}

- (BOOL)isDone
{
	return YES;
}

- (NSDictionary *)httpHeaders
{
	HTTPLogTrace();
	
	return @{@"Location": _redirectPath};
}

- (NSInteger)status
{
	HTTPLogTrace();
	
	return 302;
}

@end
