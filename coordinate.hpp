#pragma once

namespace EightPuzzleGame_Utils {

  class Coordinate{
    public:
      int i; // (Row count)
      int j; // (Column count)
      
      Coordinate(int i, int j)
      : i(i), j(j) {}
  };
}
