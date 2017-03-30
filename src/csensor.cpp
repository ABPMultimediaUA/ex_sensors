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
