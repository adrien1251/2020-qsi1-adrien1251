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
  | Some(a) => Forty({player: current.player, otherPlayerPoint: a});
  | None => Deuce
  };
};

let pointTo = (player, point, current) =>
  switch player {
  | PlayerOne => {...current, playerOne: point}
  | PlayerTwo => {...current, playerTwo: point}
  };

let pointFor = (player, current) =>
  switch player {
  | PlayerOne => current.playerOne
  | PlayerTwo => current.playerTwo
  };

let scoreWhenPoints = (current, winner) =>
  switch (current |> pointFor(winner) |> incrementPoint) {
  | Some(np) => Points(pointTo(winner, np, current))
  | None =>
    Forty({
      player: winner,
      otherPlayerPoint: current |> pointFor(other(winner))
    })
  };

let scoreWhenGame = winner => Game(winner);

let newGame = Points({playerOne: Love, playerTwo: Love});

let score = (current, winner) =>
  switch current {
  | Points(p) => scoreWhenPoints(p, winner)
  | Forty(f) => scoreWhenForty(f, winner)
  | Deuce => scoreWhenDeuce(winner)
  | Advantage(a) => scoreWhenAdvantage(a, winner)
  | Game(g) => scoreWhenGame(g)
  };

let string_of_player = (player) => 
  switch player {
  | PlayerOne => "Player one"
  | PlayerTwo => "Player two"
  };
let string_of_point = (point) => 
  switch point {
  | Love => "0"
  | Fifteen => "15"
  | Thirty => "30"
  };
let string_of_score = (score) => 
  switch score {
  | Points(point) => string_of_point(point.playerOne) ++ "/" ++ string_of_point(point.playerTwo)
  | Forty(forty) => forty.player === PlayerOne ? "40/" ++ string_of_point(forty.otherPlayerPoint) : string_of_point(forty.otherPlayerPoint) ++ "/40" 
  | Deuce => "Deuce"
  | Advantage(player) => string_of_player(player) ++ " advantage"
  | Game(winner) => string_of_player(winner) ++ " won the game"
  };