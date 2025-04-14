// Niech program przyjmuje jako argument nazwę pliku tekstowego, który ma
// analizować ( najlepiej lorem ipsum). Niech program sprawdza, czy ten plik
// otwiera się poprawnie / istnieje w bieżącym katalogu i czy jest plikiem
// tekstowym, jeśli nie istnieje, niech wypisuje wszystkie pliki znajdujące się
// w katalogu i kończy działanie. Jeśli plik tekstowy istnieje, niech program
// wykona podstawową analizę, tzn. niech policzy ile plik ma linijek, wyrazów,
// znaków. Znak – traktujemy jako zwykły znak interpunkcyjny, więc np.
// „czarno-czerwony” powinien być traktowany jako dwa słowa.

// Niech program liczy ile razy dane słowo wystąpiło w tekście. Duże i małe
// litery traktujemy tak samo. Wyniki proszę zapisać w mapie, a następnie ją
// wypisać.
// - Niech program uszereguje słowa alfabetycznie (wypis).
// - Niech program uszereguje słowa od najkrótszego do najdłuższego. Jeśli dwa
// słowa mają taką samą długość, niech decyduje kolejność alfabetyczna (wypis).
// - Ile różnych słów jest w tekście? (wypis)
// - Ile w tekście jest wyrazów o parzystej liczbie liter i nieparzystej liczbie
// liter? (wypis)
// - Jaki jest najdłuższy wyraz w tekście? Jeśli jest ich kilka, wypisz
// wszystkie.
// - Usuń z mapy wszystkie słowa, które zawierają literę q. Wypisz zawartość
// mapy po tej operacji.
// - Znajdź i wypisz wszystkie słowa, które zawierają litery o i l.
// -* Wyszukuj i wypisuj wyrazy pochodne np. dom: domu, domy, domów, domowi...

// Wyniki analizy tekstu zapisz w pliku tekstowym.

#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>

void print_cur_dir();
void analyze_file(std::string& file_name);

namespace fs = std::filesystem;

auto main(int argc, char** argv) -> int {
    if (argc != 2) {
        std::print("Please provide file path to analyze\n");
        return 1;
    }

    std::string file_name(argv[1]);
    switch (fs::path p{file_name}; fs::status(p).type()) {
    case fs::file_type::regular:
        analyze_file(file_name);
        break;
    default:
        print_cur_dir();
        break;
    }
    return 0;
}

void print_cur_dir() {
    std::cout << "Directory: " << fs::current_path() << std::endl;
    for (const auto& it : fs::directory_iterator{fs::current_path()}) {
        std::cout << " - " << it.path() << std::endl;
    }
}

void analyze_file(std::string& file_name) {
    std::fstream file;
    file.open(file_name, std::ios::in);

    if (!file) {
        std::cerr << "Cant open file " << file_name << std::endl;
        exit(1);
    }

    std::string line;
    int lines = 0, words = 0, chars = 0;
    while (!file.eof()) {
        std::getline(file, line);
        lines += 1;
        bool prev_char_alpha = false;
        for (auto it = line.begin(); it < line.end(); it++) {
            chars += 1;
            if (std::isalpha(*it)) {
                prev_char_alpha = true;
            } else {
                if (prev_char_alpha) {
                    words += 1;
                }
                prev_char_alpha = false;
            }
        }
        if (prev_char_alpha) {
            words += 1;
        }
    }
    std::print("Podany plik posiada: \n - {} linijek \n - {} wyrazów \n - {} "
               "znaków \n",
               lines, words, chars);
}