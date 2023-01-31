/** The Node class is used for representing the different Nodes or states of a
 * board in a seach tree. A node must have a self heuristic, a data matrix with
 * the state of the board in that node and its depth inside the seach tree.
 * @author Filipondios
 * @version 31.01.2023
 * @see node.cpp to see how this class functions are implemented. */
class Node {

  private:
    static Coordinate FINAL_POS[9]; // Final positions of the chips

  public:
    static unsigned int CREATED_NODES; // Count of all the explored nodes
    static unsigned int EXPANDED_NODES; // Count of all the expanded nodes 
    Node* father; // Father node
    uint8_t** data; // Game board
    unsigned short nodeDepth; // Depth of this node
    short eval; // Node evaluation value
  
   /* @brief Normal Node constructor.
    * Creates a intermidiate Node of a search tree.
    * @param data Board state of the created Node
    * @param father Father node of this Node in the seach tree */
    Node(Node* father, uint8_t** data) {
      this->data = data;
      this->father = father;
      this->nodeDepth = father->nodeDepth + 1;
      this->eval = calculateHeuristic() + this->nodeDepth;
      Node::CREATED_NODES++;
    }

   /* @brief Root Node constructor.
    * Creates the root Node of a search tree.
    * @param config Board state of the created Node */
    Node(std::string config) {

      this->data = new uint8_t*[3];

      for (uint8_t i = 0; i < 3; i++) {
        this->data[i] = new uint8_t[3];
      }
      for (uint8_t i = 0; i < 9; i++) {
        this->data[i/3][i%3] = ((uint8_t) config[i])-48;
      }
      this->father = nullptr;
      this->nodeDepth = 0;
      this->eval = 0;
    }

  /* @brief Initilializes the final postions array. */
    static void initFinalPositions(std::string);
  /* @brief Generates the sucessors of a node. */
    std::priority_queue<Node*, std::vector<Node*>, struct NodeComparator> generateSucessors();
  /* @brief Gets a stack with all the antecesor Nodes of a Node */
    static std::stack<Node*> getAncestorsQueue(Node*);
  /* @brief Prints the Node. */
    void toString();
  /* @brief Checks if a node is equal to another. */
    bool equals(Node*);

  private:
    /*@brief Calculates the heuristic of a node*/
    int calculateHeuristic();
    /*@brief Copies the board state of a Node.*/
    uint8_t** dataCopy();
};

/* Comparates two nodes. Used in priority queues. */
struct NodeComparator {
  bool operator()(const Node* a, const Node* b) {
    return a->eval > b->eval;
  }
};

/* A struct made for lists that not permit duplicated elements.
 * Used in lists of visited Nodes. */
struct NodeEquals {
  bool operator()(Node* a, Node* b) const {
    return a->equals(b);
  }
};
