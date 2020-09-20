#include<bits/stdc++.h> 
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
  list<int> *table; 

  list<Customer> *clientes;

  public: 
    Hash(int V);  // Constructor 

    // inserts a key into hash table 
    void insertItem(int x); 

    void insertTest(Customer *cl);

    // deletes a key from hash table 
    void deleteItem(int key); 

    // search a key from hash table
    void search(int key);

    // hash function to map values to key 
    int hashFunction(int x) { 
      return (x % BUCKET); 
    } 

  void displayHash(); 
}; 

void Hash::insertTest(Customer *cl) { 
  int index = hashFunction(cl->code); 
  cout << "Cliente chegando? " << cl << endl;
  cout << "index " << index << endl; // blz, calculou o indice

  clientes[index].push_back(*cl);

  int sizetable = sizeof(clientes)/sizeof(clientes[0]);
  cout << "Look -> " << clientes[index].front().name << endl;
  cout << sizetable << endl;
} 
  
Hash::Hash(int b) { 
  this->BUCKET = b; 
  //table = new list<int>[BUCKET];
  clientes = new list<Customer>[BUCKET]; 
} 
  
void Hash::insertItem(int key) { 
  int index = hashFunction(key); 
  table[index].push_back(key);  
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
    //cout << "-->" << sizetable << endl;

    for (auto x : clientes[i]) 
      cout << " --> " << x.getName() << "(" << x.getCode() << ")";
    cout << endl; 
  } 
} 

// function to search value in hash table
void Hash::search(int key) {
  for (int i = 0; i < BUCKET; i++) { 
    for (auto x : clientes[i]) {
      if(x.getCode() == key){
        cout << "Chave " << key;
        cout << " Encontrado no Bucket: " << i << endl;
        break;
      }
    }
    //cout << "Encontrado no Bucket: " << i;
  }
}
  
// Driver program  
int main() { 
  // array that contains keys to be mapped 
  int option, valor, codigo;
  char nome[100];
  int stopMenu = false;
  int a[] = {15, 11, 27, 8, 12}; 
  int n = sizeof(a)/sizeof(a[0]); 
  
  // insert the keys into the hash table 
  Hash h(7);   

  // hash table 
  // for (int i = 0; i < n; i++)  
  //   h.insertItem(a[i]);   

    Customer *cliente = new Customer();
    //cliente->code = 7;
    //cliente->name = "gustavo";
    cliente->ini(7, "gustavo");
    cout << "Tentando inserir" << endl;
    h.insertTest(cliente);

    cliente->code = 15;
    cliente->name = "henrique";
    h.insertTest(cliente);

    cliente->code = 8;
    cliente->name = "silva";
    h.insertTest(cliente);
  
  // delete 12 from hash table 
  //h.deleteItem(12); 
  
  // display the Hash table 
  h.displayHash(); 

  


  while(!stopMenu) {
    cout << "################################"<<endl;
    cout << "Pressione 1 para Inserir" << endl;
    cout << "Pressione 2 para Ver a hash" << endl;
    cout << "Pressione 3 para Buscar" << endl;
    cout << "Pressione 4 para Apagar" << endl;
    cout << "Pressione 0 para sair" << endl;
    cout << "################################"<<endl;

    cin >> option;

    cout << "Opcao escolhida: " << option << endl;

    //int opt;
    //scanf("%d",&opt);
    //printf("%d", opt);

    switch(option) {
      case 1: 
        cout << "Digite o codigo que deseja inserir" << endl;
        cin >> codigo;

        cout << "Digite o nome do cliente" << endl;
        cin >> nome;

        // Customer *cliente = new Customer();
        cliente->ini(codigo, nome);
        cout << "-------------" << endl;
        cout << "Codigo:" << cliente->code << endl;
        cout << cliente->name << endl;

        cout << "Objeto:" << cliente << endl;

        //h.insertItem(valor);
        cout << "Inserido com sucesso" << endl;
        cout << "-------------" << endl;
        //h.displayHash(); 
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