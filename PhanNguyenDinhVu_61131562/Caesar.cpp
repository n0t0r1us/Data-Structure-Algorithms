#include <iostream>
#include <string>
using namespace std;

// Hàm mã hóa Caesar
string caesarEncrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            result += (text[i] - base + shift) % 26 + base;
        } else {
            result += text[i];
        }
    }
    return result;
}

// Hàm giai mã Caesar
string caesarDecrypt(string text, int shift) {
    return caesarEncrypt(text, 26 - (shift % 26));
}

// Hàm phá mã Caesar (dò tat ca các kha nang)
void caesarBreak(string ciphertext) {
    for (int shift = 1; shift < 26; shift++) {
        cout << "Giai doan " << shift << ": " << caesarDecrypt(ciphertext, shift) << endl;
    }
}

int main() {
    string plaintext = "Hello World";
    int shift = 3;

    string ciphertext = caesarEncrypt(plaintext, shift);
    cout << "Ban ma: " << ciphertext << endl;

    string decryptedText = caesarDecrypt(ciphertext, shift);
    cout << "Giai ma: " << decryptedText << endl;

    cout << "Pha ma:" << endl;
    caesarBreak(ciphertext);

    return 0;
}

