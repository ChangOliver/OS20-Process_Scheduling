#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "policy.h"

int main(){

	char policy[5];
	int nprocess = 0;
	scanf("%s%d", policy, &nprocess);
	//printf("%s\n%d\n", policy, nprocess);

	Child process[nprocess];
	for(int i = 0; i < nprocess; i++){
		scanf("%s%d%d", process[i].name, &process[i].ready_time, &process[i].exe_time);
		//printf("%s %d %d\n", process[i].name, process[i].ready_time, process[i].exe_time);
	}

	switch(policy[0]) {
	    case 'F':
			FIFO(nprocess, process); 
			break;
	    case 'R': 
			RR(nprocess, process);
			break;
	    case 'S': 
			SJF(nprocess, process);
			break;
	    case 'P': 
			PSJF(nprocess, process);
			break;
    }

	return 0;
}
