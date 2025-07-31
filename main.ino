#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "TensorFlowLite.h"
#include "WakeWordModel_data.h"

#define LED_PIN 2 // Example: control onboard LED
#define SPEAKER_PIN 25

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
... (Truncated for brevity)
