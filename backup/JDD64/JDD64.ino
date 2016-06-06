//NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
// Modified by CraigColeman  for an 8x8 neopixel 160120
int clearPix ();
int cwc ();
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//  8x8 array

void setup() {
  Serial.begin(9600);      //ser up Serial.*
  randomSeed(analogRead(0));
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  pixels.begin(); // This initializes the NeoPixel library.
}
//  main loop ***  Add functions here. *********************************************************
void loop() {
clearPix(); bat(); delay(3000);
clearPix(); cwc();  delay(3000);
clearPix(); jdd();  delay(3000);
clearPix(); kyleh(); delay(3000);
clearPix(); vam();  delay(3000);
clearPix(); nrc();  delay(3000);
clearPix(); BJG();  delay(3000);
clearPix(); jz();  delay(3000);
clearPix(); tony();  delay(3000);
}
//  end of main loop *********************************************************

//start clearPix() *********************************************************
int clearPix (){
  for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0)); 
    }
02    pixels.show();
  }
//end clearPix  *********************************************************

// start CWC *********************************************************
  int cwc(){
  int i, val, newhit, countColors, r,c,x,y;
  int done = 0;
  int red = 0, green = 0, blue = 0;
  int totalBombs = 0;
//change this array use 1 as the water
int m[8][8] = {  
    {1,2,2,1,1,1,1,1} ,
    {1,1,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {5,5,5,5,5,1,1,3} ,
    {1,1,1,1,1,1,1,3},
    {4,4,4,4,1,1,1,3}   
};
int s[8][8] = {  
    {0,0,0.0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0}
};
while(done == 0){
   i = 0;// set neo-pixel number to zero
  countColors = 0;;// set count colors to 0 to count bomb hits
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue using a switch statement
      // *********************************************************
      val = m[r][c];
      switch ( val ) {
          case -1://hit ship  (RED)
            red = 70; green = 0; blue = 0;
          break;
          case 0://hit water  (BLACK)
            red = 0; green = 0; blue = 0;
          break;
          case 1://water  (BLUE)
            red = 0; green = 0; blue =70;
          break;
           case 2://ships are 2,3,4, and 5
          red = 0; green = 50; blue =0;
          break;
            case 3:
          red = 50; green = 25; blue =0;
          break;
            case 4:
          red = 25; green = 50; blue =0;
          break;
          case 5:
          red =32; green = 32; blue =1;
          break;
          default:
          red = 0; green = 0; blue = 0;
          break;
    }//end switch
      // end of set the color *********************************************************
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
      pixels.show(); 
      i++;
       if(val > 1)countColors++;//count is a color is a boat
    }//end c
}//end r    
   if (countColors == 0){done = 1;}  // this check if all the boats were hit
 
//generate random numbers
  newhit =0;
  while((newhit == 0)&& (countColors != 0)){
    x= random(8);
    y = random(8);
    if( s[x][y]== 0){
        s[x][y] = 1;
        newhit = 1;
        totalBombs++;
    }
  }//end generating random numbers

    if ( m[x][y] == 1){  m[x][y] = 0;}  //set a hit to 0 when hitting water
    if ( m[x][y]> 1) { m[x][y] = -1;}  //set a hit to -1 whren hitting a boat
   
    }//end while
    Serial.print("cwc Total Bombs = ");  //type your intials here
    Serial.println(totalBombs);
 
}//end cwc *******************************************************************




// bat *******************************************************************
  int bat(){
  int i;
  int done = 0;
  int val;
  int newhit;  //  this will determine if there is a unigue shot
  int countColors;
  int x,y;
  int r,c;//row and column
  int red = 0, green = 0, blue = 0;
  int totalBombs = 0;
//change this array use 0 as the water
int m[8][8] = {  
        {1,2,2,2,1,1,1,1} ,
    {1,1,1,1,1,1,1,1} ,
    {5,5,5,5,5,1,1,1} ,
    {1,1,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,3} ,
    {1,3,1,1,1,1,1,3},
    {4,4,4,4,1,1,1,1}   
};
int s[8][8] = {  
    {0,0,0.0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0}
};
 
while(done == 0){
   i = 0;// set neo-pixel number to zero
  countColors = 0;;// check for no boats and water
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue
      // **************************************************************
      val = m[r][c];
      switch ( val ) {
              case -1://hit ship  (RED)
            red = 70; green = 0; blue = 0;
          break;
          case 0://hit water  (BLACK)
            red = 0; green = 0; blue = 0;
          break;
          case 1://water  (BLUE)
            red = 0; green = 0; blue =70;
          break;
           case 2://ships are 2,3,4, and 5  (customize the boat color)
          red = 0; green = 50; blue =0;
          break;
            case 3:
          red = 50; green = 25; blue =0;
          break;
            case 4:
          red = 25; green = 50; blue =0;
          break;
          case 5:
          red =32; green = 32; blue =1;
          break;
          default:
          red = 0; green = 0; blue = 0;
          break;
    }//end switch
      // end of set the color *************************************************
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
      pixels.show(); 
      i++;
       if(val > 1)countColors++;
    }//end c
}//end r    
   if (countColors == 0){done = 1;}
 
