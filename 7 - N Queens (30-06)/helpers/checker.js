const hasConflict = (columns) => {
  let length = columns.length;
  let lastPlace = columns[length - 1];
  let previousPlace = length - 2;

  while (previousPlace >= 0) {
    if (columns[previousPlace] === lastPlace) return true;
    if (lastPlace - (length - 1) === columns[previousPlace] - previousPlace) return true;
    if (lastPlace + (length - 1) === columns[previousPlace] + previousPlace) return true;

    previousPlace--;
  }

  return false;
}

module.exports = hasConflict;