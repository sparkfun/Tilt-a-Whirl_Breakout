//For the RPI-1031
//Originally written by the great folks at Bildr.org
//http://bildr.org/2012/02/rpi-1031_arduino/
//Released originally under the MIT License: http://opensource.org/licenses/mit-license.php

//Modified for SparkFun Electronics by T. Klopfenstein
int tilt_s1 = 2;
int tilt_s2 = 3;

void setup(){
 pinMode(tilt_s1, INPUT);
 pinMode(tilt_s2, INPUT);
 Serial.begin(9600);
}

void loop(){
  int position = getTiltPosition();
  Serial.println(position);
  delay(200); //only here to slow down the serial output
}

int getTiltPosition(){
   int s1 = digitalRead(tilt_s1);
   int s2 = digitalRead(tilt_s2);
   return (s1 << 1) | s2; //bitwise math to combine the values
}
