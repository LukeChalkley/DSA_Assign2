/*
 * Notice that the list of included headers has
 * expanded a little. As before, you are not allowed
 * to add to this.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
#include <cstddef>
#include <string>
#include <utility>
#include <algorithm>
#include <limits>
#include <optional>
#include <exception>
#include <stdexcept>
#include <iostream>

#include "directed_graph.hpp"

enum visitation_colour { white, grey, black };

/*
 * Computes whether the input is a Directed Acyclic Graph (DAG).
 * A digraph is a DAG if there is no vertex that has a cycle.
 * A cycle is a non-empty set of [out-]edges that starts at one 
 * vertex, and returns to it.
 */
template <typename vertex>
bool is_dag(const directed_graph<vertex> &graph)
{
	for (auto vertIter = graph.begin(); vertIter != graph.end(); vertIter++)
	{
		if (!is_dag(graph, *vertIter))
			return false;
	}

	return true;
}

/*
	Performs a depth-first traversal algorithm starting from
	the specified vertex to determine if our graph is a DAG.

	Overload with additional vertex parameter for start point.
*/
template <typename vertex>
bool is_dag(const directed_graph<vertex> &graph, const vertex &start)
{
	std::stack<vertex> visitation_stack = std::stack<vertex>{};
	std::map<vertex, visitation_colour> visitation_status;

	for (auto vertexIter = graph.begin(); vertexIter != graph.end(); ++vertexIter)
		visitation_status.insert({ *vertexIter, visitation_colour::white });
	
	visitation_stack.push(start);

	while (!visitation_stack.empty())
	{
		auto current = visitation_stack.top();		

		if (visitation_status[current] == visitation_colour::white)
			visitation_status[current] = visitation_colour::grey;

		vertex min_vertex;
		
		if (has_min_adjacent(graph, current, &min_vertex, visitation_status))
		{
			if (visitation_status[min_vertex] == visitation_colour::grey)
			{
				//	Identified a cycle. End here.
				return false;
			}

			visitation_stack.push(min_vertex);
		}
		else
		{
			visitation_status[current] = visitation_colour::black;
			visitation_stack.pop();
		}
	}

	return true;
}

/*
	Determines if there is a connected edge that leads to an
	unvisited vertex, or a vertex currently being visited.

	Returns true/false if it contains this vertex. If true,
	sets a vertex parameter to the vertex which can be used
	in the calling function.
*/
template <typename vertex>
bool has_min_adjacent(const directed_graph<vertex> &graph, const vertex &source, 
					  vertex *out_vertex, 
					  std::map<vertex, 
					  visitation_colour>& visitation_states)
{
	for (auto neighIter = graph.nbegin(source); neighIter != graph.nend(source); ++neighIter)
	{
		//	Black are visited, we only want white or gray.
		if (visitation_states.at(*neighIter) != visitation_colour::black)
		{
			*out_vertex = *neighIter;
			return true;
		}
	}	

	return false;
}

/*
 * Computes a topological ordering of the vertices.
 * For every vertex u in the order, and any of its
 * neighbours v, v appears later in the order than u.
 */
template <typename vertex>
std::list<vertex> topological_sort(const directed_graph<vertex> &graph)
{
	std::list<vertex> sorted = std::list<vertex>{};
	std::map<vertex, visitation_colour> visitation_status = std::map<vertex, visitation_colour>{};
	std::stack<vertex> discovery_queue = std::stack<vertex>{};

	for (auto vertexIter = graph.begin(); vertexIter != graph.end(); ++vertexIter)	
		visitation_status.insert({ *vertexIter, visitation_colour::white });

	for (auto vertexIter = graph.begin(); vertexIter != graph.end(); ++vertexIter)
	{
		if (visitation_status.at(*vertexIter) == visitation_colour::white)
		{
			visitation_status.at(*vertexIter) = visitation_colour::black;
			discovery_queue.push(*vertexIter);
			topological_sort(graph, sorted, visitation_status, discovery_queue);
		}
	}

	return sorted;
}


