const int dht11_pin = A0;
//unsigned long times[100] = {0};

void setup()
{
  pinMode(dht11_pin, OUTPUT);
  digitalWrite(dht11_pin, HIGH);
  Serial.begin(9600);
  Serial.println("ready");
}

int init_dht11()
{
  pinMode(dht11_pin, OUTPUT);
  digitalWrite(dht11_pin, HIGH);
  delay(100);
  digitalWrite(dht11_pin, LOW);
  delay(18);
  digitalWrite(dht11_pin, HIGH);
  delayMicroseconds(40);
  pinMode(dht11_pin, INPUT);
  delayMicroseconds(40);  
  if (digitalRead(dht11_pin) != LOW) {
    delay(1000);
    return 1;
  }
  delayMicroseconds(80);
  if (digitalRead(dht11_pin) != HIGH) {
    Serial.println("condition 2 not met");
    delay(1000);
    return 2;
  }
  delayMicroseconds(80);
  return 0;
}

byte read_dht11_data()
{
  const int timeout = 10000;
  unsigned long t;
  byte data = 0;
  for (int bit = 0; bit < 8; ++bit) {
    int count = 0;
    while (digitalRead(dht11_pin) == LOW) {
      delayMicroseconds(1);
      if (++count >= timeout)
        return -1;
    }
    delayMicroseconds(30);
    data = (data << 1) | digitalRead(dht11_pin);
    count = 0;
    while (digitalRead(dht11_pin) == HIGH) { 
      delayMicroseconds(1);
      if (++count >= timeout)
        return -1;
    }
  }
  return data;
}

void measure()
{
  byte dht11_data[5] = {0};
  if (init_dht11()) {
    Serial.println("init_dht11 failed");
    return;
  }
    
  for (int i = 0; i < 5; ++i) {
    dht11_data[i] = read_dht11_data();
  }

  pinMode(dht11_pin, OUTPUT);
  digitalWrite(dht11_pin, HIGH);

  byte sum = 0;
  for (int i = 0; i < 4; ++i) {
    sum += dht11_data[i];
  }
  
  if (dht11_data[4] != sum) {
    Serial.println("bad checksum");
    return;
  }
  
  Serial.print("Humidity: ");
  Serial.print(dht11_data[0]);
  Serial.print(".");
  Serial.print(dht11_data[1]);
  Serial.println("%");
  
  Serial.print("Temperature: ");
  Serial.print(dht11_data[2]);
  Serial.print(".");
  Serial.print(dht11_data[3]);
  Serial.println("C");
  delay(1000);
}

void loop()
{
  int count;
  delay(1000);
  Serial.println("begin");
  measure();

}
