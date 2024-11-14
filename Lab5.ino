#include <mbed.h>

using namespace mbed;

void setup() {
}

void loop() {
  I2C i2c(P0_31, P0_2);              // initializes i2c, uses P0_31 as SDA (for data) and P0_2 as SCL (clock)
  const char mux_cmd = 0x01;         // defines mux_cmd as command to select a channel on the I2C mux. Addresss in hex as 1, in binary it is 0001
  //const char mux_cmd = 0x02;  //this selects the other IR sensor when uncommented
  const char mux_addr = 0xEE;        // select bus 0 on mux chip
  i2c.write(mux_addr, &mux_cmd, 1);  // writes the mux_cmd to the addresss mux_addr
  //the sensor is now on bus 0, address 0x80

  char distances[3];    //array distances with 3 values
  distances[0] = 0x5E;  //high distance
  distances[1] = 0x5F;  //low distance
  distances[2] = 0x00;
  i2c.write(0x80, distances, 1);  // write register addresss to read from
  wait_us(500000);                // wait for sensor response
  i2c.read(0x80, distances, 3);   //Read distance high
  
  Serial.println();
  Serial.print("Distance in cm: ");
  Serial.print((distances[0]*16.0+distances[1])/16.0/4);
  Serial.println();
  delay(100);
}
