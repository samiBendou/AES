//
// Created by Sami Dahoux on 15/10/2018.
//

#ifndef AES_AES_H
#define AES_AES_H

#include <NPMatrix.h>

#define MAX_N_R 14
#define N_ROWS_STATE 4

class AESHandler {
public:

    enum AESType {
        AES128, AES192, AES256
    };


    AESHandler(AESType type = AES128);

    mat_aes_t encrypt(const mat_aes_t &plain, const mat_aes_t &key);

    mat_aes_t decrypt(const mat_aes_t &cipher, const mat_aes_t &key);

protected:

    AESHandler(uc_t n_b, uc_t n_k, uc_t n_r);

    // ENCRYPTION PROCESS

    void addRoundKey();

    void subWord(vec_aes_t &block_col);

    void subBytes(mat_aes_t &block);

    void rotWord(vec_aes_t &block_col);

    void shiftRows();

    void mixColumns();

    void keyExpansion(const mat_aes_t &key);

    // DECRYTION PROCESS

    void invSubBytes(mat_aes_t &block);

    void invShiftRows();

    void invMixColumns();

    // MEMBERS

    mat_aes_t _state;

    mat_aes_t _round_key;

    uc_t _round;

    uc_t _n_b;

    uc_t _n_k;

    uc_t _n_r;

    // STATIC CONSTANT

    const static vec_aes_t s_box;

    const static vec_aes_t inv_s_box;

    const static mat_aes_t mat_mix_columns;

    const static mat_aes_t inv_mat_mix_columns;

    const static mat_aes_t r_con;
};


#endif //AES_AES_H
