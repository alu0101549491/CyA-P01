// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA
// Autor: Fabián González Lence
// Correo: alu0101549491@ull.edu.es
// Fecha: 18/10/2023
// Archivo alphabet.h: programa cliente.
// Contiene la clase Alphabet y la declaración de las funciones del programa
// Referencias:
// https://github.com/alu0101549491/CyA/tree/master/P06
//
// Historial de revisiones
// 18/10/2023 - Creación (primera versión) del código
// 21/10/2023 - Finalización (última versión) del código

#pragma once

class Alphabet {
 public:
  std::set<char> GetSet() const { return alphabet_; }
  void Insert(char symbol) { alphabet_.insert(symbol); }
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  friend bool operator!=(const Alphabet& alphabet1, const Alphabet& alphabet2);
 private:
  std::set<char> alphabet_;
};

/** @brief Sobrecarga del operador de extracción para la clase Alphabet
 *  @param[in] out. Flujo de salida
 *  @param[in] alphabet. Objeto de la clase Alphabet que se va a imprimir
 *  @return Devuelve el flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  for (auto it = alphabet.alphabet_.begin(); it != alphabet.alphabet_.end(); ++it) {
    if (*it != '&') {
      out << *it << " ";
    }
  }
  return out;
}

/** @brief Sobrecarga del operador de comparación !=
 *  @param[in] alphabet1. Objeto de la clase Alphabet
 *  @param[in] alphabet2. Objeto de la clase Alphabet
 *  @return Compara los sets de cada alfabeto y retorna si son desiguales o no
 */
bool operator!=(const Alphabet& alphabet1, const Alphabet& alphabet2) {
  return alphabet1.GetSet() != alphabet2.GetSet();
}