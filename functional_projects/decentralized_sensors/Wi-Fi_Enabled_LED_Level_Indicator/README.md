
##
# Wi-Fi Enabled LED Level Indicator

![skills_needed](https://github.com/derrildsouza/Embedded_programming/assets/64513486/799a72c5-9c5d-4225-a5db-5dbc7571a644)

# Introduction

In various applications, knowing the level of a substance—whether it’s water in a tank, the distance from an object, or any other measurable quantity—is crucial. Our project aims to provide a versatile solution using the ESP-32 microcontroller and a set of LEDs.
By wirelessly interfacing the ESP-32 with sensors or data sources, we can visualize levels in real time. Whether you’re monitoring liquid levels, measuring distances, or tracking any other parameter, this project offers flexibility and simplicity.
In this tutorial, we’ll explore how to build a customizable LED level indicator that adapts to your specific needs. Let’s illuminate the way!


# Let's Get to Work!

## Project-setup:

![block_diagram](https://github.com/derrildsouza/Embedded_programming/assets/64513486/70e3d611-fcf3-4fba-a3e9-0cde90cf299b)

_Figure 1: Project Setup_

In our project, we establish a seamless connection between our LED arrays and a Wi-Fi network. This connectivity is facilitated by an ESP-32 microcontroller, renowned for its capability to handle Wi-Fi packets effectively. 

Here's how the system works:

### Hardware Setup:

- We connect 8 LEDs to the ESP-32 microcontroller, creating a robust hardware foundation.
- A dedicated code is crafted to set the LED’s ON or OFF, which is then uploaded onto the microcontroller.

### Data Reception:

-	The microcontroller takes on the pivotal role of not only setting the LED’s but also formatting and the received data from the Wi-Fi network.
-	To ensure efficient data reception, we employ UDP reception on a specified port number and IP address. This ensures that the data flows seamlessly within the network.


### Data Transmission:

-	On the transmitting end, whether it's a Linux laptop or an Android phone, a client code is implemented to register itself to the designated IP address and port number.
-	The client code is responsible for sending the percentage value, thus establishing a vital link between the Linux laptop or an Android phone.


### Data Display:

- In this iteration of the project, our primary objective is to set the received data on the LED arrays. This foundational step lays the groundwork for further data processing and subsequent actions in future project phases.

# What Do We Need?

##   Hardware

-	A Linux laptop or an Android phone with a terminal installed.
-	An ESP-32 Microcontroller.
-	An 8 LED’s strip with parallel connection.
-	A couple of DuPont/jumper cables.
-	Optional: Power bank, casing, and other accessories.


##   Software

- Arduino IDE
- Gcc/clang or a similar C code compiler for your laptop or phone.


# What Do We Achieve?

The "Wi-Fi enabled LED Level Indicator" project offers an accessible and engaging platform for beginners to delve into the world of embedded programming. It provides a hands-on learning experience, fosters understanding of wireless communication and actuator integration, and encourages creativity and innovation.

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
| Assemble circuit.| 1 | Solder the LED’s along with resistors on a general purpose PCB. Connect DuPont cables to LED PCB while looking at the circuit diagram present in the document| ![Shape14](RackMultipart20231104-1-q0pu2j_html_7619206be0902667.gif) ![Shape16](RackMultipart20231104-1-q0pu2j_html_edc20ebd0af580ac.gif) ![Shape15](RackMultipart20231104-1-q0pu2j_html_7232abd1f4d9c016.gif)69%|
| Create a test environment.| 1 | A worktable with all the hardware/software in one place. Upload ESP-32 code through Micro-USB data cable. | ![Shape17](RackMultipart20231104-1-q0pu2j_html_7619206be0902667.gif) ![Shape19](RackMultipart20231104-1-q0pu2j_html_edc20ebd0af580ac.gif) ![Shape18](RackMultipart20231104-1-q0pu2j_html_44533c3bdfb0e7fd.gif)88%|
| Debugging| 1 (subjective) | Subjective | ![Shape20](RackMultipart20231104-1-q0pu2j_html_7619206be0902667.gif) ![Shape21](RackMultipart20231104-1-q0pu2j_html_edc20ebd0af580ac.gif) ![Shape22](RackMultipart20231104-1-q0pu2j_html_9e070da5b4c4402f.gif)99%|
| Deploy on filed.| Subjective | Subjective ||

# Source code

[https://github.com/derrildsouza/Embedded\_programming/tree/main/functional\_projects/decentralized\_sensors/Ultra-Sonic\_UDP\_terminal\_feed](https://github.com/derrildsouza/Embedded_programming/tree/main/functional_projects/decentralized_sensors/Ultra-Sonic_UDP_terminal_feed)

# Source code explanation

# Use cases.

# Pros/cons

# Conclusion

In conclusion, the "Wi-Fi enabled LED Level Indicator" project introduces a seamless way to set LED arrays wirelessly through Linux terminals. By combining hardware and software expertise, this project offers valuable learning experience for beginners in the embedded systems field. With a clear block diagram, source code explanation, and insights into its use cases and limitations, this project aims to empower enthusiasts in the world of ultrasonic data acquisition and analysis.

