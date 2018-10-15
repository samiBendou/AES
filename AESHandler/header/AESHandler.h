//
// Created by Sami Dahoux on 15/10/2018.
//

#ifndef AES_AES_H
#define AES_AES_H

#include <ByteMatrix.h>

typedef unsigned long uc_t;

class AESHandler {
public :

    AESHandler();

    ByteMatrix chiper(const ByteMatrix& plain, const ByteMatrix& key);

protected:

    void addRoundKey();

    void subBytes();

    void shiftRows();

    void mixColumns();

    void keyExpansion();

    ByteMatrix _state;

    uc_t _round;

    uc_t _n_r;
};


#endif //AES_AES_H
