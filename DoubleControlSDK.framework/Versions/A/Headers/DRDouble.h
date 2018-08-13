//  DRDouble.h
//  Double Basic Example
//
//  Created by David Cann on 8/3/13.
//  Copyright (c) 2013 Double Robotics, Inc. All rights reserved.
//

import Foundation

let kDoubleBasicSDKVersion = "0.8.1"
enum DRDriveDirection : Int {
    case kDRDriveDirectionStop = 0
    case kDRDriveDirectionForward = 1
    case kDRDriveDirectionBackward = 2
}


protocol DRDoubleDelegate: NSObjectProtocol {
    func doubleDidConnect(_ theDouble: DRDouble?)

    func doubleDidDisconnect(_ theDouble: DRDouble?)

    func doubleStatusDidUpdate(_ theDouble: DRDouble?)

    func doubleDriveShouldUpdate(_ theDouble: DRDouble?)

    func doubleTravelDataDidUpdate(_ theDouble: DRDouble?)
}

class DRDouble: NSObject {
    weak var delegate: DRDoubleDelegate?
    private(set) var poleHeightPercent: Float = 0.0
    private(set) var kickstandState: Int = 0
    private(set) var batteryPercent: Float = 0.0
    private(set) var batteryIsFullyCharged = false
    private(set) var firmwareVersion = ""
    private(set) var leftEncoderDeltaInches: Float = 0.0
    private(set) var rightEncoderDeltaInches: Float = 0.0
    private(set) var xDeltaInches: Float = 0.0
    private(set) var yDeltaInches: Float = 0.0
    private(set) var headingDeltaRadians: Float = 0.0
    private(set) var serial = ""

// MARK: - Singleton
    class func shared() -> DRDouble? {
    }

// MARK: - Controls
    func drive(_ forwardBack: DRDriveDirection, turn leftRight: Float) {
    }

    // leftRight is -1.0 to 1.0
    func variableDrive(_ forwardBack: Float, turn leftRight: Float) {
    }

    // drive is -1.0 to 1.0, leftRight is -1.0 to 1.0 (0.0 is stop on both)
    func turn(byDegrees theDegrees: Float) {
    }

    func poleUp() {
    }

    func poleDown() {
    }

    func poleStop() {
    }

    func deployKickstands() {
    }

    func retractKickstands() {
    }

    func startTravelData() {
    }

    func stopTravelData() {
    }

    func requestStatusUpdate() {
    }

    func headPowerOn() {
    }

    func headPowerOff() {
    }
}
