#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;
#define Infinity 0x3f3f3f3f

typedef pair<int, int> ipair;


// this class represents a directed graph using adjacency list. 

class graph {

private :

    int V;
    list<ipair>* adj;

public:
    graph(int V) {
        this->V = V;    // NO. Of vertex
        adj = new list<ipair>[V];   // to store vertex and weight pair for every edges
    }
    
    // function to add an edge to graph
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // funtion to calculate the sortest path form the source 
    void shortestPath(int source) {
        priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
        vector<int> dist(V, Infinity);
        pq.push(make_pair(0, source));
        dist[source] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            list<pair<int, int>>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // printing the Shortest time 
        float totalCost =0;
        for (int i = 0; i < V; ++i) {
            cout << i << "\t\t" << dist[i] << endl;
            totalCost += dist[i];
        }
        
        // Calculating the average time 
        cout << "Average time to other cities :  "<< totalCost/(V-1) << endl;
    }
};


int main(){
    
    int V =6;
    graph g(V);
    

   // Adjecency matrix representation

    int matrix[V][V]={
                   { 0,10, 0, 0,15, 5},
                   {10, 0,10,30, 0, 0},
                   { 0,10, 0,12, 5, 0},
                   { 0,30,12, 0, 0,20},
                   {15, 0, 5, 0, 0, 0},
                   { 5, 0, 0,20, 0, 0}    };

    // adding edges into graph
    for (int j = 0; j < V; j++) {
        for (int i = 0; i < V; i++) {
            if (matrix[j][i] != 0) {
                g.addEdge(j, i, matrix[j][i]);
            }
        }
    }


    // printing shorest distances from each source vertex
    for (int i =0 ; i< V; i++){
        cout<< endl;
        cout << "\nCity       Shortest time from City " << i << endl;
	    g.shortestPath(i);
    }

}
