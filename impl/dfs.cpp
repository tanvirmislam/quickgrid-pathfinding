#include <iostream>
#include <unordered_set>
#include "quickgrid.h"

using namespace std;

int recurse(Canvas*& canvas, Node*& current, Node*& start, Node*& end, unordered_set<Node*>& visited) {
	if ( (current == nullptr) || (visited.find(current) != visited.end()) ) {
		return 0;
	}
	else if (current == end) {
		return 1;
	}

	if (current != start && current != end) {
		current->evaluated();
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
			neighbor->discovered();
		}

		canvas->draw();
		
		status = recurse(canvas, neighbor, start, end, visited);	
		if (status == 1) {
			break;
		}
	}

	return status;
}


void runBFS(Canvas*& canvas) {
	Node* start = canvas->getStart();
	Node* end   = canvas->getEnd();	
	
	unordered_set<Node*> visited;

	int status = recurse(canvas, start, start, end, visited);	

	if (status == 1) {
		Node* temp = end->getParent();
		while (temp != start) {
			temp->path();
			temp = temp->getParent();
		}
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
