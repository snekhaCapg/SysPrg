#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0666

using namespace std;


int main()
{
	int msgid;
	key_t key = 100;

	msgid = msgget(key, IPC_CREAT | IPC_EXCL | PERMS);

	if(msgid < 0)
	{
		perror("msgget() error");
		exit(EXIT_FAILURE);
	}

	cout<<"msgid: "<<msgid<<endl;

	return 0;
}
