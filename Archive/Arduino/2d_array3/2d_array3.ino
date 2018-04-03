// Notes:
// draft code for storing mesh node data in a 2D array
// code currently functioning with a demo string
// needs to be integrated into the mesh code
// only one NodeMCU needed, no OLED required/used

// Behavior:
// Establish 2D node with 6x6 entries
// Fill first row with local node data
// Parse sample string, check to make sure it's not already recorded in the array
// Add the parsed data to the first available row
// If data sits in array for X time without an update, delete from array

// node ID, when added (millis), name, tag1, tag2, tag3
String testString = "123456789,0,Nick,Kiwis,Grapes,Apples";
String nodeNum = String(ESP.getChipId());
String tempData[] = {"","","","",""};

// first bracket left empty intentionally
// is there a more elegant way to declare this array?
String nodeData[][6] = {
  // first one is me
  {nodeNum,"0","Taylor","Apples","Oranges","Bananas"},
  {"","","","","",""},
  {"","","","","",""},
  {"","","","","",""},
  {"","","","","",""},
  {"","","","","",""}
  }; 

void setup() {
  // don't show initial serial garbage
  delay(100);
  
  Serial.begin(115200);

  // parse incoming data string into a temporary array
  parseData();

  // see if the node number already exists in the array
  checkExisting();
}

void loop() {


  // see if a recorded node hasn't reported for a while
  // fyi, millis don't seem to start right at zero (20k is more like a 12 sec delay)
  garbageCollection(20000);

  delay(1000);

  Serial.println("");
  for(int k = 0; k < 6; k++){
    Serial.print(nodeData[1][k] + ", ");
  }
}

void garbageCollection(int x){
  for(int i = 0; i < 6; i++){
    if((nodeData[i][1].toInt() + x) < millis()){
      for(int j = 0; j < 6; j++){
        nodeData[i][j] = "";
      }
    }
  }
}

void checkExisting(){
  
  boolean alreadyRecorded = false;
  for(int i = 0; i < 6; i++){
    if(tempData[0] == nodeData[i][0]){
      alreadyRecorded = true;
      nodeData[i][1] = String(millis());
      Serial.println("");
      for(int k = 0; k < 6; k++){
        Serial.print(nodeData[i][k] + ", ");
      }
    }
  }
    
  while (alreadyRecorded == false){
    for(int i = 0; i < 6; i++){
      if(nodeData[i][0] == ""){
        for(int x = 0; x < 6; x++){
          nodeData[i][x] = tempData[x];
        }
        // serial debug
        Serial.println("");
        for(int k = 0; k < 6; k++){
          Serial.print(nodeData[i][k] + ", ");
        }
        alreadyRecorded = true;
        break;
      }
    }  
  }  
}

void parseData(){

  int delim1 = testString.indexOf(',');
  tempData[0] = testString.substring(0,delim1);  
  int delim2 = testString.indexOf(',',delim1+1);
  tempData[1] = testString.substring(delim1+1,delim2);  
  int delim3 = testString.indexOf(',',delim2+1);
  tempData[2] = testString.substring(delim2+1,delim3);  
  int delim4 = testString.indexOf(',',delim3+1);
  tempData[3] = testString.substring(delim3+1,delim4);  
  int delim5 = testString.indexOf(',',delim4+1);
  tempData[4] = testString.substring(delim4+1,delim5); 
  int delim6 = testString.indexOf(',',delim5+1);
  tempData[5] = testString.substring(delim5+1,delim6); 

}

