
#include <limits.h> 
#include <stdio.h> 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> dijkstra(vector <vector <int> > graph, vector <int>& parents, int verticies, int src);
int minDistance(vector <int> weight, vector <bool> visted, int vecticies);
void printSolution(vector <int>weight, vector <int>parents, int verticies);

// driver program 
int main()
{
   
    int verticies; // Number of vertices in the graph 
    int source;//root 
    ifstream file{ "input.txt" };//
    if (!file.is_open()) return -1;
    file >> verticies; //reads the number of vertcies in the grah 
    file >> source; //reads the root/source
    vector <vector <int> > graph(verticies); 
    int vertex;

    //inputs the graph from the text file
    for (int i = 0; i < verticies; i++) {
        graph[i].resize(verticies);
        for (int j = 0; j < verticies; j++)
        {
            file >> vertex;
            graph[i][j] = vertex;
        }

    }

    vector <int>  parents(verticies); //holds the parent of each node
    vector <int>  weight(verticies); //eaxch node distance from the source vector 

   weight = dijkstra(graph,parents, verticies, source); // makes the call to dijkstra algorithm
   printSolution(weight, parents, verticies); // ptints the distance for each node from the root and the bath to get there 

   
   file.close();
   return 0;
}


// Dijkstra's implementation using a 2*2 int vector. to find single source shortest path
vector<int> dijkstra(vector <vector <int> > graph, vector <int>& parents, int verticies, int src)
{
    vector <int>  weight(verticies, INT_MAX); // shatest path from from te source, set all to infinity, in this case max integer 
    vector <bool> visited(verticies, 0);  // keeps track of visted nodes
    weight[src] = 0; // set distance from source to source to 0
    parents[src] = -1; //set parent of soruce to -1, dose not exist, so we knwo when we are are at the source when printing 

    //steps through until all nodes are check 
    for (int count = 0; count < verticies - 1; count++) {

        int u = minDistance(weight, visited, verticies); //checks for the smalles unvisted node 
        visited[u] = 1; // mark the smallest unvisted node as visted 

        //update adjacent verticies 
        for (int v = 0; v < verticies; v++)

            if (!visited[v] && // no need to check visted nodes
                graph[u][v] && // check if a path exist
                weight[u] != INT_MAX && //path exist from source to the node 
                weight[u] + graph[u][v] < weight[v]) //distance to get to node is less than currect distance 
            {
                weight[v] = weight[u] + graph[u][v]; //update if a shorter path exist
                parents[v] = u; //update parent to get to the node 
            }
    }

    return weight;
}

// check for the node wit the smallest uncehcked distance 
int minDistance(vector <int> weight, vector <bool> visted, int vecticies)
{
    // Initialize min value  to infinity
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < vecticies; v++)//step through the distance array
        if (visted[v] == false && weight[v] <= min) {
            min = weight[v]; 
            min_index = v;
        }
    return min_index;
}


// print weight/distance array and the path to get there 
void printSolution(vector <int>weight, vector <int>parents, int verticies)
{
    string path;
    cout << "data display as node diststance from source to the get to node and the path to get there" << endl;

    for (int i = 0; i < verticies; i++) {
        int temp = parents[i];
        path = to_string(i);
        while (temp != -1){
            path = to_string(temp) + "->" + path;
            temp = parents[temp];
        }
        cout << i << "\t\t" << weight[i] << "\t\t\t" << path << endl;
        
    }
}