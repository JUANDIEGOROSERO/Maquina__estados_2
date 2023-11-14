/*!
\file   sensor.c
\date   2023-10-24
\author Juan Rosero <juandrosero@unicauca.edu.co>
\brief  Estado de los sensores Digitales.

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
#include "KEYPAD.h"
#include "LCD.h"
#include "color_rgb.h"
#include "sensor.h"
#include "Seguridad.h"
#include "Bloqueo.h"
#include "Monitoreo.h"
#include "Alarma.h"

/*F**************************************************************************
* NAME: monitoring_sensor
*----------------------------------------------------------------------------
* PARAMS:   none
* return:   
* alarm_activ: valor sensor digital.
*----------------------------------------------------------------------------
* PURPOSE:
* Informacion de Bandera alarma.
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/
unsigned char monitoring_sensor(void){
    unsigned char alarm_activ = 1;  // Variable que indica si la alarma está activada (inicialmente activada).

    // Verificar el estado del sensor infrarrojo (SENSOR_IR).
    if (SENSOR_IR == 0) {
        alarm_activ = 0;  // Desactivar la bandera alarma si el sensor infrarrojo está activado.
    }

    // Verificar el estado del sensor Hall (SENSOR_HALL).
    if (SENSOR_HALL == 0) {
        alarm_activ = 0;  // Desactivar la alarma bandera si el sensor Hall está activado.
    }

    // Verificar el estado del sensor de metal (SENSOR_METAL).
    if (SENSOR_METAL == 0) {
        alarm_activ = 0;  // Desactivar la alarma bandera si el sensor de metal está activado.
    }

    return alarm_activ;  // Devolver el estado de la bandera alarma después de verificar todos los sensores.
}

