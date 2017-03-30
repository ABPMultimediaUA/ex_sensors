#include <cgame.h>
#include <iostream>

int main(void) {
   CGame game;

   try {
      game.run();
   } catch(...) { 
      std::cerr << "Program exited due to an uncaught exception\n";
   }

   return 0;
}