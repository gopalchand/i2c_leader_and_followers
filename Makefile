TOPDIR  := $(shell cd ..; pwd)
include $(TOPDIR)/Rules.make

APP = heartbeat_i2c

all: $(APP)

$(APP): main.cpp	
	$(CC) main.cpp -o $(APP) $(CFLAGS)
	
clean:
	-rm -f *.o ; rm $(APP)
