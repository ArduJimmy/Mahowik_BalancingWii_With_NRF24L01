#ifndef NRF24_RX_H_
#define NRF24_RX_H_

#include "config.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#if defined(NRF24_RX)

// The sizeof this struct should not exceed 32 bytes
struct RF24Data {
  byte throttle;
  byte yaw;
  byte pitch;
  byte roll;
  byte AUX1;
  byte AUX2;
  byte AUX3;
  byte AUX4;  
};
extern RF24Data nrf24Data;
extern int16_t nrf24_rcData[RC_CHANS];

void NRF24_Init();
void NRF24_Read_RC();

#endif

#endif /* NRF24_RX_H_ */
