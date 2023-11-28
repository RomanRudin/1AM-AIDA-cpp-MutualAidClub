int getFirstDigit(int value){
    int num = value;
    while (num > 9) {
        num /= 10;
    }
    return num;
}