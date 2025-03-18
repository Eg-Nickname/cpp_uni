#include <print>
void ptr_swap(int* &a_ptr, int* &b_ptr){
    int* temp_ptr = a_ptr;
    a_ptr = b_ptr;
    b_ptr = temp_ptr;
}

void val_swap(int* a_ptr, int* b_ptr){
    int tmp = *a_ptr;
    *a_ptr = *b_ptr;
    *b_ptr = tmp;  
}

auto main() -> int{
    int a=4, b=8;
    int* x_ptr=&a, *y_ptr = &b;
    std::println("Ptr before swap - x_ptr = {:p}, y_ptr = {:p}", (void*)x_ptr, (void*)y_ptr);
    ptr_swap(x_ptr, y_ptr);
    std::println("Ptr after  swap - x_ptr = {:p}, y_ptr = {:p}", (void*)x_ptr, (void*)y_ptr);
    std::println("Value of ptrs - x_ptr val = {:d}, y_ptr val = {:d}", *x_ptr, *y_ptr);
    val_swap(x_ptr, y_ptr);
    std::println("Ptr adr after val swap - x_ptr = {:p}, y_ptr = {:p}", (void*)x_ptr, (void*)y_ptr);
    std::println("Value of ptrs after val swap - x_ptr val = {:d}, y_ptr val = {:d}", *x_ptr, *y_ptr);
    return 0;
}

