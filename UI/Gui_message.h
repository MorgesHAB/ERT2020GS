#ifndef Gui_Message_H
#define Gui_Message_H

#include "../Logger/Logger.h"
#include "../Logger/utilities.h"

/**
 * @brief The Gui_Message class Inheriting the Loggable, this is a basic data which will be used by the GUI.
 */
class Gui_Message : public Loggable {
public:
    Gui_Message(const std::string & message);
    virtual std::string log_description() const;
private:
    const std::string message_;
};

#endif // Gui_Message_H
