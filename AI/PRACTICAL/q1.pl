%length of list
findlength([],0).
findlength([H|T], N) :- findlength(T,X), N is X+1.

evenlength([H|T]) :- findlength([H|T],X), 0 is mod(X,2).

sumoflist([],0).
sumoflist([H|T],X):- sumoflist(T,X1), X is H+X1.


disp([H]):-write(H).
disp([H|T]):-write(H),disp(T).

checkeven([H|T],X):-evenlength([H|T]),sumoflist([H|T],X1),X is X1.
checkeven([H|T],X):-not(evenlength([H|T])),disp([H|T]),X is 0.



