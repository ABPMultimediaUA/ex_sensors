///////////////////////////////////////////////////////////////////////////////
//     This is part of ex_sensors, an example on how to implement sensors
//     for enemies in C++. It is a simple textmode game that has two game modes: 
//     Easy and Hard. This implementation adds a third mode: Sensors. In this
//     mode, enemies created have sight sensors and stop moving when they see
//     the player in its line of sight.
//     This example was used during Videogame Programming lessons at the 
//     Multimedia Degree from the University of Alicante (Spain). You may
//     watch the associated lesson at https://youtu.be/mPapuUC0kLg
//
//    Copyright (C) 2017   Francisco J. Gallego-Durán
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
///////////////////////////////////////////////////////////////////////////////
#ifndef __CSENSOR_H__
#define __CSENSOR_H__

#include <cstdint>

class IEnvironment;
class CGameObject;

class CSensor {
public:
   enum Dir { DLEFT, DRIGHT, DUP, DDOWN };

   CSensor(const IEnvironment* e) : m_env(e) {};
   ~CSensor() {};

   const CGameObject* see(const CGameObject* g, CSensor::Dir d) const;

private:
   int8_t getDespX(CSensor::Dir d) const;
   int8_t getDespY(CSensor::Dir d) const;
   const CGameObject* findFirstGameObject(uint8_t x, uint8_t y, int8_t dx, int8_t dy) const;

   const IEnvironment *m_env;
};

#endif