# traffic-light-control
“Embedded traffic control system using Arduino with pedestrian and night mode”
# 🚦 Traffic Light Control System with Pedestrian & Night Mode

## 📘 Project Overview
An Arduino-based embedded system to control traffic lights with:
- Automated pedestrian detection (via ultrasonic sensor)
- Adaptive night mode (via LDR)
- Real-time signal transitions and safety alerts

## 💡 Features
- Ultrasonic sensor for pedestrian detection
- LDR-based ambient light sensing
- Buzzer and LED indicators for pedestrians
- Tinkercad simulation + hardware prototype
- Embedded C code on AVR-based Arduino

## 📸 Circuit Diagram
<img width="1309" height="604" alt="Circuit diagram " src="https://github.com/user-attachments/assets/834fb0c9-caac-452d-a2e1-f80333b6eed6" /> 

## 🧠 Core Logic Snippet
```cpp
if(!pm && !nm){
  digitalWrite(RED_LED, HIGH);
  delay(2000);
  digitalWrite(RED_LED, LOW);
}
else if(pm){
  blinkYellowLED();
}
