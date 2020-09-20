// Example program
#include <iostream>
#include <string>
#include<bits/stdc++.h> 
using namespace std; 

class Customer {
  public:
    int code;
    string name;
    void ini(int code, string name);
};

class Hash { 
  int BUCKET;  

  list<int> *table; 
  list<Customer> *clientes;
  
  public: 
    Hash(int V);
    void insertTest(Customer *cl);
    
    int hashFunction(int x) { 
      return (x % BUCKET); 
    } 
    
  void displayHash(); 
};

void Hash::insertTest(Customer *cl) { 
  int index = hashFunction(cl->code); //OK
  clientes[index].push_back(*cl); 
  int sizetable = sizeof(clientes)/sizeof(clientes[0]);
  cout << "size" << sizetable << endl; //prints 0, no insert worked
  cout << "Look -> " << clientes[index].front().name<<endl;
} 

Hash::Hash(int b) { 
  this->BUCKET = b; 
  clientes = new list<Customer>[BUCKET]; 
} 

void Customer::ini(int code, string name) {
  this->code = code;
  this->name = name;
}

// function to display hash table 
void Hash::displayHash() { 
  for (int i = 0; i < BUCKET; i++) { 
    cout << i; 
    int sizetable = sizeof(clientes)/sizeof(clientes[0]);
    cout << "-->" << sizetable << endl;
    // for (auto &x : table[i]) 
    //   cout << " --> " << x;
    cout << endl; 
  } 
} 

int main() {
    
  Hash h(7);   
    
  Customer *cl = new Customer();
  cl->ini(7, "jack");
  cout << cl->name << endl;
  h.insertTest(cl);
  
  //display hash (acessing all objects)
  h.displayHash(); 
}
