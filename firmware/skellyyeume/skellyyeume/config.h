// Copyright 2025 yeume (@yeume)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MASTER_LEFT //left half of the keyboard is the master
#define SOFT_SERIAL_PIN D0 //this tells which pin on the microcontroller will be used for data transmission between the keyboard halves. Refer to the pro micro controller image inside the pictures folder. D0 is pin 3 on the microcontroller.
#define SERIAL_DEBUG //used this for testing purposes
#define SPLIT_USB_DETECT //This basically tells the microcontroller that whichever side has the USB connection to the computer is the master and the other slave.
#define SPLIT_USB_TIMEOUT 2000 // This is necessary because USB enumeration during PC cold boot might not be instant. The value can be increased if necessary, but 2000 works for me.
