#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 25000// количество элементов
void selection_sort();
void swap(int* a, int* b);//меняет два элемнта местами
void randomize();// заполняет массив рандомными значениями

static int array[MAX];


int main(void){
  time_t start, end;
  srand (time (NULL));
  randomize();
  time(&start);//засекаем время начала
  selection_sort();
  time(&end);// засекаем время окончания
  printf("Time %f\n",difftime(end, start));
  printf("Size:%d\n\n",MAX);
}


void randomize(){
  for (int i = 0; i < MAX; i++){
    array[i]=rand()%MAX;
  }
}

void swap(int* a, int* b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}


void selection_sort(){
  for (int i = 0; i < MAX - 1; i++){
    int min_i = i;
	  for (int j = i + 1; j < MAX; j++){
		  if (array[j] < array[min_i]){
			  min_i = j;
		  }
	  }
    swap(&array[i],&array[min_i]);
  }
}