#include "mbed.h"
#include "TextLCD.h"

 TextLCD lcd(PA_1, PA_2, PA_3, PA_4, PA_5, PA_6); // rs, e, d4-d7
 
void runningManR(void);
void ManslipR(void);
void runningManL(void);
void ManslipL(void);

// setting animation speed (wait_ms between frames)
int x = 150;
// setting time for Man waiting
int y = 5000;

// START setting all the pixel-art
//setting pixels for standing man:
//step 1 of 1:
  unsigned char stepA1[8] = {0b00011,0b00111,0b00111,0b00111,0b00111,0b00001,0b00011,0b00111};
  unsigned char stepA2[8] = {0b00001,0b00001,0b00011,0b00011,0b00011,0b00001,0b00000,0b00001};
  unsigned char stepA3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11011,0b10001,0b10001};
  unsigned char stepA4[8] = {0b11111,0b11111,0b11101,0b11101,0b11111,0b11111,0b11111,0b11111};
  unsigned char stepA5[8] = {0b11000,0b11100,0b11100,0b11100,0b11100,0b10000,0b11000,0b11100};
  unsigned char stepA6[8] = {0b00000,0b10000,0b11000,0b00000,0b11000,0b11100,0b11000,0b10000};
  
//setting pixels for running man right:
//step 1 of 3:
  unsigned char stepB1[8] = {0b00011,0b00011,0b00011,0b00011,0b00001,0b00000,0b00000,0b00000};
  unsigned char stepB2[8] = {0b00000,0b00001,0b00001,0b00011,0b00011,0b00011,0b00000,0b00001};
  unsigned char stepB3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11110};
  unsigned char stepB4[8] = {0b11111,0b11111,0b11101,0b11101,0b11111,0b11111,0b11111,0b11111};
  unsigned char stepB5[8] = {0b00000,0b00000,0b10000,0b10000,0b10000,0b00000,0b10000,0b00000};
  unsigned char stepB6[8] = {0b00000,0b11000,0b00000,0b11000,0b11100,0b11000,0b10000,0b00000};

//step 2 of 3
  unsigned char stepC1[8] = {0b11111,0b11111,0b11101,0b00011,0b00111,0b01111,0b01111,0b00111};
  unsigned char stepC2[8] = {0b00000,0b00001,0b00001,0b00011,0b00011,0b00011,0b00000,0b00111};
  unsigned char stepC3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b10011,0b00000,0b00000};
  unsigned char stepC4[8] = {0b11111,0b11111,0b11101,0b11101,0b11111,0b11111,0b11111,0b11111};
  unsigned char stepC5[8] = {0b11110,0b11110,0b01100,0b11100,0b11100,0b11100,0b00000,0b00000};
  unsigned char stepC6[8] = {0b00000,0b11000,0b00000,0b11000,0b11100,0b11000,0b10000,0b00000};
  
//step 3 of 3
  unsigned char stepD1[8] = {0b00001,0b00011,0b00111,0b00111,0b00111,0b01111,0b01100,0b00000};
  unsigned char stepD2[8] = {0b00000,0b00000,0b00001,0b00001,0b00011,0b00011,0b00011,0b00000};
  unsigned char stepD3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11110,0b11111};
  unsigned char stepD4[8] = {0b00000,0b11111,0b11111,0b11101,0b11101,0b11111,0b11111,0b11111};
  unsigned char stepD5[8] = {0b10000,0b11000,0b10000,0b00000,0b00000,0b00000,0b00000,0b00000};
  unsigned char stepD6[8] = {0b00000,0b00000,0b11000,0b00000,0b11000,0b11100,0b11000,0b10000};

//setting pixels for man slipping right
//step 1 of 3
  unsigned char slipA1[8] = {0b00111,0b00111,0b00011,0b00011,0b00001,0b01111,0b01111,0b00111};
  unsigned char slipA2[8] = {0b00000,0b00011,0b00111,0b01111,0b01111,0b00111,0b00011,0b00111};
  unsigned char slipA3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11000,0b10000};
  unsigned char slipA4[8] = {0b11111,0b11111,0b11101,0b11101,0b11111,0b11111,0b11111,0b11111};
  unsigned char slipA5[8] = {0b11000,0b11000,0b10000,0b00000,0b00000,0b00000,0b00000,0b00000};
  unsigned char slipA6[8] = {0b00000,0b11000,0b00000,0b11100,0b11100,0b11000,0b10000,0b11000};

