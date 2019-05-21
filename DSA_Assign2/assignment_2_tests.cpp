/* Generated file, do not edit */

#define CXXTEST_HAVE_EH
#define CXXTES_ABORT_TEST_ON_FAIL

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

#include <cxxtest/ParenPrinter.h>

int main()
{	
	int status = CxxTest::ParenPrinter().run();
	
	std::cin.get();

	return status;
}

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
