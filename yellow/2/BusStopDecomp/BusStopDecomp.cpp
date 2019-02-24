#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	string request;
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
			string stop;
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

struct BusesForStopResponse {
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
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

struct StopsForBusResponse {
	string bus;
	vector<pair<string, vector<string>>> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stops.size() == 0) {
		os << "No bus";
	}
	else {
		for(int i = 0; i < r.stops.size(); i++) {
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
				os << endl;
			}			
		}
	}	
	return os;
}


struct AllBusesResponse {
	vector<pair<string, vector<string>>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
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
				os << endl;
			}
		}
	}
	return os;
}


class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		m_buses_to_stops[bus] = stops;
		for (const auto& s : stops) {
			m_stops_to_buses[s].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse res;
		if (m_stops_to_buses.count(stop) != 0) {
			res.buses = m_stops_to_buses.at(stop);
		}
		return res;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		StopsForBusResponse res;
		if (m_buses_to_stops.count(bus) != 0) {
			for (const auto& s : m_buses_to_stops.at(bus)) {
				res.stops.push_back({ s, m_stops_to_buses.at(s) });
			}
			res.bus = bus;
		}
		return res;
	}

	AllBusesResponse GetAllBuses() const {	
		AllBusesResponse res;
		for (auto& b2s : m_buses_to_stops) {
			res.buses.push_back(b2s);
		}
		return res;
	}

private:
	map<string, vector<string>> m_buses_to_stops, m_stops_to_buses;
};



int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
