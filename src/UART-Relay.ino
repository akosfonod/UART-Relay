#define BAUD 115200
#define STATUS_LED 13
#define CONTROL_PIN 4
#define UART_TIMEOUT 200 //Timeout in ms.

bool state = true;
bool previous_state = state;

void setup(){
    pinMode(STATUS_LED,OUTPUT);
    pinMode(CONTROL_PIN,OUTPUT);
    Serial.begin(BAUD);
    while(!Serial){;} //Wait for the Serial to be opened.
    Serial.setTimeout(UART_TIMEOUT);
    digitalWrite(STATUS_LED,state);
}

void loop(){
    if(state != previous_state){
        previous_state = state;
        digitalWrite(CONTROL_PIN,!state); //Inversion needed in order to control the relay in the correct order.
        digitalWrite(STATUS_LED,state);
    }
}

void serialEvent(){
    if(Serial.available() > 0){
        if(Serial.parseInt(SKIP_ALL)==0){
            state = false;
        }
        else{
            state = true;
        }
    Serial.flush();
    }
}