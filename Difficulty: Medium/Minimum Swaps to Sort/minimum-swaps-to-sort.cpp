class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Pair each element with its index
        vector<pair<int,int>> temp(n);
        for(int i = 0; i < n; i++)
            temp[i] = {arr[i], i};

        // Step 2: Sort the array by element values
        sort(temp.begin(), temp.end());

        // Step 3: Track visited elements
        vector<bool> visited(n, false);
        int swaps = 0;

        for(int i = 0; i < n; i++) {
            // Already visited or already in correct position
            if(visited[i] || temp[i].second == i)
                continue;

            // Find the size of the cycle
            int cycle_size = 0;
            int j = i;
            while(!visited[j]) {
                visited[j] = true;
                j = temp[j].second;
                cycle_size++;
            }

            // If there is a cycle of size k, we need (k-1) swaps
            if(cycle_size > 1)
                swaps += (cycle_size - 1);
        }

        return swaps;
    }
};
