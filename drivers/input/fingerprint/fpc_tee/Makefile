ifdef CONFIG_INLINE_OPTIMIZATION
ccflags-y += -mllvm -inline-threshold=15000
ccflags-y += -mllvm -inlinehint-threshold=10000
endif
ifeq ($(CONFIG_BOARD_ALIOTH), y)
obj-$(CONFIG_FINGERPRINT_FPC_TEE) += fpc1020_tee.o
else ifeq ($(CONFIG_BOARD_APOLLO), y)
obj-$(CONFIG_FINGERPRINT_FPC_TEE) += fpc1020_tee_apollo.o
endif
