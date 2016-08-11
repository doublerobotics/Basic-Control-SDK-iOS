//
//  DRDouble.h
//  Double Basic Example
//
//  Created by David Cann on 8/3/13.
//  Copyright (c) 2013 Double Robotics, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kDoubleBasicSDKVersion @"0.7"

typedef NS_ENUM(NSInteger, DRDriveDirection) {
	kDRDriveDirectionStop = 0,
	kDRDriveDirectionForward = 1,
	kDRDriveDirectionBackward = 2
};

@class DRDouble;

@protocol DRDoubleDelegate <NSObject>
@optional
- (void)doubleDidConnect:(DRDouble *)theDouble;
- (void)doubleDidDisconnect:(DRDouble *)theDouble;
- (void)doubleStatusDidUpdate:(DRDouble *)theDouble;
- (void)doubleDriveShouldUpdate:(DRDouble *)theDouble;
- (void)doubleTravelDataDidUpdate:(DRDouble *)theDouble;
@end

@interface DRDouble : NSObject {

}

@property (nonatomic, assign) id <DRDoubleDelegate> delegate;
@property (nonatomic, readonly) float poleHeightPercent;
@property (nonatomic, readonly) int kickstandState;
@property (nonatomic, readonly) float batteryPercent;
@property (nonatomic, readonly) BOOL batteryIsFullyCharged;
@property (nonatomic, readonly) NSString *firmwareVersion;
@property (nonatomic, readonly) float leftEncoderDeltaInches;
@property (nonatomic, readonly) float rightEncoderDeltaInches;
@property (nonatomic, readonly) float xDeltaInches;
@property (nonatomic, readonly) float yDeltaInches;
@property (nonatomic, readonly) float headingDeltaRadians;
@property (nonatomic, readonly) NSString *serial;

#pragma mark - Singleton
+ (DRDouble *)sharedDouble;

#pragma mark - Controls
- (void)drive:(DRDriveDirection)forwardBack turn:(float)leftRight; // leftRight is -1.0 to 1.0
- (void)variableDrive:(float)forwardBack turn:(float)leftRight; // drive is -1.0 to 1.0, leftRight is -1.0 to 1.0 (0.0 is stop on both)
- (void)turnByDegrees:(float)theDegrees;
- (void)poleUp;
- (void)poleDown;
- (void)poleStop;
- (void)deployKickstands;
- (void)retractKickstands;
- (void)startTravelData;
- (void)stopTravelData;
- (void)requestStatusUpdate;

@end
