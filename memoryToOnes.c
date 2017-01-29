#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned * allocateOnes(int numberOfOnes){
  unsigned * array = malloc(numberOfOnes * sizeof(unsigned));
  unsigned * tmp = array;
  for(int i = 0; i < numberOfOnes; i++){
    *tmp = 0b11111111111111111111111111111111;
    tmp++;
  }
  return array;
}

void printContents(unsigned * array, int size){
  for(int i = 0; i < size; i++){
    printf("%u", *array);
    array++;
  }  
}

void writeOriginalArrayToFile(unsigned * array, int size){
  FILE *f = fopen("OriginalArray.txt", "wb");
  for(int i = 0; i < size; i++){
    if(*(array + i) == 0b11111111111111111111111111111111){
      fputc('1', f);
    }
    else{
      fputc('0', f);
    }
  }
  fclose(f);
}

void writeFaultInjectedArrayToFile(unsigned * array, int size){
  FILE * f = fopen("InjectedArray.txt", "wb");
  for(int i = 0; i < size; i++){
    if(*(array + i) == 0b11111111111111111111111111111111){
      fputc('1', f);
    }
    else{
      fputc('0', f);
    }
  }
  fclose(f);
}


int main(int argc, char *argv[]){
  if(argc != 2){
    printf("Please provide the number of unisgned integers to write to malloc'd space\n");
    return EXIT_FAILURE;
  }
  int size = atoi(argv[1]);
  unsigned * ones_array = allocateOnes(size);
  printf("Allocated space for %s unsigned integers, and assigned the values to 1's\n", argv[1]);
  writeOriginalArrayToFile(ones_array, size);
  printf("Please press any key and enter to continue:\n");
  getchar();
  writeFaultInjectedArrayToFile(ones_array, size);
  printf("Wrote Fault Injected Array to File!\n");
  free(ones_array);
  return EXIT_SUCCESS;   
}
