# Mouse Jiggler

A hardware based Mouse Jiggler that prevents your computer from going to sleep. 

## Why

You can buy mouse jigglers on amazon for $10, however they are kind of dumb and limited. 

- Moves mouse 1 pixel every second
- Predictable pattern _could_ be tracked
- Fragile (I've had more than 1 die on me unexpectedly)

Furthermore if you use OSX and you 'hide' your dock, it is impossible to unhide the dock by hovering since the OS thinks you are still moving your mouse. 

## Vision

What if you could make a mouse jiggler that:

- Moved at random intervals (between 1 and 10 minutes)
- Moved a random direction
- Was more reliable
- Cost less than $10


Several perfect devices come to mind

1. [Digispark](http://digistump.com/products/1)  
    ![](https://s3.amazonaws.com/digistump-resources/images/m/2520dcf84a0a3bf2257c2559d7a187db.jpg)
2. [Adafruit NeoKey](https://www.adafruit.com/product/5020)
   ![](https://cdn-shop.adafruit.com/970x728/5020-04.jpg)
3. [Arduino Pro Micro (32u4)](https://www.amazon.com/s?k=arudino+pro+micro&crid=131WL7TFNTEXD&sprefix=arudino+pro+micro%2Caps%2C119&ref=nb_sb_noss_2)
   ![](https://cdn.sparkfun.com//assets/parts/9/3/2/6/12640-01a.jpg)
4. [Teensy](https://www.adafruit.com/product/2419)  
    ![](https://www.pjrc.com/teensy/teensy40.jpg)
5. [Adafrit Trinket M0](https://www.adafruit.com/product/3500)
    ![](https://cdn-shop.adafruit.com/970x728/3500-00.jpg)


This repo contains code for Digispark. It should be simple to add support for other devices. 

## What you need

1. Digispark [Amazon](https://www.amazon.com/s?k=digispark&crid=35OBHCUY1RSFI&sprefix=digispark%2Caps%2C158&ref=nb_sb_noss_1)
2. USB 2.0 hub or USB Extension cable (OSX wont reliably upload firmware to digispark on USB 3.0 ports https://github.com/micronucleus/micronucleus/issues/131 )
3. VsCode + Platform.io installed on your computer

![](https://docs.platformio.org/en/latest/_images/platformio-ide-vscode-build-project.png)

## Installation

1. Open vscode + platform.io and click build + upload

You will get a prompt like
```bash
> Please plug in the device (will time out in 60 seconds) ... 
```

At this point, unplug and replug in the digispark within 5 seconds. It should automatically upload. 
If it fails to upload, try a different USB 2.0 hub or add a usb extension cable. 

## Additional information

[Digispark tutorial](https://www.youtube.com/watch?v=x4Ap-ypWdFo)
[Digispark tutorial2](https://ericdraken.com/usb-mouse-jiggler/)

## Warnings

This is for educational purposes. Use at your own risk. The device _will_ show up with a ProductID and VendorID of digispark.

See [this article](https://ericdraken.com/usb-mouse-jiggler/) on how to modify `USB_CFG_VENDOR_ID` and `USB_CFG_DEVICE_VERSION` in the `usbconfig.h` if you want to change what brand device it appears as. 

```
hidapitester --list-detail

16C0/27DA: digistump.com - DigiKey
  vendorId:      0x16C0
  productId:     0x27DA
  usagePage:     0x0001
  usage:         0x0001
  serial_number: digistump.com:Mouse 
  interface:     0 
  path: IOService:/AppleARMPE/arm-io/AppleT600xIO/usb-drd2@2280000/AppleT6000USBXHCI@02000000/usb-drd2-port-hs@02100000/USB2.0 Hub@02100000/AppleUSB20Hub@02100000/AppleUSB20HubPort@02110000/DigiKey@02110000/IOUSBHostInterface@0/AppleUserUSBHostHIDDevice
```