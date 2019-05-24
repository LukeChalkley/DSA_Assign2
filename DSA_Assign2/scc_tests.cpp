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

bool suite_scc_tests_init = false;
#include "scc_tests.h"

static scc_tests suite_scc_tests;

static CxxTest::List Tests_scc_tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_scc_tests( "scc_tests.h", 10, "scc_tests", suite_scc_tests, Tests_scc_tests );

static class TestDescription_suite_scc_tests_testSCC1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_scc_tests_testSCC1() : CxxTest::RealTestDescription( Tests_scc_tests, suiteDescription_scc_tests, 24, "testSCC1" ) {}
 void runTest() { suite_scc_tests.testSCC1(); }
} testDescription_suite_scc_tests_testSCC1;

static class TestDescription_suite_scc_tests_testTranspose : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_scc_tests_testTranspose() : CxxTest::RealTestDescription( Tests_scc_tests, suiteDescription_scc_tests, 42, "testTranspose" ) {}
 void runTest() { suite_scc_tests.testTranspose(); }
} testDescription_suite_scc_tests_testTranspose;

