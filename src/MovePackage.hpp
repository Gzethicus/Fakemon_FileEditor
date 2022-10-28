#ifndef MOVEPACKAGE__H
#define MOVEPACKAGE__H

#include <string>
#include <unordered_map>
#include <vector>

namespace client {
  class Move;
}

#include "Move.hpp"

namespace client {

  /// class MovePackage - 
  class MovePackage {
    // Attributes
  private:
    std::unordered_map<std::string, Move> attacks;
    std::vector<std::string> typeDependencies;
    std::vector<std::string> spriteDependencies;
    std::vector<std::string> effectDependencies;
    // Operations
  public:
    std::vector<std::string> getNames ();
    Move get (std::string name);
    /// exports the package as a JSON string
    /// @param 		(???) 
    std::string jsonExport ( );
    void addMove (std::string name, Move move);
    // Setters and Getters
  };
};
#endif
