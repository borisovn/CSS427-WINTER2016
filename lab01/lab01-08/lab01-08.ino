// Program: based on user input (serial input) turn on or off the LED light 
// input 1: turn on
// input 0: turn off
// Use string reader to parse user input
String readString; 

void setup() {
  Serial.begin(9600);
  pinMode(13, LED_BUILTIN);
}

void loop() {
  
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the string readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() >0) {
    Serial.println(readString);  //so you can see the captured string 
    int n = readString.toInt();  //convert readString into a number

    // auto select appropriate value, copied from someone elses code.
    if(n == 1)
    {
      digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    else if (n== 0)
    {   
      digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    }

    readString=""; //empty for next input
  } 
}

