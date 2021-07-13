#include "dfs.h"

DFS::DFS() {}

int DFS::recurse(Canvas*& canvas, Node*& current, Node*& start, Node*& end, std::unordered_set<Node*>& visited) {
	if ( (current == nullptr) || (visited.find(current) != visited.end()) ) {
		return 0;
	}
	else if (current == end) {
		return 1;
	}

	if (current != start && current != end) {
		current->setAsEvaluated();
	}
	visited.insert(current);
	
	int status = 0;
	for (auto& coord : current->getNeighborCoords()) {
		Node* neighbor = canvas->get(coord);
		
		if (visited.find(neighbor) != visited.end()) {
			continue;
		}

		neighbor->setParent(current);
		if (neighbor != start && neighbor != end) {
			neighbor->setAsDiscovered();
		}

		canvas->draw();
		
		status = recurse(canvas, neighbor, start, end, visited);	
		if (status == 1) {
			break;
		}
	}

	return status;
}

bool DFS::run(Canvas* canvas) {
	Node* start = canvas->getStart();
	Node* end   = canvas->getEnd();	

	std::unordered_set<Node*> visited;

	int status = recurse(canvas, start, start, end, visited);	

	if (status == 1) {
		Node* temp = end->getParent();
		while (temp != start) {
			temp->setAsPath();
			temp = temp->getParent();
		}
	}

	return false;
}
