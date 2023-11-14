/* 
 * File:   canal.h
 * Author: JuanDiego
 *
 * Created on 18 de octubre de 2023, 10:29 AM
 */

#ifndef CANAL_H
#define	CANAL_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    
    void adc_begin(void);               /*Inicializar Conversion analogica*/
    int adc_conversion(int channel);    /*Asignacion de canal y Conversion analogica*/

#ifdef	__cplusplus
}
#endif

#endif	/* CANAL_H */

