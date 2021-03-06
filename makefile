all: geometry

geometry: functions.o geometry.o
		gcc -Wall -Wextra -Werror -MMD -o geometry functions.o geometry.o -lm

functions.o: functions.c
		gcc -Wall -Wextra -Werror -MMD -c functions.c -lm

geometry.o: geometry.c
		gcc -Wall -Wextra -Werror -MMD -c geometry.c -lm

-include geometry.d hello.d

.PHONY: clean
clean:
		rm *.d *.o geometry