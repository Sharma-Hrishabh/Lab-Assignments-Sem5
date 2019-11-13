goal([1,2,3,4,5,6,7,8,0]).

%move empty tile left in top row

move([B1,0,B3,  B4,B5,B6,  B7,B8,B9],
     [0,B1,B3,  B4,B5,B6,  B7,B8,B9]).
move([B1,B3,0,  B4,B5,B6,  B7,B8,B9],
     [B1,0,B3,  B4,B5,B6,  B7,B8,B9]).

%move empty tile right in top row

move([B1,0,B3,  B4,B5,B6,  B7,B8,B9],
     [B1,B3,0,  B4,B5,B6,  B7,B8,B9]).
move([0,B1,B3,  B4,B5,B6,  B7,B8,B9],
     [B1,0,B3,  B4,B5,B6,  B7,B8,B9]).

%move empty tile left in middle row

move([B1,B2,B3,  B4,0,B6,  B7,B8,B9],
     [B1,B2,B3,  0,B4,B6,  B7,B8,B9]).
move([B1,B2,B3,  B4,B5,0,  B7,B8,B9],
     [B1,B2,B3,  B4,0,B5,  B7,B8,B9]).

%move empty tile right in middle row

move([B1,B2,B3,  B4,0,B6,  B7,B8,B9],
     [B1,B2,B3,  B4,B6,0,  B7,B8,B9]).
move([B1,B2,B3,  0,B4,B5,  B7,B8,B9],
     [B1,B2,B3,  B4,0,B5,  B7,B8,B9]).

%move empty tile left in bottom row

move([B1,B2,B3,  B4,B5,B6,  B7,0,B9],
     [B1,B2,B3,  B4,B5,B6,  0,B7,B9]).
move([B1,B2,B3,  B4,B5,B6,  B7,B8,0],
     [B1,B2,B3,  B4,B5,B6,  B7,0,B8]).

%move empty tile right in bottom row

move([B1,B2,B3,  B4,B5,B6,  B7,0,B9],
     [B1,B2,B3,  B4,B5,B6,  B7,B9,0]).
move([B1,B2,B3,  B4,B5,B6,  0,B7,B8],
     [B1,B2,B3,  B4,B5,B6,  B7,0,B8]).

%move empty tile UP in middle row

move([B1,B2,B3,  0,B5,B6,  B7,B8,B9],
     [0,B2,B3,  B1,B5,B6,  B7,B8,B9]).
move([B1,B2,B3,  B4,0,B6,  B7,B8,B9],
     [B1,0,B3,  B4,B2,B6,  B7,B8,B9]).
move([B1,B2,B3,  B4,B5,0,  B7,B8,B9],
     [B1,B2,0,  B4,B5,B3,  B7,B8,B9]).


%move empty tile UP in bottom row

move([B1,B2,B3,  B4,B5,B6,  0,B8,B9],
     [B1,B2,B3,  0,B5,B6,  B4,B8,B9]).
move([B1,B2,B3,  B4,B5,B6,  B7,0,B9],
     [B1,B2,B3,  B4,0,B6,  B7,B5,B9]).
move([B1,B2,B3,  B4,B5,B6,  B7,B8,0],
     [B1,B2,B3,  B4,B5,0,  B7,B8,B6]).

%move empty tile DOWN in TOP row

move([0,B2,B3,  B4,B5,B6,  B7,B8,B9],
     [B4,B2,B3,  0,B5,B6,  B7,B8,B9]).
move([B1,0,B3,  B4,B5,B6,  B7,B8,B9],
     [B1,B5,B3,  B4,0,B6,  B7,B8,B9]).
move([B1,B2,0,  B4,B5,B6,  B7,B8,B9],
     [B1,B2,B6,  B4,B5,0,  B7,B8,B9]).

%move empty tile DOWN in MIDDLE row

move([B1,B2,B3,  0,B5,B6,  B7,B8,B9],
     [B1,B2,B3,  B7,B5,B6,  0,B8,B9]).
move([B1,B2,B3,  B4,0,B6,  B7,B8,B9],
     [B1,B2,B3,  B4,B8,B6,  B7,0,B9]).
move([B1,B2,B3,  B4,B5,0,  B7,B8,B9],
     [B1,B2,B3,  B4,B5,B9,  B7,B8,0]).


search_set(S,P):- search(S,[],P).
search(S,Path,Path):- goal(S).
search(S,Visited,P):- move(S,S2),
                         \+member(S2,Visited),
                         search(S2,[S2|Visited],P),
                         write(S2),nl.


