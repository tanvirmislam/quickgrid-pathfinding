#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <utility>
#include <limits>

#include "astar.h"

AStar::AStar() {}

Node* AStar::getMin(std::unordered_set<Node*>& nodeSet) {
	Node* outputNode = nullptr;
	float minF = std::numeric_limits<float>::max();

	for (auto& node : nodeSet) {
		if (node->getF() < minF) {
			minF = node->getF();
			outputNode = node;
		}
	}

	return outputNode;
}

bool AStar::run(Canvas* canvas) {
	if (canvas->isEmpty()) {
		return false;
	}

	Node* start = canvas->getStart();
	Node* end   = canvas->getEnd();

	start->setG(0.0);
	start->setH(canvas->getDist(start, end));
	start->setF(start->getH());	

	std::unordered_set<Node*> closedSet;
	
	std::unordered_set<Node*> openSet;
	openSet.insert(start);

	while (!openSet.empty()) {
		Node* current = getMin(openSet);
		
		if (current == end) {
			// Target node found
			Node* trace = end->getParent();

			while (trace != start) {
				trace->setAsPath();
				trace = trace->getParent();
			}

			return true;
		}

		openSet.erase(current);
		closedSet.insert(current);
		
		if (current != start && current != end) {
			current->setAsEvaluated();
		}

		for (auto& coord : current->getNeighborCoords()) {
			Node* neighbor = canvas->get(coord);
			
			if (closedSet.find(neighbor) != closedSet.end()) {
				// This node has already been evaluated
				continue;
			}

			// Tentative cost to visit this node
			float tentativeG = current->getG() + canvas->getDist(current, neighbor);

			if (openSet.find(neighbor) == openSet.end()) {
				// This node has been newly discovered
				openSet.insert(neighbor);
				
				if (neighbor != end) {
					neighbor->setAsDiscovered();
				}
			}
			else if (tentativeG >= neighbor->getG()) {
				// This node was previously discovered and the cost was less
				// Don't update the cost
				continue;
			}

			// Update the cost to visit this node
			neighbor->setG(tentativeG);
			neighbor->setH(canvas->getDist(neighbor, end));
			neighbor->setF(neighbor->getG() + neighbor->getH());
			neighbor->setParent(current);
		}

		canvas->draw();
	}

	// Target node not found
	return false;
}
