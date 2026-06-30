#include <iostream>

int main() {
#ifdef _GLIBCXX_HOSTED
    std::cout << "The macro _GLIBCXX_HOSTED is defined.\n";
    std::cout << "Its value is: " << _GLIBCXX_HOSTED << "\n";
    
    if (_GLIBCXX_HOSTED == 1) {
        std::cout << "-> Your compiler is targeting a HOSTED environment (OS available).\n";
    } else if (_GLIBCXX_HOSTED == 0) {
        std::cout << "-> Your compiler is targeting a FREESTANDING environment (Bare metal).\n";
    }
#else
    std::cout << "The macro _GLIBCXX_HOSTED is NOT defined.\n";
    std::cout << "(You might not be using libstdc++ / GCC).\n";
#endif

    return 0;
}