//
// Created by Sami Dahoux on 15/10/2018.
//

#ifndef AES_AES_H
#define AES_AES_H

#include <NPMatrix.h>

#define MAX_N_R 14
#define N_ROWS_STATE 4

typedef NPMatrix<AESByte> mat_aes_t;

typedef NVector<AESByte> vec_aes_t;

class AESHandler {
public:

    enum AESType {
        AES128, AES192, AES256
    };


    AESHandler(AESType type = AES128);

    mat_aes_t encrypt(const mat_aes_t &plain, const mat_aes_t &key);

protected:

    AESHandler(uc_t n_b, uc_t n_k, uc_t n_r);

    void addRoundKey();

    void subWord(vec_aes_t &block_col);

    void subBytes(mat_aes_t &block);

    void rotWord(vec_aes_t &block_col);

    void shiftRows();

    void mixColumns();

    void keyExpansion(const mat_aes_t &key);

    // MEMBERS

    mat_aes_t _state;

    mat_aes_t _round_key;

    uc_t _round;

    uc_t _n_b;

    uc_t _n_k;

    uc_t _n_r;

    // STATIC FUNCTIONS

    static mat_aes_t RCon();

    // STATIC CONSTANT

    const static vec_aes_t s_box;

    const static mat_aes_t mat_mix_columns;

    const static mat_aes_t r_con;
};


#endif //AES_AES_H
