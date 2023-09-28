"""
Reads the serial data given by the Arduino code
"""
import time
import serial

Arduino = serial.Serial(
    port="/dev/ttyACM0", baudrate=115200, timeout=0.1
)  # (Remove this comment Sohum) Replace this with the COM Port you have in Arduino

data_list = []


def write_read():
    """ """
    time.sleep(0.05)
    data = Arduino.readline()
    data = data[2::]
    return data


# You may change this into a for loop when you do the servo movement
while True:
    value = write_read()
    data_list.append(value)  #
    print(value)
