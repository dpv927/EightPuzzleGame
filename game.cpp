#include <iostream>
#include "game.hpp"

namespace EightPuzzleGame {

  void Game::initGame(int argc, char* argv[]) {
    if(argc != 3) throw invalid_argument("Invalid number of arguments.");
    Node::initFinalPositions(argv[2]);
    Game::initial = new Node(argv[1]);
    Game::final = new Node(argv[2]);
  }

  void Game::solveGame(void){
    priority_queue<Node*, vector<Node*>, NodeComparator> queue;
    priority_queue<Node*, vector<Node*>, NodeComparator> sucessors;
    Node* current;
    queue.push(Game::initial);
  
    while(!queue.empty()) {
      current = queue.top();
      queue.pop();

      if(current->equals(Game::final))
        goto solved;
      sucessors = current->generateSucessors();

      while(!sucessors.empty()) {
        queue.push(sucessors.top());
        sucessors.pop();
      }
    }
    current = nullptr;
    solved:
    Game::obtained = current;
  }

  void Game::showGameSolution(void) {
    if(Game::obtained == nullptr) {
      cout << "\nNo solution found." << endl;
      return;
    }
  
    // Search Info: Results
    cout << "\nInitial board state: " << endl;
    initial->toString();
    cout << "\nFinal board state:" << endl;
    final->toString();
    cout << endl;

    auto solutionPath = Node::getAncestorsStack(Game::obtained);
    cout << "Solution path: \n" << endl;

    // Print the solution path
    Node* tmp = nullptr;
    while(!solutionPath.empty()) {
      tmp = solutionPath.top();
      tmp->toString();
      cout << "Depth -> " << tmp->nodeDepth << "\n" << endl;
      solutionPath.pop();
    }   
  }
}
