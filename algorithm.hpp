#pragma once
#include "node.hpp"
#include <string>

using namespace EightPuzzleGame_Utils;
using namespace std;

namespace EightPuzzleGame {
  
  class Game {
    public: 
      static Node* initial;
      static Node* final;

      static void initParams(int,char*[]);
      static void initGame(string&,string&);
      static void solveGame(void);
      static void showGameSolution(void);

    private:
      static Node* AStar(Node* initial, Node* target);
  };
}
