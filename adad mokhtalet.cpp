#include <iostream>
#include <cmath>
using namespace std;

// تعریف کلاس عدد مختلط
class Complex {
private:
    float real;  // قسمت حقیقی (مثلاً عدد 3 در 3 + 4i)
    float imag;  // قسمت موهومی (ضریب i که i*i = -1 است)

public:
    // سازنده با مقداردهی پیش‌فرض
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    // سربارگذاری عملگر جمع +
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // سربارگذاری عملگر ضرب *
    Complex operator*(const Complex& obj) {
        float r = real * obj.real - imag * obj.imag;
        float i = real * obj.imag + imag * obj.real;
        return Complex(r, i);
    }

    // سربارگذاری عملگر نابرابری !=
    bool operator!=(const Complex& obj) {
        return (real != obj.real || imag != obj.imag);
    }

    // تابع تنظیم مقادیر قسمت حقیقی و موهومی
    void set(float r, float i) {
        real = r;
        imag = i;
    }

    // تابع دوست برای نمایش عدد مختلط در خروجی
    friend ostream& operator<<(ostream& out, const Complex& C) {
        out << C.real;
        if (C.imag >= 0)
            out << " + " << C.imag << "i";
        else
            out << " - " << -C.imag << "i";
        out << endl;
        return out;
    }

    // تابع دوست برای گرفتن ورودی عدد مختلط از کاربر
    friend istream& operator>>(istream& in, Complex& C) {
        cout << "GHESMAT HAGHIGHY RA VARED KOMID = ";
        in >> C.real;
        cout << "GHESMAT MOHUMY RA VARED KONID = ";
        in >> C.imag;
        return in;
    }
};


int main() {
    Complex c1, c2;

    // گرفتن ورودی دو عدد مختلط از کاربر
    cout << "ADAD MOGHTALET AVAL ="<<endl ;
    cin >> c1;

    cout << "adad moghtalet dovom ="<<endl ;
    cin >> c2;

    // جمع و ضرب دو عدد مختلط
    Complex sum = c1 + c2;
    Complex product = c1 * c2;


    cout << "jame: " << sum;
    cout << "zarb: " << product;

    // بررسی برابری یا نابرابری
    if (c1 != c2)
        cout << "numbers is differnt" << endl;
    else
        cout << "numbers is equal." << endl;

    return 0;
}
