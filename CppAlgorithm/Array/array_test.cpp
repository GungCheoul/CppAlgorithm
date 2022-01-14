// counting number by using array
// use index to check whether the number is existing or not

int func(int arr[], int N) {
    int occur[101] = {};
    for (int i = 0; i < N; i++) {
        if (occur[100 - arr[i]] == 1)
            return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}