#import "VNHTTPDataResponse.h"
#import "HTTPLogging.h"

@interface VNHTTPDataResponse ()

@property (nonatomic, strong) NSData *data;

@end

@implementation VNHTTPDataResponse

@synthesize offset = _offset;

- (instancetype)initWithData:(NSData *)dataParam
{
	if((self = [super init]))
	{
		HTTPLogTrace();
		[self setOffset: 0];
		[self setData: dataParam];
	}
	return self;
}

- (UInt64)contentLength
{
	UInt64 result = (UInt64)[_data length];
	
	HTTPLogTrace2(@"%@[%p]: contentLength - %llu", THIS_FILE, self, result);
	
	return result;
}

- (NSData *)readDataOfLength:(NSUInteger)lengthParameter
{
	HTTPLogTrace2(@"%@[%p]: readDataOfLength:%lu", THIS_FILE, self, (unsigned long)lengthParameter);
	
	NSUInteger remaining = [_data length] - _offset;
	NSUInteger length = lengthParameter < remaining ? lengthParameter : remaining;
	
	void *bytes = (void *)([_data bytes] + _offset);
	
	_offset += length;
	
	return [NSData dataWithBytesNoCopy:bytes length:length freeWhenDone:NO];
}

- (BOOL)isDone
{
	BOOL result = (_offset == [_data length]);
	
	HTTPLogTrace2(@"%@[%p]: isDone - %@", THIS_FILE, self, (result ? @"YES" : @"NO"));
	
	return result;
}

@end
