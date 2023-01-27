/** The Node class is used for representing the different Nodes or states of a
 * board in a seach tree. The node must have a self heuristic, a data matrix with
 * the state of the board in that node and its depth inside the seach tree.
 * @author Filipondios
 * @version 27.01.2023
 * @see nodeImpl.cpp to see how this class functions are implemented. */
class Node {

  public:
    static int CREATED_NODES; // Count of all the explored nodes
    static int EXPANDED_NODES; // Count of all the expanded nodes
    static Node* ROOT_NODE; // Root Node of a search tree (Initial state)
    static Node* FINAL_NODE; // Final Node of a search tree (target state)
    static Coordinate FINAL_POS[9]; // Final positions of the chips
    static struct NodeComparator comparator; // Comparator for two nodes 
  
    Node* father; // Father node
    int** data; // Game board
    int nodeDepth; // Depth of this node
    int eval; // Node evaluation value
  
   /* @brief Normal Node constructor.
    * Creates a intermidiate Node of a search tree.
    * @param data Board state of the created Node
    * @param father Father node of this Node in the seach tree */
    Node(Node* father, int** data) {
      this->data = data;
      this->father = father;
      this->nodeDepth = father->nodeDepth + 1;
      this->eval = calculateHeuristic() + this->nodeDepth;
      std::cout << "Info: Creating node at depth " << this->nodeDepth << std::endl;
      Node::CREATED_NODES++;
    }

   /* @brief Root Node constructor.
    * Creates the root Node of a search tree.
    * @param data Board state of the created Node
    * @param father Father node of this Node in the seach tree */
    Node(int** data) {
      this->data = data;
      this->father = nullptr;
      this->nodeDepth = 0;
      this->eval = 0;
    }
  /* @brief Initilializes the final postions array. */
    static void initFinalPositions(std::string);
  /* @brief Initializes the root and final node of a seach */
    static void initNodes(std::string, std::string);
  /* @brief Generates the sucessors of a node. */
    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> generateSucessors();
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
    int** dataCopy();
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
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (a->data[i][j] != b->data[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
};

/* Hash function for the visited Nodes lists. Used in the
 * visited Node lists (unordered_set) */
template<> struct std::hash<Node*> {
    size_t operator()(const Node* n) const {
    std::hash<int> h;
    size_t seed = 0;
      
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        seed ^= h(n->data[i][j]) + 0x9e3779b9 + (seed);
      }
    }
    return seed;
  }
};
