#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0666

using namespace std;


int main(int argc, char *argv[])
{
	int msgid = atoi(argv[1]);
	key_t key = 100;

	int ret = msgctl(msgid, IPC_RMID, 0);

	if(ret < 0)
	{
		perror("msgctl() error");
		exit(EXIT_FAILURE);
	}

	cout<<"msgid: "<<msgid<<" has been removed from IPC list"<<endl;

	return 0;
}
