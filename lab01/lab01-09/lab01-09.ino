// Program: based on user input (serial input) increase or decrease the speed of fading the LED’s brightness
// input 1: increase speed
// input 0: decrease speed
// input 2: set default
// Contstains: brightness can be only increase up to 5 ms delay and decrease up to 60 ms


String readString; 
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int led = 13;           // the PWM pin the LED is attached to
int mydelay = 30;
int n;


void setup() {
  Serial.begin(9600);
  pinMode(led, LED_BUILTIN);
}

void loop() {
  
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the string readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }
  if (readString.length() >0) {
    Serial.println(readString);  //so you can see the captured string 
    n = readString.toInt();  //convert readString into a number
        

    // auto select appropriate value, copied from someone elses code.
    if(n == 1) {
      if(mydelay !=5) {
        mydelay = mydelay -5;
      }
    }
    else if (n== 0) {
      if(mydelay < 60) {
        mydelay = mydelay  + 5;
      }
    }
    else if(n==2) {
      mydelay = 30;
    }
    readString=""; //empty for next input
    Serial.println(mydelay);
  } 

   // set the brightness of pin 9:
   analogWrite(led, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
    }

    delay(mydelay);
    
}

