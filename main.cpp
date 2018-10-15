#include <iostream>
#include <AESByte.h>
#include <ByteMatrix.h>
#include <AESHandler.h>

int main() {
    NPMatrix<AESByte> mat{NPMatrix<AESByte>::zeros(4)};
    std::cout << mat << std::endl;
    return 0;
}