#include "List.h"
#include <list>
#include<queue>
#include<iostream>
#include<stdexcept>
using namespace std;

int pos = -1;

template <typename T>
class Node
{
public:
	T value;
	int index;
	list<Node<T> > *neighbours;

	Node()
	{
		this->neighbours = new list<Node<T> >;
	}

	Node(T value)
	{
		this->value = value;
		this->index = ++pos;
		this->neighbours = new list<Node<T> >;
	}
};


template <typename T>

class Graph
{

public :
	
	list<Node<T> > nodes;

	void addVertex(T value)
	{
		nodes.push_back(Node<T>(value));
	}

	void addEdge(T from, T to)
	{
		list<Node<T> >::iterator it;
		list<Node<T> >::iterator it2;
		for (it = nodes.begin(); it != nodes.end(); it++)
		{
			if (it->value == from)
			{
				//verificam daca nodul to exista deja in graf
				
				for (it2 = nodes.begin(); it2 != nodes.end(); it2++)
				{
					if (it2->value == to)
					{
						it->neighbours->push_back(*it2);
						return;
					}
				}

				//in cazul in care nu exista inca, trebuie creat

				Node<T> tempNode =Node<T>(to);
				addVertex(to);
				it->neighbours->push_back(tempNode);
				return;
			}
		}

		throw runtime_error("Nu exista in graf nodul de la care incearca se se adauge o muchie");
	}

	void printGraph()
	{
		list<Node<T> >::iterator it;
		list<Node<T> >::iterator it2;
		for (it = nodes.begin(); it != nodes.end(); it++)
		{
			cout << "Nodul cu indexul "<<it->index<<"si cu cheia  "<< it->value<< "are vecinii: " ;
			for (it2 = it->neighbours->begin(); it2 != it->neighbours->end(); it2++)
			{
				cout << (*it2).value << " ";
			}
			cout << endl;
		}
	}



	void BFS(Node<T> startNode)
	{
		list<Node<T> >::iterator it;
		queue<Node<T> > queue;
		queue.push(startNode);
		bool *visits = new bool[nodes.size()];
		for (int i = 0; i < nodes.size(); i++)
		{
			visits[i] = false;
		}

		visits[startNode.index] = true;
		
		while (!queue.empty())
		{
			startNode = queue.front();
			cout << startNode.value << " ";
			//parcurgem toti vecinii acestui nod si ii vizitam
			queue.pop();
			for (it = startNode.neighbours->begin(); it != startNode.neighbours->end(); it++)
			{
				if (visits[it->index] == false)
				{
					visits[it->index] = true;
					queue.push(*it);
				}
			}
			
		}

		cout << endl;
	}

	void applyDFS(Node<T> startNode,bool visits[])
	{
		list<Node<T> >::iterator it;
		visits[startNode.index] = true;
		cout << startNode.value << " ";
		for (it = startNode.neighbours->begin(); it != startNode.neighbours->end(); it++)
		{
			if (visits[it->index] == false)
				applyDFS(*it,visits);
		}
	}

	void DFS(Node<T> startNode)
	{
		bool *visits = new bool[nodes.size()];
		for (int i = 0; i < nodes.size(); i++)
		{
			visits[i] = 0;
		}
		applyDFS(startNode,visits);
	}

};