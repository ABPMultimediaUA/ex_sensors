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
#include <cenemyWander.h>
#include <StdPijo.h>
#include <cstdlib>
#include <algorithm>

CEnemyWander::CEnemyWander() {
   initMovementVector();
}

void CEnemyWander::initMovementVector() {
   // Initialize directions vector
   m_dirs[0] = { 1, 0, static_cast<int8_t>(1 + rand() % 10) };
   m_dirs[1] = { 0, 1, static_cast<int8_t>(1 + rand() % 10) };
   m_dirs[2] = {-1, 0, static_cast<int8_t>(1 + rand() % 10) };
   m_dirs[3] = { 0,-1, static_cast<int8_t>(1 + rand() % 10) };
   std::random_shuffle(m_dirs + 0, m_dirs + 3);
}

void CEnemyWander::update() {
   // Do next movement
   TMoveDir& move = m_dirs[m_di]; 
   setNextMovement(move.dx, move.dy);

   // Count one step more and check
   ++m_step;
   if (m_step > move.step) {
      // Next direction
      ++m_di;
      if (m_di > 3) {
         initMovementVector();
         m_di   = 0;
         m_step = 0;
      }
   }
}

void CEnemyWander::draw() {
   STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_MAGENTA, STDP_C_NEGRO);  
   STDP::PonCursor(m_x, m_y);
   STDP::sout << "W";
}

CEnemyWander::~CEnemyWander() {
}
