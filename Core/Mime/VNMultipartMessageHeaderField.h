
#import <Foundation/Foundation.h>

//-----------------------------------------------------------------
// interface MultipartMessageHeaderField
//-----------------------------------------------------------------

@interface VNMultipartMessageHeaderField : NSObject {
	NSString*						name;
    NSString*						value;
    NSMutableDictionary*			params;
}

@property (strong, readonly) NSString*		value;
@property (strong, readonly) NSDictionary*	params;
@property (strong, readonly) NSString*		name;

//- (id) initWithLine:(NSString*) line;
//- (id) initWithName:(NSString*) paramName value:(NSString*) paramValue;

- (instancetype) initWithData:(NSData*) data contentEncoding:(NSStringEncoding) encoding;

@end
