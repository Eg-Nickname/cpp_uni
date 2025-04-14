#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

enum Field { Id, Title, Name, Surname, Pub_year };

struct Book {
    int id;
    std::string title;
    std::string name;
    std::string surname;
    int pub_year;

    void print_book() {
        std::cout << id << " \"" << title << "\" by " << name << " " << surname
                  << " was published in " << pub_year << std::endl;
    }
};

std::vector<Book> load_books_from_file(std::string filename) {
    // Open file to get bookdata
    std::fstream file;
    file.open(filename, std::ios::in);

    if (!file) {
        std::cerr << "Cant open file " << filename << std::endl;
        exit(1);
    }

    std::vector<Book> books;
    std::string line;
    // Parse book data fro each line of file
    while (!file.eof()) {
        auto book = Book();
        std::getline(file, line);
        std::stringstream linestream(line);
        std::string str_id;
        if (!std::getline(linestream, str_id, ';')) {
            break;
        }
        if (!std::getline(linestream, book.title, ';')) {
            break;
        }

        if (!std::getline(linestream, book.name, ';')) {
            break;
        }
        if (!std::getline(linestream, book.surname, ';')) {
            break;
        }
        std::string str_pub_year;
        if (!std::getline(linestream, str_pub_year, ';')) {
            break;
        }

        try {
            book.id = std::stoi(str_id);
            book.pub_year = std::stoi(str_pub_year);
        } catch (std::invalid_argument const&) {
            break;
        }
        book.title.erase(0, book.title.find(" ") + 1);
        book.name.erase(0, book.name.find(" ") + 1);
        book.surname.erase(0, book.surname.find(" ") + 1);
        books.push_back(book);
    }

    return books;
}

void sort_books(std::vector<Book>& vec, Field field) {
    switch (field) {
    case Id:
        std::sort(vec.begin(), vec.end(), [](Book const& lhs, Book const& rhs) {
            return lhs.id < rhs.id;
        });
        return;
    case Title:
        std::sort(vec.begin(), vec.end(), [](Book const& lhs, Book const& rhs) {
            return lhs.title < rhs.title;
        });
        return;
    case Name:
        std::sort(vec.begin(), vec.end(), [](Book const& lhs, Book const& rhs) {
            return lhs.name < rhs.name;
        });
        return;
    case Surname:
        std::sort(vec.begin(), vec.end(), [](Book const& lhs, Book const& rhs) {
            return lhs.surname < rhs.surname;
        });
        return;
    case Pub_year:
        std::sort(vec.begin(), vec.end(), [](Book const& lhs, Book const& rhs) {
            return lhs.pub_year < rhs.pub_year;
        });
        return;
    }
}

auto main(int argc, char** argv) -> int {
    if (argc != 2) {
        std::cout << "Provide book file." << std::endl;
    }
    auto books = load_books_from_file(argv[1]);
    sort_books(books, Field::Title);
    for (auto it = books.begin(); it < books.end(); it++) {
        it->print_book();
    }
    return 0;
}