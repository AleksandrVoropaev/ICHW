//
//  AVLinkedListNode.c
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/9/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#include "AVLinkedListNode.h"

//void __AVLinkedListNodeDeallocate(void *object) {
//    AVLinkedListNodeSetObject(object, NULL);
//    AVLinkedListNodeSetNextNode(object, NULL);
//    
//    __AVObjectDeallocate(object);
//}
//
//AVLinkedListNode *AVLinkedListNodeCreateWithObject(AVObject *object) {
//    AVLinkedListNode *result = AVObjectCreateOfType(AVLinkedListNode);
//    AVLinkedListNodeSetObject(result, object);
//    
//    return result;
//}
//
//AVLinkedListNode *AVLinkedListNodeGetNextNode(AVLinkedListNode *node) {
//    return NULL != node ? node->_nextNode : NULL;
//}
//
//void AVLinkedListNodeSetNextNode(AVLinkedListNode *node, AVLinkedListNode *nextNode) {
//    if (NULL != node && node->_nextNode != nextNode) {
//        AVObjectRetain(nextNode);
//        AVObjectRelease(node->_nextNode);
//        
//        node->_nextNode = nextNode;
//    }
//}
//
//extern
//AVObject *AVLinkedListNodeGetObject(AVLinkedListNode *node);
//
//extern
//AVLinkedListNode AVLinkedListNodeSetObject(AVLinkedListNode *node, AVObject *object);
