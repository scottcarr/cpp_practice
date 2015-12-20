#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

int binary_search(int arr[], int target, int low, int high) {
  if (low == high) 
  { 
    if (arr[low] == target) { return low;}
    else { return -1; }
  }
  int mid = (high - low) / 2;
  if (arr[mid] == target) { return mid; }
  if (arr[mid] < target) { return binary_search(arr, target, mid + 1, high); }
  if (arr[mid] > target) { return binary_search(arr, target, low, mid - 1); }
  return -1;
}

class BinNode {
  public:
    int data;
    BinNode* leftChild = nullptr;
    BinNode* rightChild = nullptr;
    BinNode(int x) : data(x) {}
};
class BinTree {
  BinNode* root = nullptr;
  public:
  BinTree() { }
  void insert(int x) {
    if (!root) {
      root = new BinNode(x);
    } else {
      recInsert(x, root);
    }
  }
  void recInsert(int x, BinNode* curr) {
    if (x <= curr->data) {
      if (!curr->leftChild) {
        curr->leftChild = new BinNode(x);
      } else {
        recInsert(x, curr->leftChild);
      }
    } else {
      if (!curr->rightChild) {
        curr->rightChild = new BinNode(x);
      } else {
        recInsert(x, curr->rightChild);
      }
    }
  }
  void print() {
    recPrint(root);
    cout << "\n";
  }
  void recPrint(BinNode* curr) {
    if (curr->leftChild) {
      recPrint(curr->leftChild);
    }
    cout << curr->data << " ";
    if (curr->rightChild) {
      recPrint(curr->rightChild);
    }
  }
};

bool isWhiteSpace(char c) {
  if (c == '\n') { return true; }
  if (c == '\r') { return true; }
  if (c == '\t') { return true; }
  if (c == ' ') { return true; }
  return false;
}

int count_words(string filename) {
  ifstream inFile(filename.c_str(), ifstream::in);
  stringstream ss;
  ss << inFile.rdbuf();
  string text = ss.str();
  int n_words = 0;

  for (int i = 0, N = text.size(); i < N; ++i) {
    if (i == 0) {
      if (!isWhiteSpace(text[i])) {
      n_words++;
      } else {
        continue;
      }
    }
    if (isWhiteSpace(text[i-1]) && !isWhiteSpace(text[i])) {
      n_words++;
    }
  }
  return n_words;
}

//map<string, int> get_word_counts(string filename) {
//}

void print_k_lines(string filename, int k) {
  // what should it do when k > # lines in file?
  //
  // print the last k lines in a file
  ifstream infile("test.txt");

  int i = 0;
  string line;
  while(getline(infile, line)) {
    ++i;
  }
  int N = i;
  //cout << "# lines: " << N << "\n";
  int start = N - k;
  i = 0;
  infile.seekg(0, ios::beg);
  infile.clear();
  while(getline(infile, line)) {
    if (i >= start) {
      cout << line << "\n";
    }
    ++i;
  }
}

void count_all_words(string filename) {
  map<string, int> word_counts;

  ifstream inFile(filename.c_str(), ifstream::in);
  stringstream ss;
  ss << inFile.rdbuf();
  string text = ss.str();
  int n_words = 0;

  stringstream match;

  for (int i = 0, N = text.size(); i < N; ++i) {
    if (!isWhiteSpace(text[i])) {
      match << text[i];
    } else {
      // end word or space
      cout << "word: " << match.str() << "\n";
      if (word_counts.find(match.str()) == word_counts.end()) {
        word_counts[match.str()] = 1;
      } else {
        word_counts[match.str()]++;
      }
      match.str("");
      match.clear();
    }
  }

  // the last word can be right before the EOF without a space
  if (!isWhiteSpace(text[text.size()-1])) {
    if (word_counts.find(match.str()) == word_counts.end()) {
      word_counts[match.str()] = 1;
    } else {
      word_counts[match.str()]++;
    }
  }

  for (auto p : word_counts) {
    auto word = p.first;
    auto count = p.second;
    cout << word << " " << count << "\n";
  }

}

int count_this_word(string filename, string the_word) {
  ifstream inFile(filename.c_str(), ifstream::in);
  stringstream ss;
  ss << inFile.rdbuf();
  string text = ss.str();
  int n_words = 0;

  stringstream match;

  for (int i = 0, N = text.size(); i < N; ++i) {
    if (!isWhiteSpace(text[i])) {
      match << text[i];
    } else {
      cout << "word: " << match.str() << "\n";
      // end word or space
      if (the_word.compare(match.str()) == 0) {
        n_words++;
      }
      match.str("");
      match.clear();
    }
  }

  // word can end at EOF without trailing space
  if (the_word.compare(match.str()) == 0) {
    n_words++;
  }

  return n_words;
}


// Q1: sort a list of 10 ints not using merge sort

void print_ints(int arr[], int len) {
  cout << "ints:";
  for (int j = 0; j < len; j++) {
    cout << " " << arr[j];
  }
  cout << "\n";
}

int get_min_idx(int arr[], int start, int end) {
  int lowest = arr[start];
  int min_idx = start;
  for (int i = start; i < end; ++i) {
    if (arr[i] < lowest) {
      lowest = arr[i];
      min_idx = i;
    }
  }
  return min_idx;
}

void sort_ints(int arr[], int len) {
  // check if arr is null?
  for (int j = 0; j < len; j++) {
    int min_idx = get_min_idx(arr, j, len);
    int tmp = arr[j];
    arr[j] = arr[min_idx];
    arr[min_idx] = tmp;
  }
}

void test_q1_1() {
  int arr[] = {3, 4, 2, 5, 6, 7, 8, 1, 10, 42};
  sort_ints(arr, 10);
  print_ints(arr, 10);
}



// Q2: calculate the (integer floor of the) square root of a number using binary search
// the number is a uint32_t


// Q1: count number of words in a file
// Q2: occurances of specific word in a file
// Q3: word count every word in a file


// CCIp54: given a string, generate all permutations of all characters in the string

vector<string> add_char(vector<string> orig_perms, string c) {
  vector<string> new_perms;
  for (auto p : orig_perms) {
    for (int i = 0, N = p.size()+1; i < N; ++i) {
      string p_copy(p);
      auto tmp = p_copy.insert(i, c);
      //cout << tmp << endl;
      //cout << p << endl;
      new_perms.push_back(tmp);
    }
  }
  return new_perms;
}
vector<string> get_perms(string orig) {
  vector<string> perms;
  perms.push_back(string(1, orig[0]));

  for (int i = 1, N = orig.size(); i < N; ++i) {
    perms = add_char(perms, string(1,orig[i]));
  }

  return perms;
}

void test_CCIp54() {
  auto orig = "abc";
  auto perms = get_perms(orig);
  cout << "perms:";
  for (auto p : perms) {
    cout << " " << p;
  }
  cout << "\n";
}


int main(int argc, char** argv) {

  //int arr[] = {0, 1, 2, 3};
  //cout << binary_search(arr, 1, 0, sizeof(arr)/sizeof(int)-1) << "\n";
  
  //BinTree* tree = new BinTree();
  //tree->insert(10);
  //tree->insert(3);
  //tree->insert(1);
  //tree->insert(99);
  //tree->insert(98);
  //tree->insert(100);

  //tree->print();
  
  //print_k_lines("test.txt", 3);
  //cout << "# words: " << count_words("words.txt") << "\n";

  //cout << "# words: " << count_this_word("words.txt", "hello") << "\n";
  
  //count_all_words("words.txt");

  //test_q1_1();

  test_CCIp54();

  return 0;
}
