#include <iostream>
void word_processing(char* word) { //removing punctuation symbols and digits
	int a = 0;
    char symbols[23] = {",.;:<>(){}[]0123456789"};
	while (word[a] != '\0') {
        for (char symbol : symbols){
            if (word[a] == symbol){
                word[a] = '\0';
                return;
            }
        }
		a++;
	}
}


int length(char* word){ //returns a length of word
    int len = 0;
    while (word[len] != 0) len++;
    return len;
}


bool has_three_same(char* word) { //checks if there are 3 same letters in word
	short len = length(word);
	for (short a = 0; a < len-1; a++) {
		short count = 1;
		for (short b = a + 1; b < len; b++) {
			if (word[a] == word[b]) {
				count++;
				if (count == 3) {
					return true;
				}
			}
		}
	}
	return false;
}


bool strcompare(char* word1, char* word2) { //compares two strings and returns are they same or no
	if (length(word1) == length(word2)) {
		for (short a = 0; a < length(word1); a++) {
			if (word1[a] != word2[a]) return false;
		}
		return true;
	}
	else return false;
}


void copy_to_string(char* input, char* output, int size_of_output){ //copies all symbols from 1 word to other
    if (size_of_output < length(input)){
        std::cerr << "Error! Not enough space to write!" << std::endl;
    }
    else {
        for (int a = 0; a <= length(input); a++) output[a] = input[a];
    }
}