//step 2 of 3
  unsigned char slipB1[8] = {0b00011,0b00011,0b00001,0b00001,0b00000,0b00111,0b00111,0b00011};
  unsigned char slipB2[8] = {0b00000,0b00001,0b00011,0b00111,0b00111,0b00011,0b00001,0b00011};
  unsigned char slipB3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11100,0b11000};
  unsigned char slipB4[8] = {0b11111,0b11111,0b11110,0b11110,0b11111,0b11111,0b11111,0b11111};
  unsigned char slipB5[8] = {0b11100,0b11100,0b11000,0b10000,0b10000,0b00000,0b00000,0b00000};
  unsigned char slipB6[8] = {0b00000,0b11000,0b10000,0b11100,0b11110,0b11100,0b11000,0b11100};

//step 3 of 3
  unsigned char slipC1[8] = {0b00001,0b00001,0b00000,0b00000,0b00000,0b00011,0b00011,0b00001};
  unsigned char slipC2[8] = {0b00000,0b00000,0b00001,0b00011,0b00011,0b00001,0b00000,0b00001};
  unsigned char slipC3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11110,0b11100};
  unsigned char slipC4[8] = {0b01111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
  unsigned char slipC5[8] = {0b11110,0b11110,0b11100,0b11000,0b11000,0b10000,0b00000,0b00000};
  unsigned char slipC6[8] = {0b10000,0b11100,0b11000,0b11110,0b11111,0b11110,0b11100,0b11110};

//setting pixels for man running left
//step 1 of 3
  unsigned char stepE1[8] = {0b00000,0b00001,0b00001,0b00001,0b00000,0b00000,0b00001,0b00000};
  unsigned char stepE2[8] = {0b00000,0b00011,0b00000,0b00011,0b00111,0b00011,0b00001,0b00000};
  unsigned char stepE3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b01111};
  unsigned char stepE4[8] = {0b11111,0b11111,0b10111,0b10111,0b11111,0b11111,0b11111,0b11111};
  unsigned char stepE5[8] = {0b11000,0b11000,0b11000,0b11000,0b10000,0b00000,0b00000,0b00000};
  unsigned char stepE6[8] = {0b00000,0b10000,0b10000,0b11000,0b11000,0b11000,0b10000,0b10000};
  
//step 2 of 3
  unsigned char stepF1[8] = {0b01111,0b01111,0b01100,0b00111,0b00111,0b00111,0b00000,0b00000};
  unsigned char stepF2[8] = {0b00000,0b00011,0b00000,0b00011,0b00111,0b00011,0b00001,0b00000};
  unsigned char stepF3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11001,0b00000,0b00000};
  unsigned char stepF4[8] = {0b11111,0b11111,0b10111,0b10111,0b11111,0b11111,0b11111,0b11111};
  unsigned char stepF5[8] = {0b11111,0b11111,0b10111,0b11000,0b11100,0b11110,0b11110,0b11100};
  unsigned char stepF6[8] = {0b00000,0b10000,0b10000,0b11000,0b11000,0b11000,0b00000,0b11100};
  
//step 3 of 3
  unsigned char stepG1[8] = {0b00001,0b00011,0b00001,0b00000,0b00000,0b00000,0b00000,0b00000};
  unsigned char stepG2[8] = {0b00000,0b00000,0b00011,0b00000,0b00011,0b00111,0b00011,0b00001};
  unsigned char stepG3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b01111,0b11111};
  unsigned char stepG4[8] = {0b00000,0b11111,0b11111,0b10111,0b10111,0b11111,0b11111,0b11111};
  unsigned char stepG5[8] = {0b10000,0b11000,0b11100,0b11100,0b11100,0b11110,0b00110,0b00000};
  unsigned char stepG6[8] = {0b00000,0b00000,0b10000,0b10000,0b11000,0b11000,0b11000,0b00000};
  
