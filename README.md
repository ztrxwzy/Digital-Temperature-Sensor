# 🌡️ Digital Thermometer with Arduino UNO

An environmental temperature measurement system with **16x2 LCD display** and **LEDs** indicators, all powered by an Arduino UNO.
This was my first project in electronics, and it marked the beginning of my journey into hardware.
**Zero experience, but a thousand desires** 🚀.

---
## 📸 Prototype Preview

![20250716_181344](https://github.com/user-attachments/assets/be82a18a-bdde-48db-a4b9-88b9b9359a53)

---

## 🔧 What does this project do?

- Reads the ambient temperature using a **LM35DZ sensor**.

  ![LM35DZ](https://github.com/user-attachments/assets/7ffa30e3-41ff-4e75-8da9-e4e4d72a0941)

- Displays temperature on **16x2 LCD display** with I2C module.

  ![Display](https://github.com/user-attachments/assets/52ad8500-adb1-4746-98d7-10b0e4fb25cf)

- It uses **LEDs** to alert you to temperatures outside the range: a green LED if the room temperature is good, and a red LED if it is too hot or too cold inside the room.

  ![LEDs Testing](https://github.com/user-attachments/assets/6ddd5f66-4a27-431b-8e5e-96f7f37df247)

---
## 🛠️ Components

| Component         | Quantity | Description                           |
|-------------------|----------|---------------------------------------|
| Arduino UNO R3    | 1        | Main microcontroller                  |
| LM35DZ            | 1        | Temperature sensor                    |
| LCD 16x2 + I2C    | 1        | Display to show temperature           |
| LED red / gren    | 2        | Visual indicators                     |
| Resistors 220Ω    | 1        | To limit current to the LEDs          |
| Wires Dupont      | Various  | Connection between components         |
| Protoboard        | 1        | For seamless assembly                 |
| USB source        | 1        | Temporary feeding                     |

---

## ⚙️ Main Connections
