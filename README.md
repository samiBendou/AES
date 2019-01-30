# AES 0.5.0
C++ interface simple for AES encryption and decryption. Designed both as useful AES tolbox for production and efficient research tool for cryptanalysis

### Featuring
  - Block encrypt and decrypt tools for AES 126, 192 and 256 bits.
  - Scallable block : change block size parameter
  - Highly customizable : code structure designed to easily implement new/different operations
  - High level code structure using NAlgebra module from [MathToolKitCPP](https://github.com/samiBendou/MathToolKitCPP)

### Install
  - Clone the project
  - Copy the AESHandler directory in the project you wanto import
  
### Getting Started
The module performs AES operations using a `AESHandler` object which carries both the atom operations such as `ShiftRows` and the API.
The `AESHandler` stores the key and message block as matrices. 

#### Encryption
To perform encryption of a block few lines are required :

- Instantiate a plain text and key matrix :
```cpp
mat_aes_t plain{
                  {0x00, 0x44, 0x88, 0xcc},
                  {0x11, 0x55, 0x99, 0xdd},
                  {0x22, 0x66, 0xaa, 0xee},
                  {0x33, 0x77, 0xbb, 0xff}
                };


mat_aes_t key{ 
                {0x00, 0x04, 0x08, 0x0c},
                {0x01, 0x05, 0x09, 0x0d},
                {0x02, 0x06, 0x0a, 0x0e},
                {0x03, 0x07, 0x0b, 0x0f}
              };
```
- Instantiate a handler and call `encrypt()` method :
```cpp
AESHandler hander{};
mat_aes_t cipher = handler.encrypt(plain, key);
```

#### Decryption
Decryption is performed exactly the same way as encryption but us `decrypt()` method instead of `encrypt()`.

