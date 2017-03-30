#include <cmazefactSensor.h>
#include <cwallNormal.h>
#include <cplayer.h>
#include <cenemySensor.h>
#include <csensor.h>
#include <ienvironment.h>

CMazeFactSensor::CMazeFactSensor(const IEnvironment* e) : m_env(e){
}

CEnemy *CMazeFactSensor::createEnemy (uint8_t x, uint8_t y) const{
   CSensor*      s = new CSensor(m_env);
   CEnemySensor* e = new CEnemySensor(s);
   e->setLocation(x, y);
   return e;
}

CPlayer *CMazeFactSensor::createPlayer (uint8_t x, uint8_t y) const{
   CPlayer* p = new CPlayer();
   p->setLocation(x, y);
   return p;
}

CWall *CMazeFactSensor::createWall (uint8_t x, uint8_t y) const{
   CWallNormal* w = new CWallNormal();
   w->setLocation(x, y);
   return w;
}