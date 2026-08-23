#include <Wire.h>
// ---------- pins ----------
#define RED_LED       33
#define BLUE_LED      25
#define YELLOW_LED    27
#define BUZZER        26

#define FORWARD_BTN   18
#define BACKWARD_BTN  19
#define PIEZO_PIN     34

#define SDA_PIN       21
#define SCL_PIN       22
// ---------- mpu6050 ----------



#define MPU_ADDR      0x68
#define PWR_MGMT_1    0x6B
#define ACCEL_CONFIG  0x1C
#define ACCEL_XOUT_H  0x3B
// ---------- setup —————
void setup() {

  Serial.begin(115200);
  delay(2000);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(FORWARD_BTN, INPUT_PULLUP);
  pinMode(BACKWARD_BTN, INPUT_PULLUP);

  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(BUZZER, LOW);

  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("SYSTEM STARTING");

  // Wake MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);
  byte result = Wire.endTransmission();

  if (result == 0) {
    Serial.println("MPU IS READY");
  } else {
    Serial.println("MPU ERROR");
  }

  // Set accelerometer to +/-8G
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(ACCEL_CONFIG);
  Wire.write(0x10);
  Wire.endTransmission();

  Serial.println("SYSTEM READY");
}

// ---------- loop —————

void loop() {

  // ---------- read mpu ----------

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6);

  if (Wire.available() == 6) {

    int16_t rawX = (Wire.read() << 8) | Wire.read();
    int16_t rawY = (Wire.read() << 8) | Wire.read();
    int16_t rawZ = (Wire.read() << 8) | Wire.read();

    float x = rawX / 4096.0;
    float y = rawY / 4096.0;
    float z = rawZ / 4096.0;

    Serial.print("X: ");
    Serial.print(x, 2);

    Serial.print(" | Y: ");
    Serial.print(y, 2);
    Serial.print(" | Z: ");
    Serial.print(z, 2);

  } else {

    Serial.print("MPU READ ERROR");
  }

  // ---------- buttons ----------

  bool forwardPressed = digitalRead(FORWARD_BTN) == LOW;
  bool backwardPressed = digitalRead(BACKWARD_BTN) == LOW;

  digitalWrite(BLUE_LED, forwardPressed);
  digitalWrite(YELLOW_LED, backwardPressed);

  // ---------- peizo ———
  int piezoValue = analogRead(PIEZO_PIN);

  Serial.print(" | Piezo: ");
  Serial.print(piezoValue);

  // Piezo threshold
  if (piezoValue > 1000) {

    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);

  } else {

    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  // ---------- button status ----------

  if (forwardPressed) {
    Serial.print(" | FORWARD");
  }
  if (backwardPressed) {
    Serial.print(" | BACKWARD");
  }
 Serial.println();
 delay(100);
}
