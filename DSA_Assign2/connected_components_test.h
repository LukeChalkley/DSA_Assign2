#pragma once

#include <cxxtest/TestSuite.h>
#include <string>

#include "directed_graph.hpp"
#include "directed_graph_algorithms.cpp"


class connected_components_test : public CxxTest::TestSuite
{
	private:
		directed_graph<char> _dg;

	public:
		void setUp() override
		{
			_dg = directed_graph<char>{};
		}

		void testVerticesNumbering()
		{
			for (char vert = 'A'; vert <= 'J'; ++vert)
				_dg.add_vertex(vert);

			_dg.add_edge('A', 'C');
			_dg.add_edge('B', 'A');
			_dg.add_edge('C', 'F');
			_dg.add_edge('D', 'C');
			_dg.add_edge('D', 'A');
			_dg.add_edge('E', 'C');
			_dg.add_edge('E', 'D');
			_dg.add_edge('F', 'B');
			_dg.add_edge('F', 'G');
			_dg.add_edge('H', 'G');
			_dg.add_edge('H', 'I');
			_dg.add_edge('I', 'J');
			_dg.add_edge('J', 'H');
		}

		void testStrongConnectedComponents()
		{
			for (char vert = 'A'; vert <= 'J'; ++vert)
				_dg.add_vertex(vert);

			_dg.add_edge('A', 'C');
			_dg.add_edge('B', 'A');
			_dg.add_edge('C', 'F');
			_dg.add_edge('D', 'C');
			_dg.add_edge('D', 'A');
			_dg.add_edge('E', 'C');
			_dg.add_edge('E', 'D');
			_dg.add_edge('F', 'B');
			_dg.add_edge('F', 'G');
			_dg.add_edge('H', 'G');
			_dg.add_edge('H', 'I');
			_dg.add_edge('I', 'J');
			_dg.add_edge('J', 'H');

			TS_ASSERT_EQUALS(_dg.num_edges(), 13);

			std::vector<std::vector<char>> expected = 
			{
				std::vector<char> {'G'},
				std::vector<char> {'H', 'I', 'J'},
				std::vector<char> {'B', 'A', 'C', 'F'},
				std::vector<char> {'D', 'E'},
			};

			TS_ASSERT_EQUALS(expected.size(), 4);
		}
};