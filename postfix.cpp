#include <iostream>
using namespace std;

class MyCar {
private:
    int speed;

public:
    MyCar(int s = 0) : speed(s) {}

    // نمایش سرعت
    void show() const {
        cout << "سرعت فعلی ماشین: " << speed << " کیلومتر بر ساعت" << endl;
    }

    // اوورلود ++ به صورت پسوند (postfix)
    MyCar operator++(int) {
        MyCar temp = *this; // نگه داشتن مقدار فعلی
        speed++;            // افزایش سرعت
        return temp;        // بازگرداندن مقدار قبلی
    }
};

int main() {
    MyCar car(50); // سرعت اولیه 50
    car.show();

    MyCar oldCar = car++; // اعمال ++ به صورت postfix

    cout << "بعد از car++ :" << endl;
    car.show();

    cout << "مقدار قبلی که ذخیره شد:" << endl;
    oldCar.show();

    return 0;
}
