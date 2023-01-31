/*@brief A* algorithm implemented for the 8-puzzle game.*/
Node* AStar(Node* initial, Node* target) {
  std::priority_queue<Node*, std::vector<Node*>, NodeComparator> queue;
  std::priority_queue<Node*, std::vector<Node*>, NodeComparator> sucessors;
  Node* current;
  queue.push(initial);
  
  while(!queue.empty()) {
    current = queue.top();
    queue.pop();

    if(current->equals(target)) {
      return current;
    }

    sucessors = current->generateSucessors();

    while(!sucessors.empty()) {
      queue.push(sucessors.top());
      sucessors.pop();
    }
  }
  return nullptr;
}
