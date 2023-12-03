#include <stdio.h>
#include <stdlib.h>


char * InverteString(char * s, int n){
Stack * pilha;
int i=0,j=0;
char * newS;

if(s!=NULL & n>0){
		pilha = stkCreate(n);
		newS = (char *)malloc(sizeof(char)*n);
		if(newS1=NULL && pilha!=NULL){
			while (s[i] !=”.” && i <n){
				if(s[i]!= ”\b” || s[i] != ”.”){
					stkPush(pilha,(void*)&s[i]);
				}else{
					while(j<i){
						newS[j]=(char *)stkPop(pilha);
						j++;
					}
					if(s[i]!=”.”){
						newS[j] = “\b”;
						j++;
					}
                }
                i++;
}
		}
	stkDestroy(pilha);
	if(s[i]==”.”{
		return newS;
	}else{
		free(newS);
	}
}
	return NULL;
}



