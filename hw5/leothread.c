#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	int name;
};

int calc(int num)
{
	if(num == 0 || num == 1)
	{
		return 1;
	}
	else
	{
		return calc(num - 1) + calc(num - 2) + 1;
	}
}

void* thread(void* vargp) //thread routine
{
	struct node curr = *(struct node*)vargp;
	if(curr.value <= 1)
	//end case
	{
	    printf("[%d]\n", curr.name);
		return NULL;
	}


	//doing the left side
	struct node left;
	left.value = curr.value - 1;
	left.name = curr.name + 1;

	if(left.value > 1) printf("(%d\n", left.name);
    pthread_t lid;
    pthread_create(&lid, NULL, thread, (void*)&left);
    if(pthread_join(lid, NULL))
    {
    	fprintf(stderr, "Error: Failed to join");
    	exit(1);
    }
    if(left.value > 1) printf("%d)\n", left.name);



    //doing the right side
	struct node right;
	right.value = curr.value - 2;
	right.name = curr.name + 1 + calc(curr.value - 1);

	if(right.value > 1) printf("(%d\n", right.name);
    pthread_t rid;
    pthread_create(&rid, NULL, thread, (void*)&right);
    if(pthread_join(rid, NULL))
    {
    	fprintf(stderr, "Error: Failed to join");
    	exit(1);
    }
    if(right.value > 1) printf("%d)\n", right.name);
    
    return NULL;
}





int main(int argc, char* argv[])
{
	int num = atoi(argv[1]);
   	if(argc != 2 || num <= 0)
    {
            fprintf(stderr, "Error: Invalid arguments");
            exit(1);
    }
    if(num <= 1)
    	//if only 1 argument, just return
    {
    	printf("[0]\n");
    	exit(0);
    }

    //prepare the threading
    struct node first;
	first.value = num;
    first.name = 0;

    //start the threading
    printf("(0\n");
	pthread_t rid;
	pthread_create(&rid, NULL, thread, (void*)&first);
	if(pthread_join(rid, NULL))
    {
    	fprintf(stderr, "Error: Failed to join");
    	exit(1);
    }
    printf("0)\n");


	return 0;
}


