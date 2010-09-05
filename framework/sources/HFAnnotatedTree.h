//
//  HFAnnotatedTree.h
//  HexFiend_2
//
//  Created by Peter Ammon on 8/25/10.
//  Copyright 2010 ridiculous_fish. All rights reserved.
//

#import <Foundation/NSObject.h>

typedef unsigned long long (*HFAnnotatedTreeAnnotaterFunction_t)(id left, id right);


@interface HFAnnotatedTreeNode : NSObject {
    HFAnnotatedTreeNode *left;
    HFAnnotatedTreeNode *right;
    HFAnnotatedTreeNode *parent;
    uint32_t level;
    unsigned long long annotation;
}

/* Pure virtual method, which must be overridden. */
- (NSComparisonResult)compare:(HFAnnotatedTreeNode *)node;

/* Returns the next in-order node. */
- (id)nextNode;

#if ! NDEBUG
- (void)verifyIntegrity;
- (void)verifyAnnotation:(HFAnnotatedTreeAnnotaterFunction_t)annotater;
#endif


@end


@interface HFAnnotatedTree : NSObject {
    HFAnnotatedTreeAnnotaterFunction_t annotater;
    HFAnnotatedTreeNode *root;
}

- (id)initWithAnnotater:(HFAnnotatedTreeAnnotaterFunction_t)annotater;
- (void)insertNode:(HFAnnotatedTreeNode *)node;
- (void)removeNode:(HFAnnotatedTreeNode *)node;
- (id)rootNode;
- (id)firstNode;
- (BOOL)isEmpty;

#if ! NDEBUG
- (void)verifyIntegrity;
#endif

@end