//generate random numbers
  newhit =0;
  while((newhit == 0)&& (countColors != 0)){
    x= random(8);
    y = random(8);
    if( s[x][y]== 0){
        s[x][y] = 1;
        newhit = 1;
        totalBombs++;
    }
  }//end while newhit

    if ( m[x][y] == 1){  m[x][y] = 0;}
    if ( m[x][y]> 1) { m[x][y] = -1;}
   
    }//end while
    Serial.print("bat Total Bombs = ");
    Serial.println(totalBombs);
 
}//end bat

// start kyleh *********************************************************
  int kyleh(){
  int i, val, newhit, countColors, r,c,x,y;
  int done = 0;
  int red = 0, green = 0, blue = 0;
  int totalBombs = 0;
//change this array use 1 as the water
int m[8][8] = {  
    {1,5,5,5,5,5,1,1} ,
    {1,1,1,1,1,1,1,1} ,
    {3,1,1,1,1,1,1,1} ,
    {3,1,1,2,2,1,1,1} ,
    {3,1,1,1,1,1,1,3} ,
    {1,1,1,1,1,1,1,3} ,
    {1,1,1,1,1,1,1,3},
    {4,4,4,4,1,1,1,1}   
};
int s[8][8] = {  
    {0,0,0.0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0}
};
while(done == 0){
   i = 0;// set neo-pixel number to zero
  countColors = 0;;// set count colors to 0 to count bomb hits
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue using a switch statement
      // *********************************************************
      val = m[r][c];
  switch ( val ) {
          case -1://hit ship  (RED)
            red = 70; green = 0; blue = 0;
          break;
          case 0://hit water  (BLACK)
            red = 0; green = 0; blue = 0;
          break;
          case 1://water  (BLUE)
            red = 0; green = 0; blue =70;
          break;
           case 2://ships are 2,3,4, and 5  (customize the boat color)
          red = 131; green = 131; blue =131;
          break;
            case 3:
          red = 131; green = 131; blue =131;
          break;
            case 4:
          red = 131; green = 131; blue =131;
          break;
          case 5:
          red =131; green = 131; blue =131;
          break;
          default:
          red = 0; green = 0; blue = 0;
          break;

    }//end switch
      // end of set the color *********************************************************
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
      pixels.show(); 
      i++;
       if(val > 1)countColors++;//count is a color is a boat
    }//end c
}//end r    
   if (countColors == 0){done = 1;}  // this check if all the boats were hit
 
//generate random numbers
  newhit =0;
  while((newhit == 0)&& (countColors != 0)){
    x= random(8);
    y = random(8);
    if( s[x][y]== 0){
        s[x][y] = 1;
        newhit = 1;
        totalBombs++;
    }
  }//end generating random numbers

    if ( m[x][y] == 1){  m[x][y] = 0;}  //set a hit to 0 when hitting water
    if ( m[x][y]> 1) { m[x][y] = -1;}  //set a hit to -1 whren hitting a boat
   
    }//end while
    Serial.print("kyleh Total Bombs = ");  //type your intials here
    Serial.println(totalBombs);
 
}//end kyleh *******************************************************************
// start vam *********************************************************
  int vam(){
  int i, val, newhit, countColors, r,c,x,y;
  int done = 0;
  int red = 0, green = 0, blue = 0;
  int totalBombs = 0;
//change this array use 1 as the water
int m[8][8] = {  
    {1,5,5,5,5,5,1,1} ,
    {1,1,1,1,1,1,1,1} ,
    {1,3,1,1,2,2,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,4,4,4,4,1,1,3} ,
    {1,1,1,1,1,1,1,3},
    {1,1,1,1,1,1,1,3}    
};
int s[8][8] = {  
    {0,0,0.0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0}
};
while(done == 0){
   i = 0;// set neo-pixel number to zero
  countColors = 0;;// set count colors to 0 to count bomb hits
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue using a switch statement
      // *********************************************************
      val = m[r][c];
      switch ( val ) {
          case -1://hit ship  (RED)
            red = 70; green = 0; blue = 0;
          break;
          case 0://hit water  (BLACK)
            red = 0; green = 0; blue = 0;
          break;
          case 1://water  (BLUE)
            red = 0; green = 0; blue =70;
          break;
           case 2://ships are 2,3,4, and 5
          red = 25; green = 50; blue =0;
          break;
            case 3:
          red = 50; green = 25; blue =60;
          break;
            case 4:
          red = 15; green = 40; blue =22;
          break;
          case 5:
          red =32; green = 32; blue =1;
          break;
          default:
          red = 0; green = 0; blue = 0;
          break;
    }//end switch
      // end of set the color *********************************************************
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
      pixels.show(); 
      i++;
       if(val > 1)countColors++;//count is a color is a boat
    }//end c
}//end r    
   if (countColors == 0){done = 1;}  // this check if all the boats were hit
 
