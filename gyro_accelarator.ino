#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;
void setup() {
  Serial.begin(115200);
  Wire.begin(); 
  mpu.initialize();
  // Check if the connection was successful
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connection successful");
  } else {
    Serial.println("MPU6050 connection failed");
  }
}
void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  // Read accelerometer and gyroscope data
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  // Print the data
  Serial.print("aX = "); Serial.print(ax);
  Serial.print(" | aY = "); Serial.print(ay);
  Serial.print(" | aZ = "); Serial.print(az);
  Serial.print(" | gX = "); Serial.print(gx);
  Serial.print(" | gY = "); Serial.print(gy);
  Serial.print(" | gZ = "); Serial.println(gz);

  delay(500);
}


