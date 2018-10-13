#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int sumArray(int arr[], int index) {
    int sum = 0;
    for (int i = index; i < (index+100); i++ ) {
        sum+=arr[i];        
    }
    return sum;
}

int main() { 
    
    int arr[1000];
    for (int i = 0; i < 1000; i++){
        arr[i]=i+1;
    }

    int fd[10][2];

    for (int i =0; i < 10; i++){
    	pipe(fd[i]);
    }

    int pid = 0;
    int sum = 0;
    
    for(int i = 0; i < 10; i++) {
        pid = fork();
        if(pid == 0) { 
            sum+=sumArray(arr, i*100);
            printf("%d\t%d\t%d\n",i,i*100,sum);
            write(fd[i][1],&sum,sizeof(sum));
            exit(0);
        }

    } 
    if (pid!=0) {


    	for (int i= 0; i < 10; i++)
    		wait(NULL);

    	sum = 0;
    	int t;
    	for (int i=0; i <10; i++){
    		read(fd[i][0],&t,sizeof(t));
    		sum+=t;
    	}
    	printf("Sum: %d\n", sum);
    }
    
    return 0;

}
