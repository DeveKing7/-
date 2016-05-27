//
//  DES3Util.m
//  DES
//
//  Created by Toni on 12-12-27.
//  Copyright (c) 2012年 sinofreely. All rights reserved.
//

#import "DES3Util.h"
#define gkey            @"app_key_ioved1cm!@#$5678"
//#define gkey            @"liuyunqiang@lx100$#365#$"
#define gIv             @"01234567"
#import "GTMBase64.h"
#include <CommonCrypto/CommonCryptor.h>

@implementation DES3Util


 const Byte iv[] = {1,2,3,4,5,6,7,8};

////Des加密
// +(NSString *) encryptUseDES:(NSString *)plainText key:(NSString *)key
// {
//    
//     NSString *ciphertext = nil;
//     NSData *textData = [plainText dataUsingEncoding:NSUTF8StringEncoding];
//     NSUInteger dataLength = [textData length];
//     unsigned char buffer[1024];
//     memset(buffer, 0, sizeof(char));
//     size_t numBytesEncrypted = 0;
//     CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt, kCCAlgorithmDES,
//                                                kCCOptionPKCS7Padding,
//                                              [key UTF8String], kCCKeySizeDES,
//                                                            iv,
//                                                [textData bytes], dataLength,
//                                                        buffer, 1024,
//                                                    &numBytesEncrypted);
//         if (cryptStatus == kCCSuccess) {
//                 NSData *data = [NSData dataWithBytes:buffer length:(NSUInteger)numBytesEncrypted];
//                 ciphertext = [GTMBase64 stringByEncodingData:data];
//             }
//     
//     
//         return ciphertext;
//     }
//
//
//
////Des解密
// +(NSString *)decryptUseDES:(NSString *)cipherText key:(NSString *)key
// {
//      NSString *plaintext = nil;
//        NSData *cipherdata = [GTMBase64 decodeString:cipherText];
// //    NSData * cipherdata = [cipherText dataUsingEncoding:NSUTF8StringEncoding];
//     
//         unsigned char buffer[1024];
//         memset(buffer, 0, sizeof(char));
//         size_t numBytesDecrypted = 0;
//         CCCryptorStatus cryptStatus = CCCrypt(kCCDecrypt, kCCAlgorithmDES,
//                                                           kCCOptionPKCS7Padding,
//                                                           [key UTF8String], kCCKeySizeDES,
//                                                           iv,
//                                                           [cipherdata bytes], [cipherdata length],
//                                                           buffer, 1024,
//                                                           &numBytesDecrypted);
//         if(cryptStatus == kCCSuccess)
//         {
//                NSData *plaindata = [NSData dataWithBytes:buffer length:(NSUInteger)numBytesDecrypted];
//                 plaintext = [[NSString alloc]initWithData:plaindata encoding:NSUTF8StringEncoding];
//         }
//     return plaintext;
//     }
//+ (NSString *) encryptUseDES:(NSString *)plainText key:(NSString *)key
//{
//    NSString *ciphertext = nil;
//    const char *textBytes = [plainText UTF8String];
//    NSUInteger dataLength = [plainText length];
//    unsigned char buffer[1024];
//    memset(buffer, 0, sizeof(char));
//    Byte iv[] = {1,2,3,4,5,6,7,8};
//    size_t numBytesEncrypted = 0;
//    CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt, kCCAlgorithmDES,
//                                          kCCOptionPKCS7Padding,
//                                          [key UTF8String], kCCKeySizeDES,
//                                          iv,
//                                          textBytes, dataLength,
//                                          buffer, 1024,
//                                          &numBytesEncrypted);
//    if (cryptStatus == kCCSuccess) {
//        NSData *data = [NSData dataWithBytes:buffer length:(NSUInteger)numBytesEncrypted];
//        
//        ciphertext = [[NSString alloc] initWithData:[GTMBase64 encodeData:data] encoding:NSUTF8StringEncoding];
//    }
//    return ciphertext;
//}
//
////解密
//+ (NSString *) decryptUseDES:(NSString*)cipherText key:(NSString*)key
//{
//    NSData* cipherData = [GTMBase64 decodeString:cipherText];
//    unsigned char buffer[1024];
//    memset(buffer, 0, sizeof(char));
//    size_t numBytesDecrypted = 0;
//    Byte iv[] = {1,2,3,4,5,6,7,8};
//    CCCryptorStatus cryptStatus = CCCrypt(kCCDecrypt,
//                                          kCCAlgorithmDES,
//                                          kCCOptionPKCS7Padding,
//                                          [key UTF8String],
//                                          kCCKeySizeDES,
//                                          iv,
//                                          [cipherData bytes],
//                                          [cipherData length],
//                                          buffer,
//                                          1024,
//                                          &numBytesDecrypted);
//    NSString* plainText = nil;
//    if (cryptStatus == kCCSuccess) {
//        NSData* data = [NSData dataWithBytes:buffer length:(NSUInteger)numBytesDecrypted];
//        plainText = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
//    }
//    return plainText;
//}
+(NSString*) decryptUseDES:(NSString*)cipherText key:(NSString*)key {
    // 利用 GTMBase64 解碼 Base64 字串
    NSData* cipherData = [GTMBase64 decodeString:cipherText];
    unsigned char buffer[1024];
    memset(buffer, 0, sizeof(char));
    size_t numBytesDecrypted = 0;
    
    // IV 偏移量不需使用
    CCCryptorStatus cryptStatus = CCCrypt(kCCDecrypt,
                                          kCCAlgorithmDES,
                                          kCCOptionPKCS7Padding | kCCOptionECBMode,
                                          [key UTF8String],
                                          kCCKeySizeDES,
                                          nil,
                                          [cipherData bytes],
                                          [cipherData length],
                                          buffer,
                                          1024,
                                          &numBytesDecrypted);
    NSString* plainText = nil;
    if (cryptStatus == kCCSuccess) {
        NSData* data = [NSData dataWithBytes:buffer length:(NSUInteger)numBytesDecrypted];
        plainText = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    }
    return plainText;
}
+(NSString *) encryptUseDES:(NSString *)clearText key:(NSString *)key
{
    NSData *data = [clearText dataUsingEncoding:NSUTF8StringEncoding allowLossyConversion:YES];
    unsigned char buffer[1024];
    memset(buffer, 0, sizeof(char));
    size_t numBytesEncrypted = 0;
    
    CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt,
                                          kCCAlgorithmDES,
                                          kCCOptionPKCS7Padding | kCCOptionECBMode,
                                          [key UTF8String],
                                          kCCKeySizeDES,
                                          nil,
                                          [data bytes],
                                          [data length],
                                          buffer,
                                          1024,
                                          &numBytesEncrypted);
    
    NSString* plainText = nil;
    if (cryptStatus == kCCSuccess) {
        NSData *dataTemp = [NSData dataWithBytes:buffer length:(NSUInteger)numBytesEncrypted];
        plainText = [GTMBase64 stringByEncodingData:dataTemp];
    }else{
        NSLog(@"DES加密失败");
    }
    return plainText;
}


@end
