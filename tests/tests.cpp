#include <cpp11patch/mutex.h>
#include <iostream>

cpp11patch::once_flag flag;

void my_init(int x) {
    std::cout << "Initialize: " << x << std::endl;
}

int main() {
    cpp11patch::call_once(flag, my_init, 42);
    cpp11patch::call_once(flag, my_init, 99); // This call will not execute the function again
    return 0;
}
