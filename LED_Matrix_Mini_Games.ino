/*Marko Djordjevic    2016230098    
  Two minigames using 2x8 LED Matrix 

{0. 0. 0. 0. 0. 0. 0. 0.}
{0. 0. 0. 0. 0. 0. 0. 0.}

*/

// ALLOCATING ROWS TO PINS
#define ROW_4 2
#define ROW_5 3

// ALLOCATING COLUMNS TO PINS
#define COL_1 10
#define COL_2 11
#define COL_3 12
#define COL_4 13
#define COL_5 A0
#define COL_6 A1
#define COL_7 A2
#define COL_8 A3

//STORE ROWS AND COLUMNS IN SEPERATE ARRAYS
const byte rows[] = {
  ROW_4, ROW_5
  };
const byte col[] = {
  COL_1,COL_2,COL_3,COL_4,COL_5,COL_6,COL_7,COL_8
  };

//CREATING BALL WITH 7 FRAMES

byte LEFT[] = {B00000011,B00000011};//      {1. 1. 0. 0. 0. 0. 0. 0.}
//                                          {1. 1. 0. 0. 0. 0. 0. 0.}

byte BALL2[] = {B00000110,B00000110};//     {0. 1. 1. 0. 0. 0. 0. 0.}
//                                          {0. 1. 1. 0. 0. 0. 0. 0.}
                                          
byte BALL3[] = {B00001100,B00001100};//     {0. 0. 1. 1. 0. 0. 0. 0.}
//                                          {0. 0. 1. 1. 0. 0. 0. 0.}

byte BALL4[] = {B00011000,B00011000};//     {0. 0. 0. 1. 1. 0. 0. 0.}
//                                          {0. 0. 0. 1. 1. 0. 0. 0.}

byte BALL5[] = {B00110000,B00110000};//     {0. 0. 0. 0. 1. 1. 0. 0.}
//                                          {0. 0. 0. 0. 1. 1. 0. 0.}

byte BALL6[] = {B01100000,B01100000};//     {0. 0. 0. 0. 0. 1. 1. 0.}
//                                          {0. 0. 0. 0. 0. 1. 1. 0.}

byte RIGHT[] = {B11000000,B11000000};//     {0. 0. 0. 0. 0. 0. 1. 1.}
//                                          {0. 0. 0. 0. 0. 0. 1. 1.}


byte ALL[] = {B11111111,B11111111};
byte NONE[] = {B00000000,B00000000};

//CREATING DISPLAY FOR POINTS
byte CNT1[] = {B00000001,B00000000};//      {1. 0. 0. 0. 0. 0. 0. 0.}
//                                          {0. 0. 0. 0. 0. 0. 0. 0.}

byte CNT2[] = {B00000001,B00000010};//      {1. 0. 0. 0. 0. 0. 0. 0.}
//                                          {0. 1. 0. 0. 0. 0. 0. 0.}

byte CNT3[] = {B00000101,B00000010};//      {1. 0. 1. 0. 0. 0. 0. 0.}
//                                          {0. 1. 0. 0. 0. 0. 0. 0.}

byte CNT4[] = {B00000101,B00001010};//      {1. 0. 1. 0. 0. 0. 0. 0.}
//                                          {0. 1. 0. 1. 0. 0. 0. 0.}

byte CNT5[] = {B00010101,B00001010};//      {1. 0. 1. 0. 1. 0. 0. 0.}
//                                          {0. 1. 0. 1. 0. 0. 0. 0.}

byte CNT6[] = {B00010101,B00101010};//      {1. 0. 1. 0. 1. 0. 0. 0.}
//                                          {0. 1. 0. 1. 0. 1. 0. 0.}

byte CNT7[] = {B01010101,B00101010};//      {1. 0. 1. 0. 1. 0. 1. 0.}
//                                          {0. 1. 0. 1. 0. 1. 0. 0.}

byte CNT8[] = {B01010101,B10101010};//      {1. 0. 1. 0. 1. 0. 1. 0.}
//                                          {0. 1. 0. 1. 0. 1. 0. 1.}

