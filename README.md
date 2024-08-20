# UART Communication Between Two Arduinos

This project demonstrates how to set up UART (Universal Asynchronous Receiver-Transmitter) communication between two Arduino boards without using any external libraries.
The project includes code for both the transmitter and receiver Arduinos.

### Hardware Setup

### Components
- 2 Arduino boards (e.g., Arduino Uno)
- Jumper wires

### Wiring Diagram
- **Arduino A (Transmitter):**
  - TX (Pin 1) ➜ RX (Pin 0) of Arduino B
  - RX (Pin 0) ➜ TX (Pin 1) of Arduino B
  - GND ➜ GND of Arduino B

- **Arduino B (Receiver):**
  - TX (Pin 1) ➜ RX (Pin 0) of Arduino A
  - RX (Pin 0) ➜ TX (Pin 1) of Arduino A
  - GND ➜ GND of Arduino A

The functionality of this project was tested at Tinkercad.
