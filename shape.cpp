    #include <iostream>
    using namespace std;

    const float PI = 3.14159;

    class Shape {
    protected:
        string color;    // رنگ شکل
        string pattern;  // الگوی شکل (مثل نقطه‌ای، خط‌دار و غیره)
    public:
        // سازنده کلاس پایه برای مقداردهی اولیه رنگ و الگو
        Shape(string c, string p) {
            this->color = c;
            this->pattern = p;
        }

        // تابع برای نمایش مشخصات رنگ و الگوی شکل
        void Display() {
            cout << "The color of shape = " << color << ", pattern = " << pattern << endl;
        }
    };

    class Circle : protected Shape {
    private:
        float radius;  // شعاع دایره
    public:
        // سازنده کلاس دایره برای مقداردهی اولیه شعاع، رنگ و الگو
        Circle(float r, string c1, string p1) : Shape(c1, p1) {
            this->radius = r;
        }

        // محاسبه مساحت دایره
        float Area() {
            return PI * radius * radius;
        }

        // تابع برای نمایش مشخصات دایره
        void Display() {
            cout << "Circle -> Radius = " << radius
                 << ", Area = " << Area()
                 << ", color = " << color << ", pattern = " << pattern << endl;
        }
    };

    class Rectangle : protected Shape {
    private:
        float length;  // طول مستطیل
        float width;   // عرض مستطیل
    public:
        // سازنده کلاس مستطیل برای مقداردهی اولیه طول، عرض، رنگ و الگو
        Rectangle(float l, float w, string c, string p) : Shape(c, p) {
            length = l;
            width = w;
        }


        float Area() {
            return length * width;

        }

        // تابع برای نمایش مشخصات مستطیل
        void Display() {
            cout << "Rectangle -> Length = " << length << ", Width = " << width
                 << ", Area = " << Area()
                 << ", color = " << color << ", pattern = " << pattern << endl;
        }
    };

    class Triangle : protected Shape {
    private:
        float base;
        float height;
    public:
        // سازنده کلاس مثلث برای مقداردهی اولیه قاعده، ارتفاع، رنگ و الگو
        Triangle(float b, float h, string c, string p) : Shape(c, p) {
            base = b;
            height = h;
        }


        float Area() {
            return 0.5 * base * height;
        }

        // تابع برای نمایش مشخصات مثلث
        void Display() {
            cout << "Triangle -> Base = " << base << ", Height = " << height
                 << ", Area = " << Area()
                 << ", color = " << color << ", pattern = " << pattern << endl;
        }
    };

    int main() {
        // ایجاد اشیاء از کلاس‌های Circle، Rectangle و Triangle
        Circle c1(2.5, "Yellow", "LineLine");
        Rectangle r1(5.0, 3.0, "Red", "Striped");
        Triangle t1(4.0, 2.5, "Green", "Solid");

        // نمایش مشخصات هر یک از شی ها
        c1.Display();
        r1.Display();
        t1.Display();

        return 0;
    }
