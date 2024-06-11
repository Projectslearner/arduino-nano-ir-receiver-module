/*
    Project name : IR Receiver Module
    Modified Date: 10-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-ir-receiver-module
*/

#include <IRremote.h>

// Define the pin for the IR receiver
const int RECV_PIN = 2;

// Create an IR receiver object
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  irrecv.enableIRIn(); // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received IR code: ");
    Serial.println(results.value, HEX); // Print the received IR code in hexadecimal format
    irrecv.resume(); // Receive the next value
  }
}
