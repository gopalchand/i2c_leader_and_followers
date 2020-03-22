APP = i2c_slave

all: $(APP)

$(APP): i2c_slave.cpp
	g++ i2c_slave.cpp -lpthread -lpigpio -o $(APP)

clean:
	rm -f *.o ; rm $(APP)
