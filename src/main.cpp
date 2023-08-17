// Json Libraries:
#include "config.h"

// System Libraries:
#include <iostream>
#include <concepts>

template<class T>
requires std::integral<T>
bool IsIntegral()
{
	return true;
}

template<class T>
bool IsIntegral()
{
	return false;
}

int main()
{
	if (IsIntegral<int>())
	{
		std::cout << "stk-json version " << Json_VERSION_MAJOR << "." << Json_VERSION_MINOR << "." << Json_VERSION_PATCH << std::endl;
	}
	else
	{
		std::cout << "Not an integral type!\n";
	}
	return 0;
}