#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include "coordinate.h"
#include "node.h"

int Node::CREATED_NODES = 0;
int Node::EXPANDED_NODES = 0;
Node* Node::ROOT_NODE = nullptr;
Node* Node::FINAL_NODE = nullptr;
Coordinate Node::FINAL_POS[9]; 

/* @brief Initializes the array with all the final coordinates of the
 * board chips, so we can check if any chip is out of position 
 * @param conf Final config of the board */
void Node::initFinalPositions(std::string conf) {
  for (int i = 0; i < 9; i++) {
    Node::FINAL_POS[(int)(conf[i])-48] = Coordinate(i/3,i%3);
  }
}

/* @brief Initilalizes the root Node and the target node of a search.
 * @param init Initial board config (Needed for the root Node)
 * @param final Final board config (Needed for the target Node)*/
void Node::initNodes(std::string init, std::string final) {
  int row, col;
  int** initData = new int*[3];
  int** finData = new int*[3];

  for (int i = 0; i < 3; i++) {
    initData[i] = new int[3];
    finData[i] = new int[3];
  }

  for (int i = 0; i < 9; i++) {
    row = i/3;
    col = i%3;
    initData[row][col] = ((int) init[i])-48;
    finData[row][col] = ((int) final[i])-48;
  }
  Node::ROOT_NODE = new Node(initData);
  Node::FINAL_NODE = new Node(finData);
}

/** @brief Generates all the sucessors of a node (by its legal moves) and
 * stores them in a priority queue. The orther is the next one: First we
 * try to move the chip that is above the gap, then the one under the gap,
 * next the one at the left and lastly the one at the right. */
std::priority_queue<Node*, std::vector<Node*>, NodeComparator> Node::generateSucessors() {
  std::priority_queue<Node*, std::vector<Node*>, NodeComparator> queue;
  int holeRow = -1, holeCol = -1;
  Node::EXPANDED_NODES++;
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if(this->data[i][j] == 0) {
        holeRow = i;
        holeCol = j;
        break;
      }        
    }
  }

  if(holeRow > 0) { // move up to down
	  Node* node = new Node(this, this->dataCopy());
    node->data[holeRow][holeCol] = node->data[holeRow-1][holeCol];
    node->data[holeRow-1][holeCol] = 0;
		queue.push(node);
  }

	if(holeRow < 2) { // move down to up
	  Node* node = new Node(this, this->dataCopy());
		node->data[holeRow][holeCol] = node->data[holeRow+1][holeCol];
		node->data[holeRow+1][holeCol] = 0;
		queue.push(node);
	}
			
	if(holeCol > 0) { // move left to right
		Node* node = new Node(this, this->dataCopy());
		node->data[holeRow][holeCol] = node->data[holeRow][holeCol-1];
		node->data[holeRow][holeCol-1] = 0;
		queue.push(node);
	}
	
	if(holeCol < 2) { // move right to left
		Node* node = new Node(this, this->dataCopy());
    node->data[holeRow][holeCol] = node->data[holeRow][holeCol+1];
		node->data[holeRow][holeCol+1] = 0;
		queue.push(node);
	}
  return queue;
}

/* @brief Calculates the heuristic of a Node.
 * @returns Value of the heuristic */
int Node::calculateHeuristic() {
  int total = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Coordinate* target = &Node::FINAL_POS[this->data[i][j]];
      
      if(i != target->i || j != target->j) {
        total += (abs(target->i - i) + abs(target->j - j)) + 1;
      }
    }
  }
  return total;
}

/* @brief Utility to copy a Node's data (board)
 * @param data Data to copy 
 * @return Copied data */
int** Node::dataCopy() {
  int** dataCopy = new int*[3];

  for (int i = 0; i < 3; i++) {
    dataCopy[i] = new int[3];
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      dataCopy[i][j] = this->data[i][j];
    }
  }
  return dataCopy;
}

/* @brief Checks if a Node is equal to another. */
bool Node::equals(Node* other) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if(this->data[i][j] != other->data[i][j]) {
        return false;
      }
    }
  }
  return true;
}

/* @brief Prints a Node's data (board). */
void Node::toString() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << this->data[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void fillQueue(Node* current, std::stack<Node*> &s) {
    if (current->father == nullptr) {
        return;
    }
    s.push(current->father);
    fillQueue(current->father, s);
}

std::stack<Node*> Node::getAncestorsQueue(Node* node) {
    std::stack<Node*> s;
    s.push(node);
    fillQueue(node, s);
    return s;
}
