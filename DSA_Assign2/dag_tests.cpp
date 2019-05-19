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

bool suite_dag_tests_init = false;
#include "dag_tests.h"

static dag_tests suite_dag_tests;

static CxxTest::List Tests_dag_tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_dag_tests( "dag_tests.h", 8, "dag_tests", suite_dag_tests, Tests_dag_tests );

static class TestDescription_suite_dag_tests_testValidDAG : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_dag_tests_testValidDAG() : CxxTest::RealTestDescription( Tests_dag_tests, suiteDescription_dag_tests, 19, "testValidDAG" ) {}
 void runTest() { suite_dag_tests.testValidDAG(); }
} testDescription_suite_dag_tests_testValidDAG;

static class TestDescription_suite_dag_tests_testInvalidDAG : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_dag_tests_testInvalidDAG() : CxxTest::RealTestDescription( Tests_dag_tests, suiteDescription_dag_tests, 35, "testInvalidDAG" ) {}
 void runTest() { suite_dag_tests.testInvalidDAG(); }
} testDescription_suite_dag_tests_testInvalidDAG;

static class TestDescription_suite_dag_tests_testValidDAG2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_dag_tests_testValidDAG2() : CxxTest::RealTestDescription( Tests_dag_tests, suiteDescription_dag_tests, 51, "testValidDAG2" ) {}
 void runTest() { suite_dag_tests.testValidDAG2(); }
} testDescription_suite_dag_tests_testValidDAG2;

