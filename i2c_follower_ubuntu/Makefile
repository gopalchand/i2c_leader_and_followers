TOPDIR  := $(shell cd ..; pwd)
include $(TOPDIR)/Rules.make

APP = heartbeat_i2c

all: $(APP)

$(APP): heartbeat_i2c.cpp	
	$(CC) heartbeat_i2c.cpp -o $(APP) $(CFLAGS)
	
clean:
	-rm -f *.o ; rm $(APP)
