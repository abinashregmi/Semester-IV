is_a(cat, mammal).
is_a(dog, mammal).
is_a(eagle, bird).
is_a(sparrow, bird).

is_a_bird(Animal) :- is_a(Animal, bird).
