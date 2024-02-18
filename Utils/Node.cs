using System.Text.RegularExpressions;

namespace EightPuzzleGame.Utils {

    public class Node {

        // Final positions of the game
        private static readonly int NumTiles = 9;
        public static Coordinate[]? TargetPosition;

        // Node private propierties
        private Node? _father;
        private byte[] _board;
        public int _depth;
        public int _evaluation;

        ///
        /// <summary>
        /// Usual constructor for a child node.
        /// </summary>
        /// <param name="father">Father of the node to create</param>
        /// <param name="board">New node's game board state</param>
        /// 
        public Node(Node father) {
            _father = father;
            _depth = father._depth+1;
            _board = new byte[NumTiles];
            Array.Copy(father._board, _board, NumTiles);
        }

        /// 
        /// <summary>
        /// Constructor for single nodes.
        /// </summary>
        /// <param name="config">Board configuration</param>
        /// <exception cref="InvalidGameStateException"></exception>
        /// 
        public Node(string config) {
            if (!IsValidConfiguration(config))
                throw new InvalidGameStateException(config + ": Not a valid game state.");
            _board = new byte[NumTiles];

            int index = 0;
            foreach (char c in config) {
                if (c == '-') continue;
                _board[index++] = (byte)(c - '0');
            }
        }

        /// 
        /// <summary>
        /// Checks whether the given board configuration string
        /// is a valid state of a game or not.
        /// </summary>
        /// <param name="config">Board configuration/state</param>
        /// <returns>False if the string is not valid</returns>
        /// 
        private static bool IsValidConfiguration(string config) {
            string pattern = @"^(?:0|1|2|3|4|5|6|7|8)(?:-(?!.*\1)(0|1|2|3|4|5|6|7|8)){8}$";
            return Regex.IsMatch(config, pattern);
        }

        /// 
        /// <summary>
        /// Generates the target board state. 
        /// </summary>
        /// <param name="config">String that represents a game board state</param>
        /// <exception cref="InvalidGameStateException"></exception>
        /// 
        public static void GenTargetPosition(string config) {
            if (!IsValidConfiguration(config))
                throw new InvalidGameStateException(config + ": Not a valid game state.");
             
            TargetPosition = new Coordinate[NumTiles];

            for (int i = 0, j = 0; i < config.Length; i++) {
                if (config[i] ==  '-') continue;
                TargetPosition[(byte)(config[i]-'0')] = 
                    new Coordinate(j/3, j%3);
                j++;
            }
        }

        /// 
        /// <summary>
        /// Calculates the heuristic value of the actual node,
        /// based in the Manhattan Distance method.
        /// </summary>
        ///
        public int GetHeuristic() {
            int total = 0, i, j;

            for(int k= 0; k < NumTiles; k++) {
                Coordinate target = TargetPosition![_board[k]];
                i = k/3; j = k%3;
                total += (Math.Abs(target._i-i) + Math.Abs(target._j-j));
            }
            return total;
        }

        /// <summary>
        /// Generates all the possible sucessors of a node.
        /// </summary>
        /// <returns>
        /// Priority queue with all the sucessor nodes ordered
        /// by them heuristic.
        /// </returns>
        public Stack<Node> GetSuccessors() {
            var succesors = new Stack<Node>();
            int holePos = Array.IndexOf(_board, (byte)0);
            int[] directions = { -3, 3, -1, 1 };

            foreach (var direction in directions) {
                int newPos = holePos + direction;
                
                if (newPos >= 0 && newPos<_board.Length && (holePos%3 == newPos%3 || holePos/3 == newPos/3)) {
                    Node node = new Node(this);
                    node._board[holePos] = node._board[newPos];
                    node._board[newPos] = 0;
                    node._evaluation = node.GetHeuristic()+_depth;
                    succesors.Push(node);
                }
            }
            return succesors;
        }

        /// 
        /// <summary>
        /// Generates all the ancestors of the actual 
        /// node instance.
        /// </summary>
        /// <returns>Stack with all the ancestors of a node.</returns>
        /// 
        public Stack<Node> GetAncestors() {
            var ancestors = new Stack<Node>();
            ancestors.Push(this);
            
            Node? iter = _father;
            while(iter is not null) {
                ancestors.Push(iter);
                iter = iter._father;
            }
            return ancestors;
        }

        public static bool operator ==(Node left, Node right) {
            return left._board.SequenceEqual(right._board);
        }

        public static bool operator !=(Node left, Node right) {
            return !(left._board.SequenceEqual(right._board));
        }

        public override string ToString() {
            string separator = "+---+---+---+";
            string result = separator + "\n";

            for (int i = 0; i<9; i++) {
                result += "| " + _board[i] + " ";
                if((i+1)%3 == 0)
                    result += "|\n"+separator+"\n";
            }
            return result;
        }
    }
}