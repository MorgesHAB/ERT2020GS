#ifndef GUI_LOGGER_H
#define GUI_LOGGER_H

#include "../Logger/Logger.h"

class Gui_Logger : public Logger
{
public:

    virtual void log(Loggable *data) override;

};

#endif // GUI_LOGGER_H
