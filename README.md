Supported Targets	ESP32	ESP32-C2	ESP32-C3	ESP32-C5	ESP32-C6	ESP32-C61	ESP32-H2	ESP32-H21	ESP32-H4	ESP32-P4	ESP32-S2	ESP32-S3
UART Full Duplex Example (ESP32 ↔ ESP32)

This example demonstrates full-duplex UART communication between two ESP32 boards using ESP-IDF and FreeRTOS.

Each ESP32:

Sends UART data periodically

Receives UART data concurrently

Uses two FreeRTOS tasks (TX & RX)

How the example works

UART port: UART1

Baudrate: 115200

Two FreeRTOS tasks are created:

uart_tx_task: send data every 1 second

uart_rx_task: receive data continuously

Each board prints both sent and received messages to the serial monitor.

Hardware required

2 × ESP32 development boards

Jumper wires

UART wiring
ESP32 #1	ESP32 #2
GPIO17 (TX)	GPIO16 (RX)
GPIO16 (RX)	GPIO17 (TX)
GND	GND

⚠️ Common ground is required

UART configuration
UART Port     : UART1
Baudrate      : 115200
Data bits     : 8
Parity        : None
Stop bits     : 1
Flow control  : Disabled
TX Pin        : GPIO17
RX Pin        : GPIO16

How to use example

Follow the ESP-IDF setup instructions depending on your board:

ESP32 Getting Started Guide

ESP32-S2 Getting Started Guide

Build and flash
idf.py set-target esp32
idf.py build
idf.py -p PORT flash monitor


Replace PORT with your serial port (e.g. /dev/ttyUSB0 or COM3).

Expected output
ESP1
I (1000) ESP1_FULL: ESP1 đã gửi: ESP1 SEND: Hello 1
I (1100) ESP1_FULL: ESP1 đã nhận: ESP2 SEND: Hello 1

ESP2
I (1000) ESP2_FULL: ESP2 đã gửi: ESP2 SEND: Hello 1
I (1100) ESP2_FULL: ESP2 đã nhận: ESP1 SEND: Hello 1

Example folder contents
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── uart_full_duplex_main.c
└── README.md


uart_full_duplex_main.c: Main application source

CMakeLists.txt: Project build configuration

ESP-IDF projects use CMake as the build system.

For more details, refer to:
ESP-IDF Build System Guide

Troubleshooting
Program upload failure

Check UART cable and connections

Make sure correct PORT is selected

Lower flash baudrate in menuconfig if needed

No UART data received

Verify TX/RX wiring is crossed correctly

Ensure both boards use the same baudrate

Confirm both boards share a common GND

Technical support and feedback

For technical questions:
👉 https://esp32.com/

For bug reports or feature requests:
👉 https://github.com/espressif/esp-idf/issues
