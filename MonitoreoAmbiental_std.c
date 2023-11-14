/*!
\file   MonitoreoAmbiental_std.c
\date   2023-10-25
\author Juan Rosero <juandrosero@unicauca.edu.co>
\brief  Monitoreo sesores analogicos.

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
#include    <stdio.h>
#include    <string.h>

#include    "CONFIG.h"
#include    "canal.h"
#include    "temperatura.h"
#include    "LCD.h"
#include    "color_rgb.h"

int Termometro;
int Fotocelda;
int Fuego;

char buffer [17];


/*F**************************************************************************
* NAME: function_monitoreo_ambiente
*----------------------------------------------------------------------------
* PARAMS:   none
* return:   
* var_Sensor_Ambiental: Bandera para el cambio de estado
*----------------------------------------------------------------------------
* PURPOSE:
* Informacion de el valor de los sensores en LCD.
* Informacion del estado en LCD.
* Informacion de Bandera para el cambio de estado.
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/

unsigned char function_monitoreo_ambiente(void) {
    
    // Variables internas
    int TempC= convertir_temperatura(Termometro);       // Temperatura en °C
    unsigned char var_Sensor_Ambiental;                 // Bandera Cambio de estado
    
    Termometro     = adc_conversion(0);                 // Valor de la Temperatura
    Fotocelda      = adc_conversion(1);                 // Valor de la Luz     
    Fuego          = adc_conversion(4);                 // Valor de la Fuego
            
    
    // Funcion
    if (TempC>=30){                                     // Si la temperatura es mayor a 30°C se cambiara de estado.
        
        LCD_String_xy(0,0,"MONIT AMBIENTAL");           // Informacion de estado en LCD.
        color(1,1,0);                                   // Led RGB indicador del estado.
            __delay_ms(1000);
            
            
            int n = sprintf(buffer,"T=%d,Fg=%d,L=%d",TempC,Fuego,Fotocelda);
            LCD_String_xy(1,0,buffer);                  // LCD muestra valor de Temperatura, Luz y Fuego.
            
            __delay_ms(2000);
            
            LCD_Clear(); 
            var_Sensor_Ambiental = 1;                   //Bandera de cambio de estado en 1.
    }
    
    else{
        
        var_Sensor_Ambiental = 0;                       //Bandera de cambio de estado en 0.
    }
    
    
    return var_Sensor_Ambiental;
}

