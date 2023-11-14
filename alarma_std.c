/*!
\file   alarma_std.c
\date   2023-10-13
\author Juan Rosero <juandrosero@unicauca.edu.co>
\brief  Estado alarma.

\par Copyright
Information contained herein is proprietary to and constitutes valuable
confidential trade secrets of unicauca, and
is subject to restrictions on use and disclosure.

\par
Copyright (c) unicauca 2022. All rights reserved.

\par
The copyright notices above do not evidence any actual or
intended publication of this material.
******************************************************************************
*/
#include <xc.h>
#include <PIC16F887.h>
#include <stdio.h>  
#include <string.h>

#include "CONFIG.h"
#include "LCD.h"
#include "color_rgb.h"


/*F**************************************************************************
* NAME: function_alarma
*----------------------------------------------------------------------------
* PARAMS:   none
* return:   none
*----------------------------------------------------------------------------
* PURPOSE:
* Informacion de estado actual en LCD.
* Enciende LED rojo.
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/

void function_alarma(void){
    
    LCD_Clear();                        //El LCD se limpia
    LCD_String_xy(0,0,"std_Alarma");    //Escribimos en el LCD que se encuentra en el estado alarma
    color(1,0,0);                       //Encendemos un LED rojo
    __delay_ms(1000);                   //Creamos un retraso de 1 segundo

}

