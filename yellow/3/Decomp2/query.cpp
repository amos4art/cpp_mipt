#include "query.h"

std::istream& operator >> (std::istream& is, Query& q) {
	std::string request;
	is >> request;
	if (request == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;
		//clean stops vector
		q.stops.clear();
		q.stops.shrink_to_fit();
		int stop_count;
		is >> stop_count;
		for (int i = 0; i < stop_count; i++) {
			std::string stop;
			is >> stop;
			q.stops.push_back(stop);
		}
	}
	else if (request == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (request == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (request == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}

	return is;
}