//setting pixels for man slipping left
//step 1 of 3
  unsigned char slipD1[8] = {0b00011,0b00011,0b00001,0b00000,0b00000,0b00000,0b00000,0b00000};
  unsigned char slipD2[8] = {0b00000,0b00001,0b00000,0b00011,0b00111,0b00011,0b00001,0b00011};
  unsigned char slipD3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b00011,0b00001};
  unsigned char slipD4[8] = {0b11111,0b11111,0b10111,0b10111,0b11111,0b11111,0b11111,0b11111};
  unsigned char slipD5[8] = {0b11100,0b11100,0b11000,0b11000,0b10000,0b11110,0b11110,0b11100};
  unsigned char slipD6[8] = {0b00000,0b11000,0b11100,0b11110,0b11110,0b11100,0b11000,0b11100};

//step 2 of 3
  unsigned char slipE1[8] = {0b00111,0b00111,0b00111,0b00011,0b00001,0b00000,0b00000,0b00000};
  unsigned char slipE2[8] = {0b00000,0b00011,0b00001,0b00111,0b01111,0b00111,0b00011,0b00111};
  unsigned char slipE3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b00111,0b00011};
  unsigned char slipE4[8] = {0b11111,0b11111,0b01111,0b01111,0b11111,0b11111,0b11111,0b11111};
  unsigned char slipE5[8] = {0b11000,0b11000,0b10000,0b00000,0b10000,0b11100,0b11100,0b11000};
  unsigned char slipE6[8] = {0b00000,0b00000,0b11000,0b11100,0b11100,0b11000,0b10000,0b11000};
  
