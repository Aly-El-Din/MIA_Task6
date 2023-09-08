#define pinEncoderA 6
#define pinEncoderB 7
long long counter=0;
int angle=0;
void setup(){
  pinMode(pinEncoderA, INPUT_PULLUP);
  pinMode(pinEncoderB, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(pinEncoderA, ISR_rotateClockWise, CHANGE);
  attachInterrupt(pinEncoderB, ISR_rotateAntiClockWise, CHANGE);
  	
}
void loop(){
	angle=(int)counter*(-1.8);
  Serial.println(angle);
}

void ISR_rotateClockWise(void){
	if(digitalRead(pinEncoderA)!=digitalRead(pinEncoderB))
      counter++;
  else
      counter--;
    //clockwise
}
  
 void ISR_rotateAntiClockWise(void){
 	if(digitalRead(pinEncoderA)== digitalRead(pinEncoderB))
      counter++;
   	else
      counter--;
   //counter clock wise

}
  /*change-->on change we check once in rising and in falling in each 
  of A and B, which means that we check 4 times per pulse hence we
  increases resolution as if we choose to make our parameter is
  rising or falling--> we will work with half of the resolution
  */
  