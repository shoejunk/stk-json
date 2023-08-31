// Json Libraries:
#include "config.h"

// STK Libraries:
#include <log/logger.h>

// 3rd Party Libraries:
#include <nlohmann/json.hpp>

// System Libraries:
#include <iostream>

int main()
{
	nlohmann::json json =
	{ 
		{"pi", 3.141},
		{"happy", true},
		{"name", "Niels"},
		{"nothing", nullptr},
		{"answer", {{"everything", 42}}},
		{"list", {1, 0, 2}},
		{"object", {{"currency", "USD"}, {"value", 42.99}}}
	};
	std::cout << "declared JSON object: " << std::setw(2) << json << std::endl;
	NStk::CLogger oLogger;
	oLogger.Log("borp stormp mcgormp");
	return 0;
}
