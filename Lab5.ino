#include <mbed.h>

using namespace mbed;
//Serial.begin(9600);

void setup() {
}

void loop() {
  I2C i2c(P0_31, P0_2); // initializes i2c, uses P0_31 as SDA (for data) and P0_2 as SCL (clock)
  const char mux_cmd = 0x01; // defines mux_cmd as command to select a channel on the I2C mux. Addresss in hex as 1, in binary it is 0001
  const char mux_addr = 0xEE; // select bus 0 on mux chip
  i2c.write(mux_addr, &mux_cmd, 1); // writes the mux_cmd to the addresss mux_addr  
  //the sensor is now on bus 0, address 0x80
  
  char cmd[2];
  cmd[0] = 0x5E;
  cmd[1] = 0x00;
  i2c.write(0x80, cmd, 1);
  wait_us(500000); // wait for sensor response
  i2c.read(0x80, cmd, 2);

  // ir sensor has a 7 bit slave address so must be shifted by 1 bit before passing
  //how does that apply to this??

  char distances[2];//array distances with 2 values
  distances[0] = 0x5E;//high distance
  distances[1] = 0x5F;//low distance
  i2c.write(0x80, distances, 1);
  char dist_high;
  i2c.read(0x80, distances, 1);  //Read distance high 

  wait_us(500000); // wait for sensor response

  i2c.write(0x80, distances, 2);
  char dist_low = 0x5F;
  i2c.read(0x80, distances, 2);//Read distance low


  //Read shift bit
  char n = 0x35;
  
  float dist = (dist_high*16)+(dist_low/(16/(2^n)));

  Serial.print(cmd[0], HEX); // print the first byte in hex
  Serial.println(); // print blank line
  Serial.print(cmd[1], HEX); // print the second byte in hex
  Serial.println(); // print blank line
  Serial.print("Distance in cm: ");
  Serial.println(dist, 2);//Print distance

}
