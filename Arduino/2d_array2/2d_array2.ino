// draft code for storing mesh node data in a 2D array

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
  
}

void checkExisting(){
  
  boolean alreadyRecorded = false;
  for(int i = 0; i < 6; i++){
    if(tempData[0] == nodeData[i][0]){
      alreadyRecorded = true;
    }
  }
    
  while (alreadyRecorded == false){
    for(int i = 0; i < 6; i++){
      if(nodeData[i][0] == ""){
        for(int x = 0; x < 6; x++){
          nodeData[i][x] = tempData[x];
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


