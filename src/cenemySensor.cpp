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
#include <cenemySensor.h>
#include <StdPijo.h>

CEnemySensor::CEnemySensor(CSensor* s) 
   : m_dir(1), m_vsensor(s) {
}

void CEnemySensor::update() {
   const CGameObject* g;

   // Movement setup and having a look
   turnAroundOnWalls();
   g = getObjectSeenAtPresentMovementDirection();
   
   // Move only when we are not seeing a player
   if (!g || !g->isPlayer())
      setNextMovement(m_dir, 0);
}

const CGameObject* CEnemySensor::getObjectSeenAtPresentMovementDirection() const {
   // Get present movement direction and look for the 
   // first object we see in that direction 
   CSensor::Dir dir = getSeeDir();
   return m_vsensor->see(this, dir);
}

void CEnemySensor::turnAroundOnWalls() {
   // Check if last movement was successful
   if (m_x != m_nx) {
      // Not successful, change direction
      m_dir = -m_dir;
   }   
}

CSensor::Dir CEnemySensor::getSeeDir() const {
   if (m_dir > 0)
      return CSensor::DRIGHT;

   return CSensor::DLEFT;
}

void CEnemySensor::draw() {
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_ROJO, STDP_C_NEGRO);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << "E";
}

CEnemySensor::~CEnemySensor() {
   if (m_vsensor) {
      delete m_vsensor;
      m_vsensor = nullptr;
   }
}
