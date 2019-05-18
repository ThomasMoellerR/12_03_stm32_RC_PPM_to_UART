
/******************************************************************************
*  File           :  fse.h
*  Version        :  1
*  Last Changes   :  2019-05-18 14:50:58
******************************************************************************/

#ifndef __FSE_H
#define __FSE_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
*  Include Files
******************************************************************************/

#include "typ.h"

/******************************************************************************
*  Global Constants
******************************************************************************/

/******************************************************************************
*  Global Type Definitions
******************************************************************************/

/******************************************************************************
*  Global Variables
******************************************************************************/

extern TUINT8 FSE_Temp;

extern TUINT16 FSE_u16FailSafe_LEDisBlinkingCounter;
extern TUINT8 FSE_u8FailSafe_LEDisBlinking;




/******************************************************************************
*  Global Function Prototypes
******************************************************************************/

extern void FSE_Ini (void);

/******************************************************************************
*  Changes        :  
*                    
*                    
*                    
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __FSE_H */

/******************************************************************************
*  END OF FILE    :  fse.h
******************************************************************************/
