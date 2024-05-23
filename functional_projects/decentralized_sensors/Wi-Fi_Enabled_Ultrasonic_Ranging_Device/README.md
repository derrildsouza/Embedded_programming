
##
# Wi-Fi Enabled Ultrasonic Ranging Device



# Introduction

The "Wi-Fi enabled Ultrasonic ranging device" project aims to develop a wireless distance measurement system using an ultrasonic sensor HC-SR04, an ESP-32 chip, and the UDP protocol over Wi-Fi. This project enables real-time transmission of distance data from the sensor to a remote receiver, which can be a client socket code written in C programming. The receiver can be executed on a Linux terminal or an Android phone terminal using the Termux app, as long as they are connected to the same local Wi-Fi network.

By leveraging the capabilities of the ESP-32 chip and its built-in Wi-Fi module, the system establishes a wireless connection and utilizes the UDP protocol for data transmission. The ultrasonic sensor HC-SR04 measures distances by emitting ultrasonic waves and calculating the time it takes for the waves to bounce back. The measured distance is then transmitted wirelessly to the receiver within the local Wi-Fi network, allowing for remote monitoring and analysis.

It's important to note that the data transmission is limited to the local Wi-Fi network and is not connected to the internet. This ensures data privacy and security, as the distance data remains within the confines of the local network.

The receiver, implemented as a client socket code in C programming, can be executed on a Linux terminal or an Android phone terminal using the Termux app. This flexibility allows for easy integration with existing systems and provides a convenient interface for receiving and processing the distance data. The client socket code establishes a connection with the ESP-32 chip acting as the server, enabling seamless communication and data retrieval.

The primary objective of this project is to provide a reliable and efficient means of distance measurement that eliminates the need for physical connections. This wireless solution offers flexibility in terms of sensor placement and enables real-time monitoring of distances in various applications such as robotics, automation, security systems, and more. In this project I will leave it to your imagination on how you can use this.
Throughout this design document, we will outline the system architecture, hardware components, software implementation, and testing procedures required to successfully develop the "Ultrasonic Wi-Fi Distance Transmitter" project, including the setup and execution of the client socket code on a Linux terminal or an Android phone terminal using the Termux app within the local Wi-Fi network.


# Let's Get to Work!

## Project-setup:

![block_diagram](https://github.com/derrildsouza/Embedded_programming/assets/64513486/70e3d611-fcf3-4fba-a3e9-0cde90cf299b)

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

 "Wi-Fi Enabled Ultrasonic ranging device" project offers an accessible and engaging platform for beginners to delve into the world of embedded programming. It provides a hands-on learning experience, fosters understanding of wireless communication and sensor integration, develops problem-solving skills, and encourages creativity and innovation.

# ![Shape1](RackMultipart20231104-1-q0pu2j_html_dd0215582b2d4580.gif)Skills Needed:

- Software development in C.
- Basic hardware understanding.
- A grasp of network protocols, specifically UDP in this case.
- Time management to complete the project efficiently.


# Circuit diagram:

![circuit_diagram](https://github.com/derrildsouza/Embedded_programming/assets/64513486/d32f9125-9231-4492-9121-7af729a35770)

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


