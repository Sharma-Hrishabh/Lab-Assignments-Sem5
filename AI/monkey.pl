

move(state(middle,onbox,middle,hasnot),grasp,state(middle,onbox,middle,has)).
move(state(middle,onfloor,middle,H),climb,state(middle,onbox,middle,H)).
move(state(atdoor,onfloor,atdoor,H),push(atdoor,middle),state(middle,onfloor,middle,H)).
move(state(atdoor,onbox,B,H),stepdown,state(atdoor,onfloor,B,H)).

canget(state(_,_,_,has)).
canget(State1):-
	move(State1,Move,State2),
	canget(State2).



