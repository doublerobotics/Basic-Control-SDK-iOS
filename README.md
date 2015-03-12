Basic Control SDK iOS
=====================

This SDK provides access to basic driving controls from a custom iOS application.

1. Add DoubleControlSDK.framework to your app
2. Add an entry in Info.plist for "Supported external accessory protocols" > Item 0 = com.doublerobotics.pancho
3. #import &lt;DoubleControlSDK/DoubleControlSDK.h&gt;
4. Add &lt;DRDoubleDelegate&gt;
5. [DRDouble sharedDouble].delegate = self;

DRDouble
========
```
@property (nonatomic, assign) id <DRDoubleDelegate> delegate;
@property (nonatomic, readonly) float poleHeightPercent;
@property (nonatomic, readonly) int kickstandState;
@property (nonatomic, readonly) float batteryPercent;
@property (nonatomic, readonly) BOOL batteryIsFullyCharged;
@property (nonatomic, readonly) NSString *firmwareVersion;
@property (nonatomic, readonly) float leftEncoderDeltaInches;
@property (nonatomic, readonly) float rightEncoderDeltaInches;
@property (nonatomic, readonly) NSString *serial;

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
```

DRDoubleDelegate
================
```
- (void)doubleDidConnect:(DRDouble *)theDouble;
- (void)doubleDidDisconnect:(DRDouble *)theDouble;
- (void)doubleStatusDidUpdate:(DRDouble *)theDouble;
- (void)doubleDriveShouldUpdate:(DRDouble *)theDouble;
- (void)doubleTravelDataDidUpdate:(DRDouble *)theDouble;
```

Example Usage (See DRViewController)
====================================
```
- (void)viewDidLoad {
	[super viewDidLoad];
	[DRDouble sharedDouble].delegate = self;
	NSLog(@"SDK Version: %@", kDoubleBasicSDKVersion);
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {
	return UIInterfaceOrientationIsPortrait(toInterfaceOrientation);
}

#pragma mark - Actions

- (IBAction)poleUp:(id)sender {
	[[DRDouble sharedDouble] poleUp];
}

- (IBAction)poleStop:(id)sender {
	[[DRDouble sharedDouble] poleStop];
}

- (IBAction)poleDown:(id)sender {
	[[DRDouble sharedDouble] poleDown];
}

- (IBAction)kickstandsRetract:(id)sender {
	[[DRDouble sharedDouble] retractKickstands];
}

- (IBAction)kickstandsDeploy:(id)sender {
	[[DRDouble sharedDouble] deployKickstands];
}

- (IBAction)startTravelData:(id)sender {
	[[DRDouble sharedDouble] startTravelData];
}

- (IBAction)stopTravelData:(id)sender {
	[[DRDouble sharedDouble] stopTravelData];
}

#pragma mark - DRDoubleDelegate

- (void)doubleDidConnect:(DRDouble *)theDouble {
	statusLabel.text = @"Connected";
}

- (void)doubleDidDisconnect:(DRDouble *)theDouble {
	statusLabel.text = @"Not Connected";
}

- (void)doubleStatusDidUpdate:(DRDouble *)theDouble {
	poleHeightPercentLabel.text = [NSString stringWithFormat:@"%f", [DRDouble sharedDouble].poleHeightPercent];
	kickstandStateLabel.text = [NSString stringWithFormat:@"%d", [DRDouble sharedDouble].kickstandState];
	batteryPercentLabel.text = [NSString stringWithFormat:@"%f", [DRDouble sharedDouble].batteryPercent];
	batteryIsFullyChargedLabel.text = [NSString stringWithFormat:@"%d", [DRDouble sharedDouble].batteryIsFullyCharged];
	firmwareVersionLabel.text = [DRDouble sharedDouble].firmwareVersion;
}

- (void)doubleDriveShouldUpdate:(DRDouble *)theDouble {
	float drive = (driveForwardButton.highlighted) ? kDRDriveDirectionForward : ((driveBackwardButton.highlighted) ? kDRDriveDirectionBackward : kDRDriveDirectionStop);
	float turn = (driveRightButton.highlighted) ? 1.0 : ((driveLeftButton.highlighted) ? -1.0 : 0.0);
	[theDouble drive:drive turn:turn];
}

- (void)doubleTravelDataDidUpdate:(DRDouble *)theDouble {
	leftEncoderLabel.text = [NSString stringWithFormat:@"%.02f", [leftEncoderLabel.text floatValue] + [DRDouble sharedDouble].leftEncoderDeltaInches];
	rightEncoderLabel.text = [NSString stringWithFormat:@"%.02f", [rightEncoderLabel.text floatValue] + [DRDouble sharedDouble].rightEncoderDeltaInches];
	NSLog(@"Left Encoder: %f, Right Encoder: %f", theDouble.leftEncoderDeltaInches, theDouble.rightEncoderDeltaInches);
}
```

Note
====
The SDK is experimental. If you have any questions about the SDK or its usage, please contact us: info@doublerobotics.com
