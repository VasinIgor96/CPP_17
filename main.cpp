#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

void editBook(Book& book) {
    cout << "Enter new information for the book:" << endl;
    cout << "Title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Author: ";
    getline(cin, book.author);
    cout << "Publisher: ";
    getline(cin, book.publisher);
    cout << "Genre: ";
    getline(cin, book.genre);
}

void printBooks(const Book books[], int numBooks) {
    cout << "Library Books:" << endl;
    for (int i = 0; i < numBooks; i++) {
        cout << "Book " << (i + 1) << ":" << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publisher: " << books[i].publisher << endl;
        cout << "Genre: " << books[i].genre << endl;
        cout << endl;
    }
}

void searchBooksByAuthor(const Book books[], int numBooks, const string& author) {
    cout << "Books by author " << author << ":" << endl;
    bool found = false;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].author == author) {
            cout << "Title: " << books[i].title << endl;
            cout << "Publisher: " << books[i].publisher << endl;
            cout << "Genre: " << books[i].genre << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No books found by author " << author << endl;
    }
}

void searchBooksByTitle(const Book books[], int numBooks, const string& title) {
    cout << "Books with title " << title << ":" << endl;
    bool found = false;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].title == title) {
            cout << "Author: " << books[i].author << endl;
            cout << "Publisher: " << books[i].publisher << endl;
            cout << "Genre: " << books[i].genre << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No books found with title " << title << endl;
    }
}

bool compareByTitle(const Book& book1, const Book& book2) {
    return book1.title < book2.title;
}

bool compareByAuthor(const Book& book1, const Book& book2) {
    return book1.author < book2.author;
}

bool compareByPublisher(const Book& book1, const Book& book2) {
    return book1.publisher < book2.publisher;
}

int main() {
    const int numBooks = 10;
    Book books[numBooks];

    for (int i = 0; i < numBooks; i++) {
        cout << "Enter information for Book " << (i + 1) << ":" << endl;
        cout << "Title: ";
        cin.ignore();
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Publisher: ";
        getline(cin, books[i].publisher);
        cout << "Genre: ";
        getline(cin, books[i].genre);
        cout << endl;
    }

    int bookIndex;
    cout << "Enter the index of the book to edit (1-" << numBooks << "): ";
    cin >> bookIndex;

    if (bookIndex >= 1 && bookIndex <= numBooks) {
        editBook(books[bookIndex - 1]);
        cout << "Book successfully edited." << endl;
    }
    else {
        cout << "Invalid book index." << endl;
    }

    printBooks(books, numBooks);

    string author;
    cout << "Enter the author to search for: ";
    cin.ignore();
    getline(cin, author);
    searchBooksByAuthor(books, numBooks, author);

    string title;
    cout << "Enter the title to search for: ";
    getline(cin, title);
    searchBooksByTitle(books, numBooks, title);

    sort(books, books + numBooks, compareByTitle);
    cout << "Books sorted by title:" << endl;
    printBooks(books, numBooks);

    sort(books, books + numBooks, compareByAuthor);
    cout << "Books sorted by author:" << endl;
    printBooks(books, numBooks);

    sort(books, books + numBooks, compareByPublisher);
    cout << "Books sorted by publisher:" << endl;
    printBooks(books, numBooks);
