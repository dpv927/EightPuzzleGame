#include <cstdint>

/** The Node class is used for representing the different Nodes or states of a
 * board in a seach tree. The node must have a self heuristic, a data matrix with
 * the state of the board in that node and its depth inside the seach tree.
 * @author Filipondios
 * @version 22.01.2023 
 * @see nodeImpl.cpp to see how this class functions are implemented. */
class Node {
  public:
    static int EXPLORED_NODES; // Count of all the explored nodes
    static int EXPANDED_NODES; // Count of all the expanded nodes

    Node* father; // Father node
    uint8_t** data; // Game board
    int heuristic; // Node heuristic
    uint32_t nodeDepth; // Depth of this node
    
  /* @brief Normal Node constructor.
   * Creates a intermidiate Node of a search tree.
   * @param data Board state of the created Node
   * @param father Father node of this Node in the seach tree */
    Node(uint8_t** data, Node* father) {
      this->data = data;
      this->father = father;
      this->nodeDepth = father->nodeDepth;
      this->heuristic = calculateHeuristic() + this->nodeDepth;
    }

  /* @brief Root Node constructor.
   * Creates the root Node of a search tree.
   * @param data Board state of the created Node
   * @param father Father node of this Node in the seach tree */
    Node(uint8_t** data) {
      this->data = data;
      this->father = nullptr;
      this->nodeDepth = 0;
      this->heuristic = 0;
    }
    
    /*@brief Prints the Node.*/
    void toString();

  private:
    /*@brief Calculates the heuristic of a node*/
    int calculateHeuristic();
    /*@brief Copies the board state of a Node.*/
    uint8_t** dataCopy(uint8_t** data);
};

/* A simple comparator between Nodes. Useful when using priority queques
 * with nodes at the search algorithms */
struct NodeComparator {
    bool operator()(const Node& a, const Node& b) {
      return a.heuristic > b.heuristic;
    }
};
