// draft code for storing mesh node data in a 2D array

// String nodeNum = String(ESP.getChipId());
String testString = "Taylor,apples,oranges,bananas,123456789";

String nodeData[][5] = {
  // this seems to be the only way to declare a 2D array
  {"","","","",""},
  {"","","","",""},
  {"","","","",""},
  {"","","","",""},
  {"","","","",""}
  }; 

void setup() {
  // don't show initial serial garbage
  delay(100);
  
  Serial.begin(115200);
  int arrayLoc = 0;
  recordNode(arrayLoc);
  for(int i = 0; i < 5; i++){
    Serial.println(nodeData[arrayLoc][i]);
  }
}

void loop() {
  
}

void recordNode(int x){

  int delim1 = testString.indexOf(',');
  nodeData[x][0] = testString.substring(0,delim1);  
  int delim2 = testString.indexOf(',',delim1+1);
  nodeData[x][1] = testString.substring(delim1+1,delim2);  
  int delim3 = testString.indexOf(',',delim2+1);
  nodeData[x][2] = testString.substring(delim2+1,delim3);  
  int delim4 = testString.indexOf(',',delim3+1);
  nodeData[x][3] = testString.substring(delim3+1,delim4);  
  int delim5 = testString.indexOf(',',delim4+1);
  nodeData[x][4] = testString.substring(delim4+1,delim5); 

}


