#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>

namespace utilities {
/**
 * @brief datetime_short
 * @return An std::string representing the current system date and time.
 */
std::string datetime_short();

/**
 * @brief datetime_long
 * @return An std::string representing the current system date and time.
 */
std::string datetime_long();

/**
 * @brief time
 * @return An std::String representing the current system time.
 */
std::string time();
}
#endif // UTILITIES_H
