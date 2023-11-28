bool contains(int num, int contains1, int contains2) {
    while (num > 0) {
        if ((num % 10 == contains1) || (num % 10 == contains2)) {
            return true;
        }
        num /= 10;
    }
    return false;
}