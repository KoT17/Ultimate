#include <string>

using namespace std;

class pull_object {
public:
  int position;
  string name;
  string success;

  pull_object();
  pull_object(int p, string n, string s);
  bool is_succesful();
  int get_position();
  string get_name();
};
