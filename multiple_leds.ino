/**
 * Copyright 2012 Dmitri Kornev
 *
 * @date    Jan 18, 2013
 * @author  "Dmitri Kornev" <d.v.kornev@gmail.com>
 *
 * @brief   
 */

const int leds[] = {13,12,11,10,9,8,7,6,5,4};
const int num_of_leds = sizeof(leds) / sizeof(int);

void led_on(int i)
{
  digitalWrite(leds[i], HIGH);
}

void led_off(int i)
{
  digitalWrite(leds[i], LOW);
}

void pattern_blink_all()
{
  int sleep_ms = 1000;
  for (int r = 0; r < 5; ++r) {
    for (int i = 0; i < num_of_leds; ++i)
      led_on(i);
    delay(sleep_ms);
    for (int i = 0; i < num_of_leds; ++i)
      led_off(i);
    delay(sleep_ms);
  }
}

void pattern_shooting_beam()
{
  int sleep_ms = 50;  
  for (int r = 0; r < 5; ++r) {
    for (int i = 0; i < num_of_leds; ++i)
      led_off(i);
    delay(sleep_ms);    
    for (int i = 0; i < num_of_leds; ++i) {
      led_on(i);
      delay(sleep_ms);
    }        
    for (int i = 0; i < num_of_leds; ++i) {
      led_off(i);
      delay(sleep_ms);
    }
  }
}  

void pattern_taxi()
{
  int sleep_ms = 200;        
  for (int r = 0; r < 20; ++r) {
    for (int i = 0; i < num_of_leds; ++i)
      i % 2 ? led_on(i) : led_off(i);
    delay(sleep_ms);    
    for (int i = 0; i < num_of_leds; ++i)
      i % 2 ? led_off(i) : led_on(i);
    delay(sleep_ms);
    sleep_ms -= 10;
  }
} 

void pattern_tetris()
{
  int sleep_ms = 100;
  for (int i = 0; i < num_of_leds; ++i)
    led_off(i);
  delay(sleep_ms);
  for (int j = 0; j < num_of_leds; ++j) {
    led_on(0);
    delay(sleep_ms);
    for (int i = 1; i < num_of_leds - j; ++i) {
      led_off(i - 1);
      led_on(i);
      delay(sleep_ms);
    }
  }
  delay(sleep_ms);
} 

void pattern_inc()
{
  int sleep_ms = 20;
  for (int t = 0; t < 1024; ++t) {
    for (int i = 0; i < num_of_leds; ++i)
      (t >> i) & 1 ? led_on(i) : led_off(i);
    delay(sleep_ms);
  }
} 

void pattern_downloading()
{
  int sleep_ms = 100;
  for (int i = 0; i < num_of_leds; ++i)
    led_off(i);
  delay(sleep_ms);
  for (int j = 0; j < num_of_leds; ++j) {
    for (int i = 0; i < 18; ++i) {
      i % 2 ? led_on(j) : led_off(j);
      delay(sleep_ms);
    }
    led_on(j);
  }
  delay(sleep_ms);
}    

void setup()
{                
  for (int i = 0; i < num_of_leds; ++i)
    pinMode(leds[i], OUTPUT);     
}

void loop()
{
  pattern_blink_all();
  pattern_shooting_beam();
  pattern_tetris();
  pattern_inc();
  pattern_downloading();
}

