#include "pch.h"
#include "CppUnitTest.h"
#include "../src/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string expected = "Hello, World!\n";

			std::stringstream buffer;
			std::streambuf* sbuf = std::cout.rdbuf(); // Save cout's buffer
			std::cout.rdbuf(buffer.rdbuf()); // Redirect cout to the stringstream buffer

			// Call main() in your test
			int result = main();

			// When finished, redirect cout to the original buffer 
			std::cout.rdbuf(sbuf);
			std::cout << "std original buffer: \n";
			std::cout << buffer.get();

			// Test
			Assert::AreEqual(expected, buffer.str());
		}
	};
}
