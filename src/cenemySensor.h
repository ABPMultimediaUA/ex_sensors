#ifndef __CENEMYSENSOR_H__
#define __CENEMYSENSOR_H__

#include <cenemy.h>
#include <csensor.h>

class CEnemySensor : public CEnemy {
public:
   CEnemySensor(CSensor* s);
   virtual ~CEnemySensor();
   virtual void update() override;
   virtual void draw()   override;

   virtual bool isPlayer() const override { return false; };
   virtual bool isMortal() const override { return true;  };
private:
   void               turnAroundOnWalls();
   CSensor::Dir       getSeeDir() const;
   const CGameObject* getObjectSeenAtPresentMovementDirection() const;

   int8_t   m_dir;     // Movement Direction
   CSensor* m_vsensor;
};

#endif