#------------------------------------------------------------
TEMP = ./tmp

SRC_DIR = ./docs_src
OUT_DIR = ./tmp

SRCS       = $(shell find $(SRC_DIR) -type f)
SRCS_md    = $(filter %.md, $(SRCS))
TARGETS_md = $(patsubst $(SRC_DIR)/%.md,$(OUT_DIR)/%.md,$(SRCS_md))

#------------------------------------------------------------

TARGET_all = FORCE_MAKEALL
$(TARGET_all): build_MkDocs build_mdEx
	@echo "SRCS: $(SRCS)\n"
	@echo "SRCS_md: $(SRCS_md)\n"
	@echo "TARGETS_md: $(TARGETS_md)\n"
	@echo "maked all"

#copy_files:
#define copy_files
#$(1): $(2)
#	mkdir -p $(OUT_DIR)
#	@echo ""
#	@echo "------------------------------------------------------------"
#	@echo "TARGET: \n$(1)\n"
#	@echo "SRCS: \n$(2)"
#	@echo "CFLAGS: \n$(CFLAGS)"
#	@echo "------------------------------------------------------------"
#	$(CXX) -o $(1) $(2) $(CFLAGS)
#	@echo ""
#endef
#$(foreach x, $(TARGETS), $(eval $(call copy_files, ./$(x), $(patsubst $(OUT_DIR)/%.exe,./$(SRC_DIR)/%.cpp,$(x)))))

build_MkDocs:
	@(mkdir -p $(TEMP))
	@(cp -r ./docs_src/* ./$(TEMP))
	@(cd ./$(TEMP); mkdocs build)

build_mdEx:
	@(cd ./mdEx_cpp_example; make) # markdown expansion

run: build_MkDocs build_mdEx
	@(xdg-open http://127.0.0.1:8000/)
	@(cd ./$(TEMP); mkdocs serve)

updateDocs:
	@(make build_MkDocs)
	@(mkdir -p ./docs)
	@(cp -r ./$(TEMP)/site/* ./docs)
	@(git add ./docs)
	@(git commit -m 'Update docs')
	@(git push origin main)

clean:
	@(rm -rf $(TEMP))
	@(cd ./mdEx_cpp_example; make clean)
