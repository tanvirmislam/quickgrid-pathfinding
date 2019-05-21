#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <utility>
#include <limits>

#include "quickgrid.h"

using namespace std;

Node* getMin(unordered_set<Node*>& sqSet) {
	Node* outputSq = nullptr;
	float minF = numeric_limits<float>::max();

	for (Node* sq : sqSet) {
		if (sq->getF() < minF) {
			minF = sq->getF();
			outputSq = sq;
		}
	}

	return outputSq;
}

void runAStar(Canvas* canvas) {
	Node* start = canvas->getStart();
	Node* end   = canvas->getEnd();

	start->setG(0.0);
	start->setH(canvas->getDist(start, end));
	start->setF(start->getH());	

	unordered_set<Node*> closedSet;
	
	unordered_set<Node*> openSet;
	openSet.insert(start);

	while (!openSet.empty()) {
		Node* current = getMin(openSet);
		
		if (current == end) {
			Node* trace = end->getParent();
			while (trace != start) {
				trace->path();
				trace = trace->getParent();
			}
			break;
		}

		openSet.erase(current);
		closedSet.insert(current);
		
		if (current != start && current != end) {
			current->evaluated();
		}

		for (auto& coord : current->getNeighborCoords()) {
			Node* neighbor = canvas->get(coord);
			
			if (closedSet.find(neighbor) != closedSet.end()) {
				continue;
			}

			float tentativeG = current->getG() + canvas->getDist(current, neighbor);

			if (openSet.find(neighbor) == openSet.end()) {
				openSet.insert(neighbor);
				
				if (neighbor != end) {
					neighbor->discovered();
				}
			}
			else if (tentativeG >= neighbor->getG()) {
				continue;
			}
			
			neighbor->setG(tentativeG);
			neighbor->setH(canvas->getDist(neighbor, end));
			neighbor->setF(neighbor->getG() + neighbor->getH());
			neighbor->setParent(current);
		}

		canvas->draw();
	}
	
}


int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "usage: ./run <filename>" << endl;
		exit(1);
	}

	string filename = argv[1];

	Canvas* canvas = new Canvas(filename);	
	runAStar(canvas);
	canvas->draw(0);

	delete canvas;
	return 0;  
}
