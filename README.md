# 42-filler
42 "Filler" game AI.
## The "Filler" game
* The game is about 2 players placing pieces one after another on a board.
* The goal is to fill as many pieces as possible while preventing the opponent to do so.
* Pieces are [Polyomino](https://en.wikipedia.org/wiki/Polyomino).
* To be able to place a piece on the board, it is mandatory that one, and only one
cell of the shape (in your piece) covers the cell of a shape placed previously (your
territory).
## The "Virtual machine"
* On each turn, the VM will send to the AI the state of the board and the shape of the piece to place.
* The AI must reply with the coordinates to place the piece.
* If the reply is wrong, the VM terminates the AI and it loses the game.
## Usage
```console
make
./resources/filler_vm -f resources/maps/map01 -p1 ./juazouz.filler -p2 ./resources/players/superjeannot.filler
```
