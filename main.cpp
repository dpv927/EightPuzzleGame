#include <iostream>
#include "node.hpp"
#include "algorithm.hpp"

int main(int argc, char *argv[]) {
  
  std::string initial_config;
  std::string final_config;
  std::stack<Node*> solutionPath;
  Node* initial;
  Node* final;
  Node* solution;
  Node* tmp;

  if(argc != 3) {
    std::cout << "Two args (initial & final states) are required to calculate the solution "
              << "of a 8-Puzzle game. See the documentation for more info." << std::endl;
    return -1;
  }
  
  initial_config = argv[1];
  final_config = argv[2];
  
  if(initial_config.length()!=9 || final_config.length()!=9) {
    std::cout << "Cannot parse the given args to a board config." << std::endl;
    return -1;
  }

  // Create the initial and final nodes of the problem
  initial = new Node(initial_config);
  final = new Node(final_config);
  Node::initFinalPositions(final_config);

  // Start the A* algorithm search
  std::cout << "Please wait..." << std::endl;
  solution = AStar(initial, final);
    
  if(solution == nullptr) {
    std::cout << "\nNo solution found." << std::endl;
    return 0;
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
    std::cout << "Depth -> " << tmp->nodeDepth << "\n" << std::endl;
    solutionPath.pop();
  }   
  return 0;
}
