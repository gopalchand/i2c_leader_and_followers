APP = heartbeat_i2c_pi

all: $(APP)

$(APP): heartbeat_i2c_pi.cpp
	g++ heartbeat_i2c_pi.cpp -lpthread -lpigpio -o $(APP)

clean:
	rm -f *.o ; rm $(APP)
