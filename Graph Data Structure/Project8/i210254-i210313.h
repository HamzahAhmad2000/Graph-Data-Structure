#pragma once


#include<iostream>
#include<cstring>

using namespace std;

int WP = 0;

int Largestwcc[100];

int temp_wcc[100];

int LargestWcc = INT_MIN;


class Node
{


private:
	int data;


	Node* next;


public:
	Node()
	{


		this->data = 0;


		next = nullptr;


	}
	Node(int value)
	{


		this->data = value;


		next = nullptr;


	}
	int get_data()
	{


		return data;


	}


	void set_data(int value)
	{


		this->data = value;


	}
	Node* get_next()
	{


		return next;


	}


	void set_next(Node* n)
	{


		this->next = n;


	}
};




class Stack
{


	Node* top;


	int size = 0;


public:

	Stack()
	{


		top = nullptr;


	}
	Node* get_top()
	{


		return this->top;


	}


	void set_top(Node* n)
	{


		top = n;


	}
	void insertatTop(int v)
	{


		Node* nnode = new Node(v);


		if (top == NULL)


		{


			top = nnode;




		}


		else


		{


			nnode->set_next(top);


			set_top(nnode);


		}




	}


	int deleteAtTop()
	{


		if (top == NULL)


		{


			cout << "emptyy stackkk" << endl;


			delete top;


			return 0;


		}


		Node* temp = top;


		top = top->get_next();


		int x = temp->get_data();


		delete temp;


		return x;


	}


	bool isEmpty()
	{


		if (top == NULL)


		{


			return true;


		}


		else


		{


			return false;


		}


	}


	void push(int y)
	{


		insertatTop(y);


	}
	int pop()
	{


		int val = deleteAtTop();


		return val;


	}


	int peek()
	{


		return top->get_data();


	}


};




class linkedlist
{


	Node* head;


	int size = 0;


public:
	linkedlist()
	{


		head = NULL;


	}
	linkedlist(int val)
	{


		Node* temp = new Node(val);


		head = temp;


	}
	Node* get_head()
	{


		return head;


	}


	void set_head(Node* rex)
	{


		head = rex;


	}
	void insertathead(int fun)
	{


		Node* nnode = new Node(fun);


		if (head == NULL)


		{


			head = nnode;




		}


		else


		{


			nnode->set_next(head);


			set_head(nnode);


		}




	}


	bool insertBefore(int x1, int x2)
	{


		Node* nnode = new Node(x2);


		if (head == NULL)


		{


			return false;


		}


		else


		{


			Node* temp1 = head;


			Node* prev = NULL;


			while (temp1 != NULL && temp1->get_data() != x1)


			{


				prev = temp1;


				temp1 = temp1->get_next();


			}


			if (temp1 == NULL)


			{


				return false;


			}


			else


			{


				nnode->get_next()->set_next(temp1);


				prev->get_next()->set_next(nnode);


				return true;


			}


		}


	}


	void insertattail(int v4)
	{


		Node* nnode = new Node(v4);


		if (head == NULL)


		{


			head = nnode;


		}


		else


		{


			Node* temp5 = head;


			while (temp5->get_next() != NULL)


			{


				temp5 = temp5->get_next();


			}


			temp5->set_next(nnode);


			nnode->set_next(NULL);


		}


	}


	void deleteAthead()
	{


		if (head == NULL)


		{


			delete head;



		}


		Node* temp6 = head;


		head = head->get_next();


		delete temp6;


	}


	void display()
	{


		if (head == NULL)


		{


			cout << "list is empty" << endl;


		}


		else


		{


			Node* temp4 = head;


			while (temp4 != NULL)


			{


				cout << temp4->get_data() << "->";


				temp4 = temp4->get_next();


			}


			cout << "Null";


		}


		cout << endl;



	}


	int size_of_linkedlist()
	{


		int count1 = -1;


		Node* temp = head;


		if (head == NULL)


		{


			cout << "empty" << endl;


			return count1;


		}


		while (temp != NULL)


		{


			temp = temp->get_next();


			count1++;


		}


		return count1;


	}


};





class Queue
{


	Node* front;


	Node* rear;


public:
	Queue()
	{


		front = NULL;


		rear = NULL;


	}


	int showFront()
	{



		return front->get_data();


	}


	int size()
	{


		int count7 = 0;


		Node* temp = front;


		while (temp != NULL)


		{


			count7++;


			temp = temp->get_next();



		}

		return count7;


	}


