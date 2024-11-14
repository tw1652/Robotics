#include <mbed.h>

using namespace mbed;

void setup() {
}


void loop() {
  I2C i2c(P0_31, P0_2); // initializes i2c, uses P0_31 as SDA (for data) and P0_2 as SCL (clock)
  const char mux_cmd = 0x01; // defines mux_cmd as command to select a channel on the I2C mux. Addresss in hex as 1, in binary it is 0001
  const char mux_addr = 0xEE; // select bus 0 on mux chip
  i2c.write(mux_addr, &mux_cmd, 1); // writes the mux_cmd to the addresss mux_addr  
  //the sensor is now on bus 0, address 0x80
  
  //Read shift bit
  //char n;
  //i2c.read(0x35, &n, 1);
  int n = 2.04;

  // ir sensor has a 7 bit slave address so must be shifted by 1 bit before passing
  // how does that apply to this??

  char distances[3];//array distances with 3 values
  distances[0] = 0x5E;//high distance
  distances[1] = 0x5F;//low distance
  distances[2] = 0x00;
  i2c.write(0x80, distances, 1);// write register addresss to read from
  wait_us(500000); // wait for sensor response
  i2c.read(0x80, distances, 3);  //Read distance high 

  float dist = ((distances[0]*16)+(distances[1]))/(16/(2^n));

  /*Serial.println(); // print blank line
  Serial.println("high distance");
  Serial.println();
  Serial.print(distances[0], DEC);
  Serial.println();
  Serial.println("low distance");
  Serial.println(); 
  Serial.print(distances[1], DEC);
  //Serial.println();
  //Serial.println("shift bit");
  //Serial.println();
  //Serial.println(n);
  //Serial.println();*/
  Serial.print("Distance in cm: ");
  Serial.println(dist, 3);//Print distance
