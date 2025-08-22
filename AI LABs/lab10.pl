parent(bob,pam).
parent(bob,tom).
parent(liz,pam).
parent(liz,tom).
parent(ann,bob).
parent(ann,pat).
parent(jim,pat).

male(tom).
male(bob).
male(jim).
male(bill).
female(bill).
female(pam).
female(pat).
female(ann).

mother(X,Y):-
    parent(Y,X),
    female(X).

father(X,Y):-
    parent(Y,X),
    male(X).

siblings(X,Y):-
    parent(X,Z),
    parent(Y,Z),
    X \= Y.

grandparent(X, Y):-
    parent(Y,Z),
    parent(Z,X).

ancestor(X, Y):-
    parent(Y,X).
ancestor(X,Y):-
    parent(Y,Z),
    ancestor(X,Z).


