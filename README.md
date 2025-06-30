# Pi-Sight-Smart device for Object Detection
PiSight is a Raspberry pi 0 2w powered smart glasses project designed to assist the visually impaired by identifying surrounding objects in real time. It captures images using a mobile phone's IP webcam, processes them through an server with the help of YOLOv8 , and speaks out the names of detected objects using a Bluetooth speaker via the Raspberry pi 0 2w .

# How it works
~Step by Step Flow:
1. Phone streams camera using IP Webcam app.
2. Raspberry Pi captures frames from the stream.
3. Pi sends each frame to a YOLOv8 server running on a PC.
4. Server performs object detection and sends the detected object names back to Rasberry pi.
5. Pi reads out the result using 'espeak' through a Bluetooth speaker.

# Components used
-"Raspberry Pi Zero 2W"–Captures and sends image.  
-"Android Phone"–Used as an IP camera.  
-"YOLOv8"–Object detection model on PC.  
-"Bluetooth Speaker"–For audio output via Pi.  
-"Python"–Used for both Pi and PC scripts.  
-"Flask"–Lightweight server on PC.  
-"espeak"–Converts text output to speech.  

# Installation

# 📷 PiSight Installation Guide

## 📱 Phone Setup

1. Install the **IP Webcam** app from the Google Play Store.
2. Start the **camera server** in the app.
3. Note the **stream URL**, e.g.:

   ```
   http://192.168.0.103:8080
   ```

---

## 💻 PC Setup (Object Detection Server)

1. Clone the repository:

   ```bash
   git clone https://github.com/your_username/PiSight.git
   ```

2. Navigate to the project directory:

   ```bash
   cd PiSight
   ```

3. Install the required Python packages:

   ```bash
   pip install -r requirements.txt
   ```

---

## ▶️ Start the Server

Run the object detection server with:

```bash
python detect_server.py
```

# File Structure
PiSight/  
|--pi_send_frame.py  (Pi client script)  
|--detect_server.py  (Flask server script on PC)  
|--requirements.txt  (Dependencies)  
|--README.md         (This file)  
|--LICENSE           (MIT License)  
|--.gitignore        (Git ignored files)  
|--detection_log.txt (Auto-generated log of detections)  

# Sample Output
[INFO] Capturing image from IP webcam...  
[INFO] Sending image to detection server...  
[DETECTED] 2025-06-20 12:45:31 - person, laptop, keyboard  

