


int currentPIRposition = 0; 


int currentLEDpin = 9; 
int PIRpin[] = {2,3,4,5,6}; 
int currentPIRpin = 2;
int PIRprevState[] = {1,1,1,1,1}; 
int PIRposition[] = {157,117.75,78.5,39.25,0}; 
boolean PIRstatus; 


void setup()  {
  
  Serial.begin(9600);
  
  
  for (int p = 0; p < 5; p++)  { 
  pinMode(PIRpin[p], INPUT);
    } 
    
  for (int l = 0; l < 5; l++)  { 
 
    } 
  
  
  
    for(int c = 0; c < 15; c++){ 
      Serial.print(".");
      delay(1000); // wait 1 second
      } // end calibration for
    
  
   
  } 




void loop()  {
  
  for (int PIR = 0; PIR < 5; PIR++) { 
    currentPIRpin = PIRpin[PIR];
  
    PIRstatus = digitalRead(currentPIRpin);
    
    if (PIRstatus == HIGH) { 
    
      if(PIRprevState[PIR] == 0) { 
        if (currentPIRposition != currentPIRpin && PIRprevState[PIR] == 0) { 
        
          Serial.print("Current angle : ");
          Serial.println(PIRposition[PIR]);
          delay(50);
          currentPIRposition = currentPIRpin; 
          PIRprevState[PIR] = 1; 
          }
        PIRprevState[PIR] = 1; 
        } 
      } 
    
    else  { 
      digitalWrite(currentLEDpin, LOW); 
      PIRprevState[PIR] = 0;  
      } 
      
    } 
  } 
