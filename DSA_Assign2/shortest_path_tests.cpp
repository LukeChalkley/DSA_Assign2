/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

bool suite_shortest_path_tests_init = false;
#include "shortest_path_tests.h"

static shortest_path_tests suite_shortest_path_tests;

static CxxTest::List Tests_shortest_path_tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_shortest_path_tests( "shortest_path_tests.h", 8, "shortest_path_tests", suite_shortest_path_tests, Tests_shortest_path_tests );

static class TestDescription_suite_shortest_path_tests_testShortestPath1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_shortest_path_tests_testShortestPath1() : CxxTest::RealTestDescription( Tests_shortest_path_tests, suiteDescription_shortest_path_tests, 19, "testShortestPath1" ) {}
 void runTest() { suite_shortest_path_tests.testShortestPathAllConnected(); }
} testDescription_suite_shortest_path_tests_testShortestPath1;

