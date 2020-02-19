#include "gui_logger.h"

#include "utilities.h"


void Gui_Logger::log(Loggable *data)
{
    Logger::buffer.add( "GUI\t" + utilities::time_long() + "\t" + data->log_description());
}