	void enQueue(int v7)
	{


		Node* n3 = new Node(v7);


		if (rear == NULL)


		{


			front = n3;


			rear = n3;


			return;


		}


		else


		{


			rear->set_next(n3);


			rear = n3;


			n3->set_next(NULL);


		}


	}


	int showRear()
	{


		return rear->get_data();


	}


	void displayQueue()
	{


		Node* temp = front;


		while (temp != NULL)


		{


			cout << temp->get_data() << endl;


			temp = temp->get_next();


		}


	}


	int deQueue()
	{


		if (front == NULL)


		{


			return 0;


		}


		Node* todelete = front;


		int temp8 = front->get_data();


		front = front->get_next();


		if (front == NULL)


		{


			rear = NULL;


		}


		return temp8;


	}


	bool isEmpty()
	{


		if (front == NULL && rear == NULL)


		{


			return true;


		}


		else


		{


			return false;


		}


	}



};





class Graph
{


	int vertex;


	int edge;


	linkedlist* l1;


	Queue q;


	Stack s;


	linkedlist* mappedArr;



	int SccDistArr[100] = { 0 };

	int sccIndex = 0;


	int* wccArr;


	int* tempWcc;

	int max = 0;

	int wccLargestSize = INT_MIN;

public:


	Graph()
	{


		edge = 0;


		vertex = 0;


		l1 = NULL;


	}
	Graph(int v)
	{


		this->vertex = v;


		l1 = new linkedlist[vertex];

		mappedArr = new linkedlist[vertex];

		for (int i = 0; i < vertex; i++)


		{


			Node* temp = new Node(-1);


			l1[i].set_head(temp);

			mappedArr[i].set_head(temp);


		}

	}
	Graph(int v, int e)
	{


		this->vertex = v;


		l1 = new linkedlist[vertex];

		mappedArr = new linkedlist[vertex];

		for (int i = 0; i < vertex; i++)


		{


			Node* temp = new Node(-1);


			l1[i].set_head(temp);

			mappedArr[i].set_head(temp);


		}


	}

	linkedlist getListAtIndex(int index)
	{


		return l1[index];


	}


	int nodeAtIndex(int index)
	{


		try
		{


			return l1[index].get_head()->get_data();


		}


		catch (...)
		{


			cout << "Vertex doesnot exist \n";


			return 0;


		}


	}


	int indexAtNode(int node)
	{


		for (int i = 0; i < vertex; i++)

		{


			if (l1[i].get_head()->get_data() == node)

			{


				return i;


			}


		}


		return -1;


	}


	void addEdge(int src, int dest)
	{


		//l1[src].insertattail(dest);
		for (int i = 0; i < vertex; i++)


		{


			if (l1[i].get_head()->get_data() == src)


			{

				Node* temp;

				temp = l1[i].get_head();

				while (temp != NULL)
				{

					if (temp->get_data() == dest)

						return;

					temp = temp->get_next();

				}


				l1[i].insertattail(dest);


				return;


			}


		}


		for (int i = 0; i < vertex; i++)


		{


			if (l1[i].get_head()->get_data() == -1)


			{


				l1[i].get_head()->set_data(src);


				l1[i].insertattail(dest);


				return;


			}


		}


		//l1[dest].insertattail(src);
	}


	void mappedArray()
	{

		for (int i = 0; i < vertex; i++)
		{

			Node* temp = new Node(i);

			mappedArr[i].set_head(temp);

			temp = l1[i].get_head();

			while (temp->get_next())
			{

				temp = temp->get_next();

				mappedArr[i].insertattail(indexAtNode(temp->get_data()));

			}


		}


	};


	void showGraphStructure()
	{


		for (int i = 0; i < vertex; i++)


		{


			cout << i << " ";


			l1[i].display();


			cout << endl;


		}
	}

	void BFS(int StartNode)
	{


		int x;


		x = indexAtNode(StartNode);


		if (x != -1)

		{


			q.enQueue(indexAtNode(StartNode));


			bool* visited = new bool[vertex];


			for (int i = 0; i < vertex; i++)


			{


				visited[i] = false;


			}
			visited[indexAtNode(StartNode)] = true;


			while (!q.isEmpty())


			{



				int temp = q.deQueue();


				int node;


				node = l1[temp].get_head()->get_data();




				Node* t = l1[temp].get_head();


				while (t != NULL)


				{


					int x = t->get_data();


					x = indexAtNode(x);


					if (visited[x] == false)


					{


						q.enQueue(x);


						visited[x] = true;


					}


					else


					{


						t = t->get_next();


					}


				}


			}



		}




	}



