#include <iostream>
#include <string>

using namespace std;


struct Book {
    string title;       // عنوان کتاب
    string author;      // نویسنده
    int year;           // سال انتشار
    int pages;          // تعداد صفحات
    double price;       // قیمت کتاب
};

// تابع برای نمایش اطلاعات یک کتاب
void printBookInfo(const Book& book) {
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Year: " << book.year << endl;
    cout << "Pages: " << book.pages << endl;
    cout << "Price: tuman" << book.price<<endl ;
    cout << "--------------------------" << endl;
}

int main() {

    Book book1 = {"buf kur ", "sadegh hedayat", 1315, 180, 30000};
    Book book2 = {"samphoni mordegan", "abbas maeruphy", 1368, 328,50000};
    Book book3 = {"soshon ", "simin daneshvar",1348, 281, 100000};


    printBookInfo(book1);
    printBookInfo(book2);
    printBookInfo(book3);

    return 0;
}
