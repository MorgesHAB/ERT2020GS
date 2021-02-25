#include "Double_buffer.h"

#include <iostream>
#include <ios>
#include <iosfwd>
#include <thread>


Double_buffer::Double_buffer(const std::string & filename) : output_file_(), filename_(filename), current_buffer(0){}


Double_buffer::~Double_buffer()
{
    log_buffer(current_buffer);
    output_file_.close();
}

Double_buffer::Double_buffer(size_t size, const std::string &filename) :
    buffers_{{ { size }, { size } }}, output_file_(), filename_(filename), current_buffer(0){ }

void Double_buffer::add(const std::string & str)
{
    if(buffers_[current_buffer].is_ready_to_fill())
        buffers_[current_buffer].add(str);
    else
        std::cerr << "The current buffer is not ready to fill." << std::endl;

    if(buffers_[current_buffer].is_full()){
        std::thread (&Double_buffer::log_buffer, this, current_buffer).detach();
        current_buffer = ++current_buffer % buffers_.size(); //change the buffer to the next one
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

    size_t last_position(buffers_[index].position()); //last position not valid i.e not ready to fill
    if(last_position==0) return;

    output_file_.open(filename_, std::ios::app);

    if(!output_file_){
        std::cerr << "Could not open file for writing, data will be lost." << std::endl << std::flush;
        return;
    }

    for(size_t i(0); i < last_position; ++i){
        output_file_ << (buffers_[index])[i] << std::endl << std::endl;
    }
    output_file_.flush();
    buffers_[index].make_ready_to_fill(); // last position is valid i.e ready to fill
    output_file_.close();
}


