#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>



void decrepte(int encrypted[],int random[],int len){
    char pass[100];

    do{
        printf("\nEnter The key for the decryption : ");
        scanf("%s",pass);
        if (strcmp("password",pass)==0)
        {
            printf("\nDecrypted : ");

            for (int i = 0; i < len; i++)
            {
                printf("%c",encrypted[i]-random[i]);
            }
            
        }
        else{
            puts("Wrong password");
        }
    }
    while (strcmp("password",pass)!=0);

}

void encrypte(char password[],int len,int random[],int encrypted[]){

    printf("\nEnrypted Paket :");
    
    for (int i = 0; i < len; i++)
    {
        srand(time(NULL));
        int num=rand()%10+1;
        random[i]=num;
        encrypted[i]=password[i]+num;
        printf("%c",encrypted[i]);
    }

    

}

int main(){
    char password[100];
    fgets(password,100,stdin);
    int len=strlen(password);
    int random[len];
    int encrypted[len];
    encrypte(password,len,random,encrypted);
    decrepte(encrypted,random,len);
    return 0;
}