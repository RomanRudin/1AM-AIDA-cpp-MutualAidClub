#include <string>

void toLower(std::string& word) {
	for (int i = 0; i < word.length(); i++) {
		if (((int)word[i] >= -64) && ((int)word[i] <= -33)) {
			word[i] = (char)(word[i] + 32);
		}
	}
}