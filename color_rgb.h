/* 
 * File:   color_rgb.h
 * Author: JuanDiego
 *
 * Created on 6 de octubre de 2023, 03:11 PM
 */

#ifndef COLOR_RGB_H
#define	COLOR_RGB_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define ldatae TRISE        /*Definici�n de una macro que proporciona un alias para el registro de direcci�n TRISE.*/
#define rojo PORTEbits.RE0  /*Definici�n de una macro que proporciona un alias para el bit RE0 del puerto E.*/
#define verde PORTEbits.RE1 /*Definici�n de una macro que proporciona un alias para el bit RE1 del puerto E.*/ 
#define azul PORTEbits.RE2  /*Definici�n de una macro que proporciona un alias para el bit RE2 del puerto E.*/

void color(unsigned char red, unsigned char green, unsigned char blue); /*Funci�n para controlar la combinaci�n de colores en un sistema basado en LEDs o indicadores de color.*/

#ifdef	__cplusplus
}
#endif

#endif	/* COLOR_RGB_H */

