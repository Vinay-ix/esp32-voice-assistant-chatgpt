
---

## ✅ `main.ino` (Starter Code)

```cpp
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "TensorFlowLite.h"
#include "WakeWordModel_data.h"

#define LED_PIN 2 // Example: control onboard LED
#define SPEAKER_PIN 25

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// API endpoint for ChatGPT (e.g., OpenAI proxy)
const char* chatgpt_endpoint = "https://api.openai.com/v1/chat/completions";
const char* chatgpt_token = "Bearer YOUR_API_KEY"; // Replace with your token

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  connectToWiFi();

  // Initialize TensorFlow Lite model
  Serial.println("Initializing wake word detection...");
  // Add tflite-micro setup logic here (model, interpreter, input/output tensors)
}

void loop() {
  // Simulate wake word detection (real implementation would use TensorFlow model)
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    handleCommand(cmd);
  }
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
}

void handleCommand(String command) {
  if (command.equalsIgnoreCase("turn on light")) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Light turned ON");
  } else if (command.equalsIgnoreCase("turn off light")) {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Light turned OFF");
  } else {
    queryChatGPT(command);
  }
}

void queryChatGPT(String prompt) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected");
    return;
  }

  HTTPClient http;
  http.begin(chatgpt_endpoint);
  http.addHeader("Authorization", chatgpt_token);
  http.addHeader("Content-Type", "application/json");

  String payload = "{\"model\": \"gpt-3.5-turbo\", \"messages\": [{\"role\": \"user\", \"content\": \"" + prompt + "\"}]}";

  int httpResponseCode = http.POST(payload);
  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println("Response from ChatGPT:");
    Serial.println(response);
  } else {
    Serial.printf("Error in POST: %d\n", httpResponseCode);
  }

  http.end();
}