//generate random numbers
  newhit =0;
  while((newhit == 0)&& (countColors != 0)){
    x= random(8);
    y = random(8);
    if( s[x][y]== 0){
        s[x][y] = 1;
        newhit = 1;
        totalBombs++;
    }
  }//end generating random numbers

    if ( m[x][y] == 1){  m[x][y] = 0;}  //set a hit to 0 when hitting water
    if ( m[x][y]> 1) { m[x][y] = -1;}  //set a hit to -1 whren hitting a boat
   
    }//end while
    Serial.print("vam Total Bombs = ");  //type your intials here
    Serial.println(totalBombs);
 
}//end vam *******************************************************************

// start jdd *********************************************************
  int jdd(){
  int i, val, newhit, countColors, r,c,x,y;
  int done = 0;
  int red = 0, green = 0, blue = 0;
  int totalBombs = 0;
//change this array use 1 as the water
int m[8][8] = {  
    {3,3,3,1,1,1,1,1} ,
    {3,3,3,1,1,1,1,1} ,
    {1,1,1,5,1,1,4,1} ,
    {1,1,1,5,1,1,4,1} ,
    {1,1,1,5,1,1,4,1},
    {1,1,1,5,1,1,4,1} ,
    {1,1,1,5,1,1,1,1},
    {2,2,1,5,1,1,1,1}    
};
int s[8][8] = {  
    {0,0,0.0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0}
};
while(done == 0){
   i = 0;// set neo-pixel number to zero
  countColors = 0;;// set count colors to 0 to count bomb hits
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue using a switch statement
      // *********************************************************
      val = m[r][c];
      switch ( val ) {
          case -1://hit ship  (RED)
            red = 70; green = 0; blue = 0;
          break;
          case 0://hit water  (BLACK)
            red = 0; green = 0; blue = 0;
          break;
          case 1://water  (BLUE)
            red = 0; green = 0; blue =70;
          break;
           case 2://ships are 2,3,4, and 5
          red = 25; green = 50; blue =0;
          break;
            case 3:
          red = 50; green = 25; blue =60;
          break;
            case 4:
          red = 15; green = 40; blue =22;
          break;
          case 5:
          red =32; green = 32; blue =1;
          break;
          default:
          red = 0; green = 0; blue = 0;
          break;
    }//end switch
      // end of set the color *********************************************************
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
      pixels.show(); 
      i++;
       if(val > 1)countColors++;//count is a color is a boat
    }//end c
}//end r    
   if (countColors == 0){done = 1;}  // this check if all the boats were hit
 
