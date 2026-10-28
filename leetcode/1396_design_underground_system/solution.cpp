#include <unordered_map>
#include <string>

using namespace std;

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> activeTrips;
    unordered_map<string, pair<long long, int>> statistics;

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        activeTrips[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {

        auto [startStation, startTime] = activeTrips[id];

        int duration = t - startTime;

        string route = startStation + "->" + stationName;

        statistics[route].first += duration;
        statistics[route].second++;

        activeTrips.erase(id);
    }

    double getAverageTime(string startStation,
                          string endStation) {

        string route = startStation + "->" + endStation;

        auto [totalTime, trips] = statistics[route];

        return (double) totalTime / trips;
    }
};