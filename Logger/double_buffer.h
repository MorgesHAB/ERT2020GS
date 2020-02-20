#ifndef DOUBLE_BUFFER_H
#define DOUBLE_BUFFER_H

#include <array>
#include <atomic>
#include <fstream>

#include "Logger_buffer.h"


class Double_buffer
{
public:

    /**
     * @brief Double_buffer Creates a default-sized double buffer.
     * @param filename The file to write data.
     */
    Double_buffer(const std::string & filename);

    ~Double_buffer();

    /**
     * @brief Double_buffer
     * @param size The size of each buffer.
     * @param filename The file to write data.
     */
    Double_buffer(size_t size, const std::string & filename);

    /**
     * @brief add Adds the string to the buffer which is ready.
     * @attention Empties a buffer by logging its data in the file if a buffer is full.
     */
    void add(const std::string &);

    /**
     * @brief display Displays both of the buffers.
     */
    void display() const;


private:
    /**
     * @brief Logger_buffer Empties the buffer by logging its data into a file.
     * @param index The index of the buffer to log.
     */
    void log_buffer(size_t index);

    std::array<Logger_buffer, 2> buffers_;
    std::ofstream output_file_;
    std::string filename_;
    size_t current_buffer;
    std::atomic<bool> ok;
};


#endif // DOUBLE_BUFFER_H
