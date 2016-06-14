//
//  AVCreature.h
//  ObjectiveC
//
//  Created by Aleksandr Voropaev on 6/14/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    AVGenderMale,
    AVGenderFemale
} AVGender;

@interface AVCreature : NSObject
@property (atomic, assign) AVGender gender;
@property (atomic, retain) NSString *name;
@property (atomic, assign) NSUInteger weight;
@property (atomic, assign) NSUInteger age;
@property (atomic, assign, readonly) NSArray *children;

-(void)addChild: (AVCreature *) child;
-(void)removeChild: (AVCreature *) child;
-(void)sayHi;
-(void)makeChildrenSayHi;

@end
