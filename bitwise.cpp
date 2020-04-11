#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
void solution(vector<vector<int>>& numberPairs);
void printNumberPairs(vector<vector<int>>& np);


int main()
{
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  
  vector<vector<int>> numberPairs;

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    vector<int> tmp;
    tmp.push_back(stoi(nk[0]));
    tmp.push_back(stoi(nk[1]));

    numberPairs.push_back(tmp);
  }

  // printNumberPairs(numberPairs);
  solution(numberPairs);

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
      return x == y and x == ' ';
  });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
      input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
      splits.push_back(input_string.substr(i, pos - i));

      i = pos + 1;
      pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}

void printNumberPairs(vector<vector<int>>& np) {
  for (int i = 0; i < np.size(); i++) {
    for (int j = 0; j < np[i].size(); j++) {
      printf("[%d][%d] = %d\n", i, j, np[i][j]);
    }
  }
}

// numberPairs[i][0] = N
// numberPairs[i][1] = K
// set S = {1, 2, 3, ... , N}
// 2 <= K <= N
void solution(vector<vector<int>>& numberPairs) {
  vector<vector<int>> S; // conains a list of sets S
  vector<int> solution;

   for (int i = 0; i < numberPairs.size(); i++) {
    vector<int> tmpS;
    int max = 0;
    int tmp;
    // form the S set based on numberPairs[i][0] (N)
    for (int q = 1; q <= numberPairs[i][0]; q++) {
      tmpS.push_back(q);
    }

    // debug
    // cout << "k = " << numberPairs[i][1] << endl;

    // find max
    for (int p = 0; p < tmpS.size(); p++) {
      for (int r = p + 1; r < tmpS.size(); r++) {
        tmp = tmpS[p] & tmpS[r];
        // debug
        // printf("i=%d, tmp=%d, K=%d\n", i, tmp, numberPairs[i][1]);
        if ( (tmp > max) && (tmp < numberPairs[i][1]) ) {
          max = tmp;
        }
      }
      // debug
      // printf("\n");
    }
    // solution.push_back(tmp); // BUG !
    solution.push_back(max);
   }

   for (int l = 0; l < solution.size(); l++) {
     cout << solution[l] << endl;
   }
}