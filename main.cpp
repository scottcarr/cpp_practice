#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <math.h>
#include <assert.h>
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

void are_all_unique(string test_str) {
  char counts[256];

  memset(counts, 0, 256);

  for (int i = 0, N = test_str.size(); i < N; ++i) {
    counts[test_str[i]]++;
  }

  for (int i = 0; i < 256; ++i) {
    if (counts[i] > 1) {
      cout << "not unique\n";
      return;
    }
  }

  cout << "unique\n";
}

void test_CCI1_1() {
  // implement an algorithm to test if a string has all unique characters
  // do no use additional data structures
  
  string test_str1("hello");
  string test_str2("abcdef");
  are_all_unique(test_str1);
  are_all_unique(test_str2);

}

void reverse(char* str) {
  int N = strlen(str);
  for (int i = 0; i < N/2; ++i) {
    int tmp = str[i];
    int tmp2 = str[N-1-i];
    str[N-1-i] = tmp;
    str[i] = tmp2;
  }
}

void test_CCI1_2() {
  // implement a function reverse(char* str) that reverses a null terminated string
  
  char* str = (char*)malloc(100);
  strcpy(str, "hello");
  printf("%s\n", str);
  reverse(str);
  printf("%s\n", str);
  strcpy(str, "goodbye");
  printf("%s\n", str);
  reverse(str);
  printf("%s\n", str);
  free(str);
}

void count_chars(string str, char* counts) {
  memset(counts, 0, 256);
  for (int i = 0, N = str.size(); i < N; ++i) {
    counts[str[i]]++;
  }
}

bool isPermutation(string str1, string str2) {
  char str1_counts[256];
  char str2_counts[256];

  count_chars(str1, str1_counts);
  count_chars(str2, str2_counts);

  for (int i = 0; i < 256; ++i) {
    if (str1_counts[i] != str2_counts[i]) {
      cout << "not a perm\n";
      return false;
    }
  }

  cout << "is a perm\n";
  return true;

}

void test_CCI1_3() {
  // given two strings write a function to decide if one is a permutation of the other
  
  string str1("hello");
  string str2("helloo");
  isPermutation(str1, str2);

  string str3("hello");
  string str4("olleh");
  isPermutation(str3, str4);
  
}

void replace20(string& str) {
  int i = 0;
  while (i + 2 < str.size()) {
    if (str[i] == '%' && str[i+1] == '2' && str[i+2] == '0') {
      cout << "i: " << i << " replacing...\n";
      str.erase(i,3);
      str.insert(i, string(" "));
    }
    ++i;
  }
}

void test_CCI1_4() {
  // given a string, replace all instances of %20 with spaces
  
  string str1("hello%20world");
  replace20(str1);
  cout << str1 << endl;
  string str2("hello%20world%20");
  replace20(str2);
  cout << str2 << endl;
}

int count_repeats(string str, int idx) {
  char letter = str[idx];
  int count = 1;
  for (int i = idx-1; i >= 0; --i) {
    if (str[i] == letter) {
      count++;
    } else {
      break;
    }
  }
  return count;
}

bool try_replace(string& str, int& i) {
  int count = count_repeats(str, i);
  cout << "count: " << count << endl;
  if (count > 2) {
    stringstream ss;
    ss << str[i];
    ss << count;
    str.replace(i-(count-1), count, ss.str());
    i = i - (count-1)+1;
    return true;
  }
  return false;
}

void compress(string& str) {
  for (int i = 1; i < str.size(); ++i) {
    if (str[i-1] != str[i]) {
      cout << "end conseq at: " << i-1 << endl;
      // transition
      int idx = i - 1;
      if (try_replace(str, idx)) {
        i = idx;
      }
    }
  }
  int n = (int)str.size()-1;  
  try_replace(str, n);
}

void test_CCI1_5() {
  // implement string compression by replacing repeated characters by a count
  // ex: aaabbb => a3b3
  
  string str1("aaabbb");
  compress(str1);
  cout << str1 << endl;
  string str2("abaabbb");
  compress(str2);
  cout << str2 << endl;
  string str3("cabaabbbcccbccc");
  compress(str3);
  cout << str3 << endl;

}

