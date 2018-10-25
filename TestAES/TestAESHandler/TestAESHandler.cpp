//
// Created by Bendou on 25/10/2018.
//

#include <AESHandler.h>
#include "gtest/gtest.h"

class AESHandlerTest : public ::testing::Test {

protected:
    mat_aes_t _plain{{0x00, 0x44, 0x88, 0xcc},
                     {0x11, 0x55, 0x99, 0xdd},
                     {0x22, 0x66, 0xaa, 0xee},
                     {0x33, 0x77, 0xbb, 0xff}};

    mat_aes_t _cipher128{{0x69, 0x6a, 0xd8, 0x70},
                         {0xc4, 0x7b, 0xcd, 0xb4},
                         {0xe0, 0x04, 0xb7, 0xc5},
                         {0xd8, 0x30, 0x80, 0x5a}};

    mat_aes_t _cipher192{{0xdd, 0x86, 0x6e, 0xec},
                         {0xa9, 0x4c, 0xaf, 0x0d},
                         {0x7c, 0xdf, 0x70, 0x71},
                         {0xa4, 0xe0, 0xa0, 0x91}};

    mat_aes_t _cipher256{{0x8e, 0x51, 0xea, 0x4b},
                         {0xa2, 0x67, 0xfc, 0x49},
                         {0xb7, 0x45, 0x49, 0x60},
                         {0xca, 0xbf, 0x90, 0x89}};

    mat_aes_t _key{{0x00, 0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c},
                   {0x01, 0x05, 0x09, 0x0d, 0x11, 0x15, 0x19, 0x1d},
                   {0x02, 0x06, 0x0a, 0x0e, 0x12, 0x16, 0x1a, 0x1e},
                   {0x03, 0x07, 0x0b, 0x0f, 0x13, 0x17, 0x1b, 0x1f}};

    AESHandler _handler;
};


TEST_F(AESHandlerTest, EncyrptAES128) {
    mat_aes_t key128{_key(0, 0, 3, 3)};
    ASSERT_EQ(_handler.encrypt(_plain, key128), _cipher128);
}

TEST_F(AESHandlerTest, EncyrptAES192) {
    _handler = AESHandler(AESHandler::AES192);
    mat_aes_t key192{_key(0, 0, 3, 5)};
    ASSERT_EQ(_handler.encrypt(_plain, key192), _cipher192);
}

TEST_F(AESHandlerTest, EncyrptAES256) {
    _handler = AESHandler(AESHandler::AES256);
    ASSERT_EQ(_handler.encrypt(_plain, _key), _cipher256);
}

TEST_F(AESHandlerTest, DecyrptAES128) {
    mat_aes_t key128{_key(0, 0, 3, 3)};
    ASSERT_EQ(_handler.decrypt(_cipher128, key128), _plain);
}

TEST_F(AESHandlerTest, DecyrptAES192) {
    _handler = AESHandler(AESHandler::AES192);
    mat_aes_t key192{_key(0, 0, 3, 5)};
    ASSERT_EQ(_handler.decrypt(_cipher192, key192), _plain);
}

TEST_F(AESHandlerTest, DecyrptAES256) {
    _handler = AESHandler(AESHandler::AES256);
    ASSERT_EQ(_handler.decrypt(_cipher256, _key), _plain);
}
