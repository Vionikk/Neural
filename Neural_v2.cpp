#include <iostream>
#include <cstdlib>

using namespace std;

//Selection sort function
void selectionSort(unsigned long long int	 dizi[], unsigned long long int	 elemanSayisi) {
    unsigned long long int	 i, j, enKucuk, temp;
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
void insertionSort(unsigned long long int	 dizi[], unsigned long long int	 elemanSayisi) {
    unsigned long long int	 i, j, temp;
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
void bubbleSort(unsigned long long int	 dizi[], unsigned long long int	 elemanSayisi) {
    unsigned long long int	 temp;
    unsigned long long int	 i, j;

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
void shellSort(unsigned long long int	 dizi[], unsigned long long int	 elemanSayisi) {
    unsigned long long int	 j;
    for (unsigned long long int	 gap = elemanSayisi / 2; gap > 0; gap /= 2) {
        for (unsigned long long int	 i = gap; i < elemanSayisi; ++i) {
            unsigned long long int	 temp = dizi[i];
            for (j = i; j >= gap && temp < dizi[j - gap]; j -= gap) {
                dizi[j] = dizi[j - gap];
            }
            dizi[j] = temp;
        }
    }
}

//Merge sort functions
void merge(unsigned long long int	 arr[], unsigned long long int	 l, unsigned long long int	 m, unsigned long long int	 r) {
    unsigned long long int	 i, j, k;
    unsigned long long int	 n1 = m - l + 1;
    unsigned long long int	 n2 = r - m;

    /* create temp arrays */
    unsigned long long int	 L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back unsigned long long int	o arr[l..r]*/
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
void mergeSort(unsigned long long int	 dizi[], unsigned long long int	 l, unsigned long long int	 r) {
    if (l < r) {
        unsigned long long int	 m = l + (r - l) / 2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(dizi, l, m);
        mergeSort(dizi, m + 1, r);
        merge(dizi, l, m, r);
    }
}

//Quick sort function
void quickSort(unsigned long long int	 arr[], unsigned long long int	 left, unsigned long long int	 right) {
    unsigned long long int	 i = left, j = right;
    unsigned long long int	 tmp;
    unsigned long long int	 pivot = arr[(left + right) / 2];

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
void swap(unsigned long long int	 a[], unsigned long long int	 *g, unsigned long long int	 *b) {
    unsigned long long int	 temp;
    temp = a[*g];
    a[*g] = a[*b];
    a[*b] = temp;
}

void maxHeapify(unsigned long long int	 a[], unsigned long long int	 parent, unsigned long long int	 last) {
    unsigned long long int	 child;
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

void buildHeap(unsigned long long int	 a[], unsigned long long int	 last) {
    unsigned long long int	 i;
    for (i = last / 2; i > 0; i--) {
        maxHeapify(a, i, last);
    }
}

void heapSort(unsigned long long int	 a[], unsigned long long int	 last) {
    unsigned long long int	 l;
    l = 1;
    buildHeap(a, last);
    while (last > 1) {
        swap(a, &l, &last);
        last--;
        maxHeapify(a, 1, last);
    }
}

//Radix sort function
unsigned long long int	 getMax(unsigned long long int	 arr[], unsigned long long int	 n) {
    unsigned long long int	 max = arr[0];
    for (unsigned long long int	 i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(unsigned long long int	 arr[], unsigned long long int	 n, unsigned long long int	 exp) {
    unsigned long long int	 output[n];
    unsigned long long int	 i, count[10] = {0};
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

void radixSort(unsigned long long int	 arr[], unsigned long long int	 n) {
    unsigned long long int	 m = getMax(arr, n);
    for (unsigned long long int	 exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

unsigned long long int main() {
    //Create Dummy Array!!!
    //cout << "SORT ME LIKE YOU DO!" << endl;
    
    
   unsigned long long int	 sz = 274835456456;
   unsigned long long int	 sirala[sz];
   for(unsigned long long int	 i=0;i<sz;i++)
      sirala[i]=rand()%165460;  //Generate number between 0 to 2147483645
    
   unsigned long long int	 sz1 = 274835345345;
   unsigned long long int	 sirala1[sz1];
   for(unsigned long long int	 i=0;i<sz1;i++)
      sirala1[i]=rand()%165460;  //Generate number between 0 to 2147483645
    
   unsigned long long int	 sz2 = 27483521312;
   unsigned long long int	 sirala2[sz2];
   for(unsigned long long int	 i=0;i<sz2;i++)
      sirala2[i]=rand()%165460;  //Generate number between 0 to 2147483645
    
   unsigned long long int	 sz3 = 27483123125;
   unsigned long long int	 sirala3[sz3];
   for(unsigned long long int	 i=0;i<sz3;i++)
      sirala3[i]=rand()%165460;  //Generate number between 0 to 2147483645*/

    //Prunsigned long long int	 Dummy Array!
    /*for (unsigned long long int	 k = 0; k < sz; ++k) {
        cout << sirala[k] << " ";
    }
    cout << "\n";*/



    unsigned long long int	 sz_1 = sz - 1;
    //Sort Functions:
    selectionSort(sirala,sz);
    insertionSort(sirala1,sz1);
    bubbleSort(sirala2,sz2);
    shellSort(sirala3,sz3);
    mergeSort(sirala,0,sz_1);
    quickSort(sirala, 0, sz_1);
    heapSort(sirala, sz);
    radixSort(sirala,sz);


    //Prunsigned long long int	 sorted arrays
    /*for (unsigned long long int	 j = 0; j < sz; ++j) {
        cout << sirala[j] << " ";
    }*/

    //Return 0 :)
    return 0;
}
