#pragma once

#include <cxxtest/TestSuite.h>
#include <string>

#include "directed_graph.hpp"
#include "directed_graph_algorithms.cpp"


class hamiltonian_graph_tests : public CxxTest::TestSuite
{
	private:


	public:
		void setUp() override
		{
			TS_TRACE("Beginning Hamiltonian DAG Tests");
		}

		/*
			https://www.youtube.com/watch?v=6QFSkhcHLiA

			Note: Modified so is DAG.
		*/
		void test1()
		{
			directed_graph<char> dg = directed_graph<char>{};

			for (char vert = 'A'; vert <= 'H'; ++vert)			
				dg.add_vertex(vert);

			dg.add_edge('A', 'I');
			dg.add_edge('A', 'B');
			dg.add_edge('I', 'H');
			dg.add_edge('H', 'B');
			dg.add_edge('B', 'C');
			dg.add_edge('C', 'D');
			dg.add_edge('D', 'E');
			dg.add_edge('E', 'F');
			dg.add_edge('F', 'G');			
		}

		void test1_variation2()
		{
			directed_graph<char> dg = directed_graph<char>{};

			for (char vert = 'A'; vert <= 'H'; ++vert)
				dg.add_vertex(vert);

			dg.add_edge('A', 'I');
			dg.add_edge('A', 'B');
			dg.add_edge('E', 'I');
			dg.add_edge('I', 'H');
			dg.add_edge('H', 'B');
			dg.add_edge('B', 'C');
			dg.add_edge('C', 'D');
			dg.add_edge('D', 'E');
			dg.add_edge('E', 'F');
			dg.add_edge('F', 'G');
		}

		void testValidDAG()
		{
			directed_graph<char> dg = directed_graph<char>{};

			for (char vert = 'A'; vert <= 'I'; ++vert)
				dg.add_vertex(vert);

			dg.add_edge('A', 'B');
			dg.add_edge('B', 'C');
			dg.add_edge('C', 'D');
			dg.add_edge('D', 'F');
			dg.add_edge('D', 'E');
			dg.add_edge('F', 'E');
			dg.add_edge('E', 'G');
			dg.add_edge('G', 'H');
			dg.add_edge('H', 'I');
			
			TS_ASSERT_EQUALS(dg.num_edges(), 9);
			TS_ASSERT(is_dag(dg));

			TS_ASSERT(is_hamiltonian_dag(dg));
		}

		void testValidDAG2()
		{
			directed_graph<int> dg = directed_graph<int>{};

			dg.add_vertex(0);
			dg.add_vertex(1);
			dg.add_vertex(2);
			dg.add_vertex(3);

			dg.add_edge(0, 1);
			dg.add_edge(1, 2);
			dg.add_edge(2, 3);
			dg.add_edge(3, 1);

			TS_ASSERT(is_hamiltonian_dag(dg));
		}

		void testNonHamiltonian()
		{
			directed_graph<char> dg = directed_graph<char>{};

			for (char vert = 'A'; vert <= 'G'; ++vert)
				dg.add_vertex(vert);

			dg.add_edge('A', 'B');
			dg.add_edge('A', 'F');
			dg.add_edge('A', 'G');
			dg.add_edge('B', 'E');
			dg.add_edge('B', 'C');
			dg.add_edge('C', 'G');
			dg.add_edge('D', 'C');
			dg.add_edge('E', 'D');
			dg.add_edge('F', 'D');

			TS_ASSERT(is_dag(dg));
			TS_ASSERT(!is_hamiltonian_dag(dg));
		}
};