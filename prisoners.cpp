# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>

using namespace std;

vector<int> randomList(int size);

int main(){
  srand(time(NULL)); //sets the random seed
  int prisonerCount;
  int tries;
  int trials;
  int sucsesses = 0;
  cout << "How many prisoners?" << endl;
  cin >> prisonerCount;
  cout << "How many tries?" << endl;
  cin >> tries;
  cout << "How many trials?" << endl;
  cin >> trials;
  cout << "Running" << endl;
  int progress = 0;
  for (int i = 0; i < trials; i++){
    vector<int> boxes = randomList(prisonerCount);
    bool win = true;
    int j = 0;
    while (win == true && j < prisonerCount){
      int k = -1;
      int l = j;
      bool currentPass = false;
      do{ 
	k++;
	l = boxes[l];
	if (l == j){
	  currentPass = true;
	}
      }while (k < tries && currentPass == false);
      win = currentPass;
      j++;
    }
    sucsesses += win;
    if (100*i/trials > progress){
      progress =100*i/trials;
      cout << progress << endl;
    }
  }
  cout << "Won " << sucsesses << " times" << endl;
  cout << 100*sucsesses/trials <<" %" << endl; 
}
vector<int> randomList(int size){
  vector<int> output;
  vector<int> list;
  for(int i = 1; i < size+1; i++){
    list.push_back(i);
  }
  for (int i = 0; i < size; i++){
    int random = rand() %(size-i);
    output.push_back(list.at(random));
    list.erase(list.begin() + random);
  }
  return output;
}
