#include "main.h"

#define RCC_ORIGIN_ADDRESS (0x40023800U)
#define RCC_CR_OFFSET (0x00U)
#define RCC_CFGR_OFFSET (0x08U)

#pragma pack(1)
typedef struct Reg_RCC_CR{
  uint32_t HSION : 1;
  uint32_t HSIRDY : 1;
  uint32_t RES0 : 1;
  uint32_t HSITRIM : 5;
  uint32_t HSICAL : 8;
  uint32_t HSEON : 1;
  uint32_t HSERDY : 1;
  uint32_t HSEBPY : 1;
  uint32_t CSSON : 1;
  uint32_t RES1 : 4;
  uint32_t PLLON : 1;
  uint32_t PLLRDY : 1;
  uint32_t PLLI2SON : 1;
  uint32_t PLLI2SRDY : 1;
  uint32_t PLLSAION : 1;
  uint32_t PLLSAIRDY : 1;
  uint32_t RES2 : 2;
} *pReg_RCC_CR;

#pragma pack(1)
typedef struct Reg_RCC_CFGR{
  uint32_t SW0 : 1;
  uint32_t SW1 : 1;
  uint32_t SWS0 : 1;
  uint32_t WS1 : 1;
  uint32_t HPRE : 4;
  uint32_t RES0 : 2;
  uint32_t PPRE1 : 3;
  uint32_t PPRE2 : 3;
  uint32_t RTCPRE : 5;
  uint32_t MCO1 : 2;
  uint32_t I2SSCR : 1;
  uint32_t MCO1PRE : 3;
  uint32_t MCO2PRE : 3;
  uint32_t MCO2 : 2;
} *pReg_RCC_CFGR;

pReg_RCC_CR RCC_CR = RCC_ORIGIN_ADDRESS + RCC_CR_OFFSET;
pReg_RCC_CFGR RCC_CFGR = RCC_ORIGIN_ADDRESS + RCC_CFGR_OFFSET;

#define LED_PORT 

int main(void)
{
  RCC_CR->HSION = 1U;
  while(!(RCC_CR->HSIRDY));
  RCC_CFGR->PPRE1 = 4U;
  RCC_CFGR->PPRE2 = 4U;
  return 0;
}
