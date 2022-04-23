OFILES_MedianOfMedians = main.o Array.o MedianOfMedians.o
OFILES_SelectByHeapsort = main.o Array.o SelectByHeapsort.o
OFILES_QuickSelect = main.o Array.o QuickSelect.o
OFILES_SelectByQuicksort = main.o Array.o SelectByQuicksort.o

TARGET_MedianOfMedians = test_MedianOfMedians
TARGET_SelectByHeapsort = test_SelectByHeapsort
TARGET_QuickSelect = test_QuickSelect
TARGET_SelectByQuicksort = test_SelectByQuicksort

CC = gcc
CFLAGS = -g -Wall -Wextra -Wmissing-prototypes --pedantic -std=c99 -O3 -march=native -flto

.PHONY: all clean run

LDFLAGS = -lm

all: $(TARGET_MedianOfMedians) $(TARGET_QuickSelect) $(TARGET_SelectByHeapsort) $(TARGET_SelectByQuicksort)
clean:
	rm -f $(OFILES_MedianOfMedians) $(OFILES_SelectByHeapsort) $(OFILES_QuickSelect) $(OFILES_SelectByQuicksort) $(TARGET_MedianOfMedians) $(TARGET_QuickSelect) $(TARGET_SelectByHeapsort) $(TARGET_SelectByQuicksort)
run: $(TARGET_MedianOfMedians) $(TARGET_QuickSelect) $(TARGET_SelectByHeapsort) $(TARGET_SelectByQuicksort)
	./$(TARGET_MedianOfMedians)
	./$(TARGET_QuickSelect)
	./$(TARGET_SelectByHeapsort)
	./$(TARGET_SelectByQuicksort)
$(TARGET_MedianOfMedians): $(OFILES_MedianOfMedians)
	$(CC) -o $(TARGET_MedianOfMedians) $(OFILES_MedianOfMedians) $(LDFLAGS)
$(TARGET_QuickSelect): $(OFILES_QuickSelect)
	$(CC) -o $(TARGET_QuickSelect) $(OFILES_QuickSelect) $(LDFLAGS)
$(TARGET_SelectByHeapsort): $(OFILES_SelectByHeapsort)
	$(CC) -o $(TARGET_SelectByHeapsort) $(OFILES_SelectByHeapsort) $(LDFLAGS)
$(TARGET_SelectByQuicksort): $(OFILES_SelectByQuicksort)
	$(CC) -o $(TARGET_SelectByQuicksort) $(OFILES_SelectByQuicksort) $(LDFLAGS)

Array.o: Array.c Array.h
MedianOfMedians.o: MedianOfMedians.c Select.h
QuickSelect.o: QuickSelect.c Select.h
SelectByHeapsort.o: SelectByHeapsort.c Select.h
SelectByQuicksort.o: SelectByQuicksort.c Select.h
main.o: main.c Array.h Select.h


