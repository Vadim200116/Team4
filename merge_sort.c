#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Size 100000000//количесвто элементов
//Объединяет два подмассива в arr[].
// Первый подмассив arr[l..m]
// Второй подмассив arr[m+1..r]
void merge(int l, int m, int r);

void mergeSort(int l, int r);//функция сортрровки слиянием

void randArr();//заполняет массив рандомными значениями

static int arr[Size];


int main(void){
  time_t start, end;
  srand (time (NULL));
  randArr();
  time(&start);//засекаем время начала
  mergeSort( 0, Size - 1);
  time(&end);// засекаем время окончания
  printf("Time %f\n",difftime(end, start));
  printf("Size:%d\n\n",Size);
  return 0;
}

void randArr(){
   for (int i = 0; i < Size; i++){
    arr[i]=rand();
  }
}


void merge(int l, int m, int r){
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int *L,*R;
  L=(int*)malloc(n1*sizeof(int));
  R=(int*)malloc(n2*sizeof(int));
  for (i = 0; i < n1; i++){
    L[i] = arr[l + i];  
  }
  for (j = 0; j < n2; j++){
    R[j] = arr[m + 1+ j];
  }
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2){
    if (L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
    }
  while (i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2){
  arr[k] = R[j];
  j++;
  k++;
  }
  free(L);
  free(R);
}

// l это левый индекс and r это правый индекс массива, который мы будем сортировать
void mergeSort( int l, int r){
  if (l < r){
    int m = l+(r-l)/2;// находим середину
    //сортирует первую и вторую половины
    mergeSort( l, m);
    mergeSort( m+1, r);
    merge( l, m, r);
  }
}