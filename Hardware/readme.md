# Comprehensive Biometric Student Attendance System - Hardware
This folder contains the hardware design and implementation details for the Comprehensive Biometric Student Attendance System. The system uses biometric authentication to record attendance efficiently and accurately, eliminating the need for traditional roll-call methods.

## Hardware Overview
The hardware component of the system consists of the following primary components:

1.  **R307 Fingerprint Sensor:**
- Used to capture and verify fingerprints.
- Fingerprint templates storage.
- High accuracy and reliability.
- Arduino Uno

2.  **Microcontroller for interfacing and control:**
- 14 digital I/O pins (6 PWM outputs).
- Supports serial communication with the fingerprint sensor.

3.  **Button Switches:**
- Used for navigation and additional operations such as adding and removing students.
- Additional Components

4.  **Breadboard:**
-For circuit prototyping.

5.  **Jumper Wires:**
- For connections.

6.  **LEDs:**
- For status indicators.

7.  **Resistors:**
- For circuit stability.

## Features
- **Add Student:** Enroll new students into the system by storing their fingerprint data in Arduino memory.
- **Remove Student:** Delete existing student records from memory.
- **Mark Attendance:** Detect fingerprints, match them with stored records, and update attendance.
- **Navigation:** Use button switches for up/down and other navigation functions.
- **Database Integration:** Upload fingerprint data and attendance records to a central database for real-time tracking and management.

## Setup Instructions
- **Components Wiring:** Do as in the circuit diagram.
- Fingerprint Sensor:
-- Connect the TX and RX pins of the R307 fingerprint sensor to the Arduino’s RX and TX pins, respectively.
-- Use a 5V pin for power and GND for grounding.

- Button Switches:
-- Connect one terminal of each switch to a digital I/O pin on the Arduino.
-- Use pull-down resistors to stabilize the input.

- LED Indicators:
-- Connect LEDs to digital pins through resistors (220Ω) for visual feedback.

## Code Upload
- Install the required libraries for Arduino.
- Select the correct port and board (Arduino Uno) from the Tools menu.
- Upload the code to the Arduino.

## Components Required
- **R307 Fingerprint Sensor:**	1	Biometric sensor for fingerprint scanning.
- **Arduino Uno:**	1	Microcontroller for interfacing.
- **Button Switches:**	3-4	For up, down, add, and remove navigation.
- **LEDs:**	2-3	Status indicators for different operations.
- **Resistors:** 220Ω,	3-4	Current limiting for LEDs.
- **Jumper Wires:**	As required	For connections between components.
- **Breadboard:**	1	Prototyping board for connections.
- **Power Supply:**	1	USB or external power for the Arduino.

## Usage
- Power on the device.
- Follow the navigation buttons to enroll or remove students.
- Place a registered fingerprint on the scanner to mark attendance.
- Check the Arduino serial monitor or linked database for attendance logs.
