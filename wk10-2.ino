#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const char* ssid = "IOT_LAB";
const char* password = "password";
AsyncWebServer server(80);
String website ;
char webSite[1000];
void handleRoot(AsyncWebServerRequest *request){
  snprintf(webSite, 1000, "<!DOCTYPE html><html lang=\"en\"><head> <meta charset=\"UTF-8\"> <script src=\"https://code.jquery.com/jquery-2.2.4.min.js\"></script> <script>setInterval(requestData, 500); function requestData(){$.get(\"/sensors\") .done(function(data){if(data){$(\"#resis\").text(data.vr);}else{$(\"#resis\").text(\"?\");}}) .fail(function(){console.log(\"fail\");});}</script> <title>VR Reader</title></head><body> <div class=\"container\"> <p>Variable Resistor=<span id=\"resis\"></span></p></div></body></html>");
  request->send(200,"text/html",webSite);
  }
void handleSensorData(AsyncWebServerRequest *request){
  int sensor=analogRead(36);
  String json ="{\"vr\": ";
  json +=sensor;
  json +="}";
  request->send(200, "application/json",json);
}
void setup(void) {
   Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println(WiFi.localIP());

  
  server.on("/", handleRoot);
  server.on("/sensors",handleSensorData);
  server.begin();
  Serial.println("HTTP server started");
}
void loop(void) {
  for(int i=0;i<=10;i++){
    delay(1000);
  }
}
