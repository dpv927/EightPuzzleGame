#include <iostream>
#include <cmath>
#include "node.h"

int Node::EXPLORED_NODES = 0;
int Node::EXPANDED_NODES = 0;

int Node::calculateHeuristic() {
  int total = 0;   
  return total;
}

uint8_t** Node::dataCopy(uint8_t** data) {
  uint8_t** dataCopy = new uint8_t*[3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; i++) {
      dataCopy[i][j] = data[i][j];
    }
  }
  return dataCopy;
}

void Node::toString() {
  if(data==nullptr)
    std::cout << "Empty matrix" << std::endl;
  else{
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        std::cout << unsigned(this->data[i][j]) << " ";
      }
      std::cout << std::endl;
    }
  }
}

