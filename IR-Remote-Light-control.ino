// GP4UTECH
#include <IRremote.h>

int RECV_PIN = 2; // the pin where you connect the output pin of sensor
int led1 = 6;
int led2 = 8;
int led3 = 10;
int led4 = 12;
int itsONled[] = {0, 0, 0, 0, 0}; // Including index for LED4

#define code1 0x1FE50AF // code received from button no. 1
#define code2 0x1FED827 // code received from button no. 2
#define code3 0x1FEF807 // code received from button no. 3
#define code4 0x1FE30CF // code received from button no. 4

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600); // you can omit this line
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
      case code1:
        if (itsONled[1] == 1) {
          digitalWrite(led1, LOW);
          itsONled[1] = 0;
        } else {
          digitalWrite(led1, HIGH);
          itsONled[1] = 1;
        }
        break;
      case code2:
        if (itsONled[2] == 1) {
          digitalWrite(led2, LOW);
          itsONled[2] = 0;
        } else {
          digitalWrite(led2, HIGH);
          itsONled[2] = 1;
        }
        break;
      case code3:
        if (itsONled[3] == 1) {
          digitalWrite(led3, LOW);
          itsONled[3] = 0;
        } else {
          digitalWrite(led3, HIGH);
          itsONled[3] = 1;
        }
        break;
      case code4:
        if (itsONled[4] == 1) { // Corrected indexing
          digitalWrite(led4, LOW);
          itsONled[4] = 0;
        } else {
          digitalWrite(led4, HIGH);
          itsONled[4] = 1;
        }
        break;
    }
    Serial.println(value); // you can omit this line
    irrecv.resume(); // Receive the next value
  }
}
