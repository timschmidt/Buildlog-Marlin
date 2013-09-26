/*
  laser.cpp - Laser control library for Arduino using 16 bit timers- Version 1
  Copyright (c) 2013 Timothy Schmidt.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Configuration.h"
#include "pins.h"
#include <avr/interrupt.h>
#include <Arduino.h>

static void setupLaser()
{
  pinMode(LASER_FIRING_PIN, OUTPUT);
  pinMode(LASER_INTENSITY_PIN, OUTPUT);
  
  float avr_freq = 16000000;
  float max_timer_count = 65536;
  
  if (avr_freq / 256 / LASER_PWM_MAX < max_timer_count) {
    
  }
  
  else if (avr_freq / 64 / LASER_PWM_MAX < max_timer_count) {
    
  }
  
  else if (avr_freq / 8 / LASER_PWM_MAX < max_timer_count) {
    
  }  
  
  else {
    
  }
}

static void fireLaser(float intensity)
{
  if (intensity < 0) intensity = 0;
  if (intensity > 1000) intensity = 1000;
  float laser_pwm = LASER_PWM_MIN + ((LASER_PWM_MAX - LASER_PWM_MIN) * (intensity / 1000));
  SERIAL_ECHO_START;
  SERIAL_ECHO("Laser firing intensity: ");
  SERIAL_ECHO(intensity);
  SERIAL_ECHO("Laser firing PWM: ");
  SERIAL_ECHOLN(laser_pwm);
}

static void offLaser()
{
  digitalWrite(LASER_FIRING_PIN,LOW);
}
