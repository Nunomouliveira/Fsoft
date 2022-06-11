//
// Created by nunon on 09/06/2022.
//

#ifndef FSOFT2022_1A_4_CLASSVIEW_H
#define FSOFT2022_1A_4_CLASSVIEW_H

#include <list>
#include "class.h"

class ClassView{
public:
    Class getClass();
    void printClass(Class *classes);
    void printClasses(list<Class>& classes);
};

#endif //FSOFT2022_1A_4_CLASSVIEW_H
