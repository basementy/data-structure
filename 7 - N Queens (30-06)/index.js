const printBoard = require('./helpers/printer');
const hasConflict = require('./helpers/checker');

var iterations = 0

var placeNextQueen = (total, queens, columns) => {
  if (queens === 0) {
    return columns;
  }

  columns = columns || [];

  for (let currentColumn = 0; currentColumn < total; currentColumn++) {
    columns.push(currentColumn);
    iterations++;

    if (!hasConflict(columns) && placeNextQueen(total, queens - 1, columns)) {
      return columns;
    }

    columns.pop(currentColumn);
  }

  return null;
}

printBoard(placeNextQueen(20, 20))
console.log('\nTotal Iterations: ', iterations)