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

bool suite_connected_components_test_init = false;
#include "connected_components_test.h"

static connected_components_test suite_connected_components_test;

static CxxTest::List Tests_connected_components_test = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_connected_components_test( "connected_components_test.h", 10, "connected_components_test", suite_connected_components_test, Tests_connected_components_test );

static class TestDescription_suite_connected_components_test_testVerticesNumbering : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_connected_components_test_testVerticesNumbering() : CxxTest::RealTestDescription( Tests_connected_components_test, suiteDescription_connected_components_test, 21, "testVerticesNumbering" ) {}
 void runTest() { suite_connected_components_test.testVerticesNumbering(); }
} testDescription_suite_connected_components_test_testVerticesNumbering;

static class TestDescription_suite_connected_components_test_testStrongConnectedComponents : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_connected_components_test_testStrongConnectedComponents() : CxxTest::RealTestDescription( Tests_connected_components_test, suiteDescription_connected_components_test, 41, "testStrongConnectedComponents" ) {}
 void runTest() { suite_connected_components_test.testStrongConnectedComponents(); }
} testDescription_suite_connected_components_test_testStrongConnectedComponents;

