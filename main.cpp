#include <iostream>
#include <fstream> // доступ до класу ofstream, ifstream
#include <string>
#include <windows.h>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;


class Text {
public:
    char* text;
    int size;
    Text() {
        text = static_cast<char *>(calloc(10, sizeof(char))); // Allocate memory for array
        size = strlen(text);
    }
    void changeSize(char* newText) {
        text = newText;
    }
    void changeTextByIndex(int index, char element) {
        text[index] = element;
    }

    ~Text() {
        free(text);
    }
};

class Caesar {
    HINSTANCE handle;
    public:
    Caesar() {
        handle = LoadLibrary(TEXT("C:\\Users\\Professional\\CLionProjects\\untitled3\\cmake-build-debug\\liblibrary.dll"));
        if (handle == nullptr || handle == INVALID_HANDLE_VALUE) {
            cout << "Library not found" << endl;
        }
    }

    char* encrypt(char* rawText, int key){
        typedef char* (*encrypt_ptr_t)(char*, int);
        encrypt_ptr_t encrypt_ptr = (encrypt_ptr_t)GetProcAddress(handle, "encrypt");
        if (encrypt_ptr == nullptr) {
            cout << "Encrypt function not found" << endl;
        }
    }

    char* decrypt(char* encryptedText, int key) {
        typedef char* (*decrypt_ptr_t)(char*, int);
        decrypt_ptr_t decrypt_ptr = (decrypt_ptr_t)GetProcAddress(handle, "decrypt");
        if (decrypt_ptr == nullptr) {
            cout << "Decrypt function not found" << endl;
        }
    }
};