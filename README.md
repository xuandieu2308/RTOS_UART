| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C5 | ESP32-C6 | ESP32-C61 | ESP32-H2 | ESP32-H21 | ESP32-H4 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | --------- | -------- | --------- | -------- | -------- | -------- | -------- |

# UART Full Duplex Example (ESP32 ↔ ESP32)

This example demonstrates full-duplex UART communication between two ESP32 boards using ESP-IDF and FreeRTOS.

Each ESP32 periodically sends data and receives data concurrently using two FreeRTOS tasks.

## How the example works

- UART port: UART1
- Baudrate: 115200
- Two FreeRTOS tasks are created:
  - uart_tx_task: sends data every 1 second
  - uart_rx_task: receives data continuously

## Hardware required

- 2 × ESP32 development boards
- Jumper wires

### UART wiring

| ESP32 #1 | ESP32 #2 |
|---------|----------|
| GPIO17 (TX) | GPIO16 (RX) |
| GPIO16 (RX) | GPIO17 (TX) |
| GND | GND |

Common ground is required.

## UART configuration

UART parameters used in this example:

- Port: UART1
- Baudrate: 115200
- Data bits: 8
- Parity: None
- Stop bits: 1
- Flow control: Disabled
- TX pin: GPIO17
- RX pin: GPIO16

## How to use example

Follow the ESP-IDF setup instructions for your target chip:

- ESP32 Getting Started Guide  
  https://docs.espressif.com/projects/esp-idf/en/stable/get-started/index.html

- ESP32-S2 Getting Started Guide  
  https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/get-started/index.html

### Build and flash

```bash
idf.py set-target esp32
idf.py build
idf.py -p PORT flash monitor
Expected output

ESP1:

ESP1 SEND: Hello 1
ESP1 SEND: Hello 2


ESP2:

ESP2 SEND: Hello 1
ESP2 SEND: Hello 2


Both boards will also log received UART data.

Example folder contents
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── uart_full_duplex_main.c
└── README.md

Troubleshooting
Program upload failure

Check USB and UART connections

Select the correct serial port

Lower flash baudrate in menuconfig if flashing fails

No UART communication

Verify TX/RX wiring

Ensure both boards use the same baudrate

Ensure GND is connected

Technical support and feedback

ESP32 Forum: https://esp32.com/

ESP-IDF Issues: https://github.com/espressif/esp-idf/issues
