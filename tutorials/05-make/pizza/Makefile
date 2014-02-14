CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g

pizza: pizza.o pizzadough.o tomatosauce.o toppings.o mushrooms.o peppers.o cheese.o pepperoni.o
	$(CXX) $(DEBUG) pizza.o pizzadough.o tomatosauce.o toppings.o mushrooms.o peppers.o cheese.o pepperoni.o -o pizza
	@echo "Pizza is Hot and Ready!"
	
pizza.o: pizza.cpp
	$(CXX) -c pizza.cpp

pizzadough.o: pizzadough.cpp pizzadough.h
	$(CXX) -c pizzadough.cpp
	
tomatosauce.o: tomatosauce.cpp tomatosauce.h
	$(CXX) -c tomatosauce.cpp
	
toppings.o: pepperoni.cpp peppers.cpp mushrooms.cpp cheese.cpp toppings.cpp \
			pepperoni.h peppers.h mushrooms.h cheese.h toppings.h
	$(CXX) -c toppings.cpp
	
pepperoni.o: pepperoni.cpp pepperoni.h
	$(CXX) -c pepperoni.cpp
	
mushrooms.o: mushrooms.cpp mushrooms.h
	$(CXX) -c mushrooms.cpp
	
peppers.o: peppers.cpp peppers.h
	$(CXX) -c peppers.cpp

cheese.o: cheese.cpp cheese.h
	$(CXX) -c cheese.cpp
	
	
clean:
	-rm *.o pizza
