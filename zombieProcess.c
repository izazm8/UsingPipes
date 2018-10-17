#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{
    int cpid = fork(); 
    
    
    //parent process
    if (cpid > 0) 
        sleep(50); 
  
    //chile process
    else        
        exit(0); 
  
    return 0; 
}
