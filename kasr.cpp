#include <iostream>
#include <cstdlib> // برای abs و مجاسبه ب م م
using namespace std;

class Kasr {
private:
    int soorat;
    int makhraj;

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    void sadehKon() {// تابع ساده سازی کسر
        int common = gcd(abs(soorat), abs(makhraj));
        soorat /= common;
        makhraj /= common;
        if (makhraj < 0) {
            soorat *= -1;
            makhraj *= -1;
        }
    }

public:
    Kasr(int s, int m) {
        if (m == 0) {
            throw invalid_argument(" مخرج نمی‌تواند صفر باشد.");
        }
        soorat = s;
        makhraj = m;
        sadehKon();
    }

    void namayesh() const {// نشان دادن کسر بعد از ساده شدن
        cout << soorat << "/" << makhraj << endl;
    }

    Kasr operator+(const Kasr& dige) const {
        int new_soorat = soorat * dige.makhraj + dige.soorat * makhraj;
        int new_makhraj = makhraj * dige.makhraj;
        return Kasr(new_soorat, new_makhraj);
    }

    Kasr operator*(const Kasr& dige) const {
        int new_soorat = soorat * dige.soorat;
        int new_makhraj = makhraj * dige.makhraj;
        return Kasr(new_soorat, new_makhraj);
    }

    friend ostream& operator<<(ostream& os, const Kasr& k) {// تابع دسترسی به صورت و مخرج که خصوصی هستند
        os << k.soorat << "/" << k.makhraj;
        return os;
    }
};

int main() {
    try {// try اماده شدن برای اینکه اگر خطایی اومد بگیریمش
        Kasr k1(2, 6);
        Kasr k2(3, 4);

        cout << "کسر اول: " << k1 << endl;
        cout << "کسر دوم: " << k2 << endl;

        Kasr jam = k1 + k2;
        cout << "حاصل جمع: " << jam << endl;

        Kasr zarb = k1 * k2;
        cout << "حاصل ضرب: " << zarb << endl;
    }
    catch (const exception& e) {//اگر خطایی مثل صفر شدت مخرج پیش بیاد خطا را چاپ میکنه
        cout << e.what() << endl;
    }

    return 0;
}
