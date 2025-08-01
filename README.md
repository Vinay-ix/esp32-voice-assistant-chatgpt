# ESP32 Voice Assistant with ChatGPT

An embedded AI voice assistant system powered by the ESP32 microcontroller and integrated with ChatGPT for intelligent interaction. This hybrid system supports **offline wake word detection and command execution** using TensorFlow Lite Micro and **cloud-based processing** for advanced conversational tasks via APIs like OpenAI's ChatGPT and OpenWeatherMap.

> Built for hands-free IoT control and real-time interaction with edge AI capabilities.

---

## 🧠 Project Overview

The project demonstrates how voice-driven AI systems can be implemented on low-cost microcontrollers. It allows users to:
- Control home appliances using voice commands
- Retrieve live data from the internet (like weather info)
- Interact with ChatGPT for general-purpose responses
- Extend functionality via custom cloud APIs or local scripts

This system combines:
- **Embedded systems** (ESP32)
- **Voice processing**
- **AI/ML models (on-device)**
- **Cloud APIs**

---

## 📌 Features

- 🎙️ **Wake Word Detection** with TensorFlow Lite Micro
- 🧠 **Voice Command Recognition** & GPIO Control
- ☁️ **Cloud Integration** with ChatGPT, Weather API
- 💡 **Control LEDs, Relays, Fans**, etc. via GPIO
- 🔄 **Offline + Online Hybrid Design**
- 📡 Wi-Fi & OTA Support
- 🔊 Voice feedback via speaker or LED indications
- ⚙️ Expandable & customizable via JSON commands

---
## ⚙️ System Architecture

Mic → ESP32 → Wake Word → Command Classification →
[Local Action | Cloud API] → Feedback (Speaker / LED)


**Key Components:**
- **ESP32**: Dual-core microcontroller with Wi-Fi & BLE
- **Microphone**: Captures audio input
- **Speaker/LEDs**: Outputs assistant feedback
- **Cloud Services**: ChatGPT, OpenWeatherMap for NLP tasks

---

## 🛠 Hardware Requirements

| Component         | Specification                    |
|------------------|----------------------------------|
| Microcontroller   | ESP32 Dev Board                  |
| Microphone        | INMP441 (I2S Digital Mic)        |
| Speaker/LED       | Optional for feedback            |
| Power Supply      | 5V USB / Battery Module          |
| Connectivity      | Wi-Fi required for cloud tasks   |

---

## 💻 Software Stack

- **Arduino IDE** with ESP32 board support
- **TensorFlow Lite Micro** for on-device keyword spotting
- **HTTPClient + ArduinoJson** for cloud API integration
- **Wake word model** trained in Python and deployed in `.tflite` format

---

## 📂 Project Structure
esp32-voice-assistant-chatgpt/
├── code/
│ ├── main.ino # Arduino sketch with voice logic
│ └── wake_word_model.tflite # Trained model
├── docs/
│ └── Final_Project_Report.pdf
├── images/
│ └── system_architecture.png
├── LICENSE
├── README.md
└── .gitignore


---

## 🧪 Setup Instructions

### 1. Clone the Repository


git clone https://github.com/yourusername/esp32-voice-assistant-chatgpt.git
cd esp32-voice-assistant-chatgpt 
---
2. Install Arduino Dependencies
In Arduino IDE, install the following libraries:

WiFi.h

HTTPClient.h

ArduinoJson

TensorFlowLite_ESP32 or tflite-micro
---
3. Configure Wi-Fi and API Keys
Update the main.ino:
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";
const char* chatgpt_token = "Bearer YOUR_OPENAI_API_KEY";
---
4. Upload the Code
Open code/main.ino in Arduino IDE

Select the correct ESP32 board & COM port


Upload the sketch
🗣️ Example Voice Commands
Command	Action
"Hey ESP, turn on light"	Turns on GPIO connected light
"Turn off fan"	Turns off connected fan via relay
"What's the weather"	Calls weather API and returns response
"How are you?"	Forwards query to ChatGPT
---
📊 Results & Performance
Metric	Result
Wake Word Accuracy	94% in controlled setting
Command Accuracy	90% (10 test commands)
Offline Response Time	250–400 ms
Online Query Time	800 ms – 1.5 sec
---
🚧 Limitations
Background noise may affect wake word detection

Limited offline NLP capability (basic commands only)

Internet required for ChatGPT/cloud APIs
---
🚀 Future Scope
🌍 Multi-language support

📷 Vision-based object detection (ESP32-CAM)

📡 Bluetooth fallback for offline control

🧠 Improved on-device NLP via better models

📊 Cloud dashboard integration (e.g., Firebase)
---
👨‍💻 Authors
Name	Email	VIT Reg. No
Vinay	22BEC1247
Ralf Paul Victor	22BEC1222
Manan Malik	22BEC1245
Saumil S. Rana	22BEC1310

📄 License
This project is licensed under the MIT License.

🙋‍♂️ Contributing
We welcome community contributions!
Feel free to fork the repo, make improvements, and create a pull request.

📬 Contact
For technical support or suggestions:


