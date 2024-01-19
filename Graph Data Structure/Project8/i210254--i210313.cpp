#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "i210254-i210313.h"
using namespace std;


void checkBridgeNode(Graph destination, int vertex);

void checkSinkNode(Graph& source, Graph& destination, int vertices);

void checkSourceNode(Graph& source, Graph& destination, int vertices);



int
main()
{


	ifstream file;

	file.open("testData.txt");

	int to = 0, from = 0;

	string str, str1;

	getline(file, str);

	getline(file, str);

	getline(file, str, ' ');

	getline(file, str, ' ');

	getline(file, str, ' ');

	int totalvertices = stoi(str);


	getline(file, str, ' ');

	getline(file, str, '\n');

	int totaledges = stoi(str);


	Graph undirected(totalvertices, totaledges);

	Graph g(totalvertices, totaledges);

	Graph dest(totalvertices, totaledges);

	cout << "Graph ready" << endl;


	getline(file, str);


	//getline(file, str, '\t');
	//cout << str << endl;
	//getline(file, str1, '\n');
	//cout << str1 << endl;

	for (int i = 0; i < (totaledges + 1); i++)

	{

		try
		{

			getline(file, str, '\t');

			//cout << str << endl;
			getline(file, str1, '\n');

			//cout << str1 << endl;
			g.addEdge(stoi(str), stoi(str1));

			dest.addEdge(stoi(str1), stoi(str));

			undirected.addEdge(stoi(str), stoi(str1));

			undirected.addEdge(stoi(str1), stoi(str));

		}
		catch (...)
		{

			cout << "No node" << endl;

		}

	}
	checkSinkNode(g, dest, totalvertices);

	undirected.mappedArray();

	g.mappedArray();



	cout << "Complete graph made" << endl;

	int choice = 0;

	while (choice != 17)
	{

		system("CLS");

		cout <<
			"*******************************************************************************************"
			<< endl;

		cout << endl;

		cout << "                          MAIN MENU                          "
			<< endl;

		cout << endl;

		cout <<
			"*******************************************************************************************"
			<< endl;


		cout <<
			"Welcome user!!!\t following are the functionalities you can apply on the graph \nCHOOSE YOUR OPTION";

		cout <<
			"\nenter 1 to Display the number of nodes \nenter 2 to Display the number of edges"
			<<

			" \nenter 3 to Display the number of source nodes \nenter 4 to Display the number of sink nodes"
			<<
			" \nenter 5 to Display the number of isolated nodes";

		cout <<
			"\nenter 6 to Display the number of bridge edges\nenter 7 to Display the number of articulation nodes"
			<<

			"\nenter 8 to Display the shortest path length distribution\nenter 9 to Display the diameter of the graph"
			<<

			" \nenter 10 to Display the in-degree distribution in the form of a table";

		cout <<
			"\nenter 11 to Display the out-degree distribution in the form of a table"
			<<

			"\nenter 12 to Display the size of the largest strongly connected component (SCC)"
			<<
			"\nenter 13 to Display the size distribution of all SCCs" <<

			"\nenter 14 to Display the size of the largest weakly connected component (WCC)"
			<<

			"\nenter 15 to Display the size distribution of all WCCs\nenter 16 to Display Adjacency List\nenter 17 to exit\n\n\n\n";


		cout << "Your Choice Here:\t ";

		int temp;

		cin >> choice;

		cout << endl;

		switch (choice)

		{

		case 1:

			cout << "The Total Vertices Are :" << totalvertices << endl;

			break;

		case 2:

			cout << "The Total Edges Are :" << totaledges << endl;

			break;

		case 3:

			checkSourceNode(g, dest, totalvertices);

			break;

		case 4:

			cout << "number of Sink Nodes are : ";
			g.findSinkNodes();

			break;

		case 5:

			cout << "\n the total number of isolated nodes are :" << g.
				findIsolatedNodes();

			break;

		case 6:

			checkBridgeNode(dest, totalvertices);

			break;

		case 7:

		{

			undirected.ArticulationPoints();

		}

		break;

		case 8:

			cout << "\nEnter the length of the distribution you want\t";

			cin >> temp;

			cout << "\nshortest path length distribution of " << temp << " is"
				<< g.shortestPathLengthDistribution(temp);

			break;

		case 9:

			cout << "\nthe diameter is : " << g.diameter();

			break;

		case 10:

			cout << "\nin degree distribution table:";

			g.degreeTable();

			break;

		case 11:

			cout << "\nout degree distribution table:";

			dest.degreeTable();

			break;

		case 12:

			g.SCCs();

			break;

		case 13:

			g.SCCDistribution();

			break;

		case 14:

			undirected.WCC();

			break;

		case 15:

			break;

		case 16:

			g.display();

			cout << "mapped Array:" << endl;

			g.displayMapped();

			break;

		case 17:

			break;

		default:

			cout << "invalid value";

			break;

		}

		_getch();

	}

	//g.showGraphStructure();
	// g.sourceNodes();


	// g.numberOfSourceNodes();
	cout << endl;

	//g.BFS(1);
	//g.DFS(2);

	//// g.searchSpec(5364);
	////_getche();
	//cout << "\nthe shortest path length is " << g.shortestPathLength(1, 4);
	//
	//cout << "\nshortest path length distribution of 3 is" << g.shortestPathLengthDistribution(3);
	//cout << "\nlargest out degree is : " << g.largestDegree();
	//cout << "\nlargest in degree is : " << dest.largestDegree() << endl;
	//
	//cout << "\nin degree distribution of 2 is : " << dest.degreeDistribution(2);


	//cout << "\nfind outnodes of element 2 : " <<g.findOutNodesOfAnElement(2);
	//cout << "\nfind innodes of element 2 : " << g.findInNodesOfAnElement(7);

	return 0;

}