//step 3 of 3
  unsigned char slipF1[8] = {0b01111,0b01111,0b00111,0b00111,0b00011,0b00001,0b00000,0b00000};
  unsigned char slipF2[8] = {0b00001,0b00111,0b00011,0b01111,0b11111,0b01111,0b00111,0b01111};
  unsigned char slipF3[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b01111,0b00111};
  unsigned char slipF4[8] = {0b11110,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
  unsigned char slipF5[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b11000,0b11000,0b10000};
  unsigned char slipF6[8] = {0b00000,0b00000,0b10000,0b11000,0b11000,0b10000,0b00000,0b10000};
// END setting all the pixel-art


int main() 
{
	while(1) 
	{
		runningManR();
          // slip to the right:
        ManslipR();
          // now run to the left:
        runningManL();
          // slip to the left:
        ManslipL();
	
    }
}

// running man to the right animation part
void runningManR() {
  for (int a=0;a<11;a+=4){
  int b = a + 1;
  int c = a + 2;
  int d = a + 3;
  int e = a + 4;
  int f = a + 5;
  int g = a + 6;
  lcd.cls();
  lcd.createChar(1, stepB1);
  lcd.createChar(2, stepB2);
  lcd.createChar(3, stepB3);
  lcd.createChar(4, stepB4);
  lcd.createChar(5, stepB5);
  lcd.createChar(6, stepB6);
  lcd.address(b,1);
  lcd.writeData(1);
  lcd.address(b,0);
  lcd.writeData(2);
  lcd.address(c,1);
  lcd.writeData(3);
  lcd.address(c,0);
  lcd.writeData(4);
  lcd.address(d,1);
  lcd.writeData(5);
  lcd.address(d,0);
  lcd.writeData(6);
  wait_ms(x);
  lcd.cls();
  lcd.createChar(1, stepC1);
  lcd.createChar(2, stepC2);
  lcd.createChar(3, stepC3);
  lcd.createChar(4, stepC4);
  lcd.createChar(5, stepC5);
  lcd.createChar(6, stepC6);
  lcd.address(c,1);
  lcd.writeData(1);
  lcd.address(c,0);
  lcd.writeData(2);
  lcd.address(d,1);
  lcd.writeData(3);
  lcd.address(d,0);
  lcd.writeData(4);
  lcd.address(e,1);
  lcd.writeData(5);
  lcd.address(e,0);
  lcd.writeData(6);
  wait_ms(x);
  lcd.cls();
  lcd.createChar(1, stepB1);
  lcd.createChar(2, stepB2);
  lcd.createChar(3, stepB3);
  lcd.createChar(4, stepB4);
  lcd.createChar(5, stepB5);
  lcd.createChar(6, stepB6);
  lcd.address(d,1);
  lcd.writeData(1);
  lcd.address(d,0);
  lcd.writeData(2);
  lcd.address(e,1);
  lcd.writeData(3);
  lcd.address(e,0);
  lcd.writeData(4);
  lcd.address(f,1);
  lcd.writeData(5);
  lcd.address(f,0);
  lcd.writeData(6);
  wait_ms(x);
  lcd.cls();
  lcd.createChar(1, stepD1);
  lcd.createChar(2, stepD2);
  lcd.createChar(3, stepD3);
  lcd.createChar(4, stepD4);
  lcd.createChar(5, stepD5);
  lcd.createChar(6, stepD6);
  lcd.address(e,1);
  lcd.writeData(1);
  lcd.address(e,0);
  lcd.writeData(2);
  lcd.address(f,1);
  lcd.writeData(3);
  lcd.address(f,0);
  lcd.writeData(4);
  lcd.address(g,1);
  lcd.writeData(5);
  lcd.address(g,0);
  lcd.writeData(6);
  wait_ms(x);
  }
}

// slipping man the the right animation part
void ManslipR(){
  int a = 13;
  int b = a + 1;
  int c = a + 2;
  lcd.cls();
  lcd.createChar(1, slipA1);
  lcd.createChar(2, slipA2);
  lcd.createChar(3, slipA3);
  lcd.createChar(4, slipA4);
  lcd.createChar(5, slipA5);
  lcd.createChar(6, slipA6);
  lcd.address(a,1);
  lcd.writeData(1);
  lcd.address(a,0);
  lcd.writeData(2);
  lcd.address(b,1);
  lcd.writeData(3);
  lcd.address(b,0);
  lcd.writeData(4);
  lcd.address(c,1);
  lcd.writeData(5);
  lcd.address(c,0);
  lcd.writeData(6);
  wait_ms(x);
  lcd.cls();
  lcd.createChar(1, slipB1);
  lcd.createChar(2, slipB2);
  lcd.createChar(3, slipB3);
  lcd.createChar(4, slipB4);
  lcd.createChar(5, slipB5);
  lcd.createChar(6, slipB6);
  lcd.address(a,1);
  lcd.writeData(1);
  lcd.address(a,0);
  lcd.writeData(2);
  lcd.address(b,1);
  lcd.writeData(3);
  lcd.address(b,0);
  lcd.writeData(4);
  lcd.address(c,1);
  lcd.writeData(5);
  lcd.address(c,0);
  lcd.writeData(6);
  wait_ms(x);
  lcd.createChar(1, slipC1);
  lcd.createChar(2, slipC2);
  lcd.createChar(3, slipC3);
  lcd.createChar(4, slipC4);
  lcd.createChar(5, slipC5);
  lcd.createChar(6, slipC6);
  lcd.address(a,1);
  lcd.writeData(1);
  lcd.address(a,0);
  lcd.writeData(2);
  lcd.address(b,1);
  lcd.writeData(3);
  lcd.address(b,0);
  lcd.writeData(4);
  lcd.address(c,1);
  lcd.writeData(5);
  lcd.address(c,0);
  lcd.writeData(6);
  wait_ms(x);
}

// running man to the left animation part
void runningManL(){
  for (int a=16;a>4;a-=4){
  int b = a - 1;
  int c = a - 2;
  int d = a - 3;
  int e = a - 4;
  int f = a - 5;
  int g = a - 6;
  lcd.cls();
  lcd.createChar(1, stepE1);
  lcd.createChar(2, stepE2);
  lcd.createChar(3, stepE3);
  lcd.createChar(4, stepE4);
  lcd.createChar(5, stepE5);
  lcd.createChar(6, stepE6);
  lcd.address(d,1);
  lcd.writeData(1);
  lcd.address(d,0);
  lcd.writeData(2);
  lcd.address(c,1);
  lcd.writeData(3);
  lcd.address(c,0);
  lcd.writeData(4);
  lcd.address(b,1);
  lcd.writeData(5);
  lcd.address(b,0);
  lcd.writeData(6);
  wait_ms(x);
  lcd.cls();
  lcd.createChar(1, stepF1);
  lcd.createChar(2, stepF2);
  lcd.createChar(3, stepF3);
  lcd.createChar(4, stepF4);
  lcd.createChar(5, stepF5);
  lcd.createChar(6, stepF6);
  lcd.address(e,1);
  lcd.writeData(1);
  lcd.address(e,0);
  lcd.writeData(2);
  lcd.address(d,1);
  lcd.writeData(3);
  lcd.address(d,0);
  lcd.writeData(4);
  lcd.address(c,1);
  lcd.writeData(5);
  lcd.address(c,0);
  lcd.writeData(6);
  wait_ms(x);
  lcd.cls();
  lcd.createChar(1, stepE1);
  lcd.createChar(2, stepE2);
  lcd.createChar(3, stepE3);
  lcd.createChar(4, stepE4);
  lcd.createChar(5, stepE5);
  lcd.createChar(6, stepE6);
  lcd.address(f,1);
  lcd.writeData(1);
  lcd.address(f,0);
  lcd.writeData(2);
  lcd.address(e,1);
  lcd.writeData(3);
  lcd.address(e,0);
  lcd.writeData(4);
  lcd.address(d,1);
  lcd.writeData(5);
  lcd.address(d,0);
  lcd.writeData(6);
  wait_ms(x);
  lcd.cls();
  lcd.createChar(1, stepG1);
  lcd.createChar(2, stepG2);
  lcd.createChar(3, stepG3);
  lcd.createChar(4, stepG4);
  lcd.createChar(5, stepG5);
  lcd.createChar(6, stepG6);
  lcd.address(g,1);
  lcd.writeData(1);
  lcd.address(g,0);
  lcd.writeData(2);
  lcd.address(f,1);
  lcd.writeData(3);
  lcd.address(f,0);
  lcd.writeData(4);
  lcd.address(e,1);
  lcd.writeData(5);
  lcd.address(e,0);
  lcd.writeData(6);
  wait_ms(x);
  }
}

// slipping man to the leftt animation part
void ManslipL(){
  int a = 1;
  int b = a + 1;
  int c = a + 2;
  lcd.cls();
  lcd.createChar(1, slipD1);
  lcd.createChar(2, slipD2);
  lcd.createChar(3, slipD3);
  lcd.createChar(4, slipD4);
  lcd.createChar(5, slipD5);
  lcd.createChar(6, slipD6);
  lcd.address(a,1);
  lcd.writeData(1);
  lcd.address(a,0);
  lcd.writeData(2);
  lcd.address(b,1);
  lcd.writeData(3);
  lcd.address(b,0);
  lcd.writeData(4);
  lcd.address(c,1);
  lcd.writeData(5);
  lcd.address(c,0);
  lcd.writeData(6);
  wait_ms(x);
  lcd.cls();
  lcd.createChar(1, slipE1);
  lcd.createChar(2, slipE2);
  lcd.createChar(3, slipE3);
  lcd.createChar(4, slipE4);
  lcd.createChar(5, slipE5);
  lcd.createChar(6, slipE6);
  lcd.address(a,1);
  lcd.writeData(1);
  lcd.address(a,0);
  lcd.writeData(2);
  lcd.address(b,1);
  lcd.writeData(3);
  lcd.address(b,0);
  lcd.writeData(4);
  lcd.address(c,1);
  lcd.writeData(5);
  lcd.address(c,0);
  lcd.writeData(6);
  wait_ms(x);
  lcd.createChar(1, slipF1);
  lcd.createChar(2, slipF2);
  lcd.createChar(3, slipF3);
  lcd.createChar(4, slipF4);
  lcd.createChar(5, slipF5);
  lcd.createChar(6, slipF6);
  lcd.address(a,1);
  lcd.writeData(1);
  lcd.address(a,0);
  lcd.writeData(2);
  lcd.address(b,1);
  lcd.writeData(3);
  lcd.address(b,0);
  lcd.writeData(4);
  lcd.address(c,1);
  lcd.writeData(5);
  lcd.address(c,0);
  lcd.writeData(6);
  wait_ms(x);
}