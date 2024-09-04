/*

  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital

  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:

  - momentary switch attached from pin 2 to ground

  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal

  20K-ohm resistor is pulled to 5V. This configuration causes the input to read

  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012

  by Scott Fitzgerald

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/InputPullupSerial

*/

void setup() {

  //start serial connection

  Serial.begin(9600);

  //configure pin 2 as an input and enable the internal pull-up resistor

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  
  pinMode(13, OUTPUT);

}

void loop() {

  //read the pushbutton value into a variable

  int QRG = 255-(digitalRead(2)+(2*digitalRead(3))+(4*digitalRead(4))+(8*digitalRead(5))+(16*digitalRead(6))+(32*digitalRead(7))+(64*digitalRead(8))+(128*digitalRead(9)));
    //print out the value of the pushbutton

  Serial.println(QRG);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes

  // HIGH when it's open, and L pressed. Turn on pin 13 when the

  // button's pressed, and off when it's not:
  delay(200);
  if (QRG >= 161) {

    digitalWrite(13, HIGH);

  } else {

    digitalWrite(13, LOW);

  }
}