	int VertexDegree(int v)
	{


		int d = 0;


		Node* temp9 = l1[v].get_head();


		while (temp9 != NULL)


		{


			d++;


			temp9 = temp9->get_next();


		}


		return d;


	}


	void sourceNodes()	//shows all the source nodes
	{


		int* array = new int[vertex];


		for (int i = 0; i < vertex; i++)


		{


			array[i] = l1[i].get_head()->get_data();


		}
		for (int i = 0; i < vertex; i++)


		{


			bool flag = false;



			for (int k = 0; k < vertex; k++)


			{


				Node* temp = l1[k].get_head();


				if (temp == NULL)


				{


					continue;


				}


				while (temp != NULL)


				{


					if (array[i] == temp->get_data())


					{


						flag = true;


					}


					temp = temp->get_next();


				}


			}


			if (flag == false)


			{


				/*      cout << array[i] << endl; */
			}


		}


	}


	void searchSpec(int d)	//to look at the list of any specific ID
	{


		int* array = new int[vertex];


		for (int i = 0; i < vertex; i++)


		{


			array[i] = l1[i].get_head()->get_data();


		}
		for (int i = 0; i < vertex; i++)


		{


			if (d == array[i])


			{


				Node* temp = l1[i].get_head();


				while (temp != NULL)


				{


					cout << temp->get_data() << endl;


					temp = temp->get_next();


				}


				return;


			}


		}


	}


	bool checkExistance(int d)
	{


		int* array = new int[vertex];


		for (int i = 0; i < vertex; i++)


		{


			array[i] = l1[i].get_head()->get_data();


		}
		for (int i = 0; i < vertex; i++)

		{


			if (d == array[i])

			{


				return true;


			}


		}


		return false;


	}


	int diameter()
	{


		int max = INT_MIN;


		int x = 1;


		for (int i = 0; i < vertex; i++)


			for (int j = 0; j < vertex; j++)

			{


				x =

					shortestPathLength(l1[i].get_head()->get_data(),

						l1[j].get_head()->get_data());


				if (x != -1)



					if (x > max)


						max = x;


			}


		return max;


	}


	float shortestPathLengthDistribution(int length)
	{


		int totalsize = diameter();


		totalsize++;


		float* distributionLenght = new float[totalsize];


		for (int i = 0; i < totalsize; i++)

		{


			distributionLenght[i] = 0;


		}
		float count = 0;


		int x;


		for (int i = 0; i < vertex; i++)


			for (int j = 0; j < vertex; j++)

			{


				x =

					shortestPathLength(l1[i].get_head()->get_data(),

						l1[j].get_head()->get_data());


				if (x != -1)


				{


					distributionLenght[x]++;


					count++;



				}


			}


		float probablity;


		probablity = distributionLenght[length] / count;


		return probablity;



	}


	int shortestPathLength(int StartNode, int destination)
	{



		int dest = indexAtNode(destination);


		int start = indexAtNode(StartNode);


		//cout << "destination " << dest << " starting " << start;
		if (dest == -1 || start == -1)

		{


			cout << "invalid nodes\n";


			return -1;


		}


		else

		{


			q.enQueue(indexAtNode(StartNode));


			bool* visited = new bool[vertex];


			int* distance = new int[vertex];


			for (int i = 0; i < vertex; i++)


			{


				visited[i] = false;


				distance[i] = 0;


			}



			visited[indexAtNode(StartNode)] = true;


			while (!q.isEmpty())


			{


				int count = 1;


				int temp = q.deQueue();


				Node* t = l1[temp].get_head();



				while (t != NULL)


				{


					int x = t->get_data();


					x = indexAtNode(x);




					if (visited[x] == false)


					{



						q.enQueue(x);


						//cout << "node is " << nodeAtIndex(x) << "index is " << x << " dest is " << dest << endl;
						distance[x] = distance[temp] + 1;


						if (x == dest)

						{


							return distance[x];


						}


						visited[x] = true;



					}


					else


					{



						t = t->get_next();


					}


				}


			}


			return -1;


		}


	}


	float degreeDistribution(int nodes)
	{


		int totalsize;


		totalsize = largestDegree() + 1;


		float* degreelist = new float[totalsize];


		for (int i = 0; i < totalsize; i++)

		{


			degreelist[i] = 0;


		}
		float count = 0;


		int x;


		for (int i = 0; i < vertex; i++)

		{


			x = l1[i].size_of_linkedlist();


			degreelist[x]++;


			count++;


		}
		float probablity;


		probablity = degreelist[nodes] / count;


		return probablity;


	}


