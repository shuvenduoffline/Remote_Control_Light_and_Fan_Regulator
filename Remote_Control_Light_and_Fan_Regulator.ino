#include <IRremote.h>
const int RECV_PIN=0;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define led 9
#define sw1 3
#define sw2 1
#define sw3 12
#define sw4 13
int seg_a = 11; // declare the variables
int seg_b = 10;
int seg_c = 2;
int seg_d = 8;
int seg_e = 7;
int seg_f = 6;
int seg_g = 5;
int seg_dp = 4;
int seed=9;
bool j=false;
bool k=false;
bool l=false;
bool m=false;
bool n=false;
void mydisplay(int);
void myspeed(int);

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sw1, OUTPUT);
  pinMode(sw2, OUTPUT);
  pinMode(sw3, OUTPUT);
  pinMode(sw4, OUTPUT);
  pinMode(seg_a,OUTPUT); // configure all pins used to outputs
  pinMode(seg_b,OUTPUT);
  pinMode(seg_c,OUTPUT);
  pinMode(seg_d,OUTPUT);
  pinMode(seg_e,OUTPUT);
  pinMode(seg_f,OUTPUT);
  pinMode(seg_g,OUTPUT);
  pinMode(seg_dp,OUTPUT);
 // pinMode(com,OUTPUT);
  irrecv.enableIRIn();
  irrecv.blink13(true);
 
}
void loop() 
{
  if (irrecv.decode(&results)) 
   {
     Serial.println(results.value,HEX);
     delay(100);
     /////////////////////////for sw1
     if(results.value==0x1FE50AF)
     {
        j=!j;
        digitalWrite(sw1, j);
        
     }
      /////////////////////////for sw2
     if(results.value==0x1FED827)
     {
        k=!k;
        digitalWrite(sw2, k);
        
     }
      /////////////////////////for sw3
     if(results.value==0x1FEF807)
     {
        l=!l;
        digitalWrite(sw3, l);
        
     }
           /////////////////////////for sw4
     if(results.value==0x1FE30CF)
     {
        m=!m;
        digitalWrite(sw4, m);
        
     }//FOR TOTAL ON/OFF
     if(results.value==0x1FE48B7)
     {
        n=!n;
        digitalWrite(sw1, n);
        digitalWrite(sw2, n);
        digitalWrite(sw3, n);
        digitalWrite(sw4, n);
        
       // delay(200);
     }
     ///////////////////////
     if(results.value==0x1FE609F)
     {
        if(seed<9)
        {seed++;
        mydisplay(seed);
        myspeed(seed); }
        else
         mydisplay(10);

        
        
     }
     ////////////////////////
     if(results.value==0x1FEA05F)
     {
       if(seed>0){ seed--;
       mydisplay(seed);
       myspeed(seed); }
       else
        mydisplay(11);
        
       // delay(200);
     }
   
     
     irrecv.resume(); // Receive the next value
     //delay(100);
   }
}
void myspeed(int i)
{
   switch(i){ // switch statemet to select the number 
  
  case 0: // set output pin 0
  analogWrite(led, 0);
  break;

  case 1:
  analogWrite(led, 32);
  break;

  case 2:
  analogWrite(led, 64);
  break;

  case 3:
 analogWrite(led, 96);
  break;

  case 4:
  analogWrite(led, 128);
  break;

  case 5:
  analogWrite(led, 150);
  break;

  case 6:
 analogWrite(led, 182);
  break;

  case 7:
 analogWrite(led, 214);
  break;

  case 8:
  analogWrite(led, 246);
  break;

  case 9:
  analogWrite(led, 255);
  break;

 }
}
void mydisplay(int i)
{
  //digitalWrite(com,LOW); 
   switch(i){ // switch statemet to select the number 
  
  case 0: // set relevent segments HIGH and others LOW
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,HIGH);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,HIGH);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,LOW);
  digitalWrite(seg_dp,LOW);
 delay(1000);
//CODE FOR L
  digitalWrite(seg_a,LOW);
  digitalWrite(seg_b,LOW);
  digitalWrite(seg_c,LOW);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,HIGH);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,LOW);
  digitalWrite(seg_dp,HIGH);
  break;

  case 1: //CODE FOR 1
  digitalWrite(seg_a,LOW);
  digitalWrite(seg_b,HIGH);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,LOW);
  digitalWrite(seg_e,LOW);
  digitalWrite(seg_f,LOW);
  digitalWrite(seg_g,LOW);
  digitalWrite(seg_dp,LOW);
  break;

  case 2:
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,HIGH);
  digitalWrite(seg_c,LOW);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,HIGH);
  digitalWrite(seg_f,LOW);
  digitalWrite(seg_g,HIGH);
  digitalWrite(seg_dp,LOW);
  break;

  case 3:
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,HIGH);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,LOW);
  digitalWrite(seg_f,LOW);
  digitalWrite(seg_g,HIGH);
  digitalWrite(seg_dp,LOW);
  break;

  case 4:
  digitalWrite(seg_a,LOW);
  digitalWrite(seg_b,HIGH);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,LOW);
  digitalWrite(seg_e,LOW);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,HIGH);
  digitalWrite(seg_dp,LOW);
  break;

  case 5:
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,LOW);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,LOW);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,HIGH);
  digitalWrite(seg_dp,LOW);
  break;

  case 6:
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,LOW);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,HIGH);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,HIGH);
  digitalWrite(seg_dp,LOW);
  break;

  case 7:
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,HIGH);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,LOW);
  digitalWrite(seg_e,LOW);
  digitalWrite(seg_f,LOW);
  digitalWrite(seg_g,LOW);
  digitalWrite(seg_dp,LOW);
  break;

  case 8:
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,HIGH);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,HIGH);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,HIGH);
  digitalWrite(seg_dp,LOW);
  break;

  case 9:
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,HIGH);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,LOW);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,HIGH);
  digitalWrite(seg_dp,LOW);

delay(1000);
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,LOW);
  digitalWrite(seg_c,LOW);
  digitalWrite(seg_d,LOW);
  digitalWrite(seg_e,HIGH);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,HIGH);
  digitalWrite(seg_dp,HIGH);
  break;
  
    case 10:
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,LOW);
  digitalWrite(seg_c,LOW);
  digitalWrite(seg_d,LOW);
  digitalWrite(seg_e,HIGH);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,HIGH);
  digitalWrite(seg_dp,HIGH);

delay(1000);
    digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,HIGH);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,LOW);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,HIGH);
  digitalWrite(seg_dp,LOW);
  break;
  case 11: //code for L
   digitalWrite(seg_a,LOW);
  digitalWrite(seg_b,LOW);
  digitalWrite(seg_c,LOW);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,HIGH);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,LOW);
  digitalWrite(seg_dp,HIGH);
  delay(1000);//CODE FOR O
  digitalWrite(seg_a,HIGH);
  digitalWrite(seg_b,HIGH);
  digitalWrite(seg_c,HIGH);
  digitalWrite(seg_d,HIGH);
  digitalWrite(seg_e,HIGH);
  digitalWrite(seg_f,HIGH);
  digitalWrite(seg_g,LOW);
  digitalWrite(seg_dp,LOW);
  
  
  

 }
}

