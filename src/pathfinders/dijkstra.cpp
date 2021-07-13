#include "dijkstra.h"

Dijkstra::Dijkstra() {}

bool Dijkstra::run(Canvas* canvas) {
	Node* start = canvas->getStart();
	Node* end   = canvas->getEnd();

	start->setG(0.0);

	std::priority_queue<Node*, std::vector<Node*>, CompareG> pq;
	pq.push(start);

	while (!pq.empty()) {
		Node* current = pq.top();
		pq.pop();

		if (current == end) {
			Node* temp = current->getParent();

			while (temp != start) {
				temp->setAsPath();
				temp = temp->getParent();
			}

			return true;
		}
	
		if (current != start && current != end) {
			current->setAsEvaluated();
		}

		for (auto& coord : current->getNeighborCoords()) {
			Node* neighbor = canvas->get(coord);
			
			float dist  = canvas->getDist(current, neighbor);
			float total = current->getG() + dist;

			if (total < neighbor->getG()) {
				neighbor->setG(total);
				neighbor->setParent(current);
				pq.push(neighbor);

				if (neighbor != start && neighbor != end) {
					neighbor->setAsDiscovered();
				}
			}
						
		}
		
		canvas->draw();
	}

	return false;
}
