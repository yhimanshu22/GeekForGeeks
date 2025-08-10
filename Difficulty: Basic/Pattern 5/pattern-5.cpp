class Solution {
  public:

    void printTriangle(int n) {
        // code here
          for (int i = n; i > 0; i--) {       // Number of rows
            for (int j = 0; j < i; j++) {   // Stars in each row
                cout << "* ";
            }
            cout << endl;
        }
    }
};