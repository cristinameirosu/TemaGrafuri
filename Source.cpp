#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
	/*cout << "Miau";
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
	*/

	binarySearchTree<int> binaryGraph;
	binaryGraph.insert(10);
	binaryGraph.insert(12);
	binaryGraph.insert(14);
	binaryGraph.insert(6);
	binaryGraph.insert(8);
	binaryGraph.insert(7);
	binaryGraph.insert(9);
	binaryGraph.insert(5);
	binaryGraph.insert(4);
	Node<int> *nodeToBeFound=new Node<int>;
	nodeToBeFound = binaryGraph.search(10);
	if (nodeToBeFound != NULL)
	{
		cout << "Nodul a fost gasit.Cheia sa este "<<nodeToBeFound->key<<endl;
	}
	nodeToBeFound = binaryGraph.search(8);
	cout << binaryGraph.getRoot()->key << endl;
	binaryGraph.inorder(binaryGraph.getRoot());
	cout << endl;
	binaryGraph.preoder(binaryGraph.getRoot());
	cout << endl;
	binaryGraph.postorder(binaryGraph.getRoot());
	char c;
	cin >> c;
}