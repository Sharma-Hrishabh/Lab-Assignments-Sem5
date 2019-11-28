permutation([X|Y],Z):- permutation(Y,W), remove(X,Z,W).
permutation([],[]).

remove(X,[X|R],R).
remove(X,[H|T],[H|T1]):-remove(X,T,T1).


solve(P) :-
     permutation([1,2,3,4],P),
     combine([1,2,3,4],P,S,D),
     all_diff(S),
     all_diff(D).


combine([X1|X],[Y1|Y],[S1|S],[D1|D]) :-
     S1 is X1 +Y1,
     D1 is X1 - Y1,
     combine(X,Y,S,D).
combine([],[],[],[]).

all_diff([X|Y]) :-  \+member(X,Y), all_diff(Y).
all_diff([X]).