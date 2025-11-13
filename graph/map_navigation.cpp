#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
using namespace std;

// Class representing a node/vertex in the graph
class Place{
  public:
    string name;  // Name of the place (e.g., "A", "B", "C", "D")
    unordered_map<Place*, int> neighbours;  // Adjacency list: stores neighbors and edge weights
    
    // Constructor: initializes place with a name
    Place(string name) : name(name) {}
    
    // Getter method: returns the name of the place
    string getName() const{
      return name;
    }
    
    // Method to add a neighbor with a specific distance (edge weight)
    void addNeighbour(Place* neighbour, int distance){
      neighbours[neighbour] = distance;
    }
    
    // Getter method: returns all neighbors and their distances
    const unordered_map<Place*, int>& getNeighbours() const{
      return neighbours;
    }
};

// Dijkstra's Algorithm: finds shortest path from start to destination
// Parameters:
//   - start: pointer to starting node
//   - destination: pointer to destination node
//   - parent: reference map to track path (for reconstruction later)
// Returns: map of all places and their shortest distances from start
unordered_map<Place*, int> findShortestPath(Place* start, Place* destination, unordered_map<Place*, Place*>& parent){
  
  // Map to store the shortest distance from start to each place
  unordered_map<Place*, int> distances;
  
  // Set to track which places have been fully processed (visited)
  set<Place*> visited;
  
  // Initialize distances for all neighbors of start to infinity (INT_MAX)
  // This means we haven't found a path to them yet
  for(auto neighbor : start->neighbours){
    distances[neighbor.first] = INT_MAX;
  }
  
  // Distance from start to itself is 0
  distances[start] = 0;
  
  // Main loop: continue until destination is visited
  while(visited.find(destination) == visited.end()){
    
    // Variables to find the unvisited place with minimum distance
    Place* closestPlace = nullptr;
    int closestDistance = INT_MAX;
    
    // Loop through all known distances to find closest unvisited place
    for(auto entry : distances){
      // Check if this place is unvisited AND has smaller distance
      if(visited.find(entry.first) == visited.end() && entry.second < closestDistance){
        closestPlace = entry.first;
        closestDistance = entry.second;
      }
    }
    
    // If no unvisited place found, no path exists to destination
    if(closestPlace == nullptr){
      break;
    }
    
    // Mark the closest place as visited (fully processed)
    visited.insert(closestPlace);
    
    // Relax edges: check all neighbors of the current closest place
    for(auto neighbor : closestPlace->neighbours){
      
      // Calculate new distance: distance to current place + edge weight to neighbor
      int newDistance = distances[closestPlace] + neighbor.second;
      
      // If we found a shorter path to this neighbor, update it
      // Conditions: neighbor not in distances yet OR new distance is shorter
      if(distances.count(neighbor.first) == 0 || distances[neighbor.first] > newDistance){
        distances[neighbor.first] = newDistance;  // Update shortest distance
        parent[neighbor.first] = closestPlace;    // Track parent for path reconstruction
      }
    }
  }
  
  // Return the map of shortest distances
  return distances;
}

// Function to reconstruct the actual path from start to destination
// Uses the parent map to backtrack from destination to start
// Parameters:
//   - start: starting place
//   - destination: ending place
//   - parent: map showing which place leads to which (from Dijkstra's)
// Returns: vector containing the path in order from start to destination
vector<Place*> reconstructPath(Place* start, Place* destination, const unordered_map<Place*, Place*>& parent){
  
  vector<Place*> path;  // Vector to store the path
  Place* current = destination;  // Start from destination and work backwards
  
  // Backtrack from destination to start using parent pointers
  while(current != start){
    path.insert(path.begin(), current);  // Insert at beginning to maintain correct order
    current = parent.at(current);        // Move to parent node
  }
  
  // Add the starting point at the beginning
  path.insert(path.begin(), start);
  
  return path;
}

// Main function: demonstrates Dijkstra's algorithm
int main(){
  
  // Create 4 places (nodes in the graph)
  Place startingPoint("A");
  Place midPointB("B");
  Place midPointC("C");
  Place endPoint("D");
  
  // Build the graph by adding edges (connections between places)
  // Graph structure:
  //   A --10--> B --15--> D
  //    \                 /
  //     5----> C --20---
  startingPoint.addNeighbour(&midPointB, 10);  // A to B with distance 10
  startingPoint.addNeighbour(&midPointC, 5);   // A to C with distance 5
  midPointB.addNeighbour(&endPoint, 15);       // B to D with distance 15
  midPointC.addNeighbour(&endPoint, 20);       // C to D with distance 20
  
  // Map to store parent relationships (for path reconstruction)
  unordered_map<Place*, Place*> travelHistory;
  
  // Run Dijkstra's algorithm to find shortest distances
  unordered_map<Place*, int> travelDistances = findShortestPath(&startingPoint, &endPoint, travelHistory);
  
  // Check if a path to destination was found
  if(travelDistances.count(&endPoint) > 0){
    
    // Print the shortest distance
    cout << "Shortest distance to destination: " << travelDistances[&endPoint] << endl;
    
    // Reconstruct the actual path
    vector<Place*> travelRoute = reconstructPath(&startingPoint, &endPoint, travelHistory);
    
    // Print the path
    cout << "Shortest Path:" << endl;
    for(Place* location : travelRoute){
      cout << location->getName() << " -> ";
    }
    cout << "Destination" << endl;
  }
  else{
    // No path exists from start to destination
    cout << "No path found to destination." << endl;
  }
  
  return 0;
}