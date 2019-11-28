reverse([H|T],A,R):- reverse(T,[H|A],R).
reverse([],A,A).



vowel(X):-find(X,[a,e,i,o,u]).
nr_vowel([],0).
nr_vowel([X|T],N):-vowel(X),nr_vowel(T,N1),N is N1+1,!.
nr_vowel([X|T],N):-nr_vowel(T,N).



find_dup([],[]).
find_dup([H|T],[H|X]):- not(member(H,T)),find_dup(T,X).
find_dup([H|T],X) :- member(H,T),find_dup(T,X).





fact(1,0).
fact(X,N):-N>0,Y is N-1,fact(X1,Y),X is X1*N. 

fib(1,1).
fib(2,1).
fib(N,X):- N>0, Y is N-1,Z is N-2,fib(Y,X1),fib(Z,X2),X is X1+X2.

gcd(A,0,A).
gcd(A,B,X):- B>0, Y is mod(A,B),gcd(B,Y,X1), X is X1.
lcm(A,B,X):- Y is A*B,Z is gcd(A,B,X),X is Y/Z.


find(X,[X|T]).
find(X,[H|T]):-find(X,T).

findlength([],0).
findlength([H|T],N):-findlength(T,X),N is X+1.


%findfl([],F,L).
%findfl([H],F,H).
%findfl([H|T],H,L):-findfl(T,H,L).
%

findnth([H|T],H,1).
findnth([H|T],X,N) :- N1 is N-1,N1 > 0,findnth(T,X,N1).


incrementeach([],[]) .
incrementeach([X|Xs],[Y|Ys]) :-(number(X) -> Y is X+1 ; Y = X ),incrementeach(Xs,Ys).


intersect([ ], X, [ ]).
intersect([X|R], Y, [X|Z]) :- member(X, Y), !, intersect(R, Y, Z).
intersect([X|R], Y, Z) :- intersect(R, Y, Z).

union([ ], X, X).
union([X|R], Y, Z):- member(X, Y), !, union(R, Y, Z).
union([X|R], Y, [X|Z]):- union(R, Y, Z).


concat([],X,X).
concat([H|T],X,[H|Y]):-concat(T,X,Y).



move(1,X,Y):-
	write('move top disk from'),
	write(X),
	write('to'),
	write(Y),nl.


move(N,X,Y):-
	N>0,
	M is N-1,
	move(1,X,Y,_),
	move(M,X,Y)