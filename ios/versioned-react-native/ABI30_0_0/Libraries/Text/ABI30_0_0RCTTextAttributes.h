/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

#import <ReactABI30_0_0/ABI30_0_0RCTTextDecorationLineType.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const ABI30_0_0RCTTextAttributesIsHighlightedAttributeName;
extern NSString *const ABI30_0_0RCTTextAttributesTagAttributeName;

/**
 * Represents knowledge about all supported *text* attributes
 * assigned to some text component such as <Text>, <VirtualText>,
 * and <TextInput>.
 */
@interface ABI30_0_0RCTTextAttributes : NSObject <NSCopying>

// Color
@property (nonatomic, strong, nullable) UIColor *foregroundColor;
@property (nonatomic, strong, nullable) UIColor *backgroundColor;
@property (nonatomic, assign) CGFloat opacity;
// Font
@property (nonatomic, copy, nullable) NSString *fontFamily;
@property (nonatomic, assign) CGFloat fontSize;
@property (nonatomic, assign) CGFloat fontSizeMultiplier;
@property (nonatomic, copy, nullable) NSString *fontWeight;
@property (nonatomic, copy, nullable) NSString *fontStyle;
@property (nonatomic, copy, nullable) NSArray<NSString *> *fontVariant;
@property (nonatomic, assign) BOOL allowFontScaling;
@property (nonatomic, assign) CGFloat letterSpacing;
// Paragraph Styles
@property (nonatomic, assign) CGFloat lineHeight;
@property (nonatomic, assign) NSTextAlignment alignment;
@property (nonatomic, assign) NSWritingDirection baseWritingDirection;
// Decoration
@property (nonatomic, strong, nullable) UIColor *textDecorationColor;
@property (nonatomic, assign) NSUnderlineStyle textDecorationStyle;
@property (nonatomic, assign) ABI30_0_0RCTTextDecorationLineType textDecorationLine;
// Shadow
@property (nonatomic, assign) CGSize textShadowOffset;
@property (nonatomic, assign) CGFloat textShadowRadius;
@property (nonatomic, strong, nullable) UIColor *textShadowColor;
// Special
@property (nonatomic, assign) BOOL isHighlighted;
@property (nonatomic, strong, nullable) NSNumber *tag;
@property (nonatomic, assign) UIUserInterfaceLayoutDirection layoutDirection;

#pragma mark - Inheritance

- (void)applyTextAttributes:(ABI30_0_0RCTTextAttributes *)textAttributes;

#pragma mark - Adapters

/**
 * Text attributes in NSAttributedString terms.
 */
- (NSDictionary<NSAttributedStringKey, id> *)effectiveTextAttributes;

/**
 * Constructed font.
 */
- (UIFont *)effectiveFont;

/**
 * Font size multiplier reflects `allowFontScaling` and `fontSizeMultiplier`.
 */
- (CGFloat)effectiveFontSizeMultiplier;

/**
 * Foreground and background colors with opacity and right defaults.
 */
- (UIColor *)effectiveForegroundColor;
- (UIColor *)effectiveBackgroundColor;

@end

NS_ASSUME_NONNULL_END
