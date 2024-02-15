#include "game.hpp"

using namespace EightPuzzleGame;

int main(int argc, char *argv[]) {
  Game::initGame(argc, argv);
  Game::solveGame();
  Game::showGameSolution();
}
