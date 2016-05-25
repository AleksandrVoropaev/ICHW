//
//  AVUsableThings.h
//  StudyPlanHuman
//
//  Created by Aleksandr Voropaev on 5/23/16.
//  Copyright © 2016 Aleksandr Voropaev. All rights reserved.
//

#ifndef AVUsableThings_h
#define AVUsableThings_h

#define AVSwitchDefault(expression) \
    default: expression;

#define AVSwitchDefaultBreak AVSwitchDefault({})

#define AVSwitchCase(value, expression) \
    case value: expression; \
    break;

#endif /* AVUsableThings_h */
