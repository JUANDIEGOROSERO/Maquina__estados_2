/*!
\file   bloqueo_std.c
\date   2023-10-13
\author Juan Rosero <juandrosero@unicauca.edu.co>
\brief  Estado de Bloqueo.

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
* NAME: function_bloqueado
*----------------------------------------------------------------------------
* PARAMS:   none
* return:   none
*----------------------------------------------------------------------------
* PURPOSE:
* Informacion de estado actual en LCD. 
* Parpadeo de Led rojo.
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/

void function_bloqueado(void){

    LCD_Clear();
    LCD_String_xy(0,0,"Sistema BLOQUEADO"); //Escribimos en el LCD que se encuentra en el estado alarma
                                            
    color(1,0,0);
    __delay_ms(500);
    color(0,0,0);
    __delay_ms(500);
    color(1,0,0);
    __delay_ms(500);
    color(0,0,0);
    __delay_ms(500);
    color(1,0,0);
    __delay_ms(500);
    color(0,0,0);
    __delay_ms(500);
    color(1,0,0);
    __delay_ms(500);
    color(0,0,0);
    __delay_ms(500);
    color(1,0,0);
    __delay_ms(500);
    color(0,0,0);
    __delay_ms(500);                          //Parpadea un Led Rojo con lapsos de medio segundo                       
    
    LCD_Clear();                              //El LCD se limpia  
    __delay_ms(500);
}

