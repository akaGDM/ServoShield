#ifndef SS_DEVICE
#define SS_DEVICE

#include <Arduino.h>

#define SERVO_COUNT 20

typedef struct {
  uint16_t value;
  uint8_t speed_step;
  uint8_t speed_count;
  uint8_t speed_curr_count;
  uint16_t destination;
  boolean enabled;
} tservo;

tservo servos[SERVO_COUNT];
// все сервы делятся на 3 банка
// каналы 0  - 7  - банк А
// каналы 8  - 15 - банк В
// каналы 16 - 17 - банк С
#define  OFFSET_BANK_A 0
#define  OFFSET_BANK_B 8
#define  OFFSET_BANK_C 16

#define COUNT_BANK_A 8
#define COUNT_BANK_B 8
#define COUNT_BANK_C 2

volatile int CurrServoA = -1;
volatile int CurrServoB = -1;
volatile int CurrServoC = -1;

#define TIME_OFFSET_BANK_A 100
#define TIME_OFFSET_BANK_B 400
#define TIME_OFFSET_BANK_C 3

#define  CH0_on PORTD |= (1<<2) //D2
#define  CH0_off PORTD &= 0xFB //D2

#define  CH1_on PORTD |= (1<<3) //D3
#define  CH1_off PORTD &= 0xF7 //D3

#define  CH2_on PORTD |= (1<<4) //D4
#define  CH2_off PORTD &= 0xEF //D4

#define  CH3_on PORTD |= (1<<5) //D5
#define  CH3_off PORTD &= 0xDF //D5

#define  CH4_on PORTD |= (1<<6) //D6
#define  CH4_off PORTD &= 0xBF //D6

#define  CH5_on PORTD |= (1<<7) //D7
#define  CH5_off PORTD &= 0x7F //D7

#define  CH6_on PORTB |= 1 //D8
#define  CH6_off PORTB &= 0xFE //D8

#define  CH7_on PORTB |= (1<<1) //D9
#define  CH7_off PORTB &= 0xFD //D9

#define  CH8_on PORTB |= (1<<2) //D10
#define  CH8_off PORTB &= 0xFB //D10

#define  CH9_on PORTB |= (1<<3) //D11
#define  CH9_off PORTB &= 0xF7 //D11

#define  CH10_on PORTB |= (1<<4) //D12
#define  CH10_off PORTB &= 0xED //D12

#define  CH11_on PORTB |= (1<<5) //D13
#define  CH11_off PORTB &= 0xDF //D13

#define  CH12_on PORTC |= 1 //A0
#define  CH12_off PORTC &= 0xFE //A0

#define  CH13_on PORTC |= (1<<1) //A1
#define  CH13_off PORTC &= 0xFD //A1

#define  CH14_on PORTC |= (1<<2) //A2
#define  CH14_off PORTC &= 0xFB //A2

#define  CH15_on PORTC |= (1<<3) //A3
#define  CH15_off PORTC &= 0xF7 //A3

#define  CH16_on PORTC |= (1<<4) //A4
#define  CH16_off PORTC &= 0xED //A4

#define  CH17_on PORTC |= (1<<5) //A5
#define  CH17_off PORTC &= 0xDF //A5

#endif
