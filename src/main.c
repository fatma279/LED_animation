/*   Author  : FATMA           */
/*   Date    : 24 July 2021    */
/*   Version : V1              */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "LED_interface.h"

void main(void)
{
	/*  Enable Peripheral Clock  */
	 RCC_voidInitSysClock();
     RCC_voidEnablePeripheralClock(RCC_APB2, RCC_PORTA);


	/* set Pins direction */
     GPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_2MHZ_PP);
     GPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP);
     GPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP);
     GPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_2MHZ_PP);
     GPIO_voidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_2MHZ_PP);
     GPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_2MHZ_PP);
     GPIO_voidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_2MHZ_PP);
     GPIO_voidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_2MHZ_PP);

     /* initiate timer */
      STK_voidInit();

  // Infinite loop
  while (1)
    {
     // shift left and shift right for 4 times
	  LED_voidShiftLedRightLed(4);
      //delay for 1s
	 STK_voidSetBusyWait(8000000);

	 // in out for 4 times
	 LED_voidLedOnLedOut(4);
	 //delay for 1s
	 STK_voidSetBusyWait(8000000);

	 // flashing 8 times
	  LED_voidTFlashingLed(8);
	  //delay for 1s
	  STK_voidSetBusyWait(8000000);
    }
}

