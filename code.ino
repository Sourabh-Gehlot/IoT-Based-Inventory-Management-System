#include <HX711.h>
#include <WiFi.h>
#include <WebServer.h>
// HX711 Pins
#define DOUT 2  // Data pin
#define CLK 5   // Clock pin
HX711 scale;
// Calibration factor (adjust based on your setup)
float calibration_factor = 2175;
// Wi-Fi credentials
const char* ssid = "RADHEKRISHNA 9946";
const char* password = "1z72(02S";
// Web server instance
WebServer server(80);
float weight = 0.0;
float volume = 0.0;
const float density = 1.0;  // Density of water in kg/L
const float beaker_capacity = 10.0;  // Beaker capacity in liters
void handleRoot() {
  String html = "<html><head><title>IoT-Based Chemical Inventory Management</title></head><body>";
  html += "<h1>Chemical Inventory Management</h1>";
  html += "<p><strong>Weight:</strong> " + String(weight, 2) + " kg</p>";
  html += "<p><strong>Volume:</strong> " + String(volume, 2) + " L</p>";
  if (volume < 0.05) {  // Threshold of 50 mL (0.05 L)
    html += "<p style='color:red;'><strong>Alert:</strong> Chemical is not sufficient, purchase it!</p>";
  }
  html += "</body></html>";
  server.send(200, "text/html", html);
}
void setup() {
  Serial.begin(9600);
  // Initialize the HX711
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor);
  scale.tare();  // Reset the scale to 0
  Serial.println("HX711 Load Cell Initialized.");
  Serial.println("Place a known weight for calibration if needed.");
// Connect to Wi-Fi
  Serial.print("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
 // Set up the web server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started.");
}
void loop() {
  // Check if HX711 is ready
  if (scale.is_ready()) {
    weight = scale.get_units(10);  // Average of 10 readings
    weight = (weight / 40);  // Calibration adjustment
    volume = weight / density;  // Calculate volume
  Serial.print("Weight: ");
    Serial.print(weight, 2);  // Display weight with 2 decimal places
    Serial.println(" kg");
   Serial.print("Volume: ");
    Serial.print(volume, 2);  // Display volume with 2 decimal places
    Serial.println(" L");
   if (volume < 0.05) {
      Serial.println("Alert: Chemical is not sufficient, purchase it!");
    }
  } else {
    Serial.println("HX711 not found. Please check connections.");
  }
// Handle client requests
  server.handleClient();
 delay(1000);  // Delay for 1 second between readings
}
