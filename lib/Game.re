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

let scoreWhenDeuce: player => score = winner => Advantage(winner);

let scoreWhenAdvantage: (player, player) => score = (advantagedPlayer, winner) => advantagedPlayer == winner ? Game(winner) : Deuce;
/* This time we infer that the function type is (player) => player */
let other = player =>
  switch player {
  | PlayerOne => PlayerTwo
  | PlayerTwo => PlayerOne
  };

let incrementPoint: point => option(point) = point =>
  switch point {
  | Love => Some(Fifteen)
  | Fifteen => Some(Thirty)
  | Thirty => None
  };

let scoreWhenForty = (current, winner) => 
if (current.player === winner) { 
  Game(winner) ;
} else {
  switch (incrementPoint(current.otherPlayerPoint)) {
  | None => Deuce
  | Some(a) => Forty({player: current.player, otherPlayerPoint: a});
  };
};
