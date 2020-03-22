import serial
import sys
import re

DEBUG = False
port_identifier = "COM7"
port = None

try:
    port = serial.Serial(port_identifier, baudrate = 115200, timeout = None)
except serial.serialutil.SerialException as e:
    print "Could not open port: " + port_identifier

if port is not None and len(sys.argv) > 1:
    value = re.sub("\D","",sys.argv[1])
    if DEBUG:
        print "Value: " + value
    port.write(value)
    if DEBUG:
        print "Exiting"
sys.exit(0)