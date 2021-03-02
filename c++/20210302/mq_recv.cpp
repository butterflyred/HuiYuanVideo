#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define PERMS 0644
using namespace std;
struct my_msgbuf
{
    /* data */
    long mytype;
    char mtext[1024];

    my_msgbuf() : mytype(0){
        memset(mtext,'\0',sizeof(mtext)+1);
    }
};

int main(int argc,char* argv[]){
    struct my_msgbuf buf;
    int msqid;
    int toend;
    key_t key;


    system("touch msgq.txt");

    if ((key=ftok("msgq.txt",'B'))==-1)
    {
        cout << "fork err"<<endl;
        exit(1);
        /* code */
    }
    
    if ((msqid=msgget(key,PERMS))==-1)
    {
        cout << "msgget err"<<endl;
        exit(1);
        /* code */
    }
  
    printf("msg queue : ready to receving msg\n");


    for(;;){
        
        if (msgrcv(msqid,&buf,sizeof(buf.mtext),0,0)== -1)
        {
            cout << "msgrcv err"<<endl;
            /* code */
        }
        
        printf("recvd :\"%s\"\n",buf.mtext);
        toend = strcmp(buf.mtext,"end");
        if (toend == 0)
        {
            /* code */
            break;
        }
        
        
    }
    printf("msg queue : done to receving msg\n");
    system("rm msgq.txt");
    return 0; 

}
