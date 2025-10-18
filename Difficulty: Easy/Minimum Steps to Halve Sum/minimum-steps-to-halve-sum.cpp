class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
          double sum = 0;
    for (int num : arr) sum += num;

    double target = sum / 2.0;

    // Step 2: Use max-heap to always halve the largest element
    priority_queue<double> pq;
    for (int num : arr) pq.push(num);

    int ops = 0;
    double reducedSum = sum;

    while (reducedSum > target) {
        double largest = pq.top();
        pq.pop();

        double half = largest / 2.0;
        reducedSum -= half; // total sum decreases by half the value
        pq.push(half);      // push the halved value back into heap

        ops++;
    }

    return ops;
    }
};