#include <cstdint>
/** The Coordinate class represents a Coordinate inside a board of the
 * 8-puzzle game. The domain of the coordinates (i,j) inside the board are
 * i = {0,1,2} and j = {0,1,2}. Because of that, we use an unsigned int
 * of 8 bits to represent both coordinates.
 * @author Filipondios
 * @version 22.02.2023 */
class Coordinate{

  public:
    uint8_t i; // Horizontal coordinate (Row count)
    uint8_t j; // Vertical coordinate (Column count)

   /* @brief Constructor of the class
    * @param i Column of the board
    * @param j Row of the board */
    Coordinate(uint8_t i = 0, uint8_t j = 0)
    : i(i), j(j) {}
};
