#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_set>
#include <functional>
#include "coordinate.h"
#include "node.h"
#include "algorithm.h"

int main() {
  std::string initial, final;
  std::stack<Node*> solutionPath;
  Node* solution;
  Node* tmp;

  std::cout << "Eight Puzzle Game Solver 1.0.0 - by Filipondios\n" <<
  "Introduce a String that represents the board, describing the board and the position " <<
  "of each chip from up to down and from left to right.\n>> ";  
  std::cin >> initial;

  std::cout << "\nIntroduce the final (target) board config:\n>> ";
  std::cin >> final;

  if(initial.length()!=9 || final.length()!=9) {
    std::cout << "Cannot parse the given strings to a board config :(" << std::endl;
    exit(0);
  }
  
  Node::initNodes(initial, final);
  Node::initFinalPositions(final);

  solution = AStar();
    
  if(solution==nullptr) {
    std::cout << "\nNo solution found." << std::endl;
    exit(0);
  }
  
  std::cout << "\nInitial board state: " << std::endl;
  Node::ROOT_NODE->toString();
  std::cout << "\nFinal board state:" << std::endl;
  Node::FINAL_NODE->toString();
  std::cout << std::endl;

  solutionPath = Node::getAncestorsQueue(solution);
  std::cout << "Solution path: \n" << std::endl;

  while(!solutionPath.empty()) {
    tmp = solutionPath.top();
    tmp->toString();
    std::cout << "Depth = " << tmp->nodeDepth << "\n" << std::endl;
    solutionPath.pop();
  }  
  
  std::cout << "Solution found at depth: " << solution->nodeDepth << "\nCreated Nodes: " 
            << Node::CREATED_NODES << "\nExpanded nodes: " << Node::EXPANDED_NODES << "\n";
  return 0;
}
