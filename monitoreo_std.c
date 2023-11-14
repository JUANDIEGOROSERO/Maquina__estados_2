/*!
\file   monitoreo_std.c
\date   2023-10-13
\author Juan Rosero <juandrosero@unicauca.edu.co>
\brief  Monitoreo sesores digitales.

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
#include <stdio.h>
#include <string.h>

#include "CONFIG.h"
#include "sensor.h"
#include "LCD.h"

unsigned char var_sensor_ir= 0;
unsigned char var_sensor_hall = 0;
unsigned char var_sensor_metal = 0;
char buffer [17];


/*F**************************************************************************
* NAME: function_monitoreo
*----------------------------------------------------------------------------
* PARAMS:   none
* return:   
* var_Sensor: Bandera para el cambio de estado
*----------------------------------------------------------------------------
* PURPOSE:
* Informacion del estado de los sensores en LCD.
* Informacion de que la alarma esta activada en LCD.
* Informacion de Bandera para el cambio de estado.
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/

unsigned char function_monitoreo(void){
    
    unsigned char var_Sensor;
    
    var_sensor_ir = SENSOR_IR;
    var_sensor_hall = SENSOR_HALL;
    var_sensor_metal = SENSOR_METAL;    // Asignamos a una bandera para saber si los sensores de metal, hall o Ir estan detectando algun evento sospechoso.
    
    if(monitoring_sensor()==1){         // Si la función que decta las señales de los sensore se activa
        
        sprintf(buffer,"ir=%d,hl=%d,mt=%d",var_sensor_ir,var_sensor_hall,var_sensor_metal); 
        LCD_String_xy(0,0,buffer);      // LCD muestra cual sensor se activo mostrando un 1 o 0.
        __delay_ms(5000);
        
        LCD_Clear();                            // LCD se limpia.
        LCD_String_xy(0,0,"Alarma Activada");   // LCD nos muestra que la alarma se activo.
        var_Sensor=1;                           // Bandera para cambiar de estado en 1.
    }
    else{
        var_Sensor=0;                           // // Bandera para cambiar de estado en 0.
    }
return var_Sensor;
}