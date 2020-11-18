#include <iostream>
#include <string>
#include <limits.h>
#include <queue>

using namespace std;

//assumes 0 is start node always
void bfs (int** g, int* dist, int n) {

    queue<int> q;
    dist[0] = 0;
    q.push (0);

    while ( q.size() > 0 ) {
        int curNode = q.front();
        q.pop();

        //look at all neighbors
        for ( int i = 0; i < n; i++ )
            if ( g[curNode][i] == 1 && dist[i] == INT_MAX ) {
                dist[i] = dist[curNode] + 1;
                q.push (i);
            }
    }
}


int main() {

    //read in n (number of nodes) and e (number of edges)
    int n, e;
    cin >> n >> e;

    //initialize the matrix of the graph to all 0s
    int** g = new int* [n];
    for ( int i = 0; i < n; i++ ) {
        g[i] = new int[n];
        for ( int j = 0; j < n; j++ )
            g[i][j] = 0;
    }

    //setup edges by changing some values in matrix to 1
    for ( int i = 0; i < e; i++ ) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    //take in the number of "bad" nodes that cannot be traveled
    int numBad;
    cin >> numBad;

    //remove any edges connected to bad nodes
    for ( int i = 0; i < numBad; i++ ) {
        int bad;
        cin >> bad;
        for ( int j = 0; j < n; j++ )
            g[bad][j] = g[j][bad] = 0;
    }

    //setup array of distances to all be infinity
    int* dist = new int[n];
    for ( int i = 0; i < n; i++ )
        dist[i] = INT_MAX;

    //run bfs on the graph
    bfs (g, dist, n);

    //print out the distances
    for ( int i = 0; i < n; i++ )
        cout << "Dist to node " << i << ": " << dist[i] << endl;

    // deallocation
    for ( int i = 0; i < n; i++ )
        delete [] g[i];
    delete [] g;
    delete [] dist;

    // all done!
    return 0;
}
