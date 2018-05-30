//
// Created by younghyun on 18. 5. 31.
//

#ifndef INC_9_DATE_H
#define INC_9_DATE_H

class Date {
public:
    Date(int y, int m, int d);

    class Invalid {};
    int month() { return m; }

private:
    int y, m, d;
    bool is_valid();
};


#endif //INC_9_DATE_H