class SquareMatrix {
  private:
    int N;
    vector<int> data;
  public:
    SquareMatrix(vector<int> init) {
      N = sqrt(init.size()); 
      if (N*N != init.size()) {
        assert(0);
      }
      data = init;
    }
    int& at(int i, int j) {
      return data[i*N+j];
    } 
    void print() {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          cout << this->at(i,j) << " ";
        }
        cout << endl;
      }
    }
    void rotate_90() {
      SquareMatrix rotated(data);
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          //cout << "swaping: " << i << " " << j << endl;
          //cout << "width: " << j << " " << N-i-1 << endl;
          rotated.at(j, N-1-i) = this->at(i,j);
        }
      }
      this->data = rotated.data;
    }
};


void test_CCI1_6() {
  // given an NxN matrix, rotate it 90 degrees,
  // can it be done in place?
  
  /*
   * 1 2 3
   * 4 5 6
   * 7 8 9
   *
   * 7 4 1
   * 8 5 2
   * 9 6 3
   *
   * (0,0) -> (0,N-1)
   * (0,1) -> (1, N-1)
   */

   int init[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   vector<int> initV(init, init + sizeof(init)/sizeof(int));
   
   SquareMatrix mat(initV);
   mat.print();
   cout << endl;
   mat.rotate_90();
   mat.print();

   cout << endl;

   int init2[] = {1, 2, 3, 4};
   vector<int> initV2(init2, init2 + sizeof(init2)/sizeof(int));
   
   SquareMatrix mat2(initV2);
   mat2.print();
   cout << endl;
   mat2.rotate_90();
   mat2.print();
}

class Node {
  public:
  int data;
  Node* next = nullptr;
  Node(int d) : data(d) {}
};

Node* make_list(vector<int> data) {
  Node* head = new Node(data[0]); 
  Node* prev = head;
  for (int i = 1; i < data.size(); ++i) {
    Node* curr = new Node(data[i]);
    prev->next = curr;
    prev = curr;
  }
  prev->next = nullptr;
  return head;
}

Node* remove_duplicates(Node* head) {
  set<int> seen;
  Node* curr_new = nullptr;
  Node* new_head = nullptr;
  Node* curr_old = head;

  while(curr_old) {
    int i = curr_old->data;
    curr_old = curr_old->next;
    if (seen.find(i) == seen.end()) {
      seen.insert(i);
      if (!curr_new) {
        curr_new = new Node(i);
        new_head = curr_new;
      } else {
        auto tmp = new Node(i);
        curr_new->next = tmp;
        curr_new = tmp;
      }
    }
  }
  curr_new->next = nullptr;
  return new_head;
}

void print_list(Node* head) {
  Node* curr = head;
  while(curr) {
    cout << " " << curr->data;
    curr = curr->next;
  }
  cout << endl;
}

void test_CCI_2_1() {
  vector<int> data;
  data.push_back(0);
  data.push_back(1);
  data.push_back(42);
  data.push_back(1);
  data.push_back(74);
  auto head = make_list(data);
  print_list(head);
  cout << endl;
  auto unduped = remove_duplicates(head);
  print_list(unduped);
}

Node* returnKth(Node* head, int k) {
  Node* leader;
  Node* follower;

  leader = head;
  for (int i = 0; i <= k; ++i) {
    if (!leader) { return nullptr; }  // there aren't k elements
    leader = leader->next;
  }

  follower = head;

  while(leader) {
    leader = leader->next;
    follower = follower->next;
  }
  return follower;
}

void test_CCI_2_2() {
  // return the kth to last element of a singely linked list
  vector<int> data;
  data.push_back(0);
  data.push_back(1);
  data.push_back(42);
  data.push_back(1);
  data.push_back(74);
  auto head = make_list(data);
  auto found = returnKth(head, 4);
  cout << found->data << endl;
  found = returnKth(head, 3);
  cout << found->data << endl;
  found = returnKth(head, 2);
  cout << found->data << endl;
  found = returnKth(head, 1);
  cout << found->data << endl;
  found = returnKth(head, 0);
  cout << found->data << endl;
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

  //test_CCIp54();

  //test_CCI1_1();
  //test_CCI1_2();
  //test_CCI1_3();
  //test_CCI1_4();
  //test_CCI1_5();
  //test_CCI1_6();
  //test_CCI_2_1();
  test_CCI_2_2();

  return 0;
}
