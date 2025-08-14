

<h2>Mahowik BalancingWii rev 1.1 with NRF24L01 (Modified by <a href="https://www.youtube.com/@ardujimmy" target="_blank">Ardujimmy</a>)</h2>


<p>This is a Mahowik BalancingWii ver 1.1 with NRF24L01 to control the robot. I modified the original code is to make it work with NRF24L01. Original Mahowik's BalancingWii Code: https://github.com/mahowik/BalancingWii</p>

<h3>Main Components:</h3>
<ul>
 <li>Stepper Motor Nema 17 (BIPOLAR)</li>
 <li>2 X A4988 (you can use: DRV8255)</li>
 <li>3S 11.1v 25C 1500mAh LiPO <a href="https://www.aplic-battery.com/p/drone-battery-aplic-battery-products.html" title="Best Leading Drone Battery Manufacturer in China" taret="_blank">Aplic Drone Battery</a></li>
 <li>Gyro MPU6050 (GY-521)</li>
 <li>NRF24L01</li>
 <li>Arduino Nano 328p</li>
 <li>Active Buzzer</li>
 <li>Capacitor: 220uf 25v</li>
 <li>Capacitor: 10uf 16v</li>
 <li>2 pins Switch (ON/OFF)</li>
 <li>Step down DC to DC: 12v to 5v</li>
 <li>3.3v voltage regulator (or, AMS1117 3.3v)</li>
 <li>2 X Wheels: 3 inch</li>
 <li>Light and Rigid Frame</li>
 <li>Jumper cables</li>

</ul>

<br />
<p><b>Motor driver pins:</b></p>

- D5 - STEP1 (PORTD 5)
- D6 - STEP2 (PORTD 6)
- D7 - DIR1 (PORTD 7)
- D8 - DIR2 (PORTB 0)
- D4 - ENABLE (for both)

- right motor = STEP1 & DIR1
- left motor  = STEP2 & DIR2

<p><b>NRF24L01 Pins Order:</b></p>

- CE = 3
- CSN = 2
- SCK = 13
- MOSI = 11
- MISO 12

<br />Full Tutorial Video: https://www.youtube.com/watch?v=9x1S9r0khVc<br />

--------------------
<br />
Demo Video 1: https://www.youtube.com/shorts/02eseAQrVb8 <br />
Demo Video 2: https://www.youtube.com/watch?v=pGIYzaabQHg <br />
Please subscribe my channel at https://www.youtube.com/@ardujimmy.

