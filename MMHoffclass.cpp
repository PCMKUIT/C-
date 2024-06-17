// g++ -g3 -ggdb -O0 -DDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread
// g++ -g -O2 -DNDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread
#include "pch.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdlib>
#include <locale>
#include <cctype>

#ifndef DLL_EXPORT
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
#endif

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::getline;
#include <cryptopp/queue.h>
using CryptoPP::ByteQueue;
#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "cryptopp/cryptlib.h"
using CryptoPP::Exception;
using CryptoPP::DecodingResult;
using CryptoPP::PrivateKey;
using CryptoPP::PublicKey;
using CryptoPP::BufferedTransformation;

#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;
#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::ArraySink;
using CryptoPP::ArraySource;
#include "cryptopp/aes.h"
using CryptoPP::AES;

#include "cryptopp/modes.h"
using CryptoPP::CBC_Mode;
using CryptoPP::CFB_Mode;
using CryptoPP::CTR_Mode;
#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;


#include <cryptopp/files.h>
using CryptoPP::FileSource;
using CryptoPP::FileSink;
extern "C" {
	DLL_EXPORT void GenerateAndSaveAESKeys(int keysize,const char* format,const char* filename);
	DLL_EXPORT void AESencrypt(const char* mode, const char* keyfile, const char* keyformat, const char* plaintextfile, const char* plaintextformat, const char* ciphertextfile, const char* ciphetextformat);
	DLL_EXPORT void AESdecrypt(const char* mode, const char* keyfile, const char* keyformat, const char* ciphertextfile, const char* ciphertextformat);
} 

void GenerateAndSaveAESKeys(int keysize,const char* format,const char* filename){
		string strFormat(format);
		string strfilename(filename);
        
		AutoSeededRandomPool prng;
        CryptoPP::SecByteBlock key(keysize);
		prng.GenerateBlock(key, keysize);
        CryptoPP::byte iv[AES::BLOCKSIZE]; 
		prng.GenerateBlock(iv, AES::BLOCKSIZE);
		
        string outputkey,outputvi;
        StringSource(key, keysize, true,(new FileSink(filename)));

		StringSource(iv, AES::BLOCKSIZE, true,(new FileSink("iv.bin")));
		
		if (strFormat == "Hex") {
            
			StringSource(key,keysize, true,new HexEncoder(new StringSink(outputkey)));

			StringSource(iv,AES::BLOCKSIZE, true,new HexEncoder(new StringSink(outputvi)));
            cout<<"Key: "<<outputkey<<endl<<"Vi: "<<outputvi<<endl;
		}
		else if (strFormat == "Base64") {
		    StringSource(key, keysize, true,new Base64Encoder(new StringSink(outputkey)));

			StringSource(iv, AES::BLOCKSIZE, true,new Base64Encoder(new StringSink(outputvi)));
            cout<<"Key: "<<outputkey<<endl<<"Vi: "<<outputvi<<endl;
		}
		else {
			std::cerr << "Unsupported format. Please choose 'Hex' or 'Base64'." << std::endl;
			return;
		}			
}

void AESencrypt(const char* mode, const char* keyfile, const char* keyformat, const char* plaintextfile, const char* plaintextformat, const char* ciphertextfile, const char* ciphetextformat) {
    string plaintext;
    FileSource(plaintextfile, true, new StringSink(plaintext));
 
    CryptoPP::byte key[AES::DEFAULT_KEYLENGTH];
    FileSource(keyfile,  true,
        new ArraySink(key,sizeof(key)),true
    );

    CryptoPP::byte iv[AES::BLOCKSIZE]; //key=128
    FileSource("iv.bin",  true,
        new ArraySink(iv,sizeof(iv)),true
    );

    string strmode(mode);
    string strCipher(ciphetextformat);
    
    if (strmode == "CTR") {
        CTR_Mode<AES>::Encryption e;
        e.SetKeyWithIV(key, sizeof(key), iv);
            
        if (strCipher == "Hex") {
            StringSource(plaintext, true, new StreamTransformationFilter(e, new HexEncoder(new FileSink(ciphertextfile))));
            
        } else if (strCipher == "Base64") {
            StringSource(plaintext, true, new StreamTransformationFilter(e, new Base64Encoder(new FileSink(ciphertextfile))));
        }
    } else if (strmode == "CBC") {
        CBC_Mode<AES>::Encryption e;
        e.SetKeyWithIV(key, sizeof(key), iv);

        if (strCipher == "Hex") {
            StringSource(plaintext, true, new StreamTransformationFilter(e, new HexEncoder(new FileSink(ciphertextfile))));
        } else if (strCipher == "Base64") {
            StringSource(plaintext, true, new StreamTransformationFilter(e, new Base64Encoder(new FileSink(ciphertextfile))));
        }
    }
}

