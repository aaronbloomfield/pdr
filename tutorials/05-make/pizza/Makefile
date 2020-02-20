# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

pizza: pizza.o pizzadough.o tomatosauce.o toppings.o mushrooms.o peppers.o cheese.o pepperoni.o
	$(CXX) $(DEBUG) pizza.o pizzadough.o tomatosauce.o toppings.o mushrooms.o peppers.o cheese.o pepperoni.o -o pizza
	@echo "Pizza is Hot and Ready!"

pizza.o: pizza.cpp

pizzadough.o: pizzadough.cpp pizzadough.h

tomatosauce.o: tomatosauce.cpp tomatosauce.h

toppings.o: pepperoni.cpp peppers.cpp mushrooms.cpp cheese.cpp toppings.cpp \
            pepperoni.h peppers.h mushrooms.h cheese.h toppings.h

pepperoni.o: pepperoni.cpp pepperoni.h

mushrooms.o: mushrooms.cpp mushrooms.h

peppers.o: peppers.cpp peppers.h

cheese.o: cheese.cpp cheese.h

.PHONY: clean
clean:
	-rm -f *.o pizza
