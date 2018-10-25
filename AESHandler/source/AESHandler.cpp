//
// Created by Sami Dahoux on 15/10/2018.
//

#include <AESHandler.h>

#include "AESHandler.h"

using namespace std;

const vec_aes_t AESHandler::s_box = vec_aes_t(vector<AESByte>({
                                                                      0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5,
                                                                      0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
                                                                      0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0,
                                                                      0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
                                                                      0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc,
                                                                      0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
                                                                      0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a,
                                                                      0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
                                                                      0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0,
                                                                      0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
                                                                      0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b,
                                                                      0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
                                                                      0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85,
                                                                      0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
                                                                      0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5,
                                                                      0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
                                                                      0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17,
                                                                      0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
                                                                      0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88,
                                                                      0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
                                                                      0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c,
                                                                      0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
                                                                      0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9,
                                                                      0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
                                                                      0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6,
                                                                      0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
                                                                      0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e,
                                                                      0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
                                                                      0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94,
                                                                      0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
                                                                      0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68,
                                                                      0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
                                                              }));

const mat_aes_t AESHandler::mat_mix_columns = mat_aes_t(std::vector<AESByte>{
        0x02, 0x03, 0x01, 0x01,
        0x01, 0x02, 0x03, 0x01,
        0x01, 0x01, 0x02, 0x03,
        0x03, 0x01, 0x01, 0x02}, N_ROWS_STATE, N_ROWS_STATE);

const mat_aes_t AESHandler::r_con = AESHandler::RCon();


AESHandler::AESHandler(AESType type) {
    switch (type) {
        case AES128 :
            *this = AESHandler(4, 4, 10);
            break;
        case AES192:
            *this = AESHandler(4, 6, 12);
            break;
        case AES256:
            *this = AESHandler(4, 8, 14);
            break;
    }
}

AESHandler::AESHandler(uc_t n_b, uc_t n_k, uc_t n_r) : _state(mat_aes_t()), _round_key(mat_aes_t()), _round(0),
                                                       _n_b(n_b), _n_k(n_k), _n_r(n_r) {}


mat_aes_t AESHandler::encrypt(const mat_aes_t &plain, const mat_aes_t &key) {

    assert(plain.n() == N_ROWS_STATE && plain.p() == _n_b);
    assert(key.n() == N_ROWS_STATE && key.p() == _n_k);

    _state = plain;
    keyExpansion(key);
    addRoundKey();

    _round = 1;

    while (_round <= _n_r) {
        subBytes(_state);
        shiftRows();

        if (_round <= _n_r - 1) {
            mixColumns();
        }
        addRoundKey();
        ++_round;
    }

    return _state;
}

void AESHandler::addRoundKey() {
    _state += _round_key(0, _n_b * _round, 3, _n_b * (_round + 1) - 1);
}


void AESHandler::subWord(vec_aes_t &block_col) {
    for (uc_t k = 0; k < N_ROWS_STATE; ++k) {
        block_col(k) = s_box(block_col(k).val());
    }
}

void AESHandler::subBytes(mat_aes_t &block) {
    for (uc_t i = 0; i < N_ROWS_STATE; ++i) {
        for (uc_t j = 0; j < _n_b; ++j) {
            block(i, j) = s_box(block(i, j).val());
        }
    }
}

void AESHandler::rotWord(vec_aes_t &block_col) {
    block_col.shift(1);
}

void AESHandler::shiftRows() {
    for (uc_t i = 0; i < N_ROWS_STATE; ++i) {
        _state.shiftRow(i, i);
    }
}

void AESHandler::mixColumns() {
    _state = mat_mix_columns * _state;
}

void AESHandler::keyExpansion(const mat_aes_t &key) {


    _round_key = mat_aes_t::zeros(N_ROWS_STATE, _n_b * (_n_r + 1));
    _round_key(0, 0, 3, _n_k - 1) = key;

    vec_aes_t round_key_col;

    for (uc_t k = _n_k; k < _n_b * (_n_r + 1); ++k) {
        round_key_col = _round_key.col(k - 1);
        if (k % _n_k == 0) {
            rotWord(round_key_col);
            subWord(round_key_col);
            round_key_col += r_con.col(k / _n_k - 1);
        } else if (_n_k > 6 && k % _n_k == N_ROWS_STATE) {
            subWord(round_key_col);
        }
        round_key_col = _round_key.col(k - _n_k) + round_key_col;
        _round_key.setCol(round_key_col, k);
    }
}


mat_aes_t AESHandler::RCon() {
    vec_aes_t r_con_col = vec_aes_t::zeros(N_ROWS_STATE);
    mat_aes_t r_con = mat_aes_t(N_ROWS_STATE, MAX_N_R);

    r_con_col(0) = 0x01;
    r_con.setCol(r_con_col, 0);
    for (uc_t k = 1; k < MAX_N_R; ++k) {
        r_con_col(0) = r_con_col(0) * 0x02;
        r_con.setCol(r_con_col, k);
    }

    return r_con;
}





