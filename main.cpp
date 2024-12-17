#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string cipher_decrypt(string text, int shift) {
    string result = "";
    for (char c : text) {
        if (isupper(c))
            result += char(int(c - shift - 65 + 26) % 26 + 65);
        else if (islower(c))
            result += char(int(c - shift - 97 + 26) % 26 + 97);
        else
            result += c;
    }
    return result;
}
string cipher_encrypt(string text, int shift) {
    string result = "";
    for (char c : text) {
        if (isupper(c))
            result += char(int(c + shift - 65) % 26 + 65);
        else if (islower(c))
            result += char(int(c + shift - 97) % 26 + 97);
        else
            result += c;
    }
    return result;
}
string mono_decrypt(string text, string key) {
    unordered_map<char, char> decryptMap;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++) decryptMap[key[i]] = alphabet[i];
    string result = "";
    for (char c : text) {
        if (isupper(c)) result += decryptMap[c];
        else if (islower(c)) result += tolower(decryptMap[toupper(c)]);
        else result += c;
    }
    return result;
}

string mono_encrypt(string text, string key) {
    unordered_map<char, char> encryptMap;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++) encryptMap[alphabet[i]] = key[i];
    string result = "";
    for (char c : text) {
        if (isupper(c)) result += encryptMap[c];
        else if (islower(c)) result += tolower(encryptMap[toupper(c)]);
        else result += c;
    }
    return result;
}


int main() {
    // Mono
    string key, text;

    cout << "Enter substitution key (26 uppercase letters): ";
    cin >> key;
    cin.ignore();
    cout << "Enter plain text: ";
    getline(cin, text);
    string encrypted_message = mono_encrypt(text, key);
    cout << "Encrypted message: " << encrypted_message << endl;
    string decrypted_message = mono_decrypt(encrypted_message, key);
    cout << "Decrypted message: " << decrypted_message << endl;

    // cipher
    int shift;
    cout << "Enter plain text: ";
    getline(cin, text);
    cout << "Enter shift value: ";
    cin >> shift;
    auto message = cipher_encrypt(text, shift);
    cout << "Encrypted message: " << message << endl;
    cout << "Decrypt message: " << cipher_decrypt(message, shift) << endl;
    return 0;
}