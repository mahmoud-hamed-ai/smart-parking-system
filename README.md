# 🚗 Smart Parking Assistant System (P1)

An Arduino-based smart parking assistant designed to help drivers park safely by measuring real-time distances, providing visual and audio alerts, and transmitting live sensor readings via Bluetooth.

---

## 🛠️ Hardware & Components Used
* **Microcontroller:** Arduino Uno
* **Distance Measurement:** Ultrasonic Sensor (HC-SR04)
* **Display:** 16x2 LCD Screen (I2C / Standard)
* **Wireless Communication:** Bluetooth Module (HC-05 / HC-06)
* **Alerts & Indicators:** Buzzer & Status LEDs (Green, Yellow, Red)
* **Simulation:** Tested and verified on Tinkercad

---

## ⚙️ How It Works
1. **Distance Detection:** The ultrasonic sensor continuously calculates the distance between the vehicle and nearby obstacles.
2. **Visual & Audio Feedback:** 
   * **Safe Zone:** Green LED lights up.
   * **Warning Zone:** Yellow LED lights up with intermittent buzzer beeps.
   * **Danger Zone:** Red LED lights up with a continuous alarm sound.
3. **Real-Time Monitoring:** Distance values are displayed live on the **LCD screen** and sent wirelessly to a mobile **Bluetooth Terminal** app.

---

## 🚀 Getting Started
1. Clone or download this repository.
2. Open the `.ino` code file using **Arduino IDE** (or import the circuit into **Tinkercad**).
3. Connect the components according to the pin definitions in the code.
4. Upload the sketch to your Arduino board and pair your phone with the Bluetooth module.

---

## 👥 Project Owner
**Team:** MIND CRAFT  
**Project Code:** P1  
**Institution:** Faculty of Artificial Intelligence – KNU  

* **Mahmoud Mohamed Ahmed Hamed Ali**
