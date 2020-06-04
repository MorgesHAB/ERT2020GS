#include "Gui_message.h"

Gui_Message::Gui_Message(const std::string & message): message_("GUI\t" + utilities::datetime_long() + "\t" + message){}


std::string Gui_Message::log_description() const
{
    return message_;
}
