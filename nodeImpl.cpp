#include <iostream>
#include <cmath>
#include <string>
#include <cstdint>
#include "coordinate.h"
#include "node.h"

int Node::EXPLORED_NODES = 0;
int Node::EXPANDED_NODES = 0;
Node* Node::ROOT_NODE = nullptr;
Node* Node::FINAL_NODE = nullptr;
Coordinate Node::FINAL_POS[9]; 

/* @brief Initializes the array with all the final coordinates of the
 * board chips, so we can check if any chip is out of position 
 * @param conf Final config of the board */
void initFinalPositions(std::string conf) {
  for (int i = 0; i < 9; i++) {
    Node::FINAL_POS[(int)(conf[i])] = Coordinate(i/3,i%3);
  }
}

/* @brief Initilalizes the root Node and the target node of a search.
 * @param init Initial board config (Needed for the root Node)
 * @param final Final board config (Needed for the target Node)*/
void initNodes(std::string init, std::string final) {
  int row, col;
  uint8_t** initData = new uint8_t*[3];
  uint8_t** finData = new uint8_t*[3];

  for (int i = 0; i < 9; i++) {
    row = i/3;
    col = i%3;
    initData[row][col] = (uint8_t) init[i];
    finData[row][col] = (uint8_t) final[i];
  }
  Node::ROOT_NODE = new Node(initData);
  Node::FINAL_NODE = new Node(finData);
}

/* @brief Calculates the heuristic of a Node.
 * @returns Value of the heuristic */
int Node::calculateHeuristic() {
  int total = 0;   
  return total;
}

/* @brief Utility to copy a Node's data (board)
 * @param data Data to copy 
 * @return Copied data */
uint8_t** Node::dataCopy(uint8_t** data) {
  uint8_t** dataCopy = new uint8_t*[3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; i++) {
      dataCopy[i][j] = data[i][j];
    }
  }
  return dataCopy;
}

/* @brief Checks if a Node is equal to another. */
bool Node::equals(Node* other) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; i++) {
      if(this->data[i][j] != other->data[i][j])
        return false;
    }
  }
  return true;
}

/* @brief Prints a Node's data (board). */
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
