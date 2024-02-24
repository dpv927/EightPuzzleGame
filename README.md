
<h1 align="center">
  EightPuzzleGame 
  <br>
</h1>

<h4 align="center">A interactive command line solver for the eight puzzle game.</h4>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#download">Download</a> •
  <a href="#credits">Credits</a> •
  <a href="#related">Related</a> •
  <a href="#license">License</a>
</p>

## About

El juego del 8 es un juego donde se tiene un tablero con 8 piezas y un hueco. El objetivo principal es usar ese hueco
adicional para mover los numeros del tablero y conseguir llegar a un orden de los numeros en concreto.

Para ello, se ha creado esta aplicacion la cual permite al usuario seleccionar un estado inicial y objetivo, a la vez que
obtener el camino de la solucion, no como otros programas de la web que solo permiten especificar el estado inicial.

## How To Use

Esta aplicacion se corre en consola, y responde a comandos que el usuario va introduciendo durante su ejecucion. Para ello,
se podran usar los comandos que se indican a continuacion:

| Command | Description | 
| --- | --- |
| `initpos <position>` | Sets a new initial configuration |
| `finalpos <position>` | Sets a new final configuration |
| `solve` | Solves the puzzle given by 'initpos' and 'finalpos' |
| `help` | Shows a help message | 
| `exit` | Finalizes the program |

## Board format

El programa tiene una manera de entender las configuraciones de los tableros de una forma especifica. Esta es una cadena
de caracteres numericos del 0 al 8 sin repetirse, los cuales indican el orden de los numeros dentro del tablero. 

A continuacion se muestran algunos ejemplos:

```
                            +---+---+---+                                  +---+---+---+
                            | 6 | 5 | 7 |                                  | 1 | 2 | 3 |
Este seria el tablero para  +---+---+---+      Este seria el tablero para  +---+---+---+
   la cadena 657431208:     | 4 | 3 | 1 |         la cadena 123456780      | 4 | 5 | 6 |
                            +---+---+---+                                  +---+---+---+
                            | 2 |   | 8 |                                  | 7 | 8 |   |
                            +---+---+---+                                  +---+---+---+
```
> **Note**
> Debes tener en cuenta que el hueco del tablero se anotara como '0'.


## Command Examples

```bash
> initpos 123456780   # sets the board '123456780' as the new initial position 
> finalpos 736458201  # sets the board '736458201' as the new final position
> solve
> help
> exit
```

