#include <algorithm>
#include <iostream>
#include "node.hpp"

using namespace std;
namespace EightPuzzleGame_Utils {

  bool Node::isBoardConfig(string config) {
    string pattern = R"(^([0-8])(?:-(?!.*\1)([0-8])){8}$)";
    return std::regex_match(config, regex(pattern));   
  }
  
  void Node::initFinalPositions(string config) {
    if(!isBoardConfig(config))
      throw invalid_argument(config + 
        ": Invalid board config.");
    
    for (int i = 0; i < 9; i++)
      Node::targetBoard[config[i]-48] = Coordinate(i/3,i%3);
  }

  priority_queue<Node*, vector<Node*>, NodeComparator> Node::generateSucessors() {
    priority_queue<Node*, vector<Node*>, NodeComparator> queue;
    int holePos = -1, index = 0;

    for (int e : this->board) {
      if(!e) { holePos = index; break; }
      index++;
    }

    #define switchGap(cond, offset)\
      if(cond) {\
        Node* node = new Node(this);\
		    node->board[holePos] = node->board[offset];\
        node->board[offset] = 0;\
        queue.push(node);\
      }\
      
    switchGap(holePos>2,  holePos-3);
    switchGap(holePos<=5, holePos+3);

    holePos %= 3; // Transform into columns
    switchGap(holePos>0,  holePos-1);
    switchGap(holePos<=1, holePos+1);
    return queue;
  }
 
  int Node::getHeuristic() {
    int total = 0, i, j;
    
    for (int k = 0; k<9; k++) {
      Coordinate* target = &Node::targetBoard[this->board[k]];
      i = k/3; j = k%3;

      if(i != target->i || j != target->j) 
        total += (abs(target->i - i) + abs(target->j - j)) + 1;
    }
    return total;
  }
  
  bool Node::equals(Node* other) {
    for (int i = 0; i < 9; i++)
      if(this->board[i] != other->board[i])
        return false;
    return true;
  }
  
  void Node::toString() {
    string separator = "+---+---+---+";
    cout << separator + "\n"; 

    for (int i = 0; i < 9; ++i){
      cout << "| " << this->board[i] << " ";
      if ((i + 1) % 3 == 0) 
        cout << "|\n" + separator + "\n";
    }
    cout << endl;
  }

  void fillQueue(Node* current, stack<Node*> &s) {
    if (current->father == nullptr)
        return;
    s.push(current->father);
    fillQueue(current->father, s);
  }

  stack<Node*> Node::getAncestorsStack(Node* node) {
    stack<Node*> s;
    s.push(node);
    fillQueue(node, s);
    return s;
  }  
}
