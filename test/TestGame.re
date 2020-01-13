open Framework;
open TennisKata.Game;

describe("Test Game transitions", ({test}) => {
  test("Given PlayerOne then PlayerTwo is different", ({expect}) => {
    expect.notEqual(PlayerOne, PlayerTwo)
  })
});

describe("Test Game transitions", ({test}) => {
  test("Given deuce when PlayerOne wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerOne), Advantage(PlayerOne))
  });
  test("Given deuce when PlayerTwo wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerTwo), Advantage(PlayerTwo))
  });
  test(
    "Given advantage when advantaged player wins then score is correct",
    ({expect}) => {
    let advantagedPlayer = PlayerOne;
    let winner = advantagedPlayer;
    expect.equal(
      scoreWhenAdvantage(advantagedPlayer, winner),
      Game(advantagedPlayer),
    );
  });
  test("Given advantage when the other player wins then score is Deuce",
  ({expect}) => {
    let advantagedPlayer = PlayerOne;
    let winner = other(advantagedPlayer);
    expect.equal(
      scoreWhenAdvantage(advantagedPlayer, winner),
      Deuce,
    );
  });
  test(
    "Given player: 40 when wins then score is Game for this player",
    ({expect}) => {
    let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
    expect.equal(
      scoreWhenForty(fortyThirty, fortyThirty.player),
      Game(fortyThirty.player),
    );
  });
  test(
    "Given player: 40 | other : 30 when other wins then score is Deuce",
    ({expect}) => {
    let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
    expect.equal(
      scoreWhenForty(fortyThirty, other(fortyThirty.player)),
      Deuce
    );
  });
  test("Given player: 40 | other : 0 when other wins then score is fortyFifteen",
  ({expect}) => {
    let fortyLove = {player: PlayerOne, otherPlayerPoint: Love};
    let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
    expect.equal(
      scoreWhenForty(fortyLove, other(fortyLove.player)),
      Forty(fortyFifteen)
    );
  });

  test(
    "Given player: 15 | other : 15 when player wins then score is 30/15",
    ({expect}) => {
    let fifteenFifteen = {playerOne: Fifteen, playerTwo: Fifteen};
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    expect.equal(
      scoreWhenPoints(fifteenFifteen, PlayerOne),
      Points(thirtyFifteen)
    );
  });

   test("Given player: 0 | other : 15 when other wins then score is 0/30",
  ({expect}) => {
    let loveFifteen = {playerOne: Love, playerTwo: Fifteen};
    let loveThirty = {playerOne: Love, playerTwo: Thirty};
    expect.equal(
      scoreWhenPoints(loveFifteen, PlayerTwo),
      Points(loveThirty)
    );
  });
  
  test(
    "Given player: 30 | other : 15 when player wins then score is 40/15",
    ({expect}) => {
      let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
      let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
      expect.equal(
        scoreWhenPoints(thirtyFifteen, PlayerOne),
        Forty(fortyFifteen)
      );
  });
  
  test(
    "Player one to string is hello i'm player one",
    ({expect}) => {
      expect.equal(
        string_of_player(PlayerOne),
        "Player one"
      );
  });
  test(
    "Player two to string is hello i'm player one",
    ({expect}) => {
      expect.equal(
        string_of_player(PlayerTwo),
        "Player two"
      );
  });
  test(
    "Point Love to string is love",
    ({expect}) => {
      expect.equal(
        string_of_point(Love),
        "0"
      );
  });
  test(
    "Point Fifteen to string is Fifteen",
    ({expect}) => {
      expect.equal(
        string_of_point(Fifteen),
        "15"
      );
  });
  test(
    "Point Thirty to string is Thirty",
    ({expect}) => {
      expect.equal(
        string_of_point(Thirty),
        "30"
      );
  });
  test(
    "Score Deuce is Deuce to string",
    ({expect}) => {
      expect.equal(
        string_of_score(Deuce),
        "Deuce"
      );
  });
  test(
    "Score Love vs Fifteen return Love/Fifteen",
    ({expect}) => {
      let pData = {playerOne: Love, playerTwo: Fifteen};
      expect.equal(
        string_of_score(Points(pData)),
        "0/15"
      );
  });
  test(
    "Score Forty vs Fifteen return 40/15",
    ({expect}) => {
      let pData = {player: PlayerOne, otherPlayerPoint: Fifteen};
      expect.equal(
        string_of_score(Forty(pData)),
        "40/15"
      );
  });
  test(
    "Score Fifteen vs Forty return 30/40",
    ({expect}) => {
      let pData = {player: PlayerTwo, otherPlayerPoint: Thirty};
      expect.equal(
        string_of_score(Forty(pData)),
        "30/40"
      );
  });
  test(
    "Player one has advantage",
    ({expect}) => {
      let pData = PlayerOne;
      expect.equal(
        string_of_score(Advantage(pData)),
        "Player one advantage"
      );
  });
  test(
    "Player two has advantage",
    ({expect}) => {
      let pData = PlayerTwo;
      expect.equal(
        string_of_score(Advantage(pData)),
        "Player two advantage"
      );
  });
  test(
    "Player one won the game",
    ({expect}) => {
      let pData = PlayerOne;
      expect.equal(
        string_of_score(Game(pData)),
        "Player one won the game"
      );
  });
  test(
    "Player two won the game",
    ({expect}) => {
      let pData = PlayerTwo;
      expect.equal(
        string_of_score(Game(pData)),
        "Player two won the game"
      );
  });
});
