#pragma once

namespace meetup {

enum class weekday {
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
};

enum class schedule {
    first,
    second,
    third,
    fourth,
    last,
    teenth
};

class meetup {

public:

    meetup(int year, int month);

    int day(weekday dayOfWeek,
            schedule occurrence);

private:

    int year;
    int month;
};

}