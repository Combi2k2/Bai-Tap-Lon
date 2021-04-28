TETRIS by Combi:

1. Feature:

-	GAME Board of size 10x20.
-	7 types of tetrominoes with fixed color for each tetromino.
-	Board predicts next 2 coming tetrominoes.
-	Board informs player about which tetromino is being stored for later use.
-	Simulation of final destination facilitate player.

2. Tutorial:

-	Left arrow:	Move current tetromino to the left (if visible)
-	Right arrow:	Move current tetromino to the right (if visible)
-	Down arrow:	Move current tetromino down (if visible)
-	Up arrow:	Rotate current tetromino in clockwise direction.
-	SPACE bar:	Drop current tetromino to predicted destination.
-	Button 'c':	Hold current tetromino (this tetromino is put into the storage)
		+	if the storage is empty:	the first predicted tetromino is put into GAME board.
		+	else:				the tetomino in the storage   is put into GAME board.

-	Button 'p':	Pause game.

3. Scoring:

-	Using "Down arrow" or "SPACE BAR" increases score by the number of units that current tetromino move down.
-	When an entire row is full of colored cells, all cells in this row disappear and score increases by 10.
-	When you have a COMBO A rows being full of color cells, score increases by 10 * (A - 1) extra score.