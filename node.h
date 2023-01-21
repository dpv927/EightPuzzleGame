#include <cstdint>

class Node {
  public:
    static int EXPLORED_NODES;
    static int EXPANDED_NODES;

    Node* father;
    uint8_t** data; 
    int heuristic;
    uint32_t nodeDepth;
    
    Node(uint8_t** data, Node* father) {
      this->data = data;
      this->father = father;
      this->nodeDepth = father->nodeDepth;
      this->heuristic = calculateHeuristic() + this->nodeDepth;
    }

    Node(uint8_t** data) {
      this->data = data;
      this->father = nullptr;
      this->nodeDepth = 0;
      this->heuristic = 0;
    }

    void toString();

  private:
    int calculateHeuristic();
    int manhattanDistance(int i1, int j1, int i2, int j2);
    uint8_t** dataCopy(uint8_t** data);
};

struct NodeComparator {
    bool operator()(const Node& a, const Node& b) {
      return a.heuristic > b.heuristic;
    }
};
