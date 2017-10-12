// Based on the HelloMesh Example
// Add OLED for debugging messages
// I have two identical NodeMCUs, both programmed the same, yet one runs slower than the other?

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMesh.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET LED_BUILTIN //4
Adafruit_SSD1306 display(OLED_RESET);

unsigned int request_i = 0;
unsigned int response_i = 0;

String myName = "Taylor";
String myNode = String(ESP.getChipId());
String myData[] = {myName, myNode, "CNC", "3D Printing", "Open Source"};
int numEntries = 5;   // must match array above

String manageRequest(String request);

/* Create the mesh node object */
ESP8266WiFiMesh mesh_node = ESP8266WiFiMesh(ESP.getChipId(), manageRequest);

/**
 * Callback for when other nodes send you data
 *
 * @request The string received from another node in the mesh
 * @returns The string to send back to the other node
 */
String manageRequest(String request)
{
  /* Print out received message */
  // Serial.print("received: ");
  // Serial.println(request);

  for(int i = 0; i < numEntries; i++){
    int commaIndex = request.indexOf(',',i); 
    Serial.println(commaIndex);
  }

  // Display the current chip ID in yellow
  // Display the incoming message
  display.clearDisplay();
  display.setCursor(0,0);
  display.println(myName);  
  display.setCursor(0,16);
  display.println(request); 
  display.display();

  /* return a string to send back */
  String response = ("Hello #" + String(response_i) + " from " + myName);
  response_i++;
  return response;
}

void setup(){

  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.println("Setting up mesh node...");
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  // empty the buffer
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(myName);
  display.setCursor(0,16);
  display.print("Searching...");
  display.display();
  
	mesh_node.begin();
}

void loop()
{
  /* Accept any incoming connections */
  mesh_node.acceptRequest();

  /* Scan for other nodes and send them a message */
  String request;
  
  for (int i = sizeof(myData); i > 0; i--){
    request = request + myData[i] + ",";
  }
  
  Serial.println(request);
  request_i++;
  mesh_node.attemptScan("hello");
  delay(5000);
}
