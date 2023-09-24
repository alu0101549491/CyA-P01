// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con Cadenas
// Autor: Fabián González Lence
// Correo: alu0101549491@ull.edu.es
// Fecha: 21/09/2023
// Archivo p02_strings.cc: programa cliente.
// Contiene la función main del proyecto que usa la clase Strings
// para procesar un fichero que contiene cadenas e imprimir los 
// resultados en un fichero de salida
// Referencias:
// https://github.com/alu0101549491/CyA/tree/master/P02
//
// Historial de revisiones
// 21/09/2023 - Creación (primera versión) del código

#include "strings.h"
#include "strings.cc"
#include "symbols.h"
#include "symbols.cc"
#include "alphabet.h"
#include "alphabet.cc"

/** @brief Imprime en pantalla una breve guía y explicación sobre el funcionamiento del programa */
void Help() {
  std::ifstream input_file{"help.txt"};
  while (input_file) {
    std::string text_line;
    std::getline(input_file, text_line);
    std::cout << text_line << std::endl;
  }
}

/** @brief Revisa que los parámetros introducidos al programa funcionen correctamente y no generen errores
  * @param[in] argc. Número de parámetros pasados al programa a través de la terminal
  * @param[in] argv. Vector de char* que contiene los parámetros pasados al programa
  * @return Valor booleano que determina si el parámetro que se le pasó al programa es correcto y se puede proseguir
  */
bool CheckParameters(const int& argc, char* argv[]) {
  if (argc < 4 || argc > 4) {
    std::string input_file = argv[1];
    if (input_file == "--help") {
      Help();
      return false;
    }
    else {
      std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
      std::cout << "Pruebe './p02_strings --help' para más información" << std::endl;
      return false;
    }
  }
  else {
    std::ifstream input{std::string{argv[1]}};
    std::ofstream output{std::string{argv[2]}};
    std::string opcode = argv[3];
    if (input.fail() || output.fail()) {
      std::cout << "No se ha encontrado el fichero introducido" << std::endl;
      return false;
    }
    else {
      return true;
    }
  }
}

int main(int argc, char* argv[]) {
  if (CheckParameters(argc, argv)) {
    std::string input_file = argv[1];
    std::string output_file = argv[2];
    std::ofstream output {output_file};
    Strings strings_register(input_file, output_file);
    std::cin >> strings_register;
    std::cout << strings_register;
    switch (std::stoi(argv[3])) {
      case 1: {
        Alphabet alphabets;
        for (auto it : strings_register.GetStringsSet()) {
          Symbols symbols_of_string{it};
          alphabets.Insert(symbols_of_string);
        }
        for (auto j : alphabets.GetAlphabet()) {
          output << j << std::endl;
        }
        break;
      }
      case 2: {
        std::unordered_set<int> length = strings_register.Length();
        for (auto i : length) {
          output << i << std::endl;
        }
        break;
      }
      case 3: {
        std::unordered_set<std::string> inverse_strings = strings_register.Inverse();
        for (auto i : inverse_strings) {
          output << i << std::endl;
        }
        break;
      }
      case 4: {
        std::set<Strings> prefixes = strings_register.Prefixes();
        for (auto i : prefixes) {
          std::cout << i << std::endl;
        }
        break;
      }
      case 5: {
        
        break;
      }
      default:
        std::cout << "La opción elegida no es correcta" << std::endl;
        return 1;
    }
    return 0;
  }
  else {
    return 1;
  }
}