#include <DacESP32.h>

// Create DAC object
DacESP32 dac1(GPIO_NUM_25);

void setup(){
  // Output a Cosine wave with frequency of 1KHz and max. amplitude (default)
  dac1.outputCW(1000);

  delay(5000);
}

void loop(){
  for(int i = 0; i < 4; i++){
    delay(1000);
    if(i == 0)  dac1.setCwScale(DAC_CW_SCALE_1);
    else if(i == 1)  dac1.setCwScale(DAC_CW_SCALE_2);
    else if(i == 2)  dac1.setCwScale(DAC_CW_SCALE_4);
    else if(i == 3)  dac1.setCwScale(DAC_CW_SCALE_8);
  }
}