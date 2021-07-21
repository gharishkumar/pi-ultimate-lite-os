#include <IRremote.h>
//FFE21D LEFT
//FF02FD RIGHT
//FF609F UP
//FF22DD DOWN
//FFE01F ENTER
//FF7A85 BACK

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

uint8_t buf[8] = { 
  0 }; 	/* Keyboard report buffer */

int state = 0;

void setup() 
{
  Serial.begin(9600); 
  irrecv.enableIRIn(); // Start the receiver
  delay(200);
  releaseKey();
}
void loop() 
{
    if (irrecv.decode(&results)) 
    {
      if (results.value == 0xFFE01F){
        buf[2] = 40;    //ENTER
        Serial.write(buf, 8); // Send keypress
        releaseKey();
        }
      if (results.value == 0xFFE21D){
        buf[2] = 80;    //LEFT
        Serial.write(buf, 8); // Send keypress
        releaseKey();
        }
      if (results.value == 0xFF02FD){
        buf[2] = 79;    //RIGTH
        Serial.write(buf, 8); // Send keypress
        releaseKey();
        }
      if (results.value == 0xFF609F){
        buf[2] = 75;    //UP
        Serial.write(buf, 8); // Send keypress
        releaseKey();
        }
      if (results.value == 0xFF22DD){
        buf[2] = 78;    //DOWN
        Serial.write(buf, 8); // Send keypress
        releaseKey();
        }
      if(results.value == 0xFF7A85){
        buf[2] = 42;    //back
        Serial.write(buf, 8); // Send keypress
        releaseKey();
      }
    //Serial.println(results.value, HEX);   // DON'T UNCOMMENT THIS DUE TO ALOT OF DISTORTION
     irrecv.resume(); // Receive the next value
    }
  
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key 
 // delay(50); 
}
