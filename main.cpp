#include <iostream>
#include <NVector.h>
#include <NPMatrix.h>
#include <AESHandler.h>

using namespace std;

int main() {

    AESHandler handler;

    mat_aes_t cipher{vector<AESByte>({0x00, 0x44, 0x88, 0xcc,
                                      0x11, 0x55, 0x99, 0xdd,
                                      0x22, 0x66, 0xaa, 0xee,
                                      0x33, 0x77, 0xbb, 0xff}), 4, 4};

    mat_aes_t key128{vector<AESByte>({0x00, 0x04, 0x08, 0x0c,
                                      0x01, 0x05, 0x09, 0x0d,
                                      0x02, 0x06, 0x0a, 0x0e,
                                      0x03, 0x07, 0x0b, 0x0f}), 4, 4};

    mat_aes_t res;

    cout << "*AES128*" << endl;
    cout << "input :" << endl;
    cout << cipher << endl;
    cout << "key :" << endl;
    cout << key128 << endl;
    cout << "output :" << endl;
    cout << handler.encrypt(cipher, key128) << endl;


    handler = AESHandler(AESHandler::AES192);

    mat_aes_t key192{vector<AESByte>({0x00, 0x04, 0x08, 0x0c, 0x10, 0x14,
                                      0x01, 0x05, 0x09, 0x0d, 0x11, 0x15,
                                      0x02, 0x06, 0x0a, 0x0e, 0x12, 0x16,
                                      0x03, 0x07, 0x0b, 0x0f, 0x13, 0x17}), 4, 6};

    cout << "*AES192*" << endl;
    cout << "input :" << endl;
    cout << cipher << endl;
    cout << "key :" << endl;
    cout << key192 << endl;
    cout << "output :" << endl;
    cout << handler.encrypt(cipher, key192) << endl;



    handler = AESHandler(AESHandler::AES256);

    mat_aes_t key256{vector<AESByte>({0x00, 0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c,
                                0x01, 0x05, 0x09, 0x0d, 0x11, 0x15, 0x19, 0x1d,
                                0x02, 0x06, 0x0a, 0x0e, 0x12, 0x16, 0x1a, 0x1e,
                                0x03, 0x07, 0x0b, 0x0f, 0x13, 0x17, 0x1b, 0x1f}), 4, 8};

    cout << "*AES256*" << endl;
    cout << "input :" << endl;
    cout << cipher << endl;
    cout << "key :" << endl;
    cout << key256 << endl;
    cout << "output :" << endl;
    cout << handler.encrypt(cipher, key256) << endl;



    return 0;
}