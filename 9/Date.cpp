//
// Created by younghyun on 18. 5. 31.
//

#include "Date.h"

Date::Date(int yy, int mm, int dd)
        : y{yy}, m{mm}, d{dd} {
    if (!is_valid())
        throw Invalid();
}

bool Date::is_valid() {
    if (m < 1 || m > 12)
        return false;

    return true;
}