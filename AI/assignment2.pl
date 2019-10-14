%Making the Knowledge base.

% Declaring genders.
male(i).
male(f).
male(s1).
male(s2).

female(w).
female(d).

% Declaring parents
parent(f,i).
parent(w,d).
parent(i,s1).
parent(w,s1).
parent(f,s2).
parent(d,s2).

%Marriage Status
husband(i,w).
husband(f,d).
wife(w,i).
wife(d,f).


%defining relationships.
stepfather(X,Y) :- husband(X,Z),parent(Z,Y),male(X),not(parent(X,Y)).
father(X,Y) :- parent(X,Y),male(X) ; stepfather(X,Y).
stepmother(X,Y) :- wife(X,Z),parent(Z,Y),female(X),not(parent(X,Y)).
mother(X,Y) :- parent(X,Y),female(X) ; stepmother(X,Y).
stepparent(X,Y) :- stepfather(X,Y) ; stepmother(X,Y).
stepdaughter(X,Y) :- stepparent(Y,X),female(X).
soninlaw(X,Y) :- father(Y,Z),female(Z),husband(X,Z) ; mother(Y,Z),female(Z),husband(X,Z).
brotherinlaw(X,Y) :- father(Z,X),soninlaw(Y,Z).
uncle(X,Y) :- parent(Z,Y),brotherinlaw(X,Z).
grandfather(X,Y) :- father(Z,X),soninlaw(Z,Y) ; father(X,Z),mother(Z,Y).