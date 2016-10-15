#include <stdio.h>
#include <stdbool.h>

int main(){
	//initialize polybius square
	char square[6][6] = {
		{'b','c','d','e','f','g'},
		{'m','l','k','j','i','h'},
		{'n','o','p','q','r','s'},
		{'y','x','w','v','u','t'},
		{'z','a','1','2','3','4'},
		{'0','9','8','7','6','5'}
	};
	char index[6]={'a','d','f','g','v','x'};
	char key[6];
	char message[20];
	int messageLen=0,keyLen=0,i,j,k;
	
	printf("Enter 6-character keyword : ");
	scanf("%s", key);
	printf("Enter message : ");
	scanf("%s", message);
	
	messageLen = strlen(message);
	keyLen = strlen(key);
	
	// assign adfgvx coordinates for each letter
	char cipher1[2*messageLen]; 
	for(i=0;i<messageLen;i++){
		for(j=0;j<6;j++){
			for(k=0;k<6;k++){
				if(message[i]==square[j][k]){
					if(i==0){
						cipher1[0]=index[j];
						cipher1[1]=index[k];
					}else{
						cipher1[2*i]=index[j];
						cipher1[2*i+1]=index[k];
					}
				}
			}
		}
	}
	int cipherLen = sizeof(cipher1);
	
	// get the order of the letters in the key
	int keyOrder[keyLen];
	int pos = 0;
	for (i = (int)'a'; pos < keyLen; i++){
		for (j = 0; j < keyLen; j++){
			if (key[j] == (char)i) keyOrder[pos++] = j;
		}
	}
    
    // calculate number of rows
	int rows;
	bool even = true;
	char cipher2[cipherLen];
	if(cipherLen%keyLen>0){
		rows = cipherLen/keyLen + 1;
		even = false;
	}else{
		rows = cipherLen/keyLen;
	}
	
	// magic
	for(i=0,j=0,k=0;i<cipherLen;i++){
		cipher2[i]=cipher1[keyOrder[j]+k*keyLen];
		if(!even){
			if((keyOrder[j]+(k+1)*keyLen)>cipherLen-1){
				k=0;
				j++;
				continue;
			}
		}
		k++;
		if(k==rows) {
			k=0;
			j++;
		}
	}
	
	for(i=0;i<cipherLen;i++){
		printf("%c",cipher2[i]);
	}
	
}
