#pragma once

namespace particle_app{
class RandHelper {
 public:
  static double randToOne();
  static int randSign();
  static double randToLimit(int limit);
  static double randOfOrder(int order);
};
}
