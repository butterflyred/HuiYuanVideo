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
    int len;
    key_t key;


    system("touch msgq.txt");

    if ((key=ftok("msgq.txt",'B'))==-1)
    {
        cout << "fork err"<<endl;
        exit(1);
        /* code */
    }
    
    if ((msqid=msgget(key,PERMS | IPC_CREAT))==-1)
    {
        cout << "msgget err"<<endl;
        exit(1);
        /* code */
    }
    
    printf("ready to send msg\n");
    printf("enter lines of text\n");
    buf.mytype=1;


    for(;;){
        cin.getline(buf.mtext,sizeof(buf.mtext));
        len = strlen(buf.mtext);
        if (/* condition */buf.mtext[len-1]== '\n')
        {
            /* code */
            buf.mtext[len-1] == '\0';
        }
        if (msgsnd(msqid,&buf,len+1,0)== -1)
        {
            cout << "msgsnd err"<<endl;
            /* code */
        }
        
        
    }

    strcpy(buf.mtext, "end");
    len = strlen(buf.mtext);
    if (msgsnd(msqid,&buf,len+1,0)== -1)
    {
        cout << "msgsnd err"<<endl;
        /* code */
    }
    if (msgctl(msqid,IPC_RMID,NULL)== -1)
    {
        cout << "msgctl err"<<endl;
        /* code */
    }
    printf("msg queue : done sending msg\n");
    return 0; 

}
