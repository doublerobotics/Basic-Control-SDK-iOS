//
//  DRViewController.h
//  DoubleBasicHelloWorld
//
//  Created by David Cann on 8/3/13.
//  Copyright (c) 2013 Double Robotics, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DRViewController : UIViewController {
	IBOutlet UILabel *statusLabel;
	IBOutlet UILabel *poleHeightPercentLabel;
	IBOutlet UILabel *kickstandStateLabel;
	IBOutlet UILabel *batteryPercentLabel;
	IBOutlet UILabel *batteryIsFullyChargedLabel;
	IBOutlet UILabel *firmwareVersionLabel;
	IBOutlet UILabel *serialLabel;
	IBOutlet UILabel *leftEncoderLabel;
	IBOutlet UILabel *rightEncoderLabel;
	IBOutlet UIButton *driveForwardButton;
	IBOutlet UIButton *driveBackwardButton;
	IBOutlet UIButton *driveLeftButton;
	IBOutlet UIButton *driveRightButton;
}

@end
