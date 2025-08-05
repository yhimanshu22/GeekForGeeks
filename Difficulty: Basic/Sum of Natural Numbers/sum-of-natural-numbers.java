class Solution {
    public static int findSum(int n) {
        // code here
        int count =1;
        int sum = 0;
        while(count<=n){
            sum+=count;
            count++;
        }
        return sum;
    }
}
