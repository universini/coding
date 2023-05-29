#include <iostream>
#include <string>

using namespace std;

class BaseClass {
 public:
  int str_len(string s1) { return (s1.size()); }

  int str_cmp(string s1, string s2) {
    string::iterator it1, it2;

    for (it1 = s1.begin(), it2 = s2.begin();
         it1 != s1.end() || it2 != s2.end();
         ++it1, ++it2) {
      if (*it1 != *it2) {
        return (*it1 - *it2);
      }
    }

    return (0);
  }

 protected:
  string s1;
};

class DerivedClass : public BaseClass {};

/*
  class Base {
    public:
      int x;
    protected:
      int y;
    private:
      int z;
  };

  class PublicDerived: public Base {
    // x is public
    // y is protected
    // z is not accessible from PublicDerived
  };

  class ProtectedDerived: protected Base {
    // x is protected
    // y is protected
    // z is not accessible from ProtectedDerived
  };

  class PrivateDerived: private Base {
    // x is private
    // y is private
    // z is not accessible from PrivateDerived
  };
*/
class Base {
  private:
    int pvt = 1;

  protected:
    int prot = 2;

  public:
    int pub = 3;

    // function to access private member
    int getPVT() {
      return pvt;
    }
};

class PrivateDerived : private Base {
  public:
    // function to access protected member from Base
    int getProt() {
      return prot;
    }

    // function to access private member
    int getPub() {
      return pub;
    }
};

class ProtectedDerived : protected Base {
  public:
    // function to access protected member from Base
    int getProt() {
      return prot;
    }

    // function to access public member from Base
    int getPub() {
      return pub;
    }
};

class PublicDerived : public Base {
  public:
    // function to access protected member from Base
    int getProt() {
      return prot;
    }
};

int main() {
  PrivateDerived object1;
  cout << "Private cannot be accessed." << endl;
  // cout << "Private = " << object1.getPVT() << endl;
  cout << "Protected = " << object1.getProt() << endl;
  cout << "Public = " << object1.getPub() << endl;
  cout << endl;

  ProtectedDerived object2;
  cout << "Private cannot be accessed." << endl;
  // cout << "Private = " << object2.getPVT() << endl;
  cout << "Protected = " << object2.getProt() << endl;
  cout << "Public = " << object2.getPub() << endl;
  cout << endl;

  PublicDerived object3;
  cout << "Private = " << object3.getPVT() << endl;
  cout << "Protected = " << object3.getProt() << endl;
  cout << "Public = " << object3.pub << endl;
  cout << endl;

  DerivedClass object4;

  string s = "Sidde";
  cout << "String length: " << object4.str_len(s) << "\n";
  cout << "Strings compare: " << object4.str_cmp(s, "sidde");
  cout << endl;

  return 0;
}
