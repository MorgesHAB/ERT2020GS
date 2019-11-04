# EPFL Rocket Team Bella Lui Project Makefile
# Lionel Isoz
#######################################################
CXX=g++
libPath=lib
srcPath=src
CPPFILES= $(srcPath)/*.cpp $(srcPath)/*.h
OFILES = $(CPPFILES:.cpp=.o)
Transceiver1=GST
Transceiver2=GSE
#######################################################
CPPFLAGS=-std=c++11 -g -Wall -DRH_PLATFORM=RH_PLATFORM_RPI -D__RASPBERRY_PI_ -I $(libPath)/
LDFLAGS=-lwiringPi

RH95_SRCS=$(libPath)/RH_RF95.cpp \
	$(libPath)//RHGenericSPI.cpp \
	$(libPath)//RHLinuxSPI.cpp \
 	$(libPath)//RHGenericDriver.cpp
RH95_OBJS=$(subst .cpp,.o,$(RH95_SRCS))
#######################################################
all:
	@echo "In which subsystem are you ?"
	@echo "Type : 'make GST' or 'make GSE'"

# default command
%.o: %.cpp
	$(CXX) $(CPPFLAGS) -o $@ -c $<

$(Transceiver1): $(Transceiver1).o $(RH95_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(Transceiver2): $(Transceiver2).o $(RH95_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

#change this part after
$(Transceiver1).o: $(CPPFILES)
$(Transceiver2).o: $(CPPFILES)

clean:
	rm -f $(RH95_OBJS) $(Transceiver1) $(Transceiver2) $(OFILES)
