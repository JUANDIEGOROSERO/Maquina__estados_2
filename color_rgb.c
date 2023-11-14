/*!
\file   color_rgb.c
\date   2023-10-06
\author Juan Rosero <juandrosero@unicauca.edu.co>
\brief  Funcion para cambiar color de LED RGB.

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
#include "color_rgb.h"

/*F**************************************************************************
* NAME: color
*----------------------------------------------------------------------------
* PARAMS:   
* red:   Valor para el led rojo.
* green: Valor para el led verde.
* blue:  Valor para el led azul
* return:   none
*----------------------------------------------------------------------------
* PURPOSE:
* Generar color rojo, azul o verde y sus combinaciones para un Led RGB. 
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/

void color(unsigned char red,unsigned char green, unsigned char blue){
    ldatae = 0;
    rojo   = red;
    verde  = green;
    azul   = blue;
}
