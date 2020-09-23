int analogPin = 0;//send to A0
int raw = 0;//used to store the initial input voltage values
int Vin = 5; //input voltage
float Vout = 0; //ground voltage
float R1 = 10000;//Known resistor value
float R2 = 0;//used to store determined resistance
float buffer = 0;//used to store the intermediate calculated values

void setup(){
  Serial.begin(9600);//transfer rate
}

void loop(){
  raw = analogRead(analogPin);
  if(raw){
    buffer = raw * Vin;//scale the voltage to the input voltage
    Vout = (buffer)/1024.0;//remove the 12 bit scaling
    buffer = (Vin/Vout) - 1;
    R2= R1 * buffer;
    Serial.print("Vout: ");
    Serial.println(Vout);
    Serial.print("R2: ");
    Serial.println(R2);
    delay(500);
  }
}