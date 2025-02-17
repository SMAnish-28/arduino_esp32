#define DAC_CH1 25
#define DAC_CH1 26

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int deg = 0; deg < 360; deg++){
    dacWrite(DAC_CH1, int(128 + 64 * sin(deg * PI / 180)));
  }
}
