#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i, j, *p, n, m, k, zeroStolb=0, st, st1=1, stN;
	
	puts("vvedite n");
	scanf("%i",&n);
	puts("vvedite m");
	scanf("%i",&m);
	
	if(!(p=(int*)malloc(n*m*sizeof(int)))){
		puts("not enough memory");
		return 1;
	}
	puts("vvedite element massiva\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("  [%i|%i]=",i+1,j+1);
			scanf("%i",p+i*m+j);
		}
	}
	//find zero
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(*(p+j+i*m)==0){
				zeroStolb++;
				i++;
			}
		}
	}
	
	stN=-1;
	st=1;
	for(i=0;i<n;i++){
		for(j=1;j<m;){
				if(*(p+i*m) == *(p+i*m+j)){
					st1++;
					if(!(j+1<m)){
						if(st<st1){
							st=st1;
							stN=i;
						}
						st1=1;
						j+=2;	
					}
					j++;
				}
				else {
					if(st<st1){
						st=st1;
						stN=i;	
					}
				st1=1;
				break;
			}
		}
	}
	
	k=1;
	printf("MASS: \n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(i>k){
				printf("\n");
				k++;
			}
			printf("[%i|%i]=%i  ",i+1,j+1,*(p+i*m+j));
		}
	}
	if(stN==-1){
		puts("sovpadenii ne naideno");
	}
	else printf("¹ stroki s seriei el-tov= %i",stN);
	free(p);
	return 0;
}
