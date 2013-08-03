#include <cstdlib>
#include "level2.h"

Block* Level2::makeBlock()
{
   int num = rand() % 7;
   switch(num)
   {
      case 0:
         return new I(2);
      case 1:
         return new J(2);
      case 2:
         return new L(2);
      case 3:
         return new O(2);
      case 4:
         return new S(2);
      case 5:
         return new Z(2);
      case 6:
         return new T(2);
      default:
         return 0;
   }
}
