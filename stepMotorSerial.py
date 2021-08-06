#!/usr/bin/env python
import time
import serial
import RPi.GPIO as GPIO    # Import Raspberry Pi GPIO library
from time import sleep     # Import the sleep function from the time module
GPIO.setwarnings(False)    # Ignore warning for now
GPIO.setmode(GPIO.BOARD)   # Use physical pin numbering
GPIO.setup(8, GPIO.OUT, initial=GPIO.LOW)   # Set pin 8 to be an output pin and set initial value to low (off)

ser = serial.Serial(
    port='/dev/ttyUSB0', #Replace ttyS0 with ttyAM0 for Pi1,Pi2,Pi0
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1)
counter=100

while True: # Run forever
    GPIO.output(8, GPIO.HIGH) # Turn on
    sleep(0.1) # Sleep for 1 second
    GPIO.output(8, GPIO.LOW) # Turn off
    sleep(0.1) # Sleep for 1 second
    command = raw_input("komut = ")
    ser.write(command)
    time.sleep(1)
    
       
        