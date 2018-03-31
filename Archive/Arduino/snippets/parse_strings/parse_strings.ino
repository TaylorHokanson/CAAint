String testString = "CNC,3D Printing,Open Source,Biology,Electronics";

void setup() {

 Serial.begin(115200);
 delay(10);

String parseResponse[5];
int tempIndex = 0;
  
    int delim1 = testString.indexOf(',');
    Serial.println(testString.substring(0,delim1));  
    int delim2 = testString.indexOf(',',delim1+1);
    Serial.println(testString.substring(delim1+1,delim2));  
    int delim3 = testString.indexOf(',',delim2+1);
    Serial.println(testString.substring(delim2+1,delim3));  
    int delim4 = testString.indexOf(',',delim3+1);
    Serial.println(testString.substring(delim3+1,delim4));  
    int delim5 = testString.indexOf(',',delim4+1);
    Serial.println(testString.substring(delim4+1,delim5));      
}

void loop() {

}
