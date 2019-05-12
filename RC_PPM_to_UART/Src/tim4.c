
/******************************************************************************
*  File           :  TIM4.c
*  Version        :  1
*  Last Changes   :  2019-05-11 13:46:42
******************************************************************************/

/******************************************************************************
*  Include Files
******************************************************************************/

#include "typ.h"
#include "TIM4.h"
#include "main.h"
#include "tim2.h"
#include "tim3.h"
#include "ctl.h"

/******************************************************************************
*  Local Constants
******************************************************************************/

/******************************************************************************
*  Local Type Definitions
******************************************************************************/

/******************************************************************************
*  Local Variables
******************************************************************************/

TIM_HandleTypeDef htim4;

/******************************************************************************
*  Global Variables
******************************************************************************/

TUINT8 TIM4_Temp = 0;


TUINT16 TIM4_TIM2_u16Ch1_Counter;
TUINT16 TIM4_TIM2_u16Ch2_Counter;
TUINT16 TIM4_TIM2_u16Ch3_Counter;
TUINT16 TIM4_TIM2_u16Ch4_Counter;

TUINT16 TIM4_TIM3_u16Ch1_Counter;
TUINT16 TIM4_TIM3_u16Ch2_Counter;
TUINT16 TIM4_TIM3_u16Ch3_Counter;
TUINT16 TIM4_TIM3_u16Ch4_Counter;

TUINT16 EXTI_PC13_Counter;

/******************************************************************************
*  Local Function Prototypes
******************************************************************************/

/******************************************************************************
*  Local Functions
******************************************************************************/

/******************************************************************************
*  Global Functions
******************************************************************************/

/******************************************************************************
*  Function Name  :  
*  Description    :  
*  Parameter(s)   :  
*  Return Value   :  
******************************************************************************/

void TIM4_Ini (void)
{
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_NVIC_EnableIRQ(TIM4_IRQn);
}

/******************************************************************************
*  Function Name  :
*  Description    :
*  Parameter(s)   :
*  Return Value   :
******************************************************************************/

void TIM4_HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	// Fail Safe LED detection

	if (!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)) // Inverse logic
	{
		CTL_FailSafe_Detected = 0; // Wenne High dann kein Failsafe
	}
	else
	{
		CTL_FailSafe_Detected = 1;
	}


	/*
	if (EXTI_PC13_Counter < 100)
	{
		EXTI_PC13_Counter++;
	}
	else
	{
		// Fail Safe action

		CTL_FailSafe_Detected = 1;
	}
	*/


	// Channels
	TIM4_TIM2_u16Ch1_Counter++;
	TIM4_TIM2_u16Ch2_Counter++;
	TIM4_TIM2_u16Ch3_Counter++;
	TIM4_TIM2_u16Ch4_Counter++;

	if (TIM4_TIM2_u16Ch1_Counter < TIMEOUT_TICKS)
	{
		TIM4_TIM2_u16Ch1_Counter++;
	}
	else
	{
		TIM2_u16Ch1_PulseTime = 0;
	}


	if (TIM4_TIM2_u16Ch2_Counter < TIMEOUT_TICKS)
	{
		TIM4_TIM2_u16Ch2_Counter++;
	}
	else
	{
		TIM2_u16Ch2_PulseTime = 0;
	}


	if (TIM4_TIM2_u16Ch3_Counter < TIMEOUT_TICKS)
	{
		TIM4_TIM2_u16Ch3_Counter++;
	}
	else
	{
		TIM2_u16Ch3_PulseTime = 0;
	}


	if (TIM4_TIM2_u16Ch4_Counter < TIMEOUT_TICKS)
	{
		TIM4_TIM2_u16Ch4_Counter++;
	}
	else
	{
		TIM2_u16Ch4_PulseTime = 0;
	}


	TIM4_TIM3_u16Ch1_Counter++;
	TIM4_TIM3_u16Ch2_Counter++;
	TIM4_TIM3_u16Ch3_Counter++;
	TIM4_TIM3_u16Ch4_Counter++;

	if (TIM4_TIM3_u16Ch1_Counter < TIMEOUT_TICKS)
	{
		TIM4_TIM3_u16Ch1_Counter++;
	}
	else
	{
		TIM3_u16Ch1_PulseTime = 0;
	}


	if (TIM4_TIM3_u16Ch2_Counter < TIMEOUT_TICKS)
	{
		TIM4_TIM3_u16Ch2_Counter++;
	}
	else
	{
		TIM3_u16Ch2_PulseTime = 0;
	}


	if (TIM4_TIM3_u16Ch3_Counter < TIMEOUT_TICKS)
	{
		TIM4_TIM3_u16Ch3_Counter++;
	}
	else
	{
		TIM3_u16Ch3_PulseTime = 0;
	}


	if (TIM4_TIM3_u16Ch4_Counter < TIMEOUT_TICKS)
	{
		TIM4_TIM3_u16Ch4_Counter++;
	}
	else
	{
		TIM3_u16Ch4_PulseTime = 0;
	}
}

/******************************************************************************
*  Changes        :  
*                    
*                    
*                    
******************************************************************************/

/******************************************************************************
*  END OF FILE    :  TIM4.h
******************************************************************************/
