char mystr; //Initialized variable to store recieved data
char nostr;

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  mystr = Serial.read(); //Read the serial data and store in var
  if (mystr != nostr) {
    Serial.println(mystr); //Print data on Serial Monitor
    mystr = nostr;
  }
  delay(50);
}