void AESdecrypt(const char* mode, const char* keyfile, const char* keyformat, const char* ciphertextfile, const char* ciphertextformat) {
    CryptoPP::byte key[AES::DEFAULT_KEYLENGTH];
    FileSource(keyfile, true, new ArraySink(key, sizeof(key)), true);

    CryptoPP::byte iv[AES::BLOCKSIZE];
    FileSource("iv.bin", true, new ArraySink(iv, sizeof(iv)), true);

    string strmode(mode);
    string recovered,cipher,encoded;
    cipher.clear();
    string strCipher(ciphertextformat);
    FileSource(ciphertextfile, true, new StringSink(cipher));
    if (strmode == "CTR") {
        CTR_Mode<AES>::Decryption d;
        d.SetKeyWithIV(key, sizeof(key), iv);

        if (strCipher == "Hex") {
            encoded.clear();
            StringSource(cipher, true,new HexDecoder(new StringSink(encoded)));
            StringSource(encoded, true, new StreamTransformationFilter(d, new StringSink(recovered)));
            cout << "Recovered text CTR-Hex: " << recovered << endl;
        } else if (strCipher == "Base64") {
             encoded.clear();
            StringSource(cipher, true,new Base64Decoder(new StringSink(encoded)));
            StringSource(encoded, true, new StreamTransformationFilter(d, new StringSink(recovered)));
            cout << "Recovered text CTR-Base64: " << recovered << endl;
        }
    } else if (strmode == "CBC") {
        CBC_Mode<AES>::Decryption d;
        d.SetKeyWithIV(key, sizeof(key), iv);

        if (strCipher == "Hex") {
            encoded.clear();
            StringSource(cipher, true,new HexDecoder(new StringSink(encoded)));
            StringSource(encoded, true, new StreamTransformationFilter(d, new StringSink(recovered)));
            cout << "Recovered text CBC-Hex: " << recovered << endl;
        } else if (strCipher == "Base64") {
           encoded.clear();
            StringSource(cipher, true,new Base64Decoder(new StringSink(encoded)));
            StringSource(encoded, true, new StreamTransformationFilter(d, new StringSink(recovered)));
            cout << "Recovered text CBC-Base64: " << recovered << endl;
        }
    }
    std::ofstream file("Output.txt");
    if(file.is_open()){
        file<<recovered;
        file.close();
    }
}


int main(int argc, char* argv[])
{
	// Set locale to support UTF-8
	#ifdef linux
	std::locale::global(std::locale("C.utf8"));
	#endif
	
	#ifdef _WIN32
	// Set console code page to UTF-8 on Windows C.utf8, CP_UTF8
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif
	if (argc < 2) {
		cerr << "Usage: \n"
			<< argv[0] << " keygen <key_length> <output_format> <filename> \n"
			<< argv[0] << " encrypt <mode> <keyfile> <keyformat> <plaintextfile> <plaintextformat> <ciphertextfile> <ciphertextformat>\n"
			<< argv[0] << " decrypt <mode> <keyfile> <keyformat> <ciphertextfile> <ciphertextformat>\n";
			
		return -1;
	}

	string action=argv[1];
	if (action == "keygen" && argc == 5)
	{
		int keySize = std::stoi(argv[2]);
		GenerateAndSaveAESKeys(keySize, argv[3], argv[4]);
		
	}else if(action=="encrypt" && argc==9){
		AESencrypt(argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8]);
	}else if(action=="decrypt" && argc==7){
		AESdecrypt(argv[2],argv[3],argv[4],argv[5],argv[6]);
	}
}
