/*!
\file   canal.c
\date   2023-10-18
\author Juan Rosero <juandrosero@unicauca.edu.co>
\brief  Seleci�n de canal y resultado de conversi�n.

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
#include    <xc.h>
#include    <pic16f887.h>
#include    "CONFIG.h"

/*F**************************************************************************
* NAME: adc_begin
*----------------------------------------------------------------------------
* PARAMS:   none
* return:   none
*----------------------------------------------------------------------------
* PURPOSE:
* Inicializaci�n de conversi�n.
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/
void adc_begin(void){
    
    ADCON1bits.ADFM  = 0;       //  Justificaci�n Izquierda (modo-8bits).
    ADCON1bits.VCFG0 = 0;       //  Selecciona Voltajes de Referencia (5v-0v).
    ADCON1bits.VCFG1 = 0;       //  Selecciona Voltajes de Referencia (5v-0v). 
    ADCON0bits.ADCS  = 0b01;    //  Tiempo de conversion Fosc/8.
}

/*F**************************************************************************
* NAME: adc_conversion
*----------------------------------------------------------------------------
* PARAMS:  
* channel: Pin utilizado para seleccionar el canal.
* return:   none
*----------------------------------------------------------------------------
* PURPOSE:
* Seleccion de canal para la conversi�n.
 * Resultado de la conversi�n.
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/
int adc_conversion(int channel){
        
        ADCON0bits.CHS = (0x0f & channel);  //  Seleccion de canal segun el pin utilizado.
        ADCON0bits.ADON = 1;                //  Habilita el M�dulo AD.
        __delay_us(30);
        ADCON0bits.GO = 1;                  //  Inicia la Conversi�n AD.
        while (ADCON0bits.GO);              //  Espera a que termine la conversi�n AD.
        ADCON0bits.ADON = 0;                //  Habilita el M�dulo AD.
        
        return ADRESH;                      //  Devolvemos el resultado de la conversion.
}