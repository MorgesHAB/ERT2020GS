#include "double_buffer.h"

#include <iostream>
#include <iosfwd>
#include <fstream>
#include <thread>
#include <sstream>
#include <iomanip>


Double_buffer::Double_buffer(const std::string & filename) : output_file_(filename), current_buffer(0){}


Double_buffer::~Double_buffer()
{
    log_buffer(current_buffer);
}

Double_buffer::Double_buffer(size_t size, const std::string &filename) :
    buffers_{{ { size }, { size } }}, output_file_(filename), current_buffer(0){ }

void Double_buffer::add(const std::string & str)
{
    if(buffers_[current_buffer].is_ready_to_fill())
        buffers_[current_buffer].add(str);
    else
        std::cout << "The current buffer is not ready to fill, check algo." << std::endl;

    if(buffers_[current_buffer].is_full()){
        //std::cout << "The buffer got full, initializing thread \n";
        std::thread (&Double_buffer::log_buffer, this,current_buffer).detach();
        current_buffer = ++current_buffer % buffers_.size();
    }
}

void Double_buffer::display() const
{
    for(size_t i(0); i<buffers_.size();++i){
        std::cout << "\nBUFFER NO " + std::to_string(i) << std::endl;
        buffers_[i].display();
    }
}

void Double_buffer::log_buffer(size_t index){
    //std::cout << "inside the thread";
    //std::cout << "Logging the buffer no: " + std::to_string(index) + "\n" << std::endl;


    if(!output_file_){
        std::cerr << "Could not open file for writing, data will be lost." << std::endl << std::flush;
        return;
    }

    size_t last_position(buffers_[index].position()); //last position not valid i.e not ready to fill

    for(size_t i(0); i < last_position; ++i){
        output_file_ << (buffers_[index])[i] << std::endl;
    }
    //output_file_.flush();
    buffers_[index].make_ready_to_fill(); // last position is valid i.e ready to fill

}


