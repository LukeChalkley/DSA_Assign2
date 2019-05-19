#define CXXTEST_HAVE_EH
#define CXXTES_ABORT_TEST_ON_FAIL

#include <cxxtest/ParenPrinter.h>

int main()
{
	std::cout << "Starting test runner." << std::endl;

	int status = CxxTest::ParenPrinter().run();

	std::cout << "Finished test runner." << std::endl;

	std::cin.get();

	return status;
}

<CxxTest world>