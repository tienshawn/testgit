int onesAndZeros(char* s)
{
    int n;
    sscanf(s, "%d", &n);
    int arr[1000] = {};
    int count = 0;
    while (n > 0) {
        arr[count] = n % 10;
        count++;
        n = n /10;
    }
    int len = count;
    for (int i = count - 1; i >= 0; i--) {
        if (arr[i] == 0 && arr[i+1] == 1) {
            len -= 2;
        }
    }
    printf("%d", len);
}