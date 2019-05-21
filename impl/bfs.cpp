#include <iostream>
#include <queue>
#include <unordered_set>
#include "quickgrid.h"

using namespace std;

void runBFS(Canvas*& canvas) {
	Node* start = canvas->getStart();
	Node* end   = canvas->getEnd();	
	
	unordered_set<Node*> visited;

	queue<Node*> q;
	q.push(start);

	while (!q.empty()) {
		Node* current = q.front();
		q.pop();

		if (current == end) {
			break;
		}
		else if (current != start) {
			current->evaluated();
		}
		visited.insert(current);

		for (auto& coord : current->getNeighborCoords()) {
			Node* neighbor = canvas->get(coord);
			
			if (visited.find(neighbor) == visited.end()) {
				neighbor->setParent(current);
				if (neighbor != start && neighbor != end) {
					neighbor->discovered();
				}
				q.push(neighbor);

				canvas->draw();
			}
			else {
				cout << "neighbor already visited" << endl;
			}
		}

		//canvas->draw();
	}

	Node* temp = end->getParent();
	while (temp != start) {
		temp->path();
		temp = temp->getParent();
	}
}


int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "usage: ./runbfs <filename>" << endl;
		exit(1);
	}
	
	string filename(argv[1]);

	Canvas* canvas = new Canvas(filename);
	runBFS(canvas);
	canvas->draw(0);

	delete canvas;	

	return 0;
} 