// CREATING DISPLAY FOR EXPLOSION
byte EXP1[] = {B00100100,B00100100};//      {0. 0. 1. 0. 0. 1. 0. 0.}
//                                          {0. 0. 1. 0. 0. 1. 0. 0.}

byte EXP2[] = {B01000010,B01000010};//      {0. 1. 0. 0. 0. 0. 1. 0.}
//                                          {0. 1. 0. 0. 0. 0. 1. 0.}

byte EXP3[] = {B10000001,B10000001};//      {1. 0. 0. 0. 0. 0. 0. 1.}
//                                          {1. 0. 0. 0. 0. 0. 0. 1.}

byte EEXP1[] = {B00000001,B00000001};
byte EEXP2[] = {B00000010,B00000010};
byte EEXP3[] = {B00000100,B00000100};
byte EEXP4[] = {B00001000,B00001000};
byte EEXP5[] = {B00010000,B00010000};
byte EEXP6[] = {B00100000,B00100000};
byte EEXP7[] = {B01000000,B01000000};
byte EEXP8[] = {B10000000,B10000000};


// VARIABLES USED IN START PONG
int count = 0;
int timer = 0;
int trigger = 0;

// VARIABLES USED IN PING PONG 
int x = 110;
int trig = 0;
int counter = 0;

// VARIABLES USED IN HIT MIDDLE
float timeCount = 20;
int del = 5000;
int buttonCount = 0;

// VARIABLES SHARED
int buttonState = 0;
int prevState = 0;
int buttonPin1 = 4;


void setup() {
    Serial.begin(9600);
    // INITIALISING PINS FOR LED MATRIX
    for (byte i = 10; i <= 13; i++){
        pinMode(i, OUTPUT);
    }
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    
    // INITIALISING BUTTON
    pinMode(buttonPin1, INPUT);
}


void loop() {
  pingPong();
//  hitMiddle();
//  startPong();
}

// FUNCTION USED TO CREATE A BALL
void  drawScreen(byte buffer2[])
 { 
   // Turn on each row in series
    for (byte i = 0; i < 2; i++)        // count next row
     {
        digitalWrite(rows[i], HIGH);    //initiate whole row
        for (byte a = 0; a < 8; a++)    // count next row
        {
          digitalWrite(col[a], (buffer2[i] >> a) & 0x01); // initiate whole column          
          delayMicroseconds(200);          
          digitalWrite(col[a], 0);      // reset whole column
        }
        digitalWrite(rows[i], LOW);
        // reset whole row
    }
 }

