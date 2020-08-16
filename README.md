# Dijkstra-s-Algorithm
Finds the shortest path from source to all other nodes in the graph

# Infinity = INT_MAX = 2147483647

# The Driver program/ main funtion 

- inputs the graph and the source vertex from the a txt file using a nested for loop
    first number represent the number of verticies in the graph (sorted in int verticies;)
    second number represents the source (stored in int source;)
    the next n*n numbers represents the 2X2 array for the graph (vector <vector <int> > graph(verticies);)
    the index ofthe array correcponds to the node
    each array shows distance to adjacent node 
    if not an adjacent node then it is represented as 0 
    0 also represents the node disatnce to it self
    below is a format in which the txt file must be created 
    5
    0
    0 2 4 3 0
    0 0 0 0 6
    0 0 0 0 7
    0 0 0 0 0
    
 - create a vector that holds the parent of each node of size vertcies/n (vector <int>  parents(verticies);)
 - create a vector to hold the distance to all nodes  of size vecticies/n (vector <int>  weight(verticies);)
 - call the the dijkstra function : dijkstra(graph,parents, verticies, source), the parent vector is being refference
   parameters:
   - graph
   - parents
   - vertcies
   - source
 - the dijkstra function returns a vector of with the distance to get to each nodes and store it into the weight vector
 - make call to printFunction
 
 # vector<int> dijkstra(vector <vector <int> > graph, vector <int>& parents, int verticies, int src);
 - create a weight vector and initilize all index to INT_MAX: vector <int>  weight(verticies, INT_MAX);
 -create a visted vector and initilize all index to false: vector <bool> visited(verticies, 0);
 -set source weight to 0: weight[src] = 0;
 -set parent of source to -1: parents[src] = -1; //set parent of soruce to -1, dose not exist, so we knwo when we are are at the source when printing 
 - Enter for loop that runs n-1ertcies-1)imes
 - make call for adjacent node with shartest disatnce to: nDistance(weight, visited, verticies);
 - store min index in u
 - set min index as visted 
 - enter nested for loop that runs n(vertcies) times, to update adject node and parent 
 - return the weighted vector of the source
 
 # int minDistance(vector <int> weight, vector <bool> visted, int vecticies)// returns the minimum unchked index/node
 - int min = INT_MAX; //initizale min tothe max value/infinity 
 - int min_index; //stores the min index
 - enter a for loop that runs n(vertcies) times
 - If index is unchecked and is less that the min index set min to currect index and store that index
 - return the min index 
 
 # void printFunction(vector <int>weight, vector <int>parents, int verticies)
 - prints out the distance from source to all nodes and its path
 - if no path exist
    
    
# How to run the code 

downlaod the heapSort.cpp file

 # using visualstudio:

To create a C++ project in Visual Studio 2019
From the main menu, choose File > New > Project to open the Create a New Project dialog box.

At the top of the dialog, set Language to C++, set Platform to Windows, and set Project type to Console.

From the filtered list of project types, choose Console App then choose Next. In the next page, enter a name for the project, and specify the project location if desired.

Choose the Create button to create the project.

Add a new source file
If Solution Explorer isn't displayed, on the View menu, click Solution Explorer.

Add a new source file to the project, as follows.

In Solution Explorer, right-click the Source Files folder, point to Add, and then click New Item.

In the Code node, click C++ File (.cpp), type a name for the file, and then click Add.

The .cpp file appears in the Source Files folder in Solution Explorer, and the file is opened in the Visual Studio editor.

copy the code from the heapSort.cpp file into the editor

Save the file.

dwonload the the input.txt file and cape it in the same folder as the .cpp file

On the Build menu, click Build Solution.

The Output window displays information about the compilation progress, for example, the location of the build log and a message that indicates the build status.

On the Debug menu, click Start without Debugging.

a command window is displays the result


 # running the heapSOrt.cpp file using g++ compiler 

download the Dijkstra's.cpp and input.txt file and store both in one folder
open the terminal 
chanage the directory to the folder you have the Dijkstra's.cpp file stored 
type the command g++ -o main.exe heapSort.cpp
then type the command ./main.exe
a terminal will popup with the result 

the input.txt file can be edited for new graph and take another node as the source


 
 
 
    
    
    

