#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>


const int greenLED  = 2;
const int yellowLED = 3;
const int redLED    = 4;


const int buzzer = 5;


const int echoPin = 7;
const int trigPin = 8;


SoftwareSerial bluetooth(10, 11);


LiquidCrystal_I2C lcd( 0x27,16, 2);

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  bluetooth.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("SMART PARKING");

  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(1500);
  lcd.clear();
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);


  long duration = pulseIn(echoPin, HIGH, 30000);


  if (duration == 0) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    noTone(buzzer);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No object");
    lcd.setCursor(0, 1);
    lcd.print("Check sensor");

    delay(200);
    return;
  }


  float distance = duration * 0.0343 / 2.0;


  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  noTone(buzzer);

  String status;


  if (distance > 50) {
    digitalWrite(greenLED, HIGH);
    status = "SAFE";
  }


  else if (distance > 25) {
    digitalWrite(yellowLED, HIGH);
    status = "CAUTION";
    tone(buzzer, 2000, 80);
  }


  else {
    digitalWrite(redLED, HIGH);
    status = "STOP";
    tone(buzzer, 2000, 150);
  }


  Serial.print("Distance: ");
  Serial.print(distance, 1);
  Serial.print(" cm | Status: ");
  Serial.println(status);


  bluetooth.print("Distance: ");
  bluetooth.print(distance, 1);
  bluetooth.print(" cm | Status: ");
  bluetooth.println(status);


  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance, 1);
  lcd.print("cm");

  lcd.setCursor(0, 1);
  lcd.print("Status: ");
  lcd.print(status);

  delay(distance <= 25 ? 150 : 300);
}