//generate random numbers
  newhit =0;
  while((newhit == 0)&& (countColors != 0)){
    x= random(8);
    y = random(8);
    if( s[x][y]== 0){
        s[x][y] = 1;
        newhit = 1;
        totalBombs++;
    }
  }//end generating random numbers

    if ( m[x][y] == 1){  m[x][y] = 0;}  //set a hit to 0 when hitting water
    if ( m[x][y]> 1) { m[x][y] = -1;}  //set a hit to -1 whren hitting a boat
   
    }//end while
    Serial.print("jdd Total Bombs = ");  //type your intials here
    Serial.println(totalBombs);
 
}//end jdd *******************************************************************
// nrc *******************************************************************
  int nrc(){
  int i;
  int done = 0;
  int val;
  int newhit;  //  this will determine if there is a unigue shot
  int countColors;
  int x,y;
  int r,c;//row and column
  int red = 0, green = 0, blue = 0;
  int totalBombs = 0;
//change this array use 0 as the water
int m[8][8] = {  
  // ++++++++++++++++++++++++++++++++++++++++
    {1,2,2,1,1,1,1,1} ,
    {1,1,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {5,5,5,5,5,1,1,3} ,
    {1,1,1,1,1,1,1,3},
    {4,4,4,4,1,1,1,3}      
   // ++++++++++++++++++++++++++++++++++++++++
};
int s[8][8] = {  
    {0,0,0.0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0}
};
 
while(done == 0){
   i = 0;// set neo-pixel number to zero
  countColors = 0;;// check for no boats and water
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue
      // **************************************************************
      val = m[r][c];
      switch ( val ) {
          case -1://hit ship  (RED)
            red = 70; green = 0; blue = 0;
          break;
          case 0://hit water  (BLACK)
            red = 0; green = 0; blue = 0;
          break;
          case 1://water  (BLUE)
            red = 0; green = 0; blue =70;
          break;
           case 2://ships are 2,3,4, and 5  (customize the boat color)
          red = 0; green = 50; blue =0;
          break;
            case 3:
          red = 15; green = 15; blue =0;
          break;
            case 4:
          red = 22; green = 0; blue =17;
          break;
          case 5:
          red =22; green = 10; blue =0;
          break;
          default:
          red = 0; green = 0; blue = 0;
          break;
           // ++++++++++++++++++++++++++++++++++++++++
    }//end switch
      // end of set the color *************************************************
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
      pixels.show(); 
      i++;
       if(val > 1)countColors++;
    }//end c
}//end r    
   if (countColors == 0){done = 1;}
 
//generate random numbers
  newhit =0;
  while((newhit == 0)&& (countColors != 0)){
    x= random(8);
    y = random(8);
    if( s[x][y]== 0){
        s[x][y] = 1;
        newhit = 1;
        totalBombs++;
    }
  }//end while newhit

    if ( m[x][y] == 1){  m[x][y] = 0;}
    if ( m[x][y]> 1) { m[x][y] = -1;}
   
    }//end while
    Serial.print("nrc Total Bombs = ");
    Serial.println(totalBombs);
 
}//end nrc
// BJG *******************************************************************
  int BJG(){
  int i;
  int done = 0;
  int val;
  int newhit;  //  this will determine if there is a unigue shot
  int countColors;
  int x,y;
  int r,c;//row and column
  int red = 0, green = 0, blue = 0;
  int totalBombs = 0;
//change this array use 0 as the water
int m[8][8] = {  
  // ++++++++++++++++++++++++++++++++++++++++
    {1,2,2,1,1,1,1,1} ,
    {1,1,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {5,5,5,5,5,1,1,3} ,
    {1,1,1,1,1,1,1,3},
    {4,4,4,4,1,1,1,3}      
   // ++++++++++++++++++++++++++++++++++++++++
};
int s[8][8] = {  
    {0,0,0.0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0}
};
 
while(done == 0){
   i = 0;// set neo-pixel number to zero
  countColors = 0;;// check for no boats and water
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue
      // **************************************************************
      val = m[r][c];
      switch ( val ) {
          case -1://hit ship  (RED)
            red = 70; green = 0; blue = 0;
          break;
          case 0://hit water  (BLACK)
            red = 0; green = 0; blue = 0;
          break;
          case 1://water  (BLUE)
            red = 0; green = 0; blue =70;
          break;
           case 2://ships are 2,3,4, and 5
          red = 0; green = 50; blue =0;
          break;
            case 3:
          red = 50; green = 25; blue =0;
          break;
            case 4:
          red = 25; green = 50; blue =0;
          break;
          case 5:
          red =32; green = 32; blue =1;
          break;
          default:
          red = 0; green = 0; blue = 0;
          break;
           // ++++++++++++++++++++++++++++++++++++++++
    }//end switch
      // end of set the color *************************************************
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
      pixels.show(); 
      i++;
       if(val > 1)countColors++;
    }//end c
}//end r    
   if (countColors == 0){done = 1;}
 
//generate random numbers
  newhit =0;
  while((newhit == 0)&& (countColors != 0)){
    x= random(8);
    y = random(8);
    if( s[x][y]== 0){
        s[x][y] = 1;
        newhit = 1;
        totalBombs++;
    }
  }//end while newhit

    if ( m[x][y] == 1){  m[x][y] = 0;}
    if ( m[x][y]> 1) { m[x][y] = -1;}
   
    }//end while
    Serial.print("BJG Total Bombs = ");
    Serial.println(totalBombs);
 
}//end BJG