	int largestDegree()
	{


		int max = -1;


		int x;


		for (int i = 0; i < vertex; i++)

		{


			x = l1[i].size_of_linkedlist();


			if (x > max)


				max = x;


		}


		return max;


	}


	void degreeTable()
	{


		int x = largestDegree();


		x++;




		cout <<

			"\n---------------------------------------------------------------------------------\n";


		cout << "|V|k \t:\t";


		for (int i = 1; i < x; i++)

		{


			cout << i << "\t|";



		}
		cout << "\n|V| \t:\t";


		for (int i = 1; i < x; i++)

		{


			cout << degreeDistribution(i) << "\t|";


		}
	}

	int findInNodesOfAnElement(int source)
	{


		int x = indexAtNode(source);


		Node* temp;


		int count = 0;


		for (int i = 0; i < vertex; i++)

		{


			temp = l1[i].get_head();


			while (temp)

			{


				if (source == temp->get_data())


					count++;


				temp = temp->get_next();


			}


			if (i == x)

			{


				count--;


			}


		}


		return count;



	}


	int findIsolatedNodes()
	{


		int x;


		int count = 0;


		for (int i = 0; i < vertex; i++)

		{


			x = findInNodesOfAnElement(l1[i].get_head()->get_data());


			if (x == 0)

			{


				x = findOutNodesOfAnElement(l1[i].get_head()->get_data());


				if (x == 0)


					count++;


			}



		}


		return count;


	}


	int findOutNodesOfAnElement(int source)
	{


		int x = indexAtNode(source);


		Node* temp;


		temp = l1[x].get_head();


		int count = -1;


		while (temp)

		{


			temp = temp->get_next();


			count++;


		}


		return count;


	}


	void displayMapped()
	{


		for (int i = 0; i < vertex; i++)

		{


			Node* temp;


			temp = mappedArr[i].get_head();


			Node* prevTemp = NULL;


			while (temp)

			{


				if (temp->get_data() != -1)


				{

					cout << temp->get_data() << "\t";

					temp = temp->get_next();

				}


				else

				{

					temp = NULL;

					prevTemp->set_next(NULL);

				}

				prevTemp = temp;



			}


			cout << endl;


		}

	}


	void display()
	{


		for (int i = 0; i < vertex; i++)

		{


			Node* temp;


			temp = l1[i].get_head();


			Node* prevTemp = NULL;


			while (temp)

			{


				if (temp->get_data() != -1)


				{

					cout << temp->get_data() << "\t";

					temp = temp->get_next();

				}


				else

				{

					temp = NULL;

					prevTemp->set_next(NULL);

				}

				prevTemp = temp;



			}


			cout << endl;


		}


	}


	void findSinkNodes()
	{


		int count = 0;


		for (int i = 0; i < vertex; i++)

		{


			Node* temp;


			temp = l1[i].get_head();


			temp = temp->get_next();


			if (temp->get_data() == -1)


				count++;



		}


		cout << count;


	}


	void ArticulationPointsRecursive(int u, bool visited[], int disc[],
		int low[], int& time, int parent,

		bool isAP[])
	{

		// Count of children in DFS Tree
		int children = 0;


		// Mark the current node as visited
		visited[u] = true;


		// Initialize discovery time and low value
		disc[u] = low[u] = time++;


		// Go through all vertices adjacent to this
		Node* temp;

		temp = mappedArr[u].get_head();

		temp = temp->get_next();

		while (temp)

		{

			int i = temp->get_data();

			int v = i;		// v is current adjacent of u

				  // If v is not visited yet, then make it a child of u
				  // in DFS tree and recur for it
			if (!visited[v])

			{

				children++;

				parent = u;

				ArticulationPointsRecursive(v, visited, disc, low, time, parent,
					isAP);


				// Check if the subtree rooted with v has a connection to
				// one of the ancestors of u
				low[u] = min(low[u], low[v]);


				// u is an articulation point in following cases

				// (1) u is root of DFS tree and has two or more children.
				if (parent != -1 && low[v] >= disc[u])

					isAP[u] = true;


				// (2) If u is not root and low value of one of its child
				// is more than discovery value of u.
				if (parent != 0 && low[v] >= disc[u])

					isAP[u] = true;

			}


			// Update low value of u for parent function calls.
			else if (v != parent)

				low[u] = min(low[u], low[v]);

			temp = temp->get_next();

		}

	}



