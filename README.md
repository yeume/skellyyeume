# skellyyeume
This is a guide on how to hardwire build a TBK skeletyl <br>

https://bastardkb.com/product/skeletyl-kit/
https://github.com/Bastardkb/Skeletyl/tree/main?tab=readme-ov-file

# Table of Contents
1. [Useful Links](#usefullinks)
2. [Prerequisites](#prereq)
3. [How the hell does handwiring keyboard work?](#howthehell)
4. [What the hell are all these files in the firmware folder?](#whatthehell)
5. [Getting the firmware onto the microcontroller](#buildfirmware)
6. [BOM (Bill of materials)](#bom)


<div id='rules'>
- NEVER unplug the TRRS jack from either half of the keyboard while it is plugged in via usb to the computer.
- ALWAYS flash the firmware to both microcontrollers when making changes.

<div id='usefullinks'>

# Useful Links 
https://docs.qmk.fm/features/split_keyboard<br>
https://docs.splitkb.com/troubleshooting/one-half<br>
https://docs.qmk.fm/keycodes_basic<br>
https://docs.qmk.fm/feature_layers<br>
https://docs.qmk.fm/mod_tap (if you want to use [**homerow mods**](https://precondition.github.io/home-row-mods))

Disclaimer: 
- You do not need any prior programming background, but it helps.
- This assumes you have some experience with soldering
- keymapping this keyboard currently only works through modifying the `keymap.c` file in the firmware folder. The via keymapper doesn't work properly (mainly because via thinks this keyboard is a dactyl manuform, which it is not. Basically there's a vid (vendor id)/pid (product id) in keyboard.json which via looks up to determine what keyboard it is when we load the keyboard on the via website. I just borrowed one from dactyl at the time...)


<div id='prereq'>

# Prerequisites:

- [QMK MSYS](https://msys.qmk.fm) <details>
<collapse> </collapse>
This is the CLI (Command Line Interface, think of it like the command prompt/power shell on windows (or if you're a mac user, the terminal), but it comes with lots of prebuilt tools, and also has Git preinstalled so you don't need to go through manually setting up Git on your machine). Install it wherever you like, as long as you can find it later.
</details>

- [VS Code](https://code.visualstudio.com/download)<details>
<collapse> </collapse>
Text editor of choice, you'll use this to modify the keymap later when building the firmware.
</details>




<div id='bom'>

# BOM:
- Case/Plate <details>
<collapse> </collapse>
if you have a 3d printer, feel free to use the files
[case](https://github.com/Bastardkb/Skeletyl/blob/main/V4/case_v4_103.stl) , [plate](https://github.com/Bastardkb/Skeletyl/blob/main/V4/plates/plate_v4_103.stl) and print them yourself. I personally went with https://jlc3dp.com and chose their 9600 Resin option. You can see it doesn't cost a lot. The part that costs the most is the shipping, as this company is located in Hong Kong (for me it was ~20 dollar shipping.) ![img](pictures/jlc_order_option.png) ![img](pictures/jlc_order_history.png)
</details> 

- [Pro Micro](https://www.amazon.com/dp/B0D83FBYPD?ref=ppx_yo2ov_dt_b_fed_asin_title)
- [TRRS cable (if you don't have one)](https://www.amazon.com/Auxiliary-Braided-Compatible-Stereos-Headphones/dp/B07PJW6RQ7?crid=M0JVQ8AC44R2&dib=eyJ2IjoiMSJ9.x8XyTX_WjBB74z2o_RS3wZouPmAvfc9lsTF2XwadVspnsXhCyZ3sEjrJIFvcj07VjPb2ukVEcHMMdFqQQ5WnilRhUtSXqpUNZeYQrIj6PCi3d0s-_3WaSPNqsxLHPGGlmoelcC116vqeaLxyneCUOdxsF61USm3T56SrBBsqNiOE8nwHdqjUuTznev3zTZjn67bkJ3-58j1BcJup_rc7W6c5BgaXe67HN8kMBzFW7Ks.w0K85m45D4xlSl5SNSa1YeLz5AXxlyIiPARfxesFRcA&dib_tag=se&keywords=trrs+cable&qid=1743568676&sprefix=trrs+cab%2Caps%2C173&sr=8-3)
- [TRRS jack](https://www.amazon.com/uxcell-Connector-Female-Socket-PJ-320A/dp/B07KXZ6T3D?dib=eyJ2IjoiMSJ9.5VGTNb80dxu3oo0avJPM9Z9LNGvpT85MTJS8sOLkSrD91o5140na1eeToQN8mSKX0kUHNauVv19QxmRHMvqKts9XhCDL5ACRRBtrTjbySfnvGx5ehynBM3MiuiPcmDZ52uHtuv5MUD5cGwvlTXAGT9ZKohi6Ioh4NxmFxMQbYObZJguELrT73il9QgBC4bS9ONDyj6gylXU5DhPkSw8xnzWsiZIoKzAecX9OZSVtrPQ.su6CPoWc3V_3lI0K1bqFUdlCaWO7_RsF8YB98WO36gI&dib_tag=se&keywords=trrs%2Bjack&qid=1743568599&sr=8-3&th=1)
- [[OPTIONAL] 16 gauge copper wire](https://www.amazon.com/dp/B000BP7WH8?ref=ppx_yo2ov_dt_b_fed_asin_title) - This is to provide a cleaner way to wire up the columns/rows, but it can be done without.
- [22AWG wire](https://www.amazon.com/dp/B00QTCBZ4I?ref=ppx_yo2ov_dt_b_fed_asin_title)
- [solder iron](https://www.amazon.com/dp/B06XZ31W3M?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_5&th=1)
- [solder wire](https://www.amazon.com/dp/B01M071WEE?ref=ppx_yo2ov_dt_b_fed_asin_title)
- 

<div id='howthehell'>

# How the hell does handwiring keyboard work?
Imagine the keyboard as a matrix grid, like tic-tac-toe. As every switch has 2 metal pins, a collection of one of the pins on each switch can be wired together to form columns, and the other pin can be used for rows. Each row and column is designated to a pin on the microcontroller, and based on a switch press on the grid, the keyboard recognizes the keystroke to the designated key command. Joe scotto's vid, if you're a visual learner https://youtu.be/hjml-K-pV4E?t=41&feature=shared


<div id='whatthehell'>

# What the hell are all these files in the firmware folder?
I've went ahead and dropped comments where I could, but these are the most important files:
- keyboard.json - sets up the basic information about your keyboard (keyboard matrix layout, what sort of microcontroller is used, what pins on the microcontroller are used, etc.)
- keymap.c - contains different keymap profiles/layouts based on what tools you'll be using (ex. via)
- config.h, rules.mk - similar to keyboard.json, but has additional settings.

<div id='buildfirmware'>

# Getting the firmware onto the microcontroller

1. Open QMK MSYS, and input `qmk setup`. This process will take some time depending on your internet connection. It basically prepares your machine with necessary tools to start building your firmware, and clones the [qmk_firmware github repo](https://github.com/qmk/qmk_firmware) on to your machine.
2. Once the setup has finished, you can copy the folder `skellyyeume` under `firmware` of this repo, and paste it under `/keyboards/handwired` of the `qmk_firmware` folder (so it would look like `/keyboards/handwired/skellyyeume`)
3. Modify `keymap.c` (under the **default** folder) to your desired layout in VS Code. [Useful Links](#usefullinks) for selecting your keycodes.
4. Head back to QMK MSYS, and type the following
```
cd qmk_firmware
```

```
qmk compile -kb handwired/skellyyeume -km default
```

once successfully compiled you should see a message like the following and find the file that was generated at the root of the qmk_firmware folder:
![img](pictures/compile.png)


```
qmk flash -bl avrdude handwired_skellyyeume_default.hex
```
![img](pictures/flash1.png) <br>
You'll first be prompted to put the microcontroller in DFU/bootloarder mode to flash the firmware. You can achieve this by shorting the RST & GND Pin on the microcontroller with some tweezers [pinout](pictures/pinout.jpg). It only takes a gentle tap on the pins and you'll see a very tiny red led light up for half of a second when you short these pins. Wait for 5~10 seconds and then brighter red LEDs will flash and you'll see more console lines printed on QMK MSYS console like below. 
![img](pictures/flash2.png)

<h1 style="color: red; font-weight: bold"> Repeat the process for a second microcontroller, which will be used for the other half of the keyboard. </h1>

The above command simply translates to...<details>
<collapse> </collapse>
```
change directory to qmk_firmware
compile the firmware using the default keymap.c from the /keymaps/default folder
flash the firmware file generated
```
</details> 


5. 

qmk compile -kb handwired/skellyyeume -km default
qmk flash -bl avrdude handwired_skellyyeume_default.hex

<div id='wiring'>

# wiring up the board
