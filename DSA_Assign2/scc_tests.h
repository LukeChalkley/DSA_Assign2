#pragma once

#include <cxxtest/TestSuite.h>
#include <string>

#include "directed_graph.hpp"
#include "directed_graph_algorithms.cpp"


class scc_tests : public CxxTest::TestSuite
{
	private:
		directed_graph<int> _dg;

	public:
		void setUp() override
		{
			_dg = directed_graph<int>{};
		}

		/*
			https://www.geeksforgeeks.org/strongly-connected-components/
		*/
		void testSCC1()
		{
			for (int i = 0; i < 5; ++i)
				_dg.add_vertex(i);

			_dg.add_edge(1, 0);
			_dg.add_edge(0, 2);
			_dg.add_edge(2, 1);
			_dg.add_edge(0, 3);
			_dg.add_edge(3, 4);

			TS_ASSERT_EQUALS(_dg.num_edges(), 5);
			TS_ASSERT_EQUALS(_dg.num_vertices(), 5);
		}

		/*
			https://www.geeksforgeeks.org/strongly-connected-components/
		*/
		void testTranspose()
		{
			for (int i = 0; i < 5; ++i)
				_dg.add_vertex(i);

			_dg.add_edge(1, 0);
			_dg.add_edge(0, 2);
			_dg.add_edge(2, 1);
			_dg.add_edge(0, 3);
			_dg.add_edge(3, 4);

			TS_ASSERT_EQUALS(_dg.num_edges(), 5);
			TS_ASSERT_EQUALS(_dg.num_vertices(), 5);

			directed_graph<int> trans = _dg.get_transpose();

			TS_ASSERT_EQUALS(trans.num_edges(), _dg.num_edges());
			TS_ASSERT_EQUALS(trans.num_vertices(), _dg.num_vertices());

			for (auto vertIter = _dg.begin(); vertIter != _dg.end(); ++vertIter)
			{
				TS_ASSERT(trans.contains(*vertIter));

				for (auto nIter = _dg.nbegin(*vertIter); nIter != _dg.nend(*vertIter); ++nIter)
				{
					TS_ASSERT(trans.adjacent(*nIter, *vertIter));
				}
			}
		}
};