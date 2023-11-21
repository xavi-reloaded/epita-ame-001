SRC_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

config/libconfig.a:
	$(MAKE) -C $(SRC_DIR)config

utils/libutils.a:
	$(MAKE) -C $(SRC_DIR)utils

server/libserver.a:
	$(MAKE) -C $(SRC_DIR)server

