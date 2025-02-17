#include "WiFi.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Scan start");
  int n = WiFi.scanNetworks(); // returns the number of networks found
  Serial.println("Scan done");
  if(n == 0){
    Serial.println("No Networks found!");
  }
  else{
    Serial.print(n);
    Serial.println(" networks found.");
    Serial.println("Nr | SSID                         | RSSI | CH | Encryption");
    for(int i = 0; i < n; i++){
      // Print SSID and RSSI for each network found
      Serial.printf("%2d", i+1);
      Serial.print("  | ");
      Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
      Serial.print("  | ");
      Serial.printf("%4d", WiFi.RSSI(i));
      Serial.print("  | ");
      Serial.printf("%2d", WiFi.channel(i));
      Serial.print("  | ");
      switch(WiFi.encryptionType(i)){
        case WIFI_AUTH_OPEN:
          Serial.print("open");
          break;
        case WIFI_AUTH_WEP:
          Serial.print("WEP");
          break;
        case WIFI_AUTH_WPA_PSK:
          Serial.print("WPA");
          break;
        case WIFI_AUTH_WPA2_PSK:
          Serial.print("WPA2");
          break;
        case WIFI_AUTH_WPA_WPA2_PSK:
          Serial.print("WPA+WPA2");
          break;
        case WIFI_AUTH_WPA2_ENTERPRISE:
          Serial.print("WPA2-EAP");
          break;
        case WIFI_AUTH_WPA3_PSK:
          Serial.print("WPA3");
          break;
        case WIFI_AUTH_WPA2_WPA3_PSK:
          Serial.print("WPA2+WPA3");
          break;
        case WIFI_AUTH_WAPI_PSK:
          Serial.print("WAPI");
          break;
        default:
          Serial.print("unknown");
      }
      Serial.println();
      delay(10);
    }
  }
  Serial.println("");

  WiFi.scanDelete();

  delay(5000);
}