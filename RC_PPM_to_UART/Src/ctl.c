
/******************************************************************************
*  File           :  ctl.c
*  Version        :  1
*  Last Changes   :  2019-05-11 18:24:20
******************************************************************************/

/******************************************************************************
*  Include Files
******************************************************************************/

#include "typ.h"
#include "ctl.h"
#include "main.h"
#include "tim2.h"
#include "tim3.h"
#include "tim4.h"
#include "ser1.h"


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
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_tx;

tyun_AnyData unAnyData;

TUINT8 au8Temp[100];

/******************************************************************************
*  Global Variables
******************************************************************************/

TUINT8 CTL_Temp = 0;

TUINT8 CTL_FailSafe_Detected = 0;

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

void CTL_Ini (void)
{

}

/******************************************************************************
*  Function Name  :
*  Description    :
*  Parameter(s)   :
*  Return Value   :
******************************************************************************/

void CTL_Main (void)
{


	HAL_Delay(100);

	//sprintf((char*)SER1_au8SndBuf, "%d, %d, %d, %d, %d, %d, %d, %d\n", TIM2_u16Ch1_PulseTime, TIM2_u16Ch2_PulseTime, TIM2_u16Ch3_PulseTime, TIM2_u16Ch4_PulseTime, TIM3_u16Ch1_PulseTime, TIM3_u16Ch2_PulseTime, TIM3_u16Ch3_PulseTime, TIM3_u16Ch4_PulseTime);


	unAnyData.u16Data = TIM2_u16Ch1_PulseTime;
	au8Temp[0] = unAnyData.au8Data[0];
	au8Temp[1] = unAnyData.au8Data[1];

	unAnyData.u16Data = TIM2_u16Ch2_PulseTime;
	au8Temp[2] = unAnyData.au8Data[0];
	au8Temp[3] = unAnyData.au8Data[1];

	unAnyData.u16Data = TIM2_u16Ch3_PulseTime;
	au8Temp[4] = unAnyData.au8Data[0];
	au8Temp[5] = unAnyData.au8Data[1];

	unAnyData.u16Data = TIM2_u16Ch4_PulseTime;
	au8Temp[6] = unAnyData.au8Data[0];
	au8Temp[7] = unAnyData.au8Data[1];




	unAnyData.u16Data = TIM3_u16Ch1_PulseTime;
	au8Temp[8] = unAnyData.au8Data[0];
	au8Temp[9] = unAnyData.au8Data[1];

	unAnyData.u16Data = TIM3_u16Ch2_PulseTime;
	au8Temp[10] = unAnyData.au8Data[0];
	au8Temp[11] = unAnyData.au8Data[1];

	unAnyData.u16Data = TIM3_u16Ch3_PulseTime;
	au8Temp[12] = unAnyData.au8Data[0];
	au8Temp[13] = unAnyData.au8Data[1];

	unAnyData.u16Data = TIM3_u16Ch4_PulseTime;
	au8Temp[14] = unAnyData.au8Data[0];
	au8Temp[15] = unAnyData.au8Data[1];

	au8Temp[16] = CTL_FailSafe_Detected;


	SER1_Send_Protocol(au8Temp, 17);


	HAL_UART_Transmit_DMA(&huart1, SER1_au8SndBuf, SER1_TransmitFrameLength) ;


}





/******************************************************************************
*  Changes        :  
*                    
*                    
*                    
******************************************************************************/

/******************************************************************************
*  END OF FILE    :  ctl.h
******************************************************************************/