template <typename vertex>
void topological_sort(const directed_graph<vertex> &graph,
					  std::list<vertex> &sorted, 
					  std::map<vertex, visitation_colour> &visitation_status,
					  std::stack<vertex> &discovery_queue)
{
	//	Base case for recursion.
	if (discovery_queue.empty())
		return;		//Should this just be an if statement where we execute if not empty?
					//	Is return a bad thing for spaghetti code?

	vertex current = discovery_queue.top();
	discovery_queue.pop();

	for (auto nIter = graph.nbegin(current); nIter != graph.nend(current); ++nIter)
	{
		if (visitation_status.at(*nIter) == visitation_colour::white)
		{
			visitation_status.at(*nIter) = visitation_colour::black;
			discovery_queue.push(*nIter);
			topological_sort(graph, sorted, visitation_status, discovery_queue);
		}
	}

	sorted.push_front(current);
}



/*
 * Given a DAG, computes whether there is a Hamiltonian path.
 * a Hamiltonian path is a path that visits every vertex
 * exactly once.
 */
template <typename vertex>
bool is_hamiltonian_dag(const directed_graph<vertex> &graph)
{
	std::list<vertex> top_sort = topological_sort(graph);

	typename std::list<vertex>::iterator top_iter = top_sort.begin();

	while (top_iter != --top_sort.end())
	{
		vertex u = *top_iter;
		vertex v = *(++top_iter);

		if (!graph.adjacent(u, v))
			return false;
	}

	return true;
}

/*
 * Computes the weakly connected components of the graph.
 * A [weak] component is the smallest subset of the vertices
 * such that the in and out neighbourhood of each vertex in
 * the set is also contained in the set.
 */
template <typename vertex>
std::vector<std::vector<vertex>> components(const directed_graph<vertex> & d)
{
	return std::vector<std::vector<vertex>>();
}

/*
 * Computes the strongly connected components of the graph.
 * A strongly connected component is a subset of the vertices
 * such that for every pair u, v of vertices in the subset,
 * v is reachable from u and u is reachable from v.
 */

template <typename vertex>
std::vector<std::vector<vertex>> strongly_connected_components(const directed_graph<vertex> & d)
{
	std::vector<std::vector<vertex>> strong_connected_comp = std::vector<std::vector<vertex>>{};

	return strong_connected_comp;
}

template <typename vertex>
void strongly_connected_components(const directed_graph<vertex> &graph, vertex &source)
{
	return std::vector<std::vector<vertex>>();
}

/*
 * Computes the shortest distance from u to every other vertex
 * in the graph d. The shortest distance is the smallest number
 * of edges in any path from u to the other vertex.
 * If there is no path from u to a vertex, set the distance to
 * be the number of vertices in d plus 1.

	Lets do this one iteratively.
 */
template <typename vertex>
std::unordered_map<vertex, std::size_t> shortest_distances(const directed_graph<vertex> &graph, const vertex &source)
{	
	std::unordered_map<vertex, std::size_t> shortest_distance_from_u = std::unordered_map<vertex, size_t>{};
	std::queue<vertex> visitation_queue = std::queue<vertex>{};
	std::map<vertex, visitation_colour> visitation_status = std::map<vertex, visitation_colour>{};

	for (typename directed_graph<vertex>::const_vertex_iterator vertexIter = graph.begin(); vertexIter != graph.end(); ++vertexIter)
	{
		visitation_status.insert({ *vertexIter, visitation_colour::white });	//	Set all vertices to unvisited.
		
		//	Set all distances to num_vertices + 1. Any unvisited vertices will keep this value.
		shortest_distance_from_u.insert({ *vertexIter, graph.num_vertices() + 1 });
	}

	visitation_queue.push(source);
	
	while (!visitation_queue.empty())
	{
		auto current_vertex = visitation_queue.front();
		visitation_queue.pop();
		
		if (visitation_status.at(current_vertex) == visitation_colour::white)
			shortest_distance_from_u.at(current_vertex) = 0;	//	New vertex: reset distance to 0.

		for (auto neighIter = graph.nbegin(current_vertex); neighIter != graph.nend(current_vertex); ++neighIter)
		{
			//	If there is a new vertex connected to our current
			if (visitation_status.at(*neighIter) == visitation_colour::white)
			{
				visitation_status.at(*neighIter) = visitation_colour::grey;	//	Set to grey so we don't confuse it with a vertex being explored/already finished.
				shortest_distance_from_u.at(*neighIter) = shortest_distance_from_u.at(current_vertex) + 1;	//	Add 1 to the distance of the neighbour vertex.
				visitation_queue.push(*neighIter);
			}
		}
	}

	return shortest_distance_from_u;
}
