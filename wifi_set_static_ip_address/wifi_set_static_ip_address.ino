void setup() {
  // put your setup code here, to run once:
  IPAddress local_IP(192, 168, 1, x); // Your Desired Static IP Address
  IPAddress subnet(255, 255, 255, 0);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress primaryDNS(192, 168, 1, 1); // Not Mandatory
  IPAddress secondaryDNS(0, 0, 0, 0);   // Not Mandatory

  // Configures Static IP Address
   if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS))
   {
       Serial.println("Configuration Failed!");
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}
