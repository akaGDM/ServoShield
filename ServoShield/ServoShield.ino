#include "device.h"

void setup()
{
  for (uint8_t i = 0; i < SERVO_COUNT; i++)
    Servo_Init(i);
  Serial.begin(115200);
  //////// BANK A //////////
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
//////// BANK B //////////
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
//////// BANK C //////////
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  Timer1_Init();
  Timer0_Init();
  Timer2_Init();
  AllBankReset();
}


uint8_t packet[100];
uint8_t packet_length=0;
boolean xor_next = false;

void parse_packet()
{
  if (packet_length < 6) return;
  
  packet_length = 0;
  if (packet[0]>19) return;
  if (packet[3]==0) packet[3] = 4;
  uint16_t val = packet[1] | (packet[2]<<8);
  if (val>2200 || val<800) return;
  uint8_t indx = packet[0];
  //cli();
  servos[indx].speed_step=packet[3];
  servos[indx].speed_count=packet[4];
  servos[indx].speed_curr_count=0;
  servos[indx].destination=packet[1] | (packet[2]<<8);
  servos[indx].enabled=packet[5];
  //sei();
}

void loop()
{
  if (Serial.available()){
    uint8_t data = Serial.read();
    if (data == 0x5E) parse_packet();
    else {
      if (data == 0x5D) xor_next = true;
      else {
        if (xor_next) data = data ^ 0x60;
        xor_next = false;
        packet[packet_length++] = data;
      }
    }
  }
}
