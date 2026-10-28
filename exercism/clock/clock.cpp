#include "clock.h"

#include <sstream>
#include <iomanip>

namespace date_independent {

const int DAY_MINUTES = 24 * 60;

int clock::normalize(int value)
{
    value %= DAY_MINUTES;

    if(value < 0)
        value += DAY_MINUTES;

    return value;
}

clock::clock(int totalMinutes)
    : totalMinutes(normalize(totalMinutes))
{
}

clock clock::at(int hour,
                int minute)
{
    return clock(hour * 60 + minute);
}

clock clock::plus(int minutes) const
{
    return clock(totalMinutes + minutes);
}

bool clock::operator==(const clock& other) const
{
    return totalMinutes == other.totalMinutes;
}

clock::operator std::string() const
{
    int hour = totalMinutes / 60;
    int minute = totalMinutes % 60;

    std::ostringstream out;

    out << std::setw(2)
        << std::setfill('0')
        << hour
        << ":"
        << std::setw(2)
        << std::setfill('0')
        << minute;

    return out.str();
}

}