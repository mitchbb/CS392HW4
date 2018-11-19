#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int** transpose(int **input, int blocksize, int width){
	int output[width][width];
	for(int i = 0; i < width - blocksize; i = i + blocksize){
		for(int j = 0; j < width; j = j + blocksize){
			for(int k = 0; k < blocksize; k++){
				for(int l = 0; l < blocksize; l++){
					output[l + j][k + i] = input[k + i][l + j];
				}
			}
		}
	}
	return &output;
}

int main(int argc, char* argv) {
	if(argc != 3) {
		printf("ERROR! WRONG NUMBER ARGUMENTS! EXPECTED: NONE\n");
		return -1;
	}
	int width = sizeof(argv[1]);
	width = width/4;
	printf("%d\n", width);
	int blocksize = argv[2];
	transpose(argv[1], blocksize, width);
	return 0;
}
	