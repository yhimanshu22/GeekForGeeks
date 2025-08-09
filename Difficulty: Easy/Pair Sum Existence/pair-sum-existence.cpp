int sumExists(int arr[], int n, int sum) {

    // code here
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j] == sum){
                return 1;
            }
        }
    }
    return 0;
}