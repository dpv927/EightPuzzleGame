/*#include <queue>
#include <vector>*/
#include "node.h"

int main() {
  //std::priority_queue<Node, std::vector<Node>, NodeComparator> pq;
  uint8_t** data = new uint8_t*[10];
    for (int i = 0; i < 10; i++) {
        data[i] = new uint8_t[10];
    }
  Node* father = new Node(data);
}
