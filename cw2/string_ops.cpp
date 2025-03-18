#include <print>
#include <string>
auto main() -> int{
    std::string s1= "a";
    for(auto i =0; i<257;i++){
        s1+="a";
        std::println("s1 size - {:d}, s1 capacity - {:d}", s1.size(), s1.capacity());
    }
    return 0;
}