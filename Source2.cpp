#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	cout << "Miau";
	Graph<int> graph;
	for (int i = 0; i <= 6; i++)
	{
	graph.addVertex(i);
	}


	graph.addEdge(0, 6);
	graph.addEdge(6, 5);
	graph.addEdge(5, 4);
	graph.addEdge(0, 3);
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(3, 2);
	graph.addEdge(2, 1);

	graph.printGraph();
	list<Node<int> >::iterator it;
	it = graph.nodes.begin();
	graph.BFS(*it);
	graph.DFS(*it);
	char c;
	cin >> c;
}