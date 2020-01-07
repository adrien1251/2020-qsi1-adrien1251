type player =
  | PlayerOne
  | PlayerTwo;

type point =
  | Love
  | Fifteen
  | Thirty;

type pointsData = {
  playerOne: point,
  playerTwo: point
};

type fortyData = {
  player: player, /* The player who have forty points */
  otherPlayerPoint: point
};

type score =
| Points(pointsData)
| Forty(fortyData)
| Deuce
| Advantage(player)
| Game(player);

let startScore : score = Points({playerOne: Love, playerTwo: Love});
let anotherScore : score = Forty({player: PlayerTwo, otherPlayerPoint:Thirty });

