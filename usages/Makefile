#------------------------------------------------------------
# please set each item

# source files
SRC_DIR = src
OUT_DIR = exe

SRCS   = $(wildcard $(SRC_DIR)/*.cpp)
TARGET = $(patsubst $(SRC_DIR)/%.cpp,$(OUT_DIR)/%.exe,$(SRCS))

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


# generate exe file
TARGET_all = FORCE_MAKEALL
$(TARGET_all): $(LIB_ALL) $(TARGET)
	@echo "maked all"
$(TARGET): $(LIB_ALL) $(SRCS)
	mkdir -p $(OUT_DIR)
	@echo ""
	@echo "------------------------------------------------------------"
	@echo "SRCS: $<\n"
	@echo "TARGET: $@\n"
	@echo "CFLAGS: $(CFLAGS)\n"
	@echo "------------------------------------------------------------"
	$(CXX) -o ./$@ $(patsubst $(OUT_DIR)/%.exe,./$(SRC_DIR)/%.cpp,$@) $(CFLAGS)
	@echo ""

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


.PHONY: zip
zip:
	-rm -rf $(RMs)
	@mkdir -p $(BACKUP_DIR)
	zip -r $(BACKUP_DIR)/${TIME_STAMP}$(m).zip $(BACKUP_FILES)
.PHONY: backup
backup:
	@(make zip)
	@(make)
# when you need comments for backup, just type
# $ make backup m=_comment_will_be_inserted_after_the_date


.PHONY: updateLib
updateLib:
	wget https://github.com/admiswalker/SubStandardLibrary-SSTD-/archive/master.zip -O SubStandardLibrary-SSTD--master.zip
	-rm -rf sstd # remove previous versions of sstd


.PHONY: steps
steps: $(SRCS)
	@echo "$^" | xargs wc -l
	@echo ""
	@(cd ./sstd; make steps)

