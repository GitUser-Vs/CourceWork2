#include <iostream>
#include <string>

struct Date {
    int day;
    int month;
    int year;

    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    // ѕример метода дл€ сравнени€ дат (упрощенно)
    bool isAfter(const Date& other) const {
        if (year > other.year) return true;
        if (year == other.year && month > other.month) return true;
        if (year == other.year && month == other.month && day > other.day) return true;
        return false;
    }

    // ѕример метода дл€ вычислени€ разницы (упрощенно, в дн€х)
    int daysDifference(const Date& other) const {
        // Ёто очень упрощенна€ модель. –еальна€ реализаци€ потребует учета дней в мес€цах, високосных годов и т.д.
        // ƒл€ демонстрации достаточно, что мы можем получить число.
        // ѕример: 30 дней в мес€це, 365 в году.
        return (year - other.year) * 365 + (month - other.month) * 30 + (day - other.day);
    }

    void display() const {
        std::cout << day << "/" << month << "/" << year;
    }
};