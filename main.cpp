#include <iostream>
using namespace std;


int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int number;
    cout << "n adad ra vared konid): ";
    cin >> number;

    if (number < 0) {
        cout << "adad bayad bozorg tar ya mosavi sefr bashad !" << endl;
    } else {
        int result = fibonacci(number);
        cout << "adad " << number << "n dar donbale barabar ast ba : " << result << endl;
    }

    return 0;
}
