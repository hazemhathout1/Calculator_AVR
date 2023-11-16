# Calculator Project using Atmega32

This repository contains the source code and documentation for a simple calculator project implemented on an Atmega32 microcontroller. The calculator utilizes an LCD in 4-bit mode, a keypad for input, and an external interrupt to clear the screen.

## Overview

The calculator project aims to demonstrate basic arithmetic operations (addition, subtraction, multiplication, division) on an embedded system using the Atmega32 microcontroller. It uses the following components:

- Atmega32 microcontroller
- 16x2 LCD in 4-bit mode
- Keypad for input
- External interrupt to clear the screen

## Features

- Arithmetic operations: addition, subtraction, multiplication, division.
- Clear screen functionality using an external interrupt (e.g., push button).

## Hardware Setup

### Connections:

- **Atmega32**: Configure and connect the microcontroller as per the datasheet.
- **LCD (16x2) in 4-bit mode**: Connect the LCD data pins to the microcontroller's GPIO pins. Refer to the provided source code for pin configurations.
- **Keypad**: Connect the keypad to GPIO pins on the microcontroller for input.
- **External Interrupt**: Connect an external interrupt pin (e.g., using a push button) to a GPIO pin on the microcontroller for clearing the screen.
