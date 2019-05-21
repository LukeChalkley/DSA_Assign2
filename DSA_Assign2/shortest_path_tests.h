#pragma once

#include <cxxtest/TestSuite.h>

#include "directed_graph.hpp"
#include "directed_graph_algorithms.cpp"

class shortest_path_tests : public CxxTest::TestSuite
{
	private:
		directed_graph<int> _dg;

	public:
		void setUp() override
		{
			_dg = directed_graph<int>{};
		}

		void testShortestPathAllConnected()
		{
			for (auto vertex = 0; vertex <= 9; ++vertex)
				_dg.add_vertex(vertex);

			_dg.add_edge(0, 1);
			_dg.add_edge(0, 3);
			_dg.add_edge(2, 5);
			_dg.add_edge(3, 2);
			_dg.add_edge(5, 7);
			_dg.add_edge(5, 8);
			_dg.add_edge(6, 7);
			_dg.add_edge(6, 4);
			_dg.add_edge(9, 7);
			_dg.add_edge(9, 8);

			auto distances = shortest_distances(_dg, 0);

			TS_ASSERT_EQUALS(distances.size(), _dg.num_vertices());

			TS_ASSERT_EQUALS(distances[1], 1);
			TS_ASSERT_EQUALS(distances[3], 1);
			TS_ASSERT_EQUALS(distances[2], 2);
			TS_ASSERT_EQUALS(distances[5], 3);
			TS_ASSERT_EQUALS(distances[8], 4);
			TS_ASSERT_EQUALS(distances[7], 4);
		}
};