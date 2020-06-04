#ifndef Gui_Message_H
#define Gui_Message_H

#include "../Logger/Logger.h"
#include "../Logger/utilities.h"

class Gui_Message : public Loggable {
public:
    Gui_Message(const std::string & message);
    virtual std::string log_description() const;
private:
    const std::string message_;
};

#endif // Gui_Message_H
