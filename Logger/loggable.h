#ifndef LOGGABLE_H
#define LOGGABLE_H

#include <string>

class Loggable
{
public:
    virtual std::string log_description() = 0; //don't forget to move when returning for efficiency reasons
    virtual ~Loggable();
};

#endif // LOGGABLE_H
