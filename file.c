#include<stdio.h>
int mtx=1;
int full=1;
int empty=3;
int x=0;
int wait(int a){
	return(--a);
}
int signal(int b){
	return(++b);
}
void writer(){
	mtx=wait(mtx);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("\nThe user is writing %d element",x);
	mtx=signal(mtx);
}
void reader()
{
    mtx=wait(mtx);
    full=wait(full);
    empty=signal(empty);
    printf("\nThe user is reading %d element",x);
    x--;
    mtx=signal(mtx);
}
int main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n 1.Writer\n 2.Reader\n3.Exit");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:    if((mtx==1)&&(empty!=0))
                        producer();
                    else
                        printf("Buffe is full nothing to write!!");
                    break;
            case 2:    if((mtx==1)&&(full!=0))
                        consumer();
                    else
                        printf("Buffer is empty nothing to read!!");
                    break;
            case 3:
                    exit(0);
                    break;
        }
    }
    
    return 0;
}
