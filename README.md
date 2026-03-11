# IoT-Based-Inventory-Management-System
1. Problem Statement

Chemical inventory management is crucial in laboratories and industrial settings to ensure operational efficiency and safety. Often, chemicals like water, NaOH, or other reagents need to be monitored to prevent shortages or overstocking. Manual measurement of chemical levels in storage containers is time-consuming, prone to errors, and may lead to unsafe working conditions.
This project aims to develop an IoT-based Chemical Inventory Management System to automate the process of chemical weight and volume measurement using sensors and ESP32. The system provides real-time data on a webpage, alerts when chemical levels are low, and reduces the dependency on manual monitoring.
________________________________________

2. Project Description and Components

This project uses an HX711 Load Cell Module to measure the weight of chemicals stored in a container. The measured weight is then used to calculate the volume based on the density of the chemical (in this case, water). An ESP32 microcontroller is used for data acquisition and hosting a web server to display the weight and volume in real time.
Objectives
•	Automate chemical inventory monitoring.
•	Provide real-time weight and volume data via a webpage.
•	Alert users when the chemical volume drops below a specified threshold.
Components Used
Component          	   Quantity	   Description
ESP32 Microcontroller	    1	       Hosts the web server and processes sensor data.
HX711 Load Cell Module	  1	       Measures the weight of the container.
Load Cell	                1	       Senses the weight of the object.
Wi-Fi Network	            1        For real-time monitoring via the web.
Item	                    1	       Used as a object to sense


We can calliberate the equipment with standard weight of a particaular object and find out the number of items (as multiplier of weight) in that particular shelf.
