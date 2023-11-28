#include <cmath>

bool isPrimary(int num) {
    if (num == 2) return true;
    for (int i = std::sqrt(num) + 1; i > 1; i--) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}