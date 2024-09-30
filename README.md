
const int trigPin = 2;
const int echoPin = 3;
int en=6;
int in1=8;
int in2=7;
int in3 = 11;
int in4 = 12;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(en,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(en,200);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  if(distance <=6)
  {
    while(1)
    {    
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
    }
  }
}
