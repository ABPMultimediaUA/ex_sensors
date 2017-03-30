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
#ifndef __CSCENE_H__
#define __CSCENE_H__

#include <vector>
#include <cgameobject.h>
#include <ienvironment.h>

class CMazeFact;

class CScene : public CGameObject, public IEnvironment {
public:
   typedef std::vector<CGameObject*> TObjVec;

   CScene();
   ~CScene();

   virtual void  draw()    override;
   virtual void  update()  override;

   uint8_t            getSize() const override { return kMapSize; }
   const CGameObject* getGameObject(uint8_t x, uint8_t y) const override;

   void initialize(CMazeFact &f);
   void addGameObject   (CGameObject* o, uint8_t x, uint8_t y);
   void removeGameObject(CGameObject* o);
   void moveGameObject  (CGameObject *g);

   bool thereIsAPlayer() const { return m_thereIsAPlayer; }
   bool isPlayer()       const override { return false; }
   bool isMortal()       const override { return false; }
private:
   static constexpr uint8_t kMapSize = 13;

   TObjVec        m_gameObjects;
   CGameObject*   m_objMatrix[kMapSize][kMapSize];
   bool           m_thereIsAPlayer;
};

#endif