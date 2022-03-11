#include <stdio.h>
#include "MyStm32f407xx.h"
#include<stdbool.h>


#define BTN_PRESSED ENABLE

int encrypt()

{ 
   bool flag = false;
   const int a = 123;
   const int b = 234;
   int result = a * b;
   if(result==28782)
   {

      flag= true;
   }
   else{

      flag=false;
   }

   return flag;
}
   void delay(void)
   {
      for (uint32_t i = 0; i < 5000000; i++);
   }
   void unlock(void)
   {
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0);
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0);

   }
   void lock(void)
   {
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 1);
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 1);
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 1);
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 1);

   }
   void Alarm_Activation_Deactivation(void)
   {
      
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
      delay();

   }
   void Approach_light(void)
   {
     
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
      delay();
      
   }
   int main(void)
   {   
      int count = 0;
      GPIO_Handle_t GpioLed, GPIOBtn, GpioLed1, GpioLed2, GpioLed3;

      GpioLed.pGPIOx = GPIOD;
      GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
      GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed);

      GpioLed1.pGPIOx = GPIOD;
      GpioLed1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
      GpioLed1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLed1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed1);

      GpioLed2.pGPIOx = GPIOD;
      GpioLed2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
      GpioLed2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLed2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed2);

      GpioLed3.pGPIOx = GPIOD;
      GpioLed3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
      GpioLed3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLed3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed3);

      GPIOBtn.pGPIOx = GPIOA;
      GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
      GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
      GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
      GPIO_PeriClockControl(GPIOA, ENABLE);
      GPIO_Init(&GPIOBtn);
      
      if (encrypt())
      {

         while (1)
         {
            if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED)
            {
               delay();
               count = count + 1;
            }
            if (count == 3)
            {
               lock();
            }
            else if (count == 9)
            {
                unlock();
            }
            else if (count==18)
            {

               Alarm_Activation_Deactivation();
            }
            else if (count==27)
            {
               Approach_light();
            }
         }
      }
   }