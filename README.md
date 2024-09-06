 

This project implements a **Traffic Light Control System** using Arduino. The system controls traffic lights on three roads, represented by three sets of LEDs: green, yellow, and red. It reads sensor values to determine the traffic density on each road and opens the roads in order of least to most traffic density, while adhering to timed light changes.

#### **Features:**
- Traffic lights (green, yellow, and red) are controlled based on traffic density on three roads (A, B, and C).
- The system reads sensors to measure traffic density on each road.
- It uses a **bubble sort algorithm** to prioritize roads based on traffic density.
- Lights transition smoothly from **red** to **yellow**, then **green**, and back to **red** after a set duration.
- Timing for each light is based on traffic density, with customizable durations.

---

### **Components:**
1. **Arduino Board** (e.g., Arduino Uno)
2. **LEDs** (9 total: 3 sets of red, yellow, and green LEDs)
3. **Sensors** (to simulate traffic density)
4. **Resistors** (for LEDs)
5. **Jumper Wires**
6. **Breadboard**

---

### **Pin Assignments:**
The system uses specific digital pins to control each LED:
- **Road A**:
  - `ledA1 (Pin 2)` - Green
  - `ledA2 (Pin 3)` - Yellow
  - `ledA3 (Pin 4)` - Red
- **Road B**:
  - `ledB1 (Pin 5)` - Green
  - `ledB2 (Pin 6)` - Yellow
  - `ledB3 (Pin 7)` - Red
- **Road C**:
  - `ledC1 (Pin 8)` - Green
  - `ledC2 (Pin 9)` - Yellow
  - `ledC3 (Pin 10)` - Red

---

### **Code Explanation:**

1. **Pin Setup**:  
   The pins for each LED are defined and set as `OUTPUT` in the `setup()` function.
   
2. **Sensor Readings**:  
   The system reads sensor values (simulated via analog inputs) using the `readSensor()` function. Sensor thresholds are set to determine whether traffic is present on each road.

3. **Sorting Traffic Density**:  
   The densities of the three roads are calculated by adding sensor values. The roads are then sorted in ascending order of density using a simple **bubble sort**.

4. **Light Control**:  
   Based on the traffic density, the lights on each road are controlled. The road with the least traffic is opened first. The system turns on the **yellow light** for 3 seconds before switching to the **green light** for a period determined by the traffic density:
   - **Least dense road**: 5 seconds of green
   - **Medium dense road**: 6 seconds of green
   - **Most dense road**: 8 seconds of green

5. **Light Transitions**:  
   The system manages the transition of lights from **yellow** to **green**, then back to **red** while keeping other roads in the red state. Each road follows a similar timing sequence based on traffic density.

---

### **How to Use:**

1. **Setup the Circuit**:
   - Connect the LEDs to the Arduino according to the pin assignments above.
   - Use analog sensors (or potentiometers) to simulate traffic density.

2. **Upload the Code**:
   - Upload the provided Arduino sketch to your Arduino board.

3. **Run the Program**:
   - Once the sketch is running, the system will read sensor values and manage the traffic lights based on the traffic density on each road.

---

### **Customization:**
- **Adjusting Timings**:
  - The yellow light duration is set using the `YELLOW_TIME` macro (`#define YELLOW_TIME 3000`) which is in milliseconds (3 seconds).
  - You can modify the green light durations by changing the values in the `openRoad()` function.

- **Sensor Thresholds**:
  - The current threshold for detecting traffic is set to `400`. You can adjust this value in the `readSensor()` function based on your sensor setup.

---

### **Key Functions:**

1. **`void readSensor()`**:
   - Reads analog values from traffic sensors, converting them to binary (1 if traffic is present, 0 if not).

2. **`void openRoad(int roadIndex, int nextRoadIndex, int densityRank)`**:
   - Manages the light sequence for the given road and controls the transition from red to yellow to green.

---
LED testing and IR testing would help you test the components and ensure their positions relative to the code.


