#include "Time.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int tempHour;
    int tempMin;
    int tempSec;
    cout << "Инициализация Time 1\nВведите количество часов: ";
    cin >> tempHour;
    cout << "Введите количество минут: ";
    cin >> tempMin;
    cout << "Введите количество cекунд: ";
    cin >> tempSec;
    Time time1(tempHour, tempMin, tempSec);
    cin.ignore(1000, '\n');
    cout << "Инициализация Time 2\nВведите время в формате 23:59:59: ";
    string tempTimeStr;
    getline(cin, tempTimeStr);
    Time time2(tempTimeStr);
    cout << "Инициализация Time 3\nВведите еще время в формате 23:59:59: ";
    getline(cin, tempTimeStr);
    Time timetemp(tempTimeStr);
    Time time3(timetemp);
    cout << "Созданы и инициализированы объекты:\n"
        << "Time 1 - " << time1.getTimeString()
        << "\nTime 2 - " << time2.getTimeString()
        << "\nTime 3 - " << time3.getTimeString();
    ++time1;
    time2++;
    cout << "\nTime 1 увеличено на 1 минуту - " << time1.getTimeString()
        << "\nTime 2 увеличено на 1 секунду - " << time2.getTimeString();
    if (time1 > time2)
        cout << "\nTime 1 больше Time 2";
    else
        cout << "\nTime 1 не больше Time 2";
    cout << "\n\nВведите время, до которого нужно посчитать промежуток в формате 23:59:59: ";
    getline(cin, tempTimeStr);
    Time compare(tempTimeStr);
    TimePeriod timeLeft = time3.countTimeTo(compare);
    if (timeLeft.hours != 0 && timeLeft.minutes != 0 && timeLeft.seconds != 0)
    {
        cout << "До " << compare.getTimeString() << " относительно Time 3 осталось " << timeLeft.hours
            << " часов, " << timeLeft.minutes << " минут и " << timeLeft.seconds << " секунд\n";
    }
}
