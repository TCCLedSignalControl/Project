#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 84

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int rightArrow   [] = {5,6,18,17,29,30,42,41,51,52,53,54,55,56,64,65,66,67,77,78}; 
int leftArrow    [] = {5,6,16,17,18,19,27,28,29,30,31,32,41,42,53,54,65,66,77,78}; 
int warningSign  [] = {25,26,27,28,29,30,31,33,34,46,45,44,43,42,40,41,38,37,49,50,51,52,53,54,55,57,58}; 

char Incoming_value = 0;

void setup() 
{
  pixels.begin();
  Serial.begin(38400);
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read(); 
    
    if(Incoming_value == 'M')
    {
       background();
       setAnimation(27,warningSign);
       delay(3000);
       cleanAll();
    }
    else if(Incoming_value != 0)
    {
      for (int i=0; i< 3; i++)
      {
        if(Incoming_value == 'L')
        {
          background();
          setAnimation(20,leftArrow);
        }                  
        else if(Incoming_value == 'R')
        {
          background(); 
          setAnimation(20,rightArrow);  
        }
        delay(500);
        cleanAll();
        delay(500);
      }
    }
  }                        
} 

void setAnimation(int size, int pattern [])
{
    for (int i=0; i< size; i++)
    {
        pixels.setPixelColor(pattern[i]-1 , pixels.Color(100, 100, 100));        
    }
    pixels.show();
}

void background()
{
    for (int i=0; i< NUMPIXELS; i++)
    {   
        pixels.setPixelColor(i, pixels.Color(40,0,0));      
    }
    pixels.show();
}
void cleanAll()
{
    for (int i=0; i< NUMPIXELS; i++)
    {   
        pixels.setPixelColor(i, pixels.Color(0,0,0));      
    }
    pixels.show();
}
