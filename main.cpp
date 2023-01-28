#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_set>
#include <functional>
#include <cstdint>
#include "coordinate.h"
#include "node.h"
#include "algorithm.h"

int main() {
  std::string initial_config, final_config;
  std::stack<Node*> solutionPath;
  Node* initial;
  Node* final;
  Node* solution;
  Node* tmp;

  std::cout << "Eight Puzzle Game Solver 1.2.0 - by Filipondios\n" <<
  "Introduce a String that represents the board, describing the board and the position " <<
  "of each chip from up to down and from left to right.\n>> ";  
  std::cin >> initial_config;

  std::cout << "\nIntroduce the final (target) board config:\n>> ";
  std::cin >> final_config;

  if(initial_config.length()!=9 || final_config.length()!=9) {
    std::cout << "Cannot parse the given strings to a board config :(" << std::endl;
    exit(0);
  }
  
  initial = new Node(initial_config);
  final = new Node(final_config); 

  Node::initFinalPositions(final_config);
  solution = AStar(initial, final);
    
  if(solution==nullptr) {
    std::cout << "\nNo solution found." << std::endl;
    exit(0);
  }
  
  // Search Info: Results
  std::cout << "\nInitial board state: " << std::endl;
  initial->toString();
  std::cout << "\nFinal board state:" << std::endl;
  final->toString();
  std::cout << std::endl;

  solutionPath = Node::getAncestorsQueue(solution);
  std::cout << "Solution path: \n" << std::endl;

  // Print the solution path
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
