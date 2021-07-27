/*   Author  : FATMA           */
/*   Date    : 24 July 2021    */
/*   Version : V1              */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



 void LED_voidShiftLedRightLed(u8 copy_u8NumberOfIterations){
	 //iteration for scenario
	 for(u8 LoopCounter=0; LoopCounter<copy_u8NumberOfIterations; LoopCounter++)
	 {
	 //Right to Left
		for(u8 LedNumber = 0; LedNumber < 8; LedNumber++){
		  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], HIGH);
		  // delay for 2ms
		  STK_voidSetBusyWait(1600000);
		  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], LOW);
		  // delay for 2ms
		  STK_voidSetBusyWait(1600000);
		}

	//Left to Right
	  for(u8 LedNumber = 6; LedNumber > 0; LedNumber--){
	   GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], HIGH);
		  // delay for 2ms
		  STK_voidSetBusyWait(1600000);
	   GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], LOW);
		  // delay for 2ms
		  STK_voidSetBusyWait(1600000);
	 }

	 }
}


void LED_voidLedOnLedOut(u8 copy_u8NumberOfIterations){

     // iteration for scenario
	 for(u8 LoopCounter=0; LoopCounter<copy_u8NumberOfIterations; LoopCounter++)
	 {
		    u8 Local_u8Decreasing=3;
			u8 Local_u8Increasing=1;
	//From in to out
	for(u8 LedNumber = 4; LedNumber < 8; LedNumber++){
	  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], HIGH);
	  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[Local_u8Decreasing], HIGH);
	  // delay for 2ms
	  STK_voidSetBusyWait(1600000);

	  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], LOW);
	  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[Local_u8Decreasing], LOW);

	  Local_u8Decreasing--;
		// delay for 2ms
		 STK_voidSetBusyWait(1600000);

	}


		//From out to in
	for(u8 LedNumber = 6; LedNumber >= 4; LedNumber--){
	  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], HIGH);
	  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[Local_u8Increasing], HIGH);

	  // delay for 2ms
	  STK_voidSetBusyWait(1600000);

	  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], LOW);
	  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[Local_u8Increasing], LOW);

	  Local_u8Increasing++;

		// delay for 2ms
		 STK_voidSetBusyWait(1600000);

}
	 }
}


void LED_voidTFlashingLed(u8 copy_u8NumberOfIterations){
	//iteration for scenario
	 for(u8 LoopCounter=0; LoopCounter<copy_u8NumberOfIterations; LoopCounter++)
	 {
	//Led on

	for(u8 LedNumber = 0; LedNumber < 8; LedNumber++){
	  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], HIGH);
	}
	// delay for 2ms
	 STK_voidSetBusyWait(1600000);
		for(u8 LedNumber = 0; LedNumber < 8; LedNumber++){
	  GPIO_voidSetPinValue(LED_PORT, ArrayOfLeds[LedNumber], LOW);
	}
		// delay for 2ms
		 STK_voidSetBusyWait(1600000);
	 }
}
