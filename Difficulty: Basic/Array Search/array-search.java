class Solution {
    public int search(int arr[], int x) {
        // code here
        for(int i =0;i< arr.length;i++){
            if(arr[i] == x){
                return i;
            }
        }
        return -1;
    }
}
