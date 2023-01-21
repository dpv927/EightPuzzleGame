#include <iostream>
#include "node.h"

int Node::EXPLORED_NODES = 0;
int Node::EXPANDED_NODES = 0;

void Node::toString() {
  std::cout << "This is the toString method" << std::endl;
}

int Node::calculateHeuristic() {
    return 1 + 1;
}

int Node::manhattanDistance(int i1, int j1, int i2, int j2) {
  return 1 + 2;
}

uint8_t** Node::dataCopy(uint8_t** data) {
  return nullptr;
}
