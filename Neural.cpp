#include <iostream>
#include <cstdlib>

using namespace std;

//Selection sort function
void selectionSort(int dizi[], int elemanSayisi) {
    int i, j, enKucuk, temp;
    for (i = 0; i < elemanSayisi - 1; i++) {
        enKucuk = i;
        for (j = i + 1; j < elemanSayisi; j++) {
            if (dizi[j] < dizi[enKucuk])
                enKucuk = j;
        }
        temp = dizi[i];
        dizi[i] = dizi[enKucuk];
        dizi[enKucuk] = temp;
    }
}

//Insertion sort function
void insertionSort(int dizi[], int elemanSayisi) {
    int i, j, temp;
    for (i = 1; i < elemanSayisi; i++) {
        j = i;
        while (j > 0 && dizi[j - 1] > dizi[j]) {
            temp = dizi[j];
            dizi[j] = dizi[j - 1];
            dizi[j - 1] = temp;
            j--;
        }
    }
}

//Bubble sort function
void bubbleSort(int dizi[], int elemanSayisi) {
    int temp;
    int i, j;

    for (i = 1; i < elemanSayisi; i++) {
        for (j = 0; j < elemanSayisi - i; j++) {
            if (dizi[j] > dizi[j + 1]) {
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

//Shell sort function
void shellSort(int dizi[], int elemanSayisi) {
    int j;
    for (int gap = elemanSayisi / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < elemanSayisi; ++i) {
            int temp = dizi[i];
            for (j = i; j >= gap && temp < dizi[j - gap]; j -= gap) {
                dizi[j] = dizi[j - gap];
            }
            dizi[j] = temp;
        }
    }
}

//Merge sort functions
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int dizi[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(dizi, l, m);
        mergeSort(dizi, m + 1, r);
        merge(dizi, l, m, r);
    }
}

//Quick sort function
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

//Heap sort function
void swap(int a[], int *g, int *b) {
    int temp;
    temp = a[*g];
    a[*g] = a[*b];
    a[*b] = temp;
}

void maxHeapify(int a[], int parent, int last) {
    int child;
    child = 2 * parent;
    while (child <= last) {
        if ((child + 1 <= last) && (a[child + 1] > a[child]))
            child++;
        if (a[parent] < a[child])
            swap(a, &parent, &child);
        parent = child;
        child = 2 * parent;
    }
}

void buildHeap(int a[], int last) {
    int i;
    for (i = last / 2; i > 0; i--) {
        maxHeapify(a, i, last);
    }
}

void heapSort(int a[], int last) {
    int l;
    l = 1;
    buildHeap(a, last);
    while (last > 1) {
        swap(a, &l, &last);
        last--;
        maxHeapify(a, 1, last);
    }
}

//Radix sort function
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    //Create Dummy Array!!!
    //cout << "SORT ME LIKE YOU DO!" << endl;
    
    
   int sz = 274835;
   int sirala[sz];
   for(int i=0;i<sz;i++)
      sirala[i]=rand()%165460;  //Generate number between 0 to 2147483645
    
   int sz1 = 274835;
   int sirala1[sz1];
   for(int i=0;i<sz1;i++)
      sirala1[i]=rand()%165460;  //Generate number between 0 to 2147483645
    
   int sz2 = 274835;
   int sirala2[sz2];
   for(int i=0;i<sz2;i++)
      sirala2[i]=rand()%165420;  //Generate number between 0 to 2147483645
    
   int sz3 = 27835;
   int sirala3[sz3];
   for(int i=0;i<sz3;i++)
      sirala3[i]=rand()%165410;  //Generate number between 0 to 2147483645*/
    
   int sz4 = 274835;
   int sirala4[sz4];
   for(int i=0;i<sz4;i++)
      sirala4[i]=rand()%145460;  //Generate number between 0 to 2147483645*/
    
   int sz5 = 24835;
   int sirala5[sz5];
   for(int i=0;i<sz5;i++)
      sirala5[i]=rand()%164460;  //Generate number between 0 to 2147483645*/
    
   int sz6 = 24835;
   int sirala6[sz6];
   for(int i=0;i<sz6;i++)
      sirala6[i]=rand()%165440;  //Generate number between 0 to 2147483645*/
    
   int sz7 = 27835;
   int sirala7[sz7];
   for(int i=0;i<sz7;i++)
      sirala7[i]=rand()%16546;  //Generate number between 0 to 2147483645*/

    //Print Dummy Array!
    /*for (int k = 0; k < sz; ++k) {
        cout << sirala[k] << " ";
    }
    cout << "\n";*/



    int sz_1 = sz - 1;
    //Sort Functions:
    selectionSort(sirala,sz);
    insertionSort(sirala1,sz1);
    bubbleSort(sirala2,sz2);
    shellSort(sirala3,sz3);
    mergeSort(sirala4,0,sz_1);
    quickSort(sirala5, 0, sz_1);
    heapSort(sirala6, sz6);
    radixSort(sirala7,sz7);


    //Print sorted arrays
    /*for (int j = 0; j < sz; ++j) {
        cout << sirala[j] << " ";
    }*/

    //Return 0 :)
    return 0;
}
