TEMP = ./tmp

build:
	@(mkdir -p $(TEMP))
	@(cp -r ./docs_src/* ./$(TEMP))
	@(cd ./$(TEMP); mkdocs build)

run: build
	@(xdg-open http://127.0.0.1:8000/)
	@(cd ./$(TEMP); mkdocs serve)

updateDocs:
	@(make build)
	@(mkdir -p ./docs)
	@(cp -r ./$(TEMP)/site/* ./docs)
	@(git add ./docs)
	@(git commit -m 'Update docs')
	@(git push origin main)

clean:
	@(rm -rf $(TEMP))
	@(rm -rf ./docs)
