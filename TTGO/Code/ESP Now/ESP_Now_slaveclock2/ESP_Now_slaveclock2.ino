/**
   ESPNOW - Basic communication - Slave
   Date: 26th September 2017
   Author: Arvind Ravulavaru <https://github.com/arvindr21>
   Purpose: ESPNow Communication between a Master ESP32 and multiple ESP32 Slaves
   Description: This sketch consists of the code for the Slave module.
   Resources: (A bit outdated)
   a. https://espressif.com/sites/default/files/documentation/esp-now_user_guide_en.pdf
   b. http://www.esploradores.com/practica-6-conexion-esp-now/

    * Board:   Wemos Wifi&Bluetooth Battery 
    * Flash:   80Mhz
    * Upload:  921600
    * Prog:    AVRISPmkII

   << This Device Slave >>

   Flow: Master
   Step 1 : ESPNow Init on Master and set it in STA mode
   Step 2 : Start scanning for Slave ESP32 (we have added a prefix of `slave` to the SSID of slave for an easy setup)
   Step 3 : Once found, add Slave as peer
   Step 4 : Register for send callback
   Step 5 : Start Transmitting data from Master to Slave(s)

   Flow: Slave
   Step 1 : ESPNow Init on Slave
   Step 2 : Update the SSID of Slave with a prefix of `slave`
   Step 3 : Set Slave in AP mode
   Step 4 : Register for receive callback and wait for data
   Step 5 : Once data arrives, print it in the serial monitor

   Note: Master and Slave have been defined to easily understand the setup.
         Based on the ESPNOW API, there is no concept of Master and Slave.
         Any devices can act as master or salve.
*/

#include <esp_now.h>
#include <WiFi.h>
#include <U8x8lib.h>  

#define CHANNEL 1

// OLED
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 4, /* data=*/ 5, /* reset=*/U8X8_PIN_NONE );

// Init ESP Now with fallback
void InitESPNow() {
  if (esp_now_init() == ESP_OK) {
    //Serial.println("ESPNow Init Success");
  }
  else {
    //Serial.println("ESPNow Init Failed");
    // Retry InitESPNow, add a counte and then restart?
    // InitESPNow();
    // or Simply Restart
    ESP.restart();
  }
}

// config AP SSID
void configDeviceAP() {
  String Prefix = "Slave:";
  String Mac = WiFi.macAddress();
  String SSID = Prefix + Mac;
  String Password = "123456789";
  bool result = WiFi.softAP(SSID.c_str(), Password.c_str(), CHANNEL, 0);
//  if (!result) {
//    Serial.println("AP Config failed.");
//  } else {
//    Serial.println("AP Config Success. Broadcasting with AP: " + String(SSID));
//  }
}

const int ledPin =  16;
int ledState = LOW;             
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 100;               // interval at which to blink (milliseconds)
unsigned long currentMillis;
unsigned long clockPulse;
boolean oneTime = true;
int testCount = 0;

void setup() {
  //Serial.begin(115200);
  u8x8.begin();
  u8x8.setFont(u8x8_font_pxplusibmcga_r);
  u8x8.setFlipMode(1);        //remove if screen is flipped
  //Serial.println("ESPNow/Basic/Slave Example");
  u8x8.drawString(0, 0, "ESPNow Slave");
  //Set device in AP mode to begin with
  WiFi.mode(WIFI_AP);
  // configure device AP mode
  //configDeviceAP();
  // This is the mac address of the Slave in AP Mode
  Serial.print("AP MAC: "); Serial.println(WiFi.softAPmacAddress());
  //u8x8.drawString(0, 1, "AP MAC: "); 
  //u8x8.setCursor(0, 2);
  //u8x8.print(WiFi.softAPmacAddress());
  // Init ESPNow with a fallback logic
  InitESPNow();
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info.
  esp_now_register_recv_cb(OnDataRecv);

  pinMode(ledPin, OUTPUT);
  
}

// callback when data is recv from Master
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {

  digitalWrite(ledPin, LOW); //onboard TTGO blue led is active low
  delay(20);
  digitalWrite(ledPin, HIGH);
  
  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print("Last Packet Recv from: "); Serial.println(macStr);
  //u8x8.drawString(0, 3, "Last Packet From");
  //u8x8.setCursor(0, 4);
  //u8x8.print(macStr);
  Serial.print("Last Packet Recv Data: "); Serial.println(*data);
  //u8x8.drawString(0, 5, "Last Packet Data");
  u8x8.drawString(0, 6, "     ");  //clear data line before update
  u8x8.setCursor(0, 1);
  u8x8.print(*data);
  Serial.println("");
  testCount++;
  u8x8.print("   " + testCount);

}

void loop() {
  // Chill
}
