#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif

#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void Timer0_Init()
{
//  TCCR0B = 0;
//  TCCR0B |= (1<<CS00)|(0<<CS01)|(0<<CS02);                      // Тактирование от CLK.
  sbi(TCCR0B, CS00);
  cbi(TCCR0B, CS01);
  cbi(TCCR0B, CS02);
  OCR0B = 0;
  TIMSK0 = (1<<OCIE0B);                  // Разрешить прерывание по совпадению B
}
// таймер 1 обслуживает банки 0 и 1
void Timer1_Init()
{
  TCCR1B   =   0;   //stop timer
  TCCR1A   =   0;
  TCNT1   =    0;   //setup
  TCCR1A   =   0;
  TCCR1B = (1<<CS10); 
  //TCCR1B = 0<<CS12 | 1<<CS11 | 0<<CS10;
  TIMSK1 = (1<<OCIE1A) | (1<<OCIE1B);   // Разрешить прерывание по совпадению
  OCR1A = 0;
  OCR1B = 0;
}

ISR (TIMER1_COMPA_vect)
{
  UpdateBankA();
}

ISR (TIMER1_COMPB_vect)
{
  UpdateBankB();
}
uint16_t bankc_count = 0;
uint16_t bankc_dsk = 0;
ISR (TIMER0_COMPB_vect)
{
  if (bankc_count == 1)
  {
    bankc_count--;
    OCR0B = bankc_dsk;
  }
  if (bankc_count==0)
  {
    UpdateBankC();
  }
  else bankc_count--;
}

// таймер 2 используем для формирования частоты 50Гц
void Timer2_Init()
{
  TCCR2B   =   0;   //stop timer
  TCCR2A   =   0;
  TCNT2   =    0;   //setup
  TCCR2A   =   0;
  TCCR2A = 1<<WGM21;
  TCCR2B = (1<<CS20)|(1<<CS21)|(1<<CS22); // CLK/1024 
  TIMSK2 = 1<<OCIE2A;
  OCR2A = 155;
}

uint8_t timer2_cnt = 0;
ISR(TIMER2_COMPA_vect) {
  timer2_cnt++;
  if (timer2_cnt > 1)
  {
    timer2_cnt = 0;
    AllBankReset();
  }
}

void AllBankReset()
{
  // сбросить банки сервоприводов
  CurrServoA = -1;
  OCR1A = TCNT1 + (TIME_OFFSET_BANK_A << 4);
  
  CurrServoB = -1;
  OCR1B = TCNT1 + (TIME_OFFSET_BANK_B << 4);
  
  CurrServoC = -1;
  OCR0B = (TIME_OFFSET_BANK_C << 4);
  bankc_count=0;
  TCNT0=0;
}

void ServoOn(uint8_t ch)
{
  switch(ch)
  {
    case 0: CH0_on; break;
    case 1: CH1_on; break;
    case 2: CH2_on; break;
    case 3: CH3_on; break;
    case 4: CH4_on; break;
    case 5: CH5_on; break;
    case 6: CH6_on; break;
    case 7: CH7_on; break;
    case 8: CH8_on; break;
    case 9: CH9_on; break;
    case 10: CH10_on; break;
    case 11: CH11_on; break;
    case 12: CH12_on; break;
    case 13: CH13_on; break;
    case 14: CH14_on; break;
    case 15: CH15_on; break;
    case 16: CH16_on; break;
    case 17: CH17_on; break;
  }
}

void ServoOff(uint8_t ch)
{
  switch(ch)
  {
    case 0: CH0_off; break;
    case 1: CH1_off; break;
    case 2: CH2_off; break;
    case 3: CH3_off; break;
    case 4: CH4_off; break;
    case 5: CH5_off; break;
    case 6: CH6_off; break;
    case 7: CH7_off; break;
    case 8: CH8_off; break;
    case 9: CH9_off; break;
    case 10: CH10_off; break;
    case 11: CH11_off; break;
    case 12: CH12_off; break;
    case 13: CH13_off; break;
    case 14: CH14_off; break;
    case 15: CH15_off; break;
    case 16: CH16_off; break;
    case 17: CH17_off; break;
  }
}

