#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Initial Some Function
#define pop(pda, i) pda.erase(remove(pda.begin(), pda.end(), i), pda.end())
#define push(pda, i) pda.push_back(i)
#define top(pda) pda.back()

// Dictionary
string S[5] = {"saya","budi","dia","kamu","andi"};
string P[5] = {"melihat","bermain","belajar","membaca","melempar"};
string O[5] = {"bola","tba","buku","air","pbo"};
string K[5] = {"sekarang","lusa","besok","nanti","kemarin"};

vector<char> pda;

bool isS(string word) {

  // initial state
  int n = 0;
  bool status = false;

  // check
  for(string s : S) {
    n = 0;
    for(int i = 0;i < s.size();i++)
      if(word[i] == s[i]) n++;

    if(n == s.size()) {
      status = true;
      break;
    }
  }

  return status;
}

bool isP(string word) {

  // initial state
  int n = 0;
  bool status = false;

  // check
  for(string p : P) {
    n = 0;
    for(int i = 0;i < p.size();i++)
      if(word[i] == p[i]) n++;

    if(n == p.size()) {
      status = true;
      break;
    }
  }

  return status;
}

bool isO(string word) {

  // initial state
  int n = 0;
  bool status = false;

  // check
  for(string o : O) {
    n = 0;
    for(int i = 0;i < o.size();i++)
      if(word[i] == o[i]) n++;

    if(n == o.size()) {
      status = true;
      break;
    }
  }

  return status;
}

bool isK(string word) {

  // initial state
  int n = 0;
  bool status = false;

  // check
  for(string k : K) {
    n = 0;
    for(int i = 0;i < k.size();i++)
      if(word[i] == k[i]) n++;

    if(n == k.size()) {
      status = true;
      break;
    }
  }

  return status;
}

bool isValid(vector<string> words) {

  // initital state
  bool status = false;
  if(pda.empty()) pda.push_back('#');
  pda.push_back('$');

  // check
  for(string word : words) {

    if (isS(word)) {
        pop(pda, '$');
        push(pda, 'S');
        cout << top(pda);
    } else if (isP(word)) {
        pop(pda, 'S');
        push(pda, 'P');
        cout << top(pda);
    } else if (isO(word)) {
        pop(pda, 'P');
        push(pda, 'O');
        cout << top(pda);
    } else if (isK(word)) {
        if (top(pda) == 'P')
            pop(pda, 'P');
        else if (top(pda) == 'O')
            pop(pda, 'O');
        push(pda, 'K');
        cout << top(pda);
    } else {
        push(pda, ' ');
        cout << '_';
    }

  }
  cout << " ";

  // final state
  if (top(pda) == 'P' || top(pda) == 'O' || top(pda) == 'K') pda.pop_back();

  // check
  return top(pda) == '#' ? true:false;
}

string toLower(string word) {
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  return word;
}

int main() {

  do {
    // input sentence
    string sentence;
    cout << ">> ";
    getline(cin, sentence);
    sentence = toLower(sentence);

    // exit
    if(sentence == "exit") break;

    // split sentence by space into vector
    vector<string> wordlist;
    istringstream s(sentence);
    for(string sentence; s >> sentence; ) wordlist.push_back(sentence);

    // output
    cout << "=> " << (isValid(wordlist) ? "Valid" : "Invalid") << "\n";

  } while(true);

  return 0;
}

