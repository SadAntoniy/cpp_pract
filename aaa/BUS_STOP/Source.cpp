#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int Q;
	cin >> Q;
	map <string, vector<string>> bus_stop;
	vector<string> bus_stop_station;
	for (int i = 0; i < Q; i++) {
		string request;
		cin >> request;
		string bus;
		vector<string> stop;
		
		if (request == "NEW_BUS") {
			
			int stop_count;
			
			string temp;
			cin >> bus >> stop_count;
			bus_stop_station.push_back(bus);
			for (int j = 0; j < stop_count; j++) {				
				cin >> temp;
				bus_stop[bus].push_back(temp);
			}
			
			/*for (const auto& m : bus_stop) {
				cout << m.first << " ";
				for (auto s : stop) {
					cout << s << " ";
				}
			}*/

		}
		else if (request == "BUSES_FOR_STOP") {
			string station;
			cin >> station;
			vector <string> buses;
			
			for (const auto& m : bus_stop) {
				for (string stops : m.second) {
					
					if (station == stops) {
						buses.push_back(m.first);
					}
				}
			}
			for (auto stop_station : bus_stop_station) {
				for (auto a : buses) {
					if (stop_station == a) cout << stop_station << " ";
				}
			}
			if (buses.empty()) {
				cout << "No stop" << endl;
			}
		}
		else if (request == "STOPS_FOR_BUS"){
			string stop_bus;
			cin >> stop_bus;
			vector<string> temp;
			
			for (auto m : bus_stop) {
				if (stop_bus == m.first) {
					for (auto stops : bus_stop[stop_bus]) {
						cout << "Stop " << stops << ": ";
						int i = 0;
						for (auto a : bus_stop_station) {
							
							for (auto b : bus_stop[a]) {
								
								if (stop_bus == a) {
									continue;
								}
								else if (stops == b) {
									cout << a << " ";
									i++;
								}
								
							}
							
						}
						if (i == 0) {
							cout << "no interchange";
						}
						cout << endl;						
					}
				}
				

				
			}
			if (bus_stop.count(stop_bus) == 0) {
				cout << "No bus" << endl;
			}

		}
		else if (request == "ALL_BUSES") {
			for (auto b : bus_stop) {
				cout << "Bus " << b.first << ": ";
				for (auto a : b.second) {
					cout << a << " ";
				}
				cout << endl;
			}
			if (bus_stop.empty()) {
				cout << "No buses" << endl;
			}
		}
	}
}