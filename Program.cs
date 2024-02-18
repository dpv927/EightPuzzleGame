using EightPuzzleGame.Engine;

// 
// Create a dictionary with all the available commands
// that the user can use.
//
var commands = new Dictionary<string, Action<string>> {
    { "initpos", GameConsole.HandleSetInitPos },
    { "finalpos", GameConsole.HandleSetFinalPos },
    { "solve", GameConsole.HandleSolve },
    { "help", GameConsole.HandleHelp },
    { "exit", GameConsole.HandleExit }
};

// Create a new Analysis session
bool keepAnalysis = true;
string? userInput;
string[] parts;
Action<string>? func;

GameConsole.Start();
while (keepAnalysis) {

    userInput = GameConsole.Prompt();
    if (userInput is null) {
        Console.WriteLine("Input error!");
        break;
    }

    parts = userInput.Split(" ");
    if (parts.Length > 2) {
        Console.WriteLine("Invalid command: ~"
        + userInput + "~");
        continue;
    }

    try { func = commands[parts[0]];
    } catch {
        Console.WriteLine("Invalid command: ~"
        + userInput + "~");
        continue;
    }
    func(parts[parts.Length-1]);
}