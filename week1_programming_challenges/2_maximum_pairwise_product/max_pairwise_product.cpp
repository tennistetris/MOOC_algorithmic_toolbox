#include <iostream>
#include <vector>
#include<stdlib.h>


using namespace std;

long long int MaxPairwiseProduct(const vector<int>& numbers) {
  long long int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ( ((long long)numbers[i] * (long long)numbers[j]) > result) {
        result = (long long)numbers[i] * (long long)numbers[j];
      }
    }
  }
  return result;
}

long long int FastPairwiseProduct(const vector<int>& numbers){
  
  long long int result = 0;
  int n = numbers.size();
  int Index1,Index2;
  
  Index1 = 0;
  
  for (int i = 0;i<n;i++){
    if (numbers[i]>=numbers[Index1])Index1=i;
  }

  if (Index1 == 0)Index2 = 1;
  else Index2 = 0;
  
  for(int i = 0;i<n;i++){
    if((numbers[Index2]<numbers[i]) && (i!=Index1)){
      Index2 = i;
    } 
  }
  result = (long long)numbers[Index1]*(long long)numbers[Index2];
  return result;
}

void StressTest(int N,int M){
  int counter = 0;
  int num;
  do{
    srand(time(0));
    //Randomly defining the number of number of elements
    num = 2 + rand()%N;
    vector <int> numbers(num);

    //Randomly defining the elements
    for (int i = 0;i<num;i++){
      numbers[i] = 1 + rand()%M;
    }

    long long int Result1,Result2;
    Result1 = MaxPairwiseProduct(numbers);
    Result2 = FastPairwiseProduct(numbers);

    if(Result1 == Result2){
      counter++;
    }
    else{
      cout <<"Wrong Answer ... \n";

      cout<<"Numbers Array : \n";
      for(int i=0;i<num;i++){
        cout<<numbers[i]<<":";
      }
      
      cout<<"Result 1 (NAIVE): "<<Result1<<endl;
      cout<<"Result 1 (FAST): "<<Result2<<endl;
      cout<<"Iteration No :"<<++counter<<endl;

      break;

    }
    if(counter%10000 == 0){
      cout<<"OK !!\n";
      cout<<"Iteration No :"<<counter<<endl;
    }

  }while(counter <= 1e6);

}

int main() {
  
  int n;
  long long int result;
  cin >> n;
  vector<int> numbers(n);

  for (int i = 0;i<n;i++){
    cout<<"Enter number["<<i<<"]    :   ";
    cin>>numbers[i];
  }


  result = FastPairwiseProduct(numbers);
  cout << result << "\n";
  return 0;

  //StressTest(100,100000);
  //return 0;
}
