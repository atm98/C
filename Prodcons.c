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
void producer(){
        mtx=wait(mtx);
        full=signal(full);
        empty=wait(empty);
        x++;
        printf("\nProducer produced item %d",x);
        mtx=signal(mtx);
}

void consumer()
{
    mtx=wait(mtx);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
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
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:    if((mtx==1)&&(empty!=0))
                        producer();
                    else
                        printf("Buffer is full!!");
                    break;
            case 2:    if((mtx==1)&&(full!=0))
                        consumer();
                    else
                        printf("Buffer is empty!!");
                    break;
            case 3:
                    break;
        }
    }

    return 0;
}
