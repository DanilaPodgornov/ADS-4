// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    int startIndex = 0;
    int endIndex = size - 1;

    while (startIndex <= endIndex) {
        int middleIndex = startIndex + (endIndex - startIndex) / 2;
        if (value == arr[middleIndex]) {
            int count = 0;
            int border = middleIndex - 1;
            while (value == arr[middleIndex]) {
                middleIndex++;
                count++;
            }
            while (value == arr[border]) {
                border--;
                count++;
            }
            return count;
        } else if (value < arr[middleIndex]) {
            endIndex = middleIndex - 1;
        } else {
            startIndex = middleIndex + 1;
        }
    }
    return 0;
}

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int start = 0;
    int end = len - 1;
    int count = 0;
    while (start < end) {
        for (int i = start + 1; i <= end; i++) {
            if (arr[start] + arr[i] == value) {
                count++;
            }
        }
        start++;
        for (int j = end - 1; j >= start; j--) {
            if (arr[end] + arr[j] == value) {
                count++;
            }
        }
        end--;
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int i = 0;
    int count = 0;
    int border = 0;
    while (arr[i] < value / 2) {
        count += cbinsearch(arr + i + 1, len - i - 1, value - arr[i]);//2 + 2 + 
        i++;
    }
    while (arr[i] == value / 2) {
        border += cbinsearch(arr + i + 1, len - i - 1, value - arr[i]);
        i++;
    }
    border /= 2;
    return count + border;
}
