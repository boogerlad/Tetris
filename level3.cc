#include <cstdlib>
#include "level3.h"

Block* Level3::makeBlock()
{
   int num = rand() % 9;
   switch(num)
   {
      case 0:
         return new I(3);
      case 1:
         return new J(3);
      case 2:
         return new L(3);
      case 3:
         return new O(3);
      case 4:
      case 5:
         return new S(3);
      case 6:
      case 7:
         return new Z(3);
      case 8:
         return new T(3);
      default:
         return 0;
   }
}
