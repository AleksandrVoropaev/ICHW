//
//  AVCreature.m
//  ObjectiveC
//
//  Created by Aleksandr Voropaev on 6/14/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#import "AVCreature.h"

@interface AVCreature()
@property (atomic, retain) NSMutableArray *mutableArrayChildren;
@end

@implementation AVCreature

@dynamic children;

-(NSArray *)children {
    return [[self.mutableArrayChildren copy] autorelease];
}

-(void)addChild: (AVCreature *) child {
    if (![_mutableArrayChildren containsObject:child]) {
        [_mutableArrayChildren addObject:child];
    }
}

-(void)removeChild: (AVCreature *) child {
    if ([_mutableArrayChildren containsObject:child]) {
        [_mutableArrayChildren removeObject:child];
    }
}

-(void)sayHi {
    NSLog(@"Hi!");
    [self makeChildrenSayHi];
}

-(void)makeChildrenSayHi {
    for (AVCreature *child in _mutableArrayChildren) {
        [child sayHi];
    }
}



@end
