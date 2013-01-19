int prev = 0, cur = 0, state = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  prev = cur;
  cur = digitalRead(2);
  
  if (Serial.available()) {
    int todo = Serial.read();
    if (todo == '0') {
      digitalWrite(4, LOW);
      state = 0;
    } else {
      digitalWrite(4, HIGH);
      state = 1;
    }
  }
  
  if (prev != cur && cur == HIGH) {
    state = 1 - state;
    if (state)
      digitalWrite(4, HIGH);
    else
      digitalWrite(4, LOW);
  }
  
  delay(1);
}
  
