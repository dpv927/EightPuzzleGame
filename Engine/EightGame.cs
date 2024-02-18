using EightPuzzleGame.Utils;

namespace EightPuzzleGame.Engine {

    public class Game {

        private static Node? _initial;
        private static Node? _final;
        private static Node? _obtained;

        /// 
        /// <summary>
        /// Modifies the initial board configuration.
        /// </summary>
        /// <param name="conf">String representing the configuration</param>
        /// 
        public static void SetInitial(string conf) {
            _initial = new Node(conf);
        }

        /// 
        /// <summary>
        /// Modifies the final board configuration.
        /// </summary>
        /// <param name="conf">String representing the configuration</param>
        /// 
        public static void SetFinal(string conf) {
            _final = new Node(conf);
        }

        /// 
        /// <summary>
        /// Solves and shows the actual game.
        /// </summary>
        /// 
        public static void Solve() {
           
            if( _initial is null || _final is null)
                throw new NodeIsNullException();

            // Try to solve the actual game with the 
            // A* algorithm.

            var queue = new PriorityQueue<Node, int>();
            Stack<Node> succesors;
            Node current, suc;

            queue.Enqueue(_initial, 0);

            while (queue.Count > 0) {
                current = queue.Dequeue();

                if (current == _final) {
                    // Current is the best solution
                    _obtained = current;
                    break;
                }

                // Generate all the succesors of the
                // actual node.
                succesors = current.GetSuccessors();

                while (succesors.Count > 0) {
                    suc = succesors.Pop();
                    queue.Enqueue(suc, suc._evaluation);
                }
            }

            // Show the solution path if its possible
            if (_obtained is null) {
                Console.WriteLine("There is no solution available.");
                return;
            }

            var ancestors = _obtained.GetAncestors();
            Node node;

            while (ancestors.Count > 0) {
                node = ancestors.Pop();

                Console.WriteLine(
                    "Depth: " + node._depth +
                    "\n" + node
                );
            }
        }
    }
}