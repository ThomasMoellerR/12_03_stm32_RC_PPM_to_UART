
/******************************************************************************
*  File           :  tim2.c
*  Version        :  1
*  Last Changes   :  2019-05-08 14:53:40
******************************************************************************/

/******************************************************************************
*  Include Files
******************************************************************************/

#include "typ.h"
#include "tim2.h"
#include "main.h"
#include "tim4.h"

/******************************************************************************
*  Local Constants
******************************************************************************/

/******************************************************************************
*  Local Type Definitions
******************************************************************************/

/******************************************************************************
*  Local Variables
******************************************************************************/

TIM_HandleTypeDef htim2;

TUINT16 tim2_u16Ch1_Capture_Rising_Edge;
TUINT16 tim2_u16Ch1_Capture_Falling_Edge;
TUINT16 tim2_u16Ch2_Capture_Rising_Edge;
TUINT16 tim2_u16Ch2_Capture_Falling_Edge;
TUINT16 tim2_u16Ch3_Capture_Rising_Edge;
TUINT16 tim2_u16Ch3_Capture_Falling_Edge;
TUINT16 tim2_u16Ch4_Capture_Rising_Edge;
TUINT16 tim2_u16Ch4_Capture_Falling_Edge;

/******************************************************************************
*  Global Variables
******************************************************************************/

TUINT16 TIM2_u16Ch1_PulseTime;
TUINT16 TIM2_u16Ch2_PulseTime;
TUINT16 TIM2_u16Ch3_PulseTime;
TUINT16 TIM2_u16Ch4_PulseTime;


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

void TIM2_Ini (void)
{
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_3);
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_4);

	HAL_TIM_Base_Start_IT(&htim2);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

/******************************************************************************
*  Function Name  :
*  Description    :
*  Parameter(s)   :
*  Return Value   :
******************************************************************************/

void TIM2_HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance==TIM2)
	{
		if (htim->Channel==HAL_TIM_ACTIVE_CHANNEL_1)
		{
			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0))
			{
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);

				tim2_u16Ch1_Capture_Rising_Edge = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_1);
			}

			if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0))
			{
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);

				tim2_u16Ch1_Capture_Falling_Edge = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_1);

				TIM2_u16Ch1_PulseTime = tim2_u16Ch1_Capture_Falling_Edge - tim2_u16Ch1_Capture_Rising_Edge;
			}

			TIM4_TIM2_u16Ch1_Counter = 0;
		}


		if (htim->Channel==HAL_TIM_ACTIVE_CHANNEL_2)
		{
			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1))
			{
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);

				tim2_u16Ch2_Capture_Rising_Edge = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_2);

			}

			if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1))
			{
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);

				tim2_u16Ch2_Capture_Falling_Edge = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_2);

				TIM2_u16Ch2_PulseTime = tim2_u16Ch2_Capture_Falling_Edge - tim2_u16Ch2_Capture_Rising_Edge;
			}

			TIM4_TIM2_u16Ch2_Counter = 0;
		}


		if (htim->Channel==HAL_TIM_ACTIVE_CHANNEL_3)
		{
			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2))
			{
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_FALLING);

				tim2_u16Ch3_Capture_Rising_Edge = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_3);
			}

			if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2))
			{
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_RISING);

				tim2_u16Ch3_Capture_Falling_Edge = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_3);

				TIM2_u16Ch3_PulseTime = tim2_u16Ch3_Capture_Falling_Edge - tim2_u16Ch3_Capture_Rising_Edge;
			}

			TIM4_TIM2_u16Ch3_Counter = 0;
		}


		if (htim->Channel==HAL_TIM_ACTIVE_CHANNEL_4)
		{
			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3))
			{
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_4, TIM_INPUTCHANNELPOLARITY_FALLING);

				tim2_u16Ch4_Capture_Rising_Edge = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_4);
			}

			if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3))
			{
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_4, TIM_INPUTCHANNELPOLARITY_RISING);

				tim2_u16Ch4_Capture_Falling_Edge = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_4);

				TIM2_u16Ch4_PulseTime = tim2_u16Ch4_Capture_Falling_Edge - tim2_u16Ch4_Capture_Rising_Edge;
			}

			TIM4_TIM2_u16Ch4_Counter = 0;
		}

	  }
}


/******************************************************************************
*  Changes        :  
*                    
*                    
*                    
******************************************************************************/

/******************************************************************************
*  END OF FILE    :  tim2.h
******************************************************************************/
