#define DAC_CH1 25
#define DAC_CH1 26

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  dacWrite(DAC_CH1, 0);
  Serial.println("DAC Value 0");
  delay(5000);
  
  dacWrite(DAC_CH1, 64);
  Serial.println("DAC Value 64");
  delay(5000);
  
  dacWrite(DAC_CH1, 128);
  Serial.println("DAC Value 128");
  delay(5000);
  
  dacWrite(DAC_CH1, 192);
  Serial.println("DAC Value 192");
  delay(5000);
  
  dacWrite(DAC_CH1, 255);
  Serial.println("DAC Value 255");
  delay(5000);
}
