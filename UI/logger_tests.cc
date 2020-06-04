
#ifdef aa
#include "../Logger/Logger_buffer.h"
#include "../Logger/double_buffer.h"
#include "../Logger/Logger.h"
#include "../Logger/Loggable.h"
#include <string>
#include <chrono>


class Data : public Loggable {
public:
    virtual std::string log_description() const{
        return std::move(text);
    }

    Data(std::string str):text(str){}
    std::string text;
};




void foo(size_t until){
/*
    Double_buffer buf;

    for(size_t i=0;i<until; i++){
        buf.add(std::to_string(i) + d.log_description());
        std::this_thread::sleep_for(std::chrono::microseconds(2));
        //b1.display();
        //std::cout << i << std::endl;

    }
*/

    static std::atomic<size_t> a(0);

    Logger lo(std::to_string(++a));
    for(size_t i(0); i < until; ++i){
        lo.log(new Data(std::to_string(i)));
        std::this_thread::sleep_for(std::chrono::nanoseconds(1));
    }
}

int
    main(int argc, char ** argv)
{

    Logger test(1000, "THIS_IS_A_LOGFILE_b5");
    Data* dat = new Data("This simulates a long packet which was sent "
                         "from the rocket to our ground station. "
                         "We love receiving long packets as we can log them all. "
                         "This is used to test logging "
                         "long packets at a high rate on the Raspberry Pi 4. "
                         "This packet is exactly 256 bytes "
                         "long.");
    for(int i=0;i<50000;i++)
    {
        test.log(dat);
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    }

    /*
    for(int i=0;i<200000;i++){
        b1.add("sentence" + std::to_string(i));
        std::this_thread::sleep_for(std::chrono::microseconds(2));
        //b1.display();
        std::cout << i << std::endl;
        if(i==47868)
            return 0;
    }
*/

    std::thread t1(foo, 0);
    std::thread t2(foo, 5);
    std::thread t3(foo, 9);
    std::thread t4(foo, 41251);

    std::this_thread::sleep_for(std::chrono::seconds(3));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;

}
#endif
