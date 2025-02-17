#include <iostream>
using namespace std;


struct Rectangle {
    int length;
    int width;
};


int calculatePerimeter(const Rectangle& rect) {
    return 2 * (rect.length + rect.width);
}


int calculateArea(const Rectangle& rect) {
    return rect.length * rect.width;
}


void drawRectangle(const Rectangle& rect) {
    for (int i = 0; i < rect.width; ++i) {
        for (int j = 0; j < rect.length; ++j) {

            if (i == 0 || i == rect.width - 1 || j == 0 || j == rect.length - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    Rectangle rect;

    cout << "tule mostatil ra vared konid : ";
    cin >> rect.length;
    cout << "arze mostatil ra vared konid : ";
    cin >> rect.width;


    cout << "mohit mostatil : " << calculatePerimeter(rect) << endl;
    cout << "masahat mostatil: " << calculateArea(rect) << endl;


    cout << "mostatil rasm shode :" << endl;
    drawRectangle(rect);

    return 0;
}
