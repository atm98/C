#include <stdio.h>
#include <string.h>
#include <ctype.h>
void chcklexical(int a){
    int i;
    int alpha=0;
    int operend=0;
    char str[a];
    gets(str);
    for(i=0;i<a;i++){
        if(isalpha(str[i])||isdigit(str[i]))
            alpha++;
        else if(str[a]=='+'||str[a]=='-'||str[a]=='*'||str[a]=='/'||str[a]=='^'||str[a]=='%')
            operend++;
            
    }        
    if(alpha==operend+1)
        printf("The String Has Passed the Lexical Analysis");
    else
        printf("The String Has Passed the Lexical Analysis");
}
int main(void) {
    int length
    printf("Enter length");
    scanf("%d",&length);
    chcklexical(length);
	return 0;
}

