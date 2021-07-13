#include "bfs.h"

BFS::BFS() {}

bool BFS::run(Canvas* canvas) {
	if (canvas->isEmpty()) {
		return false;
	}

	Node* start = canvas->getStart();
	Node* end = canvas->getEnd();	

	std::unordered_set<Node*> visited;

	std::queue<Node*> q;
	q.push(start);

	bool isTargetFound = false;

	while (!q.empty()) {
		Node* current = q.front();
		q.pop();

		if (current == end) {
			isTargetFound = true;
			break;
		}
		else if (current != start) {
			current->setAsEvaluated();
		}

		visited.insert(current);

		for (auto& coord : current->getNeighborCoords()) {
			Node* neighbor = canvas->get(coord);
			
			if (visited.find(neighbor) == visited.end()) {
				neighbor->setParent(current);

				if (neighbor != start && neighbor != end) {
					neighbor->setAsDiscovered();
				}

				q.push(neighbor);
				canvas->draw();
			}
		}
	}

	if (!isTargetFound) {
		return false;
	}

	Node* temp = end->getParent();
	while (temp != start) {
		temp->setAsPath();
		temp = temp->getParent();
	}

	return true;
}
