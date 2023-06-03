# Uniplex_LE
Uniplex_LE
#Introduction
Welcome to Uniplex_LE, the Lightweight version of the Uniplex system. This repository focuses on achieving an extremely low power consumption for efficient energy usage. We have applied power-saving principles to both hardware and firmware components to ensure optimal performance while minimizing power consumption.

#Features
The Uniplex_LE system incorporates the following key features to achieve low power consumption:

Hardware Power Optimization: We have implemented hardware optimizations to ensure minimal power usage in the system.
Firmware Low Power Modes: The firmware utilizes low power modes and interrupt controls to achieve deep power savings.
Interrupts: The system supports various interrupts, including RTC, USB, Display, and Button.

#Interrupts Explanation
Here's a breakdown of how each interrupt is handled:

RTC Interrupt: When triggered by the Real-Time Clock (RTC), the device wakes up to read and store a measurement value. The data is then saved in a log file, which can be accessed via USB or NFC for further analysis.
USB Interrupt: Upon a USB interrupt, the device is ready to communicate with external systems. It responds to commands promptly and returns to sleep mode to conserve power.
Display Interrupt: When a display interrupt occurs, the device is awakened from sleep mode, and the display is turned on. After 10 seconds of inactivity, the display automatically turns off to save power.
Button Interrupt: Similar to the display interrupt, a button interrupt wakes up the device, turns on the display, and follows the same power-saving behavior after a period of inactivity.
Power Consumption Goals
Our primary goal is to achieve an average power consumption of a maximum of 1mA, considering the fastest interval of 10 seconds and the slowest interval of 24 hours.

#How to Contribute
We welcome contributions from the community to enhance the Uniplex_LE system. To contribute, please follow these steps:

Fork this repository and clone it to your local machine.
Implement your modifications or optimizations in the codebase.
Ensure that your code adheres to best practices and includes appropriate documentation.
Submit a pull request detailing the changes you made.

#Support and Feedback
If you have any questions, feedback, or require assistance, please don't hesitate to reach out to us. You can contact the maintainers at [maintainer@email.com].

We appreciate your interest in Uniplex_LE and look forward to your contributions. Together, let's make a significant impact in achieving optimal power consumption!

Happy coding!

The Uniplex_LE Team