void
checkBridgeNode(Graph destination, int vertex)
{

	int count = 0;

	for (int i = 0; i < vertex; i++)
	{

		if (destination.VertexDegree(i) == 2)
		{

			if (destination.getListAtIndex(i).get_head()->get_next()->
				get_data() != -1)

				count++;		//cout << destination.nodeAtIndex(i) << "," << destination.getListAtIndex(i).get_head()->get_next()->get_data() << "is a bridge node\n";
		}

	}

	cout << "The Number of Bridge Nodes are : " << count << endl;


}


void
checkSinkNode(Graph& source, Graph& destination, int vertices)
{

	bool flag = 0;

	int count = 0;

	for (int i = 0; i < vertices; i++)
	{

		if (destination.nodeAtIndex(i) != -1)
		{

			for (int j = 0; j < vertices; j++)
			{

				if (destination.nodeAtIndex(i) == source.nodeAtIndex(j))

					flag = 1;

			}


			if (flag == 0)
			{

				//cout << destination.nodeAtIndex(i) << " is a sink Node\n";
				count++;

				source.addEdge(destination.nodeAtIndex(i), -1);

			}

		}

		flag = 0;

	}

	cout << "total number of sink nodes are : " << count << endl;

}


void
checkSourceNode(Graph& source, Graph& destination, int vertices)
{

	bool flag = 0;

	int count = 0;

	for (int i = 0; i < vertices; i++)
	{

		if (source.nodeAtIndex(i) != -1)
		{

			for (int j = 0; j < vertices; j++)
			{

				if (source.nodeAtIndex(i) == destination.nodeAtIndex(j))

					flag = 1;

			}


			if (flag == 0)
			{

				//cout << source.nodeAtIndex(i) << " is a source Node\n";
				count++;

				destination.addEdge(source.nodeAtIndex(i), -1);

			}

		}

		flag = 0;

	}

	cout << "the total number of source nodes are: " << count << endl;


}
