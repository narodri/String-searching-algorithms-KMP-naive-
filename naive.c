#include <stdio.h>
#include <string.h>

#define strMax 10000000
#define patMax 3000
char str[strMax], pat[patMax];
int pos[strMax];

void main(){
	FILE *file_str = fopen("string.txt", "r");
	FILE *file_pat = fopen("pattern.txt", "r");
	if (file_str == NULL)
		printf("The string file does not exist.\n");
	if (file_pat == NULL)
		printf("The pattern file does not exist.\n");
	while(!feof(file_str))
		fgets(str, strMax, file_str);
	while(!feof(file_pat))
		fgets(pat, patMax, file_pat);
	// str과 pat에 txt파일에서 읽어온 값 저장완료
	int appear=0;

	FILE *file_result = fopen("result_naive.txt", "w");
	if (file_result == NULL)
		printf("error\n");

	int i, j, start = 0;
	int ls = strlen(str) - 2;
	int lp = strlen(pat) - 2;
	int end = lp;
	for(i=0;end<=ls;end++,start++){
		if(str[end] == pat[lp]){
			for(j=0,i=start;j<lp && str[i]==pat[j];i++,j++);
			if(j==lp){
				pos[appear] = start;
				appear++;
			}			
		}
	}

	fprintf(file_result, "We found %d patterns and the positions are \n", appear);
	for(i=0;i<appear;i++){
		fprintf(file_result,"%d ", pos[i]);
	}

	int close_str = fclose(file_str);
	int close_pat = fclose(file_pat);
	int close_result = fclose(file_result);
	if (close_str != 0)
		printf("error\n");
	if (close_pat != 0)
		printf("error\n");
	if (close_result != 0)
		printf("error\n");
}
