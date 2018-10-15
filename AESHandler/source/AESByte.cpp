//
// Created by Sami Dahoux on 15/10/2018.
//

#include <AESByte.h>

#include "AESByte.h"

AESByte::AESByte(char val) : _val(val){

}

void AESByte::xtime() {
    this->_val = (_val & (char) 0x80) ? ((_val << 1) ^ (char) 0x1b) : (_val << 1);
}

void AESByte::add(const AESByte &b) {
    this->_val ^= b._val;
}

void AESByte::prod(const AESByte &b) {
    for (int k = 0; k < b._val / 2; ++k) {
        xtime();
    }
    if(b._val % 2 != 0) {
        add(*this);
    }
}

AESByte AESByte::operator+(const AESByte &b) {
    AESByte res{*this};
    res.add(b);
    return res;
}

AESByte AESByte::operator-() const {
    // WARNING : Not yet implemented
    return *this;
}

AESByte operator*(const AESByte &b1, const AESByte &b2) {
    AESByte res{b1};
    res.prod(b2);
    return res;
}

AESByte &AESByte::operator+=(const AESByte &b) {
    add(b);
    return *this;
}

AESByte &AESByte::operator*=(const AESByte &b) {
    prod(b);
    return *this;
}

bool operator<=(const AESByte &b1, const AESByte &b2) {
    return b1._val <= b2._val;
}

bool operator<(const AESByte &b1, const AESByte &b2) {
    return  b1._val < b2._val;
}

bool operator>(const AESByte &b1, const AESByte &b2) {
    return  b1._val > b2._val;
}

bool operator>=(const AESByte &b1, const AESByte &b2) {
    return b1._val >= b2._val;
}

AESByte &AESByte::operator-=(const AESByte &b) {
    // WARNING : Not yet implemented
    return *this;
}

AESByte &AESByte::operator/=(const AESByte &b) {
    // WARNING : Not yet implemented
    return *this;
}


AESByte abs(const AESByte &b) {
    return b;
}





