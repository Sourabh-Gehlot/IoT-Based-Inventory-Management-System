# IoT-Based-Inventory-Management-System
1. Problem Statement

Chemical inventory management is crucial in laboratories and industrial settings to ensure operational efficiency and safety. Often, equipments or machinery parts need to be monitored to prevent shortages or overstocking. Manual measurement of equipment quantity is time-consuming, prone to errors, and may lead to unsafe working conditions.
This project aims to develop an IoT-based Inventory Management System to automate the process of weight measurement using sensors and ESP32. The system provides real-time data on a webpage, alerts when equipment quantity are low, and reduces the dependency on manual monitoring.
________________________________________

2. Project Description and Components

This project uses an HX711 Load Cell Module to measure the weight of equipment stored. The measured weight is then used to calculate the quantity based on the standard weight of part. An ESP32 microcontroller is used for data acquisition and hosting a web server to display the weight and quantity in real time.
Objectives
•	Automate equipment inventory monitoring.
•	Provide real-time weight and quantity data via a webpage.
•	Alert users when the quantity drops below a specified threshold.

3. Components Used

Components

1. ESP32 Microcontroller	 -  Hosts the web server and processes sensor data.
2. HX711 Load Cell Module  -  Measures the weight of the container.
3. Load Cell	             -  Senses the weight of the object.
4. Wi-Fi Network	         -  For real-time monitoring via the web.
5. Item	                   -  Used as a object to sense


We can calliberate the equipment with standard weight of a particaular object and find out the number of items (as multiplier of weight) in that particular shelf.
