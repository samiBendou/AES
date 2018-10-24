#include <iostream>
#include <NVector.h>
#include <NPMatrix.h>
#include <AESHandler.h>

using namespace std;

int main() {
    mat_aes_t cipher{vector<AESByte>({0x32, 0x88, 0x31, 0xe0,
                                      0x43, 0x5a, 0x31, 0x37,
                                      0xf6, 0x30, 0x98, 0x07,
                                      0xa8, 0x8d, 0xa2, 0x34}), 4, 4};

    mat_aes_t key{vector<AESByte>({0x2b, 0x28, 0xab, 0x09,
                                   0x7e, 0xae, 0xf7, 0xcf,
                                   0x15, 0xd2, 0x15, 0x4f,
                                   0x16, 0xa6, 0x88, 0x3c}), 4, 4};

    mat_aes_t res;

    cout << cipher << endl;

    AESHandler handler;
    res = handler.encrypt(cipher, key);

    cout << res << endl;

    return 0;
}