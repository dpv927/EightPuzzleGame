<div class="languages" align="center">

# Eight-puzzle-game

:uk: <a href="https://github.com/dpv927/eight-puzzle-game">English</a>
:es: <a href="#">Español</a>
</div>

## Sobre esto
A diferencia de otras aplicaciones que resuelven el juego del 8, a esta aplicación le puedes especificar un estado del tablero inicial y final. 
El arbol de búsqueda es desarrollado por el <ins>algoritmo A*</ins>, dando la solución menos costosa (hablando del número de movimientos realizados).

## Como usar
La aplicación espera dos entradas (el estado inicial y final del tablero) como un string (cadena de texto). Por ejemplo, para el string "123456780"
(Evidentemente sin las comillas ("")) representará el siguiente tablero: 
```
+---+---+---+
| 1 | 2 | 3 |
+---+---+---+   Nota: Una posición del tabloro con '0' indica que ahí 
| 4 | 5 | 6 |   no hay colocada ninguna ficha (está vacía).
+---+---+---+
| 7 | 8 | 0 |
+---+---+---+
```

Tras ejecutar la aplicación nos mostrará el estado inicial y final del tablero especificado, la secuencia exacta de movimientos que hay que realizar desde el estado
inicial hasta el final con sus respectivas representaciones del tablero y su orden (depth) y alguna información sobre el proceso de búsqueda como lo es `CREATED_NODES`
(nodos creados), `EXPANDED_NODES` (nodos desarrollados) y `SOLUTION_DEPTH` (a que profundidad se encontró la solución.

## Compilar e Instalar

El proyecto tiene una manera fácil de compilar todo el código fuente en un archivo ejecutable e instalarlo. Para compilar ejecuta:
```bash
make clean
```
Si quieres compilarlo e instalarlo directamente:
```bash
make clean install
```

## Desinstalar

Para desinstalar el programa, simplemente elimine el ejecutable en la ruta de programas:
```bash
# Linux
sudo rm /usr/bin/eightgame

# MacOS
sudo rm /usr/local/bin/eightgame
```

> **Note**
> El comando 'make install' está hecho solo para Linux y MacOS. Si usa Windows, modifique el Makefile o copie el archivo ejecutable compilado en una ruta de origen
como C:\\\Archivos de programa.
