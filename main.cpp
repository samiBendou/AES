#include <iostream>
#include <NVector.h>
#include <NPMatrix.h>
#include <AESHandler.h>

using namespace std;

int main() {

    AESHandler handler;

    mat_aes_t cipher128{vector<AESByte>({0x32, 0x88, 0x31, 0xe0,
                                         0x43, 0x5a, 0x31, 0x37,
                                         0xf6, 0x30, 0x98, 0x07,
                                         0xa8, 0x8d, 0xa2, 0x34}), 4, 4};

    mat_aes_t key128{vector<AESByte>({0x2b, 0x28, 0xab, 0x09,
                                      0x7e, 0xae, 0xf7, 0xcf,
                                      0x15, 0xd2, 0x15, 0x4f,
                                      0x16, 0xa6, 0x88, 0x3c}), 4, 4};

    mat_aes_t res;

    cout << "*AES128*" << endl;
    cout << "input :" << endl;
    cout << cipher128 << endl;
    cout << "key :" << endl;
    cout << key128 << endl;
    cout << "output :" << endl;
    cout << handler.encrypt(cipher128, key128) << endl;


    handler = AESHandler(4, 6, 12);

    mat_aes_t cipher192{vector<AESByte>({0x00, 0x44, 0x88, 0xcc,
                                         0x11, 0x55, 0x99, 0xdd,
                                         0x22, 0x66, 0xaa, 0xee,
                                         0x33, 0x77, 0xbb, 0xff}), 4, 4};

    mat_aes_t key192{vector<AESByte>({0x00, 0x04, 0x08, 0x0c, 0x10, 0x14,
                                      0x01, 0x05, 0x09, 0x0d, 0x11, 0x15,
                                      0x02, 0x06, 0x0a, 0x0e, 0x12, 0x16,
                                      0x03, 0x07, 0x0b, 0x0f, 0x13, 0x17}), 4, 6};

    cout << "*AES192*" << endl;
    cout << "input :" << endl;
    cout << cipher192 << endl;
    cout << "key :" << endl;
    cout << key192 << endl;
    cout << "output :" << endl;
    cout << handler.encrypt(cipher192, key192) << endl;


    return 0;
}