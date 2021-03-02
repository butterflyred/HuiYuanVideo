
g++ -c -Wall -g mq_send.cpp -lpthread -lrt
g++ mq_send.o -o mq_send -lpthread -lrt
g++ -c -Wall -g mq_recv.cpp -lpthread -lrt
g++ mq_recv.o -o mq_recv -lpthread -lrt