//START PING PONG
void startPong(){   
  count++; 
  for (int j=0; j<3; j++){
    if(count<20){    
      for(int y=0; y<100; y++){//     {0. 1. 1. 0. 0. 0. 0. 0.}
        drawScreen(BALL2);//          {0. 1. 1. 0. 0. 0. 0. 0.}
      }
      }else if(count<40){
        for(int y=0; y<100; y++){//     {0. 0. 0. 0. 0. 0. 0. 0.}
          drawScreen(NONE);//           {0. 0. 0. 0. 0. 0. 0. 0.}    
        }
      }
      delay(500);
    }
    pingPong();
    trig = 1;
}
// FIRST GAME
void pingPong(){
  x = x - 10;       // Decrease the length of loops to increase the speed 
  counter = (100 - x)/10; // Counter is increased as x decreases
  if (x<11){ // Safety net to stop x from falling to 0
    x = 10;
  }
  
  if (trig == 0){ // If trigger has not been activated then run:
    for (int j=0; j<7; j++){
      buttonState = digitalRead(buttonPin1);
      switch(j){
        
      case 0:      
        for(int i=0; i<x; i++){//     {0. 1. 1. 0. 0. 0. 0. 0.}
          drawScreen(BALL2);//        {0. 1. 1. 0. 0. 0. 0. 0.}
        }
      break;
  
  
      case 1:
        if (buttonState == HIGH){
          explode();
          endGame(counter);  
        }else{
          for(int i=0; i<x; i++){//     {0. 0. 1. 1. 0. 0. 0. 0.}
            drawScreen(BALL3);//        {0. 0. 1. 1. 0. 0. 0. 0.}
          }
        }
      break;
  
  
      case 2:
        if (buttonState == HIGH){
          explode();
          endGame(counter); 
        }else{
          for(int i=0; i<x; i++){//     {0. 0. 0. 1. 1. 0. 0. 0.}
            drawScreen(BALL4);//        {0. 0. 0. 1. 1. 0. 0. 0.}
          }
        }
      break;
  
  
      case 3:
        if (buttonState == HIGH){
          explode();
          endGame(counter);  
        }else{
          for(int i=0; i<x; i++){//     {0. 0. 0. 0. 1. 1. 0. 0.}
            drawScreen(BALL5);//        {0. 0. 0. 0. 1. 1. 0. 0.}
          }
        }
      break;
  
  
      case 4:
        for(int i=0; i<x; i++){//       {0. 0. 0. 0. 0. 1. 1. 0.}
          drawScreen(BALL6);//          {0. 0. 0. 0. 0. 1. 1. 0.}
        }
      break;

  
      case 5:
        if (buttonState != HIGH){
          explodeLeft();
          endGame(counter); 
        }else{
          for(int i=0; i<x; i++){//     {0. 0. 0. 0. 0. 0. 1. 1.}
            drawScreen(RIGHT);//        {0. 0. 0. 0. 0. 0. 1. 1.}
          }
        }
      break;

  
      case 6:
        for(int i=0; i<x; i++){//       {0. 0. 0. 0. 0. 1. 1. 0.}
          drawScreen(BALL6);//          {0. 0. 0. 0. 0. 1. 1. 0.}
        }  
      break;
    } // END OF SWITCH
   } // END OF FOR-LOOP
  }else if (trig == 1){
    return;  
  }// END OF IF ELSE (TRIGGER) LOOP

 
  if (trig == 0){
    for (int j=0; j<5; j++){
      buttonState = digitalRead(buttonPin1);
      switch(j){
      
      case 0:
      if (buttonState == HIGH){
        explode();
        endGame(counter); 
      }else{
        for(int i=0; i<x; i++){//         {0. 0. 0. 0. 1. 1. 0. 0.}
            drawScreen(BALL5);//          {0. 0. 0. 0. 1. 1. 0. 0.}
        }
      }
      break;

  
      case 1:
      if (buttonState == HIGH){
        explode();
        endGame(counter);  
      }else{
        for(int i=0; i<x; i++){//       {0. 0. 0. 1. 1. 0. 0. 0.}
          drawScreen(BALL4);//          {0. 0. 0. 1. 1. 0. 0. 0.}
        }
      }
      break;

  
      case 2:
      if (buttonState == HIGH){
        explode();
        endGame(counter);     
      }else{
        for(int i=0; i<x; i++){//       {0. 0. 1. 1. 0. 0. 0. 0.}
          drawScreen(BALL3);//          {0. 0. 1. 1. 0. 0. 0. 0.}
        }
      }
      break;

  
      case 3:
      for(int i=0; i<x; i++){//         {0. 1. 1. 0. 0. 0. 0. 0.}
        drawScreen(BALL2);//            {0. 1. 1. 0. 0. 0. 0. 0.}
      }
      break;

  
      case 4:
      if (buttonState != HIGH){
        explodeRight();
        endGame(counter);
      }else{
        for(int i=0; i<x; i++){//       {1. 1. 0. 0. 0. 0. 0. 0.}
          drawScreen(LEFT);//           {1. 1. 0. 0. 0. 0. 0. 0.}
        }
      }   
      break;
      }// END OF SWITCH
    }// END OF FOR LOOP  
  }else{
    return;  
  }// END OF IF (TRIGGER) LOOP
}// END OF FUNCTION pingPong



