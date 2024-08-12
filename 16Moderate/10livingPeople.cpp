

#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
    int year;
    bool isBirth; // true for birth, false for death
};

// Comparator to sort events by year; in case of tie, births come before deaths
bool eventComparator(const Event& a, const Event& b) {
    if (a.year == b.year) {
        return a.isBirth > b.isBirth; // Prioritize births over deaths
    }
    return a.year < b.year;
}

int findYearWithMaxPeopleAlive(const std::vector<std::pair<int, int>>& people) {
    std::vector<Event> events;

    // Create events for births and deaths
    for (const auto& person : people) {
        int birth = person.first;
        int death = person.second;

        // Birth event
        events.push_back({birth, true});
        // Death event (one year after the person dies)
        events.push_back({death + 1, false});
    }

    // Sort events by year
    std::sort(events.begin(), events.end(), eventComparator);

    int currentCount = 0;
    int maxCount = 0;
    int maxYear = 1900;

    // Process events
    for (const auto& event : events) {
        if (event.isBirth) {
            ++currentCount;
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxYear = event.year;
            }
        } else {
            --currentCount;
        }
    }

    return maxYear;
}

int main() {
    // Example input: list of people with birth and death years
    std::vector<std::pair<int, int>> people = {
        {1908, 1909},
        {1909, 1910},
        {1910, 1920},
        {1915, 1925}
    };

    int year = findYearWithMaxPeopleAlive(people);
    std::cout << "Year with maximum number of people alive: " << year << std::endl;

    return 0;
}
