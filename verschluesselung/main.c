//
//  main.c
//  verschluesselung
//
//  Created by Cajetan Perwein on 22/09/15.
//  Copyright © 2015 Cajetan Perwein. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h> 

void krypt(char *str, int n);
void dekrypt(char *str, int n);
void getInput(char *buf, int size);

int main(int argc, const char * argv[]) {
    
    int move;
    char str[4096];
    char buf[4096];
    
    
    printf("please use the following commands: \ninput [string]\ncode [number]\n");
    do {
        printf("$ ");
        getInput(buf,sizeof(buf));
        
        if (!strncmp("input ", buf, 6)) {
            sscanf(buf+6,"%s",str);
        }
        
        
        else if(!strncmp("code ",buf,5)) {
            
            sscanf(buf+5,"%d",&move);
            
            if(move > 0) {
                krypt(str,move);
            }
            else {
                dekrypt(str, -move);
            }
            
            puts(str);
        }
        
    
        
    } while (strcmp(buf,"quit\n"));
    
    return 0;
}



void krypt(char *str, int n)
{
    int i;
    for (i=0; i<strlen(str); i++) {
        if(isupper(str[i])) {
            str[i]=(str[i]-'A'+n) % 26 + 'A';
        } else if(islower(str[i])) {
            str[i] = (str[i]-'a'+n) % 26 + 'a';
        }
    }
}


void dekrypt(char *str, int n) {
    krypt(str, 26-(n%26));
}

void getInput(char *buf, int size) {
    
    fgets(buf,size,stdin);
    
}