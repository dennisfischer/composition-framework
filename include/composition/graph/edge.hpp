#ifndef COMPOSITION_FRAMEWORK_GRAPH_EDGE_HPP
#define COMPOSITION_FRAMEWORK_GRAPH_EDGE_HPP

#include <utility>
#include <string>
#include <llvm/Support/raw_ostream.h>

namespace composition::graph {
//edge_idx_t type. TODO C++ does not enforce type safety. Potentially there are ways how type safety can be improved.
typedef unsigned long edge_idx_t;

/**
 * Type of the edge in a graph
 */
enum class edge_type {
  UNKNOWN,
  CFG,
  DEPENDENCY,
};

std::ostream &operator<<(std::ostream &os, const edge_type &obj);

/**
 * Defines the structure of an edge in the graph.
 */
struct edge_t {
  /**
   * Unique index of the edge
   */
  edge_idx_t index;
  /**
   * Name of the edge
   */
  std::string name;
  /**
   * Type of the edge
   */
  edge_type type;
  /**
   * Was the edge removed from the graph?
   */
  bool removed{};

  explicit edge_t(
      edge_idx_t index = 0,
      std::string name = "",
      edge_type type = edge_type::UNKNOWN
  ) noexcept;

  std::ostream &operator<<(std::ostream &os) noexcept;

  bool operator==(const edge_t &rhs) noexcept;

  bool operator!=(const edge_t &rhs) noexcept;
};

}
#endif //COMPOSITION_FRAMEWORK_GRAPH_EDGE_HPP
