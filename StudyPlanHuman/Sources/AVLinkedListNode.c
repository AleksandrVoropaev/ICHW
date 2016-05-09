//
//  AVLinkedListNode.c
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/9/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "AVLinkedListNode.h"

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