// SECOND GAME
void hitMiddle(){
  buttonState = digitalRead(buttonPin1);
  timeCount++;
  delayMicroseconds(del); // del is originally set to 5000, decreases by 200 every 2 clicks
  buttonCount = (5000-del)/200; // counter that increases as del decreases
 
  if ((timeCount <  20) && (buttonState != HIGH)) 
  {
  drawScreen(LEFT);//                   {1. 1. 0. 0. 0. 0. 0. 0.}
  }//                                   {1. 1. 0. 0. 0. 0. 0. 0.}
  else if ((timeCount < 20) && (buttonState == HIGH))
  {
    timeCount = 300;
    explodeRight();
    endGame(buttonCount);  
  }
  else if (timeCount <  40) 
  {
    drawScreen(BALL2);//                {0. 1. 1. 0. 0. 0. 0. 0.}
  }//                                   {0. 1. 1. 0. 0. 0. 0. 0.}
  
  else if (timeCount <  60) 
  {
    drawScreen(BALL3);//                {0. 0. 1. 1. 0. 0. 0. 0.}
  }//                                   {0. 0. 1. 1. 0. 0. 0. 0.}
  
  else if ((timeCount <  80) && (buttonState == HIGH))
  {
    drawScreen(BALL4);//                {0. 0. 0. 1. 1. 0. 0. 0.}
  }//                                   {0. 0. 0. 1. 1. 0. 0. 0.}
  
  else if ((timeCount < 80) && (buttonState == LOW))
  {
    timeCount = 300;
    explode();
    endGame(buttonCount);  
  } 
  else if (timeCount <  100) 
  {
    drawScreen(BALL5);//                {0. 0. 0. 0. 1. 1. 0. 0.}
  }//                                   {0. 0. 0. 0. 1. 1. 0. 0.}
  
  else if ((timeCount <  120) )
  {
    drawScreen(BALL6);//                {0. 0. 0. 0. 0. 1. 1. 0.}
  }//                                   {0. 0. 0. 0. 0. 1. 1. 0.}
  
  else if ((timeCount < 140) && (buttonState != HIGH))
  {
    drawScreen(RIGHT);//                {0. 0. 0. 0. 0. 0. 1. 1.} 
  }//                                   {0. 0. 0. 0. 0. 0. 1. 1.}
  
  else if ((timeCount < 140) && (buttonState == HIGH))
  {
    timeCount = 300;
    explodeLeft();
    endGame(buttonCount); 
  }
  else if (timeCount < 160)
  {
    drawScreen(BALL6);//                {0. 0. 0. 0. 0. 1. 1. 0.}  
  }//                                   {0. 0. 0. 0. 0. 1. 1. 0.}
  
  else if (timeCount < 180)
  {
    drawScreen(BALL5);//                {0. 0. 0. 0. 1. 1. 0. 0.}
  }//                                   {0. 0. 0. 0. 1. 1. 0. 0.}
  
  else if((timeCount < 200) && (buttonState == HIGH))
  {
    drawScreen(BALL4);//                {0. 0. 0. 1. 1. 0. 0. 0.}
  }//                                   {0. 0. 0. 1. 1. 0. 0. 0.}
  
  else if ((timeCount < 200) && (buttonState == LOW))
  {
    timeCount = 300;
    explode();
    endGame(buttonCount);  
  }
  else if(timeCount < 220)
  {
    drawScreen(BALL3);//                {0. 0. 1. 1. 0. 0. 0. 0.}
  }//                                   {0. 0. 1. 1. 0. 0. 0. 0.}
  
  else if(timeCount < 240)
  {
    drawScreen(BALL2);//                {0. 1. 1. 0. 0. 0. 0. 0.}
  }//                                   {0. 1. 1. 0. 0. 0. 0. 0.}
  
   else if((timeCount < 260) && (buttonState != HIGH))
  {
    drawScreen(LEFT);//                 {1. 1. 0. 0. 0. 0. 0. 0.}
  }//                                   {1. 1. 0. 0. 0. 0. 0. 0.}
  
  else if((timeCount < 260) && (buttonState == HIGH))
  {
    timeCount = 300;
    explodeRight();
    endGame(buttonCount);  
  }
  else if (timeCount < 280)
  {
    timeCount = 20;
    del = del - 200;
    if (del <= 100){
      del = 100;  
    }
  } 
}

