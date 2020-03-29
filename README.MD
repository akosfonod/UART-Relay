To build the project:
    platformio run  -v -e promini
    platformio run  -v -e nano
To clean the project:
    platformio run  -t clean
To flash the program onto the arduino
    platformio run  -v -e pormini -t upload --upload-port COM5
    platformio run  -v -e nano -t upload --upload-port COM1