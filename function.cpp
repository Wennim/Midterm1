#include "function.h"
#include "uLCD_4DGL.h"
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
AnalogOut  aout(PA_4);
AnalogIn Ain(A0);
AnalogOut Aout(PA_5);
float ADCdata[96];


void ulcd_display(int i){
if(i==1){

// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,0);
    uLCD.color(RED);
    uLCD.printf("  1"); //Default Green on black text
    

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(GREEN);
    uLCD.printf("  1/2"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(GREEN);
    uLCD.printf("  1/4"); //Default Green on black text
    
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(GREEN);
    uLCD.printf("  1/8"); //Default Green on black text

}

else if(i ==2){
// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,0);
    uLCD.color(GREEN);
    uLCD.printf("  1"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(RED);
    uLCD.printf("  1/2"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(GREEN);
    uLCD.printf("  1/4"); //Default Green on black text

     uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(GREEN);
    uLCD.printf("  1/8"); //Default Green on black text
}

else if(i==3){
// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,0);
    uLCD.color(GREEN);
    uLCD.printf("  1"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(GREEN);
    uLCD.printf("  1/2"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(RED);
    uLCD.printf("  1/4"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(GREEN);
    uLCD.printf("  1/8"); //Default Green on black text
}

else if(i==4){
// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,0);
    uLCD.color(GREEN);
    uLCD.printf("  1"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(GREEN);
    uLCD.printf("  1/2"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(GREEN);
    uLCD.printf("  1/4"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(RED);
    uLCD.printf("  1/8"); //Default Green on black text
}
}

void wave(float j){

while (1)
{
    for (float i = 0.00f; i <= 0.96; i += 0.012f/j) {
            aout = i;
            
        ThisThread::sleep_for(1ms);
            }

           for (float i = 0.00f; i <=0.24f-j*0.16f; i += 0.001f) {
            aout = aout;
            
        ThisThread::sleep_for(1ms);
            }

        for (float i = 0.96f; i >= 0.00; i -= 0.012f/j) {
            aout = i;
            
        ThisThread::sleep_for(1ms);
            }

}
}

void sampling(){
int i=0;
   while(i<96){
    ADCdata[i] = Ain;
    printf("%f\n", ADCdata[i]);
    Aout = ADCdata[i];
    ThisThread::sleep_for(1ms);
    i++;
  }
}

