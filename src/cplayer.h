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
#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#include <cgameobject.h>

class CKeyboardMan;

class CPlayer : public CGameObject {
public:
   CPlayer();
   virtual ~CPlayer();

   virtual void update() override;
   virtual void draw()   override;
   
   virtual bool isPlayer() const override { return true;  };
   virtual bool isMortal() const override { return false; };

   void move(int8_t dx, int8_t dy);
private:
   CKeyboardMan* m_KeyMan;

   uint8_t move_one_axis_with_limits(uint8_t p, int8_t d, uint8_t min, uint8_t max);
};

#endif