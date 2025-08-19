#include <iostream>
#include <string>
using namespace std;

// Hàm mã hóa Vigenère
string vigenereEncrypt(string text, string key) {
    string result = "";
    int keyIndex = 0;
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            char keyBase = isupper(key[keyIndex % key.length()]) ? 'A' : 'a';
            result += (text[i] - base + (key[keyIndex % key.length()] - keyBase)) % 26 + base;
            keyIndex++;
        } else {
            result += text[i];
        }
    }
    return result;
}

// Hàm giai mã Vigenère
string vigenereDecrypt(string text, string key) {
    string result = "";
    int keyIndex = 0;
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            char keyBase = isupper(key[keyIndex % key.length()]) ? 'A' : 'a';
            result += (text[i] - base - (key[keyIndex % key.length()] - keyBase) + 26) % 26 + base;
            keyIndex++;
        } else {
            result += text[i];
        }
    }
    return result;
}

int main() {
    string plaintext = "HELLO WORLD";
    string key = "KEY";

    string ciphertext = vigenereEncrypt(plaintext, key);
    cout << "Ban ma: " << ciphertext << endl;

    string decryptedText = vigenereDecrypt(ciphertext, key);
    cout << "Giai ma: " << decryptedText << endl;

    return 0;
}

