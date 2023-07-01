#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

struct MAC {
  char address[18];  
  int ip;  
};

int main() {
  int numOfDevices; 
  scanf("%d", &numOfDevices);
  printf("Get Num done");
  struct MAC *devices = malloc(numOfDevices * sizeof(struct MAC));
    
  char* ipstr = malloc(2000); 
  gets(ipstr);  
  printf("Get ipstr");
    
  char *token = strtok(ipstr," "); 
  int i = 0;  
    
  while(token != NULL && i < 2*numOfDevices){
       if(i % 2 == 0)       
           strcpy(devices[i/2].address, token);         
       else
           devices[i/2].ip = atoi(token);
      
       token = strtok(NULL, " ");
       i++;      
  }
  printf("Get lookupIP");
  int lookupIP;       
  scanf("%d", &lookupIP); 
 
  // ... Search for MAC address and print      
      
  free(devices);   
  free(ipstr);          
}