#ifndef __CMAZEFACTEASY_H__
#define __CMAZEFACTEASY_H__

#include <cmazefact.h>

class IEnvironment;

class CMazeFactSensor : public CMazeFact {
public:   
   CMazeFactSensor(const IEnvironment* e);
   virtual CEnemy  *createEnemy (uint8_t x, uint8_t y) const override;
   virtual CWall   *createWall  (uint8_t x, uint8_t y) const override;
   virtual CPlayer *createPlayer(uint8_t x, uint8_t y) const override;
protected:
   const IEnvironment *m_env;
};

#endif