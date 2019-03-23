#pragma once

#include <string>
#include <vector>
#include <iostream>


struct BusesForStopResponse {
	std::vector<std::string> buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	std::string bus;
	std::vector<std::pair<std::string, std::vector<std::string>>> stops;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	std::vector<std::pair<std::string, std::vector<std::string>>> buses;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);
