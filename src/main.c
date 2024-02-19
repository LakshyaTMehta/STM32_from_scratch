#include "main.h"

int main(void)
{
  uint32_t *stmreg;
  
  /* HSI ON */
  stmreg = (uint32_t*) RCC_CR;
  *stmreg = 0UL;
  *stmreg |= 1U;
  while(!((*stmreg) & (1UL << 1)));

  /* Enable Clk for GPIOD */
  stmreg = (uint32_t*) RCC_AHB1ENR;
  *stmreg = 0UL;
  *stmreg |= (1UL << 3);

  /* set gpio mode as output for pin 12, 13, 14 and 15 */
  stmreg = (uint32_t*) GPIOD_MODER;
  *stmreg = 0UL;
  *stmreg |= (1UL << (12 * 2));
  *stmreg |= (1UL << (13 * 2));
  *stmreg |= (1UL << (14 * 2));
  *stmreg |= (1UL << (15 * 2));

  /* pointing to Output data register */
  stmreg = (uint32_t*) GPIOD_ODR;

  /* toggle pin 12 on and off */
  while(1)
  {
    *stmreg = (1UL << 12); 
    for(int i = 0; i < 0xFFFFUL; i++);
    *stmreg = (1UL << 13);
    for(int i = 0; i < 0xFFFFUL; i++);
    *stmreg = (1UL << 14);
    for(int i = 0; i < 0xFFFFUL; i++);
    *stmreg = (1UL << 15);
    for(int i = 0; i < 0xFFFFUL; i++);
  }

  return 0;
}
