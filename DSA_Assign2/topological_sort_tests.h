#pragma once

#include <cxxtest/TestSuite.h>
#include <string>

#include "directed_graph.hpp"
#include "directed_graph_algorithms.cpp"


class topological_sort_tests : public CxxTest::TestSuite
{
	private:
		

	public:
		void setUp() override
		{

		}

		/*
			CLRS 22.7
		*/
		void testGettingDressed()
		{
			directed_graph<std::string> _dg = directed_graph<std::string>{};

			_dg.add_vertex("undershorts");
			_dg.add_vertex("pants");
			_dg.add_vertex("belt");
			_dg.add_vertex("shirt");
			_dg.add_vertex("tie");
			_dg.add_vertex("jacket");
			_dg.add_vertex("socks");
			_dg.add_vertex("shoes");
			_dg.add_vertex("watch");

			_dg.add_edge("undershorts", "pants");
			_dg.add_edge("undershorts", "shoes");
			_dg.add_edge("pants", "belt");
			_dg.add_edge("belt", "jacket");
			_dg.add_edge("shirt", "tie");
			_dg.add_edge("shirt", "belt");
			_dg.add_edge("tie", "jacket");
			_dg.add_edge("pants", "shoes");
			_dg.add_edge("socks", "shoes");

			TS_ASSERT(is_dag(_dg));

			auto actual = topological_sort(_dg);

			std::vector<std::string> expected =
			{
				"socks", "undershorts", "pants", "shoes", "watch", "shirt", "belt", "tie", "jacket"
			};

			//	Test correct setup.
			TS_ASSERT_EQUALS(expected.size(), _dg.num_vertices());
			TS_ASSERT_EQUALS(_dg.num_edges(), 9);

			TS_ASSERT_EQUALS(actual.size(), _dg.num_vertices());

			for (int index = 0; index < actual.size(); ++index)
			{
				// TS_ASSERT_EQUALS(expected.at(index), actual.front());
				actual.pop_front();
			}
		}

		/*
			From video tutorial https://www.youtube.com/watch?v=ddTC4Zovtbc
		*/
		void testCharTopologicalOrder()
		{
			directed_graph<char> _dg = directed_graph<char>{};

			_dg.add_vertex('A');
			_dg.add_vertex('B');
			_dg.add_vertex('C');
			_dg.add_vertex('D');
			_dg.add_vertex('E');
			_dg.add_vertex('F');
			_dg.add_vertex('G');
			_dg.add_vertex('H');

			_dg.add_edge('A', 'C');
			_dg.add_edge('B', 'C');
			_dg.add_edge('B', 'D');
			_dg.add_edge('C', 'E');
			_dg.add_edge('D', 'F');
			_dg.add_edge('E', 'F');
			_dg.add_edge('E', 'H');
			_dg.add_edge('F', 'G');

			auto actual = topological_sort(_dg);
		}
};