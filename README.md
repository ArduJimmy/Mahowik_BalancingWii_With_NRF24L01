

<h2>Mahowik BalancingWii rev 1.1 with NRF24L01 (Modified by <a href="https://www.youtube.com/@ardujimmy" target="_blank">Ardujimmy</a>)</h2>


<p>This is a Mahowik BalancingWii ver 1.1 with NRF24L01 to control the robot. I modified the original code is to make it work with NRF24L01. Original Mahowik's BalancingWii Code: https://github.com/mahowik/BalancingWii</p>

<h3>Main Components:</h3>
<ul>
 <li>Stepper Motor Nema 17</li>
 <li>DRV8255</li>
 <li>12v 2A x 3 (18650)</li>
 <li>MPU6050</li>
 <li>NRF24L01 with Voltage Regulator 3.3v</li>
 <li>Arduino UNO (You can use Nano 328p 5v</li>
 <li>Buzzer</li>
 <li>Capacitor: 470uf 25v</li>
 <li>LCD OLED SSD3602</li>
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

I would post a video demo as soon as My battery arrives!
Please subscribe my channel at https://www.youtube.com/@ardujimmy.

Note: I will post the detail and schematic diagram later.

