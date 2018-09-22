

g++ -pthread -lmraa -std=gnu++11 -lgpiodcxx \
main.cpp \
IRremote.h \
IRremote.cpp \
IRremoteInt.h \
irRecv.cpp \
ir_NEC.cpp \
-o main
