class Solution {
  public:
    string isVowel(char c) {
        // code here
         if(c == 'a' || c == 'A' || c == 'e' || c == 'E' 
        || c == 'i' || c == 'I' || c == 'o' || c == 'O' 
        || c == 'u' || c == 'U')return "YES";
        return "NO";
    }
};