// jz *******************************************************************
  int jz(){
  int i;
  int done = 0;
  int val;
  int newhit;  //  this will determine if there is a unigue shot
  int countColors;
  int x,y;
  int r,c;//row and column
  int red = 0, green = 0, blue = 0;
  int totalBombs = 0;
//change this array use 0 as the water
int m[8][8] = {  
  // ++++++++++++++++++++++++++++++++++++++++
    {1,2,2,1,1,1,1,1} ,
    {1,1,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,3,1,1,1,1,1,1} ,
    {1,1,5,5,5,5,5,3} ,
    {1,1,1,1,1,1,1,3},
    {4,4,4,4,1,1,1,3}   
   // ++++++++++++++++++++++++++++++++++++++++
};
int s[8][8] = {  
    {0,0,0.0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0}
};
 
while(done == 0){
   i = 0;// set neo-pixel number to zero
  countColors = 0;;// check for no boats and water
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue
      // **************************************************************
      val = m[r][c];
      switch ( val ) {
          case -1://hit ship  (RED)
            red = 70; green = 0; blue = 0;
          break;
          case 0://hit water  (BLACK)
            red = 0; green = 0; blue = 0;
          break;
          case 1://water  (BLUE)
            red = 0; green = 0; blue =70;
          break;
           case 2://ships are 2,3,4, and 5
          red = 65; green = 50; blue =0;
          break;
            case 3:
          red = 0; green = 27; blue =4;
          break;
            case 4:
          red = 34; green = 52; blue =70;
          break;
          case 5:
          red =32; green = 32; blue =1;
          break;
          default:
          red = 0; green = 0; blue = 0;
          break;
           // ++++++++++++++++++++++++++++++++++++++++
    }//end switch
      // end of set the color *************************************************
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
      pixels.show(); 
      i++;
       if(val > 1)countColors++;
    }//end c
}//end r    
   if (countColors == 0){done = 1;}
 
//generate random numbers
  newhit =0;
  while((newhit == 0)&& (countColors != 0)){
    x= random(8);
    y = random(8);
    if( s[x][y]== 0){
        s[x][y] = 1;
        newhit = 1;
        totalBombs++;
    }
  }//end while newhit

    if ( m[x][y] == 1){  m[x][y] = 0;}
    if ( m[x][y]> 1) { m[x][y] = -1;}
   
    }//end while
    Serial.print("jz Total Bombs = ");
    Serial.println(totalBombs);
 
}//end jz
 // tony *******************************************************************
  int tony(){
  int i;
  int done = 0;
  int val;
  int newhit;  //  this will determine if there is a unigue shot
  int countColors;
  int x,y;
  int r,c;//row and column
  int red = 0, green = 0, blue = 0;
  int totalBombs = 0;
//change this array use 0 as the water
int m[8][8] = {  
  // ++++++++++++++++++++++++++++++++++++++++
    {1,1,1,1,1,1,1,5} ,
    {1,1,1,1,1,1,5,1} ,
    {3,1,2,2,1,5,1,1} ,
    {1,3,1,1,5,1,1,1} ,
    {1,1,3,5,4,1,1,1} ,
    {1,1,1,4,3,1,1,1} ,
    {1,1,4,1,1,3,1,1},
    {1,4,1,1,1,1,3,1}
   // ++++++++++++++++++++++++++++++++++++++++
};
int s[8][8] = {  
    {0,0,0.0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0}
};
 
while(done == 0){
   i = 0;// set neo-pixel number to zero
  countColors = 0;;// check for no boats and water
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue
      // **************************************************************
      val = m[r][c];
      switch ( val ) {
         case -1://hit ship  (RED)
           red = 70; green = 0; blue = 0;
         break;
         case 0://hit water  (BLACK)
           red = 0; green = 0; blue = 0;
         break;
         case 1://water  (BLUE)
           red = 0; green = 0; blue =70;
         break;
          case 2://ships are 2,3,4, and 5
         red = 50; green = 0; blue =25;
         break;
           case 3:
         red = 50; green = 25; blue =0;
         break;
           case 4:
         red = 25; green = 50; blue =0;
         break;
         case 5:
         red =32; green = 32; blue =1;
         break;
           // ++++++++++++++++++++++++++++++++++++++++
    }//end switch
      // end of set the color *************************************************
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
      pixels.show(); 
      i++;
       if(val > 1)countColors++;
    }//end c
}//end r    
   if (countColors == 0){done = 1;}
 
//generate random numbers
  newhit =0;
  while((newhit == 0)&& (countColors != 0)){
    x= random(8);
    y = random(8);
    if( s[x][y]== 0){
        s[x][y] = 1;
        newhit = 1;
        totalBombs++;
    }
  }//end while newhit

    if ( m[x][y] == 1){  m[x][y] = 0;}
    if ( m[x][y]> 1) { m[x][y] = -1;}
   
    }//end while
    Serial.print("tony Total Bombs = ");
    Serial.println(totalBombs);
 
}//end tony
 

