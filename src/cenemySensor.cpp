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
