const printBoard = (columns) => {
  let columnsLength = columns.length;
  let currentRow = 0;
  let currentColumn = 0;

  while (currentRow < columnsLength) {
    while (currentColumn < columnsLength) {
      process.stdout.write(columns[currentRow] === currentColumn ? 'Q ' : '# ');
      currentColumn++;
    }

    process.stdout.write('\n');
    currentColumn = 0;
    currentRow++;
  }
}

module.exports = printBoard;