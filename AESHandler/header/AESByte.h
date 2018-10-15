//
// Created by Sami Dahoux on 15/10/2018.
//

#ifndef AESTEST_AESBYTE_H
#define AESTEST_AESBYTE_H

typedef unsigned long uc_t;

class AESByte {

public:

    AESByte(char val = 0x00);

    AESByte operator+(const AESByte& b);

    AESByte operator-() const;

    friend AESByte operator*(const AESByte& b1, const AESByte& b2);

    friend bool operator>(const AESByte& b1, const AESByte& b2);

    friend bool operator<(const AESByte& b1, const AESByte& b2);

    friend bool operator>=(const AESByte& b1, const AESByte& b2);

    friend bool operator<=(const AESByte& b1, const AESByte& b2);

    AESByte& operator+=(const AESByte& b);

    AESByte& operator*=(const AESByte& b);

    AESByte&operator -=(const AESByte& b);

    AESByte&operator /=(const AESByte& b);

private:

    void xtime();

    void add(const AESByte& b);

    void prod(const AESByte& b);

    uc_t _val;
};


AESByte abs(const AESByte& b);

#endif //AESTEST_AESBYTE_H
