// Intended for at least two NodeMCUs, see Fritzing diagram for details
// Seemed to have kicked the reset problem. Now working on speed.
// Sends out name, node ID, and three "likes"
// Now we need to respond with something useful, like a prompt to go talk with someone
// Should also look at tracking when a node leaves the network

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMesh.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET LED_BUILTIN //4
Adafruit_SSD1306 display(OLED_RESET);

String myName = "Taylor";
String myLikes[3] = {"Chips","Bangers","Mash"};
unsigned int request_i = 0;
unsigned int response_i = 0;

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
  Serial.print("Received: ");
  Serial.println(request);

  // Display the current chip ID in yellow
  // Display the incoming message
  display.clearDisplay();
  display.setCursor(0,0);
  display.println(myName);  
  display.setCursor(0,16);
  display.print("Received: "); 
  display.println(request); 
  display.display();

  /* return a string to send back */
  
  char response[60];
  // sprintf(response, "%s,%d,%s,%s,%s", myName.c_str(),ESP.getChipId(),myLikes[0].c_str(),myLikes[1].c_str(),myLikes[2].c_str());
  sprintf(response, "Thanks");
  return response;
}

void setup(){
  Serial.begin(115200);

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
  char request[60];
  // sprintf(request, "Hello #%d from %d.", request_i++, ESP.getChipId());
  sprintf(request, "%s,%d,%s,%s,%s", myName.c_str(),ESP.getChipId(),myLikes[0].c_str(),myLikes[1].c_str(),myLikes[2].c_str());
  
  mesh_node.attemptScan(request);
  Serial.print("Sent: ");
  Serial.println(request);
  
  // Needed? Serial monitor reports activity at variable intervals with or without the delay.
  delay(1000);
}
