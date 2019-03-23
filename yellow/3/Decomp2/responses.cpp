#include "responses.h"

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
	if (r.buses.size() == 0) {
		os << "No stop";
	}
	else {
		for (const auto& b : r.buses) {
			os << b << " ";
		}
	}
	return os;
}

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
	if (r.stops.size() == 0) {
		os << "No bus";
	}
	else {
		for (int i = 0; i < r.stops.size(); i++) {
			os << "Stop " << r.stops[i].first << ": ";
			if (r.stops[i].second.size() == 1) {
				os << "no interchange";
			}
			else {
				for (const auto& b : r.stops[i].second) {
					if (b != r.bus) {
						os << b << " ";
					}
				}
			}
			if (i != r.stops.size() - 1) {
				os << std::endl;
			}
		}
	}
	return os;
}

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
	if (r.buses.size() == 0) {
		os << "No buses";
	}
	else {
		for (int i = 0; i < r.buses.size(); i++) {
			os << "Bus " << r.buses[i].first << ": ";
			for (const auto& s : r.buses[i].second) {
				os << s << " ";
			}
			if (i != r.buses.size() - 1) {
				os << std::endl;
			}
		}
	}
	return os;
}
