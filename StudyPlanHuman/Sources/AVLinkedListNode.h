//
//  AVLinkedListNode.h
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/9/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#ifndef AVLinkedListNode_h
#define AVLinkedListNode_h

#include "AVHuman.h"

typedef struct AVLinkedListNode AVLinkedListNode;

struct AVLinkedListNode {
    AVObject _super;
    
    AVLinkedListNode *_nextNode;
    AVObject *_object;
};

extern
AVLinkedListNode *AVLinkedListNodeCreateWithObject(AVObject *object);

extern
AVLinkedListNode *AVLinkedListNodeGetNextNode(AVLinkedListNode *node);

extern
void AVLinkedListNodeSetNextNode(AVLinkedListNode *node, AVLinkedListNode *nextNode);

extern
AVObject *AVLinkedListNodeGetObject(AVLinkedListNode *node);

extern
AVLinkedListNode AVLinkedListNodeSetObject(AVLinkedListNode *node, AVObject *object);

#endif /* AVLinkedListNode_h */
