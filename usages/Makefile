#------------------------------------------------------------
# please set each item

# source files
SRC_DIR = src
OUT_DIR = exe

SRCS    = $(wildcard $(SRC_DIR)/*.cpp)
TARGETS = $(patsubst $(SRC_DIR)/%.cpp,$(OUT_DIR)/%.exe,$(SRCS))

# remove files
RMs = *.stackdump __pycache__ tmpDir

# compilation options
CFLAGS += -L./sstd/lib -I./sstd/include -lsstd # sstd
CFLAGS += -L./googletest-master/build/lib -I./googletest-master/googletest/include -lgtest -pthread # google test
CFLAGS += -std=c++11 # CFLAGS += -std=gnu++0x
CFLAGS += -Wall
#CFLAGS += -Wextra
CFLAGS += -O3

#------------------------------------------------------------

# when you need to check the change of files in lib, you need to change file name to a not-existing name like "FORCE_XXX".
#LIB_SSTD       = FORCE_SSTD
#LIB_GOOGLETEST = FORCE_GOOGLETEST
LIB_SSTD       = ./sstd/lib/libsstd.a
LIB_GOOGLETEST = ./googletest-master/build/lib/libgtest.a
LIB_ALL += $(LIB_SSTD)
LIB_ALL += $(LIB_GOOGLETEST)


TARGET_all = FORCE_MAKEALL
$(TARGET_all): $(LIB_ALL) $(TARGETS)
	@echo "maked all"


# generate exe file
define Fnc_gen_exe
$(1): $(2)
	mkdir -p $(OUT_DIR)
	@echo ""
	@echo "------------------------------------------------------------"
	@echo "TARGET: \n$(1)\n"
	@echo "SRCS: \n$(2)"
	@echo "CFLAGS: \n$(CFLAGS)"
	@echo "------------------------------------------------------------"
	$(CXX) -o $(1) $(2) $(CFLAGS)
	@echo ""
endef
$(foreach x, $(TARGETS), $(eval $(call Fnc_gen_exe, ./$(x), $(patsubst $(OUT_DIR)/%.exe,./$(SRC_DIR)/%.cpp,$(x)))))


$(LIB_SSTD):
	@echo ""
	@unzip -n SubStandardLibrary-SSTD--master.zip
	@mv SubStandardLibrary-SSTD--master/sstd ./
	@rm -rf SubStandardLibrary-SSTD--master/
	@(cd ./sstd; make -j)

$(LIB_GOOGLETEST):
	@echo ""
	@unzip -n googletest-master.zip
	@(cd ./googletest-master; mkdir -p build; cd build; cmake ..; make)


.PHONY: all
all:
	@(make clean)
	@(make)


.PHONY: clean
clean:
	-rm -rf $(OUT_DIR)
	-rm -rf googletest-master
	-rm -rf sstd
	-rm -rf $(RMs)


.PHONY: test
test: # run_all_test
	./exe_test


.PHONY: updateLib
updateLib:
	wget https://github.com/admiswalker/SubStandardLibrary-SSTD-/archive/master.zip -O SubStandardLibrary-SSTD--master.zip
	-rm -rf sstd # remove previous versions of sstd


.PHONY: steps
steps: $(SRCS)
	@echo "$^" | xargs wc -l
	@echo ""
	@(cd ./sstd; make steps)

