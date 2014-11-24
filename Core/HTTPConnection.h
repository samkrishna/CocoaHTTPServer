#import <Foundation/Foundation.h>

@class GCDAsyncSocket;
@class VNHTTPMessage;
@class VNHTTPServer;
@class VNWebSocket;
@protocol VNHTTPResponse;


#define HTTPConnectionDidDieNotification  @"HTTPConnectionDidDie"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface VNHTTPConfiguration : NSObject
{
	VNHTTPServer __unsafe_unretained *server;
	NSString __strong *documentRoot;
	dispatch_queue_t queue;
}

- (instancetype)initWithServer:(VNHTTPServer *)server documentRoot:(NSString *)documentRoot;
- (instancetype)initWithServer:(VNHTTPServer *)server documentRoot:(NSString *)documentRoot queue:(dispatch_queue_t)q;

@property (nonatomic, unsafe_unretained, readonly) VNHTTPServer *server;
@property (nonatomic, strong, readonly) NSString *documentRoot;
@property (nonatomic, readonly) dispatch_queue_t queue;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface VNHTTPConnection : NSObject
{
	dispatch_queue_t connectionQueue;
	GCDAsyncSocket *asyncSocket;
	VNHTTPConfiguration *config;
	
	BOOL started;
	
	VNHTTPMessage *request;
	unsigned int numHeaderLines;
	
	BOOL sentResponseHeaders;
	
	NSString *nonce;
	long lastNC;
	
	NSObject<VNHTTPResponse> *httpResponse;
	
	NSMutableArray *ranges;
	NSMutableArray *ranges_headers;
	NSString *ranges_boundry;
	int rangeIndex;
	
	UInt64 requestContentLength;
	UInt64 requestContentLengthReceived;
	UInt64 requestChunkSize;
	UInt64 requestChunkSizeReceived;
  
	NSMutableArray *responseDataSizes;
}

- (instancetype)initWithAsyncSocket:(GCDAsyncSocket *)newSocket configuration:(VNHTTPConfiguration *)aConfig;

- (void)start;
- (void)stop;

- (void)startConnection;

- (BOOL)supportsMethod:(NSString *)method atPath:(NSString *)path;
- (BOOL)expectsRequestBodyFromMethod:(NSString *)method atPath:(NSString *)path;

@property (NS_NONATOMIC_IOSONLY, getter=isSecureServer, readonly) BOOL secureServer;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSArray *sslIdentityAndCertificates;

- (BOOL)isPasswordProtected:(NSString *)path;
@property (NS_NONATOMIC_IOSONLY, readonly) BOOL useDigestAccessAuthentication;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *realm;
- (NSString *)passwordForUser:(NSString *)username;

- (NSDictionary *)parseParams:(NSString *)query;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSDictionary *parseGetParams;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *requestURI;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSArray *directoryIndexFileNames;
- (NSString *)filePathForURI:(NSString *)path;
- (NSString *)filePathForURI:(NSString *)path allowDirectory:(BOOL)allowDirectory;
- (NSObject<VNHTTPResponse> *)httpResponseForMethod:(NSString *)method URI:(NSString *)path;
- (VNWebSocket *)webSocketForURI:(NSString *)path;

- (void)prepareForBodyWithSize:(UInt64)contentLength;
- (void)processBodyData:(NSData *)postDataChunk;
- (void)finishBody;

- (void)handleVersionNotSupported:(NSString *)version;
- (void)handleAuthenticationFailed;
- (void)handleResourceNotFound;
- (void)handleInvalidRequest:(NSData *)data;
- (void)handleUnknownMethod:(NSString *)method;

- (NSData *)preprocessResponse:(VNHTTPMessage *)response;
- (NSData *)preprocessErrorResponse:(VNHTTPMessage *)response;

- (void)finishResponse;

@property (NS_NONATOMIC_IOSONLY, readonly) BOOL shouldDie;
- (void)die;

@end

@interface VNHTTPConnection (AsynchronousHTTPResponse)
- (void)responseHasAvailableData:(NSObject<VNHTTPResponse> *)sender;
- (void)responseDidAbort:(NSObject<VNHTTPResponse> *)sender;
@end
