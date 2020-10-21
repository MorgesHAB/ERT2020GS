#ifndef LOG_BUFFER_H
#define LOG_BUFFER_H

#include <string>
#include <vector>
#include <atomic>
#include <ostream>

/**
 * @brief The Logger_buffer class Used by the logger to simplify buffer utilization.
 */
class Logger_buffer
{
public:
    /**
     * @brief Logger_buffer
     * @param size The size of the buffer.
     */
    Logger_buffer(size_t size);

    /**
     * @brief Logger_buffer Initalize a default-sized buffer.
     */
    Logger_buffer();

    /**
     * @brief position The current position on the buffer.
     * @return The current position on the buffer.
     */
    size_t position();

    /**
     * @brief add Adds a new string to the buffer.
     * @param value The string to add.
     */
    void add(const std::string& value);

    /**
     * @brief make_ready_to_fill Sets the buffer as ready to fill.
     */
    void make_ready_to_fill();
    /**
     * @brief is_ready_to_fill
     * @return If the buffer is ready to fill. (if it still has some space)
     */
    bool is_ready_to_fill() const;
    /**
     * @brief is_full
     * @return If the buffer is not ready to fill.
     */
    bool is_full() const;
    /**
     * @brief operator []
     * @return Accessor to the elements of the buffer.
     */
    std::string & operator[](size_t);

    /**
     * @brief display Prints all the elements line by line.
     */
    void display() const;

    /**
     * @brief size The size of the buffer.
     */
    const size_t size;


private:
    std::atomic<bool> ready_; //for safety
    std::atomic<size_t> position_;
    std::vector<std::string> buffer_;

};

#endif
