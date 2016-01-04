#include <fstream>
#include <string>
 
using namespace std;
 
string paran = "[]()";
 
string process(string s) {
  string ret;
  for(const auto &c: s) {
    if(paran.find_first_of(c) != paran.npos) {
      ret += c;
    } else if(c == '*') {
      if(!ret.empty())
        ret.pop_back();
    } else if(c == 'E') {
      return ret;
    }
  }
  throw(11);
}
 
char match[sizeof(char) * 256];
 
bool good(string s) {
  string st;
  for(const auto &c: s) {
    if(c == '(' || c == '[') {
      st += c;
    } else {
      if(st.empty())
        return false;
      const char m = match[(int)c];
      if(st.back() != m)
        return false;
      st.pop_back();
    }
  }
  return st.empty();
}
 
string solve(string s) {
  string fin = process(s);
 
  if(good(fin))
    return ":)";
  else
    return ":(";
}
 
int main() {
 
  match[(int)']'] = '[';
  match[(int)')'] = '(';
 
  ifstream in("editor.in");
  ofstream out("editor.out");
  int T;
  in >> T;
  while(T--) {
    string s;
    in >> s;
    out << solve(s) << "\n";
  }
  return 0;
}
