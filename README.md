
<h1 align="center">
  EightPuzzleGame 
  <br>
</h1>

<h4 align="center">A interactive command line solver for the eight puzzle game.</h4>

<p align="center">
  <a href="#about">About</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#board-format">Board Format</a> •
  <a href="#command-examples">Command Examples</a>
</p>

## About

The 8-puzzle-game is a game where you have a board with 8 pieces and a hole. The main objective is to use this additional gap to move the numbers on the board and get to a particular order of the numbers.

For this, we have created this application which allows the user to select an initial and target state, as well as to obtain the solution path, unlike other programs on the web that only allow the user to specify the initial and target state.
the path to the solution, unlike other programs on the web that only allow the user to specify the initial state.

## How To Use

This application runs in console, and responds to commands that the user enters during its execution. To do so, the following commands can be used the following commands can be used for this purpose:

| Command | Description | 
| --- | --- |
| `initpos <position>` | Sets a new initial configuration |
| `finalpos <position>` | Sets a new final configuration |
| `solve` | Solves the puzzle given by 'initpos' and 'finalpos' |
| `help` | Shows a help message | 
| `exit` | Finalizes the program |

## Board format

The program has a way of understanding the board configurations in a specific way. This is a string of
of numerical characters from 0 to 8 without repeating, which indicate the order of the numbers within the board. 

Some examples are shown below:

```
                               +---+---+---+                                   +---+---+---+
                               | 6 | 5 | 7 |                                   | 1 | 2 | 3 |
This would be the board given  +---+---+---+    This would be the board given  +---+---+---+
   by the string 657431208:    | 4 | 3 | 1 |       by the string 123456780:    | 4 | 5 | 6 |
                               +---+---+---+                                   +---+---+---+
                               | 2 |   | 8 |                                   | 7 | 8 |   |
                               +---+---+---+                                   +---+---+---+
```
> **Note**
> You should note that the hole in the board will be represented as '0'.


## Command Examples

```bash
> initpos 123456780   # sets the board '123456780' as the new initial position 
> finalpos 736458201  # sets the board '736458201' as the new final position
> solve
> help
> exit
```

