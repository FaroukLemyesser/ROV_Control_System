#include <PS2X_lib.h>  //for v1.6, by Bill Porter

#define PS2_DAT        13  //14    
#define PS2_CMD        11  //15
#define PS2_SEL        10  //16
#define PS2_CLK        12  //17

#define pressures   true
//#define pressures   false
#define rumble      true
//#define rumble      false

PS2X ps2x; // create PS2 Controller Class

bool StateO = false; 
bool StateX = false; 
bool StateT = false; 
bool StateQ = false;  

int error = 0;
byte type = 0;
byte vibrate = 0;


char mystr ; //String data
char nostr ; 

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  delay(300); 
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);

}

void loop() {
  if(error == 1) 
    return; 
  else { 
    ps2x.read_gamepad(true, vibrate);
   
    }
    if(ps2x.Button(PSB_PAD_UP)) {      
      mystr = 'U' ;
    }
    else if(ps2x.ButtonReleased(PSB_PAD_UP)) {      
      mystr = 'u' ;
      }
    
    if(ps2x.Button(PSB_PAD_DOWN)){
      mystr = 'D' ;
    } else if(ps2x.ButtonReleased(PSB_PAD_DOWN)){
      mystr = 'd' ;
    }    
    if(ps2x.Button(PSB_PAD_RIGHT)){
      mystr = 'R' ;
    } else if(ps2x.ButtonReleased(PSB_PAD_RIGHT)){
      mystr = 'r' ;
    }
    if(ps2x.Button(PSB_PAD_LEFT)){
      mystr = 'L' ;
    } else if(ps2x.ButtonReleased(PSB_PAD_LEFT)){
      mystr = 'l' ;
    }
    if (mystr != nostr) {
      Serial.write(mystr);
      mystr = nostr;
    }
  delay(50);
}
