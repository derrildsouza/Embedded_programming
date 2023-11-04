
##
# Ultra-Sonic UDP terminal feed

# Introduction

Welcome to the "Ultra-Sonic UDP Terminal Feed" project, where we embark on a journey to seamlessly transfer ultrasonic sensor data wirelessly to any Linux terminal via a Wi-Fi network. This cutting-edge solution leverages the power of UDP (User Datagram Protocol) to ensure swift and efficient data streaming. Say farewell to the constraints of wired connections and embrace a new era of flexibility and convenience in acquiring, analyzing, and utilizing ultrasonic data.

# Let's Get to Work!

## Project-setup:

![Project_setup_block_diagram](https://github.com/derrildsouza/basics/assets/64513486/6c6929ae-c45e-454c-a274-5de931580d69)

_Figure 1: Project Setup_

In our project, we establish a seamless connection between our ultrasonic sensor and a Wi-Fi network. This connectivity is facilitated by an ESP-32 microcontroller, renowned for its capability to handle Wi-Fi packets effectively.

Here's how the system works:

### Hardware Setup:

- We connect the HC-SR04 sensor to the ESP-32 microcontroller, creating a robust hardware foundation.
- A dedicated code is crafted to read the ultrasonic data, which is then uploaded onto the microcontroller.

### Data Transmission:

- The microcontroller takes on the pivotal role of not only reading but also formatting and transmitting the sensor data into the WiFi network.
- To ensure efficient data transfer, we employ UDP broadcast on a specified port number. This ensures that the data flows seamlessly within the network.

### Data Reception:

- On the receiving end, whether it's a Linux laptop or an Android phone, a client code is implemented to register itself to the designated port number.
- The client code is responsible for accepting all incoming data, thus establishing a vital link between the sensor and the terminal.

### Data Display:

- In this iteration of the project, our primary objective is to display the received data on the terminal. This foundational step lays the groundwork for further data processing and subsequent actions in future project phases.

# What Do We Need?

##   Hardware

- A Linux laptop or an Android phone with a terminal installed.
- An ESP-32 Microcontroller.
- An HC-SR04 Ultrasonic sensor.
- A couple of DuPont/jumper cables.
- Optional: Power bank, casing, and other accessories.

##   Software

- Arduino IDE
- Gcc/clang or a similar C code compiler for your laptop or phone.


# What Do We Achieve?

This project provides a simple yet effective hardware-software fusion, making it accessible and engaging for beginners interested in the embedded field.

# ![Shape1](RackMultipart20231104-1-q0pu2j_html_dd0215582b2d4580.gif)Skills Needed:

- Software development in C.
- Basic hardware understanding.
- A grasp of network protocols, specifically UDP in this case.
- Time management to complete the project efficiently.

![skill_needed_us](https://github.com/derrildsouza/basics/assets/64513486/cbf525e6-58b1-44cb-b1b1-62d3643c95d2)


# Circuit diagram:

![circuit_diagram_us_udp](https://github.com/derrildsouza/basics/assets/64513486/5c4fa2e4-03d3-4398-aa29-80251eeb316b)

_Figure 2: Circuit diagram_

# Tasks in hand

| **Task** | **Time to be spent (hrs.)** | **Efforts** | **Percentage completion** |
| --- | --- | --- | --- |
| Get components.| 1 | Online/Offline shopping | ![Shape2](RackMultipart20231104-1-q0pu2j_html_7619206be0902667.gif) ![Shape3](RackMultipart20231104-1-q0pu2j_html_edc20ebd0af580ac.gif) ![Shape4](RackMultipart20231104-1-q0pu2j_html_46d769e70c68925.gif)19%|
| Download codes.| 0.25 | Browse web/git | ![Shape5](RackMultipart20231104-1-q0pu2j_html_6d048574a80f0a4b.gif) ![Shape7](RackMultipart20231104-1-q0pu2j_html_edc20ebd0af580ac.gif) ![Shape6](RackMultipart20231104-1-q0pu2j_html_5ff0d7084cb1e963.gif)24%|
| Install software. | 1 | Browse web. Install applications. Linux command line application installation | ![Shape8](RackMultipart20231104-1-q0pu2j_html_7619206be0902667.gif) ![Shape9](RackMultipart20231104-1-q0pu2j_html_edc20ebd0af580ac.gif) ![Shape10](RackMultipart20231104-1-q0pu2j_html_488a7c9a3001bc0c.gif)43%|
| Edit and Compile code.| 0.5 | Arduino IDE compilation. gcc/clang command line compilation | ![Shape11](RackMultipart20231104-1-q0pu2j_html_7619206be0902667.gif) ![Shape13](RackMultipart20231104-1-q0pu2j_html_edc20ebd0af580ac.gif) ![Shape12](RackMultipart20231104-1-q0pu2j_html_1bf18397f805ffa.gif)52%|
| Assemble circuit.| 0.5 | Connect DuPont cables to US sensor while looking at the circuit diagram present in the document. | ![Shape14](RackMultipart20231104-1-q0pu2j_html_7619206be0902667.gif) ![Shape16](RackMultipart20231104-1-q0pu2j_html_edc20ebd0af580ac.gif) ![Shape15](RackMultipart20231104-1-q0pu2j_html_7232abd1f4d9c016.gif)62%|
| Create a test environment.| 1 | A worktable with all the hardware/software in one place. Upload ESP-32 code through Micro-USB data cable. | ![Shape17](RackMultipart20231104-1-q0pu2j_html_7619206be0902667.gif) ![Shape19](RackMultipart20231104-1-q0pu2j_html_edc20ebd0af580ac.gif) ![Shape18](RackMultipart20231104-1-q0pu2j_html_44533c3bdfb0e7fd.gif)82%|
| Debugging| 1 (subjective) | Subjective | ![Shape20](RackMultipart20231104-1-q0pu2j_html_7619206be0902667.gif) ![Shape21](RackMultipart20231104-1-q0pu2j_html_edc20ebd0af580ac.gif) ![Shape22](RackMultipart20231104-1-q0pu2j_html_9e070da5b4c4402f.gif)99%|
| Deploy on filed.| Subjective | Subjective ||

# Source code

[https://github.com/derrildsouza/Embedded\_programming/tree/main/functional\_projects/decentralized\_sensors/Ultra-Sonic\_UDP\_terminal\_feed](https://github.com/derrildsouza/Embedded_programming/tree/main/functional_projects/decentralized_sensors/Ultra-Sonic_UDP_terminal_feed)

# Source code explanation

# Use cases.

# Pros/cons

# Conclusion

In conclusion, the "Ultra-Sonic UDP Terminal Feed" project introduces a seamless way to harness ultrasonic sensor data wirelessly on Linux terminals. By combining hardware and software expertise, this project offers valuable learning experience for beginners in the embedded systems field. With a clear block diagram, source code explanation, and insights into its use cases and limitations, this project aims to empower enthusiasts in the world of ultrasonic data acquisition and analysis.

