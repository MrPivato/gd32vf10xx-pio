# GD32VF10xx Platformio Template Project

NOTE: **Tested with the Sipeed Longan Nano Dev-Board**

## Needed Packages

Apart from the Platformio/VsCode install,
run: `sudo apt install libusb-dev stm32flash binutils build-essential`.

Don't forget to add the udev rules too:

```bash
curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core/develop/platformio/assets/system/99-platformio-udev.rules | sudo tee /etc/udev/rules.d/99-platformio-udev.rules

sudo service udev restart

sudo usermod -a -G dialout $USER
sudo usermod -a -G plugdev $USER
# now log out and log in
```

## Needed Tools

Any `FTDI` or `Usb to TTL` module should do.

## Connections

| USB to TTL | Dev Board |
|------------|-----------|
| GND        | GND       |
| 3V3        | 3V3       |
| RXD        | TX        |
| TXD        | RX        |

## Flashing

1. Enter bootloader mode by first holding down the `RESET` and `BOOT`
buttons and then release them in same order.

2. Click the `Platformio: Upload` button or run the `pio run -t upload`.

## Serial Debug

TODO

## On-Chip Debug

TODO
