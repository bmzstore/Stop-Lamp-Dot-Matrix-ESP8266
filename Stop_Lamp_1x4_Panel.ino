#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "Parola_Fonts_data.h"
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CLK_PIN   D5 
#define DATA_PIN  D7 
#define CS_PIN    D6  

#define kiri D1
#define kanan D2
#define rem D3

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

int i = 0;
int j=0;
int k=0;
void panah_kiri();
void panah_kanan();
void Stop_blink();
void Rem_blink();

textEffect_t texteffect[] =

{
  
  PA_PRINT,
  PA_SCAN_HORIZ,
  PA_SCROLL_LEFT,
  PA_WIPE,
  PA_SCROLL_UP_LEFT,
  PA_SCROLL_UP,
  PA_OPENING_CURSOR,
  PA_GROW_UP,
  PA_MESH,
  PA_SCROLL_UP_RIGHT,
  PA_BLINDS,
  PA_CLOSING,
  PA_RANDOM,
  PA_GROW_DOWN,
  PA_SCAN_VERT,
  PA_SCROLL_DOWN_LEFT,
  PA_WIPE_CURSOR,
  PA_DISSOLVE,
  PA_OPENING,
  PA_CLOSING_CURSOR,
  PA_SCROLL_DOWN_RIGHT,
  PA_SCROLL_RIGHT,
  PA_SLICE,
  PA_SCROLL_DOWN

};

void setup() {

  pinMode(kiri, INPUT_PULLUP);
  pinMode(kanan, INPUT_PULLUP);
  pinMode(rem, INPUT_PULLUP);

  myDisplay.begin();
  myDisplay.setIntensity(5);
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setPause(500);
  myDisplay.setSpeed(10);
  myDisplay.displayClear(); 

}

void loop() {

   int tombolkiri=digitalRead(kiri);
   int tombolkanan=digitalRead(kanan);
   int tombolrem=digitalRead(rem);
   
   if (tombolkiri==0 and tombolkanan==0)
    {Hati2_blink();}

   if (tombolkiri==0)
    {
     j++;
     if(j==1){
         myDisplay.displayClear();
         myDisplay.print("                            ");  
      }
      panah_kiri();
      k=0;
    } 

    else if (tombolkanan==0)
    {
      j++;
      if(j==1)
      {
         myDisplay.displayClear();
         myDisplay.print("                            ");  
      }
      panah_kanan();
      k=0;
    }

    else if (tombolrem==0)
    {
      Stop_blink();
    }
    else
    {
      j=0;
      k++;
      if(k==1)
      {
         myDisplay.displayClear();
         myDisplay.print("                            ");  
      }
      if ( k>10) {k=2;}
      
      myDisplay.setIntensity(2);
      myDisplay.setTextAlignment(PA_CENTER);
      myDisplay.setPause(1);
      myDisplay.setSpeed(30);

     if (myDisplay.displayAnimate()) {
      i=2;
      myDisplay.setFont(bmz5x7);
      myDisplay.displayText("B_Mz Store 081391543454", myDisplay.getTextAlignment(), myDisplay.getSpeed(), myDisplay.getPause(), texteffect[i], texteffect[i]);
      myDisplay.displayReset();
     }
    }
}





void panah_kiri(){
  myDisplay.setIntensity(5);
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setPause(0);
  myDisplay.setSpeed(25);
 
if (myDisplay.displayAnimate()) {
      i=2; 
      myDisplay.displayText("[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[", myDisplay.getTextAlignment(), myDisplay.getSpeed(), myDisplay.getPause(), texteffect[i], texteffect[i]);
      myDisplay.displayReset();
     }
}

void panah_kanan(){
  myDisplay.setIntensity(5);
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setPause(0);
  myDisplay.setSpeed(25);

if (myDisplay.displayAnimate()) {
      i=21; 
      myDisplay.displayText("]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]", myDisplay.getTextAlignment(), myDisplay.getSpeed(), myDisplay.getPause(), texteffect[i], texteffect[i]);
      myDisplay.displayReset();
     }
}

void Stop_blink(){
myDisplay.setFont(bmz6x8);
myDisplay.print("STOP");
delay(200);
myDisplay.print("         ");  
delay(200);
}

void Hati2_blink(){
myDisplay.print("  {}  ");
delay(100);
myDisplay.print("  {}  ");  
delay(100);
myDisplay.print(" <{}> ");
delay(100);
myDisplay.print("      ");  
delay(100);


}