// FUNCTION TO DISPLAY TOTAL POINTS EARNED
byte endGame(int count){  
  for(int g=0; g<count; g++){
    delay(10);
    switch(g){
    case 0:
      for(int i=0; i<250; i++){
        drawScreen(CNT1);  
      }
    break;


    case 1:
      for(int i=0; i<250; i++){
        drawScreen(CNT2);  
      }
    break;


    case 2:
      for(int i=0; i<250; i++){
        drawScreen(CNT3);  
      }
    break;


    case 3:
      for(int i=0; i<250; i++){
        drawScreen(CNT4);  
      }
    break;


    case 4:
      for(int i=0; i<250; i++){
        drawScreen(CNT5);  
      }
    break;


    case 5:
      for(int i=0; i<250; i++){
        drawScreen(CNT6);  
      }
    break;


    case 6:
      for(int i=0; i<250; i++){
        drawScreen(CNT7);  
      }
    break;

    case 7:
      for(int i=0; i<250; i++){
        drawScreen(CNT8);  
      }
    break;

    case 8:
      for (int h=0; h < 4; h++){
        for(int i=0; i<100; i++){
          drawScreen(ALL);
        }
        for(int i=0; i<100; i++){
          drawScreen(NONE);
        }
      }
    break;
    } 
  }
  trig = 1;
}

void explode(){
  for (int j=0; j<4; j++){
    delay(50);
    switch(j){
      case 0:
        for (int i=0; i<120; i++){
          drawScreen(BALL4);  
        }
      break;

      case 1:
        for (int i=0; i<100; i++){
            drawScreen(EXP1);  
        }
      break;

      case 2:
        for (int i=0; i<100; i++){
          drawScreen(EXP2);  
        }
      break;

      case 3:
        for (int i=0; i<100; i++){
          drawScreen(EXP3);  
        }
      break;
    }
  }  
}


void explodeRight(){
  for (int j=0; j<8; j++){
//    delay(50);
    switch(j){
      case 0:
        for (int i=0; i<75; i++){
          drawScreen(EEXP1);  
        }
      break;

      case 1:
        for (int i=0; i<75; i++){
            drawScreen(EEXP2);  
        }
      break;

      case 2:
        for (int i=0; i<75; i++){
          drawScreen(EEXP3);  
        }
      break;

      case 3:
        for (int i=0; i<75; i++){
          drawScreen(EEXP4);  
        }
      break;

      case 4:
        for (int i=0; i<75; i++){
          drawScreen(EEXP5);  
        }
      break;

      case 5:
        for (int i=0; i<75; i++){
          drawScreen(EEXP6);  
        }
      break;

      case 6:
        for (int i=0; i<75; i++){
          drawScreen(EEXP7);  
        }
      break;
      
      case 7:
        for (int i=0; i<75; i++){
          drawScreen(EEXP8);
        }
      break;
    }
  }  
}


void explodeLeft(){
  for (int j=0; j<8; j++){
//    delay(50);
    switch(j){
      case 0:
        for (int i=0; i<75; i++){
          drawScreen(EEXP8);  
        }
      break;

      case 1:
        for (int i=0; i<75; i++){
            drawScreen(EEXP7);  
        }
      break;

      case 2:
        for (int i=0; i<75; i++){
          drawScreen(EEXP6);  
        }
      break;

      case 3:
        for (int i=0; i<75; i++){
          drawScreen(EEXP5);  
        }
      break;

      case 4:
        for (int i=0; i<75; i++){
          drawScreen(EEXP4);  
        }
      break;

      case 5:
        for (int i=0; i<75; i++){
          drawScreen(EEXP3);  
        }
      break;

      case 6:
        for (int i=0; i<75; i++){
          drawScreen(EEXP2);  
        }
      break;
      
      case 7:
        for (int i=0; i<75; i++){
          drawScreen(EEXP1);
        }
      break;
    }
  }  


}
