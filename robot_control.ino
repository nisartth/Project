// Title: Obstacle Avoidance with Ultrasonic Sensor and Motor Control

// Description: 
// This code controls a motor using an ultrasonic sensor to detect obstacles. 
// When an obstacle is detected within a specified distance, the motor will reverse direction to avoid the obstacle.
// Components used: Ultrasonic sensor (HC-SR04), L298N motor driver, DC motors.

// Pin assignments for ultrasonic sensor and motor driver
const int trigPin = 2;  // Trigger pin for ultrasonic sensor
const int echoPin = 3;  // Echo pin for ultrasonic sensor
int en = 6;             // Enable pin for motor speed control (PWM)
int in1 = 8;            // Input 1 for motor 1
int in2 = 7;            // Input 2 for motor 1
int in3 = 11;           // Input 1 for motor 2
int in4 = 12;           // Input 2 for motor 2

float duration, distance;  // Variables for sensor data

void setup() {
  // Pin modes for the ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  
  // Pin modes and initial state for motor control
  pinMode(en, OUTPUT);   // PWM pin for speed control
  pinMode(in1, OUTPUT);  // Motor 1 control pins
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);  // Initially stop motor 1
  digitalWrite(in2, LOW);
  
  pinMode(in3, OUTPUT);  // Motor 2 control pins
  pinMode(in4, OUTPUT);
  analogWrite(en, 200);  // Set motor speed (PWM value)
  digitalWrite(in3, LOW);  // Initially stop motor 2
  digitalWrite(in4, LOW);
}

void loop() {
  // Trigger ultrasonic sensor to send pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;  // Speed of sound is 343 m/s
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);  // Short delay for stability
  
  // Move forward: Set motor direction
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // If an obstacle is detected within 6 cm, reverse motor direction
  if (distance <= 6) {
    while (1) {  // Infinite loop to stop further movement
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);  // Reverse motor 1 direction
    }
  }
}
