# Smart Home System using Atmega32 AVR
This project demonstrates the implementation of a smart home system using Atmega32 AVR microcontroller. The system features an LCD, keypad, LM35 temperature sensor, LDR (light-dependent resistor), buzzer, and a DC motor controlled using PWM. The system provides a user interface for interaction and access control.

# Features
* Access control using a PIN (1234)
* Three attempts to enter the correct PIN before blocking for 30 seconds.
* Main screen with options:
  1. Temp: Display current temperature.
  2. Door: Toggle door lock.
  3. Light: Toggle light.
  4. More: Navigate to second screen.

* Second screen with options:
  1. Auto Light: Set light automatically using LDR.
  2. Log Out: Log out of the system.
  3. Back: Go back to the main screen.
 
* DC motor (Fan) controlled by LM35 temperature sensor:
  * 30°C: Start working.
  * 35°C: Increase speed.
  * 40°C: Maximum speed level.
  * 60°C: Activate buzzer as a fire alarm.

 # Installation
 To install the project, follow these steps:

  1. Clone the repository
  2. Open the project in your preferred IDE
  3. Compile and upload the code to the Atmega32 AVR microcontroller

# Usage

After uploading the code, interact with the system using the keypad and LCD. The main screen will display the available options, and you can navigate through the system using the keypad. The second screen offers additional options, such as auto light control and logging out of the system.

# Contributing
Feel free to leave a suggestion or point out a problem in the issues.

# Screenshots
![image](https://github.com/HongYue1/Smart-Home-System/assets/87040288/d59cfba4-09f8-435b-b79e-cc4b2d2d6922)
![image](https://github.com/HongYue1/Smart-Home-System/assets/87040288/98fee4bc-997f-4cea-a74b-3ed8f8d3135f)
![image](https://github.com/HongYue1/Smart-Home-System/assets/87040288/5f701837-9751-47f3-afcf-6d236bb4ecfd)
![image](https://github.com/HongYue1/Smart-Home-System/assets/87040288/e0dad806-15b6-43ac-a1b7-dd976734f4a8)



