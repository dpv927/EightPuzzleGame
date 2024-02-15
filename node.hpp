#pragma once
#include <stdexcept>
#include <string>
#include <queue>
#include <stack>
#include <regex>
#include "coordinate.hpp"

using namespace std;
namespace EightPuzzleGame_Utils {

  class Node {
    public:
      // Target Board Postions
      static Coordinate targetBoard[9];
      Node* father;
      int board[9];
      int nodeDepth;
      int heuristic;
  
      Node(Node* father) {
        this->father = father;
        this->nodeDepth = father->nodeDepth + 1;
        this->heuristic = getHeuristic() + this->nodeDepth;
        copy(begin(father->board), end(father->board), begin(this->board));
      }

      Node(string config) {
        if(!isBoardConfig(config))
          throw invalid_argument(config + 
            ": Invalid board config.");

        int index = 0;
        for (char c : config)
          this->board[index++] = (c-'0');

        this->father = nullptr;
        this->nodeDepth = 0;
        this->heuristic = 0;
      }
    
      /* Checks with regex if a given board config is valid */
      static bool isBoardConfig(string);
      static void initFinalPositions(string);
      /* @brief Generates the sucessors of a node. */
      priority_queue<Node*, vector<Node*>, struct NodeComparator> generateSucessors();
      /* @brief Gets a stack with all the antecesor Nodes of a Node */
      static stack<Node*> getAncestorsStack(Node*);
      void toString();
      bool equals(Node*);

    private:
      int getHeuristic();
  };

  struct NodeComparator {
    bool operator()(const Node* a, const Node* b) {
      return a->heuristic > b->heuristic;
    }
  };

  struct NodeEquals {
    bool operator()(Node* a, Node* b) const {
      return a->equals(b);
    }
  };
}
