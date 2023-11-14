/*!
\file   main_maquina_st.c
\date   2023-11-07
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
#include "KEYPAD.h"
#include "LCD.h"
#include "Seguridad.h"
#include "Bloqueo.h"
#include "Monitoreo.h"
#include "Alarma.h"
#include "Monitoreo_ambiental.h"
#include "Alarma_ambiental.h"
#include "color_rgb.h"
#include "sensor.h"
#include "canal.h"
#include "temperatura.h"

//Asignacion de cada uno de los estados en la variable State
enum State {
    Seguridad,      // Se asigna 0
    Monitoreo,      // Se asigna 1
    Bloqueado,      // Se asigna 2
    Alarma,         // Se asigna 3
    Monitoreo_Am,   // Se asigna 4
    Alarma_Am
};

enum State Estado;

/*F**************************************************************************
* NAME: main
*----------------------------------------------------------------------------
* PARAMS:   none
* return:   none
*----------------------------------------------------------------------------
* PURPOSE:
* Maquina de estados relacionada con el control de una Casa Inteligente. 
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/
void main() {
    OSCCON = 0x71;  // Configura el oscilador interno a 8MHz.

    TRISD = 0x00;   // Configura el puerto D como salida.

    TRISA0 = 1;     // Configura RA0 como entrada para el Sensor Analógico 1.
    TRISA1 = 1;     // Configura RA1 como entrada para el Sensor Analógico 2.
    TRISA5 = 1;     // Configura RA5 como entrada para el Sensor Analógico 3.

    TRISC = 0x07;   // Configura los bits RC0, RC1, y RC2 como entrada.

    ANSEL = 0x01;   // Configura el puerto como entrada analógica.

    adc_begin();    // Inicializa el módulo ADC.
    LCD_Init();     // Inicializa el LCD.
    keypad_init();  // Inicializa el teclado numérico.

    Estado = Seguridad;  // Inicializa el estado del sistema como Seguridad.

    while (1) {
        /**
        * Implementación de la lógica de control de estados en el sistema de seguridad.
        *
        * Este bloque de código representa la máquina de estados del sistema de seguridad.
        * El sistema tiene varios estados, como Seguridad, Bloqueado, Monitoreo, Alarma,
        * Monitoreo Ambiental y Alarma Ambiental. La lógica de transición entre estos estados
        * se basa en las funciones correspondientes y en la detección de eventos específicos.
        */
        if (Estado == Seguridad) {
        // En el estado de Seguridad, se llama a la función funcion_seguridad,
        // la cual solicita la entrada de una clave. Dependiendo del resultado,
        // se transiciona a los estados Monitoreo, Bloqueado o se permanece en Seguridad.
            unsigned char n = funcion_seguridad();
            if (n == 1) {
                Estado = Monitoreo;
            } else if (n == 2) {
                Estado = Bloqueado;
            } else {
                Estado = Seguridad;
            }
        }
        
        else if (Estado == Bloqueado) {
        // En el estado Bloqueado, se ejecuta la función function_bloqueado y luego
        // se transiciona de nuevo al estado de Seguridad.
            function_bloqueado();
            Estado = Seguridad;
        }
        
        else if (Estado == Monitoreo) {
        // En el estado Monitoreo, se realiza una espera de 2000 ms (2 segundos),
        // luego se llama a la función function_monitoreo. Dependiendo del resultado,
        // se transiciona a los estados Alarma o Monitoreo Ambiental.
            __delay_ms(2000);
            unsigned char m = function_monitoreo();
            if (m == 1) {
                 Estado = Alarma;
            } else {
                __delay_ms(2000);
                Estado = Monitoreo_Am;
            }
        }
        
        else if (Estado == Alarma) {
        // En el estado Alarma, se ejecuta la función function_alarma y luego
        // se transiciona al estado de Monitoreo.
            function_alarma();
            Estado = Monitoreo;
        }
        
        else if (Estado == Monitoreo_Am) {
        // En el estado Monitoreo Ambiental, se llama a la función function_monitoreo_ambiente.
        // Dependiendo del resultado, se transiciona a los estados Alarma Ambiental o Monitoreo.
            int b = function_monitoreo_ambiente();
            if (b == 1) {
                Estado = Alarma_Am;
            } else {
                Estado = Monitoreo;
            }
        }
        
        else if (Estado == Alarma_Am) {
        // En el estado Alarma Ambiental, se ejecuta la función Funcion_Alarma_Ambiental
        // y luego se transiciona al estado de Monitoreo Ambiental.
        Funcion_Alarma_Ambiental();
        Estado = Monitoreo_Am;
        }
    }
}

