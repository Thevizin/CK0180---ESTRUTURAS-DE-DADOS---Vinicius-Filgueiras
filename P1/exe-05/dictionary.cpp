#include <iostream>
using namespace std;

struct Pair{
  int key;
  char valor;
};

struct Dictionary{
  Pair vector[100];
  int size;
};

void boot(Dictionary &d){
  d.size = 0;
}

int search(Dictionary dictionary, int key){
  for(int i = 0; i < dictionary.size; i++){
    if(dictionary.vector[i].key == key){
      return i;
    }
  }
  return -1;
}

int consulta(Dictionary dictionary, int key){
  if(search(dictionary,key) != -1){
    cout << "Valor Founded! ----> " << key << ": " << dictionary.vector[search(dictionary,key)].valor << endl;
    return dictionary.vector[search(dictionary, key)].valor;
  }
  cout << "Valor not Founded!" << endl;
  return -1;
}

void insert(Dictionary &dictionary, int key, char valor){
  if(search(dictionary, key) == -1){
    dictionary.vector[dictionary.size].key = key;
    dictionary.vector[dictionary.size].valor = valor;
    dictionary.size ++;
    cout << key << ": " << valor << " Inserted" << endl;
  }
  else{
    cout << "The key already exists" << endl;
  }
}

void remove(Dictionary &dictionary, int key){
  if(search(dictionary, key) != -1){
    cout << key << ": " << dictionary.vector[search(dictionary, key)].valor << " Removed" << endl;
    for(int i = search(dictionary, key); i < dictionary.size; i++){
      dictionary.vector[i] = dictionary.vector[i+1];
    }
    dictionary.size --;
  }
  else{
    cout << "The key does not" << endl;
  }
}

int main() {
  Dictionary dictionary;
  boot(dictionary);
  insert(dictionary, 1, 'a');
  insert(dictionary, 2, 'b');
  insert(dictionary, 3, 'c');
  insert(dictionary, 4, 'd');
  insert(dictionary, 5, 'e');
  insert(dictionary, 6, 'f');
  insert(dictionary, 7, 'g');
  consulta(dictionary, 3);
  consulta(dictionary, 4);
  remove(dictionary, 4);
  consulta(dictionary, 4);
  insert(dictionary, 4, 'f');
  consulta(dictionary, 4);

}