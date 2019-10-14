parent(albert, jim).
parent(albert, peter).
parent(jim, brian).
parent(john, darren).
parent(peter, lee).
parent(peter, sandra).
parent(peter, james).
parent(peter, kate).
parent(peter, kyle).
parent(brian, jenny).
parent(irene, jim).
parent(irene, peter).
parent(pat, brian).
parent(pat, darren).
parent(amanda, jenny).
female(irene).
female(pat).
female(lee).
female(sandra).
female(jenny).
female(amanda).
female(kate).
male(albert).
male(jim).
male(peter).
male(brian).
male(john).
male(darren).
male(james).
male(kyle).
yearOfBirth(irene, 1923).
yearOfBirth(pat, 1954).
yearOfBirth(lee, 1970).
yearOfBirth(sandra, 1973).
yearOfBirth(jenny, 2004).
yearOfBirth(amanda, 1979).
yearOfBirth(albert, 1926).
yearOfBirth(jim, 1949).
yearOfBirth(peter, 1945).
yearOfBirth(brian, 1974).
yearOfBirth(john, 1955).
yearOfBirth(darren, 1976).
yearOfBirth(james, 1969).
yearOfBirth(kate, 1975).
yearOfBirth(kyle, 1976).
older(Person1, Person2) :-

        yearOfBirth(Person1, Year1),

        yearOfBirth(Person2, Year2),

        Year2 > Year1.
predecessor(X,Z) :-
	parent(X,Z).
predecessor(X,Z) :-
	parent(X,Y),
                predecessor(Y,Z).
grandparent(X,Z):-
	parent(X,Y),
                parent(Y,Z).
sibling(X,Y) :-
	parent(Z,X),
	parent(Z,Y),
	X\=Y.
sister(X) :-
	parent(Z,X),
	parent(Z,Y),
	female(Y),
	X\=Y.

