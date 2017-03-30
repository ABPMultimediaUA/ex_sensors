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
#include <csensor.h>
#include <cgameobject.h>
#include <ienvironment.h>

const CGameObject* CSensor::see(const CGameObject* g, CSensor::Dir d) const {
   // Position of the viewer
   uint8_t x = g->getX();
   uint8_t y = g->getY();

   // Direction to which the viewer is looking at
   int8_t dx = getDespX(d);
   int8_t dy = getDespY(d);

   // The first object in the line of sight is what we see
   return findFirstGameObject(x, y, dx, dy);
}

int8_t CSensor::getDespY(CSensor::Dir d) const {
   switch(d) {
      case DUP:   return -1;
      case DDOWN: return  1;
      default:    return  0;     
   }
}

int8_t CSensor::getDespX(CSensor::Dir d) const {
   switch(d) {
      case DLEFT: return -1;
      case DRIGHT:return  1;
      default:    return  0;     
   }
}

const CGameObject* CSensor::findFirstGameObject(uint8_t x, uint8_t y, int8_t dx, int8_t dy) const {
   // Follow the line of sight until we find an object (!= nullptr) 
   // or we exit the map boundaries
   uint8_t            size = m_env->getSize();
   const CGameObject* seen = nullptr;
   do {
      x += dx;
      y += dy;

      seen = m_env->getGameObject(x, y);
   } while(!seen && x < size && y < size);

   // Return object seen
   return seen;
}
