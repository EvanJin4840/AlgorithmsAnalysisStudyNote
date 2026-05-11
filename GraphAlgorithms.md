# Graph Algorithms: Core Concepts & Breadth-First Search (BFS)

## 1. Graph Fundamentals & Paths
* **Graph (G = (V, E)):** A structure made of **Vertices** (V, nodes) connected by **Edges** (E, lines).
* **Path:** A sequence of vertices connected by edges. 
* **Simple Path:** A path where **no vertex appears more than once**. If a path loops back to a previously visited vertex, it is no longer "simple."

## 2. Graph Density & Adjacency Matrix
The efficiency of storing a graph depends heavily on its density.
* **Dense Graph:** A graph with many edges, close to the maximum possible number (O(V^2)). Almost all vertices are connected to each other.
* **Sparse Graph:** A graph with relatively few edges (closer to O(V)). 
* **Adjacency Matrix:** A 2D grid used to store graph connections, requiring O(V^2) space. 
    * **Storage Optimization (The 6-bit example):** For an undirected graph with 4 vertices, you only need 6 bits to represent it. You can **ignore the diagonal** because there are no self-loops (a node connecting to itself). You can also **ignore the bottom-left half** because an undirected graph is **symmetric** (the connection from A to B is the same as B to A). You only need to store the top-right triangle.

## 3. Breadth-First Search (BFS) Concepts
* **What is BFS?** An algorithm that explores a graph level-by-level, radiating outward from a starting source node (like ripples in water). It checks all immediate neighbors first before moving deeper.
* **Breadth-First Tree:** As BFS explores, it records the edges that lead to newly discovered vertices. This creates a branching, cycle-free structure called a "tree" that maps out the shortest paths from the start node.

## 4. BFS Vertex States (The Color System)
To keep track of progress and avoid infinite loops, BFS labels vertices with three colors:
1. **White (Undiscovered):** The vertex has not been visited yet. All vertices start as white.
2. **Gray (Discovered / Waiting):** The vertex has been reached, but the algorithm hasn't finished checking all of its immediate neighbors. It is usually placed in a Queue to wait its turn.
3. **Black (Finished):** The vertex and all of its adjacent neighbors have been completely explored. 

## 5. BFS Algorithm Logic (Pseudocode Breakdown)
* **Key Variables:**
    * `s`: Source vertex (where the search begins).
    * `d`: Distance from the source.
    * `π`: Parent node (the node that discovered it).
    * `Q`: A Queue used as a waiting line for Gray vertices.
* **The Process:**
    1. **Initialize:** Set all vertices to White, distance to infinity (∞), and parent to NIL.
    2. **Start:** Color the source `s` Gray, set its distance to 0, and push it into the Queue `Q`.
    3. **Explore:** While the Queue is not empty, pull out the first vertex (`u`).
    4. **Check Neighbors:** Look at every neighbor (`v`) of `u`. If `v` is White:
        * Color it Gray ("I found a new node!").
        * Update its distance: `d[v] = d[u] + 1`.
        * Set its parent: `π[v] = u`.
        * Push `v` into the Queue `Q` so its own neighbors can be checked later.
    5. **Finish:** Once all neighbors of `u` are checked, color `u` Black ("I'm done exploring this node's surroundings").