#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include<iostream>
#include<list>
#include<stdexcept>

template <typename T>
class Node
{

public:
	T key;
	Node<T> *left, *right;

	Node()
	{

	}

	Node(T key)
	{
		this->key = key;
		this->left = NULL;
		this->right = NULL;
	}
};

template <typename T>
class binarySearchTree
{
public:

	Node<T> *root;

	binarySearchTree()
	{
		root = NULL;
	}

	~binarySearchTree()
	{
		if (root == NULL)
			throw runtime_error("Graful nu exista");
		removeNode(root);
	}

	void insert(T key)
	{
		if (root == NULL)
		{
			root = new Node<T>(key);
		}

		else
		{
			insert(key, root);
		}

	}

	Node<T>* search(T key)
	{
		if (root->key == key)
		{
			return root;
		}

		else
		{
			if (root->left == NULL && root->right == NULL)
			{
				cout << "Nu exista nodul cautat in graf";
				return NULL;
			}

			else
			{
				search(key, root);
			}
		}
	}

	void inorder(Node<T> *leaf)
	{
		if (leaf == NULL)
			return;
		inorder(leaf->left);
		cout << leaf->key << " ";
		inorder(leaf->right);
	}

	void preoder(Node<T> *leaf)
	{
		if (leaf == NULL)
		{
			return;
		}
		cout << leaf->key << " ";
		preoder(leaf->left);
		preoder(leaf->right);
	}

	void postorder(Node<T> *leaf)
	{
		if (leaf == NULL)
		{ 
			return;
		}
		postorder(leaf->left);
		postorder(leaf->right);
		cout << leaf->key << " ";
	}

	Node<T>* getRoot()
	{
		return root;
	}



private:

	void removeNode(Node<T> *leaf)
	{
		if (leaf != NULL)
		{
			removeNode(leaf->left);
			removeNode(leaf->right);
			delete[] leaf;

		}
	}

	Node<T>* search(T key,Node<T> *leaf)
	{
		//verificam daca trebuie sa cautam in dreapta sau in stanga nodului leaf

		//cout << "Am ajuns aici";

		if (leaf!=NULL && leaf->key == key)
		{
			return leaf;
		}
		
		 if (key < leaf->key)
		{
			//trebuie sa cautam in stanga nodului leaf
			if (leaf->left != NULL)
			{
				search(key, leaf->left);
			}

			else
			{
				cout << "Nodul nu a fost gasit";
				return NULL;
			}

		}

		if (key > leaf->key)
		{
			//trebuie sa cautam in dreapta nodului leaf
			if (leaf->right != NULL)
			{
				search(key, leaf->right);
			}

			else
			{
				cout << "Nodul nu a fost gasit";
				return NULL;
			}
		}

	}

	void insert(T key, Node<T> *leaf)
	{
		//verificam daca trebuie sa inseram in stanga sau in drepta radacinii:

		if (key < leaf->key)
		{
			//trebuie sa inseram in stanga nodului leaf

			if (leaf->left != NULL)
			{
				insert(key, leaf->left);
			}

			else
			{
				leaf->left = new Node<T>(key);
			}
		}

		if (key > leaf->key)
		{
			//trebuie sa inseram in drepta nodului leaf

			if (leaf->right != NULL)
			{
				insert(key, leaf->right);
			}

			else
			{
				leaf->right = new Node<T>(key);
			}
		}


	}


};

#endif