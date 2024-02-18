using EightPuzzleGame.Utils;

namespace EightPuzzleGame.Engine
{

    public class GameConsole
    {
        private GameConsole() { }

        private static readonly string _prompt = "\x1b[1;32m>\x1b[0m ";

        public static void Start() {
            Console.WriteLine("\x1b[1mWelcome to EightPuzzleGame\x1b[0m.\n" +
                "This is an interactive program that allows you to analize and " +
                "solve boards from\nthe famous Eight Puzzle Game. " +
                "If you need help, please type the command 'help'.");
        }

        public static string? Prompt() {
            Console.Write("\n" + _prompt);
            return Console.ReadLine();
        }

        public static void HandleHelp(string cmd) {
            Console.WriteLine("\nAvailable commands: \n\n" +
                "initpos  <board config>    Set a new initial board position.\n" +
                "finalpos <board config>    Set a new final board position.\n" +
                "solve                      Solve the game with the actual initial and final position.\n" +
                "help                       Show this message.");
        }

        public static void HandleExit(string cmd) { 
            Console.WriteLine("Session finished...");
            Environment.Exit(0);
        }

        public static void HandleSetInitPos(string cmd) {
            try { 
                Game.SetInitial(cmd);
                Console.WriteLine("Successfully set the initial position.");
            } catch { Console.WriteLine("Invalid board configuration."); }
        }

        public static void HandleSetFinalPos(string cmd) {
            try { 
                Game.SetFinal(cmd); 
                Node.GenTargetPosition(cmd);
                Console.WriteLine("Successfully set the final position.");
            } catch { Console.WriteLine("Invalid board configuration."); }
        }

        public static void HandleSolve(string cmd) {
            try { Game.Solve(); }
            catch { 
                Console.WriteLine("Cannot solve game with the actual " +
                "parameters. Maybe you need so set one or more\nparameters. " +
                "If you need help, type the command 'help'."); 
            }
        }
    }
}