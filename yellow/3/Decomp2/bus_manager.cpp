#include "bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
	m_buses_to_stops[bus] = stops;
	for (const auto& s : stops) {
		m_stops_to_buses[s].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
	BusesForStopResponse res;
	if (m_stops_to_buses.count(stop) != 0) {
		res.buses = m_stops_to_buses.at(stop);
	}
	return res;
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
	StopsForBusResponse res;
	if (m_buses_to_stops.count(bus) != 0) {
		for (const auto& s : m_buses_to_stops.at(bus)) {
			res.stops.push_back({ s, m_stops_to_buses.at(s) });
		}
		res.bus = bus;
	}
	return res;
}

AllBusesResponse BusManager::GetAllBuses() const {
	AllBusesResponse res;
	for (auto& b2s : m_buses_to_stops) {
		res.buses.push_back(b2s);
	}
	return res;
}
