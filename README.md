# ilPalo
<div align="center">
     <h3 align="center">a simple IOT project that helps you scroll reddit undetected while you're in the office
</h3>
  </div>

<!-- GETTING STARTED -->
## Getting Started
To recreate this project you will need Arduino hardware components and a PIR Sensor.

### Prerequisites
Here's the Arduino components needed for the project:
* Arduino MKR 1010 Wifi
* Arduino MKR IoT carrier //not necessarly needed
* PIR sensor connected to A5 pin

Before upolading the code on your Arduino you have to add your Wifi credentials in the ilPaloArduino.ino file.
Before starting the nodejs client app you have to add the IP address and port of the Arduino in the ilPalo.js file.

<!-- USAGE EXAMPLES -->
## Usage
Put the device in your garden with the moisture sensor inside the soil, you can check values like temperature, humidity, pressure, light and soil moisture from the screen using the buttons or using the app. The app also allows you to remotely control the water pump, the lights and a fan. It also gives you a weather forecast for the next twelve hours thanks to the implementation of the Zambretti algorithm and it is possible to observe the trend of the sensor values in different time frames through the graphs page.

