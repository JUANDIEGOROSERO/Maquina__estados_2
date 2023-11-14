/* 
 * File:   sensor.h
 * Author: JuanDiego
 *
 * Created on 6 de octubre de 2023, 03:35 PM
 */

#ifndef SENSOR_H
#define	SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define SENSOR_IR RC1
#define SENSOR_HALL RC0
#define SENSOR_METAL RC2

unsigned char monitoring_sensor(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

