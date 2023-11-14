/* 
 * File:   LCD.h
 * Author: JuanDiego
 *
 * Created on 6 de octubre de 2023, 03:08 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif


#define RS PORTDbits.RD0  /*El PIN 0 de PORTD se asigna para el pin de selección de registro de la pantalla LCD*/
#define EN PORTDbits.RD1  /*PIN 1 de PORTD está asignado para habilitar Pin de LCD */
#define ldata PORTD       /*PORTD(PD4-PD7) está asignado para salida de datos LCD*/

#define LCD_Port TRISD  /*definir macros para el registro de dirección PORTD*/
    
void LCD_Init(void);                            /*Inicializar LCD*/
void LCD_Command(unsigned char );               /*Enviar comando a LCD*/
void LCD_Char(unsigned char x);                 /*Enviar datos a LCD*/
void LCD_String(const char *);                  /*Mostrar cadena de datos en LCD*/
void LCD_String_xy(char, char , const char *);  /*Mostrar cadena de datos en la posición LCD*/
void LCD_Clear(void);                           /*Borrar pantalla LCD*/

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

