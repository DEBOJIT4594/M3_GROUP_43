#include <stdio.h>
#include "MyStm32f407xx.h"
#include<stdbool.h>
#define GPIOD_Pin
#define GPIO_PCC
#define lock()
#define unlock()
#define GPIO_Init
#define GPIO_ReadFromInputPin


#define BUTTON_PRESSED ENABLE

int encryption()

{ 
   bool flag = false;
   const int a = 100;
   const int b = 120;
   int result = a * b;
   if(result==12000)
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
      for (uint32_t i = 0; i < 12000; i++);
   }
   void unlock_door(void)
   {
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_12, 0);
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_13, 0);
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_14, 0);
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_15, 0);

   }
   void lock_door(void)
   {
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_12, 1);
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_13, 1);
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_14, 1);
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_15, 1);

   }
   void Alarm_Activation_Deactivation(void)
   {
      
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_12);
      delay();
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_13);
      delay();
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_14);
      delay();
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_15);
      delay();

   }
   void Approach_light(void)
   {
     
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_15);
      delay();
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_14);
      delay();
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_13);
      delay();
      GPIOD_Pin(GPIOD, GPIO_PIN_NO_12);
      delay();
      
   }
   int main(void)
   {   
      int count = 0;
      GPIO_Handle_t GpioLED, GpioLED1, GpioLED2, GpioLED3, GPIOBUTTON;

      GpioLED.pGPIOx = GPIOD;
      GpioLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
      GpioLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PCC(GPIOD, ENABLE);
      GPIO_Init(&GpioLED);

      GpioLED1.pGPIOx = GPIOD;
      GpioLED1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
      GpioLED1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLED1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLED1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PCC(GPIOD, ENABLE);
      GPIO_Init(&GpioLED1);

      GpioLED2.pGPIOx = GPIOD;
      GpioLED2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
      GpioLED2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLED2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLED2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PCC(GPIOD, ENABLE);
      GPIO_Init(&GpioLED2);

      GpioLED3.pGPIOx = GPIOD;
      GpioLED3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
      GpioLED3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLED3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLED3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PCC(GPIOD, ENABLE);
      GPIO_Init(&GpioLED3);

      GPIOBUTTON.pGPIOx = GPIOA;
      GPIOBUTTON.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
      GPIOBUTTON.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
      GPIOBUTTON.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GPIOBUTTON.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
      GPIO_PCC(GPIOA, ENABLE);
      GPIO_Init(&GPIOBUTTON);
      
      if (encryption())
      {

         while (1)
         {
            if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BUTTON_PRESSED)
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
