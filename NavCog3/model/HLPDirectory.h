/*******************************************************************************
 * Copyright (c) 2014, 2016  IBM Corporation, Carnegie Mellon University and others
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/


#import <Foundation/Foundation.h>
#import <Mantle/Mantle.h>
#import "HLPGeoJSON.h"

@class HLPDirectory;

@interface HLPDirectoryItem : MTLModel<MTLJSONSerializing, NSCoding>
@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) NSString *titlePron;
@property (nonatomic, readonly) NSString *subtitle;
@property (nonatomic, readonly) NSString *subtitlePron;
@property (nonatomic, readonly) NSString *nodeID;
@property (nonatomic, readonly) HLPDirectory *content;

- (void) walk:(BOOL(^)(HLPDirectoryItem*))func withBuffer:(NSMutableArray*)buffer;
- (NSString*) getItemTitle;
- (NSString*) getItemTitlePron;
- (NSString*) getItemSubtitle;
- (NSString*) getItemSubtitlePron;
@end

@interface HLPDirectorySection : MTLModel<MTLJSONSerializing, NSCoding>
@property (nonatomic) NSString *title;
@property (nonatomic, readonly) NSString *pron;
@property (nonatomic, readonly) NSString *indexTitle;
@property (nonatomic) NSArray<HLPDirectoryItem*> *items;

- (void) walk:(BOOL(^)(HLPDirectoryItem*))func withBuffer:(NSMutableArray*)buffer;
@end

@interface HLPDirectory : MTLModel<MTLJSONSerializing, NSCoding>
@property (nonatomic, readonly) BOOL showSectionIndex;
@property (nonatomic) NSArray<HLPDirectorySection*> *sections;

- (void) walk:(BOOL(^)(HLPDirectoryItem*))func withBuffer:(NSMutableArray*)buffer;
- (void) addSection:(HLPDirectorySection*)section atIndex:(NSUInteger)index;
@end
