eats(cow,grass).
eats(sheep,grass).
eats(cat,fish).
eats(dog,kibble).
eats(dog,meat).

is_herbivore(Animal):-eats(Animal,grass).

is_carnivore(Animal):-eats(Animal,meat).
is_carnivore(Animal):-eats(Animal,fish).
