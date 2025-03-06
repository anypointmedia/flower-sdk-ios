#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class Sdk_coreScte35DecoderCompanion, Sdk_coreSpliceInfoSection, Sdk_coreKotlinByteArray, Sdk_coreKotlinThrowable, Sdk_coreKotlinArray<T>, Sdk_coreKotlinException, Sdk_coreSpliceInsert, Sdk_coreSpliceTime, Sdk_coreBreakDuration, Sdk_coreKmLogging, Sdk_coreKotlinPair<__covariant A, __covariant B>, Sdk_coreLogLevel, Sdk_coreKmLog, Sdk_coreKotlinEnumCompanion, Sdk_coreKotlinEnum<E>, Sdk_corePlatform, Sdk_coreTimingLogCompanion, Sdk_coreTimingLogTiming, Sdk_coreHex, Sdk_coreLifecycleManager, Sdk_coreSdkContainerClassName, Sdk_corePlatformMap<K, V>, Sdk_coreAdHandlerCompanion, Sdk_coreAd, Sdk_coreAdTrackingEvent, Sdk_coreAdUrlMacroValue, Sdk_coreAdList, Sdk_coreManipulationProxy, Sdk_coreLogger, Sdk_coreFLogging, Sdk_coreAdUrlMacroCompanion, Sdk_coreAdUrlMacroType, Sdk_coreFillerAdsManagerCompanion, Sdk_coreFlowerAdsManagerImplCompanion, Sdk_coreFlowerAdsManagerListeners, Sdk_coreFlowerError, Sdk_coreFlowerAdsManagerListenersCompanion, Sdk_corePlatformList<E>, Sdk_coreAdHandler, Sdk_coreLinearTVAdHandlerCompanion, Sdk_coreNormalAdHandlerCompanion, Sdk_coreVastParserCompanion, Sdk_coreVmapParserCompanion, Sdk_coreAdBreak, Sdk_coreNormalAdHandler, Sdk_coreVodAdHandlerCompanion, Sdk_coreCreative, Sdk_coreAdClick, Sdk_coreAdCompanion, Sdk_coreCacheAdMediaSegmentServiceAdMediaSegment, Sdk_coreConvertCreativeRequestCompanion, Sdk_coreVariant, Sdk_coreMediaPlaylist, Sdk_coreMPD, Sdk_coreCreativeResponseAsset, Sdk_coreCreativeResponseCompanion, Sdk_coreCreativeResponseAssetCompanion, Sdk_coreCreativeTypeCompanion, Sdk_coreCreativeType, Sdk_coreKotlinRuntimeException, Sdk_coreMedia, Sdk_coreMediaChunk, Sdk_coreMediaPlayerItem, Sdk_coreKotlinWrapped<__covariant T>, Sdk_coreCacheServiceCompanion, Sdk_coreConcurrentQueue, Sdk_coreFlowerConfigService, Sdk_coreSdkContainer, Sdk_coreKtor_client_coreHttpClient, Sdk_coreCachedHttpClientCompanion, Sdk_coreKtor_client_coreHttpRequestBuilder, Sdk_coreCachedHttpClientResponse, Sdk_coreKtor_httpHttpStatusCode, Sdk_coreErrorCodeCompanion, Sdk_coreErrorCode, Sdk_coreErrorLogCompanion, Sdk_coreErrorLogSenderCompanion, Sdk_coreErrorLog, Sdk_coreFlowerConfigServiceCompanion, Sdk_coreXmlNode, Sdk_coreFlowerConfigServiceStartupConfig, Sdk_coreFlowerConfigServiceStartupConfigKey, Sdk_corePlatformAnalytics, Sdk_coreSdkContainerCompanion, Sdk_coreSdkContainerLogLevel, Sdk_coreAdUrlMacro, Sdk_coreCacheService, Sdk_coreCachedHttpClient, Sdk_coreErrorLogSender, Sdk_coreFillerAdsManager, Sdk_coreKotlinx_serialization_jsonJson, Sdk_coreMediaSegmentAssumeService, Sdk_coreDeviceServiceCompanion, Sdk_coreGoogleAdReportLogEvent, Sdk_coreManipulatorCompanion, Sdk_coreManipulator, Sdk_coreFlowerAdsManagerImpl, Sdk_coreDashManipulatorCompanion, Sdk_coreTimeScaled, Sdk_coreHlsManipulatorCompanion, Sdk_coreManifestParserCompanion, Sdk_coreRepresentation, Sdk_coreSegmentTemplate, Sdk_coreMPDCompanion, Sdk_corePeriod, Sdk_coreKotlinx_datetimeInstant, Sdk_corePeriodCompanion, Sdk_coreAdaptationSet, Sdk_coreSpliceInfoSection_, Sdk_coreCacheAdMediaSegmentServiceCompanion, Sdk_coreCacheAdMediaSegmentServiceAdGroup, Sdk_coreMediaSegment, Sdk_coreCacheAdMediaSegmentService, Sdk_coreMediaPlaylistManipulatorCompanion, Sdk_coreMediaPlaylistManipulatorCueOutMarker, Sdk_coreMediaPlaylistManipulatorCueInMarker, Sdk_coreMediaPlaylistManipulatorCueEvent, Sdk_coreMediaPlaylistManipulatorHistoryMediaSegment, Sdk_coreMediaType, Sdk_coreChannels, Sdk_coreAlternativeRendition, Sdk_coreByteRange, Sdk_coreCueOut, Sdk_coreScte35, Sdk_coreCueOutCont, Sdk_coreOffsetDateTime, Sdk_coreDateRange, Sdk_coreResolution, Sdk_coreVideoRange, Sdk_coreIFrameVariant, Sdk_coreKeyMethodCompanion, Sdk_coreKeyMethod, Sdk_coreStartTimeOffset, Sdk_corePlaylistVariable, Sdk_corePlaylist, Sdk_coreSessionData, Sdk_coreSegmentKey, Sdk_coreMasterPlaylist, Sdk_corePlaylistType, Sdk_coreServerControl, Sdk_corePartialSegmentInformation, Sdk_corePartialSegment, Sdk_coreSkip, Sdk_corePreloadHint, Sdk_coreRenditionReport, Sdk_coreSegmentMap, Sdk_coreMediaTypeCompanion, Sdk_corePreloadHintType, Sdk_coreAbstractPlaylistParserCompanion, Sdk_coreTextBuilder, Sdk_coreAbstractPlaylistParser<T, B>, Sdk_coreParsingMode, Sdk_coreMasterPlaylistParserCompanion, Sdk_coreMediaPlaylistParserCompanion, Sdk_coreMediaPlaylistParserBuilder, Sdk_coreParsingModeCompanion, Sdk_corePartialSegmentAttributeCompanion, Sdk_corePartialSegmentAttribute, Sdk_corePartialSegmentInformationAttributeCompanion, Sdk_corePartialSegmentInformationAttribute, Sdk_coreKtor_ioIOException, Sdk_corePlaylistVariableAttributeCompanion, Sdk_corePlaylistVariableAttribute, Sdk_corePreloadHintAttributeCompanion, Sdk_corePreloadHintAttribute, Sdk_coreRenditionReportAttributeCompanion, Sdk_coreRenditionReportAttribute, Sdk_coreSegmentKeyAttributeCompanion, Sdk_coreSegmentKeyAttribute, Sdk_coreServerControlAttributeCompanion, Sdk_coreServerControlAttribute, Sdk_coreSkipAttributeCompanion, Sdk_coreSkipAttribute, Sdk_coreKotlinStringBuilder, Sdk_coreManipulationProxyCompanion, Sdk_coreManipulationProxyProxyType, Sdk_coreManipulationProxyProxyTypeCompanion, Sdk_coreManipulationServerCompanion, Sdk_coreKotlinRegex, Sdk_coreAdProgress, Sdk_coreAdPlayerCallbacksCompanion, Sdk_coreAdProgressCompanion, Sdk_coreConcurrentQueueCompanion, Sdk_coreOffsetDateTimeCompanion, Sdk_corePlatform_Companion, Sdk_coreStringUtils, Sdk_coreKtor_client_coreHttpClientEngineConfig, Sdk_coreKtor_client_coreHttpClientConfig<T>, Sdk_coreKtor_eventsEvents, Sdk_coreKtor_client_coreHttpReceivePipeline, Sdk_coreKtor_client_coreHttpRequestPipeline, Sdk_coreKtor_client_coreHttpResponsePipeline, Sdk_coreKtor_client_coreHttpSendPipeline, Sdk_coreKtor_client_coreHttpResponse, Sdk_coreKtor_httpHeadersBuilder, Sdk_coreKtor_client_coreHttpRequestBuilderCompanion, Sdk_coreKtor_client_coreHttpRequestData, Sdk_coreKtor_httpURLBuilder, Sdk_coreKtor_utilsTypeInfo, Sdk_coreKtor_httpHttpMethod, Sdk_coreKtor_httpUrlCompanion, Sdk_coreKtor_httpURLProtocol, Sdk_coreKtor_httpUrl, Sdk_coreKotlinByteIterator, NSData, Sdk_coreKotlinx_coroutines_coreDispatchers, Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher, Sdk_coreKotlinx_coroutines_coreMainCoroutineDispatcher, Sdk_coreKotlinx_datetimeInstantCompanion, Sdk_corePlatformSet<E>, Sdk_coreManipulationServer, Sdk_coreKotlinNothing, Sdk_coreKotlinIllegalStateException, Sdk_coreKotlinCancellationException, Sdk_coreKtor_ioMemory, Sdk_coreKtor_ioChunkBuffer, Sdk_coreKtor_ioBuffer, Sdk_coreKtor_ioByteReadPacket, Sdk_coreKtor_httpHttpStatusCodeCompanion, Sdk_coreKotlinx_serialization_coreSerializersModule, Sdk_coreKotlinx_serialization_jsonJsonDefault, Sdk_coreKotlinx_serialization_jsonJsonElement, Sdk_coreKotlinx_serialization_jsonJsonConfiguration, Sdk_coreKotlinCharArray, Sdk_coreKotlinRegexOption, Sdk_coreKotlinRegexCompanion, Sdk_coreKtor_client_coreHttpResponseData, Sdk_coreKtor_client_coreProxyConfig, Sdk_coreKtor_utilsAttributeKey<T>, Sdk_coreKtor_eventsEventDefinition<T>, Sdk_coreKtor_utilsPipelinePhase, Sdk_coreKtor_utilsPipeline<TSubject, TContext>, Sdk_coreKtor_client_coreHttpReceivePipelinePhases, Sdk_coreKotlinUnit, Sdk_coreKtor_client_coreHttpRequestPipelinePhases, Sdk_coreKtor_client_coreHttpResponsePipelinePhases, Sdk_coreKtor_client_coreHttpResponseContainer, Sdk_coreKtor_client_coreHttpClientCall, Sdk_coreKtor_client_coreHttpSendPipelinePhases, Sdk_coreKtor_utilsGMTDate, Sdk_coreKtor_httpHttpProtocolVersion, Sdk_coreKtor_utilsStringValuesBuilderImpl, Sdk_coreKtor_httpOutgoingContent, Sdk_coreKtor_httpURLBuilderCompanion, Sdk_coreKtor_httpHttpMethodCompanion, Sdk_coreKtor_httpURLProtocolCompanion, Sdk_coreKotlinAbstractCoroutineContextElement, Sdk_coreKotlinx_coroutines_coreCoroutineDispatcherKey, Sdk_coreKotlinx_serialization_coreSerialKind, Sdk_coreKtor_ioMemoryCompanion, Sdk_coreKtor_ioBufferCompanion, Sdk_coreKtor_ioChunkBufferCompanion, Sdk_coreKtor_ioInputCompanion, Sdk_coreKtor_ioInput, Sdk_coreKtor_ioByteReadPacketCompanion, Sdk_coreKotlinx_serialization_jsonJsonElementCompanion, Sdk_coreKotlinx_serialization_jsonClassDiscriminatorMode, Sdk_coreKotlinCharIterator, Sdk_coreKotlinMatchResultDestructured, Sdk_coreKotlinIntRange, Sdk_coreKtor_client_coreHttpClientCallCompanion, Sdk_coreKtor_utilsGMTDateCompanion, Sdk_coreKtor_utilsWeekDay, Sdk_coreKtor_utilsMonth, Sdk_coreKtor_httpHttpProtocolVersionCompanion, Sdk_coreKtor_httpContentType, Sdk_coreKotlinKTypeProjection, Sdk_coreKotlinAbstractCoroutineContextKey<B, E>, Sdk_coreKotlinMatchGroup, Sdk_coreKotlinIntProgressionCompanion, Sdk_coreKotlinIntIterator, Sdk_coreKotlinIntProgression, Sdk_coreKotlinIntRangeCompanion, Sdk_coreKtor_utilsWeekDayCompanion, Sdk_coreKtor_utilsMonthCompanion, Sdk_coreKtor_httpHeaderValueParam, Sdk_coreKtor_httpHeaderValueWithParametersCompanion, Sdk_coreKtor_httpHeaderValueWithParameters, Sdk_coreKtor_httpContentTypeCompanion, Sdk_coreKotlinKVariance, Sdk_coreKotlinKTypeProjectionCompanion;

@protocol Sdk_coreLogLevelController, Sdk_coreLogger, Sdk_coreLogFactory, Sdk_coreKotlinComparable, Sdk_coreTagProvider, Sdk_coreSdkLifecycleListener, Sdk_coreSdkContainerBeanFactory, Sdk_coreFlowerAdViewStub, Sdk_coreAdPlayerView, Sdk_coreGoogleAdView, Sdk_coreFlowerAdUIView, Sdk_coreFlowerAdsManagerListener, Sdk_coreKotlinx_coroutines_coreFlow, Sdk_coreKotlinx_coroutines_coreJob, Sdk_coreMediaPlayerHook, Sdk_coreFlowerAdsManager, Sdk_coreMediaPlayerAdapter, Sdk_coreAdPlayerCallback, Sdk_coreKotlinx_serialization_coreKSerializer, Sdk_coreUIElement, Sdk_coreMediaChunkStub, Sdk_corePlatformFile, Sdk_coreKtor_ioByteReadChannel, Sdk_coreKtor_httpHeaders, Sdk_coreDeviceService, Sdk_coreGoogleAdsManager, Sdk_coreXmlUtil, Sdk_coreKeyValueStore, Sdk_coreGoogleAdsLoaderListener, Sdk_coreKotlinIterator, Sdk_coreAttribute, Sdk_coreManipulationServerResponse, Sdk_coreKotlinSuspendFunction0, Sdk_coreKotlinCoroutineContext, Sdk_coreKotlinx_coroutines_coreCoroutineScope, Sdk_coreKtor_ioCloseable, Sdk_coreKtor_client_coreHttpClientEngine, Sdk_coreKtor_client_coreHttpClientEngineCapability, Sdk_coreKtor_utilsAttributes, Sdk_coreKtor_httpHttpMessageBuilder, Sdk_coreKtor_httpParameters, Sdk_coreKotlinx_coroutines_coreFlowCollector, Sdk_coreKotlinx_coroutines_coreChildHandle, Sdk_coreKotlinx_coroutines_coreChildJob, Sdk_coreKotlinx_coroutines_coreDisposableHandle, Sdk_coreKotlinSequence, Sdk_coreKotlinx_coroutines_coreSelectClause0, Sdk_coreKotlinCoroutineContextKey, Sdk_coreKotlinCoroutineContextElement, Sdk_coreKotlinx_serialization_coreEncoder, Sdk_coreKotlinx_serialization_coreSerialDescriptor, Sdk_coreKotlinx_serialization_coreSerializationStrategy, Sdk_coreKotlinx_serialization_coreDecoder, Sdk_coreKotlinx_serialization_coreDeserializationStrategy, Sdk_coreKtor_ioReadSession, Sdk_coreKotlinSuspendFunction1, Sdk_coreKotlinAppendable, Sdk_coreKotlinMapEntry, Sdk_coreKtor_utilsStringValues, Sdk_coreKotlinx_serialization_coreSerialFormat, Sdk_coreKotlinx_serialization_coreStringFormat, Sdk_coreKotlinCharSequence, Sdk_coreKotlinMatchResult, Sdk_coreKotlinFunction, Sdk_coreKtor_client_coreHttpClientPlugin, Sdk_coreKotlinSuspendFunction2, Sdk_coreKtor_httpHttpMessage, Sdk_coreKtor_utilsStringValuesBuilder, Sdk_coreKtor_httpParametersBuilder, Sdk_coreKotlinKClass, Sdk_coreKotlinKType, Sdk_coreKotlinContinuation, Sdk_coreKotlinContinuationInterceptor, Sdk_coreKotlinx_coroutines_coreRunnable, Sdk_coreKotlinx_datetimeDateTimeFormat, Sdk_coreKotlinx_coroutines_coreParentJob, Sdk_coreKotlinx_coroutines_coreSelectInstance, Sdk_coreKotlinx_coroutines_coreSelectClause, Sdk_coreKotlinx_serialization_coreCompositeEncoder, Sdk_coreKotlinAnnotation, Sdk_coreKotlinx_serialization_coreCompositeDecoder, Sdk_coreKtor_ioObjectPool, Sdk_coreKotlinx_serialization_coreSerializersModuleCollector, Sdk_coreKotlinx_serialization_jsonJsonNamingStrategy, Sdk_coreKotlinMatchGroupCollection, Sdk_coreKtor_client_coreHttpRequest, Sdk_coreKotlinKDeclarationContainer, Sdk_coreKotlinKAnnotatedElement, Sdk_coreKotlinKClassifier, Sdk_coreKotlinIterable, Sdk_coreKotlinCollection, Sdk_coreKotlinClosedRange, Sdk_coreKotlinOpenEndRange;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface Sdk_coreBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface Sdk_coreBase (Sdk_coreBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface Sdk_coreMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface Sdk_coreMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorSdk_coreKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface Sdk_coreNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface Sdk_coreByte : Sdk_coreNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface Sdk_coreUByte : Sdk_coreNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface Sdk_coreShort : Sdk_coreNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface Sdk_coreUShort : Sdk_coreNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface Sdk_coreInt : Sdk_coreNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface Sdk_coreUInt : Sdk_coreNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface Sdk_coreLong : Sdk_coreNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface Sdk_coreULong : Sdk_coreNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface Sdk_coreFloat : Sdk_coreNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface Sdk_coreDouble : Sdk_coreNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface Sdk_coreBoolean : Sdk_coreNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlatformList")))
@interface Sdk_corePlatformList<E> : Sdk_coreBase
- (instancetype)initWithArray:(NSArray<id> *)array __attribute__((swift_name("init(array:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSArray<id> *array __attribute__((swift_name("array")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlatformMap")))
@interface Sdk_corePlatformMap<K, V> : Sdk_coreBase
- (instancetype)initWithStorage:(NSDictionary<id, id> *)storage __attribute__((swift_name("init(storage:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSDictionary<id, id> *storage __attribute__((swift_name("storage")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlatformSet")))
@interface Sdk_corePlatformSet<E> : Sdk_coreBase
- (instancetype)initWithStorage:(NSSet<id> *)storage __attribute__((swift_name("init(storage:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSSet<id> *storage __attribute__((swift_name("storage")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Scte35Decoder")))
@interface Sdk_coreScte35Decoder : Sdk_coreBase
- (instancetype)initWithPrintlogs:(BOOL)printlogs __attribute__((swift_name("init(printlogs:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreScte35DecoderCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method converts instances of DecodingException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (Sdk_coreSpliceInfoSection * _Nullable)base64DecodeBase64in:(NSString *)base64in error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("base64Decode(base64in:)")));
- (int64_t)crc32B64:(Sdk_coreKotlinByteArray *)b64 startIdx:(int32_t)startIdx endIdx:(int32_t)endIdx __attribute__((swift_name("crc32(b64:startIdx:endIdx:)")));

/**
 * @note This method converts instances of DecodingException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (Sdk_coreSpliceInfoSection * _Nullable)hexDecodeHexin:(NSString *)hexin error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("hexDecode(hexin:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)logLog:(NSString * _Nullable)log __attribute__((swift_name("log(log:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Scte35Decoder.Companion")))
@interface Sdk_coreScte35DecoderCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreScte35DecoderCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface Sdk_coreKotlinThrowable : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (Sdk_coreKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Sdk_coreKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface Sdk_coreKotlinException : Sdk_coreKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DecodingException")))
@interface Sdk_coreDecodingException : Sdk_coreKotlinException
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message e:(Sdk_coreKotlinThrowable * _Nullable)e __attribute__((swift_name("init(message:e:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithCause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AvailDescriptor")))
@interface Sdk_coreAvailDescriptor : Sdk_coreBase
- (instancetype)initWithSpliceDescriptorTag:(int32_t)spliceDescriptorTag descriptorLength:(int32_t)descriptorLength identifier:(int32_t)identifier providerAvailID:(int32_t)providerAvailID __attribute__((swift_name("init(spliceDescriptorTag:descriptorLength:identifier:providerAvailID:)"))) __attribute__((objc_designated_initializer));
@property int32_t descriptorLength __attribute__((swift_name("descriptorLength")));
@property int32_t identifier __attribute__((swift_name("identifier")));
@property int32_t providerAvailID __attribute__((swift_name("providerAvailID")));
@property int32_t spliceDescriptorTag __attribute__((swift_name("spliceDescriptorTag")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BreakDuration")))
@interface Sdk_coreBreakDuration : Sdk_coreBase
- (instancetype)initWithAutoReturn:(int32_t)autoReturn reserved1:(int32_t)reserved1 duration:(int64_t)duration __attribute__((swift_name("init(autoReturn:reserved1:duration:)"))) __attribute__((objc_designated_initializer));
@property int32_t autoReturn __attribute__((swift_name("autoReturn")));
@property int64_t duration __attribute__((swift_name("duration")));
@property int32_t reserved1 __attribute__((swift_name("reserved1")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DTMFDescriptor")))
@interface Sdk_coreDTMFDescriptor : Sdk_coreBase
- (instancetype)initWithSpliceDescriptorTag:(int32_t)spliceDescriptorTag descriptorLength:(int32_t)descriptorLength identifier:(int32_t)identifier preroll:(int32_t)preroll dtmfCount:(int32_t)dtmfCount reserved:(int32_t)reserved DTMFChar:(Sdk_coreKotlinByteArray *)DTMFChar __attribute__((swift_name("init(spliceDescriptorTag:descriptorLength:identifier:preroll:dtmfCount:reserved:DTMFChar:)"))) __attribute__((objc_designated_initializer));
@property Sdk_coreKotlinByteArray *DTMFChar __attribute__((swift_name("DTMFChar")));
@property int32_t descriptorLength __attribute__((swift_name("descriptorLength")));
@property int32_t dtmfCount __attribute__((swift_name("dtmfCount")));
@property int32_t identifier __attribute__((swift_name("identifier")));
@property int32_t preroll __attribute__((swift_name("preroll")));
@property int32_t reserved __attribute__((swift_name("reserved")));
@property int32_t spliceDescriptorTag __attribute__((swift_name("spliceDescriptorTag")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SegmentationDescriptor")))
@interface Sdk_coreSegmentationDescriptor : Sdk_coreBase
- (instancetype)initWithSpliceDescriptorTag:(int32_t)spliceDescriptorTag descriptorLength:(int32_t)descriptorLength identifier:(int32_t)identifier segmentationEventID:(int32_t)segmentationEventID segmentationEventCancelIndicator:(int32_t)segmentationEventCancelIndicator reserved1:(int32_t)reserved1 programSegmentationFlag:(int32_t)programSegmentationFlag segmentationDurationFlag:(int32_t)segmentationDurationFlag deliveryNotRestricted:(int32_t)deliveryNotRestricted webDeliveryAllowedFlag:(int32_t)webDeliveryAllowedFlag noRegionalBlackoutFlag:(int32_t)noRegionalBlackoutFlag archiveAllowed:(int32_t)archiveAllowed deviceRestriction:(int32_t)deviceRestriction reserved2:(int32_t)reserved2 segmentationDuration:(int64_t)segmentationDuration turnerIdentifier:(int64_t)turnerIdentifier segmentationUPIDtype:(int32_t)segmentationUPIDtype segmentationUPIDlength:(int32_t)segmentationUPIDlength segmentationTypeID:(int32_t)segmentationTypeID segmentNum:(int32_t)segmentNum segmentsExpected:(int32_t)segmentsExpected __attribute__((swift_name("init(spliceDescriptorTag:descriptorLength:identifier:segmentationEventID:segmentationEventCancelIndicator:reserved1:programSegmentationFlag:segmentationDurationFlag:deliveryNotRestricted:webDeliveryAllowedFlag:noRegionalBlackoutFlag:archiveAllowed:deviceRestriction:reserved2:segmentationDuration:turnerIdentifier:segmentationUPIDtype:segmentationUPIDlength:segmentationTypeID:segmentNum:segmentsExpected:)"))) __attribute__((objc_designated_initializer));
@property int32_t archiveAllowed __attribute__((swift_name("archiveAllowed")));
@property int32_t deliveryNotRestricted __attribute__((swift_name("deliveryNotRestricted")));
@property int32_t descriptorLength __attribute__((swift_name("descriptorLength")));
@property int32_t deviceRestriction __attribute__((swift_name("deviceRestriction")));
@property int32_t identifier __attribute__((swift_name("identifier")));
@property int32_t noRegionalBlackoutFlag __attribute__((swift_name("noRegionalBlackoutFlag")));
@property int32_t programSegmentationFlag __attribute__((swift_name("programSegmentationFlag")));
@property int32_t reserved1 __attribute__((swift_name("reserved1")));
@property int32_t reserved2 __attribute__((swift_name("reserved2")));
@property int32_t segmentNum __attribute__((swift_name("segmentNum")));
@property int64_t segmentationDuration __attribute__((swift_name("segmentationDuration")));
@property int32_t segmentationDurationFlag __attribute__((swift_name("segmentationDurationFlag")));
@property int32_t segmentationEventCancelIndicator __attribute__((swift_name("segmentationEventCancelIndicator")));
@property int32_t segmentationEventID __attribute__((swift_name("segmentationEventID")));
@property int32_t segmentationTypeID __attribute__((swift_name("segmentationTypeID")));
@property int32_t segmentationUPIDlength __attribute__((swift_name("segmentationUPIDlength")));
@property int32_t segmentationUPIDtype __attribute__((swift_name("segmentationUPIDtype")));
@property int32_t segmentsExpected __attribute__((swift_name("segmentsExpected")));
@property int32_t spliceDescriptorTag __attribute__((swift_name("spliceDescriptorTag")));
@property int64_t turnerIdentifier __attribute__((swift_name("turnerIdentifier")));
@property int32_t webDeliveryAllowedFlag __attribute__((swift_name("webDeliveryAllowedFlag")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SpliceInfoSection")))
@interface Sdk_coreSpliceInfoSection : Sdk_coreBase
- (instancetype)initWithTableID:(int32_t)tableID sectionSyntaxIndicator:(int32_t)sectionSyntaxIndicator privateIndicator:(int32_t)privateIndicator reserved1:(int32_t)reserved1 sectionLength:(int32_t)sectionLength protocolVersion:(int32_t)protocolVersion encryptedPacket:(int32_t)encryptedPacket encryptionAlgorithm:(int32_t)encryptionAlgorithm ptsAdjustment:(int64_t)ptsAdjustment cwIndex:(int32_t)cwIndex tier:(int32_t)tier spliceCommandLength:(int32_t)spliceCommandLength spliceCommandType:(int32_t)spliceCommandType descriptorLoopLength:(int32_t)descriptorLoopLength alignmentStuffing:(int32_t)alignmentStuffing eCRC32:(int32_t)eCRC32 CRC32:(int32_t)CRC32 spliceInsert:(Sdk_coreSpliceInsert *)spliceInsert __attribute__((swift_name("init(tableID:sectionSyntaxIndicator:privateIndicator:reserved1:sectionLength:protocolVersion:encryptedPacket:encryptionAlgorithm:ptsAdjustment:cwIndex:tier:spliceCommandLength:spliceCommandType:descriptorLoopLength:alignmentStuffing:eCRC32:CRC32:spliceInsert:)"))) __attribute__((objc_designated_initializer));
@property int32_t CRC32 __attribute__((swift_name("CRC32")));
@property int32_t alignmentStuffing __attribute__((swift_name("alignmentStuffing")));
@property int32_t cwIndex __attribute__((swift_name("cwIndex")));
@property int32_t descriptorLoopLength __attribute__((swift_name("descriptorLoopLength")));
@property int32_t eCRC32 __attribute__((swift_name("eCRC32")));
@property int32_t encryptedPacket __attribute__((swift_name("encryptedPacket")));
@property int32_t encryptionAlgorithm __attribute__((swift_name("encryptionAlgorithm")));
@property int32_t privateIndicator __attribute__((swift_name("privateIndicator")));
@property int32_t protocolVersion __attribute__((swift_name("protocolVersion")));
@property int64_t ptsAdjustment __attribute__((swift_name("ptsAdjustment")));
@property int32_t reserved1 __attribute__((swift_name("reserved1")));
@property int32_t sectionLength __attribute__((swift_name("sectionLength")));
@property int32_t sectionSyntaxIndicator __attribute__((swift_name("sectionSyntaxIndicator")));
@property int32_t spliceCommandLength __attribute__((swift_name("spliceCommandLength")));
@property int32_t spliceCommandType __attribute__((swift_name("spliceCommandType")));
@property Sdk_coreSpliceInsert *spliceInsert __attribute__((swift_name("spliceInsert")));
@property int32_t tableID __attribute__((swift_name("tableID")));
@property int32_t tier __attribute__((swift_name("tier")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SpliceInsert")))
@interface Sdk_coreSpliceInsert : Sdk_coreBase
- (instancetype)initWithSpliceEventID:(int32_t)spliceEventID spliceEventCancelIndicator:(int32_t)spliceEventCancelIndicator reserved1:(int32_t)reserved1 outOfNetworkIndicator:(int32_t)outOfNetworkIndicator programSpliceFlag:(int32_t)programSpliceFlag sisp:(Sdk_coreSpliceTime *)sisp durationFlag:(int32_t)durationFlag spliceImmediateFlag:(int32_t)spliceImmediateFlag breakDuration:(Sdk_coreBreakDuration *)breakDuration reserved2:(int32_t)reserved2 uniqueProgramID:(int32_t)uniqueProgramID availNum:(int32_t)availNum availsExpected:(int32_t)availsExpected __attribute__((swift_name("init(spliceEventID:spliceEventCancelIndicator:reserved1:outOfNetworkIndicator:programSpliceFlag:sisp:durationFlag:spliceImmediateFlag:breakDuration:reserved2:uniqueProgramID:availNum:availsExpected:)"))) __attribute__((objc_designated_initializer));
@property int32_t availNum __attribute__((swift_name("availNum")));
@property int32_t availsExpected __attribute__((swift_name("availsExpected")));
@property Sdk_coreBreakDuration *breakDuration __attribute__((swift_name("breakDuration")));
@property int32_t durationFlag __attribute__((swift_name("durationFlag")));
@property int32_t outOfNetworkIndicator __attribute__((swift_name("outOfNetworkIndicator")));
@property int32_t programSpliceFlag __attribute__((swift_name("programSpliceFlag")));
@property int32_t reserved1 __attribute__((swift_name("reserved1")));
@property int32_t reserved2 __attribute__((swift_name("reserved2")));
@property Sdk_coreSpliceTime *sisp __attribute__((swift_name("sisp")));
@property int32_t spliceEventCancelIndicator __attribute__((swift_name("spliceEventCancelIndicator")));
@property int32_t spliceEventID __attribute__((swift_name("spliceEventID")));
@property int32_t spliceImmediateFlag __attribute__((swift_name("spliceImmediateFlag")));
@property int32_t uniqueProgramID __attribute__((swift_name("uniqueProgramID")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SpliceTime")))
@interface Sdk_coreSpliceTime : Sdk_coreBase
- (instancetype)initWithTimeSpecifiedFlag:(int32_t)timeSpecifiedFlag reserved1:(int32_t)reserved1 ptsTime:(int64_t)ptsTime reserved2:(int32_t)reserved2 __attribute__((swift_name("init(timeSpecifiedFlag:reserved1:ptsTime:reserved2:)"))) __attribute__((objc_designated_initializer));
@property int64_t ptsTime __attribute__((swift_name("ptsTime")));
@property int32_t reserved1 __attribute__((swift_name("reserved1")));
@property int32_t reserved2 __attribute__((swift_name("reserved2")));
@property int32_t timeSpecifiedFlag __attribute__((swift_name("timeSpecifiedFlag")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeSignal")))
@interface Sdk_coreTimeSignal : Sdk_coreBase
- (instancetype)initWithTssp:(Sdk_coreSpliceTime *)tssp __attribute__((swift_name("init(tssp:)"))) __attribute__((objc_designated_initializer));
@property Sdk_coreSpliceTime *tssp __attribute__((swift_name("tssp")));
@end

__attribute__((swift_name("LogLevelController")))
@protocol Sdk_coreLogLevelController
@required
- (BOOL)isLoggingDebug __attribute__((swift_name("isLoggingDebug()")));
- (BOOL)isLoggingError __attribute__((swift_name("isLoggingError()")));
- (BOOL)isLoggingInfo __attribute__((swift_name("isLoggingInfo()")));
- (BOOL)isLoggingVerbose __attribute__((swift_name("isLoggingVerbose()")));
- (BOOL)isLoggingWarning __attribute__((swift_name("isLoggingWarning()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FixedLogLevel")))
@interface Sdk_coreFixedLogLevel : Sdk_coreBase <Sdk_coreLogLevelController>
- (instancetype)initWithIsLogging:(BOOL)isLogging __attribute__((swift_name("init(isLogging:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isLoggingDebug __attribute__((swift_name("isLoggingDebug()")));
- (BOOL)isLoggingError __attribute__((swift_name("isLoggingError()")));
- (BOOL)isLoggingInfo __attribute__((swift_name("isLoggingInfo()")));
- (BOOL)isLoggingVerbose __attribute__((swift_name("isLoggingVerbose()")));
- (BOOL)isLoggingWarning __attribute__((swift_name("isLoggingWarning()")));
@end

__attribute__((swift_name("KmLog")))
@interface Sdk_coreKmLog : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithTag:(NSString *)tag __attribute__((swift_name("init(tag:)"))) __attribute__((objc_designated_initializer));
- (void)dTag:(NSString * _Nullable)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("d(tag:msg:)")));
- (void)debugMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("debug(msg:)")));
- (void)debugTag:(NSString *)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("debug(tag:msg:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)debugTag:(NSString *)tag msg_:(NSString *)msg __attribute__((swift_name("debug(tag:msg_:)")));
- (void)eErr:(Sdk_coreKotlinThrowable * _Nullable)err tag:(NSString * _Nullable)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("e(err:tag:msg:)")));
- (void)errorMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("error(msg:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)errorTag:(NSString *)tag msg:(NSString *)msg t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("error(tag:msg:t:)")));
- (void)errorErr:(Sdk_coreKotlinThrowable * _Nullable)err tag:(NSString * _Nullable)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("error(err:tag:msg:)")));
- (void)iTag:(NSString * _Nullable)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("i(tag:msg:)")));
- (void)infoMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("info(msg:)")));
- (void)infoTag:(NSString *)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("info(tag:msg:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)infoTag:(NSString *)tag msg_:(NSString *)msg __attribute__((swift_name("info(tag:msg_:)")));
- (void)vTag:(NSString * _Nullable)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("v(tag:msg:)")));
- (void)verboseMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("verbose(msg:)")));
- (void)verboseTag:(NSString *)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("verbose(tag:msg:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)verboseTag:(NSString *)tag msg_:(NSString *)msg __attribute__((swift_name("verbose(tag:msg_:)")));
- (void)wErr:(Sdk_coreKotlinThrowable * _Nullable)err tag:(NSString * _Nullable)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("w(err:tag:msg:)")));
- (void)warnMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("warn(msg:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)warnTag:(NSString *)tag msg:(NSString *)msg t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("warn(tag:msg:t:)")));
- (void)warnErr:(Sdk_coreKotlinThrowable * _Nullable)err tag:(NSString * _Nullable)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("warn(err:tag:msg:)")));
@property (readonly) NSString *tagName __attribute__((swift_name("tagName")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KmLogging")))
@interface Sdk_coreKmLogging : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)kmLogging __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKmLogging *shared __attribute__((swift_name("shared")));
- (void)addLoggerLogger:(id<Sdk_coreLogger>)logger __attribute__((swift_name("addLogger(logger:)")));
- (void)clear __attribute__((swift_name("clear()")));
- (Sdk_coreKotlinPair<NSString *, NSString *> *)createTagFromClass:(NSString * _Nullable)fromClass __attribute__((swift_name("createTag(fromClass:)")));
- (void)debugTag:(NSString *)tag msg:(NSString *)msg __attribute__((swift_name("debug(tag:msg:)")));
- (void)errorTag:(NSString *)tag msg:(NSString *)msg t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("error(tag:msg:t:)")));
- (void)infoTag:(NSString *)tag msg:(NSString *)msg __attribute__((swift_name("info(tag:msg:)")));
- (void)setLogFactoryFactory:(id<Sdk_coreLogFactory> _Nullable)factory __attribute__((swift_name("setLogFactory(factory:)")));
- (void)setLogLevelLevel:(Sdk_coreLogLevel *)level __attribute__((swift_name("setLogLevel(level:)")));
- (void)setLoggersLoggers:(Sdk_coreKotlinArray<id<Sdk_coreLogger>> *)loggers __attribute__((swift_name("setLoggers(loggers:)")));
- (void)setupLoggingFlags __attribute__((swift_name("setupLoggingFlags()")));
- (void)verboseTag:(NSString *)tag msg:(NSString *)msg __attribute__((swift_name("verbose(tag:msg:)")));
- (void)warnTag:(NSString *)tag msg:(NSString *)msg t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("warn(tag:msg:t:)")));
@property BOOL isLoggingDebug __attribute__((swift_name("isLoggingDebug")));
@property BOOL isLoggingError __attribute__((swift_name("isLoggingError")));
@property BOOL isLoggingInfo __attribute__((swift_name("isLoggingInfo")));
@property BOOL isLoggingVerbose __attribute__((swift_name("isLoggingVerbose")));
@property BOOL isLoggingWarning __attribute__((swift_name("isLoggingWarning")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KmModuleLog")))
@interface Sdk_coreKmModuleLog : Sdk_coreBase
- (instancetype)initWithLog:(Sdk_coreKmLog *)log isModuleLogging:(Sdk_coreBoolean *(^)(void))isModuleLogging __attribute__((swift_name("init(log:isModuleLogging:)"))) __attribute__((objc_designated_initializer));
- (void)dMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("d(msg:)")));
- (void)dTag:(NSString *)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("d(tag:msg:)")));
- (void)eMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("e(msg:)")));
- (void)eErr:(Sdk_coreKotlinThrowable * _Nullable)err tag:(NSString * _Nullable)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("e(err:tag:msg:)")));
- (void)iMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("i(msg:)")));
- (void)iTag:(NSString *)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("i(tag:msg:)")));
- (void)vMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("v(msg:)")));
- (void)vTag:(NSString *)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("v(tag:msg:)")));
- (void)wMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("w(msg:)")));
- (void)wErr:(Sdk_coreKotlinThrowable * _Nullable)err tag:(NSString * _Nullable)tag msg:(id _Nullable (^)(void))msg __attribute__((swift_name("w(err:tag:msg:)")));
@property (readonly) Sdk_coreBoolean *(^isModuleLogging)(void) __attribute__((swift_name("isModuleLogging")));
@property (readonly) Sdk_coreKmLog *log __attribute__((swift_name("log")));
@end

__attribute__((swift_name("LogFactory")))
@protocol Sdk_coreLogFactory
@required
- (Sdk_coreKmLog *)createKmLogTag:(NSString *)tag className:(NSString *)className __attribute__((swift_name("createKmLog(tag:className:)")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol Sdk_coreKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface Sdk_coreKotlinEnum<E> : Sdk_coreBase <Sdk_coreKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogLevel")))
@interface Sdk_coreLogLevel : Sdk_coreKotlinEnum<Sdk_coreLogLevel *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreLogLevel *verbose __attribute__((swift_name("verbose")));
@property (class, readonly) Sdk_coreLogLevel *debug __attribute__((swift_name("debug")));
@property (class, readonly) Sdk_coreLogLevel *info __attribute__((swift_name("info")));
@property (class, readonly) Sdk_coreLogLevel *warn __attribute__((swift_name("warn")));
@property (class, readonly) Sdk_coreLogLevel *error __attribute__((swift_name("error")));
@property (class, readonly) Sdk_coreLogLevel *off __attribute__((swift_name("off")));
+ (Sdk_coreKotlinArray<Sdk_coreLogLevel *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreLogLevel *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t level __attribute__((swift_name("level")));
@end

__attribute__((swift_name("Logger")))
@protocol Sdk_coreLogger <Sdk_coreLogLevelController>
@required
- (void)debugTag:(NSString *)tag msg_:(NSString *)msg __attribute__((swift_name("debug(tag:msg_:)")));
- (void)errorTag:(NSString *)tag msg:(NSString *)msg t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("error(tag:msg:t:)")));
- (void)infoTag:(NSString *)tag msg_:(NSString *)msg __attribute__((swift_name("info(tag:msg_:)")));
- (void)verboseTag:(NSString *)tag msg_:(NSString *)msg __attribute__((swift_name("verbose(tag:msg_:)")));
- (void)warnTag:(NSString *)tag msg:(NSString *)msg t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("warn(tag:msg:t:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Platform")))
@interface Sdk_corePlatform : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)platform __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_corePlatform *shared __attribute__((swift_name("shared")));
@property (readonly) BOOL isAndroid __attribute__((swift_name("isAndroid")));
@property (readonly) BOOL isIOS __attribute__((swift_name("isIOS")));
@property (readonly) BOOL isJS __attribute__((swift_name("isJS")));
@property (readonly) BOOL isJVM __attribute__((swift_name("isJVM")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int64_t timeNanos __attribute__((swift_name("timeNanos")));
@property (readonly) double version __attribute__((swift_name("version")));
@property (readonly) NSString *versionName __attribute__((swift_name("versionName")));
@end

__attribute__((swift_name("TagProvider")))
@protocol Sdk_coreTagProvider
@required
- (Sdk_coreKotlinPair<NSString *, NSString *> *)createTagFromClass:(NSString * _Nullable)fromClass __attribute__((swift_name("createTag(fromClass:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlatformLogger")))
@interface Sdk_corePlatformLogger : Sdk_coreBase <Sdk_coreLogger, Sdk_coreTagProvider, Sdk_coreLogLevelController>
- (instancetype)initWithLogLevel:(id<Sdk_coreLogLevelController>)logLevel __attribute__((swift_name("init(logLevel:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreKotlinPair<NSString *, NSString *> *)createTagFromClass:(NSString * _Nullable)fromClass __attribute__((swift_name("createTag(fromClass:)")));
- (void)debugTag:(NSString *)tag msg_:(NSString *)msg __attribute__((swift_name("debug(tag:msg_:)")));
- (void)errorTag:(NSString *)tag msg:(NSString *)msg t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("error(tag:msg:t:)")));
- (void)infoTag:(NSString *)tag msg_:(NSString *)msg __attribute__((swift_name("info(tag:msg_:)")));
- (BOOL)isLoggingDebug __attribute__((swift_name("isLoggingDebug()")));
- (BOOL)isLoggingError __attribute__((swift_name("isLoggingError()")));
- (BOOL)isLoggingInfo __attribute__((swift_name("isLoggingInfo()")));
- (BOOL)isLoggingVerbose __attribute__((swift_name("isLoggingVerbose()")));
- (BOOL)isLoggingWarning __attribute__((swift_name("isLoggingWarning()")));
- (void)verboseTag:(NSString *)tag msg_:(NSString *)msg __attribute__((swift_name("verbose(tag:msg_:)")));
- (void)warnTag:(NSString *)tag msg:(NSString *)msg t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("warn(tag:msg:t:)")));
@property (readonly) id<Sdk_coreLogLevelController> logLevel __attribute__((swift_name("logLevel")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimingLog")))
@interface Sdk_coreTimingLog : Sdk_coreBase
- (instancetype)initWithLabel:(NSString *)label tag:(NSString * _Nullable)tag __attribute__((swift_name("init(label:tag:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreTimingLogCompanion *companion __attribute__((swift_name("companion")));
- (void)addMsg:(NSString *)msg isVerbose:(BOOL)isVerbose __attribute__((swift_name("add(msg:isVerbose:)")));
- (void)debugMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("debug(msg:)")));
- (void)finishMinThresholdMs:(int64_t)minThresholdMs __attribute__((swift_name("finish(minThresholdMs:)")));
- (void)reset __attribute__((swift_name("reset()")));
- (void)verboseMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("verbose(msg:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimingLog.Companion")))
@interface Sdk_coreTimingLogCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreTimingLogCompanion *shared __attribute__((swift_name("shared")));
- (NSString *)truncateDecimalNum:(float)num decPlaces:(int32_t)decPlaces __attribute__((swift_name("truncateDecimal(num:decPlaces:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimingLog.Timing")))
@interface Sdk_coreTimingLogTiming : Sdk_coreBase
- (instancetype)initWithTime:(int64_t)time msg:(NSString *)msg isVerbose:(BOOL)isVerbose __attribute__((swift_name("init(time:msg:isVerbose:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreTimingLogTiming *)doCopyTime:(int64_t)time msg:(NSString *)msg isVerbose:(BOOL)isVerbose __attribute__((swift_name("doCopy(time:msg:isVerbose:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL isVerbose __attribute__((swift_name("isVerbose")));
@property (readonly) NSString *msg __attribute__((swift_name("msg")));
@property (readonly) int64_t time __attribute__((swift_name("time")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VariableLogLevel")))
@interface Sdk_coreVariableLogLevel : Sdk_coreBase <Sdk_coreLogLevelController>
- (instancetype)initWithLevel:(int32_t)level __attribute__((swift_name("init(level:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithLogLevel:(Sdk_coreLogLevel *)logLevel __attribute__((swift_name("init(logLevel:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isLoggingDebug __attribute__((swift_name("isLoggingDebug()")));
- (BOOL)isLoggingError __attribute__((swift_name("isLoggingError()")));
- (BOOL)isLoggingInfo __attribute__((swift_name("isLoggingInfo()")));
- (BOOL)isLoggingVerbose __attribute__((swift_name("isLoggingVerbose()")));
- (BOOL)isLoggingWarning __attribute__((swift_name("isLoggingWarning()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Hex")))
@interface Sdk_coreHex : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)hex __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreHex *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (Sdk_coreKotlinByteArray *)decodeData:(Sdk_coreKotlinByteArray *)data __attribute__((swift_name("decode(data:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (Sdk_coreKotlinByteArray *)decodeData_:(NSString *)data __attribute__((swift_name("decode(data_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (Sdk_coreKotlinByteArray *)encodeData:(Sdk_coreKotlinByteArray *)data __attribute__((swift_name("encode(data:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (NSString *)toHexStringData:(Sdk_coreKotlinByteArray *)data __attribute__((swift_name("toHexString(data:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LifecycleManager")))
@interface Sdk_coreLifecycleManager : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)lifecycleManager __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreLifecycleManager *shared __attribute__((swift_name("shared")));
- (void)destroy __attribute__((swift_name("destroy()")));
- (void)doInitListener:(id<Sdk_coreSdkLifecycleListener>)listener instances:(Sdk_corePlatformMap<Sdk_coreSdkContainerClassName *, id> *)instances factories:(Sdk_corePlatformMap<Sdk_coreSdkContainerClassName *, id<Sdk_coreSdkContainerBeanFactory>> *)factories __attribute__((swift_name("doInit(listener:instances:factories:)")));
@end

__attribute__((swift_name("SdkLifecycleListener")))
@protocol Sdk_coreSdkLifecycleListener
@required
- (void)onDestroyed __attribute__((swift_name("onDestroyed()")));
- (void)onInitialized __attribute__((swift_name("onInitialized()")));
@end

__attribute__((swift_name("AdHandler")))
@interface Sdk_coreAdHandler : Sdk_coreBase
- (instancetype)initWithFlowerAdView:(id<Sdk_coreFlowerAdViewStub>)flowerAdView adPlayerView:(id<Sdk_coreAdPlayerView>)adPlayerView googleAdView:(id<Sdk_coreGoogleAdView>)googleAdView flowerAdUIView:(id<Sdk_coreFlowerAdUIView>)flowerAdUIView adsManagerListener:(id<Sdk_coreFlowerAdsManagerListener>)adsManagerListener __attribute__((swift_name("init(flowerAdView:adPlayerView:googleAdView:flowerAdUIView:adsManagerListener:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreAdHandlerCompanion *companion __attribute__((swift_name("companion")));
- (void)appendAdAd:(Sdk_coreAd *)ad callback:(void (^)(Sdk_coreAd *))callback __attribute__((swift_name("appendAd(ad:callback:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)callBeaconsUrls:(NSArray<NSString *> *)urls ad:(Sdk_coreAd *)ad __attribute__((swift_name("callBeacons(urls:ad:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (Sdk_coreAd *)doCopyAdAd:(Sdk_coreAd *)ad __attribute__((swift_name("doCopyAd(ad:)")));
- (void)destroy __attribute__((swift_name("destroy()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)executeBeaconAd:(Sdk_coreAd *)ad trackingEvent:(Sdk_coreAdTrackingEvent *)trackingEvent __attribute__((swift_name("executeBeacon(ad:trackingEvent:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)executeTagUrl:(NSString *)url adUrlMacroValue:(Sdk_coreAdUrlMacroValue *)adUrlMacroValue timeoutMillis:(int64_t)timeoutMillis extraParams:(NSDictionary<NSString *, id> * _Nullable)extraParams adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders completionHandler:(void (^)(NSString * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("executeTag(url:adUrlMacroValue:timeoutMillis:extraParams:adTagHeaders:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeVastTagUrl:(NSString *)url adUrlMacroValue:(Sdk_coreAdUrlMacroValue *)adUrlMacroValue timeoutMillis:(int64_t)timeoutMillis extraParams:(NSDictionary<NSString *, id> * _Nullable)extraParams adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders adPrefix:(NSString * _Nullable)adPrefix preloadManifest:(BOOL)preloadManifest completionHandler:(void (^)(id<Sdk_coreKotlinx_coroutines_coreFlow> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("executeVastTag(url:adUrlMacroValue:timeoutMillis:extraParams:adTagHeaders:adPrefix:preloadManifest:completionHandler:)")));
- (void)executeWrapperAdWrapperAd:(Sdk_coreAd *)wrapperAd remainingAdDuration:(int64_t)remainingAdDuration callback:(void (^)(NSArray<Sdk_coreAd *> * _Nullable))callback __attribute__((swift_name("executeWrapperAd(wrapperAd:remainingAdDuration:callback:)")));
- (void)fillAdsStartRemainingTime:(int64_t)startRemainingTime callback:(void (^)(Sdk_coreAd *))callback __attribute__((swift_name("fillAds(startRemainingTime:callback:)")));
- (id<Sdk_coreKotlinx_coroutines_coreJob>)hideAdView __attribute__((swift_name("hideAdView()")));
- (id<Sdk_coreKotlinx_coroutines_coreJob>)hideClickUiAd:(Sdk_coreAd *)ad __attribute__((swift_name("hideClickUi(ad:)")));
- (id<Sdk_coreKotlinx_coroutines_coreJob>)showAdView __attribute__((swift_name("showAdView()")));
- (id<Sdk_coreKotlinx_coroutines_coreJob>)showClickUiAd:(Sdk_coreAd *)ad __attribute__((swift_name("showClickUi(ad:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)startGoogleAdTransactionId:(NSString *)transactionId duration:(int64_t)duration __attribute__((swift_name("startGoogleAd(transactionId:duration:)")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) id<Sdk_coreAdPlayerView> adPlayerView __attribute__((swift_name("adPlayerView")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) id<Sdk_coreFlowerAdsManagerListener> adsManagerListener __attribute__((swift_name("adsManagerListener")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property Sdk_coreAdList *displayAdList __attribute__((swift_name("displayAdList")));
@property int64_t fillerAppendDifference __attribute__((swift_name("fillerAppendDifference")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) id<Sdk_coreFlowerAdUIView> flowerAdUIView __attribute__((swift_name("flowerAdUIView")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) id<Sdk_coreFlowerAdViewStub> flowerAdView __attribute__((swift_name("flowerAdView")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) id<Sdk_coreGoogleAdView> googleAdView __attribute__((swift_name("googleAdView")));
@property BOOL isSkipTracking __attribute__((swift_name("isSkipTracking")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreManipulationProxy *manipulationProxy __attribute__((swift_name("manipulationProxy")));
@property Sdk_coreAdList *videoAdList __attribute__((swift_name("videoAdList")));
@end

__attribute__((swift_name("FLogging")))
@interface Sdk_coreFLogging : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (readonly) Sdk_coreLogger *logger __attribute__((swift_name("logger")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdHandler.Companion")))
@interface Sdk_coreAdHandlerCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreAdHandlerCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) int64_t AD_PLAY_TIME_CHECK_INTERVAL __attribute__((swift_name("AD_PLAY_TIME_CHECK_INTERVAL")));
@property (readonly) int64_t REMAINED_AD_DURATION_THRESHOLD __attribute__((swift_name("REMAINED_AD_DURATION_THRESHOLD")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdUrlMacro")))
@interface Sdk_coreAdUrlMacro : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreAdUrlMacroCompanion *companion __attribute__((swift_name("companion")));
- (NSString *)setMacroValueForSrcUrl:(NSString *)srcUrl adUrlMacroValue:(Sdk_coreAdUrlMacroValue *)adUrlMacroValue __attribute__((swift_name("setMacroValueFor(srcUrl:adUrlMacroValue:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdUrlMacro.Companion")))
@interface Sdk_coreAdUrlMacroCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreAdUrlMacroCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdUrlMacroType")))
@interface Sdk_coreAdUrlMacroType : Sdk_coreKotlinEnum<Sdk_coreAdUrlMacroType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreAdUrlMacroType *ip __attribute__((swift_name("ip")));
@property (class, readonly) Sdk_coreAdUrlMacroType *adid __attribute__((swift_name("adid")));
@property (class, readonly) Sdk_coreAdUrlMacroType *deviceId __attribute__((swift_name("deviceId")));
@property (class, readonly) Sdk_coreAdUrlMacroType *deviceModel __attribute__((swift_name("deviceModel")));
@property (class, readonly) Sdk_coreAdUrlMacroType *contentId __attribute__((swift_name("contentId")));
@property (class, readonly) Sdk_coreAdUrlMacroType *placementId __attribute__((swift_name("placementId")));
@property (class, readonly) Sdk_coreAdUrlMacroType *adDuration __attribute__((swift_name("adDuration")));
@property (class, readonly) Sdk_coreAdUrlMacroType *adDurationSec __attribute__((swift_name("adDurationSec")));
@property (class, readonly) Sdk_coreAdUrlMacroType *duration __attribute__((swift_name("duration")));
@property (class, readonly) Sdk_coreAdUrlMacroType *assetDuration __attribute__((swift_name("assetDuration")));
@property (class, readonly) Sdk_coreAdUrlMacroType *assetId __attribute__((swift_name("assetId")));
@property (class, readonly) Sdk_coreAdUrlMacroType *errorCode __attribute__((swift_name("errorCode")));
@property (class, readonly) Sdk_coreAdUrlMacroType *cacheBusting __attribute__((swift_name("cacheBusting")));
@property (class, readonly) Sdk_coreAdUrlMacroType *contentTaxonomy __attribute__((swift_name("contentTaxonomy")));
@property (class, readonly) Sdk_coreAdUrlMacroType *contentDuration __attribute__((swift_name("contentDuration")));
@property (class, readonly) Sdk_coreAdUrlMacroType *fwVersion __attribute__((swift_name("fwVersion")));
@property (class, readonly) Sdk_coreAdUrlMacroType *locale __attribute__((swift_name("locale")));
@property (class, readonly) Sdk_coreAdUrlMacroType *assetUri __attribute__((swift_name("assetUri")));
@property (class, readonly) Sdk_coreAdUrlMacroType *timeOut __attribute__((swift_name("timeOut")));
@property (class, readonly) Sdk_coreAdUrlMacroType *clickThrough __attribute__((swift_name("clickThrough")));
+ (Sdk_coreKotlinArray<Sdk_coreAdUrlMacroType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreAdUrlMacroType *> *entries __attribute__((swift_name("entries")));
- (NSString *)replaceUrl:(NSString *)url value:(id _Nullable)value __attribute__((swift_name("replace(url:value:)")));
@property (readonly) NSString *macro __attribute__((swift_name("macro")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdUrlMacroValue")))
@interface Sdk_coreAdUrlMacroValue : Sdk_coreBase
- (instancetype)initWithContentId:(NSString * _Nullable)contentId placementId:(Sdk_coreInt * _Nullable)placementId adDuration:(Sdk_coreLong * _Nullable)adDuration assetUri:(NSString * _Nullable)assetUri errorCode:(NSString * _Nullable)errorCode contentDuration:(Sdk_coreLong * _Nullable)contentDuration contentTaxonomies:(NSString * _Nullable)contentTaxonomies timeout:(Sdk_coreLong * _Nullable)timeout creativeId:(NSString * _Nullable)creativeId clickThrough:(NSString * _Nullable)clickThrough __attribute__((swift_name("init(contentId:placementId:adDuration:assetUri:errorCode:contentDuration:contentTaxonomies:timeout:creativeId:clickThrough:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreAdUrlMacroValue *)doCopyContentId:(NSString * _Nullable)contentId placementId:(Sdk_coreInt * _Nullable)placementId adDuration:(Sdk_coreLong * _Nullable)adDuration assetUri:(NSString * _Nullable)assetUri errorCode:(NSString * _Nullable)errorCode contentDuration:(Sdk_coreLong * _Nullable)contentDuration contentTaxonomies:(NSString * _Nullable)contentTaxonomies timeout:(Sdk_coreLong * _Nullable)timeout creativeId:(NSString * _Nullable)creativeId clickThrough:(NSString * _Nullable)clickThrough __attribute__((swift_name("doCopy(contentId:placementId:adDuration:assetUri:errorCode:contentDuration:contentTaxonomies:timeout:creativeId:clickThrough:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property Sdk_coreLong * _Nullable adDuration __attribute__((swift_name("adDuration")));
@property NSString * _Nullable assetUri __attribute__((swift_name("assetUri")));
@property NSString * _Nullable clickThrough __attribute__((swift_name("clickThrough")));
@property (readonly) Sdk_coreLong * _Nullable contentDuration __attribute__((swift_name("contentDuration")));
@property (readonly) NSString * _Nullable contentId __attribute__((swift_name("contentId")));
@property (readonly) NSString * _Nullable contentTaxonomies __attribute__((swift_name("contentTaxonomies")));
@property NSString * _Nullable creativeId __attribute__((swift_name("creativeId")));
@property NSString * _Nullable errorCode __attribute__((swift_name("errorCode")));
@property Sdk_coreInt * _Nullable placementId __attribute__((swift_name("placementId")));
@property Sdk_coreLong * _Nullable timeout __attribute__((swift_name("timeout")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FillerAdsManager")))
@interface Sdk_coreFillerAdsManager : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreFillerAdsManagerCompanion *companion __attribute__((swift_name("companion")));
- (void)completeContentId:(NSString *)contentId __attribute__((swift_name("complete(contentId:)")));
- (BOOL)containsAdId:(NSString *)adId __attribute__((swift_name("contains(adId:)")));
- (Sdk_coreAd * _Nullable)getAdId:(NSString *)adId __attribute__((swift_name("get(adId:)")));
- (BOOL)isAlreadyCashedContentId:(NSString *)contentId __attribute__((swift_name("isAlreadyCashed(contentId:)")));
- (void)putAdId:(NSString *)adId ad:(Sdk_coreAd *)ad __attribute__((swift_name("put(adId:ad:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FillerAdsManager.Companion")))
@interface Sdk_coreFillerAdsManagerCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreFillerAdsManagerCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("FlowerAdsManager")))
@protocol Sdk_coreFlowerAdsManager
@required
- (void)addListenerAdsManagerListener:(id<Sdk_coreFlowerAdsManagerListener>)adsManagerListener __attribute__((swift_name("addListener(adsManagerListener:)")));
- (void)changeChannelExtraParamsExtraParams:(NSDictionary<NSString *, NSString *> *)extraParams __attribute__((swift_name("changeChannelExtraParams(extraParams:)")));
- (NSString *)changeChannelUrlVideoUrl:(NSString *)videoUrl adTagUrl:(NSString *)adTagUrl channelId:(NSString *)channelId extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook __attribute__((swift_name("changeChannelUrl(videoUrl:adTagUrl:channelId:extraParams:mediaPlayerHook:)")));
- (NSString *)changeChannelUrlVideoUrl:(NSString *)videoUrl adTagUrl:(NSString *)adTagUrl channelId:(NSString *)channelId extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("changeChannelUrl(videoUrl:adTagUrl:channelId:extraParams:mediaPlayerHook:adTagHeaders:)")));
- (NSString *)changeChannelUrlVideoUrl:(NSString *)videoUrl adTagUrl:(NSString *)adTagUrl channelId:(NSString *)channelId extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders channelStreamHeaders:(NSDictionary<NSString *, NSString *> *)channelStreamHeaders __attribute__((swift_name("changeChannelUrl(videoUrl:adTagUrl:channelId:extraParams:mediaPlayerHook:adTagHeaders:channelStreamHeaders:)")));
- (NSString *)changeChannelUrlVideoUrl:(NSString *)videoUrl adTagUrl:(NSString *)adTagUrl channelId:(NSString *)channelId extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders channelStreamHeaders:(NSDictionary<NSString *, NSString *> *)channelStreamHeaders prerollAdTagUrl:(NSString *)prerollAdTagUrl __attribute__((swift_name("changeChannelUrl(videoUrl:adTagUrl:channelId:extraParams:mediaPlayerHook:adTagHeaders:channelStreamHeaders:prerollAdTagUrl:)")));
- (void)notifyContentEnded __attribute__((swift_name("notifyContentEnded()")));
- (void)pause __attribute__((swift_name("pause()")));
- (void)play __attribute__((swift_name("play()")));
- (void)removeListenerAdsManagerListener:(id<Sdk_coreFlowerAdsManagerListener>)adsManagerListener __attribute__((swift_name("removeListener(adsManagerListener:)")));
- (void)requestAdAdTagUrl:(NSString *)adTagUrl extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams __attribute__((swift_name("requestAd(adTagUrl:extraParams:)")));
- (void)requestAdAdTagUrl:(NSString *)adTagUrl extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("requestAd(adTagUrl:extraParams:adTagHeaders:)")));
- (void)requestVodAdAdTagUrl:(NSString *)adTagUrl contentId:(NSString *)contentId durationMs:(int64_t)durationMs extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook __attribute__((swift_name("requestVodAd(adTagUrl:contentId:durationMs:extraParams:mediaPlayerHook:)")));
- (void)requestVodAdAdTagUrl:(NSString *)adTagUrl contentId:(NSString *)contentId durationMs:(int64_t)durationMs extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("requestVodAd(adTagUrl:contentId:durationMs:extraParams:mediaPlayerHook:adTagHeaders:)")));
- (void)resume __attribute__((swift_name("resume()")));
- (void)stop __attribute__((swift_name("stop()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlowerAdsManagerImpl")))
@interface Sdk_coreFlowerAdsManagerImpl : Sdk_coreBase <Sdk_coreFlowerAdsManager>
- (instancetype)initWithFlowerAdView:(id<Sdk_coreFlowerAdViewStub>)flowerAdView adPlayerView:(id<Sdk_coreAdPlayerView>)adPlayerView googleAdView:(id<Sdk_coreGoogleAdView>)googleAdView flowerAdUIView:(id<Sdk_coreFlowerAdUIView>)flowerAdUIView __attribute__((swift_name("init(flowerAdView:adPlayerView:googleAdView:flowerAdUIView:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreFlowerAdsManagerImplCompanion *companion __attribute__((swift_name("companion")));
- (void)addListenerAdsManagerListener:(id<Sdk_coreFlowerAdsManagerListener>)adsManagerListener __attribute__((swift_name("addListener(adsManagerListener:)")));
- (void)changeChannelExtraParamsExtraParams:(NSDictionary<NSString *, NSString *> *)extraParams __attribute__((swift_name("changeChannelExtraParams(extraParams:)")));
- (void)changeChannelExtraParamsImplExtraParams:(NSDictionary<NSString *, NSString *> *)extraParams __attribute__((swift_name("changeChannelExtraParamsImpl(extraParams:)")));
- (NSString *)changeChannelUrlVideoUrl:(NSString *)videoUrl adTagUrl:(NSString *)adTagUrl channelId:(NSString *)channelId extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook __attribute__((swift_name("changeChannelUrl(videoUrl:adTagUrl:channelId:extraParams:mediaPlayerHook:)")));
- (NSString *)changeChannelUrlVideoUrl:(NSString *)videoUrl adTagUrl:(NSString *)adTagUrl channelId:(NSString *)channelId extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("changeChannelUrl(videoUrl:adTagUrl:channelId:extraParams:mediaPlayerHook:adTagHeaders:)")));
- (NSString *)changeChannelUrlVideoUrl:(NSString *)videoUrl adTagUrl:(NSString *)adTagUrl channelId:(NSString *)channelId extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders channelStreamHeaders:(NSDictionary<NSString *, NSString *> *)channelStreamHeaders __attribute__((swift_name("changeChannelUrl(videoUrl:adTagUrl:channelId:extraParams:mediaPlayerHook:adTagHeaders:channelStreamHeaders:)")));
- (NSString *)changeChannelUrlVideoUrl:(NSString *)videoUrl adTagUrl:(NSString *)adTagUrl channelId:(NSString *)channelId extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders channelStreamHeaders:(NSDictionary<NSString *, NSString *> *)channelStreamHeaders prerollAdTagUrl:(NSString *)prerollAdTagUrl __attribute__((swift_name("changeChannelUrl(videoUrl:adTagUrl:channelId:extraParams:mediaPlayerHook:adTagHeaders:channelStreamHeaders:prerollAdTagUrl:)")));
- (NSString *)changeChannelUrlImplVideoUrl:(NSString *)videoUrl adTagUrl:(NSString *)adTagUrl channelId:(NSString *)channelId extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders channelStreamHeaders:(NSDictionary<NSString *, NSString *> *)channelStreamHeaders prerollAdTagUrl:(NSString * _Nullable)prerollAdTagUrl __attribute__((swift_name("changeChannelUrlImpl(videoUrl:adTagUrl:channelId:extraParams:mediaPlayerHook:adTagHeaders:channelStreamHeaders:prerollAdTagUrl:)")));
- (void)notifyContentEnded __attribute__((swift_name("notifyContentEnded()")));
- (void)pause __attribute__((swift_name("pause()")));
- (void)play __attribute__((swift_name("play()")));
- (void)removeListenerAdsManagerListener:(id<Sdk_coreFlowerAdsManagerListener>)adsManagerListener __attribute__((swift_name("removeListener(adsManagerListener:)")));
- (void)requestAdAdTagUrl:(NSString *)adTagUrl extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams __attribute__((swift_name("requestAd(adTagUrl:extraParams:)")));
- (void)requestAdAdTagUrl:(NSString *)adTagUrl extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("requestAd(adTagUrl:extraParams:adTagHeaders:)")));
- (void)requestAdImplAdTagUrl:(NSString *)adTagUrl extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("requestAdImpl(adTagUrl:extraParams:adTagHeaders:)")));
- (NSString *)requestLinearTvAdsDurationMs:(int64_t)durationMs uniqueProgramId:(int32_t)uniqueProgramId adWaitingTime:(int64_t)adWaitingTime adPrefix:(NSString * _Nullable)adPrefix adCallback:(void (^)(Sdk_coreAd *))adCallback completedCallback:(void (^)(void))completedCallback __attribute__((swift_name("requestLinearTvAds(durationMs:uniqueProgramId:adWaitingTime:adPrefix:adCallback:completedCallback:)")));
- (void)requestLinearTvPrerollAdTagUrl:(NSString *)adTagUrl extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("requestLinearTvPreroll(adTagUrl:extraParams:adTagHeaders:)")));
- (void)requestVodAdAdTagUrl:(NSString *)adTagUrl contentId:(NSString *)contentId durationMs:(int64_t)durationMs extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook __attribute__((swift_name("requestVodAd(adTagUrl:contentId:durationMs:extraParams:mediaPlayerHook:)")));
- (void)requestVodAdAdTagUrl:(NSString *)adTagUrl contentId:(NSString *)contentId durationMs:(int64_t)durationMs extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("requestVodAd(adTagUrl:contentId:durationMs:extraParams:mediaPlayerHook:adTagHeaders:)")));
- (void)requestVodAdImplAdTagUrl:(NSString *)adTagUrl contentId:(NSString *)contentId durationMs:(int64_t)durationMs extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams mediaPlayerHook:(id<Sdk_coreMediaPlayerHook>)mediaPlayerHook adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("requestVodAdImpl(adTagUrl:contentId:durationMs:extraParams:mediaPlayerHook:adTagHeaders:)")));
- (void)resume __attribute__((swift_name("resume()")));
- (void)stop __attribute__((swift_name("stop()")));
- (void)stopLinearTvAdTransactionRequestId:(NSString *)requestId __attribute__((swift_name("stopLinearTvAdTransaction(requestId:)")));
@property Sdk_coreFlowerAdsManagerListeners *adsManagerListeners __attribute__((swift_name("adsManagerListeners")));
@property BOOL isSkipTracking __attribute__((swift_name("isSkipTracking")));
@property id<Sdk_coreMediaPlayerAdapter> _Nullable mediaPlayerAdapter __attribute__((swift_name("mediaPlayerAdapter")));
@property id<Sdk_coreMediaPlayerHook> _Nullable mediaPlayerHook __attribute__((swift_name("mediaPlayerHook")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlowerAdsManagerImpl.Companion")))
@interface Sdk_coreFlowerAdsManagerImplCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreFlowerAdsManagerImplCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("FlowerAdsManagerListener")))
@protocol Sdk_coreFlowerAdsManagerListener
@required
- (void)onAdSkippedReason:(int32_t)reason __attribute__((swift_name("onAdSkipped(reason:)")));
- (void)onCompleted __attribute__((swift_name("onCompleted()")));
- (void)onErrorError:(Sdk_coreFlowerError * _Nullable)error __attribute__((swift_name("onError(error:)")));
- (void)onPlay __attribute__((swift_name("onPlay()")));
- (void)onPrepareAdDurationMs:(int32_t)adDurationMs __attribute__((swift_name("onPrepare(adDurationMs:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlowerAdsManagerListeners")))
@interface Sdk_coreFlowerAdsManagerListeners : Sdk_coreBase <Sdk_coreFlowerAdsManagerListener>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreFlowerAdsManagerListenersCompanion *companion __attribute__((swift_name("companion")));
- (void)addListenerListener:(id<Sdk_coreFlowerAdsManagerListener>)listener __attribute__((swift_name("addListener(listener:)")));
- (void)clear __attribute__((swift_name("clear()")));
- (void)onAdSkippedReason:(int32_t)reason __attribute__((swift_name("onAdSkipped(reason:)")));
- (void)onCompleted __attribute__((swift_name("onCompleted()")));
- (void)onErrorError:(Sdk_coreFlowerError * _Nullable)error __attribute__((swift_name("onError(error:)")));
- (void)onPlay __attribute__((swift_name("onPlay()")));
- (void)onPrepareAdDurationMs:(int32_t)adDurationMs __attribute__((swift_name("onPrepare(adDurationMs:)")));
- (void)removeListenerListener:(id<Sdk_coreFlowerAdsManagerListener>)listener __attribute__((swift_name("removeListener(listener:)")));
- (Sdk_corePlatformList<id<Sdk_coreFlowerAdsManagerListener>> *)toPlatformList __attribute__((swift_name("toPlatformList()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlowerAdsManagerListeners.Companion")))
@interface Sdk_coreFlowerAdsManagerListenersCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreFlowerAdsManagerListenersCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LinearTVAdHandler")))
@interface Sdk_coreLinearTVAdHandler : Sdk_coreAdHandler
- (instancetype)initWithFlowerAdView:(id<Sdk_coreFlowerAdViewStub>)flowerAdView adPlayerView:(id<Sdk_coreAdPlayerView>)adPlayerView googleAdView:(id<Sdk_coreGoogleAdView>)googleAdView flowerAdUIView:(id<Sdk_coreFlowerAdUIView>)flowerAdUIView adsManagerListener:(id<Sdk_coreFlowerAdsManagerListener>)adsManagerListener mediaPlayerAdapter:(id<Sdk_coreMediaPlayerAdapter>)mediaPlayerAdapter __attribute__((swift_name("init(flowerAdView:adPlayerView:googleAdView:flowerAdUIView:adsManagerListener:mediaPlayerAdapter:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithFlowerAdView:(id<Sdk_coreFlowerAdViewStub>)flowerAdView adPlayerView:(id<Sdk_coreAdPlayerView>)adPlayerView googleAdView:(id<Sdk_coreGoogleAdView>)googleAdView flowerAdUIView:(id<Sdk_coreFlowerAdUIView>)flowerAdUIView adsManagerListener:(id<Sdk_coreFlowerAdsManagerListener>)adsManagerListener __attribute__((swift_name("init(flowerAdView:adPlayerView:googleAdView:flowerAdUIView:adsManagerListener:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreLinearTVAdHandlerCompanion *companion __attribute__((swift_name("companion")));
- (void)changeChannelExtraParamsExtraParams:(NSDictionary<NSString *, id> *)extraParams __attribute__((swift_name("changeChannelExtraParams(extraParams:)")));
- (NSString *)changeChannelUrlVideoUrl:(NSString *)videoUrl adTagUrl:(NSString *)adTagUrl adUrlMacroValue:(Sdk_coreAdUrlMacroValue *)adUrlMacroValue extraParams:(NSDictionary<NSString *, id> * _Nullable)extraParams adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders channelStreamHeaders:(NSDictionary<NSString *, NSString *> *)channelStreamHeaders __attribute__((swift_name("changeChannelUrl(videoUrl:adTagUrl:adUrlMacroValue:extraParams:adTagHeaders:channelStreamHeaders:)")));
- (void)destroy __attribute__((swift_name("destroy()")));
- (NSString *)requestAdsAdDuration:(int64_t)adDuration uniqueProgramId:(int32_t)uniqueProgramId adWaitingTime:(int64_t)adWaitingTime adPrefix:(NSString * _Nullable)adPrefix adCallback:(void (^)(Sdk_coreAd *))adCallback completedCallback:(void (^)(void))completedCallback __attribute__((swift_name("requestAds(adDuration:uniqueProgramId:adWaitingTime:adPrefix:adCallback:completedCallback:)")));
- (void)stopRequestTransactionRequestId:(NSString *)requestId __attribute__((swift_name("stopRequestTransaction(requestId:)")));
@property int64_t adAppendDifference __attribute__((swift_name("adAppendDifference")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LinearTVAdHandler.AdHandlerAndJobs")))
@interface Sdk_coreLinearTVAdHandlerAdHandlerAndJobs : Sdk_coreBase
- (instancetype)initWithRequestId:(NSString *)requestId adHandler:(Sdk_coreAdHandler *)adHandler playingCheckJob:(id<Sdk_coreKotlinx_coroutines_coreJob> _Nullable)playingCheckJob wrapperWaitingJob:(id<Sdk_coreKotlinx_coroutines_coreJob> _Nullable)wrapperWaitingJob __attribute__((swift_name("init(requestId:adHandler:playingCheckJob:wrapperWaitingJob:)"))) __attribute__((objc_designated_initializer));
- (void)destroy __attribute__((swift_name("destroy()")));
@property (readonly) Sdk_coreAdHandler *adHandler __attribute__((swift_name("adHandler")));
@property id<Sdk_coreKotlinx_coroutines_coreJob> _Nullable playingCheckJob __attribute__((swift_name("playingCheckJob")));
@property (readonly) NSString *requestId __attribute__((swift_name("requestId")));
@property id<Sdk_coreKotlinx_coroutines_coreJob> _Nullable wrapperWaitingJob __attribute__((swift_name("wrapperWaitingJob")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LinearTVAdHandler.Companion")))
@interface Sdk_coreLinearTVAdHandlerCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreLinearTVAdHandlerCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("AdPlayerCallback")))
@protocol Sdk_coreAdPlayerCallback
@required
- (void)onErrorMediaUrl:(NSString * _Nullable)mediaUrl t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("onError(mediaUrl:t:)")));
- (void)onLoadedMediaUrl:(NSString * _Nullable)mediaUrl duration:(int32_t)duration __attribute__((swift_name("onLoaded(mediaUrl:duration:)")));
- (void)onPauseMediaUrl:(NSString * _Nullable)mediaUrl __attribute__((swift_name("onPause(mediaUrl:)")));
- (void)onPlayMediaUrl:(NSString * _Nullable)mediaUrl __attribute__((swift_name("onPlay(mediaUrl:)")));
- (void)onResumeMediaUrl:(NSString * _Nullable)mediaUrl __attribute__((swift_name("onResume(mediaUrl:)")));
- (void)onStopped __attribute__((swift_name("onStopped()")));
@end

__attribute__((swift_name("NormalAdHandler")))
@interface Sdk_coreNormalAdHandler : Sdk_coreAdHandler <Sdk_coreAdPlayerCallback>
- (instancetype)initWithFlowerAdView:(id<Sdk_coreFlowerAdViewStub>)flowerAdView adPlayerView:(id<Sdk_coreAdPlayerView>)adPlayerView googleAdView:(id<Sdk_coreGoogleAdView>)googleAdView flowerAdUIView:(id<Sdk_coreFlowerAdUIView>)flowerAdUIView adsManagerListener:(id<Sdk_coreFlowerAdsManagerListener>)adsManagerListener __attribute__((swift_name("init(flowerAdView:adPlayerView:googleAdView:flowerAdUIView:adsManagerListener:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreNormalAdHandlerCompanion *companion __attribute__((swift_name("companion")));
- (void)destroy __attribute__((swift_name("destroy()")));
- (void)onErrorMediaUrl:(NSString * _Nullable)mediaUrl t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("onError(mediaUrl:t:)")));
- (void)onLoadedMediaUrl:(NSString * _Nullable)mediaUrl duration:(int32_t)duration __attribute__((swift_name("onLoaded(mediaUrl:duration:)")));
- (void)onPauseMediaUrl:(NSString * _Nullable)mediaUrl __attribute__((swift_name("onPause(mediaUrl:)")));
- (void)onPlayMediaUrl:(NSString * _Nullable)mediaUrl __attribute__((swift_name("onPlay(mediaUrl:)")));
- (void)onResumeMediaUrl:(NSString * _Nullable)mediaUrl __attribute__((swift_name("onResume(mediaUrl:)")));
- (void)onStopped __attribute__((swift_name("onStopped()")));
- (void)pause __attribute__((swift_name("pause()")));
- (void)play __attribute__((swift_name("play()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)requestDisplayAdAdTagUri:(NSString *)adTagUri timeoutMillis:(int64_t)timeoutMillis __attribute__((swift_name("requestDisplayAd(adTagUri:timeoutMillis:)")));
- (void)requestVideoAdAdTagUrl:(NSString *)adTagUrl extraParams:(NSDictionary<NSString *, id> * _Nullable)extraParams timeout:(int64_t)timeout macro:(Sdk_coreAdUrlMacroValue *)macro adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("requestVideoAd(adTagUrl:extraParams:timeout:macro:adTagHeaders:)")));
- (void)resume __attribute__((swift_name("resume()")));
- (void)stop __attribute__((swift_name("stop()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NormalAdHandler.Companion")))
@interface Sdk_coreNormalAdHandlerCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreNormalAdHandlerCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) int64_t REQUEST_TIMEOUT __attribute__((swift_name("REQUEST_TIMEOUT")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VastParser")))
@interface Sdk_coreVastParser : Sdk_coreBase
- (instancetype)initWithAdUrlMacroValue:(Sdk_coreAdUrlMacroValue *)adUrlMacroValue adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders adPrefix:(NSString * _Nullable)adPrefix __attribute__((swift_name("init(adUrlMacroValue:adTagHeaders:adPrefix:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreVastParserCompanion *companion __attribute__((swift_name("companion")));
- (id<Sdk_coreKotlinx_coroutines_coreFlow>)parseText:(NSString *)text timeoutMillis:(int64_t)timeoutMillis preloadManifest:(BOOL)preloadManifest __attribute__((swift_name("parse(text:timeoutMillis:preloadManifest:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VastParser.Companion")))
@interface Sdk_coreVastParserCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreVastParserCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VmapParser")))
@interface Sdk_coreVmapParser : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreVmapParserCompanion *companion __attribute__((swift_name("companion")));
- (NSArray<Sdk_coreAdBreak *> *)parseText:(NSString *)text contentDuration:(int64_t)contentDuration __attribute__((swift_name("parse(text:contentDuration:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VmapParser.Companion")))
@interface Sdk_coreVmapParserCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreVmapParserCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VodAdHandler")))
@interface Sdk_coreVodAdHandler : Sdk_coreNormalAdHandler
- (instancetype)initWithFlowerAdView:(id<Sdk_coreFlowerAdViewStub>)flowerAdView adPlayerView:(id<Sdk_coreAdPlayerView>)adPlayerView googleAdView:(id<Sdk_coreGoogleAdView>)googleAdView flowerAdUIView:(id<Sdk_coreFlowerAdUIView>)flowerAdUIView adsManagerListener:(id<Sdk_coreFlowerAdsManagerListener>)adsManagerListener mediaPlayerAdapter:(id<Sdk_coreMediaPlayerAdapter>)mediaPlayerAdapter __attribute__((swift_name("init(flowerAdView:adPlayerView:googleAdView:flowerAdUIView:adsManagerListener:mediaPlayerAdapter:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithFlowerAdView:(id<Sdk_coreFlowerAdViewStub>)flowerAdView adPlayerView:(id<Sdk_coreAdPlayerView>)adPlayerView googleAdView:(id<Sdk_coreGoogleAdView>)googleAdView flowerAdUIView:(id<Sdk_coreFlowerAdUIView>)flowerAdUIView adsManagerListener:(id<Sdk_coreFlowerAdsManagerListener>)adsManagerListener __attribute__((swift_name("init(flowerAdView:adPlayerView:googleAdView:flowerAdUIView:adsManagerListener:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreVodAdHandlerCompanion *companion __attribute__((swift_name("companion")));
- (void)destroy __attribute__((swift_name("destroy()")));
- (void)notifyContentEnded __attribute__((swift_name("notifyContentEnded()")));
- (void)requestVodAdAdTagUrl:(NSString *)adTagUrl adUrlMacroValue:(Sdk_coreAdUrlMacroValue *)adUrlMacroValue extraParams:(NSDictionary<NSString *, NSString *> * _Nullable)extraParams adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders __attribute__((swift_name("requestVodAd(adTagUrl:adUrlMacroValue:extraParams:adTagHeaders:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VodAdHandler.Companion")))
@interface Sdk_coreVodAdHandlerCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreVodAdHandlerCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) int64_t VOD_REQUEST_TIMEOUT __attribute__((swift_name("VOD_REQUEST_TIMEOUT")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ad")))
@interface Sdk_coreAd : Sdk_coreBase
- (instancetype)initWithId:(NSString * _Nullable)id creatives:(NSArray<Sdk_coreCreative *> *)creatives trackingUrls:(Sdk_coreMutableDictionary<Sdk_coreAdTrackingEvent *, NSMutableArray<NSString *> *> *)trackingUrls duration:(int64_t)duration skipDuration:(int64_t)skipDuration progressTrackingUrls:(Sdk_coreMutableDictionary<Sdk_coreLong *, NSMutableArray<NSString *> *> *)progressTrackingUrls click:(Sdk_coreAdClick * _Nullable)click companionAds:(NSArray<Sdk_coreAd *> *)companionAds isFiller:(BOOL)isFiller isWrapper:(BOOL)isWrapper adUrlMacroValue:(Sdk_coreAdUrlMacroValue *)adUrlMacroValue adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders url:(NSString * _Nullable)url isGoogle:(BOOL)isGoogle fallbackUrl:(NSString * _Nullable)fallbackUrl isFallbackGoogle:(BOOL)isFallbackGoogle adNetworkId:(int64_t)adNetworkId deviceId:(int64_t)deviceId deviceTypeId:(int32_t)deviceTypeId placementId:(int64_t)placementId transactionId:(NSString *)transactionId minReqDuration:(int64_t)minReqDuration assetProfileIds:(NSArray<Sdk_coreLong *> *)assetProfileIds beaconRetryCount:(Sdk_coreInt * _Nullable)beaconRetryCount preloadManifest:(BOOL)preloadManifest __attribute__((swift_name("init(id:creatives:trackingUrls:duration:skipDuration:progressTrackingUrls:click:companionAds:isFiller:isWrapper:adUrlMacroValue:adTagHeaders:url:isGoogle:fallbackUrl:isFallbackGoogle:adNetworkId:deviceId:deviceTypeId:placementId:transactionId:minReqDuration:assetProfileIds:beaconRetryCount:preloadManifest:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreAdCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreAd *)doCopyId:(NSString * _Nullable)id creatives:(NSArray<Sdk_coreCreative *> *)creatives trackingUrls:(Sdk_coreMutableDictionary<Sdk_coreAdTrackingEvent *, NSMutableArray<NSString *> *> *)trackingUrls duration:(int64_t)duration skipDuration:(int64_t)skipDuration progressTrackingUrls:(Sdk_coreMutableDictionary<Sdk_coreLong *, NSMutableArray<NSString *> *> *)progressTrackingUrls click:(Sdk_coreAdClick * _Nullable)click companionAds:(NSArray<Sdk_coreAd *> *)companionAds isFiller:(BOOL)isFiller isWrapper:(BOOL)isWrapper adUrlMacroValue:(Sdk_coreAdUrlMacroValue *)adUrlMacroValue adTagHeaders:(NSDictionary<NSString *, NSString *> *)adTagHeaders url:(NSString * _Nullable)url isGoogle:(BOOL)isGoogle fallbackUrl:(NSString * _Nullable)fallbackUrl isFallbackGoogle:(BOOL)isFallbackGoogle adNetworkId:(int64_t)adNetworkId deviceId:(int64_t)deviceId deviceTypeId:(int32_t)deviceTypeId placementId:(int64_t)placementId transactionId:(NSString *)transactionId minReqDuration:(int64_t)minReqDuration assetProfileIds:(NSArray<Sdk_coreLong *> *)assetProfileIds beaconRetryCount:(Sdk_coreInt * _Nullable)beaconRetryCount preloadManifest:(BOOL)preloadManifest __attribute__((swift_name("doCopy(id:creatives:trackingUrls:duration:skipDuration:progressTrackingUrls:click:companionAds:isFiller:isWrapper:adUrlMacroValue:adTagHeaders:url:isGoogle:fallbackUrl:isFallbackGoogle:adNetworkId:deviceId:deviceTypeId:placementId:transactionId:minReqDuration:assetProfileIds:beaconRetryCount:preloadManifest:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (Sdk_coreCreative *)getDashCreative __attribute__((swift_name("getDashCreative()")));
- (Sdk_coreCreative * _Nullable)getDashCreativeOrNull __attribute__((swift_name("getDashCreativeOrNull()")));
- (Sdk_coreCreative * _Nullable)getFitCreativeAdPlayerView:(id<Sdk_coreAdPlayerView>)adPlayerView __attribute__((swift_name("getFitCreative(adPlayerView:)")));
- (Sdk_coreCreative *)getHlsCreative __attribute__((swift_name("getHlsCreative()")));
- (Sdk_coreCreative * _Nullable)getHlsCreativeOrNull __attribute__((swift_name("getHlsCreativeOrNull()")));
- (Sdk_coreCreative *)getSingleMediaCreative __attribute__((swift_name("getSingleMediaCreative()")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (Sdk_coreCreative *)resolveOverlayVideoCreative __attribute__((swift_name("resolveOverlayVideoCreative()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t adNetworkId __attribute__((swift_name("adNetworkId")));
@property (readonly) NSDictionary<NSString *, NSString *> *adTagHeaders __attribute__((swift_name("adTagHeaders")));
@property (readonly) Sdk_coreAdUrlMacroValue *adUrlMacroValue __attribute__((swift_name("adUrlMacroValue")));
@property (readonly) NSArray<Sdk_coreLong *> *assetProfileIds __attribute__((swift_name("assetProfileIds")));
@property Sdk_coreInt * _Nullable beaconRetryCount __attribute__((swift_name("beaconRetryCount")));
@property (readonly) Sdk_coreAdClick * _Nullable click __attribute__((swift_name("click")));
@property NSArray<Sdk_coreAd *> *companionAds __attribute__((swift_name("companionAds")));
@property (readonly) NSArray<Sdk_coreCreative *> *creatives __attribute__((swift_name("creatives")));
@property (readonly) int64_t deviceId __attribute__((swift_name("deviceId")));
@property (readonly) int32_t deviceTypeId __attribute__((swift_name("deviceTypeId")));
@property int64_t duration __attribute__((swift_name("duration")));
@property NSString * _Nullable fallbackUrl __attribute__((swift_name("fallbackUrl")));
@property NSString * _Nullable id __attribute__((swift_name("id")));
@property BOOL isFallbackGoogle __attribute__((swift_name("isFallbackGoogle")));
@property (readonly) BOOL isFiller __attribute__((swift_name("isFiller")));
@property BOOL isFinished __attribute__((swift_name("isFinished")));
@property BOOL isGoogle __attribute__((swift_name("isGoogle")));
@property (readonly) BOOL isWrapper __attribute__((swift_name("isWrapper")));
@property Sdk_coreCacheAdMediaSegmentServiceAdMediaSegment * _Nullable mediaSegment __attribute__((swift_name("mediaSegment")));
@property (readonly) int64_t minReqDuration __attribute__((swift_name("minReqDuration")));
@property (readonly) int64_t placementId __attribute__((swift_name("placementId")));
@property (readonly) BOOL preloadManifest __attribute__((swift_name("preloadManifest")));
@property (readonly) Sdk_coreMutableDictionary<Sdk_coreLong *, NSMutableArray<NSString *> *> *progressTrackingUrls __attribute__((swift_name("progressTrackingUrls")));
@property int64_t skipDuration __attribute__((swift_name("skipDuration")));
@property (readonly) Sdk_coreMutableDictionary<Sdk_coreAdTrackingEvent *, NSMutableArray<NSString *> *> *trackingUrls __attribute__((swift_name("trackingUrls")));
@property (readonly) NSString *transactionId __attribute__((swift_name("transactionId")));
@property NSString * _Nullable url __attribute__((swift_name("url")));
@property int32_t wrapperDepth __attribute__((swift_name("wrapperDepth")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ad.Click")))
@interface Sdk_coreAdClick : Sdk_coreBase
- (instancetype)initWithClickThroughUrl:(NSString * _Nullable)clickThroughUrl clickTrackingUrls:(NSArray<NSString *> *)clickTrackingUrls __attribute__((swift_name("init(clickThroughUrl:clickTrackingUrls:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString * _Nullable clickThroughUrl __attribute__((swift_name("clickThroughUrl")));
@property NSArray<NSString *> *clickTrackingUrls __attribute__((swift_name("clickTrackingUrls")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ad.Companion")))
@interface Sdk_coreAdCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreAdCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ad.TrackingEvent")))
@interface Sdk_coreAdTrackingEvent : Sdk_coreKotlinEnum<Sdk_coreAdTrackingEvent *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreAdTrackingEvent *impression __attribute__((swift_name("impression")));
@property (class, readonly) Sdk_coreAdTrackingEvent *firstquartile __attribute__((swift_name("firstquartile")));
@property (class, readonly) Sdk_coreAdTrackingEvent *midpoint __attribute__((swift_name("midpoint")));
@property (class, readonly) Sdk_coreAdTrackingEvent *thirdquartile __attribute__((swift_name("thirdquartile")));
@property (class, readonly) Sdk_coreAdTrackingEvent *complete __attribute__((swift_name("complete")));
@property (class, readonly) Sdk_coreAdTrackingEvent *start __attribute__((swift_name("start")));
@property (class, readonly) Sdk_coreAdTrackingEvent *error __attribute__((swift_name("error")));
@property (class, readonly) Sdk_coreAdTrackingEvent *progress __attribute__((swift_name("progress")));
@property (class, readonly) Sdk_coreAdTrackingEvent *skip __attribute__((swift_name("skip")));
@property (class, readonly) Sdk_coreAdTrackingEvent *creativeview __attribute__((swift_name("creativeview")));
@property (class, readonly) Sdk_coreAdTrackingEvent *close __attribute__((swift_name("close")));
@property (class, readonly) Sdk_coreAdTrackingEvent *fullscreen __attribute__((swift_name("fullscreen")));
+ (Sdk_coreKotlinArray<Sdk_coreAdTrackingEvent *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreAdTrackingEvent *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdBreak")))
@interface Sdk_coreAdBreak : Sdk_coreBase
- (instancetype)initWithBreakId:(NSString *)breakId timeOffset:(int64_t)timeOffset adTagUri:(NSString *)adTagUri __attribute__((swift_name("init(breakId:timeOffset:adTagUri:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreAdBreak *)doCopyBreakId:(NSString *)breakId timeOffset:(int64_t)timeOffset adTagUri:(NSString *)adTagUri __attribute__((swift_name("doCopy(breakId:timeOffset:adTagUri:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *adTagUri __attribute__((swift_name("adTagUri")));
@property (readonly) NSString *breakId __attribute__((swift_name("breakId")));
@property (readonly) int64_t timeOffset __attribute__((swift_name("timeOffset")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdList")))
@interface Sdk_coreAdList : Sdk_coreBase
- (instancetype)initWithAds:(NSMutableArray<Sdk_coreAd *> *)ads fillerAds:(NSMutableArray<Sdk_coreAd *> *)fillerAds wrapperAds:(NSMutableArray<Sdk_coreAd *> *)wrapperAds __attribute__((swift_name("init(ads:fillerAds:wrapperAds:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSMutableArray<Sdk_coreAd *> *ads __attribute__((swift_name("ads")));
@property (readonly) NSMutableArray<Sdk_coreAd *> *fillerAds __attribute__((swift_name("fillerAds")));
@property (readonly) NSMutableArray<Sdk_coreAd *> *wrapperAds __attribute__((swift_name("wrapperAds")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConvertCreativeRequest")))
@interface Sdk_coreConvertCreativeRequest : Sdk_coreBase
- (instancetype)initWithMediaId:(NSString * _Nullable)mediaId mediaUrl:(NSString *)mediaUrl creativeId:(NSString * _Nullable)creativeId placementId:(int64_t)placementId encodingType:(NSString *)encodingType playType:(NSString *)playType protocol:(NSString *)protocol extPlatformMappingId:(int64_t)extPlatformMappingId deviceId:(int64_t)deviceId deviceTypeId:(int32_t)deviceTypeId zipCode:(NSString * _Nullable)zipCode price:(double)price priceModel:(NSString * _Nullable)priceModel priceCurrency:(NSString *)priceCurrency contentVendorId:(NSString * _Nullable)contentVendorId extCallbackUrl:(NSString * _Nullable)extCallbackUrl cachedAssetIds:(NSArray<Sdk_coreLong *> *)cachedAssetIds assetProfileIds:(NSArray<Sdk_coreLong *> *)assetProfileIds __attribute__((swift_name("init(mediaId:mediaUrl:creativeId:placementId:encodingType:playType:protocol:extPlatformMappingId:deviceId:deviceTypeId:zipCode:price:priceModel:priceCurrency:contentVendorId:extCallbackUrl:cachedAssetIds:assetProfileIds:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreConvertCreativeRequestCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSArray<Sdk_coreLong *> *assetProfileIds __attribute__((swift_name("assetProfileIds")));
@property (readonly) NSArray<Sdk_coreLong *> *cachedAssetIds __attribute__((swift_name("cachedAssetIds")));
@property (readonly) NSString * _Nullable contentVendorId __attribute__((swift_name("contentVendorId")));
@property (readonly) NSString * _Nullable creativeId __attribute__((swift_name("creativeId")));
@property (readonly) int64_t deviceId __attribute__((swift_name("deviceId")));
@property (readonly) int32_t deviceTypeId __attribute__((swift_name("deviceTypeId")));
@property (readonly) NSString *encodingType __attribute__((swift_name("encodingType")));
@property (readonly) NSString * _Nullable extCallbackUrl __attribute__((swift_name("extCallbackUrl")));
@property (readonly) int64_t extPlatformMappingId __attribute__((swift_name("extPlatformMappingId")));
@property (readonly) NSString * _Nullable mediaId __attribute__((swift_name("mediaId")));
@property (readonly) NSString *mediaUrl __attribute__((swift_name("mediaUrl")));
@property (readonly) int64_t placementId __attribute__((swift_name("placementId")));
@property (readonly) NSString *playType __attribute__((swift_name("playType")));
@property (readonly) double price __attribute__((swift_name("price")));
@property (readonly) NSString *priceCurrency __attribute__((swift_name("priceCurrency")));
@property (readonly) NSString * _Nullable priceModel __attribute__((swift_name("priceModel")));
@property (readonly) NSString *protocol __attribute__((swift_name("protocol")));
@property (readonly) NSString * _Nullable zipCode __attribute__((swift_name("zipCode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConvertCreativeRequest.Companion")))
@interface Sdk_coreConvertCreativeRequestCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreConvertCreativeRequestCompanion *shared __attribute__((swift_name("shared")));
- (id<Sdk_coreKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Creative")))
@interface Sdk_coreCreative : Sdk_coreBase
- (instancetype)initWithId:(NSString *)id type:(NSString *)type width:(int32_t)width height:(int32_t)height m3u8s:(NSArray<Sdk_coreKotlinPair<Sdk_coreVariant *, Sdk_coreMediaPlaylist *> *> *)m3u8s mpd:(Sdk_coreMPD * _Nullable)mpd mediaUrl:(NSString *)mediaUrl duration:(Sdk_coreLong * _Nullable)duration __attribute__((swift_name("init(id:type:width:height:m3u8s:mpd:mediaUrl:duration:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreCreative *)doCopyId:(NSString *)id type:(NSString *)type width:(int32_t)width height:(int32_t)height m3u8s:(NSArray<Sdk_coreKotlinPair<Sdk_coreVariant *, Sdk_coreMediaPlaylist *> *> *)m3u8s mpd:(Sdk_coreMPD * _Nullable)mpd mediaUrl:(NSString *)mediaUrl duration:(Sdk_coreLong * _Nullable)duration __attribute__((swift_name("doCopy(id:type:width:height:m3u8s:mpd:mediaUrl:duration:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) double aspectRatio __attribute__((swift_name("aspectRatio")));
@property (readonly) Sdk_coreLong * _Nullable duration __attribute__((swift_name("duration")));
@property int32_t height __attribute__((swift_name("height")));
@property NSString *id __attribute__((swift_name("id")));
@property NSArray<Sdk_coreKotlinPair<Sdk_coreVariant *, Sdk_coreMediaPlaylist *> *> *m3u8s __attribute__((swift_name("m3u8s")));
@property NSString *mediaUrl __attribute__((swift_name("mediaUrl")));
@property Sdk_coreMPD * _Nullable mpd __attribute__((swift_name("mpd")));
@property NSString *type __attribute__((swift_name("type")));
@property int32_t width __attribute__((swift_name("width")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreativeResponse")))
@interface Sdk_coreCreativeResponse : Sdk_coreBase
- (instancetype)initWithCreativeId:(int64_t)creativeId integrationId:(NSString *)integrationId assets:(NSArray<Sdk_coreCreativeResponseAsset *> *)assets __attribute__((swift_name("init(creativeId:integrationId:assets:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreCreativeResponseCompanion *companion __attribute__((swift_name("companion")));
@property NSArray<Sdk_coreCreativeResponseAsset *> *assets __attribute__((swift_name("assets")));
@property (readonly) int64_t creativeId __attribute__((swift_name("creativeId")));
@property (readonly) NSString *integrationId __attribute__((swift_name("integrationId")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreativeResponse.Asset")))
@interface Sdk_coreCreativeResponseAsset : Sdk_coreBase
- (instancetype)initWithCrc:(NSString *)crc mediaUrl:(NSString *)mediaUrl duration:(int32_t)duration bytes:(int64_t)bytes playType:(NSString *)playType extendedQueryString:(NSString *)extendedQueryString assetProfileId:(int64_t)assetProfileId width:(int32_t)width height:(int32_t)height __attribute__((swift_name("init(crc:mediaUrl:duration:bytes:playType:extendedQueryString:assetProfileId:width:height:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreCreativeResponseAssetCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) int64_t assetProfileId __attribute__((swift_name("assetProfileId")));
@property (readonly) int64_t bytes __attribute__((swift_name("bytes")));
@property (readonly) NSString *crc __attribute__((swift_name("crc")));
@property (readonly) int32_t duration __attribute__((swift_name("duration")));
@property (readonly) NSString *extendedQueryString __attribute__((swift_name("extendedQueryString")));
@property (readonly) int32_t height __attribute__((swift_name("height")));
@property (readonly) NSString *mediaUrl __attribute__((swift_name("mediaUrl")));
@property (readonly) NSString *playType __attribute__((swift_name("playType")));
@property (readonly) int32_t width __attribute__((swift_name("width")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreativeResponse.AssetCompanion")))
@interface Sdk_coreCreativeResponseAssetCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreCreativeResponseAssetCompanion *shared __attribute__((swift_name("shared")));
- (id<Sdk_coreKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreativeResponse.Companion")))
@interface Sdk_coreCreativeResponseCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreCreativeResponseCompanion *shared __attribute__((swift_name("shared")));
- (id<Sdk_coreKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreativeType")))
@interface Sdk_coreCreativeType : Sdk_coreKotlinEnum<Sdk_coreCreativeType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreCreativeTypeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreCreativeType *hls __attribute__((swift_name("hls")));
@property (class, readonly) Sdk_coreCreativeType *dash __attribute__((swift_name("dash")));
@property (class, readonly) Sdk_coreCreativeType *mp4 __attribute__((swift_name("mp4")));
@property (class, readonly) Sdk_coreCreativeType *webm __attribute__((swift_name("webm")));
@property (class, readonly) Sdk_coreCreativeType *mp2t __attribute__((swift_name("mp2t")));
+ (Sdk_coreKotlinArray<Sdk_coreCreativeType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreCreativeType *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreativeType.Companion")))
@interface Sdk_coreCreativeTypeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreCreativeTypeCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreCreativeType * _Nullable)fromUrlUrlString:(NSString *)urlString __attribute__((swift_name("fromUrl(urlString:)")));
@end

__attribute__((swift_name("UIElement")))
@protocol Sdk_coreUIElement
@required
- (int32_t)getHeight __attribute__((swift_name("getHeight()")));
- (int32_t)getWidth __attribute__((swift_name("getWidth()")));
- (void)hide __attribute__((swift_name("hide()")));
- (BOOL)isShow __attribute__((swift_name("isShow()")));
- (void)show __attribute__((swift_name("show()")));
@end

__attribute__((swift_name("FlowerAdUIView")))
@protocol Sdk_coreFlowerAdUIView <Sdk_coreUIElement>
@required
- (void)hideClickUiAd_:(Sdk_coreAd *)ad __attribute__((swift_name("hideClickUi(ad_:)")));
- (void)showClickUiAd:(Sdk_coreAd *)ad postClick:(void (^)(void))postClick __attribute__((swift_name("showClickUi(ad:postClick:)")));
@property (readonly) BOOL isShowingQR __attribute__((swift_name("isShowingQR")));
@end

__attribute__((swift_name("FlowerAdViewStub")))
@protocol Sdk_coreFlowerAdViewStub <Sdk_coreUIElement>
@required
@property (readonly) id<Sdk_coreFlowerAdsManager> adsManager __attribute__((swift_name("adsManager")));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface Sdk_coreKotlinRuntimeException : Sdk_coreKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlowerError")))
@interface Sdk_coreFlowerError : Sdk_coreKotlinRuntimeException
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Media")))
@interface Sdk_coreMedia : Sdk_coreBase
- (instancetype)initWithUrl:(NSString *)url duration:(int32_t)duration position:(int32_t)position __attribute__((swift_name("init(url:duration:position:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreMedia *)doCopyUrl:(NSString *)url duration:(int32_t)duration position:(int32_t)position __attribute__((swift_name("doCopy(url:duration:position:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t duration __attribute__((swift_name("duration")));
@property (readonly) int32_t position __attribute__((swift_name("position")));
@property (readonly) NSString *url __attribute__((swift_name("url")));
@end

__attribute__((swift_name("MediaChunkStub")))
@protocol Sdk_coreMediaChunkStub
@required
@property int32_t currentPosition __attribute__((swift_name("currentPosition")));
@property NSString * _Nullable periodId __attribute__((swift_name("periodId")));
@property NSString * _Nullable url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaChunk")))
@interface Sdk_coreMediaChunk : Sdk_coreBase <Sdk_coreMediaChunkStub>
- (instancetype)initWithCurrentPosition:(int32_t)currentPosition url:(NSString * _Nullable)url periodId:(NSString * _Nullable)periodId __attribute__((swift_name("init(currentPosition:url:periodId:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreMediaChunk *)doCopyCurrentPosition:(int32_t)currentPosition url:(NSString * _Nullable)url periodId:(NSString * _Nullable)periodId __attribute__((swift_name("doCopy(currentPosition:url:periodId:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property int32_t currentPosition __attribute__((swift_name("currentPosition")));
@property NSString * _Nullable periodId __attribute__((swift_name("periodId")));
@property NSString * _Nullable url __attribute__((swift_name("url")));
@end

__attribute__((swift_name("MediaPlayerAdapter")))
@protocol Sdk_coreMediaPlayerAdapter
@required

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (BOOL)enqueueMediaPlayerItem:(Sdk_coreMediaPlayerItem *)mediaPlayerItem error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("enqueue(mediaPlayerItem:)")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (Sdk_coreMedia * _Nullable)getCurrentMediaAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("getCurrentMedia()")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (id<Sdk_coreMediaChunkStub> _Nullable)getCurrentMediaChunkAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("getCurrentMediaChunk()")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (Sdk_coreKotlinWrapped<Sdk_coreInt *> * _Nullable)getCurrentPositionAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("getCurrentPosition()")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (Sdk_coreKotlinWrapped<Sdk_coreInt *> * _Nullable)getHeightAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("getHeight_()")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (Sdk_coreKotlinWrapped<Sdk_coreFloat *> * _Nullable)getVolumeAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("getVolume()")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (Sdk_coreKotlinWrapped<Sdk_coreBoolean *> * _Nullable)isPlayingAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("isPlaying()")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (BOOL)pauseAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("pause_()")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (BOOL)resumeAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("resume_()")));
@end

__attribute__((swift_name("MediaPlayerHook")))
@protocol Sdk_coreMediaPlayerHook
@required
- (id _Nullable)getPlayer __attribute__((swift_name("getPlayer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlayerItem")))
@interface Sdk_coreMediaPlayerItem : Sdk_coreBase
- (instancetype)initWithUrl:(NSString *)url __attribute__((swift_name("init(url:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreMediaPlayerItem *)doCopyUrl:(NSString *)url __attribute__((swift_name("doCopy(url:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *url __attribute__((swift_name("url")));
@end

__attribute__((swift_name("CacheService")))
@interface Sdk_coreCacheService : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreCacheServiceCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (int64_t)getFreeStorageSize __attribute__((swift_name("getFreeStorageSize()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (int64_t)getTotalCachedSize __attribute__((swift_name("getTotalCachedSize()")));
- (BOOL)hasKey:(NSString *)key __attribute__((swift_name("has(key:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSArray<id<Sdk_corePlatformFile>> *)listCacheFiles __attribute__((swift_name("listCacheFiles()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSArray<id<Sdk_corePlatformFile>> *)listTempFiles __attribute__((swift_name("listTempFiles()")));
- (Sdk_coreKotlinPair<id<Sdk_coreKtor_ioByteReadChannel>, Sdk_coreLong *> *)readKey:(NSString *)key __attribute__((swift_name("read(key:)")));
- (BOOL)revalidateCacheNewCacheSize:(int32_t)newCacheSize __attribute__((swift_name("revalidateCache(newCacheSize:)")));
- (void)stop __attribute__((swift_name("stop()")));
- (void)writeKey:(NSString *)key data:(Sdk_coreKotlinByteArray *)data __attribute__((swift_name("write(key:data:)")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) id<Sdk_corePlatformFile> cacheDir __attribute__((swift_name("cacheDir")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreConcurrentQueue *fileSaveQueue __attribute__((swift_name("fileSaveQueue")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreFlowerConfigService *flowerConfigService __attribute__((swift_name("flowerConfigService")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreSdkContainer *sdkContainer __attribute__((swift_name("sdkContainer")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheService.Companion")))
@interface Sdk_coreCacheServiceCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreCacheServiceCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *ROOT_DIR __attribute__((swift_name("ROOT_DIR")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CachedHttpClient")))
@interface Sdk_coreCachedHttpClient : Sdk_coreBase
- (instancetype)initWithHttpClient:(Sdk_coreKtor_client_coreHttpClient *)httpClient __attribute__((swift_name("init(httpClient:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreCachedHttpClientCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)requestRequestBuilder:(Sdk_coreKtor_client_coreHttpRequestBuilder *)requestBuilder completionHandler:(void (^)(Sdk_coreCachedHttpClientResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("request(requestBuilder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)requestBlock:(void (^)(Sdk_coreKtor_client_coreHttpRequestBuilder *))block completionHandler:(void (^)(Sdk_coreCachedHttpClientResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("request(block:completionHandler:)")));
- (void)stop __attribute__((swift_name("stop()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CachedHttpClient.Companion")))
@interface Sdk_coreCachedHttpClientCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreCachedHttpClientCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CachedHttpClient.Response")))
@interface Sdk_coreCachedHttpClientResponse : Sdk_coreBase
- (instancetype)initWithStatusCode:(Sdk_coreKtor_httpHttpStatusCode *)statusCode headers:(id<Sdk_coreKtor_httpHeaders>)headers data:(id<Sdk_coreKtor_ioByteReadChannel>)data __attribute__((swift_name("init(statusCode:headers:data:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreCachedHttpClientResponse *)doCopyStatusCode:(Sdk_coreKtor_httpHttpStatusCode *)statusCode headers:(id<Sdk_coreKtor_httpHeaders>)headers data:(id<Sdk_coreKtor_ioByteReadChannel>)data __attribute__((swift_name("doCopy(statusCode:headers:data:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<Sdk_coreKtor_ioByteReadChannel> data __attribute__((swift_name("data")));
@property (readonly) id<Sdk_coreKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *statusCode __attribute__((swift_name("statusCode")));
@end

__attribute__((swift_name("PlatformFile")))
@protocol Sdk_corePlatformFile
@required
- (BOOL)delete __attribute__((swift_name("delete()")));
- (BOOL)exists __attribute__((swift_name("exists()")));
- (int64_t)lastModified __attribute__((swift_name("lastModified()")));
- (NSArray<id<Sdk_corePlatformFile>> *)listFilesFilter:(Sdk_coreBoolean *(^ _Nullable)(id<Sdk_corePlatformFile>, NSString *))filter __attribute__((swift_name("listFiles(filter:)")));
- (BOOL)mkdirs __attribute__((swift_name("mkdirs()")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (Sdk_coreKotlinByteArray * _Nullable)readAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("read()")));
- (BOOL)renameToDest:(id<Sdk_corePlatformFile>)dest __attribute__((swift_name("renameTo(dest:)")));
- (BOOL)setLastModifiedTime:(int64_t)time __attribute__((swift_name("setLastModified(time:)")));
- (int64_t)size __attribute__((swift_name("size()")));
- (BOOL)touch __attribute__((swift_name("touch()")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (BOOL)writeBytesData:(Sdk_coreKotlinByteArray *)data error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("writeBytes(data:)")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSString *path __attribute__((swift_name("path")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=tv/anypoint/flower/sdk/core/common/ErrorCodeSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ErrorCode")))
@interface Sdk_coreErrorCode : Sdk_coreKotlinEnum<Sdk_coreErrorCode *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreErrorCodeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreErrorCode *unknownError __attribute__((swift_name("unknownError")));
@property (class, readonly) Sdk_coreErrorCode *segmentSkipped __attribute__((swift_name("segmentSkipped")));
@property (class, readonly) Sdk_coreErrorCode *playerErrorEvent __attribute__((swift_name("playerErrorEvent")));
@property (class, readonly) Sdk_coreErrorCode *playlistSkipped __attribute__((swift_name("playlistSkipped")));
@property (class, readonly) Sdk_coreErrorCode *playlistRewinded __attribute__((swift_name("playlistRewinded")));
@property (class, readonly) Sdk_coreErrorCode *playerStopped __attribute__((swift_name("playerStopped")));
@property (class, readonly) Sdk_coreErrorCode *playerDestroyed __attribute__((swift_name("playerDestroyed")));
@property (class, readonly) Sdk_coreErrorCode *adRequestUnknownError __attribute__((swift_name("adRequestUnknownError")));
@property (class, readonly) Sdk_coreErrorCode *adResponseIsShorterThanRequested __attribute__((swift_name("adResponseIsShorterThanRequested")));
@property (class, readonly) Sdk_coreErrorCode *adNoAcceptableCreative __attribute__((swift_name("adNoAcceptableCreative")));
@property (class, readonly) Sdk_coreErrorCode *adRequestTimeout __attribute__((swift_name("adRequestTimeout")));
@property (class, readonly) Sdk_coreErrorCode *adCannotFindSmallerVariant __attribute__((swift_name("adCannotFindSmallerVariant")));
@property (class, readonly) Sdk_coreErrorCode *adCannotFindExactVariant __attribute__((swift_name("adCannotFindExactVariant")));
@property (class, readonly) Sdk_coreErrorCode *xmlParseError __attribute__((swift_name("xmlParseError")));
@property (class, readonly) Sdk_coreErrorCode *m3u8ParseError __attribute__((swift_name("m3u8ParseError")));
+ (Sdk_coreKotlinArray<Sdk_coreErrorCode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreErrorCode *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ErrorCode.Companion")))
@interface Sdk_coreErrorCodeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreErrorCodeCompanion *shared __attribute__((swift_name("shared")));
- (id<Sdk_coreKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<Sdk_coreKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(Sdk_coreKotlinArray<id<Sdk_coreKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ErrorLog")))
@interface Sdk_coreErrorLog : Sdk_coreBase
- (instancetype)initWithErrorCode:(Sdk_coreErrorCode * _Nullable)errorCode streamVariant:(NSString * _Nullable)streamVariant tagUrl:(NSString * _Nullable)tagUrl spliceEventId:(Sdk_coreLong * _Nullable)spliceEventId cueDuration:(Sdk_coreLong * _Nullable)cueDuration adIds:(NSArray<NSString *> * _Nullable)adIds timeout:(Sdk_coreLong * _Nullable)timeout __attribute__((swift_name("init(errorCode:streamVariant:tagUrl:spliceEventId:cueDuration:adIds:timeout:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreErrorLogCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSArray<NSString *> * _Nullable adIds __attribute__((swift_name("adIds")));
@property (readonly) Sdk_coreLong * _Nullable cueDuration __attribute__((swift_name("cueDuration")));
@property NSString * _Nullable deviceId __attribute__((swift_name("deviceId")));
@property NSString * _Nullable deviceModel __attribute__((swift_name("deviceModel")));
@property (readonly) Sdk_coreErrorCode * _Nullable errorCode __attribute__((swift_name("errorCode")));
@property NSString * _Nullable firmwareVersion __attribute__((swift_name("firmwareVersion")));
@property NSString * _Nullable sdkType __attribute__((swift_name("sdkType")));
@property NSString * _Nullable sdkVersion __attribute__((swift_name("sdkVersion")));
@property (readonly) Sdk_coreLong * _Nullable spliceEventId __attribute__((swift_name("spliceEventId")));
@property (readonly) NSString * _Nullable streamVariant __attribute__((swift_name("streamVariant")));
@property (readonly) NSString * _Nullable tagUrl __attribute__((swift_name("tagUrl")));
@property (readonly) Sdk_coreLong * _Nullable timeout __attribute__((swift_name("timeout")));
@property (readonly) double timestamp __attribute__((swift_name("timestamp")));
@property NSString * _Nullable userAgent __attribute__((swift_name("userAgent")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ErrorLog.Companion")))
@interface Sdk_coreErrorLogCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreErrorLogCompanion *shared __attribute__((swift_name("shared")));
- (id<Sdk_coreKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ErrorLogSender")))
@interface Sdk_coreErrorLogSender : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreErrorLogSenderCompanion *companion __attribute__((swift_name("companion")));
- (void)logErrorLog:(Sdk_coreErrorLog *)errorLog __attribute__((swift_name("log(errorLog:)")));
- (Sdk_coreErrorLog *)resolveLogErrorLog:(Sdk_coreErrorLog *)errorLog __attribute__((swift_name("resolveLog(errorLog:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ErrorLogSender.Companion")))
@interface Sdk_coreErrorLogSenderCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreErrorLogSenderCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *S3_BUCKET_HOST __attribute__((swift_name("S3_BUCKET_HOST")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlowerConfigService")))
@interface Sdk_coreFlowerConfigService : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreFlowerConfigServiceCompanion *companion __attribute__((swift_name("companion")));
- (void)saveExtensionNode:(Sdk_coreXmlNode *)extensionNode __attribute__((swift_name("save(extensionNode:)")));
@property (readonly) Sdk_coreFlowerConfigServiceStartupConfig *startupConfig __attribute__((swift_name("startupConfig")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlowerConfigService.Companion")))
@interface Sdk_coreFlowerConfigServiceCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreFlowerConfigServiceCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlowerConfigService.StartupConfig")))
@interface Sdk_coreFlowerConfigServiceStartupConfig : Sdk_coreBase
- (instancetype)initWithVersion:(int32_t)version maxCacheStorage:(Sdk_coreInt * _Nullable)maxCacheStorage minFreeStorage:(Sdk_coreInt * _Nullable)minFreeStorage __attribute__((swift_name("init(version:maxCacheStorage:minFreeStorage:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreFlowerConfigServiceStartupConfig *)doCopyVersion:(int32_t)version maxCacheStorage:(Sdk_coreInt * _Nullable)maxCacheStorage minFreeStorage:(Sdk_coreInt * _Nullable)minFreeStorage __attribute__((swift_name("doCopy(version:maxCacheStorage:minFreeStorage:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Sdk_coreInt * _Nullable maxCacheStorage __attribute__((swift_name("maxCacheStorage")));
@property (readonly) Sdk_coreInt * _Nullable minFreeStorage __attribute__((swift_name("minFreeStorage")));
@property (readonly) int32_t version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlowerConfigService.StartupConfigKey")))
@interface Sdk_coreFlowerConfigServiceStartupConfigKey : Sdk_coreKotlinEnum<Sdk_coreFlowerConfigServiceStartupConfigKey *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreFlowerConfigServiceStartupConfigKey *version_ __attribute__((swift_name("version_")));
@property (class, readonly) Sdk_coreFlowerConfigServiceStartupConfigKey *maxCacheStorage __attribute__((swift_name("maxCacheStorage")));
@property (class, readonly) Sdk_coreFlowerConfigServiceStartupConfigKey *minFreeStorage __attribute__((swift_name("minFreeStorage")));
+ (Sdk_coreKotlinArray<Sdk_coreFlowerConfigServiceStartupConfigKey *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreFlowerConfigServiceStartupConfigKey *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlatformAnalytics")))
@interface Sdk_corePlatformAnalytics : Sdk_coreBase
- (instancetype)initWithSdkVersion:(NSString *)sdkVersion __attribute__((swift_name("init(sdkVersion:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *sdkVersion __attribute__((swift_name("sdkVersion")));
@end

__attribute__((swift_name("PlatformAnalyticsResolver")))
@protocol Sdk_corePlatformAnalyticsResolver
@required
- (Sdk_corePlatformAnalytics *)resolve __attribute__((swift_name("resolve()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SdkContainer")))
@interface Sdk_coreSdkContainer : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreSdkContainerCompanion *companion __attribute__((swift_name("companion")));
- (id _Nullable)getClassName:(Sdk_coreSdkContainerClassName *)className __attribute__((swift_name("get(className:)")));
- (void)doInitInstances:(Sdk_coreMutableDictionary<Sdk_coreSdkContainerClassName *, id> *)instances factories:(Sdk_coreMutableDictionary<Sdk_coreSdkContainerClassName *, id<Sdk_coreSdkContainerBeanFactory>> *)factories __attribute__((swift_name("doInit(instances:factories:)")));
- (id _Nullable)doNewClassName:(Sdk_coreSdkContainerClassName *)className args:(Sdk_coreKotlinArray<id> *)args __attribute__((swift_name("doNew(className:args:)")));
- (void)setClassName:(Sdk_coreSdkContainerClassName *)className object:(id)object __attribute__((swift_name("set(className:object:)")));
- (void)setEnvironmentEnv:(NSString *)env __attribute__((swift_name("setEnvironment(env:)")));
- (void)setLogLevelLevel:(Sdk_coreSdkContainerLogLevel *)level __attribute__((swift_name("setLogLevel(level:)")));
@property (readonly) Sdk_coreAdUrlMacro *adUrlMacro __attribute__((swift_name("adUrlMacro")));
@property (readonly) Sdk_coreCacheService *cacheService __attribute__((swift_name("cacheService")));
@property (readonly) Sdk_coreCachedHttpClient *cachedHttpClient __attribute__((swift_name("cachedHttpClient")));
@property (readonly) id<Sdk_coreDeviceService> deviceService __attribute__((swift_name("deviceService")));
@property NSString *env __attribute__((swift_name("env")));
@property (readonly) Sdk_coreErrorLogSender *errorLogSender __attribute__((swift_name("errorLogSender")));
@property Sdk_coreMutableDictionary<Sdk_coreSdkContainerClassName *, id<Sdk_coreSdkContainerBeanFactory>> *factories __attribute__((swift_name("factories")));
@property (readonly) Sdk_coreFillerAdsManager *fillerAdsManager __attribute__((swift_name("fillerAdsManager")));
@property (readonly) Sdk_coreFlowerConfigService *flowerConfigService __attribute__((swift_name("flowerConfigService")));
@property (readonly) id<Sdk_coreGoogleAdsManager> _Nullable googleAdsManager __attribute__((swift_name("googleAdsManager")));
@property (readonly) Sdk_coreKtor_client_coreHttpClient *httpClient __attribute__((swift_name("httpClient")));
@property Sdk_coreMutableDictionary<Sdk_coreSdkContainerClassName *, id> *instances __attribute__((swift_name("instances")));
@property (readonly) Sdk_coreKotlinx_serialization_jsonJson *json __attribute__((swift_name("json")));
@property (readonly) Sdk_coreManipulationProxy *manipulationProxy __attribute__((swift_name("manipulationProxy")));
@property (readonly) Sdk_coreMediaSegmentAssumeService * _Nullable mediaSegmentAssumeService __attribute__((swift_name("mediaSegmentAssumeService")));
@property (readonly) id<Sdk_coreXmlUtil> xml __attribute__((swift_name("xml")));
@end

__attribute__((swift_name("SdkContainerBeanFactory")))
@protocol Sdk_coreSdkContainerBeanFactory
@required

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (Sdk_coreKotlinWrapped<id> * _Nullable)createArgs:(Sdk_coreKotlinArray<id> *)args error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("create(args:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SdkContainer.ClassName")))
@interface Sdk_coreSdkContainerClassName : Sdk_coreKotlinEnum<Sdk_coreSdkContainerClassName *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreSdkContainerClassName *adUrlMacro __attribute__((swift_name("adUrlMacro")));
@property (class, readonly) Sdk_coreSdkContainerClassName *deviceService __attribute__((swift_name("deviceService")));
@property (class, readonly) Sdk_coreSdkContainerClassName *platformAnalyticsResolver __attribute__((swift_name("platformAnalyticsResolver")));
@property (class, readonly) Sdk_coreSdkContainerClassName *googleAdsManager __attribute__((swift_name("googleAdsManager")));
@property (class, readonly) Sdk_coreSdkContainerClassName *json __attribute__((swift_name("json")));
@property (class, readonly) Sdk_coreSdkContainerClassName *fillerAdsManager __attribute__((swift_name("fillerAdsManager")));
@property (class, readonly) Sdk_coreSdkContainerClassName *httpClient __attribute__((swift_name("httpClient")));
@property (class, readonly) Sdk_coreSdkContainerClassName *mediaPlayerAdapter __attribute__((swift_name("mediaPlayerAdapter")));
@property (class, readonly) Sdk_coreSdkContainerClassName *xmlUtil __attribute__((swift_name("xmlUtil")));
@property (class, readonly) Sdk_coreSdkContainerClassName *manifestParser __attribute__((swift_name("manifestParser")));
@property (class, readonly) Sdk_coreSdkContainerClassName *adPlayer __attribute__((swift_name("adPlayer")));
@property (class, readonly) Sdk_coreSdkContainerClassName *mobileMessageHandler __attribute__((swift_name("mobileMessageHandler")));
@property (class, readonly) Sdk_coreSdkContainerClassName *tvMessageHandler __attribute__((swift_name("tvMessageHandler")));
@property (class, readonly) Sdk_coreSdkContainerClassName *mediaSegmentAssumeService __attribute__((swift_name("mediaSegmentAssumeService")));
@property (class, readonly) Sdk_coreSdkContainerClassName *manipulationProxy __attribute__((swift_name("manipulationProxy")));
@property (class, readonly) Sdk_coreSdkContainerClassName *platformFile __attribute__((swift_name("platformFile")));
@property (class, readonly) Sdk_coreSdkContainerClassName *cacheService __attribute__((swift_name("cacheService")));
+ (Sdk_coreKotlinArray<Sdk_coreSdkContainerClassName *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreSdkContainerClassName *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SdkContainer.Companion")))
@interface Sdk_coreSdkContainerCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreSdkContainerCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreSdkContainer *)getInstance __attribute__((swift_name("getInstance()")));
@property (readonly) int64_t DEFAULT_TIME_OUT __attribute__((swift_name("DEFAULT_TIME_OUT")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SdkContainer.LogLevel")))
@interface Sdk_coreSdkContainerLogLevel : Sdk_coreKotlinEnum<Sdk_coreSdkContainerLogLevel *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreSdkContainerLogLevel *verbose __attribute__((swift_name("verbose")));
@property (class, readonly) Sdk_coreSdkContainerLogLevel *debug __attribute__((swift_name("debug")));
@property (class, readonly) Sdk_coreSdkContainerLogLevel *info __attribute__((swift_name("info")));
@property (class, readonly) Sdk_coreSdkContainerLogLevel *warn __attribute__((swift_name("warn")));
@property (class, readonly) Sdk_coreSdkContainerLogLevel *error __attribute__((swift_name("error")));
@property (class, readonly) Sdk_coreSdkContainerLogLevel *off __attribute__((swift_name("off")));
+ (Sdk_coreKotlinArray<Sdk_coreSdkContainerLogLevel *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreSdkContainerLogLevel *> *entries __attribute__((swift_name("entries")));
@property (readonly) Sdk_coreLogLevel *value __attribute__((swift_name("value")));
@end

__attribute__((swift_name("DeviceService")))
@protocol Sdk_coreDeviceService
@required
- (NSString * _Nullable)getDeviceId __attribute__((swift_name("getDeviceId()")));
- (NSString * _Nullable)getFwVer __attribute__((swift_name("getFwVer()")));
- (NSString * _Nullable)getIPAddressUseIPv4:(BOOL)useIPv4 __attribute__((swift_name("getIPAddress(useIPv4:)")));
- (NSString * _Nullable)getLocale __attribute__((swift_name("getLocale()")));
- (NSString * _Nullable)getModel __attribute__((swift_name("getModel()")));
- (NSString * _Nullable)getPlatformAdId __attribute__((swift_name("getPlatformAdId()")));
- (NSString * _Nullable)getUserAgent __attribute__((swift_name("getUserAgent()")));
- (void)setDeviceIdDeviceId:(NSString *)deviceId __attribute__((swift_name("setDeviceId(deviceId:)")));
@property (readonly) id<Sdk_coreKeyValueStore> keyValueStore __attribute__((swift_name("keyValueStore")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceServiceCompanion")))
@interface Sdk_coreDeviceServiceCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreDeviceServiceCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *DEVICE_ID_KEY __attribute__((swift_name("DEVICE_ID_KEY")));
@end

__attribute__((swift_name("KeyValueStore")))
@protocol Sdk_coreKeyValueStore
@required
- (Sdk_coreBoolean * _Nullable)getBooleanKey:(NSString *)key __attribute__((swift_name("getBoolean(key:)")));
- (Sdk_coreFloat * _Nullable)getFloatKey:(NSString *)key __attribute__((swift_name("getFloat(key:)")));
- (Sdk_coreInt * _Nullable)getIntKey:(NSString *)key __attribute__((swift_name("getInt(key:)")));
- (NSString * _Nullable)getStringKey:(NSString *)key __attribute__((swift_name("getString(key:)")));
- (BOOL)hasKeyKey:(NSString *)key __attribute__((swift_name("hasKey(key:)")));
- (void)putBooleanKey:(NSString *)key value:(BOOL)value __attribute__((swift_name("putBoolean(key:value:)")));
- (void)putFloatKey:(NSString *)key value:(float)value __attribute__((swift_name("putFloat(key:value:)")));
- (void)putIntKey:(NSString *)key value:(int32_t)value __attribute__((swift_name("putInt(key:value:)")));
- (void)putStringKey:(NSString *)key value:(NSString *)value __attribute__((swift_name("putString(key:value:)")));
- (void)removeKey:(NSString *)key __attribute__((swift_name("remove(key:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GoogleAdReportLogEvent")))
@interface Sdk_coreGoogleAdReportLogEvent : Sdk_coreKotlinEnum<Sdk_coreGoogleAdReportLogEvent *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *started __attribute__((swift_name("started")));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *firstQuartile __attribute__((swift_name("firstQuartile")));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *midpoint __attribute__((swift_name("midpoint")));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *thirdQuartile __attribute__((swift_name("thirdQuartile")));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *completed __attribute__((swift_name("completed")));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *skip __attribute__((swift_name("skip")));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *click __attribute__((swift_name("click")));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *noAd __attribute__((swift_name("noAd")));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *loadError __attribute__((swift_name("loadError")));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *playError __attribute__((swift_name("playError")));
@property (class, readonly) Sdk_coreGoogleAdReportLogEvent *allAdsCompleted __attribute__((swift_name("allAdsCompleted")));
+ (Sdk_coreKotlinArray<Sdk_coreGoogleAdReportLogEvent *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreGoogleAdReportLogEvent *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("GoogleAdView")))
@protocol Sdk_coreGoogleAdView <Sdk_coreUIElement>
@required
- (void)addViewView:(id<Sdk_coreGoogleAdView>)view __attribute__((swift_name("addView(view:)")));
- (void)removeViewView:(id<Sdk_coreGoogleAdView>)view __attribute__((swift_name("removeView(view:)")));
@end

__attribute__((swift_name("GoogleAdsLoaderListener")))
@protocol Sdk_coreGoogleAdsLoaderListener
@required
- (void)responseAdMediaUrl:(NSString *)mediaUrl __attribute__((swift_name("responseAd(mediaUrl:)")));
- (void)sendBeaconLogTransactionId:(NSString *)transactionId logEvent:(Sdk_coreGoogleAdReportLogEvent *)logEvent errorCode:(NSString * _Nullable)errorCode __attribute__((swift_name("sendBeaconLog(transactionId:logEvent:errorCode:)")));
@end

__attribute__((swift_name("GoogleAdsManager")))
@protocol Sdk_coreGoogleAdsManager <Sdk_coreGoogleAdsLoaderListener>
@required
- (void)release_ __attribute__((swift_name("release()")));
- (void)requestAdsWrapperAd:(Sdk_coreAd *)wrapperAd googleAdView:(id<Sdk_coreGoogleAdView>)googleAdView googleAdsLoaderListener:(id<Sdk_coreGoogleAdsLoaderListener>)googleAdsLoaderListener __attribute__((swift_name("requestAds(wrapperAd:googleAdView:googleAdsLoaderListener:)")));
- (void)startAdTransactionId:(NSString *)transactionId duration:(int64_t)duration __attribute__((swift_name("startAd(transactionId:duration:)")));
@end

__attribute__((swift_name("Manipulator")))
@interface Sdk_coreManipulator : Sdk_coreBase
- (instancetype)initWithManipulationProxy:(Sdk_coreManipulationProxy *)manipulationProxy __attribute__((swift_name("init(manipulationProxy:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreManipulatorCompanion *companion __attribute__((swift_name("companion")));
- (NSString *)manipulateText:(NSString *)text requestUri:(NSString *)requestUri __attribute__((swift_name("manipulate(text:requestUri:)")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString * _Nullable)manipulateImplText:(NSString *)text requestUri:(NSString *)requestUri error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("manipulateImpl(text:requestUri:)")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreErrorLogSender *errorLogSender __attribute__((swift_name("errorLogSender")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property Sdk_coreManipulationProxy *manipulationProxy __attribute__((swift_name("manipulationProxy")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreSdkContainer *sdkContainer __attribute__((swift_name("sdkContainer")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DashManipulator")))
@interface Sdk_coreDashManipulator : Sdk_coreManipulator
- (instancetype)initWithManipulationProxy:(Sdk_coreManipulationProxy *)manipulationProxy adsManager:(Sdk_coreFlowerAdsManagerImpl *)adsManager __attribute__((swift_name("init(manipulationProxy:adsManager:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithManipulationProxy:(Sdk_coreManipulationProxy *)manipulationProxy __attribute__((swift_name("init(manipulationProxy:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreDashManipulatorCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString * _Nullable)manipulateImplText:(NSString *)text requestUri:(NSString *)requestUri error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("manipulateImpl(text:requestUri:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DashManipulator.Companion")))
@interface Sdk_coreDashManipulatorCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreDashManipulatorCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DashManipulator.PeriodInformation")))
@interface Sdk_coreDashManipulatorPeriodInformation : Sdk_coreBase
- (instancetype)initWithId:(NSString *)id startTime:(int64_t)startTime presentationTimeOffset:(Sdk_coreTimeScaled *)presentationTimeOffset __attribute__((swift_name("init(id:startTime:presentationTimeOffset:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) Sdk_coreTimeScaled *presentationTimeOffset __attribute__((swift_name("presentationTimeOffset")));
@property (readonly) int64_t startTime __attribute__((swift_name("startTime")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DashManipulator.ResponseAds")))
@interface Sdk_coreDashManipulatorResponseAds : Sdk_coreBase
- (instancetype)initWithAds:(NSMutableArray<Sdk_coreAd *> *)ads isCompleted:(BOOL)isCompleted requestId:(NSString *)requestId __attribute__((swift_name("init(ads:isCompleted:requestId:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSMutableArray<Sdk_coreAd *> *ads __attribute__((swift_name("ads")));
@property BOOL isCompleted __attribute__((swift_name("isCompleted")));
@property NSString *requestId __attribute__((swift_name("requestId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HlsManipulator")))
@interface Sdk_coreHlsManipulator : Sdk_coreManipulator
- (instancetype)initWithManipulationProxy:(Sdk_coreManipulationProxy *)manipulationProxy flowerAdsManager:(Sdk_coreFlowerAdsManagerImpl *)flowerAdsManager __attribute__((swift_name("init(manipulationProxy:flowerAdsManager:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithManipulationProxy:(Sdk_coreManipulationProxy *)manipulationProxy __attribute__((swift_name("init(manipulationProxy:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreHlsManipulatorCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString * _Nullable)manipulateImplText:(NSString *)text requestUri:(NSString *)requestUri error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("manipulateImpl(text:requestUri:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HlsManipulator.Companion")))
@interface Sdk_coreHlsManipulatorCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreHlsManipulatorCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ManifestParser")))
@interface Sdk_coreManifestParser : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreManifestParserCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)parseM3u8MediaUrl:(NSString *)mediaUrl creativeId:(NSString *)creativeId completionHandler:(void (^)(NSArray<Sdk_coreKotlinPair<Sdk_coreVariant *, Sdk_coreMediaPlaylist *> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("parseM3u8(mediaUrl:creativeId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)parseMpdMediaUrl:(NSString *)mediaUrl adId:(NSString *)adId creativeId:(NSString *)creativeId completionHandler:(void (^)(Sdk_coreMPD * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("parseMpd(mediaUrl:adId:creativeId:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ManifestParser.Companion")))
@interface Sdk_coreManifestParserCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreManifestParserCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Manipulator.Companion")))
@interface Sdk_coreManipulatorCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreManipulatorCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdaptationSet")))
@interface Sdk_coreAdaptationSet : Sdk_coreBase
- (instancetype)initWithXmlNode:(Sdk_coreXmlNode *)xmlNode __attribute__((swift_name("init(xmlNode:)"))) __attribute__((objc_designated_initializer));
- (NSString *)getFirstRepresentationId __attribute__((swift_name("getFirstRepresentationId()")));
@property (readonly) NSArray<Sdk_coreRepresentation *> *representations __attribute__((swift_name("representations")));
@property (readonly) Sdk_coreSegmentTemplate *segmentTemplate __attribute__((swift_name("segmentTemplate")));
@property (readonly) Sdk_coreXmlNode *xmlNode __attribute__((swift_name("xmlNode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MPD")))
@interface Sdk_coreMPD : Sdk_coreBase
- (instancetype)initWithXmlNode:(Sdk_coreXmlNode *)xmlNode __attribute__((swift_name("init(xmlNode:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreMPDCompanion *companion __attribute__((swift_name("companion")));
- (NSString *)string __attribute__((swift_name("string()")));
- (Sdk_coreMPD *)withBaseURLsNewBaseURLs:(NSArray<NSString *> *)newBaseURLs __attribute__((swift_name("withBaseURLs(newBaseURLs:)")));
- (Sdk_coreMPD *)withPeriodsNewPeriods:(NSArray<Sdk_corePeriod *> *)newPeriods __attribute__((swift_name("withPeriods(newPeriods:)")));
@property (readonly) Sdk_coreKotlinx_datetimeInstant * _Nullable availabilityStartTime __attribute__((swift_name("availabilityStartTime")));
@property (readonly) NSArray<Sdk_coreXmlNode *> *baseURLs __attribute__((swift_name("baseURLs")));
@property (readonly) int64_t mediaPresentationDuration __attribute__((swift_name("mediaPresentationDuration")));
@property (readonly) Sdk_coreXmlNode *mpd __attribute__((swift_name("mpd")));
@property (readonly) NSMutableArray<Sdk_corePeriod *> *periods __attribute__((swift_name("periods")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MPD.Companion")))
@interface Sdk_coreMPDCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreMPDCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreMPD *)parseText:(NSString *)text __attribute__((swift_name("parse(text:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Period")))
@interface Sdk_corePeriod : Sdk_coreBase
- (instancetype)initWithXmlNode:(Sdk_coreXmlNode *)xmlNode __attribute__((swift_name("init(xmlNode:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_corePeriodCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreAdaptationSet *)getFirstAudioAdaptationSet __attribute__((swift_name("getFirstAudioAdaptationSet()")));
- (Sdk_coreAdaptationSet *)getFirstVideoAdaptationSet __attribute__((swift_name("getFirstVideoAdaptationSet()")));
- (Sdk_coreTimeScaled *)getPresentationTimeOffset __attribute__((swift_name("getPresentationTimeOffset()")));
- (Sdk_coreSpliceInfoSection_ * _Nullable)getSpliceInfoSection __attribute__((swift_name("getSpliceInfoSection()")));
- (BOOL)hasSpliceInfoSection __attribute__((swift_name("hasSpliceInfoSection()")));
- (Sdk_corePeriod *)updatePresentationTimeOffsetPresentationTimeOffset:(Sdk_coreTimeScaled *)presentationTimeOffset __attribute__((swift_name("updatePresentationTimeOffset(presentationTimeOffset:)")));
- (Sdk_corePeriod *)withBaseURLsNewBaseURLs:(NSArray<NSString *> *)newBaseURLs __attribute__((swift_name("withBaseURLs(newBaseURLs:)")));
- (Sdk_corePeriod *)withDurationNewDuration:(int64_t)newDuration __attribute__((swift_name("withDuration(newDuration:)")));
- (Sdk_corePeriod *)withIdId:(NSString *)id __attribute__((swift_name("withId(id:)")));
- (Sdk_corePeriod *)withStartNewStart:(int64_t)newStart __attribute__((swift_name("withStart(newStart:)")));
@property int64_t duration __attribute__((swift_name("duration")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) int64_t start __attribute__((swift_name("start")));
@property (readonly) Sdk_coreXmlNode *xmlNode __attribute__((swift_name("xmlNode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Period.Companion")))
@interface Sdk_corePeriodCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_corePeriodCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Representation")))
@interface Sdk_coreRepresentation : Sdk_coreBase
- (instancetype)initWithXmlNode:(Sdk_coreXmlNode *)xmlNode __attribute__((swift_name("init(xmlNode:)"))) __attribute__((objc_designated_initializer));
@property (readonly) int64_t bandwidth __attribute__((swift_name("bandwidth")));
@property (readonly) int64_t height __attribute__((swift_name("height")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) int64_t width __attribute__((swift_name("width")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SegmentTemplate")))
@interface Sdk_coreSegmentTemplate : Sdk_coreBase
- (instancetype)initWithXmlNode:(Sdk_coreXmlNode *)xmlNode __attribute__((swift_name("init(xmlNode:)"))) __attribute__((objc_designated_initializer));
@property (readonly) Sdk_coreTimeScaled *duration __attribute__((swift_name("duration")));
@property (readonly) NSString *initialization __attribute__((swift_name("initialization")));
@property (readonly) NSString *media __attribute__((swift_name("media")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SpliceInfoSection_")))
@interface Sdk_coreSpliceInfoSection_ : Sdk_coreBase
- (instancetype)initWithDurationMs:(int64_t)durationMs eventId:(Sdk_coreInt * _Nullable)eventId uniqueProgramId:(Sdk_coreInt * _Nullable)uniqueProgramId __attribute__((swift_name("init(durationMs:eventId:uniqueProgramId:)"))) __attribute__((objc_designated_initializer));
@property (readonly) int64_t durationMs __attribute__((swift_name("durationMs")));
@property (readonly) Sdk_coreInt * _Nullable eventId __attribute__((swift_name("eventId")));
@property (readonly) Sdk_coreInt * _Nullable uniqueProgramId __attribute__((swift_name("uniqueProgramId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeScaled")))
@interface Sdk_coreTimeScaled : Sdk_coreBase
- (instancetype)initWithValue:(int64_t)value timeScale:(int64_t)timeScale __attribute__((swift_name("init(value:timeScale:)"))) __attribute__((objc_designated_initializer));
@property (readonly) int64_t seconds __attribute__((swift_name("seconds")));
@property (readonly) int64_t value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheAdMediaSegmentService")))
@interface Sdk_coreCacheAdMediaSegmentService : Sdk_coreBase
- (instancetype)initWithAdsManager:(Sdk_coreFlowerAdsManagerImpl *)adsManager __attribute__((swift_name("init(adsManager:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreCacheAdMediaSegmentServiceCompanion *companion __attribute__((swift_name("companion")));
- (int64_t)calculateVariantDiffForHlsAdVariant:(Sdk_coreVariant *)adVariant playerVariant:(Sdk_coreVariant * _Nullable)playerVariant playerHeight:(int32_t)playerHeight __attribute__((swift_name("calculateVariantDiffForHls(adVariant:playerVariant:playerHeight:)")));
- (Sdk_coreVariant *)findBestVariantAdVariants:(NSSet<Sdk_coreVariant *> *)adVariants playerVariant:(Sdk_coreVariant * _Nullable)playerVariant playerHeight:(int32_t)playerHeight __attribute__((swift_name("findBestVariant(adVariants:playerVariant:playerHeight:)")));
- (Sdk_coreCacheAdMediaSegmentServiceAdGroup *)getAdEventId:(int32_t)adEventId __attribute__((swift_name("get(adEventId:)")));
- (void)removeAdEventId:(Sdk_coreInt * _Nullable)adEventId delayMs:(int64_t)delayMs __attribute__((swift_name("remove(adEventId:delayMs:)")));
- (void)requestAdsCueDuration:(int64_t)cueDuration uniqueProgramId:(int32_t)uniqueProgramId adEventId:(int32_t)adEventId encodedScte35:(NSString *)encodedScte35 isTs:(BOOL)isTs adWaitingTime:(int64_t)adWaitingTime adPrefix:(NSString * _Nullable)adPrefix __attribute__((swift_name("requestAds(cueDuration:uniqueProgramId:adEventId:encodedScte35:isTs:adWaitingTime:adPrefix:)")));
- (void)setCueEventAdEventId:(int32_t)adEventId __attribute__((swift_name("setCueEvent(adEventId:)")));
- (void)skipCueEventAdEventId:(int32_t)adEventId __attribute__((swift_name("skipCueEvent(adEventId:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheAdMediaSegmentService.AdGroup")))
@interface Sdk_coreCacheAdMediaSegmentServiceAdGroup : Sdk_coreBase
- (instancetype)initWithAdMediaSegments:(NSMutableArray<Sdk_coreCacheAdMediaSegmentServiceAdMediaSegment *> *)adMediaSegments isCompleted:(BOOL)isCompleted isRequested:(BOOL)isRequested lastAdSegmentIndex:(int32_t)lastAdSegmentIndex requestId:(NSString *)requestId matchedVariantPairs:(Sdk_coreMutableDictionary<id, Sdk_coreVariant *> *)matchedVariantPairs ads:(NSMutableArray<Sdk_coreAd *> *)ads isInserted:(BOOL)isInserted __attribute__((swift_name("init(adMediaSegments:isCompleted:isRequested:lastAdSegmentIndex:requestId:matchedVariantPairs:ads:isInserted:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreCacheAdMediaSegmentServiceAdGroup *)doCopyAdMediaSegments:(NSMutableArray<Sdk_coreCacheAdMediaSegmentServiceAdMediaSegment *> *)adMediaSegments isCompleted:(BOOL)isCompleted isRequested:(BOOL)isRequested lastAdSegmentIndex:(int32_t)lastAdSegmentIndex requestId:(NSString *)requestId matchedVariantPairs:(Sdk_coreMutableDictionary<id, Sdk_coreVariant *> *)matchedVariantPairs ads:(NSMutableArray<Sdk_coreAd *> *)ads isInserted:(BOOL)isInserted __attribute__((swift_name("doCopy(adMediaSegments:isCompleted:isRequested:lastAdSegmentIndex:requestId:matchedVariantPairs:ads:isInserted:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSMutableArray<Sdk_coreCacheAdMediaSegmentServiceAdMediaSegment *> *adMediaSegments __attribute__((swift_name("adMediaSegments")));
@property (readonly) NSMutableArray<Sdk_coreAd *> *ads __attribute__((swift_name("ads")));
@property BOOL isCompleted __attribute__((swift_name("isCompleted")));
@property BOOL isInserted __attribute__((swift_name("isInserted")));
@property BOOL isRequested __attribute__((swift_name("isRequested")));
@property int32_t lastAdSegmentIndex __attribute__((swift_name("lastAdSegmentIndex")));
@property Sdk_coreMutableDictionary<id, Sdk_coreVariant *> *matchedVariantPairs __attribute__((swift_name("matchedVariantPairs")));
@property NSString *requestId __attribute__((swift_name("requestId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheAdMediaSegmentService.AdMediaSegment")))
@interface Sdk_coreCacheAdMediaSegmentServiceAdMediaSegment : Sdk_coreBase
- (instancetype)initWithAdId:(NSString * _Nullable)adId duration:(int64_t)duration videoMediaSegments:(NSDictionary<Sdk_coreVariant *, NSArray<Sdk_coreMediaSegment *> *> *)videoMediaSegments audioMediaSegments:(NSArray<Sdk_coreMediaSegment *> *)audioMediaSegments __attribute__((swift_name("init(adId:duration:videoMediaSegments:audioMediaSegments:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreCacheAdMediaSegmentServiceAdMediaSegment *)doCopyAdId:(NSString * _Nullable)adId duration:(int64_t)duration videoMediaSegments:(NSDictionary<Sdk_coreVariant *, NSArray<Sdk_coreMediaSegment *> *> *)videoMediaSegments audioMediaSegments:(NSArray<Sdk_coreMediaSegment *> *)audioMediaSegments __attribute__((swift_name("doCopy(adId:duration:videoMediaSegments:audioMediaSegments:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable adId __attribute__((swift_name("adId")));
@property (readonly) NSArray<Sdk_coreMediaSegment *> *audioMediaSegments __attribute__((swift_name("audioMediaSegments")));
@property (readonly) int64_t duration __attribute__((swift_name("duration")));
@property (readonly) NSDictionary<Sdk_coreVariant *, NSArray<Sdk_coreMediaSegment *> *> *videoMediaSegments __attribute__((swift_name("videoMediaSegments")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheAdMediaSegmentService.Companion")))
@interface Sdk_coreCacheAdMediaSegmentServiceCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreCacheAdMediaSegmentServiceCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *CUE_OUT_TYPE __attribute__((swift_name("CUE_OUT_TYPE")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlaylistManipulator")))
@interface Sdk_coreMediaPlaylistManipulator : Sdk_coreManipulator
- (instancetype)initWithManipulationProxy:(Sdk_coreManipulationProxy *)manipulationProxy cacheAdMediaSegmentService:(Sdk_coreCacheAdMediaSegmentService *)cacheAdMediaSegmentService flowerAdsManager:(Sdk_coreFlowerAdsManagerImpl *)flowerAdsManager __attribute__((swift_name("init(manipulationProxy:cacheAdMediaSegmentService:flowerAdsManager:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithManipulationProxy:(Sdk_coreManipulationProxy *)manipulationProxy __attribute__((swift_name("init(manipulationProxy:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreMediaPlaylistManipulatorCompanion *companion __attribute__((swift_name("companion")));
- (NSString *)manipulateResponseBody:(NSString *)responseBody isAudio:(BOOL)isAudio requestUri:(NSString *)requestUri __attribute__((swift_name("manipulate(responseBody:isAudio:requestUri:)")));

/**
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString * _Nullable)manipulateImplText:(NSString *)text requestUri:(NSString *)requestUri error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("manipulateImpl(text:requestUri:)")));
- (NSString *)doNew_manipulateResponseBody:(NSString *)responseBody isAudio:(BOOL)isAudio requestUri:(NSString *)requestUri __attribute__((swift_name("doNew_manipulate(responseBody:isAudio:requestUri:)")));
@property Sdk_coreVariant * _Nullable variant __attribute__((swift_name("variant")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlaylistManipulator.Companion")))
@interface Sdk_coreMediaPlaylistManipulatorCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreMediaPlaylistManipulatorCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *CUE_IN_TYPE __attribute__((swift_name("CUE_IN_TYPE")));
@property (readonly) NSString *CUE_OUT_TYPE __attribute__((swift_name("CUE_OUT_TYPE")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlaylistManipulator.CueEvent")))
@interface Sdk_coreMediaPlaylistManipulatorCueEvent : Sdk_coreBase
- (instancetype)initWithCueOutMarker:(Sdk_coreMediaPlaylistManipulatorCueOutMarker *)cueOutMarker cueInMarker:(Sdk_coreMediaPlaylistManipulatorCueInMarker * _Nullable)cueInMarker previousCueEvent:(Sdk_coreMediaPlaylistManipulatorCueEvent * _Nullable)previousCueEvent originalMediaSegmentDurations:(Sdk_coreMutableDictionary<Sdk_coreLong *, Sdk_coreLong *> *)originalMediaSegmentDurations __attribute__((swift_name("init(cueOutMarker:cueInMarker:previousCueEvent:originalMediaSegmentDurations:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreMediaPlaylistManipulatorCueEvent *)doCopyCueOutMarker:(Sdk_coreMediaPlaylistManipulatorCueOutMarker *)cueOutMarker cueInMarker:(Sdk_coreMediaPlaylistManipulatorCueInMarker * _Nullable)cueInMarker previousCueEvent:(Sdk_coreMediaPlaylistManipulatorCueEvent * _Nullable)previousCueEvent originalMediaSegmentDurations:(Sdk_coreMutableDictionary<Sdk_coreLong *, Sdk_coreLong *> *)originalMediaSegmentDurations __attribute__((swift_name("doCopy(cueOutMarker:cueInMarker:previousCueEvent:originalMediaSegmentDurations:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property Sdk_coreMediaPlaylistManipulatorCueInMarker * _Nullable cueInMarker __attribute__((swift_name("cueInMarker")));
@property (readonly) Sdk_coreMediaPlaylistManipulatorCueOutMarker *cueOutMarker __attribute__((swift_name("cueOutMarker")));
@property (readonly) Sdk_coreMutableDictionary<Sdk_coreLong *, Sdk_coreLong *> *originalMediaSegmentDurations __attribute__((swift_name("originalMediaSegmentDurations")));
@property Sdk_coreMediaPlaylistManipulatorCueEvent * _Nullable previousCueEvent __attribute__((swift_name("previousCueEvent")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlaylistManipulator.CueInMarker")))
@interface Sdk_coreMediaPlaylistManipulatorCueInMarker : Sdk_coreBase
- (instancetype)initWithMediaSequence:(int64_t)mediaSequence __attribute__((swift_name("init(mediaSequence:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreMediaPlaylistManipulatorCueInMarker *)doCopyMediaSequence:(int64_t)mediaSequence __attribute__((swift_name("doCopy(mediaSequence:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t mediaSequence __attribute__((swift_name("mediaSequence")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlaylistManipulator.CueOutMarker")))
@interface Sdk_coreMediaPlaylistManipulatorCueOutMarker : Sdk_coreBase
- (instancetype)initWithDuration:(int64_t)duration uniqueProgramId:(int32_t)uniqueProgramId eventId:(int32_t)eventId encodeScte35:(NSString *)encodeScte35 mediaSequence:(int64_t)mediaSequence adPrefix:(NSString * _Nullable)adPrefix __attribute__((swift_name("init(duration:uniqueProgramId:eventId:encodeScte35:mediaSequence:adPrefix:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreMediaPlaylistManipulatorCueOutMarker *)doCopyDuration:(int64_t)duration uniqueProgramId:(int32_t)uniqueProgramId eventId:(int32_t)eventId encodeScte35:(NSString *)encodeScte35 mediaSequence:(int64_t)mediaSequence adPrefix:(NSString * _Nullable)adPrefix __attribute__((swift_name("doCopy(duration:uniqueProgramId:eventId:encodeScte35:mediaSequence:adPrefix:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable adPrefix __attribute__((swift_name("adPrefix")));
@property int64_t duration __attribute__((swift_name("duration")));
@property (readonly) NSString *encodeScte35 __attribute__((swift_name("encodeScte35")));
@property (readonly) int32_t eventId __attribute__((swift_name("eventId")));
@property (readonly) int64_t mediaSequence __attribute__((swift_name("mediaSequence")));
@property (readonly) int32_t uniqueProgramId __attribute__((swift_name("uniqueProgramId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlaylistManipulator.HistoryMediaSegment")))
@interface Sdk_coreMediaPlaylistManipulatorHistoryMediaSegment : Sdk_coreBase
- (instancetype)initWithMediaSequence:(int64_t)mediaSequence discontinuityMediaSequence:(int64_t)discontinuityMediaSequence disappeared:(BOOL)disappeared mediaSegments:(Sdk_coreMutableSet<Sdk_coreMediaSegment *> *)mediaSegments mediaSegmentUrls:(Sdk_coreMutableSet<NSString *> *)mediaSegmentUrls originalMediaSequence:(Sdk_coreLong * _Nullable)originalMediaSequence accumulatedDuration:(int64_t)accumulatedDuration disappearedAt:(int64_t)disappearedAt __attribute__((swift_name("init(mediaSequence:discontinuityMediaSequence:disappeared:mediaSegments:mediaSegmentUrls:originalMediaSequence:accumulatedDuration:disappearedAt:)"))) __attribute__((objc_designated_initializer));
- (void)addMediaSegment:(Sdk_coreMediaSegment *)mediaSegment __attribute__((swift_name("add(mediaSegment:)")));
- (BOOL)containsUri:(NSString *)uri __attribute__((swift_name("contains(uri:)")));
- (BOOL)containsMediaSegment:(Sdk_coreMediaSegment *)mediaSegment __attribute__((swift_name("contains(mediaSegment:)")));
- (Sdk_coreMediaPlaylistManipulatorHistoryMediaSegment *)doCopyMediaSequence:(int64_t)mediaSequence discontinuityMediaSequence:(int64_t)discontinuityMediaSequence disappeared:(BOOL)disappeared mediaSegments:(Sdk_coreMutableSet<Sdk_coreMediaSegment *> *)mediaSegments mediaSegmentUrls:(Sdk_coreMutableSet<NSString *> *)mediaSegmentUrls originalMediaSequence:(Sdk_coreLong * _Nullable)originalMediaSequence accumulatedDuration:(int64_t)accumulatedDuration disappearedAt:(int64_t)disappearedAt __attribute__((swift_name("doCopy(mediaSequence:discontinuityMediaSequence:disappeared:mediaSegments:mediaSegmentUrls:originalMediaSequence:accumulatedDuration:disappearedAt:)")));
- (int64_t)duration __attribute__((swift_name("duration()")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t accumulatedDuration __attribute__((swift_name("accumulatedDuration")));
@property BOOL disappeared __attribute__((swift_name("disappeared")));
@property int64_t disappearedAt __attribute__((swift_name("disappearedAt")));
@property int64_t discontinuityMediaSequence __attribute__((swift_name("discontinuityMediaSequence")));
@property (readonly) Sdk_coreMutableSet<NSString *> *mediaSegmentUrls __attribute__((swift_name("mediaSegmentUrls")));
@property (readonly) Sdk_coreMutableSet<Sdk_coreMediaSegment *> *mediaSegments __attribute__((swift_name("mediaSegments")));
@property (readonly) int64_t mediaSequence __attribute__((swift_name("mediaSequence")));
@property (readonly) Sdk_coreLong * _Nullable originalMediaSequence __attribute__((swift_name("originalMediaSequence")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaSegmentAssumeService")))
@interface Sdk_coreMediaSegmentAssumeService : Sdk_coreBase
- (instancetype)initWithMediaPlayerAdapter:(id<Sdk_coreMediaPlayerAdapter>)mediaPlayerAdapter __attribute__((swift_name("init(mediaPlayerAdapter:)"))) __attribute__((objc_designated_initializer));
- (id<Sdk_coreMediaChunkStub>)assumeSegmentUrlMediaChunkStub:(id<Sdk_coreMediaChunkStub>)mediaChunkStub __attribute__((swift_name("assumeSegmentUrl(mediaChunkStub:)")));
@property (readonly) Sdk_coreMutableDictionary<Sdk_coreLong *, Sdk_coreMediaPlaylistManipulatorHistoryMediaSegment *> *responseSegments __attribute__((swift_name("responseSegments")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AlternativeRendition")))
@interface Sdk_coreAlternativeRendition : Sdk_coreBase
- (instancetype)initWithType:(Sdk_coreMediaType *)type uri:(NSString * _Nullable)uri groupId:(NSString *)groupId language:(NSString * _Nullable)language assocLanguage:(NSString * _Nullable)assocLanguage name:(NSString *)name stableRenditionId:(NSString * _Nullable)stableRenditionId defaultRendition:(Sdk_coreBoolean * _Nullable)defaultRendition autoSelect:(Sdk_coreBoolean * _Nullable)autoSelect forced:(Sdk_coreBoolean * _Nullable)forced inStreamId:(NSString * _Nullable)inStreamId characteristics:(NSArray<NSString *> *)characteristics channels:(Sdk_coreChannels * _Nullable)channels __attribute__((swift_name("init(type:uri:groupId:language:assocLanguage:name:stableRenditionId:defaultRendition:autoSelect:forced:inStreamId:characteristics:channels:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreAlternativeRendition *)doCopyType:(Sdk_coreMediaType *)type uri:(NSString * _Nullable)uri groupId:(NSString *)groupId language:(NSString * _Nullable)language assocLanguage:(NSString * _Nullable)assocLanguage name:(NSString *)name stableRenditionId:(NSString * _Nullable)stableRenditionId defaultRendition:(Sdk_coreBoolean * _Nullable)defaultRendition autoSelect:(Sdk_coreBoolean * _Nullable)autoSelect forced:(Sdk_coreBoolean * _Nullable)forced inStreamId:(NSString * _Nullable)inStreamId characteristics:(NSArray<NSString *> *)characteristics channels:(Sdk_coreChannels * _Nullable)channels __attribute__((swift_name("doCopy(type:uri:groupId:language:assocLanguage:name:stableRenditionId:defaultRendition:autoSelect:forced:inStreamId:characteristics:channels:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable assocLanguage __attribute__((swift_name("assocLanguage")));
@property Sdk_coreBoolean * _Nullable autoSelect __attribute__((swift_name("autoSelect")));
@property Sdk_coreChannels * _Nullable channels __attribute__((swift_name("channels")));
@property NSArray<NSString *> *characteristics __attribute__((swift_name("characteristics")));
@property Sdk_coreBoolean * _Nullable defaultRendition __attribute__((swift_name("defaultRendition")));
@property Sdk_coreBoolean * _Nullable forced __attribute__((swift_name("forced")));
@property NSString *groupId __attribute__((swift_name("groupId")));
@property NSString * _Nullable inStreamId __attribute__((swift_name("inStreamId")));
@property NSString * _Nullable language __attribute__((swift_name("language")));
@property NSString *name __attribute__((swift_name("name")));
@property NSString * _Nullable stableRenditionId __attribute__((swift_name("stableRenditionId")));
@property Sdk_coreMediaType *type __attribute__((swift_name("type")));
@property NSString * _Nullable uri __attribute__((swift_name("uri")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ByteRange")))
@interface Sdk_coreByteRange : Sdk_coreBase
- (instancetype)initWithLength:(int64_t)length offset:(Sdk_coreLong * _Nullable)offset __attribute__((swift_name("init(length:offset:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreByteRange *)doCopyLength:(int64_t)length offset:(Sdk_coreLong * _Nullable)offset __attribute__((swift_name("doCopy(length:offset:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property int64_t length __attribute__((swift_name("length")));
@property Sdk_coreLong * _Nullable offset __attribute__((swift_name("offset")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Channels")))
@interface Sdk_coreChannels : Sdk_coreBase
- (instancetype)initWithCount:(int32_t)count objectCodingIdentifiers:(NSArray<NSString *> *)objectCodingIdentifiers __attribute__((swift_name("init(count:objectCodingIdentifiers:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreChannels *)doCopyCount:(int32_t)count objectCodingIdentifiers:(NSArray<NSString *> *)objectCodingIdentifiers __attribute__((swift_name("doCopy(count:objectCodingIdentifiers:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property int32_t count __attribute__((swift_name("count")));
@property NSArray<NSString *> *objectCodingIdentifiers __attribute__((swift_name("objectCodingIdentifiers")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CueOut")))
@interface Sdk_coreCueOut : Sdk_coreBase
- (instancetype)initWithDuration:(double)duration adPrefix:(NSString * _Nullable)adPrefix __attribute__((swift_name("init(duration:adPrefix:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreCueOut *)doCopyDuration:(double)duration adPrefix:(NSString * _Nullable)adPrefix __attribute__((swift_name("doCopy(duration:adPrefix:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable adPrefix __attribute__((swift_name("adPrefix")));
@property double duration __attribute__((swift_name("duration")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CueOutCont")))
@interface Sdk_coreCueOutCont : Sdk_coreBase
- (instancetype)initWithElapsedTime:(float)elapsedTime duration:(float)duration scte35:(Sdk_coreScte35 * _Nullable)scte35 adPrefix:(NSString * _Nullable)adPrefix __attribute__((swift_name("init(elapsedTime:duration:scte35:adPrefix:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreCueOutCont *)doCopyElapsedTime:(float)elapsedTime duration:(float)duration scte35:(Sdk_coreScte35 * _Nullable)scte35 adPrefix:(NSString * _Nullable)adPrefix __attribute__((swift_name("doCopy(elapsedTime:duration:scte35:adPrefix:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable adPrefix __attribute__((swift_name("adPrefix")));
@property float duration __attribute__((swift_name("duration")));
@property float elapsedTime __attribute__((swift_name("elapsedTime")));
@property Sdk_coreScte35 * _Nullable scte35 __attribute__((swift_name("scte35")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateRange")))
@interface Sdk_coreDateRange : Sdk_coreBase
- (instancetype)initWithId:(NSString *)id classAttribute:(NSString * _Nullable)classAttribute startDate:(Sdk_coreOffsetDateTime *)startDate endDate:(Sdk_coreOffsetDateTime * _Nullable)endDate duration:(Sdk_coreDouble * _Nullable)duration plannedDuration:(Sdk_coreDouble * _Nullable)plannedDuration clientAttributes:(Sdk_coreMutableDictionary<NSString *, NSString *> *)clientAttributes scte35Cmd:(NSString * _Nullable)scte35Cmd scte35Out:(NSString * _Nullable)scte35Out scte35In:(NSString * _Nullable)scte35In endOnNext:(BOOL)endOnNext __attribute__((swift_name("init(id:classAttribute:startDate:endDate:duration:plannedDuration:clientAttributes:scte35Cmd:scte35Out:scte35In:endOnNext:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreDateRange *)doCopyId:(NSString *)id classAttribute:(NSString * _Nullable)classAttribute startDate:(Sdk_coreOffsetDateTime *)startDate endDate:(Sdk_coreOffsetDateTime * _Nullable)endDate duration:(Sdk_coreDouble * _Nullable)duration plannedDuration:(Sdk_coreDouble * _Nullable)plannedDuration clientAttributes:(Sdk_coreMutableDictionary<NSString *, NSString *> *)clientAttributes scte35Cmd:(NSString * _Nullable)scte35Cmd scte35Out:(NSString * _Nullable)scte35Out scte35In:(NSString * _Nullable)scte35In endOnNext:(BOOL)endOnNext __attribute__((swift_name("doCopy(id:classAttribute:startDate:endDate:duration:plannedDuration:clientAttributes:scte35Cmd:scte35Out:scte35In:endOnNext:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable classAttribute __attribute__((swift_name("classAttribute")));
@property Sdk_coreMutableDictionary<NSString *, NSString *> *clientAttributes __attribute__((swift_name("clientAttributes")));
@property Sdk_coreDouble * _Nullable duration __attribute__((swift_name("duration")));
@property Sdk_coreOffsetDateTime * _Nullable endDate __attribute__((swift_name("endDate")));
@property BOOL endOnNext __attribute__((swift_name("endOnNext")));
@property NSString *id __attribute__((swift_name("id")));
@property Sdk_coreDouble * _Nullable plannedDuration __attribute__((swift_name("plannedDuration")));
@property NSString * _Nullable scte35Cmd __attribute__((swift_name("scte35Cmd")));
@property NSString * _Nullable scte35In __attribute__((swift_name("scte35In")));
@property NSString * _Nullable scte35Out __attribute__((swift_name("scte35Out")));
@property Sdk_coreOffsetDateTime *startDate __attribute__((swift_name("startDate")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IFrameVariant")))
@interface Sdk_coreIFrameVariant : Sdk_coreBase
- (instancetype)initWithUri:(NSString *)uri bandwidth:(int64_t)bandwidth averageBandwidth:(Sdk_coreLong * _Nullable)averageBandwidth score:(Sdk_coreDouble * _Nullable)score codecs:(NSArray<NSString *> *)codecs resolution:(Sdk_coreResolution * _Nullable)resolution hdcpLevel:(NSString * _Nullable)hdcpLevel allowedCpc:(NSArray<NSString *> *)allowedCpc stableVariantId:(NSString * _Nullable)stableVariantId video:(NSString * _Nullable)video programId:(Sdk_coreInt * _Nullable)programId videoRange:(Sdk_coreVideoRange * _Nullable)videoRange name:(NSString * _Nullable)name language:(NSString * _Nullable)language __attribute__((swift_name("init(uri:bandwidth:averageBandwidth:score:codecs:resolution:hdcpLevel:allowedCpc:stableVariantId:video:programId:videoRange:name:language:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreIFrameVariant *)doCopyUri:(NSString *)uri bandwidth:(int64_t)bandwidth averageBandwidth:(Sdk_coreLong * _Nullable)averageBandwidth score:(Sdk_coreDouble * _Nullable)score codecs:(NSArray<NSString *> *)codecs resolution:(Sdk_coreResolution * _Nullable)resolution hdcpLevel:(NSString * _Nullable)hdcpLevel allowedCpc:(NSArray<NSString *> *)allowedCpc stableVariantId:(NSString * _Nullable)stableVariantId video:(NSString * _Nullable)video programId:(Sdk_coreInt * _Nullable)programId videoRange:(Sdk_coreVideoRange * _Nullable)videoRange name:(NSString * _Nullable)name language:(NSString * _Nullable)language __attribute__((swift_name("doCopy(uri:bandwidth:averageBandwidth:score:codecs:resolution:hdcpLevel:allowedCpc:stableVariantId:video:programId:videoRange:name:language:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSArray<NSString *> *allowedCpc __attribute__((swift_name("allowedCpc")));
@property Sdk_coreLong * _Nullable averageBandwidth __attribute__((swift_name("averageBandwidth")));
@property int64_t bandwidth __attribute__((swift_name("bandwidth")));
@property NSArray<NSString *> *codecs __attribute__((swift_name("codecs")));
@property NSString * _Nullable hdcpLevel __attribute__((swift_name("hdcpLevel")));
@property NSString * _Nullable language __attribute__((swift_name("language")));
@property NSString * _Nullable name __attribute__((swift_name("name")));
@property Sdk_coreInt * _Nullable programId __attribute__((swift_name("programId")));
@property Sdk_coreResolution * _Nullable resolution __attribute__((swift_name("resolution")));
@property Sdk_coreDouble * _Nullable score __attribute__((swift_name("score")));
@property NSString * _Nullable stableVariantId __attribute__((swift_name("stableVariantId")));
@property NSString *uri __attribute__((swift_name("uri")));
@property NSString * _Nullable video __attribute__((swift_name("video")));
@property Sdk_coreVideoRange * _Nullable videoRange __attribute__((swift_name("videoRange")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KeyMethod")))
@interface Sdk_coreKeyMethod : Sdk_coreKotlinEnum<Sdk_coreKeyMethod *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKeyMethodCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreKeyMethod *none __attribute__((swift_name("none")));
@property (class, readonly) Sdk_coreKeyMethod *aes128 __attribute__((swift_name("aes128")));
@property (class, readonly) Sdk_coreKeyMethod *sampleAes __attribute__((swift_name("sampleAes")));
+ (Sdk_coreKotlinArray<Sdk_coreKeyMethod *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreKeyMethod *> *entries __attribute__((swift_name("entries")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KeyMethod.Companion")))
@interface Sdk_coreKeyMethodCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKeyMethodCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreKeyMethod *)parseName:(NSString *)name __attribute__((swift_name("parse(name:)")));
@end

__attribute__((swift_name("Playlist")))
@interface Sdk_corePlaylist : Sdk_coreBase
- (instancetype)initWithVersion:(Sdk_coreInt * _Nullable)version independentSegments:(BOOL)independentSegments startTimeOffset:(Sdk_coreStartTimeOffset * _Nullable)startTimeOffset variables:(NSMutableArray<Sdk_corePlaylistVariable *> *)variables comments:(NSMutableArray<NSString *> *)comments __attribute__((swift_name("init(version:independentSegments:startTimeOffset:variables:comments:)"))) __attribute__((objc_designated_initializer));
@property NSMutableArray<NSString *> *comments __attribute__((swift_name("comments")));
@property BOOL independentSegments __attribute__((swift_name("independentSegments")));
@property Sdk_coreStartTimeOffset * _Nullable startTimeOffset __attribute__((swift_name("startTimeOffset")));
@property NSMutableArray<Sdk_corePlaylistVariable *> *variables __attribute__((swift_name("variables")));
@property Sdk_coreInt * _Nullable version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MasterPlaylist")))
@interface Sdk_coreMasterPlaylist : Sdk_corePlaylist
- (instancetype)initWithAlternativeRenditions:(NSMutableArray<Sdk_coreAlternativeRendition *> *)alternativeRenditions variants:(NSMutableArray<Sdk_coreVariant *> *)variants iFrameVariants:(NSMutableArray<Sdk_coreIFrameVariant *> *)iFrameVariants sessionData:(NSMutableArray<Sdk_coreSessionData *> *)sessionData sessionKeys:(NSMutableArray<Sdk_coreSegmentKey *> *)sessionKeys version:(Sdk_coreInt * _Nullable)version independentSegments:(BOOL)independentSegments startTimeOffset:(Sdk_coreStartTimeOffset * _Nullable)startTimeOffset variables:(NSMutableArray<Sdk_corePlaylistVariable *> *)variables comments:(NSMutableArray<NSString *> *)comments __attribute__((swift_name("init(alternativeRenditions:variants:iFrameVariants:sessionData:sessionKeys:version:independentSegments:startTimeOffset:variables:comments:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithVersion:(Sdk_coreInt * _Nullable)version independentSegments:(BOOL)independentSegments startTimeOffset:(Sdk_coreStartTimeOffset * _Nullable)startTimeOffset variables:(NSMutableArray<Sdk_corePlaylistVariable *> *)variables comments:(NSMutableArray<NSString *> *)comments __attribute__((swift_name("init(version:independentSegments:startTimeOffset:variables:comments:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (Sdk_coreMasterPlaylist *)doCopyAlternativeRenditions:(NSMutableArray<Sdk_coreAlternativeRendition *> *)alternativeRenditions variants:(NSMutableArray<Sdk_coreVariant *> *)variants iFrameVariants:(NSMutableArray<Sdk_coreIFrameVariant *> *)iFrameVariants sessionData:(NSMutableArray<Sdk_coreSessionData *> *)sessionData sessionKeys:(NSMutableArray<Sdk_coreSegmentKey *> *)sessionKeys version:(Sdk_coreInt * _Nullable)version independentSegments:(BOOL)independentSegments startTimeOffset:(Sdk_coreStartTimeOffset * _Nullable)startTimeOffset variables:(NSMutableArray<Sdk_corePlaylistVariable *> *)variables comments:(NSMutableArray<NSString *> *)comments __attribute__((swift_name("doCopy(alternativeRenditions:variants:iFrameVariants:sessionData:sessionKeys:version:independentSegments:startTimeOffset:variables:comments:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSMutableArray<Sdk_coreAlternativeRendition *> *alternativeRenditions __attribute__((swift_name("alternativeRenditions")));
@property NSMutableArray<NSString *> *comments __attribute__((swift_name("comments")));
@property NSMutableArray<Sdk_coreIFrameVariant *> *iFrameVariants __attribute__((swift_name("iFrameVariants")));
@property BOOL independentSegments __attribute__((swift_name("independentSegments")));
@property NSMutableArray<Sdk_coreSessionData *> *sessionData __attribute__((swift_name("sessionData")));
@property NSMutableArray<Sdk_coreSegmentKey *> *sessionKeys __attribute__((swift_name("sessionKeys")));
@property Sdk_coreStartTimeOffset * _Nullable startTimeOffset __attribute__((swift_name("startTimeOffset")));
@property NSMutableArray<Sdk_corePlaylistVariable *> *variables __attribute__((swift_name("variables")));
@property NSMutableArray<Sdk_coreVariant *> *variants __attribute__((swift_name("variants")));
@property Sdk_coreInt * _Nullable version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlaylist")))
@interface Sdk_coreMediaPlaylist : Sdk_corePlaylist
- (instancetype)initWithTargetDuration:(int32_t)targetDuration mediaSequence:(int64_t)mediaSequence discontinuitySequence:(Sdk_coreLong * _Nullable)discontinuitySequence ongoing:(BOOL)ongoing allowCache:(Sdk_coreBoolean * _Nullable)allowCache playlistType:(Sdk_corePlaylistType * _Nullable)playlistType iFramesOnly:(BOOL)iFramesOnly mediaSegments:(NSMutableArray<Sdk_coreMediaSegment *> *)mediaSegments serverControl:(Sdk_coreServerControl * _Nullable)serverControl partialSegmentInformation:(Sdk_corePartialSegmentInformation * _Nullable)partialSegmentInformation partialSegments:(NSArray<Sdk_corePartialSegment *> *)partialSegments skip:(Sdk_coreSkip * _Nullable)skip preloadHint:(Sdk_corePreloadHint * _Nullable)preloadHint renditionReports:(NSMutableArray<Sdk_coreRenditionReport *> *)renditionReports version:(Sdk_coreInt * _Nullable)version independentSegments:(BOOL)independentSegments startTimeOffset:(Sdk_coreStartTimeOffset * _Nullable)startTimeOffset variables:(NSMutableArray<Sdk_corePlaylistVariable *> *)variables comments:(NSMutableArray<NSString *> *)comments __attribute__((swift_name("init(targetDuration:mediaSequence:discontinuitySequence:ongoing:allowCache:playlistType:iFramesOnly:mediaSegments:serverControl:partialSegmentInformation:partialSegments:skip:preloadHint:renditionReports:version:independentSegments:startTimeOffset:variables:comments:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithVersion:(Sdk_coreInt * _Nullable)version independentSegments:(BOOL)independentSegments startTimeOffset:(Sdk_coreStartTimeOffset * _Nullable)startTimeOffset variables:(NSMutableArray<Sdk_corePlaylistVariable *> *)variables comments:(NSMutableArray<NSString *> *)comments __attribute__((swift_name("init(version:independentSegments:startTimeOffset:variables:comments:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)addMediaSegmentSegmentBuilder:(Sdk_coreMediaSegment *)segmentBuilder __attribute__((swift_name("addMediaSegment(segmentBuilder:)")));
- (Sdk_coreMediaPlaylist *)doCopyTargetDuration:(int32_t)targetDuration mediaSequence:(int64_t)mediaSequence discontinuitySequence:(Sdk_coreLong * _Nullable)discontinuitySequence ongoing:(BOOL)ongoing allowCache:(Sdk_coreBoolean * _Nullable)allowCache playlistType:(Sdk_corePlaylistType * _Nullable)playlistType iFramesOnly:(BOOL)iFramesOnly mediaSegments:(NSMutableArray<Sdk_coreMediaSegment *> *)mediaSegments serverControl:(Sdk_coreServerControl * _Nullable)serverControl partialSegmentInformation:(Sdk_corePartialSegmentInformation * _Nullable)partialSegmentInformation partialSegments:(NSArray<Sdk_corePartialSegment *> *)partialSegments skip:(Sdk_coreSkip * _Nullable)skip preloadHint:(Sdk_corePreloadHint * _Nullable)preloadHint renditionReports:(NSMutableArray<Sdk_coreRenditionReport *> *)renditionReports version:(Sdk_coreInt * _Nullable)version independentSegments:(BOOL)independentSegments startTimeOffset:(Sdk_coreStartTimeOffset * _Nullable)startTimeOffset variables:(NSMutableArray<Sdk_corePlaylistVariable *> *)variables comments:(NSMutableArray<NSString *> *)comments __attribute__((swift_name("doCopy(targetDuration:mediaSequence:discontinuitySequence:ongoing:allowCache:playlistType:iFramesOnly:mediaSegments:serverControl:partialSegmentInformation:partialSegments:skip:preloadHint:renditionReports:version:independentSegments:startTimeOffset:variables:comments:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property Sdk_coreBoolean * _Nullable allowCache __attribute__((swift_name("allowCache")));
@property NSMutableArray<NSString *> *comments __attribute__((swift_name("comments")));
@property Sdk_coreLong * _Nullable discontinuitySequence __attribute__((swift_name("discontinuitySequence")));
@property BOOL iFramesOnly __attribute__((swift_name("iFramesOnly")));
@property BOOL independentSegments __attribute__((swift_name("independentSegments")));
@property NSMutableArray<Sdk_coreMediaSegment *> *mediaSegments __attribute__((swift_name("mediaSegments")));
@property int64_t mediaSequence __attribute__((swift_name("mediaSequence")));
@property BOOL ongoing __attribute__((swift_name("ongoing")));
@property Sdk_corePartialSegmentInformation * _Nullable partialSegmentInformation __attribute__((swift_name("partialSegmentInformation")));
@property NSArray<Sdk_corePartialSegment *> *partialSegments __attribute__((swift_name("partialSegments")));
@property Sdk_corePlaylistType * _Nullable playlistType __attribute__((swift_name("playlistType")));
@property Sdk_corePreloadHint * _Nullable preloadHint __attribute__((swift_name("preloadHint")));
@property NSMutableArray<Sdk_coreRenditionReport *> *renditionReports __attribute__((swift_name("renditionReports")));
@property Sdk_coreServerControl * _Nullable serverControl __attribute__((swift_name("serverControl")));
@property Sdk_coreSkip * _Nullable skip __attribute__((swift_name("skip")));
@property Sdk_coreStartTimeOffset * _Nullable startTimeOffset __attribute__((swift_name("startTimeOffset")));
@property int32_t targetDuration __attribute__((swift_name("targetDuration")));
@property NSMutableArray<Sdk_corePlaylistVariable *> *variables __attribute__((swift_name("variables")));
@property Sdk_coreInt * _Nullable version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaSegment")))
@interface Sdk_coreMediaSegment : Sdk_coreBase
- (instancetype)initWithMediaSequence:(Sdk_coreLong * _Nullable)mediaSequence duration:(double)duration title:(NSString * _Nullable)title uri:(NSString *)uri byteRange:(Sdk_coreByteRange * _Nullable)byteRange programDateTime:(Sdk_coreOffsetDateTime * _Nullable)programDateTime dateRange:(Sdk_coreDateRange * _Nullable)dateRange segmentMap:(Sdk_coreSegmentMap * _Nullable)segmentMap segmentKey:(Sdk_coreSegmentKey * _Nullable)segmentKey discontinuity:(BOOL)discontinuity cueOut:(Sdk_coreCueOut * _Nullable)cueOut cueIn:(BOOL)cueIn gap:(BOOL)gap bitrate:(Sdk_coreLong * _Nullable)bitrate partialSegments:(NSMutableArray<Sdk_corePartialSegment *> *)partialSegments scte35:(Sdk_coreScte35 * _Nullable)scte35 cueOutCont:(Sdk_coreCueOutCont * _Nullable)cueOutCont cueEventId:(int32_t)cueEventId endList:(BOOL)endList __attribute__((swift_name("init(mediaSequence:duration:title:uri:byteRange:programDateTime:dateRange:segmentMap:segmentKey:discontinuity:cueOut:cueIn:gap:bitrate:partialSegments:scte35:cueOutCont:cueEventId:endList:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreMediaSegment *)doCopyMediaSequence:(Sdk_coreLong * _Nullable)mediaSequence duration:(double)duration title:(NSString * _Nullable)title uri:(NSString *)uri byteRange:(Sdk_coreByteRange * _Nullable)byteRange programDateTime:(Sdk_coreOffsetDateTime * _Nullable)programDateTime dateRange:(Sdk_coreDateRange * _Nullable)dateRange segmentMap:(Sdk_coreSegmentMap * _Nullable)segmentMap segmentKey:(Sdk_coreSegmentKey * _Nullable)segmentKey discontinuity:(BOOL)discontinuity cueOut:(Sdk_coreCueOut * _Nullable)cueOut cueIn:(BOOL)cueIn gap:(BOOL)gap bitrate:(Sdk_coreLong * _Nullable)bitrate partialSegments:(NSMutableArray<Sdk_corePartialSegment *> *)partialSegments scte35:(Sdk_coreScte35 * _Nullable)scte35 cueOutCont:(Sdk_coreCueOutCont * _Nullable)cueOutCont cueEventId:(int32_t)cueEventId endList:(BOOL)endList __attribute__((swift_name("doCopy(mediaSequence:duration:title:uri:byteRange:programDateTime:dateRange:segmentMap:segmentKey:discontinuity:cueOut:cueIn:gap:bitrate:partialSegments:scte35:cueOutCont:cueEventId:endList:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property Sdk_coreLong * _Nullable bitrate __attribute__((swift_name("bitrate")));
@property Sdk_coreByteRange * _Nullable byteRange __attribute__((swift_name("byteRange")));
@property int32_t cueEventId __attribute__((swift_name("cueEventId")));
@property BOOL cueIn __attribute__((swift_name("cueIn")));
@property Sdk_coreCueOut * _Nullable cueOut __attribute__((swift_name("cueOut")));
@property Sdk_coreCueOutCont * _Nullable cueOutCont __attribute__((swift_name("cueOutCont")));
@property Sdk_coreDateRange * _Nullable dateRange __attribute__((swift_name("dateRange")));
@property BOOL discontinuity __attribute__((swift_name("discontinuity")));
@property double duration __attribute__((swift_name("duration")));
@property BOOL endList __attribute__((swift_name("endList")));
@property BOOL gap __attribute__((swift_name("gap")));
@property Sdk_coreLong * _Nullable mediaSequence __attribute__((swift_name("mediaSequence")));
@property NSMutableArray<Sdk_corePartialSegment *> *partialSegments __attribute__((swift_name("partialSegments")));
@property Sdk_coreOffsetDateTime * _Nullable programDateTime __attribute__((swift_name("programDateTime")));
@property Sdk_coreScte35 * _Nullable scte35 __attribute__((swift_name("scte35")));
@property Sdk_coreSegmentKey * _Nullable segmentKey __attribute__((swift_name("segmentKey")));
@property Sdk_coreSegmentMap * _Nullable segmentMap __attribute__((swift_name("segmentMap")));
@property NSString * _Nullable title __attribute__((swift_name("title")));
@property NSString *uri __attribute__((swift_name("uri")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaType")))
@interface Sdk_coreMediaType : Sdk_coreKotlinEnum<Sdk_coreMediaType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreMediaTypeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreMediaType *audio __attribute__((swift_name("audio")));
@property (class, readonly) Sdk_coreMediaType *video __attribute__((swift_name("video")));
@property (class, readonly) Sdk_coreMediaType *subtitles __attribute__((swift_name("subtitles")));
@property (class, readonly) Sdk_coreMediaType *closedCaptions __attribute__((swift_name("closedCaptions")));
+ (Sdk_coreKotlinArray<Sdk_coreMediaType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreMediaType *> *entries __attribute__((swift_name("entries")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaType.Companion")))
@interface Sdk_coreMediaTypeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreMediaTypeCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreMediaType *)parseName:(NSString *)name __attribute__((swift_name("parse(name:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PartialSegment")))
@interface Sdk_corePartialSegment : Sdk_coreBase
- (instancetype)initWithUri:(NSString *)uri duration:(double)duration independent:(BOOL)independent byterange:(Sdk_coreByteRange * _Nullable)byterange gap:(BOOL)gap __attribute__((swift_name("init(uri:duration:independent:byterange:gap:)"))) __attribute__((objc_designated_initializer));
- (Sdk_corePartialSegment *)doCopyUri:(NSString *)uri duration:(double)duration independent:(BOOL)independent byterange:(Sdk_coreByteRange * _Nullable)byterange gap:(BOOL)gap __attribute__((swift_name("doCopy(uri:duration:independent:byterange:gap:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property Sdk_coreByteRange * _Nullable byterange __attribute__((swift_name("byterange")));
@property double duration __attribute__((swift_name("duration")));
@property BOOL gap __attribute__((swift_name("gap")));
@property BOOL independent __attribute__((swift_name("independent")));
@property NSString *uri __attribute__((swift_name("uri")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PartialSegmentInformation")))
@interface Sdk_corePartialSegmentInformation : Sdk_coreBase
- (instancetype)initWithPartTargetDuration:(double)partTargetDuration __attribute__((swift_name("init(partTargetDuration:)"))) __attribute__((objc_designated_initializer));
- (Sdk_corePartialSegmentInformation *)doCopyPartTargetDuration:(double)partTargetDuration __attribute__((swift_name("doCopy(partTargetDuration:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property double partTargetDuration __attribute__((swift_name("partTargetDuration")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlaylistType")))
@interface Sdk_corePlaylistType : Sdk_coreKotlinEnum<Sdk_corePlaylistType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_corePlaylistType *event __attribute__((swift_name("event")));
@property (class, readonly) Sdk_corePlaylistType *vod __attribute__((swift_name("vod")));
+ (Sdk_coreKotlinArray<Sdk_corePlaylistType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_corePlaylistType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlaylistVariable")))
@interface Sdk_corePlaylistVariable : Sdk_coreBase
- (instancetype)initWithName:(NSString * _Nullable)name value:(NSString * _Nullable)value importAttribute:(NSString * _Nullable)importAttribute __attribute__((swift_name("init(name:value:importAttribute:)"))) __attribute__((objc_designated_initializer));
- (Sdk_corePlaylistVariable *)doCopyName:(NSString * _Nullable)name value:(NSString * _Nullable)value importAttribute:(NSString * _Nullable)importAttribute __attribute__((swift_name("doCopy(name:value:importAttribute:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable importAttribute __attribute__((swift_name("importAttribute")));
@property NSString * _Nullable name __attribute__((swift_name("name")));
@property NSString * _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PreloadHint")))
@interface Sdk_corePreloadHint : Sdk_coreBase
- (instancetype)initWithType:(Sdk_corePreloadHintType *)type uri:(NSString *)uri byteRangeStart:(Sdk_coreLong * _Nullable)byteRangeStart byteRangeLength:(Sdk_coreLong * _Nullable)byteRangeLength __attribute__((swift_name("init(type:uri:byteRangeStart:byteRangeLength:)"))) __attribute__((objc_designated_initializer));
- (Sdk_corePreloadHint *)doCopyType:(Sdk_corePreloadHintType *)type uri:(NSString *)uri byteRangeStart:(Sdk_coreLong * _Nullable)byteRangeStart byteRangeLength:(Sdk_coreLong * _Nullable)byteRangeLength __attribute__((swift_name("doCopy(type:uri:byteRangeStart:byteRangeLength:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property Sdk_coreLong * _Nullable byteRangeLength __attribute__((swift_name("byteRangeLength")));
@property Sdk_coreLong * _Nullable byteRangeStart __attribute__((swift_name("byteRangeStart")));
@property Sdk_corePreloadHintType *type __attribute__((swift_name("type")));
@property NSString *uri __attribute__((swift_name("uri")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PreloadHintType")))
@interface Sdk_corePreloadHintType : Sdk_coreKotlinEnum<Sdk_corePreloadHintType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_corePreloadHintType *part __attribute__((swift_name("part")));
@property (class, readonly) Sdk_corePreloadHintType *map __attribute__((swift_name("map")));
+ (Sdk_coreKotlinArray<Sdk_corePreloadHintType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_corePreloadHintType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RenditionReport")))
@interface Sdk_coreRenditionReport : Sdk_coreBase
- (instancetype)initWithUri:(NSString *)uri lastMediaSequenceNumber:(Sdk_coreLong * _Nullable)lastMediaSequenceNumber lastPartialSegmentIndex:(Sdk_coreLong * _Nullable)lastPartialSegmentIndex __attribute__((swift_name("init(uri:lastMediaSequenceNumber:lastPartialSegmentIndex:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreRenditionReport *)doCopyUri:(NSString *)uri lastMediaSequenceNumber:(Sdk_coreLong * _Nullable)lastMediaSequenceNumber lastPartialSegmentIndex:(Sdk_coreLong * _Nullable)lastPartialSegmentIndex __attribute__((swift_name("doCopy(uri:lastMediaSequenceNumber:lastPartialSegmentIndex:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property Sdk_coreLong * _Nullable lastMediaSequenceNumber __attribute__((swift_name("lastMediaSequenceNumber")));
@property Sdk_coreLong * _Nullable lastPartialSegmentIndex __attribute__((swift_name("lastPartialSegmentIndex")));
@property NSString *uri __attribute__((swift_name("uri")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Resolution")))
@interface Sdk_coreResolution : Sdk_coreBase
- (instancetype)initWithWidth:(int32_t)width height:(int32_t)height __attribute__((swift_name("init(width:height:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreResolution *)doCopyWidth:(int32_t)width height:(int32_t)height __attribute__((swift_name("doCopy(width:height:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property int32_t height __attribute__((swift_name("height")));
@property int32_t width __attribute__((swift_name("width")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Scte35")))
@interface Sdk_coreScte35 : Sdk_coreBase
- (instancetype)initWithCue:(NSString *)cue type:(NSString *)type elapsed:(Sdk_coreFloat * _Nullable)elapsed spliceInfoSection:(Sdk_coreSpliceInfoSection * _Nullable)spliceInfoSection __attribute__((swift_name("init(cue:type:elapsed:spliceInfoSection:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreScte35 *)doCopyCue:(NSString *)cue type:(NSString *)type elapsed:(Sdk_coreFloat * _Nullable)elapsed spliceInfoSection:(Sdk_coreSpliceInfoSection * _Nullable)spliceInfoSection __attribute__((swift_name("doCopy(cue:type:elapsed:spliceInfoSection:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString *cue __attribute__((swift_name("cue")));
@property Sdk_coreFloat * _Nullable elapsed __attribute__((swift_name("elapsed")));
@property Sdk_coreSpliceInfoSection * _Nullable spliceInfoSection __attribute__((swift_name("spliceInfoSection")));
@property NSString *type __attribute__((swift_name("type")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SegmentKey")))
@interface Sdk_coreSegmentKey : Sdk_coreBase
- (instancetype)initWithMethod:(Sdk_coreKeyMethod *)method uri:(NSString * _Nullable)uri iv:(NSString * _Nullable)iv keyFormat:(NSString * _Nullable)keyFormat keyFormatVersions:(NSString * _Nullable)keyFormatVersions __attribute__((swift_name("init(method:uri:iv:keyFormat:keyFormatVersions:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreSegmentKey *)doCopyMethod:(Sdk_coreKeyMethod *)method uri:(NSString * _Nullable)uri iv:(NSString * _Nullable)iv keyFormat:(NSString * _Nullable)keyFormat keyFormatVersions:(NSString * _Nullable)keyFormatVersions __attribute__((swift_name("doCopy(method:uri:iv:keyFormat:keyFormatVersions:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable iv __attribute__((swift_name("iv")));
@property NSString * _Nullable keyFormat __attribute__((swift_name("keyFormat")));
@property NSString * _Nullable keyFormatVersions __attribute__((swift_name("keyFormatVersions")));
@property Sdk_coreKeyMethod *method __attribute__((swift_name("method")));
@property NSString * _Nullable uri __attribute__((swift_name("uri")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SegmentMap")))
@interface Sdk_coreSegmentMap : Sdk_coreBase
- (instancetype)initWithUri:(NSString *)uri byteRange:(Sdk_coreByteRange * _Nullable)byteRange __attribute__((swift_name("init(uri:byteRange:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreSegmentMap *)doCopyUri:(NSString *)uri byteRange:(Sdk_coreByteRange * _Nullable)byteRange __attribute__((swift_name("doCopy(uri:byteRange:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property Sdk_coreByteRange * _Nullable byteRange __attribute__((swift_name("byteRange")));
@property NSString *uri __attribute__((swift_name("uri")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ServerControl")))
@interface Sdk_coreServerControl : Sdk_coreBase
- (instancetype)initWithCanSkipUntil:(Sdk_coreDouble * _Nullable)canSkipUntil canSkipDateRanges:(Sdk_coreBoolean * _Nullable)canSkipDateRanges holdBack:(Sdk_coreDouble * _Nullable)holdBack partHoldBack:(Sdk_coreDouble * _Nullable)partHoldBack canBlockReload:(BOOL)canBlockReload __attribute__((swift_name("init(canSkipUntil:canSkipDateRanges:holdBack:partHoldBack:canBlockReload:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreServerControl *)doCopyCanSkipUntil:(Sdk_coreDouble * _Nullable)canSkipUntil canSkipDateRanges:(Sdk_coreBoolean * _Nullable)canSkipDateRanges holdBack:(Sdk_coreDouble * _Nullable)holdBack partHoldBack:(Sdk_coreDouble * _Nullable)partHoldBack canBlockReload:(BOOL)canBlockReload __attribute__((swift_name("doCopy(canSkipUntil:canSkipDateRanges:holdBack:partHoldBack:canBlockReload:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property BOOL canBlockReload __attribute__((swift_name("canBlockReload")));
@property Sdk_coreBoolean * _Nullable canSkipDateRanges __attribute__((swift_name("canSkipDateRanges")));
@property Sdk_coreDouble * _Nullable canSkipUntil __attribute__((swift_name("canSkipUntil")));
@property Sdk_coreDouble * _Nullable holdBack __attribute__((swift_name("holdBack")));
@property Sdk_coreDouble * _Nullable partHoldBack __attribute__((swift_name("partHoldBack")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SessionData")))
@interface Sdk_coreSessionData : Sdk_coreBase
- (instancetype)initWithDataId:(NSString *)dataId value:(NSString * _Nullable)value uri:(NSString * _Nullable)uri language:(NSString * _Nullable)language __attribute__((swift_name("init(dataId:value:uri:language:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreSessionData *)doCopyDataId:(NSString *)dataId value:(NSString * _Nullable)value uri:(NSString * _Nullable)uri language:(NSString * _Nullable)language __attribute__((swift_name("doCopy(dataId:value:uri:language:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString *dataId __attribute__((swift_name("dataId")));
@property NSString * _Nullable language __attribute__((swift_name("language")));
@property NSString * _Nullable uri __attribute__((swift_name("uri")));
@property NSString * _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skip")))
@interface Sdk_coreSkip : Sdk_coreBase
- (instancetype)initWithSkippedSegments:(int64_t)skippedSegments recentlyRemovedDateRanges:(NSArray<NSString *> *)recentlyRemovedDateRanges __attribute__((swift_name("init(skippedSegments:recentlyRemovedDateRanges:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreSkip *)doCopySkippedSegments:(int64_t)skippedSegments recentlyRemovedDateRanges:(NSArray<NSString *> *)recentlyRemovedDateRanges __attribute__((swift_name("doCopy(skippedSegments:recentlyRemovedDateRanges:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSArray<NSString *> *recentlyRemovedDateRanges __attribute__((swift_name("recentlyRemovedDateRanges")));
@property int64_t skippedSegments __attribute__((swift_name("skippedSegments")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StartTimeOffset")))
@interface Sdk_coreStartTimeOffset : Sdk_coreBase
- (instancetype)initWithTimeOffset:(double)timeOffset precise:(BOOL)precise __attribute__((swift_name("init(timeOffset:precise:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreStartTimeOffset *)doCopyTimeOffset:(double)timeOffset precise:(BOOL)precise __attribute__((swift_name("doCopy(timeOffset:precise:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property BOOL precise __attribute__((swift_name("precise")));
@property double timeOffset __attribute__((swift_name("timeOffset")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Variant")))
@interface Sdk_coreVariant : Sdk_coreBase
- (instancetype)initWithBandwidth:(int64_t)bandwidth averageBandwidth:(Sdk_coreLong * _Nullable)averageBandwidth score:(Sdk_coreDouble * _Nullable)score codecs:(NSArray<NSString *> *)codecs resolution:(Sdk_coreResolution * _Nullable)resolution frameRate:(Sdk_coreDouble * _Nullable)frameRate hdcpLevel:(NSString * _Nullable)hdcpLevel allowedCpc:(NSArray<NSString *> *)allowedCpc stableVariantId:(NSString * _Nullable)stableVariantId audio:(NSString * _Nullable)audio video:(NSString * _Nullable)video subtitles:(NSString * _Nullable)subtitles closedCaptions:(NSString * _Nullable)closedCaptions closedCaptionsNone:(Sdk_coreBoolean * _Nullable)closedCaptionsNone uri:(NSString *)uri programId:(Sdk_coreInt * _Nullable)programId videoRange:(Sdk_coreVideoRange * _Nullable)videoRange __attribute__((swift_name("init(bandwidth:averageBandwidth:score:codecs:resolution:frameRate:hdcpLevel:allowedCpc:stableVariantId:audio:video:subtitles:closedCaptions:closedCaptionsNone:uri:programId:videoRange:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreVariant *)doCopyBandwidth:(int64_t)bandwidth averageBandwidth:(Sdk_coreLong * _Nullable)averageBandwidth score:(Sdk_coreDouble * _Nullable)score codecs:(NSArray<NSString *> *)codecs resolution:(Sdk_coreResolution * _Nullable)resolution frameRate:(Sdk_coreDouble * _Nullable)frameRate hdcpLevel:(NSString * _Nullable)hdcpLevel allowedCpc:(NSArray<NSString *> *)allowedCpc stableVariantId:(NSString * _Nullable)stableVariantId audio:(NSString * _Nullable)audio video:(NSString * _Nullable)video subtitles:(NSString * _Nullable)subtitles closedCaptions:(NSString * _Nullable)closedCaptions closedCaptionsNone:(Sdk_coreBoolean * _Nullable)closedCaptionsNone uri:(NSString *)uri programId:(Sdk_coreInt * _Nullable)programId videoRange:(Sdk_coreVideoRange * _Nullable)videoRange __attribute__((swift_name("doCopy(bandwidth:averageBandwidth:score:codecs:resolution:frameRate:hdcpLevel:allowedCpc:stableVariantId:audio:video:subtitles:closedCaptions:closedCaptionsNone:uri:programId:videoRange:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSArray<NSString *> *allowedCpc __attribute__((swift_name("allowedCpc")));
@property NSString * _Nullable audio __attribute__((swift_name("audio")));
@property Sdk_coreLong * _Nullable averageBandwidth __attribute__((swift_name("averageBandwidth")));
@property int64_t bandwidth __attribute__((swift_name("bandwidth")));
@property NSString * _Nullable closedCaptions __attribute__((swift_name("closedCaptions")));
@property Sdk_coreBoolean * _Nullable closedCaptionsNone __attribute__((swift_name("closedCaptionsNone")));
@property NSArray<NSString *> *codecs __attribute__((swift_name("codecs")));
@property Sdk_coreDouble * _Nullable frameRate __attribute__((swift_name("frameRate")));
@property NSString * _Nullable hdcpLevel __attribute__((swift_name("hdcpLevel")));
@property Sdk_coreInt * _Nullable programId __attribute__((swift_name("programId")));
@property Sdk_coreResolution * _Nullable resolution __attribute__((swift_name("resolution")));
@property Sdk_coreDouble * _Nullable score __attribute__((swift_name("score")));
@property NSString * _Nullable stableVariantId __attribute__((swift_name("stableVariantId")));
@property NSString * _Nullable subtitles __attribute__((swift_name("subtitles")));
@property NSString *uri __attribute__((swift_name("uri")));
@property NSString * _Nullable video __attribute__((swift_name("video")));
@property Sdk_coreVideoRange * _Nullable videoRange __attribute__((swift_name("videoRange")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VideoRange")))
@interface Sdk_coreVideoRange : Sdk_coreKotlinEnum<Sdk_coreVideoRange *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreVideoRange *sdr __attribute__((swift_name("sdr")));
@property (class, readonly) Sdk_coreVideoRange *pq __attribute__((swift_name("pq")));
@property (class, readonly) Sdk_coreVideoRange *hlg __attribute__((swift_name("hlg")));
+ (Sdk_coreKotlinArray<Sdk_coreVideoRange *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreVideoRange *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("AbstractPlaylistParser")))
@interface Sdk_coreAbstractPlaylistParser<T, B> : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreAbstractPlaylistParserCompanion *companion __attribute__((swift_name("companion")));
- (T)buildBuilder:(B _Nullable)builder __attribute__((swift_name("build(builder:)")));
- (B _Nullable)doNewBuilder __attribute__((swift_name("doNewBuilder()")));
- (void)onCommentBuilder:(B _Nullable)builder value:(NSString *)value __attribute__((swift_name("onComment(builder:value:)")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (BOOL)onTagBuilder:(B _Nullable)builder prefix:(NSString *)prefix attributes:(NSString *)attributes lineIterator:(id<Sdk_coreKotlinIterator>)lineIterator error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("onTag(builder:prefix:attributes:lineIterator:)")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (BOOL)onURIBuilder:(B _Nullable)builder uri:(NSString *)uri error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("onURI(builder:uri:)")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (T _Nullable)readPlaylistString:(NSString *)string error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("readPlaylist(string:)")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (T _Nullable)readPlaylistLineIterator:(id<Sdk_coreKotlinIterator>)lineIterator error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("readPlaylist(lineIterator:)")));
- (void)writePlaylist:(T)playlist textBuilder:(Sdk_coreTextBuilder *)textBuilder __attribute__((swift_name("write(playlist:textBuilder:)")));
- (NSString *)writePlaylistAsStringPlaylist:(T)playlist __attribute__((swift_name("writePlaylistAsString(playlist:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AbstractPlaylistParserCompanion")))
@interface Sdk_coreAbstractPlaylistParserCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreAbstractPlaylistParserCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Attribute")))
@protocol Sdk_coreAttribute
@required
- (NSString *)key_ __attribute__((swift_name("key()")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (BOOL)readBuilder:(id _Nullable)builder value:(NSString *)value error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("read(builder:value:)")));
- (void)readBuilder:(id _Nullable)builder key:(NSString *)key value:(NSString *)value __attribute__((swift_name("read(builder:key:value:)")));
- (void)writeValue:(id _Nullable)value textBuilder:(Sdk_coreTextBuilder *)textBuilder __attribute__((swift_name("write(value:textBuilder:)")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MasterPlaylistParser")))
@interface Sdk_coreMasterPlaylistParser : Sdk_coreAbstractPlaylistParser<Sdk_coreMasterPlaylist *, Sdk_coreMasterPlaylist *>

/**
 * @note annotations
 *   kotlin.jvm.JvmOverloads
*/
- (instancetype)initWithParsingMode:(Sdk_coreParsingMode *)parsingMode __attribute__((swift_name("init(parsingMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreMasterPlaylistParserCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreMasterPlaylist *)buildBuilder:(Sdk_coreMasterPlaylist *)builder __attribute__((swift_name("build(builder:)")));
- (Sdk_coreMasterPlaylist *)doNewBuilder __attribute__((swift_name("doNewBuilder()")));
- (void)onCommentBuilder:(Sdk_coreMasterPlaylist *)builder value:(NSString *)value __attribute__((swift_name("onComment(builder:value:)")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (BOOL)onTagBuilder:(Sdk_coreMasterPlaylist *)builder prefix:(NSString *)prefix attributes:(NSString *)attributes lineIterator:(id<Sdk_coreKotlinIterator>)lineIterator error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("onTag(builder:prefix:attributes:lineIterator:)")));
- (void)writePlaylist:(Sdk_coreMasterPlaylist *)playlist textBuilder:(Sdk_coreTextBuilder *)textBuilder __attribute__((swift_name("write(playlist:textBuilder:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MasterPlaylistParser.Companion")))
@interface Sdk_coreMasterPlaylistParserCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreMasterPlaylistParserCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlaylistParser")))
@interface Sdk_coreMediaPlaylistParser : Sdk_coreAbstractPlaylistParser<Sdk_coreMediaPlaylist *, Sdk_coreMediaPlaylistParserBuilder *>

/**
 * @note annotations
 *   kotlin.jvm.JvmOverloads
*/
- (instancetype)initWithParsingMode:(Sdk_coreParsingMode *)parsingMode __attribute__((swift_name("init(parsingMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreMediaPlaylistParserCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreMediaPlaylist *)buildBuilder:(Sdk_coreMediaPlaylistParserBuilder *)builder __attribute__((swift_name("build(builder:)")));
- (Sdk_coreMediaPlaylistParserBuilder *)doNewBuilder __attribute__((swift_name("doNewBuilder()")));
- (void)onCommentBuilder:(Sdk_coreMediaPlaylistParserBuilder *)builder value:(NSString *)value __attribute__((swift_name("onComment(builder:value:)")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (BOOL)onTagBuilder:(Sdk_coreMediaPlaylistParserBuilder *)builder prefix:(NSString *)prefix attributes:(NSString *)attributes lineIterator:(id<Sdk_coreKotlinIterator>)lineIterator error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("onTag(builder:prefix:attributes:lineIterator:)")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (BOOL)onURIBuilder:(Sdk_coreMediaPlaylistParserBuilder *)builder uri:(NSString *)uri error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("onURI(builder:uri:)")));
- (void)writePlaylist:(Sdk_coreMediaPlaylist *)playlist textBuilder:(Sdk_coreTextBuilder *)textBuilder __attribute__((swift_name("write(playlist:textBuilder:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlaylistParser.Builder")))
@interface Sdk_coreMediaPlaylistParserBuilder : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property NSMutableArray<Sdk_corePartialSegment *> *partialSegments __attribute__((swift_name("partialSegments")));
@property (readonly) Sdk_coreMediaPlaylist *playlistBuilder __attribute__((swift_name("playlistBuilder")));
@property Sdk_coreMediaSegment *segmentBuilder __attribute__((swift_name("segmentBuilder")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlaylistParser.Companion")))
@interface Sdk_coreMediaPlaylistParserCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreMediaPlaylistParserCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ParsingMode")))
@interface Sdk_coreParsingMode : Sdk_coreBase
@property (class, readonly, getter=companion) Sdk_coreParsingModeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)failOnUnknownAttributes __attribute__((swift_name("failOnUnknownAttributes()")));
- (BOOL)failOnUnknownTags __attribute__((swift_name("failOnUnknownTags()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ParsingMode.Companion")))
@interface Sdk_coreParsingModeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreParsingModeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreParsingMode *LENIENT __attribute__((swift_name("LENIENT")));
@property (readonly) Sdk_coreParsingMode *STRICT __attribute__((swift_name("STRICT")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PartialSegmentAttribute")))
@interface Sdk_corePartialSegmentAttribute : Sdk_coreKotlinEnum<Sdk_corePartialSegmentAttribute *> <Sdk_coreAttribute>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_corePartialSegmentAttributeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_corePartialSegmentAttribute *uri __attribute__((swift_name("uri")));
@property (class, readonly) Sdk_corePartialSegmentAttribute *duration __attribute__((swift_name("duration")));
@property (class, readonly) Sdk_corePartialSegmentAttribute *independent __attribute__((swift_name("independent")));
@property (class, readonly) Sdk_corePartialSegmentAttribute *byterange __attribute__((swift_name("byterange")));
@property (class, readonly) Sdk_corePartialSegmentAttribute *gap __attribute__((swift_name("gap")));
+ (Sdk_coreKotlinArray<Sdk_corePartialSegmentAttribute *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_corePartialSegmentAttribute *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PartialSegmentAttribute.Companion")))
@interface Sdk_corePartialSegmentAttributeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_corePartialSegmentAttributeCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (Sdk_corePartialSegment * _Nullable)parseAttributes:(NSString *)attributes parsingMode:(Sdk_coreParsingMode *)parsingMode error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("parse(attributes:parsingMode:)")));
@property (readonly) NSDictionary<NSString *, Sdk_corePartialSegmentAttribute *> *attributeMap __attribute__((swift_name("attributeMap")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PartialSegmentInformationAttribute")))
@interface Sdk_corePartialSegmentInformationAttribute : Sdk_coreKotlinEnum<Sdk_corePartialSegmentInformationAttribute *> <Sdk_coreAttribute>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_corePartialSegmentInformationAttributeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_corePartialSegmentInformationAttribute *partTarget __attribute__((swift_name("partTarget")));
+ (Sdk_coreKotlinArray<Sdk_corePartialSegmentInformationAttribute *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_corePartialSegmentInformationAttribute *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PartialSegmentInformationAttribute.Companion")))
@interface Sdk_corePartialSegmentInformationAttributeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_corePartialSegmentInformationAttributeCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (Sdk_corePartialSegmentInformation * _Nullable)parseAttributes:(NSString *)attributes parsingMode:(Sdk_coreParsingMode *)parsingMode error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("parse(attributes:parsingMode:)")));
@property (readonly) NSDictionary<NSString *, Sdk_corePartialSegmentInformationAttribute *> *attributeMap __attribute__((swift_name("attributeMap")));
@end

__attribute__((swift_name("Ktor_ioIOException")))
@interface Sdk_coreKtor_ioIOException : Sdk_coreKotlinException
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString *)message cause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithCause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlaylistParserException")))
@interface Sdk_corePlaylistParserException : Sdk_coreKtor_ioIOException
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString *)message cause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlaylistVariableAttribute")))
@interface Sdk_corePlaylistVariableAttribute : Sdk_coreKotlinEnum<Sdk_corePlaylistVariableAttribute *> <Sdk_coreAttribute>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_corePlaylistVariableAttributeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_corePlaylistVariableAttribute *name __attribute__((swift_name("name")));
@property (class, readonly) Sdk_corePlaylistVariableAttribute *value __attribute__((swift_name("value")));
@property (class, readonly) Sdk_corePlaylistVariableAttribute *import __attribute__((swift_name("import")));
+ (Sdk_coreKotlinArray<Sdk_corePlaylistVariableAttribute *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_corePlaylistVariableAttribute *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlaylistVariableAttribute.Companion")))
@interface Sdk_corePlaylistVariableAttributeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_corePlaylistVariableAttributeCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (Sdk_corePlaylistVariable * _Nullable)parseAttributes:(NSString *)attributes parsingMode:(Sdk_coreParsingMode *)parsingMode error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("parse(attributes:parsingMode:)")));
@property (readonly) NSDictionary<NSString *, Sdk_corePlaylistVariableAttribute *> *attributeMap __attribute__((swift_name("attributeMap")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PreloadHintAttribute")))
@interface Sdk_corePreloadHintAttribute : Sdk_coreKotlinEnum<Sdk_corePreloadHintAttribute *> <Sdk_coreAttribute>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_corePreloadHintAttributeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_corePreloadHintAttribute *type __attribute__((swift_name("type")));
@property (class, readonly) Sdk_corePreloadHintAttribute *uri __attribute__((swift_name("uri")));
@property (class, readonly) Sdk_corePreloadHintAttribute *byterangeStart __attribute__((swift_name("byterangeStart")));
@property (class, readonly) Sdk_corePreloadHintAttribute *byterangeLength __attribute__((swift_name("byterangeLength")));
+ (Sdk_coreKotlinArray<Sdk_corePreloadHintAttribute *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_corePreloadHintAttribute *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PreloadHintAttribute.Companion")))
@interface Sdk_corePreloadHintAttributeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_corePreloadHintAttributeCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (Sdk_corePreloadHint * _Nullable)parseAttributes:(NSString *)attributes parsingMode:(Sdk_coreParsingMode *)parsingMode error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("parse(attributes:parsingMode:)")));
@property (readonly) NSDictionary<NSString *, Sdk_corePreloadHintAttribute *> *attributeMap __attribute__((swift_name("attributeMap")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RenditionReportAttribute")))
@interface Sdk_coreRenditionReportAttribute : Sdk_coreKotlinEnum<Sdk_coreRenditionReportAttribute *> <Sdk_coreAttribute>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreRenditionReportAttributeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreRenditionReportAttribute *uri __attribute__((swift_name("uri")));
@property (class, readonly) Sdk_coreRenditionReportAttribute *lastMsn __attribute__((swift_name("lastMsn")));
@property (class, readonly) Sdk_coreRenditionReportAttribute *lastPart __attribute__((swift_name("lastPart")));
+ (Sdk_coreKotlinArray<Sdk_coreRenditionReportAttribute *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreRenditionReportAttribute *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RenditionReportAttribute.Companion")))
@interface Sdk_coreRenditionReportAttributeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreRenditionReportAttributeCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (Sdk_coreRenditionReport * _Nullable)parseAttributes:(NSString *)attributes parsingMode:(Sdk_coreParsingMode *)parsingMode error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("parse(attributes:parsingMode:)")));
@property (readonly) NSDictionary<NSString *, Sdk_coreRenditionReportAttribute *> *attributeMap __attribute__((swift_name("attributeMap")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SegmentKeyAttribute")))
@interface Sdk_coreSegmentKeyAttribute : Sdk_coreKotlinEnum<Sdk_coreSegmentKeyAttribute *> <Sdk_coreAttribute>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreSegmentKeyAttributeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreSegmentKeyAttribute *method __attribute__((swift_name("method")));
@property (class, readonly) Sdk_coreSegmentKeyAttribute *uri __attribute__((swift_name("uri")));
@property (class, readonly) Sdk_coreSegmentKeyAttribute *iv __attribute__((swift_name("iv")));
@property (class, readonly) Sdk_coreSegmentKeyAttribute *keyformat __attribute__((swift_name("keyformat")));
@property (class, readonly) Sdk_coreSegmentKeyAttribute *keyformatversions __attribute__((swift_name("keyformatversions")));
+ (Sdk_coreKotlinArray<Sdk_coreSegmentKeyAttribute *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreSegmentKeyAttribute *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SegmentKeyAttribute.Companion")))
@interface Sdk_coreSegmentKeyAttributeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreSegmentKeyAttributeCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (Sdk_coreSegmentKey * _Nullable)parseAttributes:(NSString *)attributes parsingMode:(Sdk_coreParsingMode *)parsingMode error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("parse(attributes:parsingMode:)")));
@property (readonly) NSDictionary<NSString *, Sdk_coreSegmentKeyAttribute *> *attributeMap __attribute__((swift_name("attributeMap")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ServerControlAttribute")))
@interface Sdk_coreServerControlAttribute : Sdk_coreKotlinEnum<Sdk_coreServerControlAttribute *> <Sdk_coreAttribute>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreServerControlAttributeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreServerControlAttribute *canSkipUntil __attribute__((swift_name("canSkipUntil")));
@property (class, readonly) Sdk_coreServerControlAttribute *canSkipDateranges __attribute__((swift_name("canSkipDateranges")));
@property (class, readonly) Sdk_coreServerControlAttribute *holdBack __attribute__((swift_name("holdBack")));
@property (class, readonly) Sdk_coreServerControlAttribute *partHoldBack __attribute__((swift_name("partHoldBack")));
@property (class, readonly) Sdk_coreServerControlAttribute *canBlockReload __attribute__((swift_name("canBlockReload")));
+ (Sdk_coreKotlinArray<Sdk_coreServerControlAttribute *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreServerControlAttribute *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ServerControlAttribute.Companion")))
@interface Sdk_coreServerControlAttributeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreServerControlAttributeCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (Sdk_coreServerControl * _Nullable)parseAttributes:(NSString *)attributes parsingMode:(Sdk_coreParsingMode *)parsingMode error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("parse(attributes:parsingMode:)")));
@property (readonly) NSDictionary<NSString *, Sdk_coreServerControlAttribute *> *attributeMap __attribute__((swift_name("attributeMap")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkipAttribute")))
@interface Sdk_coreSkipAttribute : Sdk_coreKotlinEnum<Sdk_coreSkipAttribute *> <Sdk_coreAttribute>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreSkipAttributeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreSkipAttribute *skippedSegments __attribute__((swift_name("skippedSegments")));
@property (class, readonly) Sdk_coreSkipAttribute *recentlyRemovedDateranges __attribute__((swift_name("recentlyRemovedDateranges")));
+ (Sdk_coreKotlinArray<Sdk_coreSkipAttribute *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreSkipAttribute *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkipAttribute.Companion")))
@interface Sdk_coreSkipAttributeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreSkipAttributeCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note This method converts instances of PlaylistParserException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (Sdk_coreSkip * _Nullable)parseAttributes:(NSString *)attributes parsingMode:(Sdk_coreParsingMode *)parsingMode error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("parse(attributes:parsingMode:)")));
@property (readonly) NSDictionary<NSString *, Sdk_coreSkipAttribute *> *attributeMap __attribute__((swift_name("attributeMap")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TextBuilder")))
@interface Sdk_coreTextBuilder : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithStringBuilder:(Sdk_coreKotlinStringBuilder *)stringBuilder __attribute__((swift_name("init(stringBuilder:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreTextBuilder *)addCh:(unichar)ch __attribute__((swift_name("add(ch:)")));
- (Sdk_coreTextBuilder *)addValue:(double)value __attribute__((swift_name("add(value:)")));
- (Sdk_coreTextBuilder *)addText:(NSString *)text __attribute__((swift_name("add(text:)")));
- (void)addKey:(NSString *)key value:(BOOL)value __attribute__((swift_name("add(key:value:)")));
- (void)addKey:(NSString *)key value_:(double)value __attribute__((swift_name("add(key:value_:)")));
- (void)addKey:(NSString *)key value__:(Sdk_coreKotlinEnum<id> *)value __attribute__((swift_name("add(key:value__:)")));
- (void)addKey:(NSString *)key value___:(NSString *)value __attribute__((swift_name("add(key:value___:)")));
- (void)addQuotedKey:(NSString *)key value:(NSString *)value __attribute__((swift_name("addQuoted(key:value:)")));
- (void)addTagTag:(NSString *)tag __attribute__((swift_name("addTag(tag:)")));
- (void)addTagTag:(NSString *)tag attribute:(int32_t)attribute __attribute__((swift_name("addTag(tag:attribute:)")));
- (void)addTagTag:(NSString *)tag attribute_:(int64_t)attribute __attribute__((swift_name("addTag(tag:attribute_:)")));
- (void)addTagTag:(NSString *)tag attribute__:(NSString *)attribute __attribute__((swift_name("addTag(tag:attribute__:)")));
- (Sdk_coreTextBuilder *)addTagTag:(NSString *)tag value:(id _Nullable)value attributeMap:(NSDictionary<NSString *, id<Sdk_coreAttribute>> *)attributeMap __attribute__((swift_name("addTag(tag:value:attributeMap:)")));
- (void)addTagTag:(NSString *)tag values:(NSArray<id> *)values attributeMap:(NSDictionary<NSString *, id<Sdk_coreAttribute>> *)attributeMap __attribute__((swift_name("addTag(tag:values:attributeMap:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("ManipulationProxy")))
@interface Sdk_coreManipulationProxy : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreManipulationProxyCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreKotlinPair<NSString *, Sdk_coreManipulationProxyProxyType *> *)convertToOriginalUrlUrl:(NSString *)url __attribute__((swift_name("convertToOriginalUrl(url:)")));
- (NSString *)convertToProxyUrlUrl:(NSString *)url proxyType:(Sdk_coreManipulationProxyProxyType *)proxyType __attribute__((swift_name("convertToProxyUrl(url:proxyType:)")));
- (void)doInitFlowerAdsManager:(Sdk_coreFlowerAdsManagerImpl *)flowerAdsManager __attribute__((swift_name("doInit(flowerAdsManager:)")));
- (void)doInitManipulatorUrl:(NSString *)url __attribute__((swift_name("doInitManipulator(url:)")));
- (BOOL)isHls __attribute__((swift_name("isHls()")));
- (void)setChannelStreamHeadersMap:(NSDictionary<NSString *, NSString *> *)map __attribute__((swift_name("setChannelStreamHeaders(map:)")));
- (void)stop __attribute__((swift_name("stop()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property Sdk_corePlatformMap<NSString *, NSString *> *channelStreamHeaders __attribute__((swift_name("channelStreamHeaders")));
@property Sdk_coreFlowerAdsManagerImpl *flowerAdsManager __attribute__((swift_name("flowerAdsManager")));
@property (readonly) BOOL isInitialized __attribute__((swift_name("isInitialized")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property Sdk_coreManipulator * _Nullable manipulator __attribute__((swift_name("manipulator")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreMediaSegmentAssumeService * _Nullable mediaSegmentAssumeService __attribute__((swift_name("mediaSegmentAssumeService")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreSdkContainer *sdkContainer __attribute__((swift_name("sdkContainer")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ManipulationProxy.Companion")))
@interface Sdk_coreManipulationProxyCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreManipulationProxyCompanion *shared __attribute__((swift_name("shared")));
- (NSString *)removeSdkInternalParamsUrlString:(NSString *)urlString __attribute__((swift_name("removeSdkInternalParams(urlString:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ManipulationProxy.ProxyType")))
@interface Sdk_coreManipulationProxyProxyType : Sdk_coreKotlinEnum<Sdk_coreManipulationProxyProxyType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreManipulationProxyProxyTypeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreManipulationProxyProxyType *manipulate __attribute__((swift_name("manipulate")));
@property (class, readonly) Sdk_coreManipulationProxyProxyType *cache __attribute__((swift_name("cache")));
@property (class, readonly) Sdk_coreManipulationProxyProxyType *bypass __attribute__((swift_name("bypass")));
+ (Sdk_coreKotlinArray<Sdk_coreManipulationProxyProxyType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreManipulationProxyProxyType *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ManipulationProxy.ProxyTypeCompanion")))
@interface Sdk_coreManipulationProxyProxyTypeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreManipulationProxyProxyTypeCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreManipulationProxyProxyType *)fromValueValue:(NSString *)value __attribute__((swift_name("fromValue(value:)")));
@end

__attribute__((swift_name("ManipulationServer")))
@interface Sdk_coreManipulationServer : Sdk_coreManipulationProxy
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreManipulationServerCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreKotlinPair<NSString *, Sdk_coreManipulationProxyProxyType *> *)convertToOriginalUrlUrl:(NSString *)url __attribute__((swift_name("convertToOriginalUrl(url:)")));
- (NSString *)convertToProxyUrlUrl:(NSString *)url proxyType:(Sdk_coreManipulationProxyProxyType *)proxyType __attribute__((swift_name("convertToProxyUrl(url:proxyType:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)handlePlaylistRequestRequestBuilder:(Sdk_coreKtor_client_coreHttpRequestBuilder *)requestBuilder originalUrl:(NSString *)originalUrl completionHandler:(void (^)(id<Sdk_coreManipulationServerResponse> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("handlePlaylistRequest(requestBuilder:originalUrl:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)handleRequestRequestUri:(NSString *)requestUri headers:(NSDictionary<NSString *, NSString *> *)headers completionHandler:(void (^)(id<Sdk_coreManipulationServerResponse> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("handleRequest(requestUri:headers:completionHandler:)")));
- (void)doInitFlowerAdsManager:(Sdk_coreFlowerAdsManagerImpl *)flowerAdsManager __attribute__((swift_name("doInit(flowerAdsManager:)")));
- (NSString * _Nullable)serve __attribute__((swift_name("serve()")));
- (void)stop __attribute__((swift_name("stop()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreCachedHttpClient *cachedHttpClient __attribute__((swift_name("cachedHttpClient")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreKtor_client_coreHttpClient *httpClient __attribute__((swift_name("httpClient")));
@property (readonly) BOOL isInitialized __attribute__((swift_name("isInitialized")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property NSString * _Nullable localEndpoint __attribute__((swift_name("localEndpoint")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ManipulationServer.Companion")))
@interface Sdk_coreManipulationServerCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreManipulationServerCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKotlinRegex *HTTP_SCHEME_PATTERN __attribute__((swift_name("HTTP_SCHEME_PATTERN")));
@end

__attribute__((swift_name("ManipulationServerResponse")))
@protocol Sdk_coreManipulationServerResponse
@required
@property (readonly) id<Sdk_coreKtor_ioByteReadChannel> data __attribute__((swift_name("data")));
@property (readonly) id<Sdk_coreKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *statusCode __attribute__((swift_name("statusCode")));
@end

__attribute__((swift_name("AdPlayer")))
@protocol Sdk_coreAdPlayer
@required
- (void)addCallbackAdPlayerCallback:(id<Sdk_coreAdPlayerCallback>)adPlayerCallback __attribute__((swift_name("addCallback(adPlayerCallback:)")));
- (Sdk_coreAdProgress *)getProgress __attribute__((swift_name("getProgress()")));
- (BOOL)isPause __attribute__((swift_name("isPause()")));
- (void)loadMediaUrls:(Sdk_corePlatformList<NSString *> *)mediaUrls totalDuration:(int32_t)totalDuration adPlayerView:(id<Sdk_coreAdPlayerView>)adPlayerView __attribute__((swift_name("load(mediaUrls:totalDuration:adPlayerView:)")));
- (void)pause __attribute__((swift_name("pause()")));
- (void)play __attribute__((swift_name("play()")));
- (void)removeCallbackAdPlayerCallback:(id<Sdk_coreAdPlayerCallback>)adPlayerCallback __attribute__((swift_name("removeCallback(adPlayerCallback:)")));
- (void)resume __attribute__((swift_name("resume()")));
- (void)stop __attribute__((swift_name("stop()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdPlayerCallbacks")))
@interface Sdk_coreAdPlayerCallbacks : Sdk_coreBase <Sdk_coreAdPlayerCallback>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreAdPlayerCallbacksCompanion *companion __attribute__((swift_name("companion")));
- (void)addCallbackCallback:(id<Sdk_coreAdPlayerCallback>)callback __attribute__((swift_name("addCallback(callback:)")));
- (void)onErrorMediaUrl:(NSString * _Nullable)mediaUrl t:(Sdk_coreKotlinThrowable * _Nullable)t __attribute__((swift_name("onError(mediaUrl:t:)")));
- (void)onLoadedMediaUrl:(NSString * _Nullable)mediaUrl duration:(int32_t)duration __attribute__((swift_name("onLoaded(mediaUrl:duration:)")));
- (void)onPauseMediaUrl:(NSString * _Nullable)mediaUrl __attribute__((swift_name("onPause(mediaUrl:)")));
- (void)onPlayMediaUrl:(NSString * _Nullable)mediaUrl __attribute__((swift_name("onPlay(mediaUrl:)")));
- (void)onResumeMediaUrl:(NSString * _Nullable)mediaUrl __attribute__((swift_name("onResume(mediaUrl:)")));
- (void)onStopped __attribute__((swift_name("onStopped()")));
- (void)removeCallbackCallback:(id<Sdk_coreAdPlayerCallback>)callback __attribute__((swift_name("removeCallback(callback:)")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreMutableSet<id<Sdk_coreAdPlayerCallback>> *callbacks __attribute__((swift_name("callbacks")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdPlayerCallbacks.Companion")))
@interface Sdk_coreAdPlayerCallbacksCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreAdPlayerCallbacksCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("AdPlayerView")))
@protocol Sdk_coreAdPlayerView <Sdk_coreUIElement>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdProgress")))
@interface Sdk_coreAdProgress : Sdk_coreBase
- (instancetype)initWithCurrentTime:(int32_t)currentTime duration:(int32_t)duration __attribute__((swift_name("init(currentTime:duration:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreAdProgressCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreAdProgress *)doCopyCurrentTime:(int32_t)currentTime duration:(int32_t)duration __attribute__((swift_name("doCopy(currentTime:duration:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t currentTime __attribute__((swift_name("currentTime")));
@property (readonly) int32_t duration __attribute__((swift_name("duration")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdProgress.Companion")))
@interface Sdk_coreAdProgressCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreAdProgressCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreAdProgress *NOT_READY __attribute__((swift_name("NOT_READY")));
@end

__attribute__((swift_name("UIButton")))
@protocol Sdk_coreUIButton <Sdk_coreUIElement>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConcurrentQueue")))
@interface Sdk_coreConcurrentQueue : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreConcurrentQueueCompanion *companion __attribute__((swift_name("companion")));
- (void)addJobJob:(id<Sdk_coreKotlinSuspendFunction0>)job __attribute__((swift_name("addJob(job:)")));
- (void)close __attribute__((swift_name("close()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConcurrentQueue.Companion")))
@interface Sdk_coreConcurrentQueueCompanion : Sdk_coreFLogging
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreConcurrentQueueCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("DeferredStub")))
@protocol Sdk_coreDeferredStub
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)awaitWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("await(completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinWrapped")))
@interface Sdk_coreKotlinWrapped<__covariant T> : Sdk_coreBase
- (instancetype)initWithValue:(T _Nullable)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (readonly) T _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Logger_")))
@interface Sdk_coreLogger : Sdk_coreBase
- (instancetype)initWithLogger:(Sdk_coreKmLog *)logger __attribute__((swift_name("init(logger:)"))) __attribute__((objc_designated_initializer));
- (void)debugMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("debug(msg:)")));
- (void)errorMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("error(msg:)")));
- (void)errorErr:(Sdk_coreKotlinThrowable * _Nullable)err msg:(id _Nullable (^)(void))msg __attribute__((swift_name("error(err:msg:)")));
- (void)infoMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("info(msg:)")));
- (void)verboseMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("verbose(msg:)")));
- (void)warnMsg:(id _Nullable (^)(void))msg __attribute__((swift_name("warn(msg:)")));
- (void)warnErr:(Sdk_coreKotlinThrowable * _Nullable)err msg:(id _Nullable (^)(void))msg __attribute__((swift_name("warn(err:msg:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OffsetDateTime")))
@interface Sdk_coreOffsetDateTime : Sdk_coreBase
- (instancetype)initWithInstant:(Sdk_coreKotlinx_datetimeInstant *)instant offset:(int32_t)offset __attribute__((swift_name("init(instant:offset:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreOffsetDateTimeCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreKotlinx_datetimeInstant *)toInstant __attribute__((swift_name("toInstant()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OffsetDateTime.Companion")))
@interface Sdk_coreOffsetDateTimeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreOffsetDateTimeCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreOffsetDateTime *)now __attribute__((swift_name("now()")));
- (Sdk_coreOffsetDateTime *)parseString:(NSString *)string __attribute__((swift_name("parse(string:)")));
- (id<Sdk_coreKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Platform_")))
@interface Sdk_corePlatform_ : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_corePlatform_Companion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Platform_.Companion")))
@interface Sdk_corePlatform_Companion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_corePlatform_Companion *shared __attribute__((swift_name("shared")));
@property (readonly) BOOL isAndroid __attribute__((swift_name("isAndroid")));
@property (readonly) BOOL isHtml5 __attribute__((swift_name("isHtml5")));
@property (readonly) BOOL isIos __attribute__((swift_name("isIos")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlatformMutex")))
@interface Sdk_corePlatformMutex : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id _Nullable)withLockTask:(id _Nullable (^)(void))task __attribute__((swift_name("withLock(task:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StringUtils")))
@interface Sdk_coreStringUtils : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)stringUtils __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreStringUtils *shared __attribute__((swift_name("shared")));
- (NSString *)randomNumericTextCount:(int32_t)textCount __attribute__((swift_name("randomNumeric(textCount:)")));
@end

__attribute__((swift_name("XmlNode")))
@interface Sdk_coreXmlNode : Sdk_coreBase
- (instancetype)initWithNode:(id)node rootNode:(id)rootNode __attribute__((swift_name("init(node:rootNode:)"))) __attribute__((objc_designated_initializer));
- (void)appendChildChild:(Sdk_coreXmlNode *)child __attribute__((swift_name("appendChild(child:)")));
- (Sdk_corePlatformList<Sdk_coreXmlNode *> *)childNodes __attribute__((swift_name("childNodes()")));
- (Sdk_coreXmlNode *)clone __attribute__((swift_name("clone()")));
- (Sdk_coreXmlNode *)createElementName:(NSString *)name __attribute__((swift_name("createElement(name:)")));
- (Sdk_coreXmlNode *)createTextNodeValue:(NSString *)value __attribute__((swift_name("createTextNode(value:)")));
- (NSString * _Nullable)getAttributeName:(NSString *)name __attribute__((swift_name("getAttribute(name:)")));
- (Sdk_coreXmlNode * _Nullable)getNodeXpathExp:(NSString *)xpathExp __attribute__((swift_name("getNode(xpathExp:)")));
- (Sdk_corePlatformList<Sdk_coreXmlNode *> *)getNodeListXpathExp:(NSString *)xpathExp __attribute__((swift_name("getNodeList(xpathExp:)")));
- (void)insertBeforeNewNode:(Sdk_coreXmlNode *)newNode baseNode:(Sdk_coreXmlNode *)baseNode __attribute__((swift_name("insertBefore(newNode:baseNode:)")));
- (NSString *)nodeName __attribute__((swift_name("nodeName()")));
- (Sdk_coreXmlNode *)parentNode __attribute__((swift_name("parentNode()")));
- (void)removeChildChild:(Sdk_coreXmlNode *)child __attribute__((swift_name("removeChild(child:)")));
- (void)setAttributeName:(NSString *)name value:(NSString *)value __attribute__((swift_name("setAttribute(name:value:)")));
- (NSString *)string __attribute__((swift_name("string()")));
- (NSString *)textContent __attribute__((swift_name("textContent()")));
@property (readonly) id node __attribute__((swift_name("node")));
@property (readonly) id rootNode __attribute__((swift_name("rootNode")));
@end

__attribute__((swift_name("XmlUtil")))
@protocol Sdk_coreXmlUtil
@required

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (Sdk_coreXmlNode * _Nullable)parseXmlText:(NSString *)text error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("parseXml(text:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineScope")))
@protocol Sdk_coreKotlinx_coroutines_coreCoroutineScope
@required
@property (readonly) id<Sdk_coreKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end

__attribute__((swift_name("Ktor_ioCloseable")))
@protocol Sdk_coreKtor_ioCloseable
@required
- (void)close __attribute__((swift_name("close()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpClient")))
@interface Sdk_coreKtor_client_coreHttpClient : Sdk_coreBase <Sdk_coreKotlinx_coroutines_coreCoroutineScope, Sdk_coreKtor_ioCloseable>
- (instancetype)initWithEngine:(id<Sdk_coreKtor_client_coreHttpClientEngine>)engine userConfig:(Sdk_coreKtor_client_coreHttpClientConfig<Sdk_coreKtor_client_coreHttpClientEngineConfig *> *)userConfig __attribute__((swift_name("init(engine:userConfig:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));
- (Sdk_coreKtor_client_coreHttpClient *)configBlock:(void (^)(Sdk_coreKtor_client_coreHttpClientConfig<id> *))block __attribute__((swift_name("config(block:)")));
- (BOOL)isSupportedCapability:(id<Sdk_coreKtor_client_coreHttpClientEngineCapability>)capability __attribute__((swift_name("isSupported(capability:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<Sdk_coreKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) id<Sdk_coreKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) id<Sdk_coreKtor_client_coreHttpClientEngine> engine __attribute__((swift_name("engine")));
@property (readonly) Sdk_coreKtor_client_coreHttpClientEngineConfig *engineConfig __attribute__((swift_name("engineConfig")));
@property (readonly) Sdk_coreKtor_eventsEvents *monitor __attribute__((swift_name("monitor")));
@property (readonly) Sdk_coreKtor_client_coreHttpReceivePipeline *receivePipeline __attribute__((swift_name("receivePipeline")));
@property (readonly) Sdk_coreKtor_client_coreHttpRequestPipeline *requestPipeline __attribute__((swift_name("requestPipeline")));
@property (readonly) Sdk_coreKtor_client_coreHttpResponsePipeline *responsePipeline __attribute__((swift_name("responsePipeline")));
@property (readonly) Sdk_coreKtor_client_coreHttpSendPipeline *sendPipeline __attribute__((swift_name("sendPipeline")));
@end

@interface Sdk_coreKtor_client_coreHttpClient (Extensions)

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (Sdk_coreKtor_client_coreHttpResponse * _Nullable)ios_requestSyncBuilder:(Sdk_coreKtor_client_coreHttpRequestBuilder *)builder error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("ios_requestSync(builder:)")));
@end

__attribute__((swift_name("Ktor_httpHttpMessageBuilder")))
@protocol Sdk_coreKtor_httpHttpMessageBuilder
@required
@property (readonly) Sdk_coreKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestBuilder")))
@interface Sdk_coreKtor_client_coreHttpRequestBuilder : Sdk_coreBase <Sdk_coreKtor_httpHttpMessageBuilder>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) Sdk_coreKtor_client_coreHttpRequestBuilderCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreKtor_client_coreHttpRequestData *)build __attribute__((swift_name("build()")));
- (id _Nullable)getCapabilityOrNullKey:(id<Sdk_coreKtor_client_coreHttpClientEngineCapability>)key __attribute__((swift_name("getCapabilityOrNull(key:)")));
- (void)setAttributesBlock:(void (^)(id<Sdk_coreKtor_utilsAttributes>))block __attribute__((swift_name("setAttributes(block:)")));
- (void)setCapabilityKey:(id<Sdk_coreKtor_client_coreHttpClientEngineCapability>)key capability:(id)capability __attribute__((swift_name("setCapability(key:capability:)")));
- (Sdk_coreKtor_client_coreHttpRequestBuilder *)takeFromBuilder:(Sdk_coreKtor_client_coreHttpRequestBuilder *)builder __attribute__((swift_name("takeFrom(builder:)")));
- (Sdk_coreKtor_client_coreHttpRequestBuilder *)takeFromWithExecutionContextBuilder:(Sdk_coreKtor_client_coreHttpRequestBuilder *)builder __attribute__((swift_name("takeFromWithExecutionContext(builder:)")));
- (void)urlBlock:(void (^)(Sdk_coreKtor_httpURLBuilder *, Sdk_coreKtor_httpURLBuilder *))block __attribute__((swift_name("url(block:)")));
@property (readonly) id<Sdk_coreKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property id body __attribute__((swift_name("body")));
@property Sdk_coreKtor_utilsTypeInfo * _Nullable bodyType __attribute__((swift_name("bodyType")));
@property (readonly) id<Sdk_coreKotlinx_coroutines_coreJob> executionContext __attribute__((swift_name("executionContext")));
@property (readonly) Sdk_coreKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));
@property Sdk_coreKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) Sdk_coreKtor_httpURLBuilder *url __attribute__((swift_name("url")));
@end

@interface Sdk_coreKtor_client_coreHttpRequestBuilder (Extensions)
- (void)ios_urlUrlString:(NSString *)urlString __attribute__((swift_name("ios_url(urlString:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpUrl")))
@interface Sdk_coreKtor_httpUrl : Sdk_coreBase
@property (class, readonly, getter=companion) Sdk_coreKtor_httpUrlCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *encodedFragment __attribute__((swift_name("encodedFragment")));
@property (readonly) NSString * _Nullable encodedPassword __attribute__((swift_name("encodedPassword")));
@property (readonly) NSString *encodedPath __attribute__((swift_name("encodedPath")));
@property (readonly) NSString *encodedPathAndQuery __attribute__((swift_name("encodedPathAndQuery")));
@property (readonly) NSString *encodedQuery __attribute__((swift_name("encodedQuery")));
@property (readonly) NSString * _Nullable encodedUser __attribute__((swift_name("encodedUser")));
@property (readonly) NSString *fragment __attribute__((swift_name("fragment")));
@property (readonly) NSString *host __attribute__((swift_name("host")));
@property (readonly) id<Sdk_coreKtor_httpParameters> parameters __attribute__((swift_name("parameters")));
@property (readonly) NSString * _Nullable password __attribute__((swift_name("password")));
@property (readonly) NSArray<NSString *> *pathSegments __attribute__((swift_name("pathSegments")));
@property (readonly) int32_t port __attribute__((swift_name("port")));
@property (readonly) Sdk_coreKtor_httpURLProtocol *protocol __attribute__((swift_name("protocol")));
@property (readonly) int32_t specifiedPort __attribute__((swift_name("specifiedPort")));
@property (readonly) BOOL trailingQuery __attribute__((swift_name("trailingQuery")));
@property (readonly) NSString * _Nullable user __attribute__((swift_name("user")));
@end

@interface Sdk_coreKtor_httpUrl (Extensions)
- (Sdk_coreKtor_httpUrl *)normalize __attribute__((swift_name("normalize()")));
@property (readonly) NSString *baseUrl __attribute__((swift_name("baseUrl")));
@property (readonly) NSString *origin __attribute__((swift_name("origin")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpUrl.Companion")))
@interface Sdk_coreKtor_httpUrlCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_httpUrlCompanion *shared __attribute__((swift_name("shared")));
@end

@interface Sdk_coreKtor_httpUrlCompanion (Extensions)
- (Sdk_coreKtor_httpUrl *)fromUrl:(NSString *)url base:(NSString *)base __attribute__((swift_name("from(url:base:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface Sdk_coreKotlinByteArray : Sdk_coreBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(Sdk_coreByte *(^)(Sdk_coreInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (Sdk_coreKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

@interface Sdk_coreKotlinByteArray (Extensions)
- (NSString *)toHexString __attribute__((swift_name("toHexString()")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (NSData * _Nullable)toNSDataAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("toNSData()")));
@property (readonly) NSString *base64Decoded __attribute__((swift_name("base64Decoded")));
@property (readonly) NSString *base64Encoded __attribute__((swift_name("base64Encoded")));
@property (readonly) NSString *base64UrlDecoded __attribute__((swift_name("base64UrlDecoded")));
@property (readonly) NSString *base64UrlEncoded __attribute__((swift_name("base64UrlEncoded")));
@property (readonly) NSString *hexDecoded __attribute__((swift_name("hexDecoded")));
@property (readonly) Sdk_coreKotlinByteArray *hexDecodedBytes __attribute__((swift_name("hexDecodedBytes")));
@property (readonly) NSString *hexEncoded __attribute__((swift_name("hexEncoded")));
@property (readonly) Sdk_coreKotlinByteArray *hexEncodedBytes __attribute__((swift_name("hexEncodedBytes")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_coroutines_coreDispatchers")))
@interface Sdk_coreKotlinx_coroutines_coreDispatchers : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dispatchers __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinx_coroutines_coreDispatchers *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher *Default __attribute__((swift_name("Default")));
@property (readonly) Sdk_coreKotlinx_coroutines_coreMainCoroutineDispatcher *Main __attribute__((swift_name("Main")));
@property (readonly) Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher *Unconfined __attribute__((swift_name("Unconfined")));
@end

@interface Sdk_coreKotlinx_coroutines_coreDispatchers (Extensions)
@property (readonly) Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher *IO __attribute__((swift_name("IO")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/InstantIso8601Serializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_datetimeInstant")))
@interface Sdk_coreKotlinx_datetimeInstant : Sdk_coreBase <Sdk_coreKotlinComparable>
@property (class, readonly, getter=companion) Sdk_coreKotlinx_datetimeInstantCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(Sdk_coreKotlinx_datetimeInstant *)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (Sdk_coreKotlinx_datetimeInstant *)minusDuration:(int64_t)duration __attribute__((swift_name("minus(duration:)")));
- (int64_t)minusOther:(Sdk_coreKotlinx_datetimeInstant *)other __attribute__((swift_name("minus(other:)")));
- (Sdk_coreKotlinx_datetimeInstant *)plusDuration:(int64_t)duration __attribute__((swift_name("plus(duration:)")));
- (int64_t)toEpochMilliseconds __attribute__((swift_name("toEpochMilliseconds()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t epochSeconds __attribute__((swift_name("epochSeconds")));
@property (readonly) int32_t nanosecondsOfSecond __attribute__((swift_name("nanosecondsOfSecond")));
@end

@interface Sdk_coreKotlinx_datetimeInstant (Extensions)
- (Sdk_coreOffsetDateTime *)toOffsetDateTime __attribute__((swift_name("toOffsetDateTime()")));
@end

@interface Sdk_corePlatformList (Extensions)
- (NSArray<id> *)toList __attribute__((swift_name("toList()")));
@end

@interface Sdk_corePlatformMap (Extensions)
- (NSDictionary<id, id> *)toMap __attribute__((swift_name("toMap()")));
@end

@interface Sdk_corePlatformSet (Extensions)
- (NSSet<id> *)toSet __attribute__((swift_name("toSet()")));
@end

@interface Sdk_coreManipulationServer (Extensions)

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
- (id<Sdk_coreManipulationServerResponse> _Nullable)ios_handleRequestSyncRequestUri:(NSString *)requestUri headers:(NSDictionary<NSString *, NSString *> *)headers error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("ios_handleRequestSync(requestUri:headers:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Base64Kt")))
@interface Sdk_coreBase64Kt : Sdk_coreBase
+ (NSString *)base64Decoded:(NSString *)receiver __attribute__((swift_name("base64Decoded(_:)")));
+ (Sdk_coreKotlinByteArray *)base64DecodedBytes:(NSString *)receiver __attribute__((swift_name("base64DecodedBytes(_:)")));
+ (NSString *)base64Encoded:(NSString *)receiver __attribute__((swift_name("base64Encoded(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Base64UrlKt")))
@interface Sdk_coreBase64UrlKt : Sdk_coreBase
+ (NSString *)base64UrlDecoded:(NSString *)receiver __attribute__((swift_name("base64UrlDecoded(_:)")));
+ (Sdk_coreKotlinByteArray *)base64UrlDecodedBytes:(NSString *)receiver __attribute__((swift_name("base64UrlDecodedBytes(_:)")));
+ (NSString *)base64UrlEncoded:(NSString *)receiver __attribute__((swift_name("base64UrlEncoded(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DurationParserKt")))
@interface Sdk_coreDurationParserKt : Sdk_coreBase
+ (int64_t)parseDuration:(NSString *)receiver __attribute__((swift_name("parseDuration(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExtensionsKt")))
@interface Sdk_coreExtensionsKt : Sdk_coreBase
+ (Sdk_coreKotlinByteArray *)hexDecodedBytes:(NSString *)receiver __attribute__((swift_name("hexDecodedBytes(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlowerAdsManagerListenerKt")))
@interface Sdk_coreFlowerAdsManagerListenerKt : Sdk_coreBase
@property (class, readonly) int32_t SKIPPED_AD_REASON_ERROR __attribute__((swift_name("SKIPPED_AD_REASON_ERROR")));
@property (class, readonly) int32_t SKIPPED_AD_REASON_NO_AD __attribute__((swift_name("SKIPPED_AD_REASON_NO_AD")));
@property (class, readonly) int32_t SKIPPED_AD_REASON_TIMEOUT __attribute__((swift_name("SKIPPED_AD_REASON_TIMEOUT")));
@property (class, readonly) int32_t SKIPPED_AD_REASON_UNKNOWN __attribute__((swift_name("SKIPPED_AD_REASON_UNKNOWN")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IntExtKt")))
@interface Sdk_coreIntExtKt : Sdk_coreBase
+ (NSString *)zeroPrefixed:(int32_t)receiver maxLength:(int32_t)maxLength __attribute__((swift_name("zeroPrefixed(_:maxLength:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KmLogKt")))
@interface Sdk_coreKmLogKt : Sdk_coreBase
+ (Sdk_coreKmLog *)loggingTag:(NSString * _Nullable)tag __attribute__((swift_name("logging(tag:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KtorExt_iosKt")))
@interface Sdk_coreKtorExt_iosKt : Sdk_coreBase

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
+ (NSData * _Nullable)ByteReadChannelToNSDataChannel:(id<Sdk_coreKtor_ioByteReadChannel>)channel error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("ByteReadChannelToNSData(channel:)")));
+ (NSDictionary<NSString *, NSString *> *)HeadersToStringMapHeaders:(id<Sdk_coreKtor_httpHeaders>)headers __attribute__((swift_name("HeadersToStringMap(headers:)")));

/**
 * @note This method converts all Kotlin exceptions to errors.
*/
+ (Sdk_coreKotlinByteArray * _Nullable)NSDataToByteArrayData:(NSData *)data error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("NSDataToByteArray(data:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogLevelKt")))
@interface Sdk_coreLogLevelKt : Sdk_coreBase
@property (class, readonly) int32_t DEBUG_MASK __attribute__((swift_name("DEBUG_MASK")));
@property (class, readonly) int32_t ERROR_MASK __attribute__((swift_name("ERROR_MASK")));
@property (class, readonly) int32_t INFO_MASK __attribute__((swift_name("INFO_MASK")));
@property (class, readonly) int32_t VERBOSE_MASK __attribute__((swift_name("VERBOSE_MASK")));
@property (class, readonly) int32_t WARN_MASK __attribute__((swift_name("WARN_MASK")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPlayerAdapterKt")))
@interface Sdk_coreMediaPlayerAdapterKt : Sdk_coreBase
@property (class, readonly) int32_t ERROR_CURRENT_POSITION __attribute__((swift_name("ERROR_CURRENT_POSITION")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlatformList_iosKt")))
@interface Sdk_corePlatformList_iosKt : Sdk_coreBase
+ (Sdk_corePlatformList<id> *)toPlatformList:(NSArray<id> *)receiver __attribute__((swift_name("toPlatformList(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlatformMap_iosKt")))
@interface Sdk_corePlatformMap_iosKt : Sdk_coreBase
+ (Sdk_corePlatformMap<id, id> *)toPlatformMap:(NSDictionary<id, id> *)receiver __attribute__((swift_name("toPlatformMap(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlatformSet_iosKt")))
@interface Sdk_corePlatformSet_iosKt : Sdk_coreBase
+ (Sdk_corePlatformSet<id> *)toPlatformSet:(NSSet<id> *)receiver __attribute__((swift_name("toPlatformSet(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UrlStringExtKt")))
@interface Sdk_coreUrlStringExtKt : Sdk_coreBase
+ (NSString *)replaceUrlPrefix:(NSString *)receiver prefixUrl:(NSString * _Nullable)prefixUrl __attribute__((swift_name("replaceUrlPrefix(_:prefixUrl:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CallBeacon_iosKt")))
@interface Sdk_coreCallBeacon_iosKt : Sdk_coreBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)callBeaconHttpClient:(Sdk_coreKtor_client_coreHttpClient *)httpClient url:(NSString *)url completionHandler:(void (^)(Sdk_coreKotlinNothing * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("callBeacon(httpClient:url:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface Sdk_coreKotlinArray<T> : Sdk_coreBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(Sdk_coreInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<Sdk_coreKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface Sdk_coreKotlinPair<__covariant A, __covariant B> : Sdk_coreBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface Sdk_coreKotlinEnumCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface Sdk_coreKotlinIllegalStateException : Sdk_coreKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface Sdk_coreKotlinCancellationException : Sdk_coreKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlow")))
@protocol Sdk_coreKotlinx_coroutines_coreFlow
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<Sdk_coreKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol Sdk_coreKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<Sdk_coreKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<Sdk_coreKotlinCoroutineContextElement> _Nullable)getKey:(id<Sdk_coreKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<Sdk_coreKotlinCoroutineContext>)minusKeyKey:(id<Sdk_coreKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<Sdk_coreKotlinCoroutineContext>)plusContext:(id<Sdk_coreKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol Sdk_coreKotlinCoroutineContextElement <Sdk_coreKotlinCoroutineContext>
@required
@property (readonly) id<Sdk_coreKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreJob")))
@protocol Sdk_coreKotlinx_coroutines_coreJob <Sdk_coreKotlinCoroutineContextElement>
@required
- (id<Sdk_coreKotlinx_coroutines_coreChildHandle>)attachChildChild:(id<Sdk_coreKotlinx_coroutines_coreChildJob>)child __attribute__((swift_name("attachChild(child:)")));
- (void)cancelCause:(Sdk_coreKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));
- (Sdk_coreKotlinCancellationException *)getCancellationException __attribute__((swift_name("getCancellationException()")));
- (id<Sdk_coreKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionHandler:(void (^)(Sdk_coreKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(handler:)")));
- (id<Sdk_coreKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionOnCancelling:(BOOL)onCancelling invokeImmediately:(BOOL)invokeImmediately handler:(void (^)(Sdk_coreKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling:invokeImmediately:handler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)joinWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("join(completionHandler:)")));
- (id<Sdk_coreKotlinx_coroutines_coreJob>)plusOther:(id<Sdk_coreKotlinx_coroutines_coreJob>)other __attribute__((swift_name("plus(other:)"))) __attribute__((unavailable("Operator '+' on two Job objects is meaningless. Job is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The job to the right of `+` just replaces the job the left of `+`.")));
- (BOOL)start __attribute__((swift_name("start()")));
@property (readonly) id<Sdk_coreKotlinSequence> children __attribute__((swift_name("children")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted")));
@property (readonly) id<Sdk_coreKotlinx_coroutines_coreSelectClause0> onJoin __attribute__((swift_name("onJoin")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
@property (readonly) id<Sdk_coreKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol Sdk_coreKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<Sdk_coreKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<Sdk_coreKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol Sdk_coreKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<Sdk_coreKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<Sdk_coreKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol Sdk_coreKotlinx_serialization_coreKSerializer <Sdk_coreKotlinx_serialization_coreSerializationStrategy, Sdk_coreKotlinx_serialization_coreDeserializationStrategy>
@required
@end

__attribute__((swift_name("Ktor_ioByteReadChannel")))
@protocol Sdk_coreKtor_ioByteReadChannel
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)awaitContentWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("awaitContent(completionHandler:)")));
- (BOOL)cancelCause_:(Sdk_coreKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(cause_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)discardMax:(int64_t)max completionHandler:(void (^)(Sdk_coreLong * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("discard(max:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)peekToDestination:(Sdk_coreKtor_ioMemory *)destination destinationOffset:(int64_t)destinationOffset offset:(int64_t)offset min:(int64_t)min max:(int64_t)max completionHandler:(void (^)(Sdk_coreLong * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("peekTo(destination:destinationOffset:offset:min:max:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readAvailableDst:(Sdk_coreKtor_ioChunkBuffer *)dst completionHandler:(void (^)(Sdk_coreInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readAvailable(dst:completionHandler:)")));
- (int32_t)readAvailableMin:(int32_t)min block:(void (^)(Sdk_coreKtor_ioBuffer *))block __attribute__((swift_name("readAvailable(min:block:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readAvailableDst:(Sdk_coreKotlinByteArray *)dst offset:(int32_t)offset length:(int32_t)length completionHandler:(void (^)(Sdk_coreInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readAvailable(dst:offset:length:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readAvailableDst:(void *)dst offset:(int32_t)offset length:(int32_t)length completionHandler_:(void (^)(Sdk_coreInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readAvailable(dst:offset:length:completionHandler_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readAvailableDst:(void *)dst offset:(int64_t)offset length:(int64_t)length completionHandler__:(void (^)(Sdk_coreInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readAvailable(dst:offset:length:completionHandler__:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readBooleanWithCompletionHandler:(void (^)(Sdk_coreBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readBoolean(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readByteWithCompletionHandler:(void (^)(Sdk_coreByte * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readByte(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readDoubleWithCompletionHandler:(void (^)(Sdk_coreDouble * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readDouble(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readFloatWithCompletionHandler:(void (^)(Sdk_coreFloat * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readFloat(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readFullyDst:(Sdk_coreKtor_ioChunkBuffer *)dst n:(int32_t)n completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("readFully(dst:n:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readFullyDst:(Sdk_coreKotlinByteArray *)dst offset:(int32_t)offset length:(int32_t)length completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("readFully(dst:offset:length:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readFullyDst:(void *)dst offset:(int32_t)offset length:(int32_t)length completionHandler_:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("readFully(dst:offset:length:completionHandler_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readFullyDst:(void *)dst offset:(int64_t)offset length:(int64_t)length completionHandler__:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("readFully(dst:offset:length:completionHandler__:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readIntWithCompletionHandler:(void (^)(Sdk_coreInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readInt(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readLongWithCompletionHandler:(void (^)(Sdk_coreLong * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readLong(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readPacketSize:(int32_t)size completionHandler:(void (^)(Sdk_coreKtor_ioByteReadPacket * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readPacket(size:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readRemainingLimit:(int64_t)limit completionHandler:(void (^)(Sdk_coreKtor_ioByteReadPacket * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readRemaining(limit:completionHandler:)")));
- (void)readSessionConsumer:(void (^)(id<Sdk_coreKtor_ioReadSession>))consumer __attribute__((swift_name("readSession(consumer:)"))) __attribute__((deprecated("Use read { } instead.")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readShortWithCompletionHandler:(void (^)(Sdk_coreShort * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readShort(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readSuspendableSessionConsumer:(id<Sdk_coreKotlinSuspendFunction1>)consumer completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("readSuspendableSession(consumer:completionHandler:)"))) __attribute__((deprecated("Use read { } instead.")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readUTF8LineLimit:(int32_t)limit completionHandler:(void (^)(NSString * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("readUTF8Line(limit:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readUTF8LineToOut:(id<Sdk_coreKotlinAppendable>)out limit:(int32_t)limit completionHandler:(void (^)(Sdk_coreBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readUTF8LineTo(out:limit:completionHandler:)")));
@property (readonly) int32_t availableForRead __attribute__((swift_name("availableForRead")));
@property (readonly) Sdk_coreKotlinThrowable * _Nullable closedCause __attribute__((swift_name("closedCause")));
@property (readonly) BOOL isClosedForRead __attribute__((swift_name("isClosedForRead")));
@property (readonly) BOOL isClosedForWrite __attribute__((swift_name("isClosedForWrite")));
@property (readonly) int64_t totalBytesRead __attribute__((swift_name("totalBytesRead")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpStatusCode")))
@interface Sdk_coreKtor_httpHttpStatusCode : Sdk_coreBase <Sdk_coreKotlinComparable>
- (instancetype)initWithValue:(int32_t)value description:(NSString *)description __attribute__((swift_name("init(value:description:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKtor_httpHttpStatusCodeCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(Sdk_coreKtor_httpHttpStatusCode *)other __attribute__((swift_name("compareTo(other:)")));
- (Sdk_coreKtor_httpHttpStatusCode *)doCopyValue:(int32_t)value description:(NSString *)description __attribute__((swift_name("doCopy(value:description:)")));
- (Sdk_coreKtor_httpHttpStatusCode *)descriptionValue:(NSString *)value __attribute__((swift_name("description(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
@end

__attribute__((swift_name("Ktor_utilsStringValues")))
@protocol Sdk_coreKtor_utilsStringValues
@required
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<Sdk_coreKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (void)forEachBody:(void (^)(NSString *, NSArray<NSString *> *))body __attribute__((swift_name("forEach(body:)")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));
@end

__attribute__((swift_name("Ktor_httpHeaders")))
@protocol Sdk_coreKtor_httpHeaders <Sdk_coreKtor_utilsStringValues>
@required
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialFormat")))
@protocol Sdk_coreKotlinx_serialization_coreSerialFormat
@required
@property (readonly) Sdk_coreKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreStringFormat")))
@protocol Sdk_coreKotlinx_serialization_coreStringFormat <Sdk_coreKotlinx_serialization_coreSerialFormat>
@required
- (id _Nullable)decodeFromStringDeserializer:(id<Sdk_coreKotlinx_serialization_coreDeserializationStrategy>)deserializer string:(NSString *)string __attribute__((swift_name("decodeFromString(deserializer:string:)")));
- (NSString *)encodeToStringSerializer:(id<Sdk_coreKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToString(serializer:value:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_jsonJson")))
@interface Sdk_coreKotlinx_serialization_jsonJson : Sdk_coreBase <Sdk_coreKotlinx_serialization_coreStringFormat>
@property (class, readonly, getter=companion) Sdk_coreKotlinx_serialization_jsonJsonDefault *companion __attribute__((swift_name("companion")));
- (id _Nullable)decodeFromJsonElementDeserializer:(id<Sdk_coreKotlinx_serialization_coreDeserializationStrategy>)deserializer element:(Sdk_coreKotlinx_serialization_jsonJsonElement *)element __attribute__((swift_name("decodeFromJsonElement(deserializer:element:)")));
- (id _Nullable)decodeFromStringString:(NSString *)string __attribute__((swift_name("decodeFromString(string:)")));
- (id _Nullable)decodeFromStringDeserializer:(id<Sdk_coreKotlinx_serialization_coreDeserializationStrategy>)deserializer string:(NSString *)string __attribute__((swift_name("decodeFromString(deserializer:string:)")));
- (Sdk_coreKotlinx_serialization_jsonJsonElement *)encodeToJsonElementSerializer:(id<Sdk_coreKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToJsonElement(serializer:value:)")));
- (NSString *)encodeToStringSerializer:(id<Sdk_coreKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToString(serializer:value:)")));
- (Sdk_coreKotlinx_serialization_jsonJsonElement *)parseToJsonElementString:(NSString *)string __attribute__((swift_name("parseToJsonElement(string:)")));
@property (readonly) Sdk_coreKotlinx_serialization_jsonJsonConfiguration *configuration __attribute__((swift_name("configuration")));
@property (readonly) Sdk_coreKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol Sdk_coreKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinCharSequence")))
@protocol Sdk_coreKotlinCharSequence
@required
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id)subSequenceStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("subSequence(startIndex:endIndex:)")));
@property (readonly) int32_t length __attribute__((swift_name("length")));
@end

__attribute__((swift_name("KotlinAppendable")))
@protocol Sdk_coreKotlinAppendable
@required
- (id<Sdk_coreKotlinAppendable>)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));
- (id<Sdk_coreKotlinAppendable>)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));
- (id<Sdk_coreKotlinAppendable>)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinStringBuilder")))
@interface Sdk_coreKotlinStringBuilder : Sdk_coreBase <Sdk_coreKotlinCharSequence, Sdk_coreKotlinAppendable>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithContent:(id)content __attribute__((swift_name("init(content:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCapacity:(int32_t)capacity __attribute__((swift_name("init(capacity:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent_:(NSString *)content __attribute__((swift_name("init(content_:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreKotlinStringBuilder *)appendValue__:(id _Nullable)value __attribute__((swift_name("append(value__:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue___:(BOOL)value __attribute__((swift_name("append(value___:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue____:(int8_t)value __attribute__((swift_name("append(value____:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue_____:(Sdk_coreKotlinCharArray *)value __attribute__((swift_name("append(value_____:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue______:(double)value __attribute__((swift_name("append(value______:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue_______:(float)value __attribute__((swift_name("append(value_______:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue________:(int32_t)value __attribute__((swift_name("append(value________:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue_________:(int64_t)value __attribute__((swift_name("append(value_________:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue__________:(int16_t)value __attribute__((swift_name("append(value__________:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue___________:(NSString * _Nullable)value __attribute__((swift_name("append(value___________:)")));
- (Sdk_coreKotlinStringBuilder *)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (Sdk_coreKotlinStringBuilder *)appendRangeValue:(Sdk_coreKotlinCharArray *)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("appendRange(value:startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (Sdk_coreKotlinStringBuilder *)appendRangeValue:(id)value startIndex:(int32_t)startIndex endIndex_:(int32_t)endIndex __attribute__((swift_name("appendRange(value:startIndex:endIndex_:)")));
- (int32_t)capacity __attribute__((swift_name("capacity()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (Sdk_coreKotlinStringBuilder *)deleteAtIndex:(int32_t)index __attribute__((swift_name("deleteAt(index:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (Sdk_coreKotlinStringBuilder *)deleteRangeStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("deleteRange(startIndex:endIndex:)")));
- (void)ensureCapacityMinimumCapacity:(int32_t)minimumCapacity __attribute__((swift_name("ensureCapacity(minimumCapacity:)")));
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (int32_t)indexOfString:(NSString *)string __attribute__((swift_name("indexOf(string:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (int32_t)indexOfString:(NSString *)string startIndex:(int32_t)startIndex __attribute__((swift_name("indexOf(string:startIndex:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value:(id _Nullable)value __attribute__((swift_name("insert(index:value:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value_:(BOOL)value __attribute__((swift_name("insert(index:value_:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value__:(int8_t)value __attribute__((swift_name("insert(index:value__:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value___:(unichar)value __attribute__((swift_name("insert(index:value___:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value____:(Sdk_coreKotlinCharArray *)value __attribute__((swift_name("insert(index:value____:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value_____:(id _Nullable)value __attribute__((swift_name("insert(index:value_____:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value______:(double)value __attribute__((swift_name("insert(index:value______:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value_______:(float)value __attribute__((swift_name("insert(index:value_______:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value________:(int32_t)value __attribute__((swift_name("insert(index:value________:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value_________:(int64_t)value __attribute__((swift_name("insert(index:value_________:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value__________:(int16_t)value __attribute__((swift_name("insert(index:value__________:)")));
- (Sdk_coreKotlinStringBuilder *)insertIndex:(int32_t)index value___________:(NSString * _Nullable)value __attribute__((swift_name("insert(index:value___________:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (Sdk_coreKotlinStringBuilder *)insertRangeIndex:(int32_t)index value:(Sdk_coreKotlinCharArray *)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("insertRange(index:value:startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (Sdk_coreKotlinStringBuilder *)insertRangeIndex:(int32_t)index value:(id)value startIndex:(int32_t)startIndex endIndex_:(int32_t)endIndex __attribute__((swift_name("insertRange(index:value:startIndex:endIndex_:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (int32_t)lastIndexOfString:(NSString *)string __attribute__((swift_name("lastIndexOf(string:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (int32_t)lastIndexOfString:(NSString *)string startIndex:(int32_t)startIndex __attribute__((swift_name("lastIndexOf(string:startIndex:)")));
- (Sdk_coreKotlinStringBuilder *)reverse __attribute__((swift_name("reverse()")));
- (void)setIndex:(int32_t)index value:(unichar)value __attribute__((swift_name("set(index:value:)")));
- (void)setLengthNewLength:(int32_t)newLength __attribute__((swift_name("setLength(newLength:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (Sdk_coreKotlinStringBuilder *)setRangeStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex value:(NSString *)value __attribute__((swift_name("setRange(startIndex:endIndex:value:)")));
- (id)subSequenceStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("subSequence(startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (NSString *)substringStartIndex:(int32_t)startIndex __attribute__((swift_name("substring(startIndex:)")));
- (NSString *)substringStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("substring(startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (void)toCharArrayDestination:(Sdk_coreKotlinCharArray *)destination destinationOffset:(int32_t)destinationOffset startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("toCharArray(destination:destinationOffset:startIndex:endIndex:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (void)trimToSize __attribute__((swift_name("trimToSize()")));
@property (readonly) int32_t length __attribute__((swift_name("length")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinRegex")))
@interface Sdk_coreKotlinRegex : Sdk_coreBase
- (instancetype)initWithPattern:(NSString *)pattern __attribute__((swift_name("init(pattern:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPattern:(NSString *)pattern options:(NSSet<Sdk_coreKotlinRegexOption *> *)options __attribute__((swift_name("init(pattern:options:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPattern:(NSString *)pattern option:(Sdk_coreKotlinRegexOption *)option __attribute__((swift_name("init(pattern:option:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKotlinRegexCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsMatchInInput:(id)input __attribute__((swift_name("containsMatchIn(input:)")));
- (id<Sdk_coreKotlinMatchResult> _Nullable)findInput:(id)input startIndex:(int32_t)startIndex __attribute__((swift_name("find(input:startIndex:)")));
- (id<Sdk_coreKotlinSequence>)findAllInput:(id)input startIndex:(int32_t)startIndex __attribute__((swift_name("findAll(input:startIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.7")
*/
- (id<Sdk_coreKotlinMatchResult> _Nullable)matchAtInput:(id)input index:(int32_t)index __attribute__((swift_name("matchAt(input:index:)")));
- (id<Sdk_coreKotlinMatchResult> _Nullable)matchEntireInput:(id)input __attribute__((swift_name("matchEntire(input:)")));
- (BOOL)matchesInput:(id)input __attribute__((swift_name("matches(input:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.7")
*/
- (BOOL)matchesAtInput:(id)input index:(int32_t)index __attribute__((swift_name("matchesAt(input:index:)")));
- (NSString *)replaceInput:(id)input transform:(id (^)(id<Sdk_coreKotlinMatchResult>))transform __attribute__((swift_name("replace(input:transform:)")));
- (NSString *)replaceInput:(id)input replacement:(NSString *)replacement __attribute__((swift_name("replace(input:replacement:)")));
- (NSString *)replaceFirstInput:(id)input replacement:(NSString *)replacement __attribute__((swift_name("replaceFirst(input:replacement:)")));
- (NSArray<NSString *> *)splitInput:(id)input limit:(int32_t)limit __attribute__((swift_name("split(input:limit:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.6")
*/
- (id<Sdk_coreKotlinSequence>)splitToSequenceInput:(id)input limit:(int32_t)limit __attribute__((swift_name("splitToSequence(input:limit:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSSet<Sdk_coreKotlinRegexOption *> *options __attribute__((swift_name("options")));
@property (readonly) NSString *pattern __attribute__((swift_name("pattern")));
@end

__attribute__((swift_name("KotlinFunction")))
@protocol Sdk_coreKotlinFunction
@required
@end

__attribute__((swift_name("KotlinSuspendFunction0")))
@protocol Sdk_coreKotlinSuspendFunction0 <Sdk_coreKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(completionHandler:)")));
@end

__attribute__((swift_name("Ktor_client_coreHttpClientEngine")))
@protocol Sdk_coreKtor_client_coreHttpClientEngine <Sdk_coreKotlinx_coroutines_coreCoroutineScope, Sdk_coreKtor_ioCloseable>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeData:(Sdk_coreKtor_client_coreHttpRequestData *)data completionHandler:(void (^)(Sdk_coreKtor_client_coreHttpResponseData * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(data:completionHandler:)")));
- (void)installClient:(Sdk_coreKtor_client_coreHttpClient *)client __attribute__((swift_name("install(client:)")));
@property (readonly) Sdk_coreKtor_client_coreHttpClientEngineConfig *config __attribute__((swift_name("config")));
@property (readonly) Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher *dispatcher __attribute__((swift_name("dispatcher")));
@property (readonly) NSSet<id<Sdk_coreKtor_client_coreHttpClientEngineCapability>> *supportedCapabilities __attribute__((swift_name("supportedCapabilities")));
@end

__attribute__((swift_name("Ktor_client_coreHttpClientEngineConfig")))
@interface Sdk_coreKtor_client_coreHttpClientEngineConfig : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property BOOL pipelining __attribute__((swift_name("pipelining")));
@property Sdk_coreKtor_client_coreProxyConfig * _Nullable proxy __attribute__((swift_name("proxy")));
@property int32_t threadsCount __attribute__((swift_name("threadsCount"))) __attribute__((deprecated("The [threadsCount] property is deprecated. The [Dispatchers.IO] is used by default.")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpClientConfig")))
@interface Sdk_coreKtor_client_coreHttpClientConfig<T> : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Sdk_coreKtor_client_coreHttpClientConfig<T> *)clone __attribute__((swift_name("clone()")));
- (void)engineBlock:(void (^)(T))block __attribute__((swift_name("engine(block:)")));
- (void)installClient:(Sdk_coreKtor_client_coreHttpClient *)client __attribute__((swift_name("install(client:)")));
- (void)installPlugin:(id<Sdk_coreKtor_client_coreHttpClientPlugin>)plugin configure:(void (^)(id))configure __attribute__((swift_name("install(plugin:configure:)")));
- (void)installKey:(NSString *)key block:(void (^)(Sdk_coreKtor_client_coreHttpClient *))block __attribute__((swift_name("install(key:block:)")));
- (void)plusAssignOther:(Sdk_coreKtor_client_coreHttpClientConfig<T> *)other __attribute__((swift_name("plusAssign(other:)")));
@property BOOL developmentMode __attribute__((swift_name("developmentMode")));
@property BOOL expectSuccess __attribute__((swift_name("expectSuccess")));
@property BOOL followRedirects __attribute__((swift_name("followRedirects")));
@property BOOL useDefaultTransformers __attribute__((swift_name("useDefaultTransformers")));
@end

__attribute__((swift_name("Ktor_client_coreHttpClientEngineCapability")))
@protocol Sdk_coreKtor_client_coreHttpClientEngineCapability
@required
@end

__attribute__((swift_name("Ktor_utilsAttributes")))
@protocol Sdk_coreKtor_utilsAttributes
@required
- (id)computeIfAbsentKey:(Sdk_coreKtor_utilsAttributeKey<id> *)key block:(id (^)(void))block __attribute__((swift_name("computeIfAbsent(key:block:)")));
- (BOOL)containsKey:(Sdk_coreKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("contains(key:)")));
- (id)getKey_:(Sdk_coreKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("get(key_:)")));
- (id _Nullable)getOrNullKey:(Sdk_coreKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getOrNull(key:)")));
- (void)putKey:(Sdk_coreKtor_utilsAttributeKey<id> *)key value:(id)value __attribute__((swift_name("put(key:value:)")));
- (void)removeKey_:(Sdk_coreKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("remove(key_:)")));
- (id)takeKey:(Sdk_coreKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("take(key:)")));
- (id _Nullable)takeOrNullKey:(Sdk_coreKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("takeOrNull(key:)")));
@property (readonly) NSArray<Sdk_coreKtor_utilsAttributeKey<id> *> *allKeys __attribute__((swift_name("allKeys")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_eventsEvents")))
@interface Sdk_coreKtor_eventsEvents : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)raiseDefinition:(Sdk_coreKtor_eventsEventDefinition<id> *)definition value:(id _Nullable)value __attribute__((swift_name("raise(definition:value:)")));
- (id<Sdk_coreKotlinx_coroutines_coreDisposableHandle>)subscribeDefinition:(Sdk_coreKtor_eventsEventDefinition<id> *)definition handler:(void (^)(id _Nullable))handler __attribute__((swift_name("subscribe(definition:handler:)")));
- (void)unsubscribeDefinition:(Sdk_coreKtor_eventsEventDefinition<id> *)definition handler:(void (^)(id _Nullable))handler __attribute__((swift_name("unsubscribe(definition:handler:)")));
@end

__attribute__((swift_name("Ktor_utilsPipeline")))
@interface Sdk_coreKtor_utilsPipeline<TSubject, TContext> : Sdk_coreBase
- (instancetype)initWithPhases:(Sdk_coreKotlinArray<Sdk_coreKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhase:(Sdk_coreKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<Sdk_coreKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer));
- (void)addPhasePhase:(Sdk_coreKtor_utilsPipelinePhase *)phase __attribute__((swift_name("addPhase(phase:)")));
- (void)afterIntercepted __attribute__((swift_name("afterIntercepted()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeContext:(TContext)context subject:(TSubject)subject completionHandler:(void (^)(TSubject _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(context:subject:completionHandler:)")));
- (void)insertPhaseAfterReference:(Sdk_coreKtor_utilsPipelinePhase *)reference phase:(Sdk_coreKtor_utilsPipelinePhase *)phase __attribute__((swift_name("insertPhaseAfter(reference:phase:)")));
- (void)insertPhaseBeforeReference:(Sdk_coreKtor_utilsPipelinePhase *)reference phase:(Sdk_coreKtor_utilsPipelinePhase *)phase __attribute__((swift_name("insertPhaseBefore(reference:phase:)")));
- (void)interceptPhase:(Sdk_coreKtor_utilsPipelinePhase *)phase block:(id<Sdk_coreKotlinSuspendFunction2>)block __attribute__((swift_name("intercept(phase:block:)")));
- (NSArray<id<Sdk_coreKotlinSuspendFunction2>> *)interceptorsForPhasePhase:(Sdk_coreKtor_utilsPipelinePhase *)phase __attribute__((swift_name("interceptorsForPhase(phase:)")));
- (void)mergeFrom:(Sdk_coreKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("merge(from:)")));
- (void)mergePhasesFrom:(Sdk_coreKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("mergePhases(from:)")));
- (void)resetFromFrom:(Sdk_coreKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("resetFrom(from:)")));
@property (readonly) id<Sdk_coreKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@property (readonly, getter=isEmpty_) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) NSArray<Sdk_coreKtor_utilsPipelinePhase *> *items __attribute__((swift_name("items")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpReceivePipeline")))
@interface Sdk_coreKtor_client_coreHttpReceivePipeline : Sdk_coreKtor_utilsPipeline<Sdk_coreKtor_client_coreHttpResponse *, Sdk_coreKotlinUnit *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(Sdk_coreKotlinArray<Sdk_coreKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(Sdk_coreKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<Sdk_coreKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKtor_client_coreHttpReceivePipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestPipeline")))
@interface Sdk_coreKtor_client_coreHttpRequestPipeline : Sdk_coreKtor_utilsPipeline<id, Sdk_coreKtor_client_coreHttpRequestBuilder *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(Sdk_coreKotlinArray<Sdk_coreKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(Sdk_coreKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<Sdk_coreKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKtor_client_coreHttpRequestPipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponsePipeline")))
@interface Sdk_coreKtor_client_coreHttpResponsePipeline : Sdk_coreKtor_utilsPipeline<Sdk_coreKtor_client_coreHttpResponseContainer *, Sdk_coreKtor_client_coreHttpClientCall *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(Sdk_coreKotlinArray<Sdk_coreKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(Sdk_coreKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<Sdk_coreKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKtor_client_coreHttpResponsePipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpSendPipeline")))
@interface Sdk_coreKtor_client_coreHttpSendPipeline : Sdk_coreKtor_utilsPipeline<id, Sdk_coreKtor_client_coreHttpRequestBuilder *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(Sdk_coreKotlinArray<Sdk_coreKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(Sdk_coreKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<Sdk_coreKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKtor_client_coreHttpSendPipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((swift_name("Ktor_httpHttpMessage")))
@protocol Sdk_coreKtor_httpHttpMessage
@required
@property (readonly) id<Sdk_coreKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@end

__attribute__((swift_name("Ktor_client_coreHttpResponse")))
@interface Sdk_coreKtor_client_coreHttpResponse : Sdk_coreBase <Sdk_coreKtor_httpHttpMessage, Sdk_coreKotlinx_coroutines_coreCoroutineScope>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Sdk_coreKtor_client_coreHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) id<Sdk_coreKtor_ioByteReadChannel> content __attribute__((swift_name("content")));
@property (readonly) Sdk_coreKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) Sdk_coreKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *status __attribute__((swift_name("status")));
@property (readonly) Sdk_coreKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
@end

__attribute__((swift_name("Ktor_utilsStringValuesBuilder")))
@protocol Sdk_coreKtor_utilsStringValuesBuilder
@required
- (void)appendName:(NSString *)name value:(NSString *)value __attribute__((swift_name("append(name:value:)")));
- (void)appendAllStringValues:(id<Sdk_coreKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendAll(stringValues:)")));
- (void)appendAllName:(NSString *)name values:(id)values __attribute__((swift_name("appendAll(name:values:)")));
- (void)appendMissingStringValues:(id<Sdk_coreKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendMissing(stringValues:)")));
- (void)appendMissingName:(NSString *)name values:(id)values __attribute__((swift_name("appendMissing(name:values:)")));
- (id<Sdk_coreKtor_utilsStringValues>)build __attribute__((swift_name("build()")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<Sdk_coreKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
- (void)removeName:(NSString *)name __attribute__((swift_name("remove(name:)")));
- (BOOL)removeName:(NSString *)name value:(NSString *)value __attribute__((swift_name("remove(name:value:)")));
- (void)removeKeysWithNoEntries __attribute__((swift_name("removeKeysWithNoEntries()")));
- (void)setName:(NSString *)name value:(NSString *)value __attribute__((swift_name("set(name:value:)")));
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));
@end

__attribute__((swift_name("Ktor_utilsStringValuesBuilderImpl")))
@interface Sdk_coreKtor_utilsStringValuesBuilderImpl : Sdk_coreBase <Sdk_coreKtor_utilsStringValuesBuilder>
- (instancetype)initWithCaseInsensitiveName:(BOOL)caseInsensitiveName size:(int32_t)size __attribute__((swift_name("init(caseInsensitiveName:size:)"))) __attribute__((objc_designated_initializer));
- (void)appendName:(NSString *)name value:(NSString *)value __attribute__((swift_name("append(name:value:)")));
- (void)appendAllStringValues:(id<Sdk_coreKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendAll(stringValues:)")));
- (void)appendAllName:(NSString *)name values:(id)values __attribute__((swift_name("appendAll(name:values:)")));
- (void)appendMissingStringValues:(id<Sdk_coreKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendMissing(stringValues:)")));
- (void)appendMissingName:(NSString *)name values:(id)values __attribute__((swift_name("appendMissing(name:values:)")));
- (id<Sdk_coreKtor_utilsStringValues>)build __attribute__((swift_name("build()")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<Sdk_coreKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
- (void)removeName:(NSString *)name __attribute__((swift_name("remove(name:)")));
- (BOOL)removeName:(NSString *)name value:(NSString *)value __attribute__((swift_name("remove(name:value:)")));
- (void)removeKeysWithNoEntries __attribute__((swift_name("removeKeysWithNoEntries()")));
- (void)setName:(NSString *)name value:(NSString *)value __attribute__((swift_name("set(name:value:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateNameName:(NSString *)name __attribute__((swift_name("validateName(name:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateValueValue:(NSString *)value __attribute__((swift_name("validateValue(value:)")));
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) Sdk_coreMutableDictionary<NSString *, NSMutableArray<NSString *> *> *values __attribute__((swift_name("values")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeadersBuilder")))
@interface Sdk_coreKtor_httpHeadersBuilder : Sdk_coreKtor_utilsStringValuesBuilderImpl
- (instancetype)initWithSize:(int32_t)size __attribute__((swift_name("init(size:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCaseInsensitiveName:(BOOL)caseInsensitiveName size:(int32_t)size __attribute__((swift_name("init(caseInsensitiveName:size:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (id<Sdk_coreKtor_httpHeaders>)build __attribute__((swift_name("build()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateNameName:(NSString *)name __attribute__((swift_name("validateName(name:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateValueValue:(NSString *)value __attribute__((swift_name("validateValue(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestBuilder.Companion")))
@interface Sdk_coreKtor_client_coreHttpRequestBuilderCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_client_coreHttpRequestBuilderCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestData")))
@interface Sdk_coreKtor_client_coreHttpRequestData : Sdk_coreBase
- (instancetype)initWithUrl:(Sdk_coreKtor_httpUrl *)url method:(Sdk_coreKtor_httpHttpMethod *)method headers:(id<Sdk_coreKtor_httpHeaders>)headers body:(Sdk_coreKtor_httpOutgoingContent *)body executionContext:(id<Sdk_coreKotlinx_coroutines_coreJob>)executionContext attributes:(id<Sdk_coreKtor_utilsAttributes>)attributes __attribute__((swift_name("init(url:method:headers:body:executionContext:attributes:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)getCapabilityOrNullKey:(id<Sdk_coreKtor_client_coreHttpClientEngineCapability>)key __attribute__((swift_name("getCapabilityOrNull(key:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<Sdk_coreKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) Sdk_coreKtor_httpOutgoingContent *body __attribute__((swift_name("body")));
@property (readonly) id<Sdk_coreKotlinx_coroutines_coreJob> executionContext __attribute__((swift_name("executionContext")));
@property (readonly) id<Sdk_coreKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) Sdk_coreKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) Sdk_coreKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLBuilder")))
@interface Sdk_coreKtor_httpURLBuilder : Sdk_coreBase
- (instancetype)initWithProtocol:(Sdk_coreKtor_httpURLProtocol *)protocol host:(NSString *)host port:(int32_t)port user:(NSString * _Nullable)user password:(NSString * _Nullable)password pathSegments:(NSArray<NSString *> *)pathSegments parameters:(id<Sdk_coreKtor_httpParameters>)parameters fragment:(NSString *)fragment trailingQuery:(BOOL)trailingQuery __attribute__((swift_name("init(protocol:host:port:user:password:pathSegments:parameters:fragment:trailingQuery:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKtor_httpURLBuilderCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreKtor_httpUrl *)build __attribute__((swift_name("build()")));
- (NSString *)buildString __attribute__((swift_name("buildString()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString *encodedFragment __attribute__((swift_name("encodedFragment")));
@property id<Sdk_coreKtor_httpParametersBuilder> encodedParameters __attribute__((swift_name("encodedParameters")));
@property NSString * _Nullable encodedPassword __attribute__((swift_name("encodedPassword")));
@property NSArray<NSString *> *encodedPathSegments __attribute__((swift_name("encodedPathSegments")));
@property NSString * _Nullable encodedUser __attribute__((swift_name("encodedUser")));
@property NSString *fragment __attribute__((swift_name("fragment")));
@property NSString *host __attribute__((swift_name("host")));
@property (readonly) id<Sdk_coreKtor_httpParametersBuilder> parameters __attribute__((swift_name("parameters")));
@property NSString * _Nullable password __attribute__((swift_name("password")));
@property NSArray<NSString *> *pathSegments __attribute__((swift_name("pathSegments")));
@property int32_t port __attribute__((swift_name("port")));
@property Sdk_coreKtor_httpURLProtocol *protocol __attribute__((swift_name("protocol")));
@property BOOL trailingQuery __attribute__((swift_name("trailingQuery")));
@property NSString * _Nullable user __attribute__((swift_name("user")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsTypeInfo")))
@interface Sdk_coreKtor_utilsTypeInfo : Sdk_coreBase
- (instancetype)initWithType:(id<Sdk_coreKotlinKClass>)type reifiedType:(id<Sdk_coreKotlinKType>)reifiedType kotlinType:(id<Sdk_coreKotlinKType> _Nullable)kotlinType __attribute__((swift_name("init(type:reifiedType:kotlinType:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreKtor_utilsTypeInfo *)doCopyType:(id<Sdk_coreKotlinKClass>)type reifiedType:(id<Sdk_coreKotlinKType>)reifiedType kotlinType:(id<Sdk_coreKotlinKType> _Nullable)kotlinType __attribute__((swift_name("doCopy(type:reifiedType:kotlinType:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<Sdk_coreKotlinKType> _Nullable kotlinType __attribute__((swift_name("kotlinType")));
@property (readonly) id<Sdk_coreKotlinKType> reifiedType __attribute__((swift_name("reifiedType")));
@property (readonly) id<Sdk_coreKotlinKClass> type __attribute__((swift_name("type")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpMethod")))
@interface Sdk_coreKtor_httpHttpMethod : Sdk_coreBase
- (instancetype)initWithValue:(NSString *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKtor_httpHttpMethodCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreKtor_httpHttpMethod *)doCopyValue:(NSString *)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((swift_name("Ktor_httpParameters")))
@protocol Sdk_coreKtor_httpParameters <Sdk_coreKtor_utilsStringValues>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLProtocol")))
@interface Sdk_coreKtor_httpURLProtocol : Sdk_coreBase
- (instancetype)initWithName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("init(name:defaultPort:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKtor_httpURLProtocolCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreKtor_httpURLProtocol *)doCopyName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("doCopy(name:defaultPort:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t defaultPort __attribute__((swift_name("defaultPort")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface Sdk_coreKotlinByteIterator : Sdk_coreBase <Sdk_coreKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Sdk_coreByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextElement")))
@interface Sdk_coreKotlinAbstractCoroutineContextElement : Sdk_coreBase <Sdk_coreKotlinCoroutineContextElement>
- (instancetype)initWithKey:(id<Sdk_coreKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<Sdk_coreKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuationInterceptor")))
@protocol Sdk_coreKotlinContinuationInterceptor <Sdk_coreKotlinCoroutineContextElement>
@required
- (id<Sdk_coreKotlinContinuation>)interceptContinuationContinuation:(id<Sdk_coreKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (void)releaseInterceptedContinuationContinuation:(id<Sdk_coreKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher")))
@interface Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher : Sdk_coreKotlinAbstractCoroutineContextElement <Sdk_coreKotlinContinuationInterceptor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithKey:(id<Sdk_coreKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKotlinx_coroutines_coreCoroutineDispatcherKey *companion __attribute__((swift_name("companion")));
- (void)dispatchContext:(id<Sdk_coreKotlinCoroutineContext>)context block:(id<Sdk_coreKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatch(context:block:)")));
- (void)dispatchYieldContext:(id<Sdk_coreKotlinCoroutineContext>)context block:(id<Sdk_coreKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatchYield(context:block:)")));
- (id<Sdk_coreKotlinContinuation>)interceptContinuationContinuation:(id<Sdk_coreKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (BOOL)isDispatchNeededContext:(id<Sdk_coreKotlinCoroutineContext>)context __attribute__((swift_name("isDispatchNeeded(context:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher *)limitedParallelismParallelism:(int32_t)parallelism __attribute__((swift_name("limitedParallelism(parallelism:)")));
- (Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher *)plusOther_:(Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher *)other __attribute__((swift_name("plus(other_:)"))) __attribute__((unavailable("Operator '+' on two CoroutineDispatcher objects is meaningless. CoroutineDispatcher is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The dispatcher to the right of `+` just replaces the dispatcher to the left.")));
- (void)releaseInterceptedContinuationContinuation:(id<Sdk_coreKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreMainCoroutineDispatcher")))
@interface Sdk_coreKotlinx_coroutines_coreMainCoroutineDispatcher : Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher *)limitedParallelismParallelism:(int32_t)parallelism __attribute__((swift_name("limitedParallelism(parallelism:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString * _Nullable)toStringInternalImpl __attribute__((swift_name("toStringInternalImpl()")));
@property (readonly) Sdk_coreKotlinx_coroutines_coreMainCoroutineDispatcher *immediate __attribute__((swift_name("immediate")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_datetimeInstant.Companion")))
@interface Sdk_coreKotlinx_datetimeInstantCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinx_datetimeInstantCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreKotlinx_datetimeInstant *)fromEpochMillisecondsEpochMilliseconds:(int64_t)epochMilliseconds __attribute__((swift_name("fromEpochMilliseconds(epochMilliseconds:)")));
- (Sdk_coreKotlinx_datetimeInstant *)fromEpochSecondsEpochSeconds:(int64_t)epochSeconds nanosecondAdjustment:(int32_t)nanosecondAdjustment __attribute__((swift_name("fromEpochSeconds(epochSeconds:nanosecondAdjustment:)")));
- (Sdk_coreKotlinx_datetimeInstant *)fromEpochSecondsEpochSeconds:(int64_t)epochSeconds nanosecondAdjustment_:(int64_t)nanosecondAdjustment __attribute__((swift_name("fromEpochSeconds(epochSeconds:nanosecondAdjustment_:)")));
- (Sdk_coreKotlinx_datetimeInstant *)now __attribute__((swift_name("now()"))) __attribute__((unavailable("Use Clock.System.now() instead")));
- (Sdk_coreKotlinx_datetimeInstant *)parseInput:(id)input format:(id<Sdk_coreKotlinx_datetimeDateTimeFormat>)format __attribute__((swift_name("parse(input:format:)")));
- (id<Sdk_coreKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@property (readonly) Sdk_coreKotlinx_datetimeInstant *DISTANT_FUTURE __attribute__((swift_name("DISTANT_FUTURE")));
@property (readonly) Sdk_coreKotlinx_datetimeInstant *DISTANT_PAST __attribute__((swift_name("DISTANT_PAST")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface Sdk_coreKotlinNothing : Sdk_coreBase
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlowCollector")))
@protocol Sdk_coreKotlinx_coroutines_coreFlowCollector
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(id _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreDisposableHandle")))
@protocol Sdk_coreKotlinx_coroutines_coreDisposableHandle
@required
- (void)dispose __attribute__((swift_name("dispose()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreChildHandle")))
@protocol Sdk_coreKotlinx_coroutines_coreChildHandle <Sdk_coreKotlinx_coroutines_coreDisposableHandle>
@required
- (BOOL)childCancelledCause:(Sdk_coreKotlinThrowable *)cause __attribute__((swift_name("childCancelled(cause:)")));
@property (readonly) id<Sdk_coreKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreChildJob")))
@protocol Sdk_coreKotlinx_coroutines_coreChildJob <Sdk_coreKotlinx_coroutines_coreJob>
@required
- (void)parentCancelledParentJob:(id<Sdk_coreKotlinx_coroutines_coreParentJob>)parentJob __attribute__((swift_name("parentCancelled(parentJob:)")));
@end

__attribute__((swift_name("KotlinSequence")))
@protocol Sdk_coreKotlinSequence
@required
- (id<Sdk_coreKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause")))
@protocol Sdk_coreKotlinx_coroutines_coreSelectClause
@required
@property (readonly) id clauseObject __attribute__((swift_name("clauseObject")));
@property (readonly) Sdk_coreKotlinUnit *(^(^ _Nullable onCancellationConstructor)(id<Sdk_coreKotlinx_coroutines_coreSelectInstance>, id _Nullable, id _Nullable))(Sdk_coreKotlinThrowable *) __attribute__((swift_name("onCancellationConstructor")));
@property (readonly) id _Nullable (^processResFunc)(id, id _Nullable, id _Nullable) __attribute__((swift_name("processResFunc")));
@property (readonly) void (^regFunc)(id, id<Sdk_coreKotlinx_coroutines_coreSelectInstance>, id _Nullable) __attribute__((swift_name("regFunc")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause0")))
@protocol Sdk_coreKotlinx_coroutines_coreSelectClause0 <Sdk_coreKotlinx_coroutines_coreSelectClause>
@required
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol Sdk_coreKotlinCoroutineContextKey
@required
@end

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol Sdk_coreKotlinx_serialization_coreEncoder
@required
- (id<Sdk_coreKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<Sdk_coreKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<Sdk_coreKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNull __attribute__((swift_name("encodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableValueSerializer:(id<Sdk_coreKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<Sdk_coreKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) Sdk_coreKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol Sdk_coreKotlinx_serialization_coreSerialDescriptor
@required

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSArray<id<Sdk_coreKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSArray<id<Sdk_coreKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) Sdk_coreKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol Sdk_coreKotlinx_serialization_coreDecoder
@required
- (id<Sdk_coreKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<Sdk_coreKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (Sdk_coreKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<Sdk_coreKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<Sdk_coreKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) Sdk_coreKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioMemory")))
@interface Sdk_coreKtor_ioMemory : Sdk_coreBase
- (instancetype)initWithPointer:(void *)pointer size:(int64_t)size __attribute__((swift_name("init(pointer:size:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKtor_ioMemoryCompanion *companion __attribute__((swift_name("companion")));
- (void)doCopyToDestination:(Sdk_coreKtor_ioMemory *)destination offset:(int32_t)offset length:(int32_t)length destinationOffset:(int32_t)destinationOffset __attribute__((swift_name("doCopyTo(destination:offset:length:destinationOffset:)")));
- (void)doCopyToDestination:(Sdk_coreKtor_ioMemory *)destination offset:(int64_t)offset length:(int64_t)length destinationOffset_:(int64_t)destinationOffset __attribute__((swift_name("doCopyTo(destination:offset:length:destinationOffset_:)")));
- (int8_t)loadAtIndex:(int32_t)index __attribute__((swift_name("loadAt(index:)")));
- (int8_t)loadAtIndex_:(int64_t)index __attribute__((swift_name("loadAt(index_:)")));
- (Sdk_coreKtor_ioMemory *)sliceOffset:(int32_t)offset length:(int32_t)length __attribute__((swift_name("slice(offset:length:)")));
- (Sdk_coreKtor_ioMemory *)sliceOffset:(int64_t)offset length_:(int64_t)length __attribute__((swift_name("slice(offset:length_:)")));
- (void)storeAtIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("storeAt(index:value:)")));
- (void)storeAtIndex:(int64_t)index value_:(int8_t)value __attribute__((swift_name("storeAt(index:value_:)")));
@property (readonly) void *pointer __attribute__((swift_name("pointer")));
@property (readonly) int64_t size __attribute__((swift_name("size")));
@property (readonly) int32_t size32 __attribute__((swift_name("size32")));
@end

__attribute__((swift_name("Ktor_ioBuffer")))
@interface Sdk_coreKtor_ioBuffer : Sdk_coreBase
- (instancetype)initWithMemory:(Sdk_coreKtor_ioMemory *)memory __attribute__((swift_name("init(memory:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("\n    We're migrating to the new kotlinx-io library.\n    This declaration is deprecated and will be removed in Ktor 4.0.0\n    If you have any problems with migration, please contact us in \n    https://youtrack.jetbrains.com/issue/KTOR-6030/Migrate-to-new-kotlinx.io-library\n    ")));
@property (class, readonly, getter=companion) Sdk_coreKtor_ioBufferCompanion *companion __attribute__((swift_name("companion")));
- (void)commitWrittenCount:(int32_t)count __attribute__((swift_name("commitWritten(count:)")));
- (void)discardExactCount:(int32_t)count __attribute__((swift_name("discardExact(count:)")));
- (Sdk_coreKtor_ioBuffer *)duplicate __attribute__((swift_name("duplicate()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)duplicateToCopy:(Sdk_coreKtor_ioBuffer *)copy __attribute__((swift_name("duplicateTo(copy:)")));
- (int8_t)readByte __attribute__((swift_name("readByte()")));
- (void)reserveEndGapEndGap:(int32_t)endGap __attribute__((swift_name("reserveEndGap(endGap:)")));
- (void)reserveStartGapStartGap:(int32_t)startGap __attribute__((swift_name("reserveStartGap(startGap:)")));
- (void)reset __attribute__((swift_name("reset()")));
- (void)resetForRead __attribute__((swift_name("resetForRead()")));
- (void)resetForWrite __attribute__((swift_name("resetForWrite()")));
- (void)resetForWriteLimit:(int32_t)limit __attribute__((swift_name("resetForWrite(limit:)")));
- (void)rewindCount:(int32_t)count __attribute__((swift_name("rewind(count:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (int32_t)tryPeekByte __attribute__((swift_name("tryPeekByte()")));
- (int32_t)tryReadByte __attribute__((swift_name("tryReadByte()")));
- (void)writeByteValue:(int8_t)value __attribute__((swift_name("writeByte(value:)")));
@property (readonly) int32_t capacity __attribute__((swift_name("capacity")));
@property (readonly) int32_t endGap __attribute__((swift_name("endGap")));
@property (readonly) int32_t limit __attribute__((swift_name("limit")));
@property (readonly) Sdk_coreKtor_ioMemory *memory __attribute__((swift_name("memory")));
@property (readonly) int32_t readPosition __attribute__((swift_name("readPosition")));
@property (readonly) int32_t readRemaining __attribute__((swift_name("readRemaining")));
@property (readonly) int32_t startGap __attribute__((swift_name("startGap")));
@property (readonly) int32_t writePosition __attribute__((swift_name("writePosition")));
@property (readonly) int32_t writeRemaining __attribute__((swift_name("writeRemaining")));
@end

__attribute__((swift_name("Ktor_ioChunkBuffer")))
@interface Sdk_coreKtor_ioChunkBuffer : Sdk_coreKtor_ioBuffer
- (instancetype)initWithMemory:(Sdk_coreKtor_ioMemory *)memory origin:(Sdk_coreKtor_ioChunkBuffer * _Nullable)origin parentPool:(id<Sdk_coreKtor_ioObjectPool> _Nullable)parentPool __attribute__((swift_name("init(memory:origin:parentPool:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("\n    We're migrating to the new kotlinx-io library.\n    This declaration is deprecated and will be removed in Ktor 4.0.0\n    If you have any problems with migration, please contact us in \n    https://youtrack.jetbrains.com/issue/KTOR-6030/Migrate-to-new-kotlinx.io-library\n    ")));
- (instancetype)initWithMemory:(Sdk_coreKtor_ioMemory *)memory __attribute__((swift_name("init(memory:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKtor_ioChunkBufferCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreKtor_ioChunkBuffer * _Nullable)cleanNext __attribute__((swift_name("cleanNext()")));
- (Sdk_coreKtor_ioChunkBuffer *)duplicate __attribute__((swift_name("duplicate()")));
- (void)releasePool:(id<Sdk_coreKtor_ioObjectPool>)pool __attribute__((swift_name("release(pool:)")));
- (void)reset __attribute__((swift_name("reset()")));
@property (getter=next_) Sdk_coreKtor_ioChunkBuffer * _Nullable next __attribute__((swift_name("next")));
@property (readonly) Sdk_coreKtor_ioChunkBuffer * _Nullable origin __attribute__((swift_name("origin")));
@property (readonly) int32_t referenceCount __attribute__((swift_name("referenceCount")));
@end

__attribute__((swift_name("Ktor_ioInput")))
@interface Sdk_coreKtor_ioInput : Sdk_coreBase <Sdk_coreKtor_ioCloseable>
- (instancetype)initWithHead:(Sdk_coreKtor_ioChunkBuffer *)head remaining:(int64_t)remaining pool:(id<Sdk_coreKtor_ioObjectPool>)pool __attribute__((swift_name("init(head:remaining:pool:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("\n    We're migrating to the new kotlinx-io library.\n    This declaration is deprecated and will be removed in Ktor 4.0.0\n    If you have any problems with migration, please contact us in \n    https://youtrack.jetbrains.com/issue/KTOR-6030/Migrate-to-new-kotlinx.io-library\n    ")));
@property (class, readonly, getter=companion) Sdk_coreKtor_ioInputCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)canRead __attribute__((swift_name("canRead()")));
- (void)close __attribute__((swift_name("close()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)closeSource __attribute__((swift_name("closeSource()")));
- (int32_t)discardN:(int32_t)n __attribute__((swift_name("discard(n:)")));
- (int64_t)discardN_:(int64_t)n __attribute__((swift_name("discard(n_:)")));
- (void)discardExactN:(int32_t)n __attribute__((swift_name("discardExact(n:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (Sdk_coreKtor_ioChunkBuffer * _Nullable)fill __attribute__((swift_name("fill()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (int32_t)fillDestination:(Sdk_coreKtor_ioMemory *)destination offset:(int32_t)offset length:(int32_t)length __attribute__((swift_name("fill(destination:offset:length:)")));
- (BOOL)hasBytesN:(int32_t)n __attribute__((swift_name("hasBytes(n:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)markNoMoreChunksAvailable __attribute__((swift_name("markNoMoreChunksAvailable()")));
- (int32_t)peekToBuffer:(Sdk_coreKtor_ioChunkBuffer *)buffer __attribute__((swift_name("peekTo(buffer:)")));
- (int64_t)peekToDestination:(Sdk_coreKtor_ioMemory *)destination destinationOffset:(int64_t)destinationOffset offset:(int64_t)offset min:(int64_t)min max:(int64_t)max __attribute__((swift_name("peekTo(destination:destinationOffset:offset:min:max:)")));
- (int8_t)readByte __attribute__((swift_name("readByte()")));
- (NSString *)readTextMin:(int32_t)min max:(int32_t)max __attribute__((swift_name("readText(min:max:)")));
- (int32_t)readTextOut:(id<Sdk_coreKotlinAppendable>)out min:(int32_t)min max:(int32_t)max __attribute__((swift_name("readText(out:min:max:)")));
- (NSString *)readTextExactExactCharacters:(int32_t)exactCharacters __attribute__((swift_name("readTextExact(exactCharacters:)")));
- (void)readTextExactOut:(id<Sdk_coreKotlinAppendable>)out exactCharacters:(int32_t)exactCharacters __attribute__((swift_name("readTextExact(out:exactCharacters:)")));
- (void)release_ __attribute__((swift_name("release()")));
- (int32_t)tryPeek __attribute__((swift_name("tryPeek()")));
@property (readonly) BOOL endOfInput __attribute__((swift_name("endOfInput")));
@property (readonly) id<Sdk_coreKtor_ioObjectPool> pool __attribute__((swift_name("pool")));
@property (readonly) int64_t remaining __attribute__((swift_name("remaining")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioByteReadPacket")))
@interface Sdk_coreKtor_ioByteReadPacket : Sdk_coreKtor_ioInput
- (instancetype)initWithHead:(Sdk_coreKtor_ioChunkBuffer *)head pool:(id<Sdk_coreKtor_ioObjectPool>)pool __attribute__((swift_name("init(head:pool:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithHead:(Sdk_coreKtor_ioChunkBuffer *)head remaining:(int64_t)remaining pool:(id<Sdk_coreKtor_ioObjectPool>)pool __attribute__((swift_name("init(head:remaining:pool:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKtor_ioByteReadPacketCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)closeSource __attribute__((swift_name("closeSource()")));
- (Sdk_coreKtor_ioByteReadPacket *)doCopy __attribute__((swift_name("doCopy()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (Sdk_coreKtor_ioChunkBuffer * _Nullable)fill __attribute__((swift_name("fill()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (int32_t)fillDestination:(Sdk_coreKtor_ioMemory *)destination offset:(int32_t)offset length:(int32_t)length __attribute__((swift_name("fill(destination:offset:length:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Ktor_ioReadSession")))
@protocol Sdk_coreKtor_ioReadSession
@required
- (int32_t)discardN:(int32_t)n __attribute__((swift_name("discard(n:)")));
- (Sdk_coreKtor_ioChunkBuffer * _Nullable)requestAtLeast:(int32_t)atLeast __attribute__((swift_name("request(atLeast:)")));
@property (readonly) int32_t availableForRead __attribute__((swift_name("availableForRead")));
@end

__attribute__((swift_name("KotlinSuspendFunction1")))
@protocol Sdk_coreKotlinSuspendFunction1 <Sdk_coreKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpStatusCode.Companion")))
@interface Sdk_coreKtor_httpHttpStatusCodeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_httpHttpStatusCodeCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreKtor_httpHttpStatusCode *)fromValueValue:(int32_t)value __attribute__((swift_name("fromValue(value:)")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *Accepted __attribute__((swift_name("Accepted")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *BadGateway __attribute__((swift_name("BadGateway")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *BadRequest __attribute__((swift_name("BadRequest")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *Conflict __attribute__((swift_name("Conflict")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *Continue __attribute__((swift_name("Continue")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *Created __attribute__((swift_name("Created")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *ExpectationFailed __attribute__((swift_name("ExpectationFailed")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *FailedDependency __attribute__((swift_name("FailedDependency")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *Forbidden __attribute__((swift_name("Forbidden")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *Found __attribute__((swift_name("Found")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *GatewayTimeout __attribute__((swift_name("GatewayTimeout")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *Gone __attribute__((swift_name("Gone")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *InsufficientStorage __attribute__((swift_name("InsufficientStorage")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *InternalServerError __attribute__((swift_name("InternalServerError")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *LengthRequired __attribute__((swift_name("LengthRequired")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *Locked __attribute__((swift_name("Locked")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *MethodNotAllowed __attribute__((swift_name("MethodNotAllowed")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *MovedPermanently __attribute__((swift_name("MovedPermanently")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *MultiStatus __attribute__((swift_name("MultiStatus")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *MultipleChoices __attribute__((swift_name("MultipleChoices")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *NoContent __attribute__((swift_name("NoContent")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *NonAuthoritativeInformation __attribute__((swift_name("NonAuthoritativeInformation")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *NotAcceptable __attribute__((swift_name("NotAcceptable")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *NotFound __attribute__((swift_name("NotFound")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *NotImplemented __attribute__((swift_name("NotImplemented")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *NotModified __attribute__((swift_name("NotModified")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *OK __attribute__((swift_name("OK")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *PartialContent __attribute__((swift_name("PartialContent")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *PayloadTooLarge __attribute__((swift_name("PayloadTooLarge")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *PaymentRequired __attribute__((swift_name("PaymentRequired")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *PermanentRedirect __attribute__((swift_name("PermanentRedirect")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *PreconditionFailed __attribute__((swift_name("PreconditionFailed")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *Processing __attribute__((swift_name("Processing")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *ProxyAuthenticationRequired __attribute__((swift_name("ProxyAuthenticationRequired")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *RequestHeaderFieldTooLarge __attribute__((swift_name("RequestHeaderFieldTooLarge")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *RequestTimeout __attribute__((swift_name("RequestTimeout")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *RequestURITooLong __attribute__((swift_name("RequestURITooLong")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *RequestedRangeNotSatisfiable __attribute__((swift_name("RequestedRangeNotSatisfiable")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *ResetContent __attribute__((swift_name("ResetContent")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *SeeOther __attribute__((swift_name("SeeOther")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *ServiceUnavailable __attribute__((swift_name("ServiceUnavailable")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *SwitchProxy __attribute__((swift_name("SwitchProxy")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *SwitchingProtocols __attribute__((swift_name("SwitchingProtocols")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *TemporaryRedirect __attribute__((swift_name("TemporaryRedirect")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *TooEarly __attribute__((swift_name("TooEarly")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *TooManyRequests __attribute__((swift_name("TooManyRequests")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *Unauthorized __attribute__((swift_name("Unauthorized")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *UnprocessableEntity __attribute__((swift_name("UnprocessableEntity")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *UnsupportedMediaType __attribute__((swift_name("UnsupportedMediaType")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *UpgradeRequired __attribute__((swift_name("UpgradeRequired")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *UseProxy __attribute__((swift_name("UseProxy")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *VariantAlsoNegotiates __attribute__((swift_name("VariantAlsoNegotiates")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *VersionNotSupported __attribute__((swift_name("VersionNotSupported")));
@property (readonly) NSArray<Sdk_coreKtor_httpHttpStatusCode *> *allStatusCodes __attribute__((swift_name("allStatusCodes")));
@end

__attribute__((swift_name("KotlinMapEntry")))
@protocol Sdk_coreKotlinMapEntry
@required
@property (readonly) id _Nullable key __attribute__((swift_name("key")));
@property (readonly) id _Nullable value_ __attribute__((swift_name("value_")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface Sdk_coreKotlinx_serialization_coreSerializersModule : Sdk_coreBase

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<Sdk_coreKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<Sdk_coreKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<Sdk_coreKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<Sdk_coreKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<Sdk_coreKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<Sdk_coreKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<Sdk_coreKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<Sdk_coreKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJson.Default")))
@interface Sdk_coreKotlinx_serialization_jsonJsonDefault : Sdk_coreKotlinx_serialization_jsonJson
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)default_ __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinx_serialization_jsonJsonDefault *shared __attribute__((swift_name("shared")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/serialization/json/JsonElementSerializer))
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement")))
@interface Sdk_coreKotlinx_serialization_jsonJsonElement : Sdk_coreBase
@property (class, readonly, getter=companion) Sdk_coreKotlinx_serialization_jsonJsonElementCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonConfiguration")))
@interface Sdk_coreKotlinx_serialization_jsonJsonConfiguration : Sdk_coreBase
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL allowSpecialFloatingPointValues __attribute__((swift_name("allowSpecialFloatingPointValues")));
@property (readonly) BOOL allowStructuredMapKeys __attribute__((swift_name("allowStructuredMapKeys")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL allowTrailingComma __attribute__((swift_name("allowTrailingComma")));
@property (readonly) NSString *classDiscriminator __attribute__((swift_name("classDiscriminator")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property Sdk_coreKotlinx_serialization_jsonClassDiscriminatorMode *classDiscriminatorMode __attribute__((swift_name("classDiscriminatorMode")));
@property (readonly) BOOL coerceInputValues __attribute__((swift_name("coerceInputValues")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL decodeEnumsCaseInsensitive __attribute__((swift_name("decodeEnumsCaseInsensitive")));
@property (readonly) BOOL encodeDefaults __attribute__((swift_name("encodeDefaults")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL explicitNulls __attribute__((swift_name("explicitNulls")));
@property (readonly) BOOL ignoreUnknownKeys __attribute__((swift_name("ignoreUnknownKeys")));
@property (readonly) BOOL isLenient __attribute__((swift_name("isLenient")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) id<Sdk_coreKotlinx_serialization_jsonJsonNamingStrategy> _Nullable namingStrategy __attribute__((swift_name("namingStrategy")));
@property (readonly) BOOL prettyPrint __attribute__((swift_name("prettyPrint")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSString *prettyPrintIndent __attribute__((swift_name("prettyPrintIndent")));
@property (readonly) BOOL useAlternativeNames __attribute__((swift_name("useAlternativeNames")));
@property (readonly) BOOL useArrayPolymorphism __attribute__((swift_name("useArrayPolymorphism")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinCharArray")))
@interface Sdk_coreKotlinCharArray : Sdk_coreBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(id (^)(Sdk_coreInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (Sdk_coreKotlinCharIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(unichar)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinRegexOption")))
@interface Sdk_coreKotlinRegexOption : Sdk_coreKotlinEnum<Sdk_coreKotlinRegexOption *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreKotlinRegexOption *ignoreCase __attribute__((swift_name("ignoreCase")));
@property (class, readonly) Sdk_coreKotlinRegexOption *multiline __attribute__((swift_name("multiline")));
@property (class, readonly) Sdk_coreKotlinRegexOption *literal __attribute__((swift_name("literal")));
@property (class, readonly) Sdk_coreKotlinRegexOption *unixLines __attribute__((swift_name("unixLines")));
@property (class, readonly) Sdk_coreKotlinRegexOption *comments __attribute__((swift_name("comments")));
@property (class, readonly) Sdk_coreKotlinRegexOption *dotMatchesAll __attribute__((swift_name("dotMatchesAll")));
@property (class, readonly) Sdk_coreKotlinRegexOption *canonEq __attribute__((swift_name("canonEq")));
+ (Sdk_coreKotlinArray<Sdk_coreKotlinRegexOption *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreKotlinRegexOption *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinRegex.Companion")))
@interface Sdk_coreKotlinRegexCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinRegexCompanion *shared __attribute__((swift_name("shared")));
- (NSString *)escapeLiteral:(NSString *)literal __attribute__((swift_name("escape(literal:)")));
- (NSString *)escapeReplacementLiteral:(NSString *)literal __attribute__((swift_name("escapeReplacement(literal:)")));
- (Sdk_coreKotlinRegex *)fromLiteralLiteral:(NSString *)literal __attribute__((swift_name("fromLiteral(literal:)")));
@end

__attribute__((swift_name("KotlinMatchResult")))
@protocol Sdk_coreKotlinMatchResult
@required
- (id<Sdk_coreKotlinMatchResult> _Nullable)next __attribute__((swift_name("next()")));
@property (readonly) Sdk_coreKotlinMatchResultDestructured *destructured __attribute__((swift_name("destructured")));
@property (readonly) NSArray<NSString *> *groupValues __attribute__((swift_name("groupValues")));
@property (readonly) id<Sdk_coreKotlinMatchGroupCollection> groups __attribute__((swift_name("groups")));
@property (readonly) Sdk_coreKotlinIntRange *range __attribute__((swift_name("range")));
@property (readonly) NSString *value_ __attribute__((swift_name("value_")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponseData")))
@interface Sdk_coreKtor_client_coreHttpResponseData : Sdk_coreBase
- (instancetype)initWithStatusCode:(Sdk_coreKtor_httpHttpStatusCode *)statusCode requestTime:(Sdk_coreKtor_utilsGMTDate *)requestTime headers:(id<Sdk_coreKtor_httpHeaders>)headers version:(Sdk_coreKtor_httpHttpProtocolVersion *)version body:(id)body callContext:(id<Sdk_coreKotlinCoroutineContext>)callContext __attribute__((swift_name("init(statusCode:requestTime:headers:version:body:callContext:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id body __attribute__((swift_name("body")));
@property (readonly) id<Sdk_coreKotlinCoroutineContext> callContext __attribute__((swift_name("callContext")));
@property (readonly) id<Sdk_coreKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) Sdk_coreKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) Sdk_coreKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode *statusCode __attribute__((swift_name("statusCode")));
@property (readonly) Sdk_coreKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreProxyConfig")))
@interface Sdk_coreKtor_client_coreProxyConfig : Sdk_coreBase
- (instancetype)initWithUrl:(Sdk_coreKtor_httpUrl *)url __attribute__((swift_name("init(url:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Sdk_coreKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((swift_name("Ktor_client_coreHttpClientPlugin")))
@protocol Sdk_coreKtor_client_coreHttpClientPlugin
@required
- (void)installPlugin:(id)plugin scope:(Sdk_coreKtor_client_coreHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));
- (id)prepareBlock:(void (^)(id))block __attribute__((swift_name("prepare(block:)")));
@property (readonly) Sdk_coreKtor_utilsAttributeKey<id> *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsAttributeKey")))
@interface Sdk_coreKtor_utilsAttributeKey<T> : Sdk_coreBase
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("Ktor_eventsEventDefinition")))
@interface Sdk_coreKtor_eventsEventDefinition<T> : Sdk_coreBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsPipelinePhase")))
@interface Sdk_coreKtor_utilsPipelinePhase : Sdk_coreBase
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("KotlinSuspendFunction2")))
@protocol Sdk_coreKotlinSuspendFunction2 <Sdk_coreKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 p2:(id _Nullable)p2 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:p2:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpReceivePipeline.Phases")))
@interface Sdk_coreKtor_client_coreHttpReceivePipelinePhases : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_client_coreHttpReceivePipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *After __attribute__((swift_name("After")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface Sdk_coreKotlinUnit : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinUnit *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestPipeline.Phases")))
@interface Sdk_coreKtor_client_coreHttpRequestPipelinePhases : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_client_coreHttpRequestPipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Render __attribute__((swift_name("Render")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Send __attribute__((swift_name("Send")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Transform __attribute__((swift_name("Transform")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponsePipeline.Phases")))
@interface Sdk_coreKtor_client_coreHttpResponsePipelinePhases : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_client_coreHttpResponsePipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *After __attribute__((swift_name("After")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Parse __attribute__((swift_name("Parse")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Receive __attribute__((swift_name("Receive")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Transform __attribute__((swift_name("Transform")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponseContainer")))
@interface Sdk_coreKtor_client_coreHttpResponseContainer : Sdk_coreBase
- (instancetype)initWithExpectedType:(Sdk_coreKtor_utilsTypeInfo *)expectedType response:(id)response __attribute__((swift_name("init(expectedType:response:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreKtor_client_coreHttpResponseContainer *)doCopyExpectedType:(Sdk_coreKtor_utilsTypeInfo *)expectedType response:(id)response __attribute__((swift_name("doCopy(expectedType:response:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Sdk_coreKtor_utilsTypeInfo *expectedType __attribute__((swift_name("expectedType")));
@property (readonly) id response __attribute__((swift_name("response")));
@end

__attribute__((swift_name("Ktor_client_coreHttpClientCall")))
@interface Sdk_coreKtor_client_coreHttpClientCall : Sdk_coreBase <Sdk_coreKotlinx_coroutines_coreCoroutineScope>
- (instancetype)initWithClient:(Sdk_coreKtor_client_coreHttpClient *)client __attribute__((swift_name("init(client:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithClient:(Sdk_coreKtor_client_coreHttpClient *)client requestData:(Sdk_coreKtor_client_coreHttpRequestData *)requestData responseData:(Sdk_coreKtor_client_coreHttpResponseData *)responseData __attribute__((swift_name("init(client:requestData:responseData:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKtor_client_coreHttpClientCallCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyInfo:(Sdk_coreKtor_utilsTypeInfo *)info completionHandler:(void (^)(id _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("body(info:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyNullableInfo:(Sdk_coreKtor_utilsTypeInfo *)info completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("bodyNullable(info:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)getResponseContentWithCompletionHandler:(void (^)(id<Sdk_coreKtor_ioByteReadChannel> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getResponseContent(completionHandler:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) BOOL allowDoubleReceive __attribute__((swift_name("allowDoubleReceive")));
@property (readonly) id<Sdk_coreKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) Sdk_coreKtor_client_coreHttpClient *client __attribute__((swift_name("client")));
@property (readonly) id<Sdk_coreKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property id<Sdk_coreKtor_client_coreHttpRequest> request __attribute__((swift_name("request")));
@property Sdk_coreKtor_client_coreHttpResponse *response __attribute__((swift_name("response")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpSendPipeline.Phases")))
@interface Sdk_coreKtor_client_coreHttpSendPipelinePhases : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_client_coreHttpSendPipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Engine __attribute__((swift_name("Engine")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Monitoring __attribute__((swift_name("Monitoring")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *Receive __attribute__((swift_name("Receive")));
@property (readonly) Sdk_coreKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsGMTDate")))
@interface Sdk_coreKtor_utilsGMTDate : Sdk_coreBase <Sdk_coreKotlinComparable>
@property (class, readonly, getter=companion) Sdk_coreKtor_utilsGMTDateCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(Sdk_coreKtor_utilsGMTDate *)other __attribute__((swift_name("compareTo(other:)")));
- (Sdk_coreKtor_utilsGMTDate *)doCopySeconds:(int32_t)seconds minutes:(int32_t)minutes hours:(int32_t)hours dayOfWeek:(Sdk_coreKtor_utilsWeekDay *)dayOfWeek dayOfMonth:(int32_t)dayOfMonth dayOfYear:(int32_t)dayOfYear month:(Sdk_coreKtor_utilsMonth *)month year:(int32_t)year timestamp:(int64_t)timestamp __attribute__((swift_name("doCopy(seconds:minutes:hours:dayOfWeek:dayOfMonth:dayOfYear:month:year:timestamp:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t dayOfMonth __attribute__((swift_name("dayOfMonth")));
@property (readonly) Sdk_coreKtor_utilsWeekDay *dayOfWeek __attribute__((swift_name("dayOfWeek")));
@property (readonly) int32_t dayOfYear __attribute__((swift_name("dayOfYear")));
@property (readonly) int32_t hours __attribute__((swift_name("hours")));
@property (readonly) int32_t minutes __attribute__((swift_name("minutes")));
@property (readonly) Sdk_coreKtor_utilsMonth *month __attribute__((swift_name("month")));
@property (readonly) int32_t seconds __attribute__((swift_name("seconds")));
@property (readonly) int64_t timestamp __attribute__((swift_name("timestamp")));
@property (readonly) int32_t year __attribute__((swift_name("year")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpProtocolVersion")))
@interface Sdk_coreKtor_httpHttpProtocolVersion : Sdk_coreBase
- (instancetype)initWithName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("init(name:major:minor:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKtor_httpHttpProtocolVersionCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreKtor_httpHttpProtocolVersion *)doCopyName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("doCopy(name:major:minor:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t major __attribute__((swift_name("major")));
@property (readonly) int32_t minor __attribute__((swift_name("minor")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("Ktor_httpOutgoingContent")))
@interface Sdk_coreKtor_httpOutgoingContent : Sdk_coreBase
- (id _Nullable)getPropertyKey:(Sdk_coreKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getProperty(key:)")));
- (void)setPropertyKey:(Sdk_coreKtor_utilsAttributeKey<id> *)key value:(id _Nullable)value __attribute__((swift_name("setProperty(key:value:)")));
- (id<Sdk_coreKtor_httpHeaders> _Nullable)trailers __attribute__((swift_name("trailers()")));
@property (readonly) Sdk_coreLong * _Nullable contentLength __attribute__((swift_name("contentLength")));
@property (readonly) Sdk_coreKtor_httpContentType * _Nullable contentType __attribute__((swift_name("contentType")));
@property (readonly) id<Sdk_coreKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) Sdk_coreKtor_httpHttpStatusCode * _Nullable status __attribute__((swift_name("status")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLBuilder.Companion")))
@interface Sdk_coreKtor_httpURLBuilderCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_httpURLBuilderCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Ktor_httpParametersBuilder")))
@protocol Sdk_coreKtor_httpParametersBuilder <Sdk_coreKtor_utilsStringValuesBuilder>
@required
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol Sdk_coreKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol Sdk_coreKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol Sdk_coreKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol Sdk_coreKotlinKClass <Sdk_coreKotlinKDeclarationContainer, Sdk_coreKotlinKAnnotatedElement, Sdk_coreKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end

__attribute__((swift_name("KotlinKType")))
@protocol Sdk_coreKotlinKType
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) NSArray<Sdk_coreKotlinKTypeProjection *> *arguments __attribute__((swift_name("arguments")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) id<Sdk_coreKotlinKClassifier> _Nullable classifier __attribute__((swift_name("classifier")));
@property (readonly) BOOL isMarkedNullable __attribute__((swift_name("isMarkedNullable")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpMethod.Companion")))
@interface Sdk_coreKtor_httpHttpMethodCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_httpHttpMethodCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreKtor_httpHttpMethod *)parseMethod:(NSString *)method __attribute__((swift_name("parse(method:)")));
@property (readonly) NSArray<Sdk_coreKtor_httpHttpMethod *> *DefaultMethods __attribute__((swift_name("DefaultMethods")));
@property (readonly) Sdk_coreKtor_httpHttpMethod *Delete __attribute__((swift_name("Delete")));
@property (readonly) Sdk_coreKtor_httpHttpMethod *Get __attribute__((swift_name("Get")));
@property (readonly) Sdk_coreKtor_httpHttpMethod *Head __attribute__((swift_name("Head")));
@property (readonly) Sdk_coreKtor_httpHttpMethod *Options __attribute__((swift_name("Options")));
@property (readonly) Sdk_coreKtor_httpHttpMethod *Patch __attribute__((swift_name("Patch")));
@property (readonly) Sdk_coreKtor_httpHttpMethod *Post __attribute__((swift_name("Post")));
@property (readonly) Sdk_coreKtor_httpHttpMethod *Put __attribute__((swift_name("Put")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLProtocol.Companion")))
@interface Sdk_coreKtor_httpURLProtocolCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_httpURLProtocolCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreKtor_httpURLProtocol *)createOrDefaultName:(NSString *)name __attribute__((swift_name("createOrDefault(name:)")));
@property (readonly) Sdk_coreKtor_httpURLProtocol *HTTP __attribute__((swift_name("HTTP")));
@property (readonly) Sdk_coreKtor_httpURLProtocol *HTTPS __attribute__((swift_name("HTTPS")));
@property (readonly) Sdk_coreKtor_httpURLProtocol *SOCKS __attribute__((swift_name("SOCKS")));
@property (readonly) Sdk_coreKtor_httpURLProtocol *WS __attribute__((swift_name("WS")));
@property (readonly) Sdk_coreKtor_httpURLProtocol *WSS __attribute__((swift_name("WSS")));
@property (readonly) NSDictionary<NSString *, Sdk_coreKtor_httpURLProtocol *> *byName __attribute__((swift_name("byName")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuation")))
@protocol Sdk_coreKotlinContinuation
@required
- (void)resumeWithResult:(id _Nullable)result __attribute__((swift_name("resumeWith(result:)")));
@property (readonly) id<Sdk_coreKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextKey")))
@interface Sdk_coreKotlinAbstractCoroutineContextKey<B, E> : Sdk_coreBase <Sdk_coreKotlinCoroutineContextKey>
- (instancetype)initWithBaseKey:(id<Sdk_coreKotlinCoroutineContextKey>)baseKey safeCast:(E _Nullable (^)(id<Sdk_coreKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher.Key")))
@interface Sdk_coreKotlinx_coroutines_coreCoroutineDispatcherKey : Sdk_coreKotlinAbstractCoroutineContextKey<id<Sdk_coreKotlinContinuationInterceptor>, Sdk_coreKotlinx_coroutines_coreCoroutineDispatcher *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithBaseKey:(id<Sdk_coreKotlinCoroutineContextKey>)baseKey safeCast:(id<Sdk_coreKotlinCoroutineContextElement> _Nullable (^)(id<Sdk_coreKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinx_coroutines_coreCoroutineDispatcherKey *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreRunnable")))
@protocol Sdk_coreKotlinx_coroutines_coreRunnable
@required
- (void)run __attribute__((swift_name("run()")));
@end

__attribute__((swift_name("Kotlinx_datetimeDateTimeFormat")))
@protocol Sdk_coreKotlinx_datetimeDateTimeFormat
@required
- (NSString *)formatValue:(id _Nullable)value __attribute__((swift_name("format(value:)")));
- (id<Sdk_coreKotlinAppendable>)formatToAppendable:(id<Sdk_coreKotlinAppendable>)appendable value:(id _Nullable)value __attribute__((swift_name("formatTo(appendable:value:)")));
- (id _Nullable)parseInput:(id)input __attribute__((swift_name("parse(input:)")));
- (id _Nullable)parseOrNullInput:(id)input __attribute__((swift_name("parseOrNull(input:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreParentJob")))
@protocol Sdk_coreKotlinx_coroutines_coreParentJob <Sdk_coreKotlinx_coroutines_coreJob>
@required
- (Sdk_coreKotlinCancellationException *)getChildJobCancellationCause __attribute__((swift_name("getChildJobCancellationCause()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectInstance")))
@protocol Sdk_coreKotlinx_coroutines_coreSelectInstance
@required
- (void)disposeOnCompletionDisposableHandle:(id<Sdk_coreKotlinx_coroutines_coreDisposableHandle>)disposableHandle __attribute__((swift_name("disposeOnCompletion(disposableHandle:)")));
- (void)selectInRegistrationPhaseInternalResult:(id _Nullable)internalResult __attribute__((swift_name("selectInRegistrationPhase(internalResult:)")));
- (BOOL)trySelectClauseObject:(id)clauseObject result:(id _Nullable)result __attribute__((swift_name("trySelect(clauseObject:result:)")));
@property (readonly) id<Sdk_coreKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol Sdk_coreKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<Sdk_coreKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<Sdk_coreKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<Sdk_coreKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) Sdk_coreKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol Sdk_coreKotlinAnnotation
@required
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface Sdk_coreKotlinx_serialization_coreSerialKind : Sdk_coreBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol Sdk_coreKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<Sdk_coreKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<Sdk_coreKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<Sdk_coreKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) Sdk_coreKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioMemory.Companion")))
@interface Sdk_coreKtor_ioMemoryCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_ioMemoryCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKtor_ioMemory *Empty __attribute__((swift_name("Empty")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioBuffer.Companion")))
@interface Sdk_coreKtor_ioBufferCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_ioBufferCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKtor_ioBuffer *Empty __attribute__((swift_name("Empty")));
@property (readonly) int32_t ReservedSize __attribute__((swift_name("ReservedSize")));
@end

__attribute__((swift_name("Ktor_ioObjectPool")))
@protocol Sdk_coreKtor_ioObjectPool <Sdk_coreKtor_ioCloseable>
@required
- (id)borrow __attribute__((swift_name("borrow()")));
- (void)dispose __attribute__((swift_name("dispose()")));
- (void)recycleInstance:(id)instance __attribute__((swift_name("recycle(instance:)")));
@property (readonly) int32_t capacity __attribute__((swift_name("capacity")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioChunkBuffer.Companion")))
@interface Sdk_coreKtor_ioChunkBufferCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_ioChunkBufferCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKtor_ioChunkBuffer *Empty __attribute__((swift_name("Empty")));
@property (readonly) id<Sdk_coreKtor_ioObjectPool> EmptyPool __attribute__((swift_name("EmptyPool")));
@property (readonly) id<Sdk_coreKtor_ioObjectPool> Pool __attribute__((swift_name("Pool")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioInput.Companion")))
@interface Sdk_coreKtor_ioInputCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_ioInputCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioByteReadPacket.Companion")))
@interface Sdk_coreKtor_ioByteReadPacketCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_ioByteReadPacketCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKtor_ioByteReadPacket *Empty __attribute__((swift_name("Empty")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol Sdk_coreKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<Sdk_coreKotlinKClass>)kClass provider:(id<Sdk_coreKotlinx_serialization_coreKSerializer> (^)(NSArray<id<Sdk_coreKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));
- (void)contextualKClass:(id<Sdk_coreKotlinKClass>)kClass serializer:(id<Sdk_coreKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<Sdk_coreKotlinKClass>)baseClass actualClass:(id<Sdk_coreKotlinKClass>)actualClass actualSerializer:(id<Sdk_coreKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<Sdk_coreKotlinKClass>)baseClass defaultDeserializerProvider:(id<Sdk_coreKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)"))) __attribute__((deprecated("Deprecated in favor of function with more precise name: polymorphicDefaultDeserializer")));
- (void)polymorphicDefaultDeserializerBaseClass:(id<Sdk_coreKotlinKClass>)baseClass defaultDeserializerProvider:(id<Sdk_coreKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));
- (void)polymorphicDefaultSerializerBaseClass:(id<Sdk_coreKotlinKClass>)baseClass defaultSerializerProvider:(id<Sdk_coreKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement.Companion")))
@interface Sdk_coreKotlinx_serialization_jsonJsonElementCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinx_serialization_jsonJsonElementCompanion *shared __attribute__((swift_name("shared")));
- (id<Sdk_coreKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonClassDiscriminatorMode")))
@interface Sdk_coreKotlinx_serialization_jsonClassDiscriminatorMode : Sdk_coreKotlinEnum<Sdk_coreKotlinx_serialization_jsonClassDiscriminatorMode *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreKotlinx_serialization_jsonClassDiscriminatorMode *none __attribute__((swift_name("none")));
@property (class, readonly) Sdk_coreKotlinx_serialization_jsonClassDiscriminatorMode *allJsonObjects __attribute__((swift_name("allJsonObjects")));
@property (class, readonly) Sdk_coreKotlinx_serialization_jsonClassDiscriminatorMode *polymorphic __attribute__((swift_name("polymorphic")));
+ (Sdk_coreKotlinArray<Sdk_coreKotlinx_serialization_jsonClassDiscriminatorMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreKotlinx_serialization_jsonClassDiscriminatorMode *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonNamingStrategy")))
@protocol Sdk_coreKotlinx_serialization_jsonJsonNamingStrategy
@required
- (NSString *)serialNameForJsonDescriptor:(id<Sdk_coreKotlinx_serialization_coreSerialDescriptor>)descriptor elementIndex:(int32_t)elementIndex serialName:(NSString *)serialName __attribute__((swift_name("serialNameForJson(descriptor:elementIndex:serialName:)")));
@end

__attribute__((swift_name("KotlinCharIterator")))
@interface Sdk_coreKotlinCharIterator : Sdk_coreBase <Sdk_coreKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id)next __attribute__((swift_name("next()")));
- (unichar)nextChar __attribute__((swift_name("nextChar()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinMatchResultDestructured")))
@interface Sdk_coreKotlinMatchResultDestructured : Sdk_coreBase
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (NSString *)component10 __attribute__((swift_name("component10()")));
- (NSString *)component2 __attribute__((swift_name("component2()")));
- (NSString *)component3 __attribute__((swift_name("component3()")));
- (NSString *)component4 __attribute__((swift_name("component4()")));
- (NSString *)component5 __attribute__((swift_name("component5()")));
- (NSString *)component6 __attribute__((swift_name("component6()")));
- (NSString *)component7 __attribute__((swift_name("component7()")));
- (NSString *)component8 __attribute__((swift_name("component8()")));
- (NSString *)component9 __attribute__((swift_name("component9()")));
- (NSArray<NSString *> *)toList __attribute__((swift_name("toList()")));
@property (readonly) id<Sdk_coreKotlinMatchResult> match __attribute__((swift_name("match")));
@end

__attribute__((swift_name("KotlinIterable")))
@protocol Sdk_coreKotlinIterable
@required
- (id<Sdk_coreKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((swift_name("KotlinCollection")))
@protocol Sdk_coreKotlinCollection <Sdk_coreKotlinIterable>
@required
- (BOOL)containsElement:(id _Nullable)element __attribute__((swift_name("contains(element:)")));
- (BOOL)containsAllElements:(id)elements __attribute__((swift_name("containsAll(elements:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
@property (readonly, getter=size_) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("KotlinMatchGroupCollection")))
@protocol Sdk_coreKotlinMatchGroupCollection <Sdk_coreKotlinCollection>
@required
- (Sdk_coreKotlinMatchGroup * _Nullable)getIndex_:(int32_t)index __attribute__((swift_name("get(index_:)")));
@end

__attribute__((swift_name("KotlinIntProgression")))
@interface Sdk_coreKotlinIntProgression : Sdk_coreBase <Sdk_coreKotlinIterable>
@property (class, readonly, getter=companion) Sdk_coreKotlinIntProgressionCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (Sdk_coreKotlinIntIterator *)iterator __attribute__((swift_name("iterator()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t first __attribute__((swift_name("first")));
@property (readonly) int32_t last __attribute__((swift_name("last")));
@property (readonly) int32_t step __attribute__((swift_name("step")));
@end

__attribute__((swift_name("KotlinClosedRange")))
@protocol Sdk_coreKotlinClosedRange
@required
- (BOOL)containsValue:(id)value __attribute__((swift_name("contains(value:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
@property (readonly) id endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly, getter=start_) id start __attribute__((swift_name("start")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
__attribute__((swift_name("KotlinOpenEndRange")))
@protocol Sdk_coreKotlinOpenEndRange
@required
- (BOOL)containsValue_:(id)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
@property (readonly) id endExclusive __attribute__((swift_name("endExclusive")));
@property (readonly, getter=start_) id start __attribute__((swift_name("start")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntRange")))
@interface Sdk_coreKotlinIntRange : Sdk_coreKotlinIntProgression <Sdk_coreKotlinClosedRange, Sdk_coreKotlinOpenEndRange>
- (instancetype)initWithStart:(int32_t)start endInclusive:(int32_t)endInclusive __attribute__((swift_name("init(start:endInclusive:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKotlinIntRangeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsValue:(Sdk_coreInt *)value __attribute__((swift_name("contains(value:)")));
- (BOOL)containsValue_:(Sdk_coreInt *)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
@property (readonly) Sdk_coreInt *endExclusive __attribute__((swift_name("endExclusive"))) __attribute__((deprecated("Can throw an exception when it's impossible to represent the value with Int type, for example, when the range includes MAX_VALUE. It's recommended to use 'endInclusive' property that doesn't throw.")));
@property (readonly) Sdk_coreInt *endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly, getter=start_) Sdk_coreInt *start __attribute__((swift_name("start")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpClientCall.Companion")))
@interface Sdk_coreKtor_client_coreHttpClientCallCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_client_coreHttpClientCallCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKtor_utilsAttributeKey<id> *CustomResponse __attribute__((swift_name("CustomResponse"))) __attribute__((unavailable("This is going to be removed. Please file a ticket with clarification why and what for do you need it.")));
@end

__attribute__((swift_name("Ktor_client_coreHttpRequest")))
@protocol Sdk_coreKtor_client_coreHttpRequest <Sdk_coreKtor_httpHttpMessage, Sdk_coreKotlinx_coroutines_coreCoroutineScope>
@required
@property (readonly) id<Sdk_coreKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) Sdk_coreKtor_client_coreHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) Sdk_coreKtor_httpOutgoingContent *content __attribute__((swift_name("content")));
@property (readonly) Sdk_coreKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) Sdk_coreKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsGMTDate.Companion")))
@interface Sdk_coreKtor_utilsGMTDateCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_utilsGMTDateCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKtor_utilsGMTDate *START __attribute__((swift_name("START")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsWeekDay")))
@interface Sdk_coreKtor_utilsWeekDay : Sdk_coreKotlinEnum<Sdk_coreKtor_utilsWeekDay *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKtor_utilsWeekDayCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreKtor_utilsWeekDay *monday __attribute__((swift_name("monday")));
@property (class, readonly) Sdk_coreKtor_utilsWeekDay *tuesday __attribute__((swift_name("tuesday")));
@property (class, readonly) Sdk_coreKtor_utilsWeekDay *wednesday __attribute__((swift_name("wednesday")));
@property (class, readonly) Sdk_coreKtor_utilsWeekDay *thursday __attribute__((swift_name("thursday")));
@property (class, readonly) Sdk_coreKtor_utilsWeekDay *friday __attribute__((swift_name("friday")));
@property (class, readonly) Sdk_coreKtor_utilsWeekDay *saturday __attribute__((swift_name("saturday")));
@property (class, readonly) Sdk_coreKtor_utilsWeekDay *sunday __attribute__((swift_name("sunday")));
+ (Sdk_coreKotlinArray<Sdk_coreKtor_utilsWeekDay *> *)values __attribute__((swift_name("values()")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsMonth")))
@interface Sdk_coreKtor_utilsMonth : Sdk_coreKotlinEnum<Sdk_coreKtor_utilsMonth *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKtor_utilsMonthCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *january __attribute__((swift_name("january")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *february __attribute__((swift_name("february")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *march __attribute__((swift_name("march")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *april __attribute__((swift_name("april")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *may __attribute__((swift_name("may")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *june __attribute__((swift_name("june")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *july __attribute__((swift_name("july")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *august __attribute__((swift_name("august")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *september __attribute__((swift_name("september")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *october __attribute__((swift_name("october")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *november __attribute__((swift_name("november")));
@property (class, readonly) Sdk_coreKtor_utilsMonth *december __attribute__((swift_name("december")));
+ (Sdk_coreKotlinArray<Sdk_coreKtor_utilsMonth *> *)values __attribute__((swift_name("values()")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpProtocolVersion.Companion")))
@interface Sdk_coreKtor_httpHttpProtocolVersionCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_httpHttpProtocolVersionCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreKtor_httpHttpProtocolVersion *)fromValueName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("fromValue(name:major:minor:)")));
- (Sdk_coreKtor_httpHttpProtocolVersion *)parseValue:(id)value __attribute__((swift_name("parse(value:)")));
@property (readonly) Sdk_coreKtor_httpHttpProtocolVersion *HTTP_1_0 __attribute__((swift_name("HTTP_1_0")));
@property (readonly) Sdk_coreKtor_httpHttpProtocolVersion *HTTP_1_1 __attribute__((swift_name("HTTP_1_1")));
@property (readonly) Sdk_coreKtor_httpHttpProtocolVersion *HTTP_2_0 __attribute__((swift_name("HTTP_2_0")));
@property (readonly) Sdk_coreKtor_httpHttpProtocolVersion *QUIC __attribute__((swift_name("QUIC")));
@property (readonly) Sdk_coreKtor_httpHttpProtocolVersion *SPDY_3 __attribute__((swift_name("SPDY_3")));
@end

__attribute__((swift_name("Ktor_httpHeaderValueWithParameters")))
@interface Sdk_coreKtor_httpHeaderValueWithParameters : Sdk_coreBase
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<Sdk_coreKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKtor_httpHeaderValueWithParametersCompanion *companion __attribute__((swift_name("companion")));
- (NSString * _Nullable)parameterName:(NSString *)name __attribute__((swift_name("parameter(name:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) NSString *content __attribute__((swift_name("content")));
@property (readonly) NSArray<Sdk_coreKtor_httpHeaderValueParam *> *parameters __attribute__((swift_name("parameters")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentType")))
@interface Sdk_coreKtor_httpContentType : Sdk_coreKtor_httpHeaderValueWithParameters
- (instancetype)initWithContentType:(NSString *)contentType contentSubtype:(NSString *)contentSubtype parameters:(NSArray<Sdk_coreKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(contentType:contentSubtype:parameters:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<Sdk_coreKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) Sdk_coreKtor_httpContentTypeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)matchPattern:(Sdk_coreKtor_httpContentType *)pattern __attribute__((swift_name("match(pattern:)")));
- (BOOL)matchPattern_:(NSString *)pattern __attribute__((swift_name("match(pattern_:)")));
- (Sdk_coreKtor_httpContentType *)withParameterName:(NSString *)name value:(NSString *)value __attribute__((swift_name("withParameter(name:value:)")));
- (Sdk_coreKtor_httpContentType *)withoutParameters __attribute__((swift_name("withoutParameters()")));
@property (readonly) NSString *contentSubtype __attribute__((swift_name("contentSubtype")));
@property (readonly) NSString *contentType __attribute__((swift_name("contentType")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection")))
@interface Sdk_coreKotlinKTypeProjection : Sdk_coreBase
- (instancetype)initWithVariance:(Sdk_coreKotlinKVariance * _Nullable)variance type:(id<Sdk_coreKotlinKType> _Nullable)type __attribute__((swift_name("init(variance:type:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Sdk_coreKotlinKTypeProjectionCompanion *companion __attribute__((swift_name("companion")));
- (Sdk_coreKotlinKTypeProjection *)doCopyVariance:(Sdk_coreKotlinKVariance * _Nullable)variance type:(id<Sdk_coreKotlinKType> _Nullable)type __attribute__((swift_name("doCopy(variance:type:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<Sdk_coreKotlinKType> _Nullable type __attribute__((swift_name("type")));
@property (readonly) Sdk_coreKotlinKVariance * _Nullable variance __attribute__((swift_name("variance")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinMatchGroup")))
@interface Sdk_coreKotlinMatchGroup : Sdk_coreBase
- (instancetype)initWithValue:(NSString *)value range:(Sdk_coreKotlinIntRange *)range __attribute__((swift_name("init(value:range:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreKotlinMatchGroup *)doCopyValue:(NSString *)value range:(Sdk_coreKotlinIntRange *)range __attribute__((swift_name("doCopy(value:range:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Sdk_coreKotlinIntRange *range __attribute__((swift_name("range")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntProgression.Companion")))
@interface Sdk_coreKotlinIntProgressionCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinIntProgressionCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreKotlinIntProgression *)fromClosedRangeRangeStart:(int32_t)rangeStart rangeEnd:(int32_t)rangeEnd step:(int32_t)step __attribute__((swift_name("fromClosedRange(rangeStart:rangeEnd:step:)")));
@end

__attribute__((swift_name("KotlinIntIterator")))
@interface Sdk_coreKotlinIntIterator : Sdk_coreBase <Sdk_coreKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Sdk_coreInt *)next __attribute__((swift_name("next()")));
- (int32_t)nextInt __attribute__((swift_name("nextInt()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntRange.Companion")))
@interface Sdk_coreKotlinIntRangeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinIntRangeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) Sdk_coreKotlinIntRange *EMPTY __attribute__((swift_name("EMPTY")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsWeekDay.Companion")))
@interface Sdk_coreKtor_utilsWeekDayCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_utilsWeekDayCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreKtor_utilsWeekDay *)fromOrdinal:(int32_t)ordinal __attribute__((swift_name("from(ordinal:)")));
- (Sdk_coreKtor_utilsWeekDay *)fromValue:(NSString *)value __attribute__((swift_name("from(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsMonth.Companion")))
@interface Sdk_coreKtor_utilsMonthCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_utilsMonthCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreKtor_utilsMonth *)fromOrdinal:(int32_t)ordinal __attribute__((swift_name("from(ordinal:)")));
- (Sdk_coreKtor_utilsMonth *)fromValue:(NSString *)value __attribute__((swift_name("from(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeaderValueParam")))
@interface Sdk_coreKtor_httpHeaderValueParam : Sdk_coreBase
- (instancetype)initWithName:(NSString *)name value:(NSString *)value __attribute__((swift_name("init(name:value:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithName:(NSString *)name value:(NSString *)value escapeValue:(BOOL)escapeValue __attribute__((swift_name("init(name:value:escapeValue:)"))) __attribute__((objc_designated_initializer));
- (Sdk_coreKtor_httpHeaderValueParam *)doCopyName:(NSString *)name value:(NSString *)value escapeValue:(BOOL)escapeValue __attribute__((swift_name("doCopy(name:value:escapeValue:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL escapeValue __attribute__((swift_name("escapeValue")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeaderValueWithParameters.Companion")))
@interface Sdk_coreKtor_httpHeaderValueWithParametersCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_httpHeaderValueWithParametersCompanion *shared __attribute__((swift_name("shared")));
- (id _Nullable)parseValue:(NSString *)value init:(id _Nullable (^)(NSString *, NSArray<Sdk_coreKtor_httpHeaderValueParam *> *))init __attribute__((swift_name("parse(value:init:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentType.Companion")))
@interface Sdk_coreKtor_httpContentTypeCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKtor_httpContentTypeCompanion *shared __attribute__((swift_name("shared")));
- (Sdk_coreKtor_httpContentType *)parseValue:(NSString *)value __attribute__((swift_name("parse(value:)")));
@property (readonly) Sdk_coreKtor_httpContentType *Any __attribute__((swift_name("Any")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKVariance")))
@interface Sdk_coreKotlinKVariance : Sdk_coreKotlinEnum<Sdk_coreKotlinKVariance *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Sdk_coreKotlinKVariance *invariant __attribute__((swift_name("invariant")));
@property (class, readonly) Sdk_coreKotlinKVariance *in __attribute__((swift_name("in")));
@property (class, readonly) Sdk_coreKotlinKVariance *out __attribute__((swift_name("out")));
+ (Sdk_coreKotlinArray<Sdk_coreKotlinKVariance *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Sdk_coreKotlinKVariance *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection.Companion")))
@interface Sdk_coreKotlinKTypeProjectionCompanion : Sdk_coreBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Sdk_coreKotlinKTypeProjectionCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (Sdk_coreKotlinKTypeProjection *)contravariantType:(id<Sdk_coreKotlinKType>)type __attribute__((swift_name("contravariant(type:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (Sdk_coreKotlinKTypeProjection *)covariantType:(id<Sdk_coreKotlinKType>)type __attribute__((swift_name("covariant(type:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (Sdk_coreKotlinKTypeProjection *)invariantType:(id<Sdk_coreKotlinKType>)type __attribute__((swift_name("invariant(type:)")));
@property (readonly) Sdk_coreKotlinKTypeProjection *STAR __attribute__((swift_name("STAR")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
