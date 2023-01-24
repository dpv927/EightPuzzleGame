/** The Node class is used for representing the different Nodes or states of a
 * board in a seach tree. The node must have a self heuristic, a data matrix with
 * the state of the board in that node and its depth inside the seach tree.
 * @author Filipondios
 * @version 23.01.2023
 * @see nodeImpl.cpp to see how this class functions are implemented. */
class Node {
  public:
    static int EXPLORED_NODES; // Count of all the explored nodes
    static int EXPANDED_NODES; // Count of all the expanded nodes
    static Node* ROOT_NODE; // Root Node of a search tree (Initial state)
    static Node* FINAL_NODE; // Final Node of a search tree (target state)
    static Coordinate FINAL_POS[9]; // Final positions of the chips

    Node* father; // Father node
    uint8_t** data; // Game board
    int nodeDepth; // Depth of this node
    int eval; // Node evaluation value
  
   /* @brief Normal Node constructor.
    * Creates a intermidiate Node of a search tree.
    * @param data Board state of the created Node
    * @param father Father node of this Node in the seach tree */
    Node(uint8_t** data, Node* father) {
      this->data = data;
      this->father = father;
      this->nodeDepth = father->nodeDepth + 1;
      this->eval = calculateHeuristic() + this->nodeDepth;
    }

   /* @brief Root Node constructor.
    * Creates the root Node of a search tree.
    * @param data Board state of the created Node
    * @param father Father node of this Node in the seach tree */
    Node(uint8_t** data) {
      this->data = data;
      this->father = nullptr;
      this->nodeDepth = 0;
      this->eval = 0;
    }
  /* @brief Initilializes the final postions array. */
    static void initFinalPositions(std::string);
  /* @brief Initializes the root and final node of a seach */
    static void initNodes(std::string, std::string);
   /* @brief Prints the Node. */
    void toString();
   /* @brief Checks if a node is equal to another. */
    bool equals(Node*);

  private:
    /*@brief Calculates the heuristic of a node*/
    int calculateHeuristic();
    /*@brief Copies the board state of a Node.*/
    uint8_t** dataCopy(uint8_t** data);
};

/* A simple comparator between Nodes. Useful when using priority queques
 * with nodes at the search algorithms */
struct NodeComparator {
    bool operator()(const Node* a, const Node* b) {
      return a->eval > b->eval;
    }
};
