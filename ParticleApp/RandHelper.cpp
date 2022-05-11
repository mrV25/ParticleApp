#include <iostream>
#include <stdlib.h>
#include "RandHelper.h"

namespace particle_app{
  double RandHelper::randToOne() {
    return (double)rand() / RAND_MAX; 
  }
  int RandHelper::randSign() {
    if ((double)(rand() - RAND_MAX / 2) / RAND_MAX > 0) {
      return 1;
    }
    return -1;
  }
  double RandHelper::randOfOrder(int order) {
    return RandHelper::randToOne() / (pow(10, order));
  }
  double RandHelper::randToLimit(int limit) { return randToOne() * limit; }
}