	void ArticulationPoints()
	{


		bool* visited = new bool[vertex];

		int* disc = new int[vertex];

		int* low = new int[vertex];

		bool* ap = new bool[vertex];

		int time = 0, par = -1;

		for (int i = 0; i < vertex; i++)
		{

			visited[i] = 0;

			ap[i] = 0;


		}


		for (int u = 0; u < vertex; u++)

			if (visited[u] == false)

				ArticulationPointsRecursive(u, visited, disc, low,
					time, par, ap);

		int count = 0;

		for (int u = 0; u < vertex; u++)

			if (ap[u] == true)

				count++;


		cout << "The total Articulation Points Are: " << count << " ";


	}



	void DFS(int v, bool visited[], int& count)
	{

		visited[v] = true;

		count++;

		Node* temp = mappedArr[v].get_head();

		temp = temp->get_next();

		int i = 0;

		while (temp)
		{

			if (!visited[i])

				DFS(i, visited, count);

			i++;

			temp = temp->get_next();

		}

	}


	Graph getTranspose()
	{

		Graph gT(vertex);

		for (int v = 0; v < vertex; v++)

		{

			Node* temp = mappedArr[v].get_head();

			temp = temp->get_next();

			int i = 0;

			while (temp)
			{

				gT.mappedArr[i].insertattail(v);

				temp = temp->get_next();

				i++;

			}

		}

		return gT;

	}


	void fillOrder(int v, bool visited[], Stack& stack)
	{

		visited[v] = true;



		Node* temp = mappedArr[v].get_head();

		temp = temp->get_next();

		int i = 0;

		while (temp)
		{

			if (!visited[i])

				fillOrder(i, visited, stack);

			temp = temp->get_next();

		}


		stack.push(v);

	}


	void SCCs()
	{

		int count = 0;

		int max1 = 0;

		Stack stack;

		bool* visited = new bool[vertex];

		for (int i = 0; i < vertex; i++)

			visited[i] = false;

		for (int i = 0; i < vertex; i++)

			if (visited[i] == false)

				fillOrder(i, visited, stack);


		Graph gr = getTranspose();


		for (int i = 0; i < vertex; i++)

			visited[i] = false;


		while (stack.isEmpty() == false)

		{

			int v = stack.pop();

			if (visited[v] == false)

			{

				count = 0;

				gr.DFS(v, visited, count);

				cout << endl;


				if (count < 50)

					SccDistArr[count]++;

				if (count > max1)

					max1 = count;

			}


		}

		cout << "the largest SCC is " << count;

		max = max1;

	}


	void SCCDistribution()
	{

		int total = 0;

		for (int i = 0; i < 50; i++)
		{

			total += SccDistArr[i];

		}
		cout <<
			"The distribution table of SCCs is :\n---------------------------------------------------------------------------------------------";

		cout << "\nSCC \t:\t";

		for (int i = 1; i <= max; i++)

		{


			cout << i << "\t|";



		}
		cout << "\nFreq \t:\t";


		for (int i = 1; i <= max; i++)

		{


			cout << SccDistArr[i] << "\t|";


		}


	}


	void WCC()
	{

		bool* check = new bool[vertex];

		for (int i = 0; i < vertex; i++)

			check[i] = false;


		for (int i = 0; i < vertex; i++)

		{

			if (check[i] == false)

			{

				WP = 0;

				WCC_rec(i, check);

				cout << "  size=" << WP + 1;

				cout << "\n";

				if (WP > LargestWcc)

				{

					LargestWcc = WP;

					for (int j = 0; j <= WP; j++)

					{

						Largestwcc[j] = temp_wcc[j];

					}
					WP = 0;


				}

			}

		}
		delete[]check;

	}

	void WCC_rec(int v, bool check[])
	{

		check[v] = true;

		cout << v << " ";

		temp_wcc[WP] = v;


		Node* temp = l1[v].get_head();

		if (temp->get_next() != NULL)

		{

			temp = temp->get_next();

			int temp_positioning;

			while (temp)

			{


				for (int i = 0; i < vertex; i++)

				{

					if (l1[i].get_head()->get_data() == temp->get_data())

						temp_positioning = i;

				}

				temp = temp->get_next();

				if (!check[temp_positioning])

				{

					WP++;

					WCC_rec(temp_positioning, check);

				}

			}

		}

	}


};
