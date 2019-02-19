#include <stdio.h>
#include <stdlib.h>



void quickSort (int * array,int start,int end);
int partition (int * array,int start,int end);
void swap (int * array,int this,int that);


int main() {
    int array[10] = {5,6,4,2,3,1,6,7,4,51};
    quickSort (array,0,9);
    for (int i = 0; i < 10 ; ++i) {
        printf("%d | ",array[i]);
    }
    return 0;
}



void quickSort (int * array,int start,int end){
    if (start < end) {
        int pIndex = partition(array,start,end);
        quickSort(array,start,pIndex-1);
        quickSort(array,pIndex+1,end);
    }
}

int partition (int * array,int start,int end){
    int pivot= array[end];
    int pIndex = start; // set partition index as start initially.
    for (int i = start; i < end ; ++i) {
        if (array[i]<= pivot) {
            swap(array,i,pIndex); //swap element is lesser than pivot.
            pIndex ++;
        }
    }
   swap(array,pIndex,end);
   return pIndex;
}

void swap (int *array,int this,int that) {
    int temp =0;
    temp=array[this];
    array[this]=array[that];
    array[that]=temp;
}