# Just-for-fun
Voice controllable RC car (Persian language)

![Picture2](https://user-images.githubusercontent.com/57262710/218384855-5a8bb12d-b11a-45dd-a1ec-0ed307ca0668.png)

In this project, I intended to control a four-wheeled robot by sending a voice command. For example, when we say 10 cm forward, the robot should move 10 cm forward, or rotate in different directions and different angles. 

For this purpose, it is first necessary to convert the voice command into text in Python software, then process that text, and finally convert it to URL code. This is all that is done on a PC. As such, the computational load and text processing is removed from NodeMCU microcontroller.

On the other hand, the laptop is connected to the microcontroller, which has become an access point, via WiFi. In fact, both the laptop and the microcontroller are connected to the same network with the same IP address. Now the microcontroller receives the command from the URL sent by Python.

This command, which was coded in Python, is converted into ASCII code in the microcontroller, and by decoding it, the information is read and sent to the motors for movement. In the Arduino code, a function has been written to convert centimeters to the time the motors stay on. The necessary command to move the robot is sent to the Arduino via WIFI.
![image](https://user-images.githubusercontent.com/57262710/218384266-cc590b8a-f3ff-404d-98b3-c9d2c7032a2b.png)

## Explanation of Python code:
By importing the google speech recognition library in Python, you can convert audio to text. In the next step, we extract the number from the sentence created with the isdigit() command. Then, by checking several if, we look for keywords such as front, back, right, centimeter, and degree, and based on these words and the extracted number We generate the corresponding URL.

![image](https://user-images.githubusercontent.com/57262710/218384207-84d87240-af07-4044-90b8-14fd91f2bcec.png)


## Microcontroller C code:
The NodeMCU with ESP8266 module was utilized because it has a Wi-Fi module and is smaller and cheaper than the Arduino UNO. It also has more flash memory. L298N engine control module was used to control the engines. The right motor pair was connected to one output of the module and the left motor pair was connected to the other output. PWM pins of NodeMCU module were used to control the speed.

In the microcontroller code, after receiving the URL from Python, we analyze the three characters after the IP address. For example, by receiving b22, meaning Backward 22cm, the number 22 is entered into the function we have fitted, and the time the engine is on is obtained in seconds. Character b also activates a part of the code that is related to moving backward. This code is also attached to this repository.
