#------------------------------------------------------------
# please set each item

# source files
SRCS = main.cpp

# name of generating file
TARGET = exe

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

BACKUP_DIR   = ./backup
ALL_FILES    = $(wildcard ./*)
TMP_DIRS     = $(wildcard ./tmp*)
LIBS_DIRS    = ./sstd ./googletest-master ./sparsehash-master
BACKUP_FILES = $(filter-out $(TMP_DIRS) $(LIBS_DIRS) ./$(TARGET_t) ./$(TARGET_bm) $(BACKUP_DIR), $(ALL_FILES))
TIME_STAMP   = `date +%Y_%m%d_%H%M`


# when you need to check the change of files in lib, you need to change file name to a not-existing name like "FORCE_XXX".
#LIB_SSTD       = FORCE_SSTD
#LIB_GOOGLETEST = FORCE_GOOGLETEST
LIB_SSTD       = ./sstd/lib/libsstd.a
LIB_GOOGLETEST = ./googletest-master/build/lib/libgtest.a
LIB_ALL += $(LIB_SSTD)
LIB_ALL += $(LIB_flat)
LIB_ALL += $(LIB_GOOGLETEST)
LIB_ALL += $(LIB_hopscotch)


# generate exe file
TARGET_all = FORCE_MAKEALL
$(TARGET_all): $(LIB_ALL) $(TARGET_tc) $(TARGET_ti_sf) $(TARGET_ti_sp) $(TARGET_ti_hf) $(TARGET_ti_hp) $(TARGET_bm) $(TARGET_bm_uM) $(TARGET_sp)
	@echo "maked all"
$(TARGET_tc): $(LIB_ALL) $(SRCS_tc) $(HEADS) $(HEADS_tc)
	@echo ""
	@echo "------------------------------------------------------------"
	@echo "SRCS_t: \n$(SRCS_t)\n"
	@echo "CFLAGS: \n$(CFLAGS)"
	@echo "------------------------------------------------------------"
	$(CXX) -o $(TARGET_tc) $(SRCS_tc) $(CFLAGS) $(CFLAGS_tc)
	@echo ""
$(TARGET_ti_sf): $(LIB_ALL) $(SRCS_ti) $(HEADS) $(HEADS_ti)
	@echo ""
	@echo "------------------------------------------------------------"
	@echo "SRCS_t: \n$(SRCS_t)\n"
	@echo "CFLAGS: \n$(CFLAGS)"
	@echo "------------------------------------------------------------"
	$(CXX) -o $(TARGET_ti_sf) $(SRCS_ti) $(CFLAGS) $(CFLAGS_ti_sf)
	@echo ""
$(TARGET_ti_sp): $(LIB_ALL) $(SRCS_ti) $(HEADS) $(HEADS_ti)
	@echo ""
	@echo "------------------------------------------------------------"
	@echo "SRCS_t: \n$(SRCS_t)\n"
	@echo "CFLAGS: \n$(CFLAGS)"
	@echo "------------------------------------------------------------"
	$(CXX) -o $(TARGET_ti_sp) $(SRCS_ti) $(CFLAGS) $(CFLAGS_ti_sp)
	@echo ""
$(TARGET_ti_hf): $(LIB_ALL) $(SRCS_ti) $(HEADS) $(HEADS_ti)
	@echo ""
	@echo "------------------------------------------------------------"
	@echo "SRCS_t: \n$(SRCS_t)\n"
	@echo "CFLAGS: \n$(CFLAGS)"
	@echo "------------------------------------------------------------"
	$(CXX) -o $(TARGET_ti_hf) $(SRCS_ti) $(CFLAGS) $(CFLAGS_ti_hf)
	@echo ""
$(TARGET_ti_hp): $(LIB_ALL) $(SRCS_ti) $(HEADS) $(HEADS_ti)
	@echo ""
	@echo "------------------------------------------------------------"
	@echo "SRCS_t: \n$(SRCS_t)\n"
	@echo "CFLAGS: \n$(CFLAGS)"
	@echo "------------------------------------------------------------"
	$(CXX) -o $(TARGET_ti_hp) $(SRCS_ti) $(CFLAGS) $(CFLAGS_ti_hp)
	@echo ""
$(TARGET_bm): $(LIB_ALL) $(SRCS_bm) $(HEADS) $(HEADS_bm)
	@echo ""
	@echo "------------------------------------------------------------"
	@echo "SRCS_bm: \n$(SRCS_bm)\n"
	@echo "CFLAGS: \n$(CFLAGS)"
	@echo "------------------------------------------------------------"
	$(CXX) -o $(TARGET_bm) $(SRCS_bm) $(CFLAGS) $(CFLAGS_bm)
	@echo ""
$(TARGET_bm_uM): $(LIB_ALL) $(SRCS_bm_uM) $(HEADS) $(HEADS_bm)
	@echo ""
	@echo "------------------------------------------------------------"
	@echo "SRCS_bm_uM: \n$(SRCS_bm_uM)\n"
	@echo "CFLAGS: \n$(CFLAGS)"
	@echo "------------------------------------------------------------"
	$(CXX) -o $(TARGET_bm_uM) $(SRCS_bm_uM) $(CFLAGS) $(CFLAGS_bm)
	@echo ""
$(TARGET_sp): $(LIB_ALL) $(SRCS_sp)
	@echo ""
	@echo "------------------------------------------------------------"
	@echo "SRCS_st: \n$(SRCS_sp)\n"
	@echo "CFLAGS: \n$(CFLAGS)"
	@echo "------------------------------------------------------------"
	$(CXX) -o $(TARGET_sp) $(SRCS_sp) $(CFLAGS) $(CFLAGS_sp)
	@echo ""


$(LIB_SSTD):
	@echo ""
	@unzip -n SubStandardLibrary-SSTD--master.zip
	@mv SubStandardLibrary-SSTD--master/sstd ./
	@rm -rf SubStandardLibrary-SSTD--master/
	@(cd ./sstd; make -j)

$(LIB_flat):
	@echo ""
	@unzip -n flat_hash_map-master.zip

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
	-rm -rf $(TARGET)
	-rm -rf googletest-master
	-rm -rf flat_hash_map-master
	-rm -rf sstd
	-rm -rf $(RMs)


.PHONY: test
test: # run_all_test
	./exe_test_c
	./exe_test_i_hf
	./exe_test_i_hp
	./exe_test_i_sf
	./exe_test_i_sp


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
steps: $(SRCS_t) $(SRCS_bm) $(HEADS) $(HEADS_t) $(HEADS_bm)
	@echo "$^" | xargs wc -l
	@echo ""
	@(cd ./sstd; make steps)

