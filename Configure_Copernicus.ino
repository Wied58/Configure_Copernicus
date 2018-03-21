// This Sets the Copernicus to Air mode, sets the baud to 57600, and saves the new config to Flash. 


void setup() {
	Serial.begin(57600);
 // Serial1.begin(4800); // Trimble Factory Setting. 
  Serial1.begin(57600);
        
}

void loop() {
  
Serial.println("I am in the loopy");   
 
//SET TO AIR MODE

Serial1.println("$PTNLSCR,0.60,5.00,12.00,6.00,0.0000020,0,3,1,1*71"); 
for (int noodle = 1; noodle < 100; noodle++);   

while (Serial1.available())  {
	Serial.print(Serial1.read(), BYTE); 
	}

//SET BAUD 57600

Serial1.println("$PTNLSPT,057600,8,N,1,4,4*12"); 
for (int noodle = 1; noodle < 100; noodle++);

while (Serial1.available())  {
	Serial.print(Serial1.read(), BYTE); 
	}

//SET NMEA SENTANCES

Serial1.println("$PTNLSNM,0101,01*57");
for (int noodle = 1; noodle < 100; noodle++);

while (Serial1.available())  {
	Serial.print(Serial1.read(), BYTE); 
	}

//SET SENSITIVITY MODE

# Serial1.println("$PTNLSFS,H,0*38"); # For high sensitivity
Serial1.println("$PTNLSFS,S,0*23"); # For standard sensitivity
for (int noodle = 1; noodle < 100; noodle++);

while (Serial1.available())  {
	Serial.print(Serial1.read(), BYTE); 
	}

//WRITE TO MEMORY

Serial1.println("$PTNLSRT,H,2,,,*05"); 
for (int noodle = 1; noodle < 100; noodle++);

while (Serial1.available())  {
	Serial.print(Serial1.read(), BYTE); 
	}
 
delay(10000);
}
