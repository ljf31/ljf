void adjustHeap(int a[], int pos, int len){
    int parent = pos;
    int child = pos * 2 + 1;
    int tmp;
    while (child < len){
        if (child + 1 < len && a[child] < a[child + 1])
            child++;
        if (a[parent] < a[child]){
            tmp = a[parent];
            a[parent] = a[child];
            a[child] = tmp;
            parent = child;
            child = 2 * parent + 1;
        }
        else
            break;
    }
}

void buildHeap(int a[], int len){
    int index = (len - 1) / 2;
    int i;
    for (i = index; i >= 0; i--){
        adjustHeap(a, i, len);
    }
}

void heapSort(int a[], int len){
    if (a == NULL || len <= 0)
        return;
    buildHeap(a, len);
    int j, tmp;
    for (j = len - 1; j >= 1; j--){
        tmp = a[0];
        a[0] = a [j];
        a[j] = tmp;
        adjustHeap(a, 0, j);
    }
}
