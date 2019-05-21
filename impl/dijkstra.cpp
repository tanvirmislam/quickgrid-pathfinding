#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>

#include "quickgrid.h"

using namespace std;

void runDijkstra(Canvas* canvas) {
	Node* start = canvas->getStart();
	Node* end   = canvas->getEnd();

	start->setG(0.0);

	priority_queue<Node*, vector<Node*>, CompareG> pq;
	pq.push(start);
	
	while (!pq.empty()) {
		Node* current = pq.top();
		pq.pop();

		if (current == end) {
			Node* temp = current->getParent();
			while (temp != start) {
				temp->path();
				temp = temp->getParent();
			}
			break;
		}
	
		if (current != start && current != end) {
			current->evaluated();
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
					neighbor->discovered();
				}
			}
						
		}
		
		canvas->draw();
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "usage: ./rundijkstra <filename>" << endl;
		exit(1);
	}
	string filename(argv[1]);

	Canvas* canvas = new Canvas(filename);
	runDijkstra(canvas);
	canvas->draw(0);

	delete canvas;
	return 0;  
}
