#pragma once

#include <cxxtest/TestSuite.h>

#include "directed_graph.hpp"
#include "directed_graph_algorithms.cpp"

class dag_tests : public CxxTest::TestSuite
{
	private:
		directed_graph<int> _dg;

	public:
		void setUp() override
		{
			_dg = directed_graph<int>{};
		}

		void testValidDAG()
		{
			for (auto vertex = 1; vertex <= 7; ++vertex)
				_dg.add_vertex(vertex);

			_dg.add_edge(1, 2);
			_dg.add_edge(2, 3);
			_dg.add_edge(2, 4);
			_dg.add_edge(4, 5);
			_dg.add_edge(4, 6);
			_dg.add_edge(5, 6);
			_dg.add_edge(6, 3);

			TS_ASSERT(is_dag(_dg));
		}

		void testInvalidDAG()
		{
			for (auto vertex = 1; vertex <= 6; ++vertex)
				_dg.add_vertex(vertex);

			_dg.add_edge(1, 2);
			_dg.add_edge(1, 3);
			_dg.add_edge(2, 3);
			_dg.add_edge(4, 1);
			_dg.add_edge(4, 5);
			_dg.add_edge(5, 6);
			_dg.add_edge(6, 4);		//	This is our cycle.

			TS_ASSERT(!is_dag(_dg));
		}

		void testValidDAG2()
		{
			for (auto vertex = 1; vertex <= 6; ++vertex)
				_dg.add_vertex(vertex);

			_dg.add_edge(1, 2);
			_dg.add_edge(1, 3);
			_dg.add_edge(2, 3);
			_dg.add_edge(4, 1);
			_dg.add_edge(4, 5);
			_dg.add_edge(5, 6);
			//	Removed the edge causing our cycle. Should pass now. 

			TS_ASSERT(is_dag(_dg));
		}
};