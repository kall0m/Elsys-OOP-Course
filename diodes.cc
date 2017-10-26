#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Pin {
  int number_;
  int state_;
public:
  Pin(int num, int state) : number_(num), state_(state) {}

  int get_number() const {
    return number_;
  }

  int get_state() const {
    return state_;
  }

  Pin& set_number(int num) {
    number_ = num;
    return *this;
  }

  Pin& set_state(int state) {
    state_ = state;
    return *this;
  }

  void print() const {
    cout << "Pin " << number_ << "->" << state_ << endl;
  }
};

void init(int diodes[4][4], vector<Pin>& pins) {
  for(int i = 2; i <= 9; i++) {
    Pin p(i, 0);
    pins.push_back(p);
  }

  int i = 0;
  for(; i < 4; i++) {
    cout << pins[i].get_number() << " |";
    for(int j = 0; j < 4; j++) {
      diodes[i][j] = 0;
      cout << diodes[i][j] << " ";
    }
    cout << endl;
  }

  while(i < 8) {
    cout << pins[i].get_number() << " |" << endl;
    i++;
  }

  cout << endl;
}

void print_diodes(int diodes[4][4]) {
  int i = 0;
  for(; i < 4; i++) {
    cout << i + 2 << " |";
    for(int j = 0; j < 4; j++) {
      cout << diodes[i][j] << " ";
    }
    cout << endl;
  }

  while(i < 8) {
    cout << i + 2 << " |" << endl;
    i++;
  }

  cout << endl;
}

int main() {
  int diodes[4][4];
  vector<Pin> pins;

  init(diodes, pins);

  int diode_c, diode_a;

  string input;

  cout << "To quit write 'stop'." << endl << "For new scheme write 'new'." << endl;

  while(true) {
    cout << "Input pin from 2 to 5 and pin from 6 to 9 separated with space and see the magic: ";
    getline(cin, input);

    if(input == "stop") {
      cout << "Bye!" << endl;
      break;
    }

    if(input == "new") {
      init(diodes, pins);
      continue;
    }

    istringstream in(input);
    int diode_c, diode_a;
    in >> diode_c;
    in >> diode_a;

    if(diode_c > 5 || diode_a <= 5) {
      cout << endl;
      print_diodes(diodes);
      continue;
    }

    cout << endl;

    pins[diode_a - 2].set_state(1);
    pins[diode_a - 2].print();

    pins[diode_c - 2].print();

    cout << endl;

    diodes[diode_c - 2][diode_a - 4 - 2] = 1;

    print_diodes(diodes);
  }

  return 0;
}
