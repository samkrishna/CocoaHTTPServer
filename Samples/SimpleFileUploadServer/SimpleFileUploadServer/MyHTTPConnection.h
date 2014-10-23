
#import "VNHTTPConnection.h"

@class VNMultipartFormDataParser;

@interface MyHTTPConnection : VNHTTPConnection  {
    VNMultipartFormDataParser*        parser;
	NSFileHandle*					storeFile;
	
	NSMutableArray*					uploadedFiles;
}

@end
