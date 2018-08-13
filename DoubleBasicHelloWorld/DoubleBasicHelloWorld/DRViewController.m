//
//  DRViewController.m
//  DoubleBasicHelloWorld
//
//  Created by David Cann on 8/3/13.
//  Copyright (c) 2013 Double Robotics, Inc. All rights reserved.
//

import DoubleControlSDK

class DRViewController: DRDoubleDelegate {
    func viewDidLoad() {
        super.viewDidLoad()
        DRDouble.shared().delegate = self
        print("SDK Version: \(kDoubleBasicSDKVersion)")
    }

    func shouldAutorotate(to toInterfaceOrientation: UIInterfaceOrientation) -> Bool {
        return UIInterfaceOrientationIsPortrait(toInterfaceOrientation)
    }

// MARK: - Actions
    @IBAction func poleUp(_ sender: Any) {
        DRDouble.shared().poleUp()
    }

    @IBAction func poleStop(_ sender: Any) {
        DRDouble.shared().poleStop()
    }

    @IBAction func poleDown(_ sender: Any) {
        DRDouble.shared().poleDown()
    }

    @IBAction func kickstandsRetract(_ sender: Any) {
        DRDouble.shared().retractKickstands()
    }

    @IBAction func kickstandsDeploy(_ sender: Any) {
        DRDouble.shared().deployKickstands()
    }

    @IBAction func startTravelData(_ sender: Any) {
        DRDouble.shared().startTravelData()
    }

    @IBAction func stopTravelData(_ sender: Any) {
        DRDouble.shared().stopTravelData()
    }

    @IBAction func headPower(on sender: Any) {
        DRDouble.shared().headPowerOn()
    }

    @IBAction func headPowerOff(_ sender: Any) {
        DRDouble.shared().headPowerOff()
    }

// MARK: - DRDoubleDelegate
    func doubleDidConnect(_ theDouble: DRDouble?) {
        statusLabel.text = "Connected"
    }

    func doubleDidDisconnect(_ theDouble: DRDouble?) {
        statusLabel.text = "Not Connected"
    }

    func doubleStatusDidUpdate(_ theDouble: DRDouble?) {
        poleHeightPercentLabel.text = "\(DRDouble.shared().poleHeightPercent)"
        kickstandStateLabel.text = "\(DRDouble.shared().kickstandState)"
        batteryPercentLabel.text = "\(DRDouble.shared().batteryPercent)"
        batteryIsFullyChargedLabel.text = "\(DRDouble.shared().batteryIsFullyCharged)"
		func doubleDriveShouldUpdate(_ theDouble: DRDouble?) {
        let drive = (driveForwardButton.highlighted) ? kDRDriveDirectionForward : ((driveBackwardButton.highlighted) ? kDRDriveDirectionBackward : kDRDriveDirectionStop)
        let turn: Float = (driveRightButton.highlighted) ? 1.0 : ((driveLeftButton.highlighted) ? -1.0 : 0.0)
        theDouble?.drive(drive, turn: turn)
    }

    func doubleTravelDataDidUpdate(_ theDouble: DRDouble?) {
        leftEncoderLabel.text = String(format: "%.02f", leftEncoderLabel.text + DRDouble.shared().leftEncoderDeltaInches)
        rightEncoderLabel.text = String(format: "%.02f", rightEncoderLabel.text + DRDouble.shared().rightEncoderDeltaInches)
        if let anInches = theDouble?.leftEncoderDeltaInches, let anInches1 = theDouble?.rightEncoderDeltaInches {
            print("Left Encoder: \(anInches), Right Encoder: \(anInches1)")
        }
    }
}
