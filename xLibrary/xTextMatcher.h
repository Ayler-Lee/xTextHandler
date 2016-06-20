//
//  xTextMatcher.h
//  xTextHandler
//
//  Created by cyan on 16/6/18.
//  Copyright © 2016年 cyan. All rights reserved.
//

#import <XcodeKit/XcodeKit.h>

static NSString *const xTextHandlerAnyPattern       = @"*";                         // match any text
static NSString *const xTextHandlerStringPattern    = @"\"(.+)\"";                  // match "abc"
static NSString *const xTextHandlerHexPattern       = @"([0-9a-fA-F]+)";            // match 00FFFF
static NSString *const xTextHandlerRGBPattern       = @"([0-9]+.+[0-9]+.+[0-9]+)";  // match 20, 20, 20 | 20 20 20 ...
static NSString *const xTextHandlerRadixPattern     = @"([0-9]+)";                  // match numbers

@interface xTextMatchResult : NSObject

@property (nonatomic, copy) NSString *text;         // text for each lines
@property (nonatomic, assign) NSRange range;        // clipped text range

@end

@interface xTextMatcher : NSObject


/**
 Match texts in XCSourceEditorCommandInvocation

 @param selection  XCSourceTextRange
 @param invocation XCSourceEditorCommandInvocation

 @return match result
 */
+ (xTextMatchResult *)match:(XCSourceTextRange *)selection invocation:(XCSourceEditorCommandInvocation *)invocation;

@end
