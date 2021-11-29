/*
*  autor: Benjamin Valdes Aguirre
*  fecha: Diciembre 2020
*  programa: act 4.1 Implementación Grafos
*  desc: estos programas son soluciones parciales a algunos de
*  las actividades planteadas en el curso TC1031
*
*
*  Extiende este archivo para completar tu solución.
*/

#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;


class Graph {
private:
		int edgesList;
		int edgesMat;
		int nodes;
    vector<int> *adjList;
		int *adjMatrix;
		//vector<Type> *vect = new vector<Type>
        void dHelper(int, int, stack<int> &, list<int> &, vector<vector<int>> &);
        void printVisited(list<int> &visited);
        string printPath(vector<vector<int>> &, int, int);

public:
		void loadGraphMat(string, int, int);
        void loadGraphList(string, int, int);
		Graph(int);
		Graph();
		void addEdgeAdjMatrix(int, int);
        void addEdgeAdjList(int, int);
		string printAdjMat();
		string printAdjMat_clean();
        string printAdjList();
        string DFS(int, int);
        string BFS(int, int);

		bool contains(list<int>, int);
		void sortAdjList();
};


void Graph::loadGraphMat(string name, int a, int b){
	adjMatrix = new int [a*b];
	nodes = a;
	for (int i = 0; i < a*b; i++)
		adjMatrix[i] = 0;
		string line;
		ifstream lee (name);
		int u, v;
		if (lee.is_open()){
			while (getline(lee, line)){
				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjList(u,v);
			}
			lee.close(); // Closes the file
		} else {
			cout << "Unable to open file";
		}
}

void Graph::loadGraphList(string arch, int a, int b){
    nodes = a;
    adjList = new vector<int>[nodes];

    string line;
    ifstream lee (arch);
    int u, v;
    if (lee.is_open()){
        while (getline(lee, line)){
            u = stoi(line.substr(1,1));
            v = stoi(line.substr(4,1));
            addEdgeAdjMatrix(u,v);
        }
        lee.close(); // Closes the file
    } else {
        cout << "Unable to open file";
    }
}

Graph::Graph() {
	edgesList = edgesMat = 0;
}

Graph::Graph(int n) {
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for (int i = 0; i < nodes*nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;
}

void Graph::addEdgeAdjMatrix(int u, int v){
	adjMatrix[u*nodes+v] = 1;
	adjMatrix[v*nodes+u] = 1;
	edgesMat++;
}

void Graph::addEdgeAdjList(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edgesMat++;
}

string Graph::printAdjList(){
	  stringstream aux;
		for (int i = 0; i < nodes; i++){
	        aux << "vertex "
	             << i << " :";
	        for (int j = 0; j < adjList[i].size(); j ++){
							 aux << " " << adjList[i][j];
					}
	        aux << " ";
    }
		return aux.str();

}

string Graph::printAdjMat(){
	stringstream aux;
	for (int i = 0; i < nodes; i++){
	   for (int j = 0; j < nodes; j++){
			 aux << adjMatrix[i*nodes+j] << " ";
		 }
  }
	return aux.str();
}

string Graph::printAdjMat_clean(){
	stringstream aux;
	aux << "\n nodes \t|";
	for (int i = 0; i < nodes; i++){
			aux << "\t" << i ;
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
			aux << "__________";
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
		 aux << i << "\t|";
	   for (int j = 0; j < nodes; j++){
			 aux << "\t" << adjMatrix[i*nodes+j];
		 }
	   aux << "\n";
  }
	return aux.str();
}
string Graph::DFS(int start, int goal) {       // Depth-First Search - Profundidad
    stack <int> st;
    list <int> visited;     // Lista de los nodos visitados
    vector <vector<int>> paths(nodes, vector<int> (1, -1));     // Guarda los caminos.
    st.push(start);
    dHelper(start, goal, st, visited, paths);
    return printPath(paths, start, goal);
}

void Graph::dHelper(int current, int goal, stack<int> &st, list<int> &visited, vector<vector<int>> &paths) {
    if (current == goal){       // 1er Caso base de recursión.
        printVisited(visited);
    } else if (st.empty()){     // 2ndo Caso base de recursión.
        cout << "Node not found";
    } else {        // Empieza recursión.
        current = st.top();
        visited.push_back(current);
        for (int i = 0; i < adjList[current].size(); i++){
            if(!contains(visited, adjList[current][i])){    // Condición para que no se repitan en la lista de visitados.
                st.push(adjList[current][i]);
                paths[adjList[current][i]][0] = current;
            }
        }
        dHelper(current, goal, st, visited, paths);
    }
}

void Graph::printVisited(list<int> &v){
    cout << "visited: ";
    while (!v.empty()){
        cout<<v.front()<<" ";
        v.pop_front();
    }
    cout<<endl;
}

string Graph::printPath(vector<vector<int>> &path, int start, int goal) {
    stringstream stroutput;
    int node = path[goal][0];
    stack<int> reverse;
    reverse.push(goal);
    stroutput<<"path ";
    while (node != start){
        reverse.push(node);
        node = path[node][0];
    }
    reverse.push(start);
    while (!reverse.empty()){
        stroutput<<reverse.top()<<" ";
        reverse.pop();
    }
    stroutput<<endl;
    return stroutput.str();
}

bool Graph::contains(list<int> ls, int node){
    list<int>::iterator it;
    it = find(ls.begin(), ls.end(), node);
    if(it != ls.end())
        return true;
    else
        return false;
}

void Graph::sortAdjList(){
    for (int i = 0; i < nodes; i++)
        sort(adjList[i].begin(),adjList[i].end());
}

/*string Graph::BFS(int, int){        // Breadth-First Search -

}*/

#endif /* Graph_H_ */
