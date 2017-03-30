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