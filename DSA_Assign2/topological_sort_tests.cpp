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

bool suite_topological_sort_tests_init = false;
#include "topological_sort_tests.h"

static topological_sort_tests suite_topological_sort_tests;

static CxxTest::List Tests_topological_sort_tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_topological_sort_tests( "topological_sort_tests.h", 10, "topological_sort_tests", suite_topological_sort_tests, Tests_topological_sort_tests );

static class TestDescription_suite_topological_sort_tests_testGettingDressed : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_topological_sort_tests_testGettingDressed() : CxxTest::RealTestDescription( Tests_topological_sort_tests, suiteDescription_topological_sort_tests, 24, "testGettingDressed" ) {}
 void runTest() { suite_topological_sort_tests.testGettingDressed(); }
} testDescription_suite_topological_sort_tests_testGettingDressed;

static class TestDescription_suite_topological_sort_tests_testCharTopologicalOrder : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_topological_sort_tests_testCharTopologicalOrder() : CxxTest::RealTestDescription( Tests_topological_sort_tests, suiteDescription_topological_sort_tests, 73, "testCharTopologicalOrder" ) {}
 void runTest() { suite_topological_sort_tests.testCharTopologicalOrder(); }
} testDescription_suite_topological_sort_tests_testCharTopologicalOrder;

