// Generated by Apple Swift version 2.1.1 (swiftlang-700.1.101.15 clang-700.1.81)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Accelerate;
@import CoreGraphics;
#endif

#import <AudioKit/AudioKit.h>

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class EZAudioFFT;


/// FFT Calculation for any node
SWIFT_CLASS("_TtC8AudioKit5AKFFT")
@interface AKFFT : NSObject <EZAudioFFTDelegate>

/// Array of FFT data
@property (nonatomic, copy) NSArray<NSNumber *> * __nonnull fftData;

/// Callback function for FFT computation
- (void)fft:(EZAudioFFT * __null_unspecified)fft updatedWithFFTData:(float * __null_unspecified)fftData bufferSize:(vDSP_Length)bufferSize;
@end

@class EZAudioPlot;
@class UIView;


/// Plot the FFT output from any node in an signal processing graph
SWIFT_CLASS("_TtC8AudioKit13AKNodeFFTPlot")
@interface AKNodeFFTPlot : NSObject <EZAudioFFTDelegate>

/// EZAudioPlot containing actual plot
@property (nonatomic, strong) EZAudioPlot * __nullable plot;

/// View with the plot
@property (nonatomic, strong) UIView * __nullable containerView;

/// Callback function for FFT data:
///
/// \param fft EZAudioFFT Reference
///
/// \param updatedWithFFTData A pointer to a c-style array of floats
///
/// \param bufferSize Number of elements in the FFT Data array
- (void)fft:(EZAudioFFT * __null_unspecified)fft updatedWithFFTData:(float * __null_unspecified)fftData bufferSize:(vDSP_Length)bufferSize;
@end

@class NSCoder;


/// Wrapper class for plotting audio from the final mix in a waveform plot
SWIFT_CLASS("_TtC8AudioKit20AKOutputWaveformPlot")
@interface AKOutputWaveformPlot : EZAudioPlot

/// Initialize the plot in a frame
///
/// \param frame CGRect in which to draw the plot
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;

/// Required coder-based initialization (for use with Interface Builder)
///
/// \param coder NSCoder
- (nullable instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;

/// Create a View with the plot (usually for playgrounds)
///
/// \param width Width of the view
///
/// \param height Height of the view
///
/// \returns  AKView
+ (UIView * __nonnull)createView:(CGFloat)width height:(CGFloat)height;
@end



/// Wrapper class for plotting audio from the final mix in a rolling plot
SWIFT_CLASS("_TtC8AudioKit19AKRollingOutputPlot")
@interface AKRollingOutputPlot : EZAudioPlot

/// Initialize the plot in a frame
///
/// \param frame CGRect in which to draw the plot
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;

/// Required coder-based initialization (for use with Interface Builder)
///
/// \param coder NSCoder
- (nullable instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;

/// Create a View with the plot (usually for playgrounds)
///
/// \param width Width of the view
///
/// \param height Height of the view
///
/// \returns  AKView
+ (UIView * __nonnull)createView:(CGFloat)width height:(CGFloat)height;
@end

#pragma clang diagnostic pop
