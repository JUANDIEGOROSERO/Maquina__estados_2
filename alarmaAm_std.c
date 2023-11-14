/*!
\file   alarmaAm_std.c
\date   2023-11-01
\author Juan Rosero <jandrosero@unicauca.edu.co>
\brief  Estado alarma ambiental.

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
#include "CONFIG.h"
#include "color_RGB.h"
#include "LCD.h"


/*F**************************************************************************
* NAME: Funcion_Alarma_Ambinental
*----------------------------------------------------------------------------
* PARAMS:   none
* return:   none
*----------------------------------------------------------------------------
* PURPOSE:
* Informacion de estado actual en LCD
* Parpadedo de LED rojo 
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/

void Funcion_Alarma_Ambiental(void){
       LCD_String_xy(0,0,"Alarm Amb Activ");    //Escribimos en el LCD que se encuentra en el estado alarma ambiental
       color(1,0,0);                            //Encendemos un LED rojo
       __delay_ms(1000);                        //Creamos un retraso de un segundo
       color(0,0,0);                            //Apagamos el LED 
       __delay_ms(1000);                        //Creamos un retraso de un segundo
       LCD_Clear();                             //El LCD se limpia
}

