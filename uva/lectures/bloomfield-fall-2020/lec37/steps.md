Lab 11 post-lab development steps
=================================

- determine how to represent each node
- write a determine_adjacent_nodes() function (can return `vector<string>`)
- TEST THAT FUNCTION!!!!1111oneoneONEONE
- determine a way to know if a node has been visited
     - keep track of it in a map<string,int>
     - keep track of the path in another map<string,string>
- perform a BFS on the graph
     - will have a `queue<string>`
     - add the start node to the BFS queue and set distance to 0
     - terminate once the goal (or final) state is found


Some pseudo-code to use maps:

```
#include <map>

// ...

map<string,int> dist;
map<string,string> path;
string s, u, v;

// ...

dist[s]
path[u]

if ( dist.find(key) != dist.end() ) {
}
```
