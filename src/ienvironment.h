#ifndef __IENVIRONMENT_H__
#define __IENVIRONMENT_H__

#include <cstdint>

class CGameObject;

class IEnvironment {
public:
   virtual uint8_t            getSize() const = 0;
   virtual const CGameObject* getGameObject(uint8_t x, uint8_t y) const = 0;
};

#endif