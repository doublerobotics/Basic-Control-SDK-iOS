//
//  DRViewController.h
//  DoubleBasicHelloWorld
//
//  Created by David Cann on 8/3/13.
//  Copyright (c) 2013 Double Robotics, Inc. All rights reserved.
//

import UIKit

class DRViewController: UIViewController {
    @IBOutlet var statusLabel: UILabel!
    @IBOutlet var poleHeightPercentLabel: UILabel!
    @IBOutlet var kickstandStateLabel: UILabel!
    @IBOutlet var batteryPercentLabel: UILabel!
    @IBOutlet var batteryIsFullyChargedLabel: UILabel!
    @IBOutlet var firmwareVersionLabel: UILabel!
    @IBOutlet var serialLabel: UILabel!
    @IBOutlet var leftEncoderLabel: UILabel!
    @IBOutlet var rightEncoderLabel: UILabel!
    @IBOutlet var driveForwardButton: UIButton!
    @IBOutlet var driveBackwardButton: UIButton!
    @IBOutlet var driveLeftButton: UIButton!
    @IBOutlet var driveRightButton: UIButton!
