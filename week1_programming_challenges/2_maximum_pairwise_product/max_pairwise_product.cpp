#include <iostream>
#include <vector>

using namespace std;

long long int MaxPairwiseProduct(const vector<long long int>& numbers) {
  long long int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

int main() {
    int n;
    //cin >> n;
    n = 2*1e5;
    vector<long long int> numbers(n);
    /*for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    */
    for (int i = 0;i<n;i++){
      numbers[i] = i;
    }

    long long int result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
