include flags.mk

OBJ = main.o

LIBS = config/libconfig.a utils/libutils.a server/libserver.a

all: httpd

httpd: $(OBJ) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) -Wl,--start-group $(LIBS) -Wl,--end-group

include libs.mk

.PHONY: all
