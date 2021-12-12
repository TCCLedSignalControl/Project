
#define VRx A2
#define VRy A1

void setup() {
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  Serial.begin(38400); 
}

void loop(){
  int vVRx = analogRead(VRx);
  int vVRy = analogRead(VRy);
  delay(2000);
  if(vVRx < 200)
    //right
    Serial.write('R');
  else if(vVRx > 800)
    //left
    Serial.write('L');
  else if(vVRy < 200)
    //middle
    Serial.write('M');
}
