/*!
\file   temperatura.c
\date   2023-10-27
\author Juan Rosero <juandrosero@unicauca.edu.co>
\brief  Conversion a grados celsius.

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
#include    <math.h>
#define     beta  4090 

/*F**************************************************************************
* NAME: convertir_temperatura
*----------------------------------------------------------------------------
* PARAMS:
* temperatura: Valor de la temperatura dada por el sensor analogico.
* return:
* TempC: Temperatura convertida a grdos celsius
*----------------------------------------------------------------------------
* PURPOSE:
* Informacion de estado actual en LCD
* Parpadedo de LED rojo 
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/
int convertir_temperatura(int temperatura){
 // Ajustar el valor analógico a la escala específica del sensor.
    long a = 1023 - temperatura;

    // Calcular la temperatura en grados Celsius utilizando la ecuación de Steinhart-Hart.
    // Esta ecuación se utiliza comúnmente para sensores de temperatura NTC.
    float TempC = (float)(beta / (log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0);

    // Ajustar la temperatura para corregir la desviación específica del sensor.
    float Tempc = TempC - 55;

    // Devolver la temperatura convertida a grados Celsius como un entero.
    return (int) Tempc;
}

