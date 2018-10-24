//
// Created by Sami Dahoux on 15/10/2018.
//

#include <AESByte.h>

#include "AESByte.h"

AESByte::AESByte(char val) : _val((uc_t) val){

}

AESByte::AESByte(int val) : _val((uc_t) abs(val) % 256){

}

AESByte::AESByte(double val) : _val(((uc_t) floor(fabs(val))) % 256){

}

uc_t AESByte::val() const {
    return _val;
}

void AESByte::xtime() {
    _val = (_val & (uc_t) 0x80) ? ((_val << 1) ^ (uc_t) 0x1b) : (_val << 1);
}

void AESByte::add(const AESByte &b) {
    _val ^= b._val;
}

void AESByte::prod(const AESByte &b) {
    AESByte copy{*this};
    for (int k = 0; k < b._val / 2; ++k) {
        xtime();
    }
    if(b._val % 2 != 0 && b != 1) {
        add(copy);
    }
}

AESByte AESByte::operator+(const AESByte &b) {
    AESByte res{*this};
    res += b;
    return res;
}

AESByte AESByte::operator-(const AESByte &b) {
    AESByte res{*this};
    res -= b;
    return res;
}

AESByte AESByte::operator-() const {
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

AESByte &AESByte::operator-=(const AESByte &b) {
    add(b);
    return *this;
}

AESByte &AESByte::operator*=(const AESByte &b) {
    prod(b);
    return *this;
}

AESByte &AESByte::operator/=(const AESByte &b) {
    // TODO: Implement Euclide's extended algorithm in Gallois Field
    return *this;
}

bool operator==(const AESByte &b1, const AESByte &b2) {
    return b1._val == b2._val;
}

bool operator!=(const AESByte &b1, const AESByte &b2) {
    return b1._val != b2._val;
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

std::ostream &operator<<(std::ostream &os, const AESByte &b) {
    char buffer[5];
    sprintf(buffer, "0x%02x", (ui_t) b._val);
    os << buffer;
    return os;
}


AESByte abs(const AESByte &b) {
    return b;
}

AESByte sqrt(const AESByte &b) {
    return {sqrt(b._val)};
}





