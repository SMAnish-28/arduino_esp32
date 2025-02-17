//  ESP32 WiFi HostName Change Example

#include <WiFi.h>
 
// Replace with your own network credentials
const char* ssid = "yourNetworkSSID";
const char* password = "yourNetworkPassword";
const char* MyHostName = "ESP32-Test";
 
void setup(){
    Serial.begin(115200);
    WiFi.setHostname(MyHostName);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting to WiFi Network ..");
    // Wait until connection is established
    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(100);
    }
    // Print ESP32's IP & HostName
    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("ESP32 HostName: ");
    Serial.println(WiFi.getHostname());
}
 
void loop(){
    // Do Nothing
}