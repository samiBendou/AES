#include <iostream>
#include <AESHandler.h>

using namespace std;

int main() {

    AESHandler handler;

    cout << "*ENCRYPTION*" << endl;

    mat_aes_t cipher{{0x00, 0x44, 0x88, 0xcc},
                     {0x11, 0x55, 0x99, 0xdd},
                     {0x22, 0x66, 0xaa, 0xee},
                     {0x33, 0x77, 0xbb, 0xff}};

    mat_aes_t key128{{0x00, 0x04, 0x08, 0x0c},
                     {0x01, 0x05, 0x09, 0x0d},
                     {0x02, 0x06, 0x0a, 0x0e},
                     {0x03, 0x07, 0x0b, 0x0f}};

    cout << "*AES128*" << endl;
    cout << "input :" << endl;
    cout << cipher << endl;
    cout << "key :" << endl;
    cout << key128 << endl;
    cout << "output :" << endl;
    cout << handler.encrypt(cipher, key128) << endl;

    cipher = {{0x69, 0x6a, 0xd8, 0x70},
              {0xc4, 0x7b, 0xcd, 0xb4},
              {0xe0, 0x04, 0xb7, 0xc5},
              {0xd8, 0x30, 0x80, 0x5a}};

    cout << "*AES128*" << endl;
    cout << "input :" << endl;
    cout << cipher << endl;
    cout << "key :" << endl;
    cout << key128 << endl;
    cout << "output :" << endl;
    cout << handler.decrypt(cipher, key128) << endl;

    return 0;
}