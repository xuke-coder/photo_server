CC = gcc
AR = ar
DEBUG = -g
CFLAG =-Wall -Werror
LIB = -lpthread -levent
TARGET = photosrv
ODIR = obj
SDIR = src
INC = -Iinc


_OBJS = photosrv.o 		\
	photosrv_log.o		\
	photosrv_slabs.o	\

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -fPIC -c $(INC) -o $@ $< $(CFLAGS) $(DEBUG)
	

.PHONY: all clean

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)  $(LIB)

clean:
	rm -rf $(ODIR)/*.o $(TARGET)
