// Stepper Motor X
  const int stepPinX = 2; //X.STEP
  const int dirPinX = 5; // X.DIR

// Stepper Motor Y
  const int stepPinY = 3; //Y.STEP
  const int dirPinY = 6; //Y.DIR

// joystick
  int vrx = A0; 
  int vry = A1; 
  int vrx_data = 0; 
  int vry_data = 0; 

  int x = 0; 
  int y = 0;
  int SMSpeed = 500; // Stepper Motor Speed 

// SETUP
void setup() {
 // Sets the two pins as Outputs
 Serial.begin(9600); 
 // X related pin output
 pinMode(stepPinX,OUTPUT); 
 pinMode(dirPinX,OUTPUT);
 // Y related pin output
 pinMode(stepPinY,OUTPUT); 
 pinMode(dirPinY,OUTPUT);
 // input
 pinMode(vrx , INPUT); 
 pinMode(vry, INPUT); 
 }

 
 void loop() 
 {
  
joystick(); 

 }

// Function that handles the joystick input and moves the X and Y motors
 void joystick()
{
// BEGIN X 
vrx_data = analogRead(vrx);
Serial.print("Vrx:"); 
Serial.println(vrx_data); 


// to stop the stepper motor
if ( (vrx_data > 490)  &&   (vrx_data < 510)   )
{

;
  
}


if ( vrx_data > 700  )
{

digitalWrite(dirPinX,HIGH);
x = x + 1; 
 digitalWrite(stepPinX,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPinX,LOW); 
 delayMicroseconds(SMSpeed); 
  
}




if ( vrx_data < 300   )
{
digitalWrite(dirPinX,LOW);
x = x - 1; 

 digitalWrite(stepPinX,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPinX,LOW); 
 delayMicroseconds(SMSpeed);  
}
// END X

// BEGING Y
vry_data = analogRead(vry);
Serial.print("Vry:"); 
Serial.println(vry_data); 


// to stop the stepper motor
if ( (vry_data > 490)  &&   (vry_data < 510)   )
{

;
  
}


if ( vry_data > 700  )
{

digitalWrite(dirPinY,HIGH);
y = y + 1; 
 digitalWrite(stepPinY,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPinY,LOW); 
 delayMicroseconds(SMSpeed); 
  
}




if ( vry_data < 300   )
{
digitalWrite(dirPinY,LOW);
y = y - 1; 

 digitalWrite(stepPinY,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPinY,LOW); 
 delayMicroseconds(SMSpeed);  
}
// END Y
}
