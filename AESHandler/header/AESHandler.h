//
// Created by Sami Dahoux on 15/10/2018.
//

#ifndef AES_AES_H
#define AES_AES_H

#include <NPMatrix.h>

typedef NPMatrix<AESByte> mat_aes_t;

typedef NVector<AESByte> vec_aes_t;

class AESHandler {
public :

    AESHandler(uc_t n_b = 4, uc_t n_k = 4, uc_t n_r = 10);

    mat_aes_t encrypt(const mat_aes_t &plain, const mat_aes_t &key);

    // PROTECTED

    void addRoundKey();

    void subBytes(vec_aes_t &block_col);

    void subBytes(mat_aes_t &block);

    void shiftRows();

    void mixColumns();

    void keyExpansion();

    mat_aes_t _state;

    mat_aes_t _round_key;

    uc_t _round;

    uc_t _n_b;

    uc_t _n_k;

    uc_t _n_r;

    // STATIC CONSTANT

    vec_aes_t s_box;

    mat_aes_t mat_mix_columns;

    mat_aes_t r_con;
};


#endif //AES_AES_H