void UpdateBankA()
{
  if (CurrServoA >= 0) ServoOff(CurrServoA+OFFSET_BANK_A);
  CurrServoA++;
  uint8_t indxA = CurrServoA + OFFSET_BANK_A;
  
  while (CurrServoA<COUNT_BANK_A && !servos[indxA].enabled) 
  {
    CurrServoA++;
    indxA = CurrServoA + OFFSET_BANK_A;
  }
  
  if (CurrServoA<COUNT_BANK_A) {
    if (servos[indxA].speed_count == 0) 
      OCR1A = TCNT1 + (servos[indxA].destination<<4);
    else {
      servos[indxA].speed_curr_count++;
      if (servos[indxA].speed_curr_count >= servos[indxA].speed_count) {
        servos[indxA].speed_curr_count = 0;
        if (servos[indxA].value < servos[indxA].destination){
          servos[indxA].value+=servos[indxA].speed_step;
          if (servos[indxA].value > servos[indxA].destination) servos[indxA].value = servos[indxA].destination;
        } else
        if (servos[indxA].value > servos[indxA].destination){
          servos[indxA].value-=servos[indxA].speed_step;
          if (servos[indxA].value < servos[indxA].destination) servos[indxA].value = servos[indxA].destination;
        }
      }
      OCR1A = TCNT1 + (servos[indxA].value << 4);
    }
    ServoOn(indxA);
  }
}

void UpdateBankB()
{
  if (CurrServoB >= 0) ServoOff(CurrServoB + OFFSET_BANK_B);
  CurrServoB++;
  uint8_t indx = CurrServoB + OFFSET_BANK_B;
  while (CurrServoB<COUNT_BANK_B && !servos[indx].enabled) 
  {
    CurrServoB++;
    indx = CurrServoB + OFFSET_BANK_B;
  }
  if (CurrServoB<COUNT_BANK_B) {
    if (servos[indx].speed_count == 0)
      OCR1B = TCNT1 + (servos[indx].destination << 4);
    else {
      servos[indx].speed_curr_count++;
      if (servos[indx].speed_curr_count >= servos[indx].speed_count) {
        servos[indx].speed_curr_count = 0;
        if (servos[indx].value < servos[indx].destination){
          servos[indx].value+=servos[indx].speed_step;
          if (servos[indx].value > servos[indx].destination) servos[indx].value = servos[indx].destination;
        } else
        if (servos[indx].value > servos[indx].destination){
          servos[indx].value-=servos[indx].speed_step;
          if (servos[indx].value < servos[indx].destination) servos[indx].value = servos[indx].destination;
        }
      }
      OCR1B = TCNT1 + (servos[indx].value << 4);
    }
    ServoOn(indx);
  }
}

void UpdateBankC()
{
  if (CurrServoC >= 0) ServoOff(CurrServoC + OFFSET_BANK_C);
  CurrServoC++;
  uint8_t indx = CurrServoC + OFFSET_BANK_C;
  while (CurrServoC<COUNT_BANK_C && !servos[indx].enabled) 
  {
    CurrServoC++;
    indx = CurrServoC + OFFSET_BANK_C;
  }
  if (CurrServoC<COUNT_BANK_C) {
    if (servos[indx].speed_count == 0) 
    {
      bankc_count = (servos[indx].destination << 4)>>8;
      bankc_count--;
      bankc_dsk = (servos[indx].destination << 4) & 0xff;
      if (bankc_dsk + bankc_count> 255)
      {
        bankc_count++;
        bankc_dsk = bankc_dsk + bankc_count - 255;
      }
      else
      {
        bankc_dsk = bankc_dsk + bankc_count;
      }
      OCR0B = 255;
      TCNT0=0;
    }
    else {
      servos[indx].speed_curr_count++;
      if (servos[indx].speed_curr_count >= servos[indx].speed_count) {
        servos[indx].speed_curr_count = 0;
        if (servos[indx].value < servos[indx].destination){
          servos[indx].value+=servos[indx].speed_step;
          if (servos[indx].value > servos[indx].destination) servos[indx].value = servos[indx].destination;
        } else
        if (servos[indx].value > servos[indx].destination){
          servos[indx].value-=servos[indx].speed_step;
          if (servos[indx].value < servos[indx].destination) servos[indx].value = servos[indx].destination;
        }
      }
      bankc_count = (TCNT0 + (servos[indx].value << 4))>>8;
      bankc_dsk = (TCNT0 + (servos[indx].value << 4)) & 0xff;
      OCR0B = 255;
      //OCR0B = TCNT0 + (servos[indx].value << 4);
    }
    ServoOn(indx);
  }
}

void Servo_Init(uint8_t indx)
{
  servos[indx].value=1500;
  servos[indx].speed_step=4;
  servos[indx].speed_count=0;
  servos[indx].speed_curr_count=0;
  servos[indx].destination=1500;
  servos[indx].enabled=false;
}
