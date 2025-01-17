#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>
#include <cctype>

using namespace std;

class Book {
    public:
        string title;
        string author;
        int realese;
        int count;

        Book(string x, string y, int z, int i) {
            title = x;
            author = y;
            realese = z;
            count = i;
        }

        void setBorrow() {
            if (count != 0) {   
                count--;
                cout << "Successfully to borrow the book!\n";
            } else {
                cout << "Sorry this book out of borrowing!\n";
            }
        }

        void setReturn() {
            count++;
            cout << "Successfully to return the book!\n";
        }
};

class Comic : public Book {
    public:
        string category = "Comic";
        using Book::Book;
        Comic(string title, string author, int realese, int count) : Book(title, author, realese, count) {}
};

class Novel : public Book {
    public:
        string category = "Novel";
        using Book::Book;
        Novel(string title, string author, int realese, int count) : Book(title, author, realese, count) {}
};

class Magazine : public Book {
    public:
        string category = "Magazine";
        using Book::Book;
        Magazine(string title, string author, int realese, int count) : Book(title, author, realese, count) {}
};

class Education : public Book {
    public:
        string category = "Education";
        using Book::Book;
        Education(string title, string author, int realese, int count) : Book(title, author, realese, count) {}
};

vector<Book> libraryDb;

void donateBook() {
    string title;
    string author;
    int realese;
    int countOfBook;
    int category;
    char optional;
    try {
        cout << "Enter the book title: ";
        getline(cin, title);

        cout << "Enter the book author: ";
        getline(cin, author);

        cout << "Enter the book realese: ";
        cin >> realese;

        cout << "Book category\n1. Comic\n2. Novel\n3. Magazine\n4. Education\nPlease select one of book category: ";
        cin >> category;

        cout << "How much the book you want to donate: ";
        cin >> countOfBook;
        cin.ignore();

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Please enter the valid option!");
        }

        if (category == 1) {
            Comic newComic(title, author, realese, countOfBook);
            libraryDb.push_back(newComic);
            cout << "Successfully to donate the comic!\n";
        } else if (category == 2) {
            Novel newNovel(title, author, realese, countOfBook);
            libraryDb.push_back(newNovel);
            cout << "Successfully to donate the novel!\n";
        } else if (category == 3) {
            Magazine newMagazine(title, author, realese, countOfBook);
            libraryDb.push_back(newMagazine);
            cout << "Successfully to donate the magazine!\n";
        } else if (category == 4) {
            Education newEducation(title, author, realese, countOfBook);
            libraryDb.push_back(newEducation);
            cout << "Successfully to donate the education book!\n";
        } else {
            throw runtime_error("Please select the valid category!");
        }
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Do you want to donate again? (Y/N): ";
    cin >> optional;
    cin.ignore();

    if (tolower(optional) == 'y') {
        donateBook();
    }
}

void borrowBook() {
    int selectedBook;
    char optional;
    if (libraryDb.size() != 0) {
        cout << "List of book title!\n";
        int number = 1;
        for (Book i : libraryDb) {
            cout << number << ". " << i.title << endl;
            number++;
        }

        cout << "Select the book want to borrow: ";
        cin >> selectedBook;
        cin.ignore();

        if (selectedBook > libraryDb.size()) {
            cout << "Plese select the valid option!\n";
        } else {
            Book bookBorrow = libraryDb[selectedBook-1];
            bookBorrow.setBorrow();
            libraryDb[selectedBook-1] = bookBorrow;
        }

    } else {
        cout << "There are no books available for borrowing yet!\n";
    }

    cout << "Do you want to donate again? (Y/N): ";
    cin >> optional;
    cin.ignore();

    if (tolower(optional) == 'y') {
        donateBook();
    }
}

void returnBook() {
    int selectedBook;
    char optional;

    if (libraryDb.size() != 0) {
        cout << "List of book title!\n";
        int number = 1;
        for (Book i : libraryDb) {
            cout << number << ". " << i.title << endl;
            number++;
        }

        cout << "Select the book want to return: ";
        cin >> selectedBook;
        cin.ignore();

        if (selectedBook > libraryDb.size()) {
            cout << "Plese select the valid option!\n";
        } else {
            Book bookBorrow = libraryDb[selectedBook-1];
            bookBorrow.setReturn();
            libraryDb[selectedBook-1] = bookBorrow;
        }

    } else {
        cout << "There are no books available for borrowing yet!\n";
    }

    cout << "Do you want to donate again? (Y/N): ";
    cin >> optional;
    cin.ignore();

    if (tolower(optional) == 'y') {
        donateBook();
    }
}

int main() {
    int choice;
    while (true) {
        system("clear");
        try {
            cout << "Welcome to National Libaray!\n1. Borrow a book\n2. Return a book\n3. Donate book\n4. Exit\nWhat do you want to do?: ";
            cin >> choice;
            cin.ignore();

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Please enter the valid option!");
            }

            if (choice == 1) {
                borrowBook();
            } else if (choice == 2) {
                returnBook();
            } else if (choice == 3) {
                donateBook();
            } else if (choice == 4) {
                break;
            } else {
                throw runtime_error("Please enter the valid option!");
            }

        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << "Enter to continue ...";
        cin.get();
    }
    return 0;
}