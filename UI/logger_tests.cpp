#include "../Logger/Logger_buffer.h"
#include "../Logger/double_buffer.h"
#include "../Logger/Logger.h"
#include <chrono>

int
    main(int argc, char ** argv)
{

    Double_buffer b1(500,"aq");


    for(int i=0;i<200000;i++){
        b1.add("sentence" + std::to_string(i));
        std::this_thread::sleep_for(std::chrono::microseconds(2));
        //b1.display();
        std::cout << i << std::endl;
        if(i==47868)
            return 0;
    }


}
