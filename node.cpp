#include "node.hpp"
#include "types.hpp"

Coordinate Node::FINAL_POS[9];  // Final positions of the chips

/* @brief Initializes the array with all the final coordinates of the
 * board chips, so we can check if any chip is out of position 
 * @param conf Final config of the board */
void Node::initFinalPositions(std::string conf) {
  for (u8 i = 0; i < 9; i++) {
    Node::FINAL_POS[(u8)(conf[i])-48] = Coordinate(i/3,i%3);
  }
}

/** @brief Generates all the sucessors of a node (by its legal moves).
 * Stores all the sucessors in a priority queue. The orther is the next one: 
 * First we try to move the chip that is above the gap, then the one under
 * the gap, next the one at the left and lastly the one at the right. */
std::priority_queue<Node*, std::vector<Node*>, NodeComparator> Node::generateSucessors() {
  std::priority_queue<Node*, std::vector<Node*>, NodeComparator> queue;
  short holeRow = -1, holeCol = -1;
  
  for (u8 i = 0; i < 3; i++) {
    for (u8 j = 0; j < 3; j++) {
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
  short total = 0;
  for (u8 i = 0; i < 3; i++) {
    for (u8 j = 0; j < 3; j++) {
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
u8** Node::dataCopy() {
  u8** dataCopy = new u8*[3];

  for (u8 i = 0; i < 3; i++) {
    dataCopy[i] = new u8[3];
  }

  for (u8 i = 0; i < 3; i++) {
    for (u8 j = 0; j < 3; j++) {
      dataCopy[i][j] = this->data[i][j];
    }
  }
  return dataCopy;
}

/* @brief Checks if a Node is equal to another.
 * @return true if both nodes are equal, else false. */
bool Node::equals(Node* other) {
  for (u8 i = 0; i < 3; i++) {
    for (u8 j = 0; j < 3; j++) {
      if(this->data[i][j] != other->data[i][j]) {
        return false;
      }
    }
  }
  return true;
}

/* @brief Prints a Node's data (board). */
void Node::toString() {
    std::cout << "+---+---+---+\n";

    for (u8 i = 0; i < 3; ++i){
      for (u8 j = 0; j < 3; ++j)
        std::cout << "| " << unsigned(this->data[i][j]) << " ";
      std::cout << "|\n+---+---+---+\n";
    }
    std::cout << std::endl;
}

/* @brief Puts the ancestor of a Node recursively. In
 * a stack. */
void fillQueue(Node* current, std::stack<Node*> &s) {
    if (current->father == nullptr) {
        return;
    }
    s.push(current->father);
    fillQueue(current->father, s);
}

/* @brief Gets all the ancestors of a node. 
 * All the sucessors (pointers to them) are stored in a stack,
 * so when a queue is processed, the ancestors order is well done.
 * @return stack with all the ancestors. */
std::stack<Node*> Node::getAncestorsQueue(Node* node) {
    std::stack<Node*> s;
    s.push(node);
    fillQueue(node, s);
    return s;
}
