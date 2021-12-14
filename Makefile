#------------------------------------------------------------

TEMP := ./tmp

SRC_DIR := ./docs_src
OUT_DIR := ./tmp

SRCS     := $(shell find $(SRC_DIR) -type f)
SRCS_md  := $(filter %.md, $(SRCS))
SRCS_nmd := $(filter-out %mkdocs.yml, $(filter-out %.md, $(SRCS)) )
TARGETS_md  := $(patsubst $(SRC_DIR)/%,$(OUT_DIR)/%,$(SRCS_md))
TARGETS_nmd := $(patsubst $(SRC_DIR)/%,$(OUT_DIR)/%,$(SRCS_nmd))

#------------------------------------------------------------

TARGET_all    := FORCE_MAKEALL
READ_DIR_TREE := FORCE_MAKE
build_MkDocs  := ./tmp/site/index.html
build_mdEx    := ./mdEx_cpp_example/mdEx_cpp_example.exe

$(TARGET_all): $(build_mdEx) $(TARGETS_md) $(TARGETS_nmd) $(READ_DIR_TREE) $(build_MkDocs)
	@echo "maked all"

$(READ_DIR_TREE):
	@echo "--- apply_mdEx: title ---"
	@echo "target: $@"
	@echo "   src: $<"
	@(python ./mdEx_title/main.py  ./$(SRC_DIR)/mkdocs.yml ./$(OUT_DIR)/mkdocs.yml $(SRC_DIR)/docs/src)

define apply_mdEx
$(1): $(2) $(build_mdEx)
	@echo "--- apply_mdEx: cpp example ---"
	@echo "target: $(1)"
	@echo "   src: $(2)"
	@(mkdir -p $(dir $(1)))
#	@(cd ./mdEx_cpp_example; ./mdEx_cpp_example.exe ../$(OUT_DIR) ../$(2) ../$(1))
	@(cd ./mdEx_cpp_example; ./mdEx_cpp_example.exe $(patsubst %,../%,$(OUT_DIR)) $(patsubst %,../%,$(2)) $(patsubst %,../%,$(1)))
endef
$(foreach x, $(TARGETS_md), $(eval $(call apply_mdEx, $(x), $(patsubst $(OUT_DIR)/%,$(SRC_DIR)/%,$(x)))))

define copy_file
$(1): $(2)
	@echo "--- copy_file ---"
	@echo "target: $(1)"
	@echo "   src: $(2)"
	@(mkdir -p $(dir $(1)))
	@cp -f $(2) $(1)
endef
$(foreach x, $(TARGETS_nmd), $(eval $(call copy_file, $(x), $(patsubst $(OUT_DIR)/%,$(SRC_DIR)/%,$(x)))))

$(build_MkDocs): $(TARGETS_md) $(TARGETS_nmd) $(READ_DIR_TREE)
	@(mkdir -p $(TEMP))
#	@(cp -r ./docs_src/* ./$(TEMP))
	@(cd ./$(TEMP); mkdocs build)

$(build_mdEx): ./mdEx_cpp_example/main.cpp
	@(cd ./mdEx_cpp_example; make) # markdown expansion
	@echo ""

run: $(TARGET_all)
	@(xdg-open http://127.0.0.1:8000/)
	@(cd ./$(TEMP); mkdocs serve)

genDocs:
	@(cd ./$(TEMP); mkdocs build)
	@(mkdir -p ./docs)
	@(cp -r ./$(TEMP)/site/* ./docs)
uploadDocs:
	@(git add ./docs)
	@(git commit -m 'Update docs')
	@(git push origin main)
updateDocs:
	@(make genDocs)
	@(make uploadDocs)

updateLib:
	@(cd ./mdEx_cpp_example; make updateLib)

clean:
	@(rm -rf $(TEMP))
	@(cd ./mdEx_cpp_example; make clean)

help:
	@(echo "Usages:")
	@(echo "  $ make -j         : Building the documents")
	@(echo "  $ make clean      : Removing the temporary files")
	@(echo "  $ make help       : Showing the help (This messages)")
	@(echo "  $ make run        : Running the previewing server on a local machine")
	@(echo "  $ make genDocs    : Generating the documents in local ./docs")
	@(echo "  $ make upDocs     : Uploading the documents in local ./docs to github repository")
	@(echo "  $ make updateDocs : Updating the documents on github.io (same as a '$ make genDocs; make upDocs')")
	@(echo "  $ make updateLib  : Updating the SSTD at \"./mdEx_cpp_example\"")

