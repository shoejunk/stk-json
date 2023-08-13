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
		std::cout << "Hello, World!\n";
	}
	else
	{
		std::cout << "Not an integral type!\n";
	}
	return 0;
}