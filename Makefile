#------------------------------------------------------------
TEMP = ./tmp

SRC_DIR = ./docs_src
OUT_DIR = ./tmp

SRCS     = $(shell find $(SRC_DIR) -type f)
SRCS_md  = $(filter %.md, $(SRCS))
SRCS_nmd = $(filter-out %.md, $(SRCS))
TARGETS_md  = $(patsubst $(SRC_DIR)/%,$(OUT_DIR)/%,$(SRCS_md))
TARGETS_nmd = $(patsubst $(SRC_DIR)/%,$(OUT_DIR)/%,$(SRCS_nmd))

#------------------------------------------------------------

TARGET_all = FORCE_MAKEALL
$(TARGET_all): $(TARGETS_md) $(TARGETS_nmd) #build_MkDocs build_mdEx
	@echo "SRCS: $(SRCS)\n"
	@echo "SRCS_md: $(SRCS_md)\n"
	@echo "SRCS_nmd: $(SRCS_nmd)\n"
	@echo "TARGETS_md: $(TARGETS_md)\n"
	@echo "TARGETS_nmd: $(TARGETS_nmd)\n"
	@echo "maked all"


define apply_mdEx
$(1): $(2)
	@echo "target: $(1)"
	@echo "   src: $(2)"
	mkdir -p $(OUT_DIR)
	./mdEx_cpp_example/mdEx_cpp_example.exe $(1) $(2)
	@echo ""
endef
$(foreach x, $(TARGETS_md), $(eval $(call apply_mdEx, $(x), $(patsubst $(OUT_DIR)/%,$(SRC_DIR)/%,$(x)))))


define copy_file
$(1): $(2)
	@echo "target: $(1)"
	@echo "   src: $(2)"
	mkdir -p $(OUT_DIR)
	cp -f $(2) $(1)
endef
$(foreach x, $(TARGETS_nmd), $(eval $(call copy_file, $(x), $(patsubst $(OUT_DIR)/%,$(SRC_DIR)/%,$(x)))))


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
