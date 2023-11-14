/*!
\file   seguridad_std.c
\date   2023-10-24
\author Juan Rosero <juandrosero@unicauca.edu.co>
\brief  Estado seguridad o clave.

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

unsigned char intento = 3;
const char password[4] ={'9','9','9','9'};
char pass_user[4];

/*F**************************************************************************
* NAME: funcion_seguridad
*----------------------------------------------------------------------------
* PARAMS:   none
* return:   
* n: Bandera para el cambio de estado
*----------------------------------------------------------------------------
* PURPOSE:
* Ingreso de la contraseña y visualizacion en LCD.
* Informacion de Bandera para el cambio de estado.
*----------------------------------------------------------------------------
* NOTE:
* 
*****************************************************************************/
unsigned char funcion_seguridad(void) {
    char key = '0';
    unsigned char idx = 0; // Índice para el arreglo de la contraseña ingresada.
    unsigned char n = 0;  // Bandera para indicar el resultado de la función.

    // Inicializar la pantalla LCD y establecer el color RGB.
    LCD_Clear();
    LCD_String_xy(0, 0, "Ingresar clave");
    LCD_Command(0xC0);
    color(1, 1, 1);

    // Leer la clave ingresada desde el teclado numérico.
    do {
        key = keypad_getkey();
        if (key != 0) {
            LCD_Char('*');  // Mostrar '*' en la pantalla LCD para cada tecla presionada.
            pass_user[idx++] = key;
        }
        __delay_ms(100);
    } while (idx < 4);

    // Verificar si la clave ingresada coincide con la clave almacenada.
    if (strncmp(pass_user, password, 4) == 0) {
        // Clave correcta.
        LCD_Clear();
        LCD_String_xy(0, 0, "Clave Correcta");

        // Cambiar el color RGB y realizar una secuencia visual.
        color(0, 1, 0);
        __delay_ms(500);
        color(0, 0, 0);
        __delay_ms(500);
        color(0, 1, 0);
        __delay_ms(500);
        color(0, 0, 0);
        __delay_ms(500);

        n = 1;  // Establecer la bandera de éxito.
    } else {
        // Clave incorrecta.
        if (intento > 1) {
            // Todavía hay más intentos permitidos.
            LCD_Clear();
            LCD_String_xy(0, 0, "Clave Incorrecta");

            // Cambiar el color RGB y realizar una secuencia visual.
            color(0, 0, 1);
            __delay_ms(500);
            color(0, 0, 0);
            __delay_ms(500);
            color(0, 0, 1);
            __delay_ms(500);
            color(0, 0, 0);
            __delay_ms(500);

            // Mostrar un mensaje para intentar nuevamente y reducir el contador de intentos.
            LCD_Clear();
            LCD_String_xy(0, 0, "intente otravez");
            intento--;
            n = 0;  // Establecer la bandera de reintentar.
        } else {
            // No hay más intentos permitidos.
            LCD_Clear();
            n = 2;  // Establecer la bandera de fracaso.
        }
    }

    return n;  // Devolver el resultado de la función.
}
