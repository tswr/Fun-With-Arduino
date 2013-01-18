const int num1_connection[8] = {9, 8, 5, 6, 7, 10, 11, 4}; // a .. h

const int numbers[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111 // 9
};

void show_number(const int n, const int num_connection[8])
{
  int bits = numbers[n % 10];
  for (int i = 0; i < 8; ++i) {
    if (bits & 1)
      digitalWrite(num_connection[i], HIGH);
    else
      digitalWrite(num_connection[i], LOW);
    bits >>= 1;
  }
}

void setup_num(const int num_connection[8])
{
  for (int i = 0; i < 8; ++i)
    pinMode(num_connection[i], OUTPUT);     
}

void setup()
{
  setup_num(num1_connection);  
  
  pinMode(18, OUTPUT);     
  pinMode(19, OUTPUT);     
}

void loop()
{
  for (int i = 0; i < 10; ++i) {
    show_number(i, num1_connection);
    delay(1000);
  }

  digitalWrite(18, HIGH);
  digitalWrite(18, LOW);
  delay(1000);
  for (int i = 0; i < 9; ++i) {
    digitalWrite(19, HIGH);
    digitalWrite(19, LOW);
    delay(1000);
  }
}
