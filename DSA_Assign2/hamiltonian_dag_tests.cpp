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

bool suite_hamiltonian_graph_tests_init = false;
#include "hamiltonian_dag_tests.h"

static hamiltonian_graph_tests suite_hamiltonian_graph_tests;

static CxxTest::List Tests_hamiltonian_graph_tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_hamiltonian_graph_tests( "hamiltonian_dag_tests.h", 10, "hamiltonian_graph_tests", suite_hamiltonian_graph_tests, Tests_hamiltonian_graph_tests );

static class TestDescription_suite_hamiltonian_graph_tests_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_hamiltonian_graph_tests_test1() : CxxTest::RealTestDescription( Tests_hamiltonian_graph_tests, suiteDescription_hamiltonian_graph_tests, 26, "test1" ) {}
 void runTest() { suite_hamiltonian_graph_tests.test1(); }
} testDescription_suite_hamiltonian_graph_tests_test1;

static class TestDescription_suite_hamiltonian_graph_tests_test1_variation2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_hamiltonian_graph_tests_test1_variation2() : CxxTest::RealTestDescription( Tests_hamiltonian_graph_tests, suiteDescription_hamiltonian_graph_tests, 44, "test1_variation2" ) {}
 void runTest() { suite_hamiltonian_graph_tests.test1_variation2(); }
} testDescription_suite_hamiltonian_graph_tests_test1_variation2;

static class TestDescription_suite_hamiltonian_graph_tests_testValidDAG : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_hamiltonian_graph_tests_testValidDAG() : CxxTest::RealTestDescription( Tests_hamiltonian_graph_tests, suiteDescription_hamiltonian_graph_tests, 63, "testValidDAG" ) {}
 void runTest() { suite_hamiltonian_graph_tests.testValidDAG(); }
} testDescription_suite_hamiltonian_graph_tests_testValidDAG;

static class TestDescription_suite_hamiltonian_graph_tests_testValidDAG2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_hamiltonian_graph_tests_testValidDAG2() : CxxTest::RealTestDescription( Tests_hamiltonian_graph_tests, suiteDescription_hamiltonian_graph_tests, 86, "testValidDAG2" ) {}
 void runTest() { suite_hamiltonian_graph_tests.testValidDAG2(); }
} testDescription_suite_hamiltonian_graph_tests_testValidDAG2;

static class TestDescription_suite_hamiltonian_graph_tests_testNonHamiltonian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_hamiltonian_graph_tests_testNonHamiltonian() : CxxTest::RealTestDescription( Tests_hamiltonian_graph_tests, suiteDescription_hamiltonian_graph_tests, 103, "testNonHamiltonian" ) {}
 void runTest() { suite_hamiltonian_graph_tests.testNonHamiltonian(); }
} testDescription_suite_hamiltonian_graph_tests_testNonHamiltonian;

