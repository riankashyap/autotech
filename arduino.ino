const int trigPin = 6;
const int trigPin_2 = 9 ;
const int echoPin  = 5;
const int echoPin_2 = 11;
long duration ;
long duration2 ;
int distance ;
int distance2 ;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin_2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin_2, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_2, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin_2, LOW);
  duration2 = pulseIn(echoPin_2, HIGH);
  distance2 = duration2 * 0.034 / 2;
  Serial.print("Distance2: ");
  Serial.println(distance2);

  if (distance2 <= 30)
  {
    analogWrite(10, 200);
  }

  else if (distance2 >= 30 && distance2 <= 60)
  {
    analogWrite(10, 150);
  }
  else if (distance2 >= 60 && distance2 <= 100)
  {
    analogWrite(10, 100);
  }
  else if (distance2 >= 100 && distance2 <= 150)
  {
    analogWrite(10, 50);
  }
  else
  {
    analogWrite(10, 0);
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin , HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 30)
  {
    analogWrite(3, 200);
  }

  else if (distance >= 30 && distance <= 60)
  {
    analogWrite(3, 150);
  }
  else if (distance >= 60 && distance <= 100)
  {
    analogWrite(3, 100);
  }
  else if (distance >= 100 && distance <= 150)
  {
    analogWrite(3, 50);
  }
  else
  {
    analogWrite(3, 0);
  }  

}
