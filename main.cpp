#include <iostream>
#include "AESByte.h"
#include <ByteMatrix.h>
#include <AESHandler.h>

int main() {

    NVector<AESByte> vec{NVector<AESByte>::ones(4)};
    NPMatrix<AESByte> mat{NPMatrix<AESByte>::scalar(1, 4)};

    std::cout << vec << std::endl;
    std::cout << mat + 6 * mat << std::endl;

    return 0;
}