// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Fabián González Lence
// Correo: alu0101549491@ull.edu.es
// Fecha: 07/11/2023
// Archivo state.h: programa cliente.
// Contiene la clase State y la declaración de los métodos de la clase
// Referencias:
// https://github.com/alu0101549491/CyA/tree/master/P09
//
// Historial de revisiones
// 07/11/2023 - Creación (primera versión) del código
// 08/11/2023 - Finalización (última versión) del código

#pragma once

#include "alphabet.h"

class State {
 public:
  State(const std::string& state) { state_id_ = state; }
  State() {}
  std::string GetID() const { return state_id_; }
  void SetIfFinal(bool final) { final_ = final; }
  bool GetIfFinal() const { return final_; }
  void InsertTuple(std::pair<char, std::tuple<std::string, char, char>> tuple) { tuples_.insert(tuple); number_of_tuples_ = tuples_.size(); }
  std::tuple<std::string, char, char> GetTuple(const char& key) const;
  std::map<char, std::tuple<std::string, char, char>> GetTupleMap() const { return tuples_; }
  friend bool operator<(const State& state1, const State& state2);
  friend bool operator==(const State& state1, const State& state2);
  friend std::ostream& operator<<(std::ostream& out, const State& state);
 private:
  std::string state_id_;
  bool final_;
  std::map<char, std::tuple<std::string, char, char>> tuples_;
  int number_of_tuples_;
};

/** @brief Busca en el mapa de tuplas el identificador deseado
 *  @param[in] key. Identificador a buscar
 *  @return Retorna la tupla cuyo identificador es "key", si no es encontrado retorna
 *          una tupla con todos sus valores a 0 (se usará como comprobación de parada)
 */
std::tuple<std::string, char, char> State::GetTuple(const char& key) const {
  if (tuples_.find(key) != tuples_.end()) {
    return tuples_.at(key);
  }
  else {
    std::tuple<std::string, char, char> no_tuple_exit{"0", '0', '0'};
    return no_tuple_exit;
  }
}

/** @brief Sobrecarga del operador de comparación "<"
 *  @param[in] state1. Estado 1
 *  @param[in] state2. Estado 2
 *  @return Devuelve la comparación de los estados en base a su ID
 */
bool operator<(const State& state1, const State& state2) {
  return state1.state_id_ < state2.state_id_;
}

/** @brief Sobrecarga del operador de comparación "=="
 *  @param[in] s1. Estado 1
 *  @param[in] s2. Estado 2
 *  @return Devuelve la comparación de igualación de los estados en base a todos sus atributos
 */
bool operator==(const State& s1, const State& s2) {
  if (s1.state_id_ != s2.state_id_ || s1.final_ != s2.final_ || s1.tuples_ != s2.tuples_) {
    return false;
  }
  return true;
}

/** @brief Sobrecarga del operador de extracción para la clase State
 *  @param[in] out. Flujo de salida
 *  @param[in] state. Objeto de la clase State que se va a imprimir
 *  @return Devuelve el flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const State& state) {
  out << state.GetID();
  return out;
}