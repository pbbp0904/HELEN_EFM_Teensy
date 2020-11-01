int i = 0;
unsigned long time = 0;
bool flag = HIGH;
int j = 245;
int startup = 40;
float startup_period = 100;
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(115200);
  pinMode(23, OUTPUT); //PWM PIN 10  with white line
  analogWrite(23, j);//input speed (must be int)
  pinMode(22, OUTPUT);//direction control PIN 11 with blue line
  pinMode(21, INPUT);
 
}


void loop() {
  /*
  if (Serial.available())  {
    j = Serial.parseInt();
    analogWrite(23, j);//input speed (must be int)
    Serial.println(j);
    j = Serial.parseInt();
    j = Serial.parseInt();
    j = Serial.parseInt();
  }*/
 
  for(int k = 0;k<8;k++)  {
    i += pulseIn(21, HIGH, 500000); //SIGNAL OUTPUT PIN 9 with  white line,cycle = 2*i,1s = 1000000usSignal cycle pulse number27*2
  }
 
  i = i >> 3;
  if (startup < startup_period) {
    startup = startup + 1;
  }

  if (111111 / i > 120*startup/startup_period) {
    j = min(j + 1, 255);
    analogWrite(23, j);//input speed (must be int)
  }
  if (111111 / i < 120*startup/startup_period) {
    j = max(j - 1, 0);
    analogWrite(23, j);//input speed (must be int)
  }
  i = 0;
}
