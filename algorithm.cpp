#include "algorithm.hpp"
#include "node.hpp"

using namespace std;
namespace EightPuzzleGame {

  static void initParams(int argc, char* argv[]) {
    if(argc < 2 || argc > 2) 
      throw invalid_argument("Invalid cmd argument/s.");
    Node::initFinalPositions(argv[2]);
    Game::initial = new Node(argv[1]);
  }

  static void initGame(string&,string&);
  static void solveGame(void);
  static void showGameSolution(void);

  Node* Game::AStar(Node* initial, Node* target) {
    priority_queue<Node*, vector<Node*>, NodeComparator> queue;
    priority_queue<Node*, vector<Node*>, NodeComparator> sucessors;
    Node* current;
    queue.push(initial);
  
    while(!queue.empty()) {
      current = queue.top();
      queue.pop();

      if(current->equals(target))
        return current;
      sucessors = current->generateSucessors();

      while(!sucessors.empty()) {
        queue.push(sucessors.top());
        sucessors.pop();
      }
    }
    return nullptr;
  }
}
