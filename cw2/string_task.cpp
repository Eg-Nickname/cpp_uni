#include <iostream>
#include <print>
#include <string>
#include <cctype>

auto main() -> int{
    // Wczytanie napisu z klawiatury
    std::string str = "";
    std::println("Podany string, na którym będziemy operować", str);
    std::cout<<std::flush;
    std::getline(std::cin, str);
    std::println("Podany string: {}", str);
    
    // Odwracanie napisu
    std::string rev_str = "";
    rev_str.reserve(str.capacity());
    for(auto it = str.crbegin(); it < str.crend(); it++){
        rev_str.push_back(*it);
    }
    std::println("Odwrócony string {}", rev_str);
    
    // Zamienia małą literę na dużą na początku każdego słowa
    std::string words_begin_upper_case = "";
    bool should_change = true;
    for(auto it = str.begin(); it < str.end(); it++){
        if(should_change == true){
            words_begin_upper_case.push_back(std::toupper(*it));
            should_change = false;
        }else{
            words_begin_upper_case.push_back(*it);
        }
        
        if(!(std::isalpha(*it) || std::isdigit(*it))){
            should_change = true;
        }
    }
    std::println("String z wielkimi literami string: {}", words_begin_upper_case);
    
    // Liczba samogłosek w podanym stringu
    int samogloski = 0;
    for(auto it = str.begin(); it < str.end(); it++){
        auto ch = std::tolower(*it);
        if(ch == 'a' || ch == 'e' || ch == 'u' || ch == 'o' || ch == 'y' || ch == 'i'){
            samogloski++;
        }
    }
    std::println("Liczba samoglosek w podanym tekscie: {}", samogloski);
    
    // -Czy w stringu są liczby, jeżeli tak, niech liczy ich sumę.
    int sum = 0, partial_sum = 0;
    bool prev_numeric = false;
    for(auto it = str.begin(); it < str.end(); it++){
        auto ch = *it;
        if(std::isdigit(ch)){
            prev_numeric = true;
            partial_sum *= 10;
            partial_sum += (int)ch - 48;
        }else{
            prev_numeric = false;
            sum += partial_sum;
            partial_sum = 0;
        }
    }
    sum += partial_sum;
    std::println("Suma cyfr w napisie: {}", sum);
    
    // Czy dany string zawiera dany „substring”
    std::string sub_str = "";
    std::println("Podaj substring, którego bedziemy szukac:", sub_str);
    std::cout<<std::flush;
    std::getline(std::cin, sub_str);

    auto sub_str_pos = str.find(sub_str);
    if (sub_str_pos != std::string::npos){
        std::println("Znaleziono substring na pozycji: {}", sub_str_pos);
    }else{
        std::println("Nie znaleziono substirnga");
    }

    return 0;
}