_CLANG                  =$(if $(V), $(CLANG), @$(CLANG))
_GCC                    =$(if $(V), $(GCC), @$(GCC))
RM                     :=$(if $(V), rm, @rm)
MKDIR                  :=$(if $(V), mkdir, @mkdir)

BUILD_DIR              :=__BUILD_
TARGET                 =$(BUILD_DIR)/$(notdir $(PWD)).elf

src                    :=$(shell find . -name "*.[c]")
obj                    :=$(subst .c,.o,$(src))
obj                    :=$(addprefix $(BUILD_DIR)/,$(obj))

.PHONY:all check clean

all:check $(BUILD_DIR) $(TARGET)

CLANG_CFLAG            =-Wall -Wextra -Werror -I/usr/include --target=$(TARGET_TRIPLE) \
                            -DRV64 -march=rv64gcv1p0_zbb -mllvm -riscv-v-vector-bits-min=512 \
                            -menable-experimental-extensions -O3 -c
GCC_CFLAG              =-Wall -Wextra -Werror -I/usr/include -O3 -c \
                            -DRV64 -march=rv64gcv_zbb_zifencei
LFLAG                  :=-O3 -static
LIB                    :=-lm

check:
ifndef CLANG
	@echo "Environment variable CLANG no set, will take GCC"
else
  ifndef TARGET_TRIPLE
	@echo "Environment variable TARGET_TRIPLE must be set for clang"
	exit 1
  endif
endif
ifndef GCC
	@echo "Environment variable GCC must be set"
	exit 1
endif

$(BUILD_DIR):
	@echo "    CleanDir $@"
	$(RM) -rf $@
	@echo "    MakeDir  $@"
	$(MKDIR) $@

$(TARGET):$(obj)
	@echo "    Link     $@"
	$(_GCC) $(LFLAG) $^ -o $@ $(LIB)

$(obj):$(BUILD_DIR)/%.o:%.c
	@echo "    MakeDir  $(dir $@)"
	$(MKDIR) -p $(dir $@)
	@echo "    Compile  $<"
ifdef CLANG
	$(_CLANG) $(CLANG_CFLAG) $< -o $@
else
	$(_GCC) $(GCC_CFLAG) $< -o $@
endif

clean:
	@echo "    CleanDir $(BUILD_DIR)"
	$(RM) -rf $(BUILD_DIR)
