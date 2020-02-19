#include "gui_message.h"

Gui_Message::Gui_Message(const std::string & message): message_(message){}


std::__cxx11::string Gui_Message::log_description() const
{
    return message_;
}
