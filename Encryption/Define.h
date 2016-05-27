//
//  Define.h
//  Encryption
//
//  Created by 雷传营 on 16/1/10.
//  Copyright © 2016年 leichuanying. All rights reserved.
//

#define ENCRYPT_KEY     @"MfsKyo8IEMb"
#define RSA_Test_secret      @"lXOjdiMhPZjxDGF2eUzv7yD6zEFTLjyclrmPNTdMyEYCQC45d4ruo4QbV9jMN5lKfTxz3dxPIPaT06KxqU5CQVZqkX4Ttrw/anZencm4WnVUs96GIgpI3uY7ohOaG36Ak3cGvkQF6DvCO88MPrdS38DxUa2OSG4G5DVl4c74M4g="
#define RSA_Public_key  @"MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDR4tfXtdtbdgAG+zoTAjxzr5MYck3MecBn0zY4N5aqrlhWiXsOJniDMij5iQphSGPckIUQ5pgaZ0vbSHCGvFQztXnTDFgcAvsleywHIn+gfB/nYlf6hrduPGOS/NjUmeD6SXzeHQ68Y59M9OWQe1vq+3CzyPU18paYvl9aXvpWLQIDAQAB"
//私钥
#define RSA_Privite_key        @"MIICdgIBADANBgkqhkiG9w0BAQEFAASCAmAwggJcAgEAAoGBANHi19e121t2AAb7OhMCPHOvkxhyTcx5wGfTNjg3lqquWFaJew4meIMyKPmJCmFIY9yQhRDmmBpnS9tIcIa8VDO1edMMWBwC+yV7LAcif6B8H+diV/qGt248Y5L82NSZ4PpJfN4dDrxjn0z05ZB7W+r7cLPI9TXylpi+X1pe+lYtAgMBAAECgYBkIMT52n8gXeXbbsSgxuNSCUOyWO12i+rXXTKzlQliubPY7NNwx7ecVzSm/tKd4GwLkEJ68pdDmV3d6ewMyxGbj1vGxqrfdRQKfMi1BTRnhr+S1OcW8eciyzW3Pgzk80IqLjr66LSOkiShIEndjy/MS/QMX26aOAdq/35i5Bg/XQJBAP8e02aFrZYeT31rqehyEsQFrajIUb4CAsxA7DknP3nlHth8fu2ztglXQCEY4yu9vvEfolBInwLHEuWv99GR7bMCQQDSnBe5qAhSBriwAyXNbTFEMxJP0BnFcONVRjmR+5gvn0E1K39LALuSz2vXpeIXQ79J1CX8m9b0QGUpDljYd3yfAkBIUuHVV6I9Q3x/bs0tI2GkhoOTrK5XslQ+uUz+atz43nZfIvQMyPybK0v31glYtiLyUmh+YAgMDomR6c/Ubo03AkADk6UPgRwLEJQoYRVORNF2YAuqkVUutjkWJKgro4M1I9Y+qetygaOt3ZnuQqHxVTQ1c8XlYVwoL8PIC7dUjcrvAkEA4PFQylodIzVZsd7TxspanM9LpctiYuTkya9bN5E0cGzlt9ObeR3tMRhEog+zxcewp0q0WAGM1Z1rL1FGpF8YZA=="






#ifdef DEBUG
#define CLog(format, ...) NSLog(format, ## __VA_ARGS__)
#else
#define CLog(format, ...)
#endif

/*
 *@bref  系统版本判断
 */
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)
#define kMainScreenWidth   ([UIScreen mainScreen].applicationFrame).size.width //应用程序的宽度
#define kMainScreenHeight   ([UIScreen mainScreen].applicationFrame).size.height //应用程序的高度
#define kMainBoundsHeight   ([UIScreen mainScreen].bounds).size.height //屏幕的高度
#define kMainBoundsWidth    ([UIScreen mainScreen].bounds).size.width //屏幕的宽度
#define kViewSizeWidth      (self.view.frame.size.width)
#define kViewSizeHeight     (self.view.frame.size.height)
#define kVersion                        [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"]
#define kIsIOS7                         ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)
#define kIsIOS8                         ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define kIsIphone6P                     ([[UIScreen mainScreen] bounds].size.height == 736)
#define kIsIphone6                      ([[UIScreen mainScreen] bounds].size.height == 667)
#define kIsIphone5                      ([[UIScreen mainScreen] bounds].size.height == 568)
#define kIsIphone4                      ([[UIScreen mainScreen] bounds].size.height == 480)
#define kIsSimulator                    (NSNotFound != [[[UIDevice currentDevice] model] rangeOfString:@"Simulator"].location)   // 是否模拟器

#define RGBA(r,g,b,a)               [UIColor colorWithRed:(float)r/255.0f green:(float)g/255.0f blue:(float)b/255.0f alpha:a]
#define RGB(r, g, b) [UIColor colorWithRed:(float)r/255.0f green:(float)g/255.0f blue:(float)b/255.0f alpha:1.0f]

#define kColorNavBg                     RGBA(255, 111, 90, 1)
#define kColorViewControllerBg          RGBA(242, 242, 242, 1.f)
#define kColorGrayText                  RGBA(153, 153, 153, 1.f)
#define kColorGrayLine                  RGBA(238, 238, 238, 1.f)
#define kColorSeparateLine              RGBA(216, 216, 216, 1.f)
#define kColorRandom                    RGB((float)(rand() % 255), (float)(rand() % 255), (float)(rand() % 255))

#define kViewControllerHeadHeight (kIsIOS7 ? 64 : 44)

#define kUserDefaultSendGifCount            @"kUserDefaultSendGifCount"
#define kUserDefaultLaunchCount             @"kUserDefaultLaunchCount"
#define kUserDefaultShareList               @"kUserDefaultShareList"

#define kNotificationDownloadProgress       @"kNotificationDownloadProgress"
#define kNotificationDownloadDone           @"kNotificationDownloadDone"
#define kNotificationDownloadFail           @"kNotificationDownloadFail"
#define kNotificationGifRemove              @"kNotificationGifRemove"
#define kNotificationShareToWX              @"kNotificationShareToWX"
#define kNotificationShareSuccess           @"kNotificationShareSuccess"
#define kNotificationLaunchFromKeyboard     @"kNotificationLaunchFromKeyboard"
#define kNotificationGifSortList            @"kNotificationGifSortList"
#define kNotificationShowGuide              @"kNotificationShowGuide"
#define kNotificationFirstIn                @"kNotificationFirstIn"
#define kNotificationFirstInFinished        @"kNotificationFirstInFinished"


