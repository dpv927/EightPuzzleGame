Node* AStar() {
  std::priority_queue<Node*, std::vector<Node*>, NodeComparator> queue;
  std::priority_queue<Node*, std::vector<Node*>, NodeComparator> tmp;
  std::unordered_set<Node*, std::hash<Node*>, NodeEquals> visited;
  Node* queue_element;
  queue.push(Node::ROOT_NODE);
  
  while(!queue.empty()) {
    Node* current = queue.top();

    if(current->equals(Node::FINAL_NODE)) {
      return current;
    }

    queue.pop();
    visited.insert(current);
    tmp = current->generateSucessors();

    while(!tmp.empty()) {
      queue_element = tmp.top();
      tmp.pop();

      if (visited.find(queue_element) == visited.end()) {
        queue.push(queue_element);
      }
    }
  }
  return nullptr;
}
