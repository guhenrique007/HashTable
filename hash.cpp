#include<bits/stdc++.h> 
#include <stdio.h>
using namespace std; 


class Customer {
  public:
    int code;
    string name;
    void ini(int code, string name);
    int getCode() { return code; } 
    string getName() {return name; }
};

void Customer::ini(int code, string name) {
  this->code = code;
  this->name = name;
}
  
class Hash { 
  int BUCKET;    // No. of buckets 

  // Pointer to an array containing buckets 
  //list<int> *table; 

  list<Customer> *clientes;

  public: 
    Hash(int V);  // Constructor 

    // inserts a key into hash table 
    // void insertItem(int x); 

    void insertItem(Customer *cl);

    // deletes a key from hash table 
    void deleteItem(int key); 

    // search a key from hash table
    int search(int key);

    // hash function to map values to key 
    int hashFunction(int x) { 
      return (x % BUCKET); 
    } 

  void displayHash(); 
  void saveInFile(); 
}; 

void Hash::insertItem(Customer *cl) { 
  int index = hashFunction(cl->code); 
  //cout << "index " << index << endl; 

  clientes[index].push_back(*cl);

  int sizetable = sizeof(clientes)/sizeof(clientes[0]);
} 
  
Hash::Hash(int b) { 
  this->BUCKET = b; 
  clientes = new list<Customer>[BUCKET]; 
} 
  
void Hash::deleteItem(int key) { 
  // vai direto pro indice no array que a chave tá (ou deveria estar)
  int index = hashFunction(key); 
  
  //tentando achar a chave iterando a lista
  list <Customer> :: iterator i; 
  for (i = clientes[index].begin(); i != clientes[index].end(); i++) { 
    cout << i->code << endl;
    if (i->code == key) 
     break; 
  } 
  
  // achou? hora de remover
  if (i != clientes[index].end()) 
   clientes[index].erase(i); 
} 
  
// function to display hash table 
void Hash::displayHash() { 
  for (int i = 0; i < BUCKET; i++) { 
    cout << i; 
    int sizetable = sizeof(clientes)/sizeof(clientes[0]);

    for (auto x : clientes[i]) 
      cout << " --> " << x.getName() << "(" << x.getCode() << ")";
    cout << endl; 
  } 
} 

void Hash::saveInFile() { 
  ofstream file;
  file.open ("data.txt", std::ofstream::out | std::ofstream::trunc);

  for (int i = 0; i < BUCKET; i++) { 
    int sizetable = sizeof(clientes)/sizeof(clientes[0]);

    for (auto x : clientes[i]) 
      file << x.getName() << " " << x.getCode() << "\n";
  } 

  file.close();
}

// function to search value in hash table
int Hash::search(int key) {
  for (int i = 0; i < BUCKET; i++) { 
    for (auto x : clientes[i]) {
      if(x.getCode() == key) {
        cout << "Chave " << key;
        cout << " Encontrado no Bucket: " << i << endl;
        return 0;
        //break;
      }
    }
  }

  return 1;
}
  
// Driver program  
int main() { 
  // array that contains keys to be mapped 
  int option, valor, codigo;
  char nome[100];
  int stopMenu = false;
  int a[] = {15, 11, 27, 8, 12}; 
  int n = sizeof(a)/sizeof(a[0]); 
  int result;

  // insert the keys into the hash table 
  Hash h(7);

  Customer *cliente = new Customer();
  int hasCode;
  hasCode = h.search(7);
  if(hasCode != 0) {
    cliente->ini(17, "henrique");
    // cout << "Tentando inserir" << endl;
    h.insertItem(cliente);
  }

  // cliente->code = 15;
  // cliente->name = "henrique";
  // h.insertItem(cliente);

  // cliente->code = 8;
  // cliente->name = "silva";
  // h.insertItem(cliente);

  int i = 0;
  int j = 0;
  string line;
  ifstream infile("data.txt");

  while(getline(infile, line)){
    stringstream ssLine(line);
    string substr;
    i++;
    j=0;
    cout << "linha -------------- " << i << endl;
    
    while(ssLine) {
      j++;
      ssLine >> substr;

      if( j % 3 != 0) {
        cout << "(Word " << j << ")" << endl;
        cout << substr << j%2 <<  endl;
        if(j % 2 != 0) {
          cliente->name = substr;
        } else {
          cout << "cast " << substr << " " << substr.c_str() << "  " << atoi(substr.c_str()) << endl;
          cliente->code = atoi(substr.c_str());
          cout << "vai inserir o codigo " << cliente->code <<endl;

          hasCode = h.search(cliente->code);
          if(hasCode != 0) {
            h.insertItem(cliente);
          }
        }
      }
      
    }
  }
  infile.close();
  
  h.displayHash(); 

  while(!stopMenu) {
    cout << "################################"<<endl;
    cout << "Pressione 1 para Inserir" << endl;
    cout << "Pressione 2 para Ver a hash" << endl;
    cout << "Pressione 3 para Buscar" << endl;
    cout << "Pressione 4 para Apagar" << endl;
    cout << "Pressione 0 para Salvar e sair" << endl;
    cout << "################################"<<endl;

    cin >> option;

    cout << "Opcao escolhida: " << option << endl;

    switch(option) {
      case 1: 
        cout << "Digite o codigo que deseja inserir" << endl;
        cin >> codigo;

        cout << "Digite o nome do cliente" << endl;
        cin >> nome;

        cliente->ini(codigo, nome);
        cout << "-------------" << endl;
        cout << "Codigo:" << cliente->code << endl;
        cout << cliente->name << endl;

        int hasCode;
        hasCode = h.search(codigo);

        if(hasCode != 0) {
          h.insertItem(cliente);
          cout << "Inserido com sucesso" << endl;
          cout << "-------------" << endl;
          h.displayHash(); 
        } else {
          cout << "Codigo ja utilizado" << endl;
        }

        break;
      case 2:
        h.displayHash(); 
        break;
      case 3:
        cout << "Insira o valor que quer buscar: " << endl;
        cin >> valor;
        h.search(valor);
        break;
      case 4:
        cout << "Insira o valor que quer deletar: " << endl;
        cin >> valor;
        h.deleteItem(valor);
        break;
      case 0:
        h.saveInFile();
        cout << "case: " << option;
        stopMenu = true;
        break;
      default:
        cout << "Comando invalido" << endl;
        break;
    }
  }

  return 0; 
} 