/*@brief A* algorithm implemented for the 8-puzzle game.
 * Uses a list with unique Nodes (can't be repeated) that have been visited
 * to avoid repeating moves. Sometimes this is more efficient than others because
 * in some ocasions a move can be repeated. Anyways this is a very uncommon thing.*/
Node* AStar(Node* initial, Node* target) {
  std::priority_queue<Node*, std::vector<Node*>, NodeComparator> queue;
  std::priority_queue<Node*, std::vector<Node*>, NodeComparator> sucessors;
  std::unordered_set<Node*, std::hash<Node*>, NodeEquals> visited;
  Node* queue_element;
  Node* current;
  queue.push(initial);
  
  while(!queue.empty()) {
    current = queue.top();

    if(current->equals(target)) {
      return current;
    }

    queue.pop();
    visited.insert(current);
    sucessors = current->generateSucessors();

    while(!sucessors.empty()) {
      queue_element = sucessors.top();
      sucessors.pop();

      if (visited.find(queue_element) == visited.end()) {
        queue.push(queue_element);
      }
    }
  }
  return nullptr;
}
