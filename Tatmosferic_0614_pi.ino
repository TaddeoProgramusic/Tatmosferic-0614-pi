#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

// --- CONFIGURACIÓN ---
const char* ssid = "Your WiFi ssid";
const char* password = "Your Password";
String webAppUrl = "Your URL"; 

#define DHTPIN 13
#define DHTTYPE DHT11
#define LDRPIN 33

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n¡Conectado!");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int luzRaw = analogRead(LDRPIN);
  int luz = map(luzRaw, 0, 4095, 100, 0);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // Armamos la URL con los datos de los sensores
    String url = webAppUrl + "?temp=" + String(t) + "&hum=" + String(h) + "&luz=" + String(luz);
    
    http.begin(url);
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    int httpCode = http.GET();
    
    if (httpCode > 0) {
      Serial.println("Datos enviados a Google Sheets!");
    } else {
      Serial.println("Error enviando datos");
    }
    http.end();
  }
  
  delay(500); // Actualiza cada 10 segundos para no saturar
}