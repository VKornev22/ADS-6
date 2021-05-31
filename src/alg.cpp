// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {

  BST<std::string>Tree;
  std::string result = "";
  char sym;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    sym = file.get();
    if ((sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z')) {
      if (sym >= 'A' && sym <= 'Z') {
        sym += 32;
      }
      result += sym;
    } else if (result !="") {
      Tree.add(result);
      result = "";
    }
  }
  file.close();
  return Tree;
}
