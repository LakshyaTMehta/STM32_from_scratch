#ifndef MAIN_H_
#define MAIN_H_

/* includes */
#include <stdint.h>

/* macro definitions */
#define RCC_CR (0x40023800U)
#define RCC_CFGR (0x40023808U)
#define RCC_AHB1ENR (0x40023830U)
#define GPIOD_MODER (0x40020C00U)
#define GPIOD_ODR (0x40020C14U)

/* type definitions */
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

/* function prototypes */
int main(void);

#endif
